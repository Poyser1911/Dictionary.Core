#pragma once
using namespace System;
using namespace System::Windows::Forms;
namespace DictionaryCore {

	public ref class PSelectorWindow : public System::Windows::Forms::Form
	{
	public:
		PSelectorWindow(void)
		{
			InitializeComponent();
		}

		~PSelectorWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  pos_selection_list;
	private: System::Windows::Forms::Label^  done;
	public: 

		delegate void OnSelectionChanged(String^ poos);
		event OnSelectionChanged^ SelectionChanged;
	private: 

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PSelectorWindow::typeid));
			this->pos_selection_list = (gcnew System::Windows::Forms::ListBox());
			this->done = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// pos_selection_list
			// 
			this->pos_selection_list->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pos_selection_list->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pos_selection_list->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pos_selection_list->FormattingEnabled = true;
			this->pos_selection_list->ItemHeight = 29;
			this->pos_selection_list->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"i.", L"n.", L"t.", L"v.", L"p.", L"pl.", 
				L"pr.", L"vb.", L"adj.", L"adv.", L"imp."});
			this->pos_selection_list->Location = System::Drawing::Point(2, 2);
			this->pos_selection_list->Margin = System::Windows::Forms::Padding(0);
			this->pos_selection_list->Name = L"pos_selection_list";
			this->pos_selection_list->Size = System::Drawing::Size(343, 464);
			this->pos_selection_list->TabIndex = 0;
			// 
			// done
			// 
			this->done->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->done->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->done->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->done->Location = System::Drawing::Point(82, 473);
			this->done->Name = L"done";
			this->done->Size = System::Drawing::Size(173, 44);
			this->done->TabIndex = 24;
			this->done->Text = L"Done";
			this->done->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->done->Click += gcnew System::EventHandler(this, &PSelectorWindow::done_Click);
			// 
			// PSelectorWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(345, 526);
			this->Controls->Add(this->done);
			this->Controls->Add(this->pos_selection_list);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PSelectorWindow";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Part of Speach Modifiers";
			this->Load += gcnew System::EventHandler(this, &PSelectorWindow::PSelectorWindow_Load);
			this->ResumeLayout(false);

		}
#pragma endregion



		System::Void PSelectorWindow_Load(System::Object^  sender, System::EventArgs^  e)
		{
			pos_selection_list->SelectedIndexChanged += gcnew EventHandler(this,&PSelectorWindow::SelectionChangedHandler);
			this->Top -= 80;
		}
		void SelectionChangedHandler(Object^ sender,EventArgs^ e)
		{
			SelectionChanged(pos_selection_list->SelectedItem->ToString());
		}
		System::Void done_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();
		}
	};
}
