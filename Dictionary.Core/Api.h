#ifndef Api_h
#define Api_h

namespace DictionaryCore {
#define BASEURL "https://od-api.oxforddictionaries.com/api/v1"
#define APPID "8aebb444"
#define APIKEY "eee88b67d11cce72ca2d782fe55c491a"
#define LANG "en"

	using namespace System::Net;

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
				//If Word not found
				if(e->Message->Contains("404"))
					return "";
				if(DisplayErrors)
					if(Ut::Error(e->Message+"\nDon't Show Again?", MessageBoxButtons::OKCancel) == DialogResult::OK)
						DisplayErrors = false;
				return "";
			}
		}
		String^ GetSampleDefinition(String^ wordname)
		{
			//Retrieve Json String
			string data = Ut::FromStringHat(GetJSONString(wordname));
			//Return Blank if word not found
			if(data == "")
				return "";
			Document doc;

			//Parse Json 
			doc.Parse(data.c_str());
			//Pull one of the definitions
			string result = doc["results"][0]["lexicalEntries"][0]["entries"][0]["senses"][0]["definitions"][0].GetString();

			//Make First Char Uppercase
			result = (char)toupper(result[0])+result.substr(1);

			return Ut::ToStringHat(result.c_str())+".";
		}
	};
}

#endif