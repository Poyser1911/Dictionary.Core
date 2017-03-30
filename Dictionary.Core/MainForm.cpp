#include "MainForm.h"

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DictionaryCore::MainForm form;

	//Opens Form GUI
	Application::Run(%form);
}