#pragma once

#include <time.h>
#include "Ut.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "ResultSet.h"
#include "Word.h"
#include "ManagedAddWord.h"
#include "ConfigManager.h"
#include "PSelectorWindow.h"
#include "Api.h"

using namespace System::Threading;

namespace DictionaryCore {

#pragma region Constructors
	public ref class MainForm : public Form
	{
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
#pragma endregion

#pragma region UI Controls
	private:
		System::Windows::Forms::TabControl^  TabControl;
		System::Windows::Forms::TabPage^  tabPage1;
		System::Windows::Forms::TabPage^  tabPage2;
		System::Windows::Forms::TabPage^  tabPage3;
		System::Windows::Forms::TabPage^  tabPage4;
		System::Windows::Forms::TabPage^  tabPage5;
		System::Windows::Forms::TabPage^  tabPage6;
		System::Windows::Forms::TabPage^  tabPage7;
		System::Windows::Forms::TabPage^  tabPage8;
		System::Windows::Forms::Label^  parse_time;
		System::Windows::Forms::Label^  sort_status;
		System::Windows::Forms::ProgressBar^  sort_progress;
		System::Windows::Forms::TextBox^  search_box;
		System::Windows::Forms::Label^  search_status;
		System::Windows::Forms::ProgressBar^  search_progress;
		System::Windows::Forms::Label^  label19;
		System::Windows::Forms::TextBox^  add_definition;
		System::Windows::Forms::Label^  label18;
		System::Windows::Forms::TextBox^  add_name;
		System::Windows::Forms::Label^  add_status;
		System::Windows::Forms::ProgressBar^  add_progress;
		System::Windows::Forms::Label^  label13;
		System::Windows::Forms::Label^  validate_status;
		System::Windows::Forms::ProgressBar^  validate_progress;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::GroupBox^  groupBox2;
		System::Windows::Forms::Label^  setting_details;
		System::Windows::Forms::RadioButton^  setting_parsethenadd;
		System::Windows::Forms::Label^  label22;
		System::Windows::Forms::RadioButton^  setting_parseadd;
		System::Windows::Forms::CheckBox^  setting_enableprogress;
		System::Windows::Forms::Label^  label21;
		System::Windows::Forms::ListBox^  setting_filelistbox;
		System::Windows::Forms::TextBox^  setting_filename_box;
		System::Windows::Forms::Label^  about_lastupdated;
		System::Windows::Forms::Label^  about_build;
		System::Windows::Forms::Label^  about_version;
		System::Windows::Forms::ListBox^  about_authors;
		System::Windows::Forms::Label^  label24;
		System::Windows::Forms::MenuStrip^  menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^  ds_selector;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::ProgressBar^  progressBar1;
		System::Windows::Forms::Label^  parse_run;

		System::Windows::Forms::PictureBox^  pictureBox2;
		System::Windows::Forms::Label^  sort_time;
		System::Windows::Forms::Label^  sort_run;
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
		System::Windows::Forms::Label^  search_time;
		System::Windows::Forms::Label^  search_run;
		System::Windows::Forms::PictureBox^  pictureBox3;
		System::Windows::Forms::Label^  label10;
		System::Windows::Forms::Label^  wordfound;
		System::Windows::Forms::Label^  add_time;
		System::Windows::Forms::Label^  add_run;
		System::Windows::Forms::PictureBox^  pictureBox4;
		System::Windows::Forms::Label^  pos_selector_run;
		System::Windows::Forms::Label^  skip_run;
		System::Windows::Forms::Label^  view_time;
		System::Windows::Forms::Label^  view_run;
		System::Windows::Forms::Label^  label17;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::Label^  label6;
		System::Windows::Forms::RichTextBox^  wordout_box;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::TextBox^  validate_box;
		System::Windows::Forms::Label^  label7;
		System::Windows::Forms::Label^  validate_time;
		System::Windows::Forms::Label^  validate_run;
		System::Windows::Forms::PictureBox^  pictureBox5;
		System::Windows::Forms::Label^  setting_addfile_run;
		System::Windows::Forms::Label^  setting_browse_run;
		System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  add_pos_string;
			 System::ComponentModel::IContainer^  components;
			 /// <summary>
			 /// Required designer variable.
			 /// </summary>

#pragma endregion

#pragma region For Windows Form Designer, modify too much = no designer editor
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
				 this->TabControl = (gcnew System::Windows::Forms::TabControl());
				 this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->parse_time = (gcnew System::Windows::Forms::Label());
				 this->parse_run = (gcnew System::Windows::Forms::Label());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->sort_time = (gcnew System::Windows::Forms::Label());
				 this->sort_run = (gcnew System::Windows::Forms::Label());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->sort_status = (gcnew System::Windows::Forms::Label());
				 this->sort_progress = (gcnew System::Windows::Forms::ProgressBar());
				 this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->wordfound = (gcnew System::Windows::Forms::Label());
				 this->search_box = (gcnew System::Windows::Forms::TextBox());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->search_time = (gcnew System::Windows::Forms::Label());
				 this->search_run = (gcnew System::Windows::Forms::Label());
				 this->search_status = (gcnew System::Windows::Forms::Label());
				 this->search_progress = (gcnew System::Windows::Forms::ProgressBar());
				 this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
				 this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
				 this->add_pos_string = (gcnew System::Windows::Forms::Label());
				 this->pos_selector_run = (gcnew System::Windows::Forms::Label());
				 this->skip_run = (gcnew System::Windows::Forms::Label());
				 this->add_time = (gcnew System::Windows::Forms::Label());
				 this->add_run = (gcnew System::Windows::Forms::Label());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 this->add_definition = (gcnew System::Windows::Forms::TextBox());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->add_name = (gcnew System::Windows::Forms::TextBox());
				 this->add_status = (gcnew System::Windows::Forms::Label());
				 this->add_progress = (gcnew System::Windows::Forms::ProgressBar());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
				 this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
				 this->wordout_box = (gcnew System::Windows::Forms::RichTextBox());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->view_time = (gcnew System::Windows::Forms::Label());
				 this->view_run = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				 this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->validate_box = (gcnew System::Windows::Forms::TextBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->validate_time = (gcnew System::Windows::Forms::Label());
				 this->validate_run = (gcnew System::Windows::Forms::Label());
				 this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
				 this->validate_status = (gcnew System::Windows::Forms::Label());
				 this->validate_progress = (gcnew System::Windows::Forms::ProgressBar());
				 this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
				 this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				 this->setting_details = (gcnew System::Windows::Forms::Label());
				 this->setting_parsethenadd = (gcnew System::Windows::Forms::RadioButton());
				 this->label22 = (gcnew System::Windows::Forms::Label());
				 this->setting_parseadd = (gcnew System::Windows::Forms::RadioButton());
				 this->setting_enableprogress = (gcnew System::Windows::Forms::CheckBox());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->setting_addfile_run = (gcnew System::Windows::Forms::Label());
				 this->setting_browse_run = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label21 = (gcnew System::Windows::Forms::Label());
				 this->setting_filelistbox = (gcnew System::Windows::Forms::ListBox());
				 this->setting_filename_box = (gcnew System::Windows::Forms::TextBox());
				 this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
				 this->about_lastupdated = (gcnew System::Windows::Forms::Label());
				 this->about_build = (gcnew System::Windows::Forms::Label());
				 this->about_version = (gcnew System::Windows::Forms::Label());
				 this->about_authors = (gcnew System::Windows::Forms::ListBox());
				 this->label24 = (gcnew System::Windows::Forms::Label());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->ds_selector = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->TabControl->SuspendLayout();
				 this->tabPage1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
				 this->tabPage2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
				 this->tabPage3->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
				 this->tabPage4->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
				 this->tabPage5->SuspendLayout();
				 this->tabPage6->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
				 this->tabPage7->SuspendLayout();
				 this->groupBox2->SuspendLayout();
				 this->groupBox1->SuspendLayout();
				 this->tabPage8->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // TabControl
				 // 
				 this->TabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
					 | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->TabControl->Controls->Add(this->tabPage1);
				 this->TabControl->Controls->Add(this->tabPage2);
				 this->TabControl->Controls->Add(this->tabPage3);
				 this->TabControl->Controls->Add(this->tabPage4);
				 this->TabControl->Controls->Add(this->tabPage5);
				 this->TabControl->Controls->Add(this->tabPage6);
				 this->TabControl->Controls->Add(this->tabPage7);
				// this->TabControl->Controls->Add(this->tabPage8);
				 this->TabControl->ItemSize = System::Drawing::Size(0, 20);
				 this->TabControl->Location = System::Drawing::Point(0, 31);
				 this->TabControl->Name = L"TabControl";
				 this->TabControl->SelectedIndex = 0;
				 this->TabControl->Size = System::Drawing::Size(1128, 627);
				 this->TabControl->TabIndex = 0;
				 // 
				 // tabPage1
				 // 
				 this->tabPage1->BackColor = System::Drawing::Color::White;
				 this->tabPage1->Controls->Add(this->label3);
				 this->tabPage1->Controls->Add(this->parse_time);
				 this->tabPage1->Controls->Add(this->parse_run);
				 this->tabPage1->Controls->Add(this->pictureBox2);
				 this->tabPage1->Location = System::Drawing::Point(4, 24);
				 this->tabPage1->Name = L"tabPage1";
				 this->tabPage1->Size = System::Drawing::Size(1120, 599);
				 this->tabPage1->TabIndex = 0;
				 this->tabPage1->Text = L"Parse";
				 // 
				 // label3
				 // 
				 this->label3->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label3->Location = System::Drawing::Point(2, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(187, 48);
				 this->label3->TabIndex = 23;
				 this->label3->Text = L"Parse Data";
				 // 
				 // parse_time
				 // 
				 this->parse_time->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->parse_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 50.24999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->parse_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->parse_time->Location = System::Drawing::Point(422, 217);
				 this->parse_time->Name = L"parse_time";
				 this->parse_time->Size = System::Drawing::Size(223, 68);
				 this->parse_time->TabIndex = 4;
				 this->parse_time->Text = L"00:00";
				 this->parse_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // parse_run
				 // 
				 this->parse_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->parse_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->parse_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 54.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->parse_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->parse_run->Location = System::Drawing::Point(421, 109);
				 this->parse_run->Name = L"parse_run";
				 this->parse_run->Size = System::Drawing::Size(232, 124);
				 this->parse_run->TabIndex = 9;
				 this->parse_run->Text = L"Start";
				 this->parse_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
				 this->pictureBox2->InitialImage = nullptr;
				 this->pictureBox2->Location = System::Drawing::Point(185, -67);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(707, 528);
				 this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox2->TabIndex = 18;
				 this->pictureBox2->TabStop = false;
				 // 
				 // tabPage2
				 // 
				 this->tabPage2->BackColor = System::Drawing::Color::White;
				 this->tabPage2->Controls->Add(this->label4);
				 this->tabPage2->Controls->Add(this->sort_time);
				 this->tabPage2->Controls->Add(this->sort_run);
				 this->tabPage2->Controls->Add(this->pictureBox1);
				 this->tabPage2->Controls->Add(this->sort_status);
				 this->tabPage2->Controls->Add(this->sort_progress);
				 this->tabPage2->Location = System::Drawing::Point(4, 24);
				 this->tabPage2->Name = L"tabPage2";
				 this->tabPage2->Size = System::Drawing::Size(1120, 599);
				 this->tabPage2->TabIndex = 0;
				 this->tabPage2->Text = L"Sort";
				 // 
				 // label4
				 // 
				 this->label4->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label4->Location = System::Drawing::Point(2, 2);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(187, 48);
				 this->label4->TabIndex = 23;
				 this->label4->Text = L"Sort Data";
				 // 
				 // sort_time
				 // 
				 this->sort_time->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->sort_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 50.24999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->sort_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->sort_time->Location = System::Drawing::Point(422, 217);
				 this->sort_time->Name = L"sort_time";
				 this->sort_time->Size = System::Drawing::Size(223, 68);
				 this->sort_time->TabIndex = 19;
				 this->sort_time->Text = L"00:00";
				 this->sort_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sort_run
				 // 
				 this->sort_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->sort_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->sort_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 54.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->sort_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->sort_run->Location = System::Drawing::Point(421, 109);
				 this->sort_run->Name = L"sort_run";
				 this->sort_run->Size = System::Drawing::Size(232, 124);
				 this->sort_run->TabIndex = 20;
				 this->sort_run->Text = L"Start";
				 this->sort_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->InitialImage = nullptr;
				 this->pictureBox1->Location = System::Drawing::Point(185, -67);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(707, 528);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox1->TabIndex = 21;
				 this->pictureBox1->TabStop = false;
				 // 
				 // sort_status
				 // 
				 this->sort_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->sort_status->AutoEllipsis = true;
				 this->sort_status->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->sort_status->Location = System::Drawing::Point(2, 676);
				 this->sort_status->Name = L"sort_status";
				 this->sort_status->Size = System::Drawing::Size(219, 28);
				 this->sort_status->TabIndex = 14;
				 this->sort_status->Text = L"Status";
				 // 
				 // sort_progress
				 // 
				 this->sort_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sort_progress->Location = System::Drawing::Point(229, 676);
				 this->sort_progress->Name = L"sort_progress";
				 this->sort_progress->Size = System::Drawing::Size(1059, 28);
				 this->sort_progress->TabIndex = 13;
				 // 
				 // tabPage3
				 // 
				 this->tabPage3->BackColor = System::Drawing::Color::White;
				 this->tabPage3->Controls->Add(this->label5);
				 this->tabPage3->Controls->Add(this->wordfound);
				 this->tabPage3->Controls->Add(this->search_box);
				 this->tabPage3->Controls->Add(this->label10);
				 this->tabPage3->Controls->Add(this->search_time);
				 this->tabPage3->Controls->Add(this->search_run);
				 this->tabPage3->Controls->Add(this->search_status);
				 this->tabPage3->Controls->Add(this->search_progress);
				 this->tabPage3->Controls->Add(this->pictureBox3);
				 this->tabPage3->Location = System::Drawing::Point(4, 24);
				 this->tabPage3->Name = L"tabPage3";
				 this->tabPage3->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage3->Size = System::Drawing::Size(1120, 599);
				 this->tabPage3->TabIndex = 1;
				 this->tabPage3->Text = L"Search";
				 // 
				 // label5
				 // 
				 this->label5->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label5->Location = System::Drawing::Point(2, 2);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(197, 48);
				 this->label5->TabIndex = 26;
				 this->label5->Text = L"Search Word";
				 // 
				 // wordfound
				 // 
				 this->wordfound->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->wordfound->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->wordfound->Location = System::Drawing::Point(4, 464);
				 this->wordfound->Name = L"wordfound";
				 this->wordfound->Size = System::Drawing::Size(1118, 112);
				 this->wordfound->TabIndex = 25;
				 this->wordfound->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // search_box
				 // 
				 this->search_box->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->search_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->search_box->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->search_box->Location = System::Drawing::Point(326, 433);
				 this->search_box->Name = L"search_box";
				 this->search_box->Size = System::Drawing::Size(436, 29);
				 this->search_box->TabIndex = 15;
				 this->search_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->search_box->WordWrap = false;
				 // 
				 // label10
				 // 
				 this->label10->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label10->BackColor = System::Drawing::Color::Transparent;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label10->Location = System::Drawing::Point(326, 399);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(436, 25);
				 this->label10->TabIndex = 9;
				 this->label10->Text = L"Search Word";
				 this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // search_time
				 // 
				 this->search_time->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->search_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 50.24999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->search_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->search_time->Location = System::Drawing::Point(422, 217);
				 this->search_time->Name = L"search_time";
				 this->search_time->Size = System::Drawing::Size(223, 68);
				 this->search_time->TabIndex = 22;
				 this->search_time->Text = L"00:00";
				 this->search_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // search_run
				 // 
				 this->search_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->search_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->search_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 54.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->search_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->search_run->Location = System::Drawing::Point(421, 109);
				 this->search_run->Name = L"search_run";
				 this->search_run->Size = System::Drawing::Size(232, 124);
				 this->search_run->TabIndex = 23;
				 this->search_run->Text = L"Start";
				 this->search_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // search_status
				 // 
				 this->search_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->search_status->AutoEllipsis = true;
				 this->search_status->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->search_status->Location = System::Drawing::Point(2, 718);
				 this->search_status->Name = L"search_status";
				 this->search_status->Size = System::Drawing::Size(219, 28);
				 this->search_status->TabIndex = 14;
				 this->search_status->Text = L"Status";
				 // 
				 // search_progress
				 // 
				 this->search_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->search_progress->Location = System::Drawing::Point(229, 718);
				 this->search_progress->Name = L"search_progress";
				 this->search_progress->Size = System::Drawing::Size(1055, 28);
				 this->search_progress->TabIndex = 13;
				 // 
				 // pictureBox3
				 // 
				 this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
				 this->pictureBox3->InitialImage = nullptr;
				 this->pictureBox3->Location = System::Drawing::Point(185, -67);
				 this->pictureBox3->Name = L"pictureBox3";
				 this->pictureBox3->Size = System::Drawing::Size(707, 528);
				 this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox3->TabIndex = 24;
				 this->pictureBox3->TabStop = false;
				 // 
				 // tabPage4
				 // 
				 this->tabPage4->BackColor = System::Drawing::Color::White;
				 this->tabPage4->Controls->Add(this->add_pos_string);
				 this->tabPage4->Controls->Add(this->pos_selector_run);
				 this->tabPage4->Controls->Add(this->skip_run);
				 this->tabPage4->Controls->Add(this->add_time);
				 this->tabPage4->Controls->Add(this->add_run);
				 this->tabPage4->Controls->Add(this->label19);
				 this->tabPage4->Controls->Add(this->add_definition);
				 this->tabPage4->Controls->Add(this->label18);
				 this->tabPage4->Controls->Add(this->label17);
				 this->tabPage4->Controls->Add(this->add_name);
				 this->tabPage4->Controls->Add(this->add_status);
				 this->tabPage4->Controls->Add(this->add_progress);
				 this->tabPage4->Controls->Add(this->label13);
				 this->tabPage4->Controls->Add(this->pictureBox4);
				 this->tabPage4->Location = System::Drawing::Point(4, 24);
				 this->tabPage4->Name = L"tabPage4";
				 this->tabPage4->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage4->Size = System::Drawing::Size(1120, 599);
				 this->tabPage4->TabIndex = 2;
				 this->tabPage4->Text = L"Add";
				 // 
				 // add_pos_string
				 // 
				 this->add_pos_string->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->add_pos_string->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_pos_string->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->add_pos_string->Location = System::Drawing::Point(336, 465);
				 this->add_pos_string->Margin = System::Windows::Forms::Padding(0);
				 this->add_pos_string->Name = L"add_pos_string";
				 this->add_pos_string->Size = System::Drawing::Size(556, 34);
				 this->add_pos_string->TabIndex = 33;
				 this->add_pos_string->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // pos_selector_run
				 // 
				 this->pos_selector_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pos_selector_run->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pos_selector_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->pos_selector_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->pos_selector_run->Location = System::Drawing::Point(185, 465);
				 this->pos_selector_run->Margin = System::Windows::Forms::Padding(0);
				 this->pos_selector_run->Name = L"pos_selector_run";
				 this->pos_selector_run->Size = System::Drawing::Size(138, 34);
				 this->pos_selector_run->TabIndex = 32;
				 this->pos_selector_run->Text = L"Select";
				 this->pos_selector_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // skip_run
				 // 
				 this->skip_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->skip_run->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->skip_run->Enabled = false;
				 this->skip_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->skip_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->skip_run->Location = System::Drawing::Point(729, 419);
				 this->skip_run->Name = L"skip_run";
				 this->skip_run->Size = System::Drawing::Size(163, 34);
				 this->skip_run->TabIndex = 31;
				 this->skip_run->Text = L"Skip >>";
				 this->skip_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->skip_run->Click += gcnew System::EventHandler(this, &MainForm::skip_run_Click);
				 // 
				 // add_time
				 // 
				 this->add_time->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->add_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 50.24999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->add_time->Location = System::Drawing::Point(422, 217);
				 this->add_time->Name = L"add_time";
				 this->add_time->Size = System::Drawing::Size(223, 68);
				 this->add_time->TabIndex = 28;
				 this->add_time->Text = L"00:00";
				 this->add_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // add_run
				 // 
				 this->add_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->add_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->add_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 54.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->add_run->Location = System::Drawing::Point(421, 109);
				 this->add_run->Name = L"add_run";
				 this->add_run->Size = System::Drawing::Size(232, 124);
				 this->add_run->TabIndex = 29;
				 this->add_run->Text = L"Start";
				 this->add_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // label19
				 // 
				 this->label19->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label19->AutoSize = true;
				 this->label19->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label19->Location = System::Drawing::Point(59, 472);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(121, 23);
				 this->label19->TabIndex = 25;
				 this->label19->Text = L"Part of Speach";
				 // 
				 // add_definition
				 // 
				 this->add_definition->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->add_definition->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_definition->Location = System::Drawing::Point(185, 508);
				 this->add_definition->Multiline = true;
				 this->add_definition->Name = L"add_definition";
				 this->add_definition->Size = System::Drawing::Size(707, 34);
				 this->add_definition->TabIndex = 24;
				 // 
				 // label18
				 // 
				 this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label18->AutoSize = true;
				 this->label18->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label18->Location = System::Drawing::Point(95, 519);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(86, 23);
				 this->label18->TabIndex = 23;
				 this->label18->Text = L"Definition";
				 // 
				 // label17
				 // 
				 this->label17->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label17->Location = System::Drawing::Point(0, 2);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(187, 48);
				 this->label17->TabIndex = 22;
				 this->label17->Text = L"Add Word";
				 // 
				 // add_name
				 // 
				 this->add_name->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->add_name->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_name->Location = System::Drawing::Point(185, 419);
				 this->add_name->Multiline = true;
				 this->add_name->Name = L"add_name";
				 this->add_name->Size = System::Drawing::Size(307, 34);
				 this->add_name->TabIndex = 21;
				 // 
				 // add_status
				 // 
				 this->add_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->add_status->AutoEllipsis = true;
				 this->add_status->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->add_status->Location = System::Drawing::Point(2, 676);
				 this->add_status->Name = L"add_status";
				 this->add_status->Size = System::Drawing::Size(219, 28);
				 this->add_status->TabIndex = 20;
				 this->add_status->Text = L"Status";
				 // 
				 // add_progress
				 // 
				 this->add_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->add_progress->Location = System::Drawing::Point(229, 676);
				 this->add_progress->Name = L"add_progress";
				 this->add_progress->Size = System::Drawing::Size(1059, 28);
				 this->add_progress->TabIndex = 19;
				 // 
				 // label13
				 // 
				 this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label13->AutoSize = true;
				 this->label13->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label13->Location = System::Drawing::Point(125, 423);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(55, 23);
				 this->label13->TabIndex = 16;
				 this->label13->Text = L"Name";
				 // 
				 // pictureBox4
				 // 
				 this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
				 this->pictureBox4->InitialImage = nullptr;
				 this->pictureBox4->Location = System::Drawing::Point(185, -67);
				 this->pictureBox4->Name = L"pictureBox4";
				 this->pictureBox4->Size = System::Drawing::Size(707, 528);
				 this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox4->TabIndex = 30;
				 this->pictureBox4->TabStop = false;
				 // 
				 // tabPage5
				 // 
				 this->tabPage5->BackColor = System::Drawing::Color::White;
				 this->tabPage5->Controls->Add(this->wordout_box);
				 this->tabPage5->Controls->Add(this->label6);
				 this->tabPage5->Controls->Add(this->view_time);
				 this->tabPage5->Controls->Add(this->view_run);
				 this->tabPage5->Controls->Add(this->label1);
				 this->tabPage5->Controls->Add(this->progressBar1);
				 this->tabPage5->Location = System::Drawing::Point(4, 24);
				 this->tabPage5->Name = L"tabPage5";
				 this->tabPage5->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage5->Size = System::Drawing::Size(1120, 599);
				 this->tabPage5->TabIndex = 3;
				 this->tabPage5->Text = L"View";
				 // 
				 // wordout_box
				 // 
				 this->wordout_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
					 | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->wordout_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
				 this->wordout_box->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->wordout_box->Location = System::Drawing::Point(0, 45);
				 this->wordout_box->Name = L"wordout_box";
				 this->wordout_box->ReadOnly = true;
				 this->wordout_box->Size = System::Drawing::Size(1120, 554);
				 this->wordout_box->TabIndex = 34;
				 this->wordout_box->Text = L"";
				 // 
				 // label6
				 // 
				 this->label6->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label6->Location = System::Drawing::Point(2, 2);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(187, 48);
				 this->label6->TabIndex = 33;
				 this->label6->Text = L"All Words";
				 // 
				 // view_time
				 // 
				 this->view_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->view_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->view_time->Location = System::Drawing::Point(509, 7);
				 this->view_time->Name = L"view_time";
				 this->view_time->Size = System::Drawing::Size(105, 34);
				 this->view_time->TabIndex = 28;
				 this->view_time->Text = L"00:00";
				 this->view_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // view_run
				 // 
				 this->view_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->view_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->view_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->view_run->Location = System::Drawing::Point(381, -2);
				 this->view_run->Name = L"view_run";
				 this->view_run->Size = System::Drawing::Size(98, 52);
				 this->view_run->TabIndex = 29;
				 this->view_run->Text = L"Start";
				 this->view_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // label1
				 // 
				 this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->label1->AutoEllipsis = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(2, 676);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(219, 28);
				 this->label1->TabIndex = 14;
				 this->label1->Text = L"Status";
				 // 
				 // progressBar1
				 // 
				 this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->progressBar1->Location = System::Drawing::Point(229, 676);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(1059, 28);
				 this->progressBar1->TabIndex = 13;
				 // 
				 // tabPage6
				 // 
				 this->tabPage6->BackColor = System::Drawing::Color::White;
				 this->tabPage6->Controls->Add(this->label2);
				 this->tabPage6->Controls->Add(this->validate_box);
				 this->tabPage6->Controls->Add(this->label7);
				 this->tabPage6->Controls->Add(this->validate_time);
				 this->tabPage6->Controls->Add(this->validate_run);
				 this->tabPage6->Controls->Add(this->pictureBox5);
				 this->tabPage6->Controls->Add(this->validate_status);
				 this->tabPage6->Controls->Add(this->validate_progress);
				 this->tabPage6->Location = System::Drawing::Point(4, 24);
				 this->tabPage6->Name = L"tabPage6";
				 this->tabPage6->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage6->Size = System::Drawing::Size(1120, 599);
				 this->tabPage6->TabIndex = 4;
				 this->tabPage6->Text = L"Validate";
				 // 
				 // label2
				 // 
				 this->label2->Font = (gcnew System::Drawing::Font(L"Komika Axis", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label2->Location = System::Drawing::Point(2, 2);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(266, 48);
				 this->label2->TabIndex = 32;
				 this->label2->Text = L"Validate Sentense";
				 // 
				 // validate_box
				 // 
				 this->validate_box->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->validate_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->validate_box->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->validate_box->Location = System::Drawing::Point(185, 432);
				 this->validate_box->Name = L"validate_box";
				 this->validate_box->Size = System::Drawing::Size(707, 29);
				 this->validate_box->TabIndex = 28;
				 this->validate_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->validate_box->WordWrap = false;
				 // 
				 // label7
				 // 
				 this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label7->Location = System::Drawing::Point(326, 398);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(436, 25);
				 this->label7->TabIndex = 27;
				 this->label7->Text = L"Enter Sentense";
				 this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // validate_time
				 // 
				 this->validate_time->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->validate_time->Font = (gcnew System::Drawing::Font(L"Digital-7", 50.24999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->validate_time->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->validate_time->Location = System::Drawing::Point(422, 217);
				 this->validate_time->Name = L"validate_time";
				 this->validate_time->Size = System::Drawing::Size(223, 68);
				 this->validate_time->TabIndex = 29;
				 this->validate_time->Text = L"00:00";
				 this->validate_time->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // validate_run
				 // 
				 this->validate_run->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->validate_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->validate_run->Font = (gcnew System::Drawing::Font(L"Digital-7", 54.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->validate_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->validate_run->Location = System::Drawing::Point(421, 109);
				 this->validate_run->Name = L"validate_run";
				 this->validate_run->Size = System::Drawing::Size(232, 124);
				 this->validate_run->TabIndex = 30;
				 this->validate_run->Text = L"Start";
				 this->validate_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pictureBox5
				 // 
				 this->pictureBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
				 this->pictureBox5->InitialImage = nullptr;
				 this->pictureBox5->Location = System::Drawing::Point(185, -67);
				 this->pictureBox5->Name = L"pictureBox5";
				 this->pictureBox5->Size = System::Drawing::Size(707, 528);
				 this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox5->TabIndex = 31;
				 this->pictureBox5->TabStop = false;
				 // 
				 // validate_status
				 // 
				 this->validate_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->validate_status->AutoEllipsis = true;
				 this->validate_status->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->validate_status->Location = System::Drawing::Point(2, 676);
				 this->validate_status->Name = L"validate_status";
				 this->validate_status->Size = System::Drawing::Size(219, 28);
				 this->validate_status->TabIndex = 26;
				 this->validate_status->Text = L"Status";
				 // 
				 // validate_progress
				 // 
				 this->validate_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->validate_progress->Location = System::Drawing::Point(237, 676);
				 this->validate_progress->Name = L"validate_progress";
				 this->validate_progress->Size = System::Drawing::Size(1051, 28);
				 this->validate_progress->TabIndex = 25;
				 // 
				 // tabPage7
				 // 
				 this->tabPage7->BackColor = System::Drawing::Color::White;
				 this->tabPage7->Controls->Add(this->groupBox2);
				 this->tabPage7->Controls->Add(this->groupBox1);
				 this->tabPage7->Location = System::Drawing::Point(4, 24);
				 this->tabPage7->Name = L"tabPage7";
				 this->tabPage7->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage7->Size = System::Drawing::Size(1120, 599);
				 this->tabPage7->TabIndex = 5;
				 this->tabPage7->Text = L"Settings";
				 // 
				 // groupBox2
				 // 
				 this->groupBox2->AccessibleRole = System::Windows::Forms::AccessibleRole::IpAddress;
				 this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
					 | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->groupBox2->Controls->Add(this->setting_details);
				 this->groupBox2->Controls->Add(this->setting_parsethenadd);
				 this->groupBox2->Controls->Add(this->label22);
				 this->groupBox2->Controls->Add(this->setting_parseadd);
				 this->groupBox2->Controls->Add(this->setting_enableprogress);
				 this->groupBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->groupBox2->Location = System::Drawing::Point(20, 405);
				 this->groupBox2->Name = L"groupBox2";
				 this->groupBox2->Size = System::Drawing::Size(1049, 174);
				 this->groupBox2->TabIndex = 1;
				 this->groupBox2->TabStop = false;
				 this->groupBox2->Text = L"Program Settings";
				 this->groupBox2->Visible = false;
				 // 
				 // setting_details
				 // 
				 this->setting_details->Location = System::Drawing::Point(477, 39);
				 this->setting_details->Name = L"setting_details";
				 this->setting_details->Size = System::Drawing::Size(575, 33);
				 this->setting_details->TabIndex = 8;
				 this->setting_details->Text = L"<Parse Mode Details On Hover>";
				 this->setting_details->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // setting_parsethenadd
				 // 
				 this->setting_parsethenadd->Location = System::Drawing::Point(267, 42);
				 this->setting_parsethenadd->Name = L"setting_parsethenadd";
				 this->setting_parsethenadd->Size = System::Drawing::Size(168, 29);
				 this->setting_parsethenadd->TabIndex = 7;
				 this->setting_parsethenadd->TabStop = true;
				 this->setting_parsethenadd->Text = L"Parse Then Insert";
				 this->setting_parsethenadd->UseVisualStyleBackColor = true;
				 // 
				 // label22
				 // 
				 this->label22->Location = System::Drawing::Point(8, 37);
				 this->label22->Name = L"label22";
				 this->label22->Size = System::Drawing::Size(111, 33);
				 this->label22->TabIndex = 6;
				 this->label22->Text = L"Parse Mode: ";
				 this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // setting_parseadd
				 // 
				 this->setting_parseadd->Location = System::Drawing::Point(126, 42);
				 this->setting_parseadd->Name = L"setting_parseadd";
				 this->setting_parseadd->Size = System::Drawing::Size(192, 29);
				 this->setting_parseadd->TabIndex = 2;
				 this->setting_parseadd->TabStop = true;
				 this->setting_parseadd->Text = L"Parse and Insert";
				 this->setting_parseadd->UseVisualStyleBackColor = true;
				 // 
				 // setting_enableprogress
				 // 
				 this->setting_enableprogress->AutoSize = true;
				 this->setting_enableprogress->Location = System::Drawing::Point(10, 107);
				 this->setting_enableprogress->Name = L"setting_enableprogress";
				 this->setting_enableprogress->Size = System::Drawing::Size(144, 21);
				 this->setting_enableprogress->TabIndex = 1;
				 this->setting_enableprogress->Text = L"Enable ProgressBar";
				 this->setting_enableprogress->UseVisualStyleBackColor = true;
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->groupBox1->Controls->Add(this->setting_addfile_run);
				 this->groupBox1->Controls->Add(this->setting_browse_run);
				 this->groupBox1->Controls->Add(this->label8);
				 this->groupBox1->Controls->Add(this->label21);
				 this->groupBox1->Controls->Add(this->setting_filelistbox);
				 this->groupBox1->Controls->Add(this->setting_filename_box);
				 this->groupBox1->Font = (gcnew System::Drawing::Font(L"Komika Axis", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->groupBox1->Location = System::Drawing::Point(20, 27);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(1049, 372);
				 this->groupBox1->TabIndex = 0;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Dictionary Word List Files";
				 // 
				 // setting_addfile_run
				 // 
				 this->setting_addfile_run->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->setting_addfile_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->setting_addfile_run->Font = (gcnew System::Drawing::Font(L"Komika Axis", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->setting_addfile_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->setting_addfile_run->Location = System::Drawing::Point(451, 31);
				 this->setting_addfile_run->Name = L"setting_addfile_run";
				 this->setting_addfile_run->Size = System::Drawing::Size(91, 29);
				 this->setting_addfile_run->TabIndex = 32;
				 this->setting_addfile_run->Text = L"Add";
				 this->setting_addfile_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->setting_addfile_run->Click += gcnew System::EventHandler(this, &MainForm::setting_addfile_run_Click);
				 // 
				 // setting_browse_run
				 // 
				 this->setting_browse_run->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->setting_browse_run->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->setting_browse_run->Font = (gcnew System::Drawing::Font(L"Komika Axis", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->setting_browse_run->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->setting_browse_run->Location = System::Drawing::Point(364, 31);
				 this->setting_browse_run->Name = L"setting_browse_run";
				 this->setting_browse_run->Size = System::Drawing::Size(81, 29);
				 this->setting_browse_run->TabIndex = 31;
				 this->setting_browse_run->Text = L"Browse";
				 this->setting_browse_run->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->setting_browse_run->Click += gcnew System::EventHandler(this, &MainForm::setting_browse_run_Click);
				 // 
				 // label8
				 // 
				 this->label8->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Komika Axis", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label8->Location = System::Drawing::Point(4, 25);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(81, 38);
				 this->label8->TabIndex = 30;
				 this->label8->Text = L"File Path";
				 this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // label21
				 // 
				 this->label21->Font = (gcnew System::Drawing::Font(L"Komika Axis", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label21->Location = System::Drawing::Point(23, 87);
				 this->label21->Name = L"label21";
				 this->label21->Size = System::Drawing::Size(565, 33);
				 this->label21->TabIndex = 5;
				 this->label21->Text = L"File List";
				 this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // setting_filelistbox
				 // 
				 this->setting_filelistbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				 this->setting_filelistbox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->setting_filelistbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->setting_filelistbox->FormattingEnabled = true;
				 this->setting_filelistbox->ItemHeight = 18;
				 this->setting_filelistbox->Location = System::Drawing::Point(27, 123);
				 this->setting_filelistbox->Name = L"setting_filelistbox";
				 this->setting_filelistbox->Size = System::Drawing::Size(561, 180);
				 this->setting_filelistbox->TabIndex = 4;
				 // 
				 // setting_filename_box
				 // 
				 this->setting_filename_box->Location = System::Drawing::Point(86, 31);
				 this->setting_filename_box->Multiline = true;
				 this->setting_filename_box->Name = L"setting_filename_box";
				 this->setting_filename_box->Size = System::Drawing::Size(272, 29);
				 this->setting_filename_box->TabIndex = 1;
				 // 
				 // tabPage8
				 // 
				 this->tabPage8->BackColor = System::Drawing::Color::White;
				 this->tabPage8->Controls->Add(this->about_lastupdated);
				 this->tabPage8->Controls->Add(this->about_build);
				 this->tabPage8->Controls->Add(this->about_version);
				 this->tabPage8->Controls->Add(this->about_authors);
				 this->tabPage8->Controls->Add(this->label24);
				 this->tabPage8->Location = System::Drawing::Point(4, 24);
				 this->tabPage8->Name = L"tabPage8";
				 this->tabPage8->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage8->Size = System::Drawing::Size(1120, 599);
				 this->tabPage8->TabIndex = 6;
				 this->tabPage8->Text = L"About";
				 this->tabPage8->Visible = false;
				 // 
				 // about_lastupdated
				 // 
				 this->about_lastupdated->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->about_lastupdated->Font = (gcnew System::Drawing::Font(L"Komika Axis", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->about_lastupdated->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->about_lastupdated->Location = System::Drawing::Point(287, 429);
				 this->about_lastupdated->Name = L"about_lastupdated";
				 this->about_lastupdated->Size = System::Drawing::Size(349, 40);
				 this->about_lastupdated->TabIndex = 4;
				 this->about_lastupdated->Text = L"Last Updated: kys";
				 this->about_lastupdated->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // about_build
				 // 
				 this->about_build->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->about_build->Font = (gcnew System::Drawing::Font(L"Komika Axis", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->about_build->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->about_build->Location = System::Drawing::Point(287, 343);
				 this->about_build->Name = L"about_build";
				 this->about_build->Size = System::Drawing::Size(349, 40);
				 this->about_build->TabIndex = 3;
				 this->about_build->Text = L"Build: #kys";
				 this->about_build->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // about_version
				 // 
				 this->about_version->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->about_version->Font = (gcnew System::Drawing::Font(L"Komika Axis", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->about_version->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->about_version->Location = System::Drawing::Point(287, 383);
				 this->about_version->Name = L"about_version";
				 this->about_version->Size = System::Drawing::Size(349, 40);
				 this->about_version->TabIndex = 2;
				 this->about_version->Text = L"Version: Kys";
				 this->about_version->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // about_authors
				 // 
				 this->about_authors->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->about_authors->BorderStyle = System::Windows::Forms::BorderStyle::None;
				 this->about_authors->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->about_authors->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->about_authors->FormattingEnabled = true;
				 this->about_authors->ItemHeight = 25;
				 this->about_authors->Location = System::Drawing::Point(400, 144);
				 this->about_authors->Name = L"about_authors";
				 this->about_authors->Size = System::Drawing::Size(357, 125);
				 this->about_authors->TabIndex = 1;
				 // 
				 // label24
				 // 
				 this->label24->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->label24->Font = (gcnew System::Drawing::Font(L"Komika Axis", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label24->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(190)), 
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->label24->Location = System::Drawing::Point(408, 100);
				 this->label24->Name = L"label24";
				 this->label24->Size = System::Drawing::Size(349, 40);
				 this->label24->TabIndex = 0;
				 this->label24->Text = L"Authors";
				 this->label24->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->BackColor = System::Drawing::Color::White;
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->ds_selector, this->toolStripMenuItem1});
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
				 this->menuStrip1->Size = System::Drawing::Size(1128, 24);
				 this->menuStrip1->TabIndex = 7;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // ds_selector
				 // 
				 this->ds_selector->ForeColor = System::Drawing::Color::Black;
				 this->ds_selector->Name = L"ds_selector";
				 this->ds_selector->Size = System::Drawing::Size(128, 20);
				 this->ds_selector->Text = L"Select Data Structure";
				 // 
				 // toolStripMenuItem1
				 // 
				 this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				 this->toolStripMenuItem1->Size = System::Drawing::Size(22, 20);
				 this->toolStripMenuItem1->Text = L" ";
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1128, 656);
				 this->Controls->Add(this->TabControl);
				 this->Controls->Add(this->menuStrip1);
				 this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MainForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Dictionary";
				 this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				 this->TabControl->ResumeLayout(false);
				 this->tabPage1->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
				 this->tabPage2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
				 this->tabPage3->ResumeLayout(false);
				 this->tabPage3->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
				 this->tabPage4->ResumeLayout(false);
				 this->tabPage4->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
				 this->tabPage5->ResumeLayout(false);
				 this->tabPage6->ResumeLayout(false);
				 this->tabPage6->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
				 this->tabPage7->ResumeLayout(false);
				 this->groupBox2->ResumeLayout(false);
				 this->groupBox2->PerformLayout();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->tabPage8->ResumeLayout(false);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

#pragma region Vars
			 //Top Menu Items//
			 ToolStripMenuItem^  LinkedListItem;
			 ToolStripMenuItem^  BinaryTreeItem;

			 //Data Structures//
			 LinkedList* list;
			 Tree* tree;

			 //Other//
			 bool OperationInProgress;
			 String^ tovalidate;
			 int tovalidateindex;
			 int tovalidateindextotal;

			 //Config//
			 ConfigManager* cM;

			 //Dictionary API - Get Sample Meaning//
			 DictionaryApi^ daapi;		
#pragma endregion

#pragma region OnFormLoad-Init
			 System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 Init();
			 }

			 void Init()
			 {
				 //Init Data Structures//
				 list = new LinkedList();
				 tree = new Tree();

				 //Init recurrsion count and allwords string
				 tree->Init();
				 tree->IsLoaded = false;

				 //Init Menu Items//
				 LinkedListItem = gcnew ToolStripMenuItem();
				 BinaryTreeItem = gcnew ToolStripMenuItem();
				 //Init Menu Items - Set Text,Attach Event, Add to Menu Dropdown//
				 InitDSItem(LinkedListItem,L"Linked List");
				 InitDSItem(BinaryTreeItem,L"Binary Tree");

				 //Have LinkedList Menu Item Checked by default//
				 LinkedListItem->Checked = true;

				 //Init ConfigManager - Read conf.json, Store FileNames//
				 cM = new ConfigManager();

				 //Init DictionaryApi - Create WebClient Add API Headers//
				 daapi = gcnew DictionaryApi();

				 //Show Loaded Files in Settings Tab//
				 LoadFileList();

				 //Used to check if a parse,sort,search,add etc Operation is in progress//
				 OperationInProgress = false;

				 //Used to track words to be added after vaidation//
				 tovalidateindex = 0;
				 tovalidateindextotal = 0;

				 //Add Main Events Handlers//
				 this->parse_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Parse);

				 this->sort_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Sort);

				 this->search_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Search);
				 this->search_box->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::SearchBoxOnEnterPressed);
				 this->search_box->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::SupressEnter);

				 this->add_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Add);
				 this->add_definition->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::DefinitionBoxOnEnterPressed);
				 this->add_definition->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::SupressEnter);
				 this->pos_selector_run->Click += gcnew System::EventHandler(this, &MainForm::OpenSelector);

				 this->view_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Display);

				 this->validate_run->Click += gcnew System::EventHandler(this, &MainForm::Run_Validate);
				 this->validate_box->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::ValidateBoxOnEnterPressed);
				 this->validate_box->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::SupressEnter);
			 }
			 void InitDSItem(ToolStripMenuItem^ item, String^ text)
			 {
				 item->Text = text;
				 item->Click += gcnew System::EventHandler(this, &MainForm::DS_SelectionChanged);

				 //Add To dropdown List//
				 this->ds_selector->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {item});
			 }
			 //Shows Tick Icon on selected Item//
			 System::Void DS_SelectionChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 ToolStripMenuItem^ item = (ToolStripMenuItem^)sender;
				 if(item->Text == "Linked List")
				 {
					 BinaryTreeItem->Checked = false;
					 tabPage2->Enabled = true;
				 }
				 else
				 {
					 tabPage2->Enabled = false;
					 LinkedListItem->Checked = false;
				 }

				 item->Checked = true;
			 }
#pragma endregion

#pragma region delegates
			 //Helpers to make Thread-Safe Calls outside main thread//
			 delegate void TimerUpdater(String^ time, Label^ timer_label); 
			 delegate void LabelUpdater(String^ Text, bool IsEnabled, Label^ button);
			 delegate void TextBoxUpdater(TextBox^ box, String^ text);
			 delegate void RichTextBoxUpdater(RichTextBox^ box, String^ text);
			 delegate void TabIndexUpdater(int index);
#pragma endregion

#pragma region Control Updaters
			 //Helpers to make Thread-Safe Calls outside main thread - Updates Controls Outside Main Thread//
			 void UpdateTrigger(String^ Text, bool IsEnabled, Label^ label)
			 {
				 if (label->InvokeRequired)  
				 {  
					 LabelUpdater^ d = gcnew LabelUpdater(this, &MainForm::UpdateTrigger);  
					 this->Invoke(d, gcnew array<Object^> { Text,IsEnabled,label });  
				 }  
				 else   
				 {
					 if(Text != "")
						 label->Text = Text; 

					 label->Enabled = IsEnabled;
				 }
			 }
			 void UpdateTimer(String^ time, Label^ timer_label)  
			 {   
				 time = time->Replace(":",".");
				 time  = float::Parse(time).ToString("00.00");
				 time = time->Replace(".",":");
				 if (timer_label->InvokeRequired)  
				 {  
					 TimerUpdater^ d = gcnew TimerUpdater(this, &MainForm::UpdateTimer);  
					 this->Invoke(d, gcnew array<Object^> { time,timer_label });  
				 }  
				 else   
					 timer_label->Text = time;  
			 }   
			 void UpdateRichTextBox(RichTextBox^ box, String^ text)  
			 {   
				 if (box->InvokeRequired)  
				 {  
					 RichTextBoxUpdater^ d = gcnew RichTextBoxUpdater(this, &MainForm::UpdateRichTextBox);  
					 this->Invoke(d, gcnew array<Object^> {box,text });  
				 }  
				 else   
					 box->Text = text;  
			 }
			 void UpdateTextBox(TextBox^ box, String^ text)  
			 {   
				 if (box->InvokeRequired)  
				 {  
					 TextBoxUpdater^ d = gcnew TextBoxUpdater(this, &MainForm::UpdateTextBox);  
					 this->Invoke(d, gcnew array<Object^> {box,text });  
				 }  
				 else   
					 box->Text = text;  
			 }
			 void SetTabIndex(int index)  
			 {   
				 if (TabControl->InvokeRequired)  
				 {  
					 TabIndexUpdater^ d = gcnew TabIndexUpdater(this, &MainForm::SetTabIndex);  
					 this->Invoke(d, gcnew array<Object^> {index });  
				 }  
				 else   
					 TabControl->SelectedIndex = index;  
			 }
#pragma endregion

#pragma region Common Checks
			 bool FilesLoaded()
			 {
				 if(cM->GetNumOFFiles() == 0)
				 {
					 if(Ut::Info("No Dictionary Files Added, Add Now?",MessageBoxButtons::OKCancel,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
						 TabControl->SelectedIndex = 6;
					 return false;
				 }
				 return true;
			 }
			 bool IsOperationInProgress()
			 {
				 if(OperationInProgress)
				 {
					 Ut::Error("Another Operation In Progress, Please Wait.");
					 return true;
				 }
				 return false;
			 }
			 bool IsSelectDataStuctureLoaded()
			 {
				 if(LinkedListItem->Checked)
				 {
					 if(!list->IsLoaded)
						 return NotifyLoadFor(LinkedListItem->Text);
				 }
				 else if(BinaryTreeItem->Checked)
					 if(!tree->IsLoaded)
						 return NotifyLoadFor(BinaryTreeItem->Text);

				 return true;
			 }
			 bool NotifyLoadFor(String^ ds)
			 {
				 if(Ut::Info(ds+" Not Loaded, Load now?",MessageBoxButtons::OKCancel,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
					 TabControl->SelectedIndex = 0;
				 return false;
			 }
			 bool CheckUp()
			 {
				 if(IsOperationInProgress())
					 return false;
				 if(!IsSelectDataStuctureLoaded())
					 return false;
				 return true;
			 }
#pragma endregion

#pragma region Timer Thread Handler
			 void TimerThread(Object^ label)
			 {
				 Label^ timer_label = (Label^)label;
				 //Get Time Now//
				 clock_t StTime = clock();
				 clock_t EnTime;
				 while(true)
				 {
					 //Time Now - Last Time//
					 EnTime=clock()-StTime;

					 //Update Text of referenced timer Lable to calculated time cross thread//
					 UpdateTimer(((double)EnTime / ((double)CLOCKS_PER_SEC)).ToString(), timer_label);
					 Thread::Sleep(1);
				 }
			 }

#pragma endregion

#pragma region Parse Dictionary
			 Void Run_Parse(Object^  sender, System::EventArgs^  e) {
				 if(!FilesLoaded())
					 return;
				 if(IsOperationInProgress())
					 return;

				 Thread^ thread = gcnew Thread( gcnew ThreadStart( this, &MainForm::ParseThread ) );
				 thread->Start();
			 }


			 void ParseThread() {
				 OperationInProgress = true;

				 //Thread-Safe Call to Change Lable Text and Set Enabled to false(Restrict Another Click)//
				 UpdateTrigger("Runnin",false, parse_run);

				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 thread3->Start(parse_time);

				 //Parse Selected Data Structure//
				 if(LinkedListItem->Checked)
					 ResultSet<Word> result = list->LoadFromFile(cM->GetFileNames(),cM->GetNumOFFiles());
				 else if(BinaryTreeItem->Checked){
					 ResultSet<char> result = tree->LoadFromFile(cM->GetFileNames(),cM->GetNumOFFiles()); 
				 }

				 //Abort Thread - Stop Timer//
				 thread3->Abort();

				 //Change back to Start and enable Label//
				 UpdateTrigger("Start",true, parse_run);

				 OperationInProgress = false;
			 }
#pragma endregion

#pragma region Sort Dictionary
			 Void Run_Sort(Object^  sender, System::EventArgs^  e) {

				 if(!CheckUp())
					 return;

				 Thread^ thread = gcnew Thread( gcnew ThreadStart( this, &MainForm::SortThread ) );
				 thread->Start();

			 }
			 void SortThread() {  
				 OperationInProgress = true;
				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 thread3->Start(sort_time);
				 if(LinkedListItem->Checked)
					 list->Sort();
				 else{
					 //Ut::Info("Binary Tree Already Sorted..");
				 }
				 thread3->Abort();
				 OperationInProgress = false;
			 }

#pragma endregion

#pragma region Search Dictionary
			 Void Run_Search(Object^  sender, System::EventArgs^  e) {
				 RunSearch(this->search_box->Text);
			 }
			 void RunSearch(String^ wordname)
			 {
				 if(!CheckUp())
					 return;

				 Thread^ thread = gcnew Thread( gcnew ParameterizedThreadStart( this, &MainForm::SearchThread ) );
				 thread->Start(wordname);
			 }
			 void SearchThread(Object^ wordname) { 

				 OperationInProgress = true;
				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 ResultSet<Word> result;
				 String^ searchvalue = ((String^)wordname)->Trim();
				 thread3->Start(search_time);
				 if(LinkedListItem->Checked)
					 result =  list->FindWord(Ut::FromStringHat(searchvalue));
				 else{
					 result = tree->FindWord(Ut::FromStringHat(searchvalue));
				 }
				 thread3->Abort();
				 if(result.result.GetName() == "")
					 UpdateTrigger("Word Not Found",true,this->wordfound);
				 else
					 UpdateTrigger("#"+result.Getindex()+" "+Ut::ToStringHat(result.result.GetValue().c_str()),true,this->wordfound);
				 OperationInProgress = false;
			 }

			 System::Void SearchBoxOnEnterPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == Keys::Enter)
					 RunSearch(this->search_box->Text);
			 }
			 System::Void SupressEnter(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == Keys::Enter)
					 e->SuppressKeyPress = true;
			 }
#pragma endregion

#pragma region Add To Dictionary
			 Void Run_Add(Object^  sender, System::EventArgs^  e) {
				 RunAdd();
			 }

			 void RunAdd()
			 {
				 if(!CheckUp())
					 return;
				 Thread^ thread = gcnew Thread( gcnew ParameterizedThreadStart( this, &MainForm::AddThread ) );
				 AddWord^ ToAdd = gcnew AddWord();
				 string wname = Ut::FromStringHat(add_name->Text->Trim());
				 string wdefinition = Ut::FromStringHat(add_definition->Text->Trim());

				 if(!regex_match(wname,regex("^[A-z]+$")) || !regex_match(wdefinition,regex(".+")))
				 {
					 Ut::Error("Invalid Word Name/Definition");
					 return;
				 }
					
				 ToAdd->word = new Word(wname,wdefinition,PoSList::GetPoSList(Ut::FromStringHat(add_pos_string->Text)));
				 thread->Start(ToAdd);

				 //Try Skip - For Vadidation//
				 SkipNext();
			 }
			 void AddThread(Object^ word) { 

				 OperationInProgress = true;
				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 AddWord^ addword = (AddWord^)word;
				 ResultSet<Word> result;
				 thread3->Start(add_time);
				 if(LinkedListItem->Checked)
					 result =  list->AddWord(*(addword->word),false);
				 else{
					 result =  tree->AddWord(*(addword->word));
				 }
				 thread3->Abort();
				 OperationInProgress = false;
				 if(result.result.GetName() != "")
				 {
					 System::Windows::Forms::MessageBox::Show("Word Already Exist","Error");
					 SetTabIndex(2);
					 String^ wordname = Ut::ToStringHat(addword->word->GetName().c_str());
					 UpdateTextBox(search_box,wordname);
					 RunSearch(wordname);
				 }
			 }

			 System::Void DefinitionBoxOnEnterPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == Keys::Enter)
					 RunAdd();
			 }

			 void OpenSelector(Object^ sender, EventArgs^ e)
			 {
				 PSelectorWindow SWin;
				 SWin.SelectionChanged += gcnew PSelectorWindow::OnSelectionChanged(this,&MainForm::AddSelected);
				 SWin.ShowDialog();
			 }
			 Void AddSelected(System::String^ pos)
			 {
				 if(!this->add_pos_string->Text->Contains(pos))
					 this->add_pos_string->Text += " "+pos;
			 }
#pragma endregion

#pragma region Display All In Dictionary
			 Void Run_Display(Object^  sender, System::EventArgs^  e) {
				 RunDisplay();
			 }

			 void RunDisplay()
			 {
				 if(!CheckUp())
					 return;
				 Thread^ thread = gcnew Thread( gcnew ThreadStart( this, &MainForm::DisplayThread ) );
				 AddWord^ ToAdd = gcnew AddWord();
				 thread->Start();
			 }
			 void DisplayThread() { 

				 OperationInProgress = true;
				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 String^ result;
				 thread3->Start(view_time);
				 if(LinkedListItem->Checked)
					 result = list->GetAll();
				 else{
					 result = tree->GetAll();
				 }
				 thread3->Abort();
				 UpdateRichTextBox(wordout_box,result);
				 OperationInProgress = false;
			 }
#pragma endregion

#pragma region Validate Sentence
			 Void Run_Validate(Object^  sender, System::EventArgs^  e) {
				 RunValidate();
			 }

			 void RunValidate()
			 {
				 if(!CheckUp())
					 return;
				 Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &MainForm::ValidateThread ) );
				 thread->Start();
			 }
			 void ValidateThread() { 

				 OperationInProgress = true;
				 Thread^ thread3 = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::TimerThread));
				 ResultSet<string> result;
				 thread3->Start(view_time);
				 if(LinkedListItem->Checked)
					 result = list->ValidateSentence(Ut::FromStringHat(validate_box->Text->Trim()));
				 else
					 result = tree->ValidateSentence(Ut::FromStringHat(validate_box->Text->Trim()));

				 thread3->Abort();
				 tovalidate = Ut::ToStringHat(result.result.c_str());
				 if(tovalidate != "")
				 {
					 if(!tovalidate->Contains(","))
					 {
						 UpdateTextBox(add_name,tovalidate);
						 UpdateTextBox(add_definition,daapi->GetSampleDefinition(tovalidate));
						 UpdateTrigger("",false,skip_run);
					 }
					 else
					 {
						 UpdateTextBox(add_name,tovalidate->Split(',')[0]);
						 UpdateTextBox(add_definition,daapi->GetSampleDefinition(tovalidate->Split(',')[0]));
						 tovalidateindextotal = tovalidate->Split(',')->Length;
						 tovalidateindex = 1;
						 UpdateTrigger("",true,skip_run);
					 }
					 SetTabIndex(3);
				 }
				 OperationInProgress = false;
			 }
			 System::Void skip_run_Click(System::Object^  sender, System::EventArgs^  e) {
				 SkipNext();
			 }
			 void SkipNext()
			 {
				 if(tovalidateindextotal == 0)
					 return;
				 add_name->Text = tovalidate->Split(',')[tovalidateindex];
				 UpdateTextBox(add_definition,daapi->GetSampleDefinition(tovalidate->Split(',')[tovalidateindex]));
				 tovalidateindex++;
				 if(tovalidateindex == tovalidateindextotal)
				 {
					 skip_run->Enabled = false;
					 tovalidateindextotal = 0;
					 return;
				 }
			 }
			 System::Void ValidateBoxOnEnterPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == Keys::Enter)
					 RunValidate();
			 }
#pragma endregion

#pragma region Settings
			 void LoadFileList()
			 {
				 Value& filenames = cM->GetFileNames();
				 for(int i=0;i<cM->GetNumOFFiles();i++)
					 setting_filelistbox->Items->Add(Ut::ToStringHat(filenames[i].GetString()));
			 }

			 System::Void setting_addfile_run_Click(System::Object^  sender, System::EventArgs^  e) {			AddFile(setting_filename_box->Text);
			 }
			 void AddFile(String^ filename)
			 {
				 if(!File::Exists(filename))
				 {
					 System::Windows::Forms::MessageBox::Show("Filename Does not exist","Error");
					 return;
				 }

				 cM->AddFileName(filename);
				 cM->Save();
				 setting_filelistbox->Items->Add(filename);
			 }
			 System::Void setting_browse_run_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ file = gcnew OpenFileDialog();
				 if(file->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 AddFile(file->FileName);
			 }
#pragma endregion

	};
}
