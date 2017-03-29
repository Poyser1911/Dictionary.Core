#ifndef ConfigM_h
#define ConfigM_h

using namespace rapidjson;
using namespace System::IO;
using namespace System;

namespace DictionaryCore {
	class ConfigManager
	{
	private:
		string filename;
		Document doc;
		int NumOfFiles;

		void CheckFile(String^ filename)
		{
			if(!File::Exists(filename))
			{
				if(Ut::Info("Configuration File Not Found, Create now?",System::Windows::Forms::MessageBoxButtons::OKCancel,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
					CreateNew(filename);
				else
					System::Environment::Exit(1);
			}
			else
			{
				try
				{
					string data = Ut::ReadAllText(this->filename);
					if (doc.Parse(data.c_str()).HasParseError()) {
						char buff[120];
						sprintf_s(buff, "\nError(offset %u)\n",(unsigned)doc.GetErrorOffset());
						string errormsg(buff);
						throw gcnew Exception("Could not parse "+filename+", "+Ut::ToStringHat(errormsg.c_str()));
					}
					else
					{
						if(!doc.HasMember("filenames"))
							throw gcnew Exception("Could not parse "+filename+", 'filenames[]' is not defined");
					}
				}
				catch(Exception^ e)
				{
					if(Ut::Info(e->Message+"\nCreate New?",System::Windows::Forms::MessageBoxButtons::OKCancel,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
						CreateNew(filename);
					else
						System::Environment::Exit(1);
				}
			}
		}
		void GetFileNamesFromJson()
		{
			NumOfFiles = 0;
			Value& filenames = doc["filenames"];

			for(rapidjson::SizeType i = 0;i<filenames.Size();i++)
				NumOfFiles++;
		}
		void CreateNew(String^ filename)
		{
			try
			{
				File::WriteAllText(filename,"{\"filenames\":[]}");
				Ut::Info(filename+" Created Sucessfully");
				CheckFile(filename);
			}
			catch(Exception^ e)
			{
				Ut::Error(e->Message);
				System::Environment::Exit(1);
			}
		}
	public:
		ConfigManager(String^ filename = "conf.json")
		{
			//Prevent / and \ confusion//
			//Prevent searching else-where when debugging//
			if(!filename->Replace('/','\\')->Contains("\\"))
				filename = System::AppDomain::CurrentDomain->BaseDirectory+"\\"+filename;

			this->filename = Ut::FromStringHat(filename);

			//Check File - Create if Not Exist,Load & Check Json//
			CheckFile(filename);

			GetFileNamesFromJson();
		}

		Value& GetFileNames()
		{
			return this->doc["filenames"];
		}
		int GetNumOFFiles()
		{
			return this->NumOfFiles;
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
}
#endif