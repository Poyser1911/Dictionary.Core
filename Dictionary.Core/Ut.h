#ifndef Ut_h
#define Ut_h

#include <msclr\marshal_cppstd.h>
#include <locale>
using namespace std;
using namespace System::Windows::Forms;
using namespace System::IO;
class Ut
{
public:
	static void ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
		if(from.empty())
			return;
		size_t start_pos = 0;
		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}

	static string ToLower(string s)
	{
		std::locale loc;
		string r;
		for(auto elem : s)
			r += tolower(elem,loc);
		return r;
	}

	static System::String^ ToStringHat(const char *c)
	{
		size_t cSize = strlen(c)+1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs_s (&cSize,wc, cSize, c, cSize);
		System::String^ r = gcnew System::String(wc);
		delete wc;
		return r;
	}

	static string FromStringHat(System::String^ string)
	{
		return msclr::interop::marshal_as<std::string>(string);
	}

	static string ReadAllText(string filename)
	{
		System::String^ file = Ut::ToStringHat(filename.c_str());
		if(File::Exists(file))
			return  FromStringHat(File::ReadAllText(file));
		else
			return string("");
	}

	static DialogResult Error(System::String^ errorstr,MessageBoxButtons buttons = MessageBoxButtons::OK)
	{
		return MessageBox::Show(errorstr,"Dictionary Error",buttons,MessageBoxIcon::Error);
	}

	static DialogResult Info(System::String^ errorstr,MessageBoxButtons buttons = MessageBoxButtons::OK,MessageBoxIcon icon = MessageBoxIcon::Information)
	{
		return MessageBox::Show(errorstr,"Dictionary Info",buttons,icon);
	}
};



#endif