#ifndef Word_h
#define Word_h

#include "Node.h"
#include "PoSList.h"
#include <regex>

using namespace std;

class Word : public Node<Word,string>
{
private: 
	string Name;
	string Definition;
	PoSList PartofS;

public: 
	Word()
	{
		this->Name = "";
	}
	Word(string Name,string Definition,PoSList PartofSpeachList)
	{
		this->Name = Name;
		this->Definition = Definition;
		this->PartofS = PartofSpeachList;
	}
	~Word()
	{
	}

	string GetName()
	{
		if((int)this->Name[0] >= 97)
			this->Name[0] = (char)((int)this->Name[0]-32);
		return this->Name;
	}

	void SetName(string Name)
	{
		this->Name = Name;
	}

	string GetDefinition()
	{
		return this->Definition;
	}

	void SetDefinition(string Definition)
	{
		this->Definition = Definition;
	}

	PoSList GetPartofSpeachList()
	{
		return this->PartofS;
	}

	void SetPartofSpeachList(PoSList PartofSpeach)
	{
		this->PartofS = PartofSpeach;
	}

	string GetValue()
	{
		return this->Name + " "+this->PartofS.ToString() + " - "+ this->Definition;
	}
	void SetValue(string Name)
	{
		this->Name = Name;
	}
	static Word GetWord(string line)
	{
		Word word;
		try
		{
		smatch match;
		regex_search(line,match,regex("[A-z/]+"));
		word.Name = match[0];

		line = regex_replace(line,regex(word.Name),"",regex_constants::format_first_only);

		string de = line.substr(line.find_last_of('\t')+1,line.length());
		regex_search(de,match,regex("[A-z].+"));
		word.Definition = match[0];
		string tempdefinition = word.Definition;
		Ut::ReplaceAll(tempdefinition,string("("),"\\(");
		Ut::ReplaceAll(tempdefinition,string(")"),"\\)");
		line = regex_replace(line,regex(tempdefinition),"");

		while(regex_search(line,match,regex("[a-z]+\\.")))
		{
			for(auto m : match)
				word.PartofS.AddPoS(m);
			line = match.suffix().str();
		}
		}
		catch(exception) {}
		return word;
	}
};

#endif