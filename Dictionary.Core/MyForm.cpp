#include "MyForm.h"
#include "Api.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is

//Main Entry Point
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DictionaryCore::MyForm form;
	//form.ShowDialog();
	//Opens Form GUI
	Application::Run(%form);

}