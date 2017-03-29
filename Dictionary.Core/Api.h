#ifndef Api_h
#define Api_h
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#define BASEURL "https://od-api.oxforddictionaries.com/api/v1"
#define APPID "8aebb444"
#define APIKEY "eee88b67d11cce72ca2d782fe55c491a"
#define LANG "en"

using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Windows::Forms;

ref class DictionaryApi
{
private:
	WebClient client;
	bool DisplayErrors;
public:
	DictionaryApi()
	{
		DisplayErrors = true;
		client.Headers->Add("Accept","application/json");
		client.Headers->Add("app_id",APPID);
		client.Headers->Add("app_key",APIKEY);
	}
	String^ GetJSONString(String^ wordname)
	{
		try{
			return client.DownloadString(BASEURL+"/entries/"+LANG"/"+wordname+"/definitions");
		}
		catch(WebException^ e)
		{
			if(DisplayErrors)
				if(Ut::Error(e->Message+"\nDon't Show Again?") == DialogResult::OK)
					DisplayErrors = false;
			return "";
		}
	}
	String^ GetSampleDefinition(String^ wordname)
	{
		string data = Ut::FromStringHat(GetJSONString(wordname));
		Document doc;
		doc.Parse(data.c_str());
		string result = doc["results"][0]["lexicalEntries"][0]["entries"][0]["senses"][0]["definitions"][0].GetString();
		result = (char)toupper(result[0])+result.substr(1);
		return Ut::ToStringHat(result.c_str())+".";
	}
};





#endif