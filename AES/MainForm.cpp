#include "MainForm.h"

using namespace SkinSharp;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	// Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	try
	{
		SkinH_Net^ skin = gcnew SkinH_Net();
		skin->AttachEx("Skin.she", "");
	}
	catch (...)
	{
	}

	AES::MainForm form;
	Application::Run(% form);
}