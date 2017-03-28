#ifndef LinkedList_h
#define LinkedList_h

#include <fstream>
#include <string>
#include "Ut.h"
#include "Word.h"
#include "ResultSet.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
class LinkedList
{
private:
	int Count;
	Word* head;
public:
	bool IsLoaded;
#pragma region Constructors
	LinkedList()
	{
		this->head  = NULL;
		this->Count = 0;
		this->IsLoaded = false;
	}

	LinkedList(Word head)
	{
		this->head = new Word(head);
		Count = 1;
	}

	~LinkedList()
	{
		//DestroyList();
	}
#pragma endregion
	ResultSet<Word> LoadFromFile(rapidjson::Value& filenames, int size)
	{
		ResultSet<Word> result;
		Word* temp = head;
		if(temp != NULL)
			while(temp->GetNextNode() != NULL)
				temp = temp->GetNextNode();

		string line; 
		for(int i=0;i<size;i++)
		{
			ifstream file(filenames[i].GetString());
			while (getline(file, line))
			{
				if(head != NULL)
				{
					temp->SetNextNode(new Word(Word::GetWord(line.c_str())));
					temp = temp->GetNextNode();
				}
				else
				{
					head = new Word(Word::GetWord(line.c_str()));
					temp = head;
				}
				Count++;
			}
		}
		result.Stop();
		this->IsLoaded = true;

		return result;
	}

	int GetCount()
	{
		return this->Count;
	}
	ResultSet<int> Sort()
	{
		ResultSet<int> result;
		pin_ptr<Word*> pinnedHead = &this->head; 
		MergeSort(pinnedHead);
		result.Stop();
		return result;
	}

	void MergeSort(Word** headRef)
	{
		Word* head = *headRef;
		Word* a;
		Word* b;

		if ((head == NULL) || (head->GetNextNode() == NULL))
			return;

		FrontBackSplit(head, &a, &b); 
		MergeSort(&a);
		MergeSort(&b);
		*headRef = SortedMerge(a, b);
	}
	Word* SortedMerge(Word* a, Word* b)
	{
		Word* result = NULL;

		if (a == NULL)
			return(b);
		else if (b==NULL)
			return(a);


		if (a->GetName() < b->GetName())
		{
			result = a;
			result->SetNextNode(SortedMerge(a->GetNextNode(), b));
		}
		else if (a->GetName() == b->GetName())
		{
			result = a;
			result->SetNextNode(SortedMerge(a->GetNextNode(), b->GetNextNode()));
		}
		else
		{
			result = b;
			result->SetNextNode(SortedMerge(a, b->GetNextNode()));
		}
		return(result);
	}
	void FrontBackSplit(Word* source,Word** frontRef, Word** backRef)
	{
		Word* fast;
		Word* slow;
		if (source==NULL || source->GetNextNode()==NULL)
		{
			*frontRef = source;
			*backRef = NULL;
		}
		else
		{
			slow = source;
			fast = source->GetNextNode();

			while (fast != NULL)
			{
				fast = fast->GetNextNode();
				if (fast != NULL)
				{
					slow = slow->GetNextNode();
					fast = fast->GetNextNode();
				}
			}
			*frontRef = source;
			*backRef = slow->GetNextNode();
			slow->SetNextNode(NULL);
		}
	}
	System::String^ GetAll()
	{
		Word *temp = head;
		System::String^ result = "";
		while (temp != NULL)
		{
			result += Ut::ToStringHat(temp->GetValue().c_str())+System::Environment::NewLine;
			temp = temp->GetNextNode();
		}
		return result;
	}
	ResultSet<Word> FindWord(string WordName)
	{
		ResultSet<Word> result;
		WordName = Ut::ToLower((WordName));
		if(head == NULL)
			return result;

		Word* temp = head;
		while(temp != NULL)
		{
			if(Ut::ToLower((temp->GetName())) == WordName)
			{
				result.Stop();
				result.Setresult(*temp);
				break;
			}
			result.IncrementIndex();
			temp = temp->GetNextNode();
		}
		return result;
	}
	ResultSet<Word> AddWord(Word word, bool AutoSort)
	{
		ResultSet<Word> result;
		string wordname = Ut::ToLower(word.GetName());
		if(FindWord(wordname).result.GetName() != "")
		{
			result.result.SetName("");
			return result;
		}
		result.Setresult(word);
		if(head != NULL)
		{
			Word* temp = new Word(word);
			temp->SetNextNode(head);
			head = temp;

			if(AutoSort)
				Sort();
		}
		else
			head = new Word(word);

		result.Stop();
		return result;

	}
	ResultSet<string> ValidateSentence(string sentence)
	{
		ResultSet<string> result;
		smatch match;
		result.result = "";
		while(regex_search(sentence,match,regex("[A-z]+")))
		{
			for(auto m : match)
				if(this->FindWord(m).result.GetName() == "")
					result.result += m.str()+",";
			sentence = match.suffix().str();
		}
		result.result =  result.result.length() != 0 ? result.result.substr(0,result.result.length()-1) : result.result;
		result.Stop();
		return result;
	}
};

#endif
