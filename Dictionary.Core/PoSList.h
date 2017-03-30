#ifndef PoSList_h
#define PoSList_h

#include "PartofSpeach.h"
#include <regex>

class PoSList 
{
private:
	PartofSpeach* head;

public:
	PoSList()
	{
		head = NULL;
	}
	PoSList(PartofSpeach* head)
	{
		this->head = head;
	}
	void AddPoS(string PoS)
	{
		PartofSpeach* temp = new PartofSpeach(PartofSpeach(PoS));
		if(head != NULL)
		{
			temp->SetNextNode(head);
			head = temp;
		}
		else
			head = temp;
	}
	static PoSList GetPoSList(string text)
	{
		smatch match;
		PartofSpeach* head = NULL;
		PartofSpeach* temp;
		while(regex_search(text,match,regex("[a-z]+\\.")))
		{
			if(head != NULL)
			{
				temp->SetNextNode(new PartofSpeach(match[0]));
				temp = temp->GetNextNode();
			}
			else
			{
				head = new PartofSpeach(match[0]);
				temp = head;
			}
			text = match.suffix().str();
		}
		return PoSList(head);
	}
	string ToString()
	{
		string result = "";
		PartofSpeach *temp = head;
		while (temp != NULL)
		{
			result += temp->GetValue() + " ";
			temp = temp->GetNextNode();
		}
		return result;
	}
};
#endif