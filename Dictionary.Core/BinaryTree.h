#ifndef BinaryTree_h
#define BinaryTree_h
#include <fstream>

#include "Word.h"
#include "ResultSet.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class Tree
{
private:
	Word* val;
	Tree* left;
	Tree* right;
	static string allwords;
	static int recursions;

public:
	bool IsLoaded;
	Tree()
	{
		val = NULL;
		left = NULL;
		right = NULL;
	}
	Tree(Word val)
	{
		this->val = new Word(val);
		left = NULL;
		right = NULL;
	}
	void Init()
	{
		allwords = string("");
		Tree::recursions = 0;
	}
	ResultSet<Word> AddWord(Word data)
	{
		ResultSet<Word> result;
		string wordname = Ut::ToLower(data.GetName());
		ResultSet<Word> findresult = FindWord(wordname);
		if(findresult.result.GetName() == "")
			Insert(data);

		result.Stop();
		result.result.SetName(findresult.result.GetName());
		return result;
	}
	ResultSet<Word> FindWord(string wordname)
	{
		ResultSet<Word> result;
		result.result = GetWord(Ut::ToLower(wordname));
		result.Stop();
		result.Setindex(recursions);
		Init();

		return result;
	}
	System::String^ GetAll()
	{
		//ResultSet<string> result;
		AppendAllWords();
		//result.Stop();

		//Potential Count of all Words
		//result.Setindex(recursions);
		//result.result = allwords;
		System::String^ temp = Ut::ToStringHat(allwords.c_str());
		Init();
		return temp;
	}
	ResultSet<char> LoadFromFile(rapidjson::Value& filenames, int size)
	{
		ResultSet<char> result;
		string line;
		for(int i=0;i<size;i++)
		{
			ifstream file(filenames[i].GetString());
			while (getline(file, line))
			{
				Word w = Word::GetWord(line.c_str());
				if(w.GetName() == "")
					continue;
				Insert(w);

				//Will Serve as count
				result.IncrementIndex();
			}
		}
		result.Stop();
		IsLoaded = true;
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
			{
				string wordname = Ut::ToLower(m);
				if(this->FindWord(wordname).result.GetName() == "")
					result.result += m.str()+",";
				sentence = match.suffix().str();
			}
		}
		result.result =  result.result.length() != 0 ? result.result.substr(0,result.result.length()-1) : result.result;
		result.Stop();
		return result;
	}
private:
	void Insert(Word data)
	{
		if(val == NULL)
			val = new Word(data);
		//Tree::recursions++;

		//Don't Insert Repeated Words
		if(data.GetName() == (*val).GetName())
			return;

		if(data.GetName() < (*val).GetName())
			if(left == NULL)
				left = new Tree(data);
			else
				left->Insert(data);
		else
			if(right == NULL)
				right = new Tree(data);
			else
				right->Insert(data);

	}
	Word GetWord(string wordname)
	{
		string name = Ut::ToLower(val->GetName());
		if(name == wordname)
			return *val;
		Tree::recursions++;
		if(wordname < name)
			if(left == NULL)
				return Word();
			else
				return left->GetWord(wordname);
		else
			if(right == NULL)
				return Word();
			else
				return right->GetWord(wordname);
	}
	void AppendAllWords()
	{
		if(left != NULL)
			left->AppendAllWords();

		allwords += val->GetValue()+"\n";
		//Tree::recursions++;
		if(right != NULL)
			right->AppendAllWords();
	}
};
string Tree::allwords;
int Tree::recursions;

#endif

