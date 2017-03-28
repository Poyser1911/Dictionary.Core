#ifndef PoSList_h
#define PoSList_h

#include "PartofSpeach.h"
class PoSList 
{
private:
	PartofSpeach* head;

public:
	PoSList()
	{
		head = NULL;
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