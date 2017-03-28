#ifndef ConfigM_h
#define ConfigM_h
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;
using namespace std;
using namespace System::IO;
class ConfigManager
{
private:
	string filename;
	Document doc;
	int NumOfFiles;
	//"C:\\sample\\conf.json"
public:
	ConfigManager(string filename = "conf.json")
	{
		this->filename = filename;
		NumOfFiles = 0;
		Reload();
	}
	Value& GetFileNames()
	{
		return this->doc["filenames"];
	}
	int GetNumOFFiles()
	{
		return this->NumOfFiles;
	}
	void Reload()
	{
		string data = Ut::ReadAllText(this->filename);
		NumOfFiles = 0;
		if(data != "")
		{
			doc.Parse(data.c_str());
			Value& filenames = doc["filenames"];
			for(rapidjson::SizeType i = 0;i<filenames.Size();i++)
				NumOfFiles++;
		}
	}
	void AddFileName(System::String^ filename)
	{
		Value& filenames = doc["filenames"];
		Value str;
		str.SetString(Ut::FromStringHat(filename).c_str(), doc.GetAllocator());
		filenames.PushBack(str, doc.GetAllocator()); 
		NumOfFiles++;
	}
	void Save()
	{
		if(NumOfFiles == 0)
			return;
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		doc.Accept(writer);

		File::WriteAllText(Ut::ToStringHat(this->filename.c_str()),Ut::ToStringHat(buffer.GetString()));
	}

};

#endif