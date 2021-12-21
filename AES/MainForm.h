#pragma once

#include "AESCrypto.h"
#include "Constant.h"

namespace AES {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form {
	public:
		MainForm() {
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			ivControl = gcnew array<TextBox^>{txtIV1, txtIV2, txtIV3, txtIV4, txtIV5, txtIV6, txtIV7, txtIV8, txtIV9, txtIV10, txtIV11, txtIV12, txtIV13, txtIV14, txtIV15, txtIV16};
			loadDefaultIV();
			txtIV1->SelectionStart = txtIV1->Text->Length;
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm() {
			if (components) {
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Label^ labelInput;
		System::Windows::Forms::TextBox^ txtInput;
		System::Windows::Forms::Button^ btnBrowseInput;
		System::Windows::Forms::TextBox^ txtOutput;
		System::Windows::Forms::Label^ labelOutput;
		System::Windows::Forms::Button^ btnBrowseOutput;
		System::Windows::Forms::Button^ btnStart;
		System::Windows::Forms::Label^ labelMode;
		System::Windows::Forms::RadioButton^ rbEncrypt;
		System::Windows::Forms::RadioButton^ rbDecrypt;
		System::Windows::Forms::Label^ labelIV;
		System::Windows::Forms::TextBox^ txtIV1;
		System::Windows::Forms::TextBox^ txtIV2;
		System::Windows::Forms::TextBox^ txtIV4;
		System::Windows::Forms::TextBox^ txtIV3;
		System::Windows::Forms::TextBox^ txtIV6;
		System::Windows::Forms::TextBox^ txtIV5;
		System::Windows::Forms::TextBox^ txtIV8;
		System::Windows::Forms::TextBox^ txtIV7;
		System::Windows::Forms::TextBox^ txtIV16;
		System::Windows::Forms::TextBox^ txtIV15;
		System::Windows::Forms::TextBox^ txtIV14;
		System::Windows::Forms::TextBox^ txtIV13;
		System::Windows::Forms::TextBox^ txtIV12;
		System::Windows::Forms::TextBox^ txtIV11;
		System::Windows::Forms::TextBox^ txtIV10;
		System::Windows::Forms::TextBox^ txtIV9;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent() {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelInput = (gcnew System::Windows::Forms::Label());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnBrowseInput = (gcnew System::Windows::Forms::Button());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->labelOutput = (gcnew System::Windows::Forms::Label());
			this->btnBrowseOutput = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->labelMode = (gcnew System::Windows::Forms::Label());
			this->rbEncrypt = (gcnew System::Windows::Forms::RadioButton());
			this->rbDecrypt = (gcnew System::Windows::Forms::RadioButton());
			this->labelIV = (gcnew System::Windows::Forms::Label());
			this->txtIV1 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV2 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV4 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV3 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV6 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV5 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV8 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV7 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV16 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV15 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV14 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV13 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV12 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV11 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV10 = (gcnew System::Windows::Forms::TextBox());
			this->txtIV9 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//
			// labelTitle
			//
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelTitle->Location = System::Drawing::Point(12, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(122, 20);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"AES 加解密工具";
			//
			// labelInput
			//
			this->labelInput->AutoSize = true;
			this->labelInput->Location = System::Drawing::Point(25, 135);
			this->labelInput->Name = L"labelInput";
			this->labelInput->Size = System::Drawing::Size(53, 12);
			this->labelInput->TabIndex = 18;
			this->labelInput->Text = L"輸入檔案";
			//
			// txtInput
			//
			this->txtInput->Location = System::Drawing::Point(84, 132);
			this->txtInput->Name = L"txtInput";
			this->txtInput->ReadOnly = true;
			this->txtInput->Size = System::Drawing::Size(325, 22);
			this->txtInput->TabIndex = 19;
			//
			// btnBrowseInput
			//
			this->btnBrowseInput->Location = System::Drawing::Point(415, 130);
			this->btnBrowseInput->Name = L"btnBrowseInput";
			this->btnBrowseInput->Size = System::Drawing::Size(75, 23);
			this->btnBrowseInput->TabIndex = 20;
			this->btnBrowseInput->Text = L"瀏覽";
			this->btnBrowseInput->UseVisualStyleBackColor = true;
			this->btnBrowseInput->Click += gcnew System::EventHandler(this, &MainForm::btnBrowseInput_Click);
			//
			// txtOutput
			//
			this->txtOutput->Location = System::Drawing::Point(84, 161);
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->Size = System::Drawing::Size(325, 22);
			this->txtOutput->TabIndex = 22;
			//
			// labelOutput
			//
			this->labelOutput->AutoSize = true;
			this->labelOutput->Location = System::Drawing::Point(25, 164);
			this->labelOutput->Name = L"labelOutput";
			this->labelOutput->Size = System::Drawing::Size(53, 12);
			this->labelOutput->TabIndex = 21;
			this->labelOutput->Text = L"輸出檔案";
			//
			// btnBrowseOutput
			//
			this->btnBrowseOutput->Location = System::Drawing::Point(415, 159);
			this->btnBrowseOutput->Name = L"btnBrowseOutput";
			this->btnBrowseOutput->Size = System::Drawing::Size(75, 23);
			this->btnBrowseOutput->TabIndex = 23;
			this->btnBrowseOutput->Text = L"瀏覽";
			this->btnBrowseOutput->UseVisualStyleBackColor = true;
			this->btnBrowseOutput->Click += gcnew System::EventHandler(this, &MainForm::btnBrowseOutput_Click);
			//
			// btnStart
			//
			this->btnStart->Location = System::Drawing::Point(415, 199);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 27;
			this->btnStart->Text = L"開始";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			//
			// labelMode
			//
			this->labelMode->AutoSize = true;
			this->labelMode->Location = System::Drawing::Point(25, 204);
			this->labelMode->Name = L"labelMode";
			this->labelMode->Size = System::Drawing::Size(29, 12);
			this->labelMode->TabIndex = 24;
			this->labelMode->Text = L"模式";
			//
			// rbEncrypt
			//
			this->rbEncrypt->AutoSize = true;
			this->rbEncrypt->Checked = true;
			this->rbEncrypt->Location = System::Drawing::Point(84, 202);
			this->rbEncrypt->Name = L"rbEncrypt";
			this->rbEncrypt->Size = System::Drawing::Size(47, 16);
			this->rbEncrypt->TabIndex = 25;
			this->rbEncrypt->TabStop = true;
			this->rbEncrypt->Text = L"加密";
			this->rbEncrypt->UseVisualStyleBackColor = true;
			//
			// rbDecrypt
			//
			this->rbDecrypt->AutoSize = true;
			this->rbDecrypt->Location = System::Drawing::Point(165, 202);
			this->rbDecrypt->Name = L"rbDecrypt";
			this->rbDecrypt->Size = System::Drawing::Size(47, 16);
			this->rbDecrypt->TabIndex = 26;
			this->rbDecrypt->Text = L"解密";
			this->rbDecrypt->UseVisualStyleBackColor = true;
			//
			// labelIV
			//
			this->labelIV->AutoSize = true;
			this->labelIV->Location = System::Drawing::Point(25, 63);
			this->labelIV->Name = L"labelIV";
			this->labelIV->Size = System::Drawing::Size(17, 12);
			this->labelIV->TabIndex = 1;
			this->labelIV->Text = L"IV";
			//
			// txtIV1
			//
			this->txtIV1->Location = System::Drawing::Point(48, 60);
			this->txtIV1->Name = L"txtIV1";
			this->txtIV1->Size = System::Drawing::Size(50, 22);
			this->txtIV1->TabIndex = 2;
			//
			// txtIV2
			//
			this->txtIV2->Location = System::Drawing::Point(104, 60);
			this->txtIV2->Name = L"txtIV2";
			this->txtIV2->Size = System::Drawing::Size(50, 22);
			this->txtIV2->TabIndex = 3;
			//
			// txtIV4
			//
			this->txtIV4->Location = System::Drawing::Point(216, 60);
			this->txtIV4->Name = L"txtIV4";
			this->txtIV4->Size = System::Drawing::Size(50, 22);
			this->txtIV4->TabIndex = 5;
			//
			// txtIV3
			//
			this->txtIV3->Location = System::Drawing::Point(160, 60);
			this->txtIV3->Name = L"txtIV3";
			this->txtIV3->Size = System::Drawing::Size(50, 22);
			this->txtIV3->TabIndex = 4;
			//
			// txtIV6
			//
			this->txtIV6->Location = System::Drawing::Point(328, 60);
			this->txtIV6->Name = L"txtIV6";
			this->txtIV6->Size = System::Drawing::Size(50, 22);
			this->txtIV6->TabIndex = 7;
			//
			// txtIV5
			//
			this->txtIV5->Location = System::Drawing::Point(272, 60);
			this->txtIV5->Name = L"txtIV5";
			this->txtIV5->Size = System::Drawing::Size(50, 22);
			this->txtIV5->TabIndex = 6;
			//
			// txtIV8
			//
			this->txtIV8->Location = System::Drawing::Point(440, 60);
			this->txtIV8->Name = L"txtIV8";
			this->txtIV8->Size = System::Drawing::Size(50, 22);
			this->txtIV8->TabIndex = 9;
			//
			// txtIV7
			//
			this->txtIV7->Location = System::Drawing::Point(384, 60);
			this->txtIV7->Name = L"txtIV7";
			this->txtIV7->Size = System::Drawing::Size(50, 22);
			this->txtIV7->TabIndex = 8;
			//
			// txtIV16
			//
			this->txtIV16->Location = System::Drawing::Point(440, 88);
			this->txtIV16->Name = L"txtIV16";
			this->txtIV16->Size = System::Drawing::Size(50, 22);
			this->txtIV16->TabIndex = 17;
			//
			// txtIV15
			//
			this->txtIV15->Location = System::Drawing::Point(384, 88);
			this->txtIV15->Name = L"txtIV15";
			this->txtIV15->Size = System::Drawing::Size(50, 22);
			this->txtIV15->TabIndex = 16;
			//
			// txtIV14
			//
			this->txtIV14->Location = System::Drawing::Point(328, 88);
			this->txtIV14->Name = L"txtIV14";
			this->txtIV14->Size = System::Drawing::Size(50, 22);
			this->txtIV14->TabIndex = 15;
			//
			// txtIV13
			//
			this->txtIV13->Location = System::Drawing::Point(272, 88);
			this->txtIV13->Name = L"txtIV13";
			this->txtIV13->Size = System::Drawing::Size(50, 22);
			this->txtIV13->TabIndex = 14;
			//
			// txtIV12
			//
			this->txtIV12->Location = System::Drawing::Point(216, 88);
			this->txtIV12->Name = L"txtIV12";
			this->txtIV12->Size = System::Drawing::Size(50, 22);
			this->txtIV12->TabIndex = 13;
			//
			// txtIV11
			//
			this->txtIV11->Location = System::Drawing::Point(160, 88);
			this->txtIV11->Name = L"txtIV11";
			this->txtIV11->Size = System::Drawing::Size(50, 22);
			this->txtIV11->TabIndex = 12;
			//
			// txtIV10
			//
			this->txtIV10->Location = System::Drawing::Point(104, 88);
			this->txtIV10->Name = L"txtIV10";
			this->txtIV10->Size = System::Drawing::Size(50, 22);
			this->txtIV10->TabIndex = 11;
			//
			// txtIV9
			//
			this->txtIV9->Location = System::Drawing::Point(48, 88);
			this->txtIV9->Name = L"txtIV9";
			this->txtIV9->Size = System::Drawing::Size(50, 22);
			this->txtIV9->TabIndex = 10;
			//
			// MainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(519, 241);
			this->Controls->Add(this->txtIV16);
			this->Controls->Add(this->txtIV15);
			this->Controls->Add(this->txtIV14);
			this->Controls->Add(this->txtIV13);
			this->Controls->Add(this->txtIV12);
			this->Controls->Add(this->txtIV11);
			this->Controls->Add(this->txtIV10);
			this->Controls->Add(this->txtIV9);
			this->Controls->Add(this->txtIV8);
			this->Controls->Add(this->txtIV7);
			this->Controls->Add(this->txtIV6);
			this->Controls->Add(this->txtIV5);
			this->Controls->Add(this->txtIV4);
			this->Controls->Add(this->txtIV3);
			this->Controls->Add(this->txtIV2);
			this->Controls->Add(this->txtIV1);
			this->Controls->Add(this->labelIV);
			this->Controls->Add(this->rbDecrypt);
			this->Controls->Add(this->rbEncrypt);
			this->Controls->Add(this->labelMode);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnBrowseOutput);
			this->Controls->Add(this->labelOutput);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->btnBrowseInput);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->labelInput);
			this->Controls->Add(this->labelTitle);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"AES 加解密工具";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		array<TextBox^>^ ivControl;

		void loadDefaultIV() {
			for (int i = 0; i < 16; ++i) {
				ivControl[i]->Text = defaultIV[i].ToString();
			}
		}

		template<typename T>
		T* manageArrayToNativeArray(array<T>^ data) {
			T* ret = new T[data->Length];
			for (int i = 0; i < data->Length; ++i) {
				ret[i] = data[i];
			}
			return ret;
		}

		template<typename T>
		array<T>^ nativeArrayToManageArray(T* data, int length) {
			array<T>^ ret = gcnew array<T>(length);
			for (int i = 0; i < length; ++i) {
				ret[i] = data[i];
			}
			return ret;
		}

		System::Void btnBrowseInput_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ ofd = gcnew OpenFileDialog();
			ofd->Title = "請選擇來源檔案";
			if (ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			txtInput->Text = ofd->FileName;
		}

		System::Void btnBrowseOutput_Click(System::Object^ sender, System::EventArgs^ e) {
			SaveFileDialog^ sfd = gcnew SaveFileDialog();
			sfd->Filter = "所有檔案 (*.*)|*.*";
			sfd->Title = "請選擇輸出檔案";
			if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			txtOutput->Text = sfd->FileName;
		}

		byte* getCurrentIV() {
			byte* ret = new byte[16];
			for (int i = 0; i < 16; ++i) {
				try {
					ret[i] = Byte::Parse(ivControl[i]->Text);
				} catch (...) {
					MessageBox::Show("請輸入正確的 IV 數值", "錯誤", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return NULL;
				}
			}
			return ret;
		}

		System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrEmpty(txtInput->Text) || String::IsNullOrEmpty(txtOutput->Text)) {
				MessageBox::Show("請指定來源檔案與輸出檔案", "錯誤", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			byte* currentIV = getCurrentIV();
			byte* nativeFile = NULL;
			byte* result = NULL;
			try {
				if (currentIV == NULL) {
					return;
				}

				AESCrypto aes(128);
				array<byte>^ file = File::ReadAllBytes(txtInput->Text);
				nativeFile = manageArrayToNativeArray(file);

				if (rbEncrypt->Checked) {
					size_t outputLength;
					result = aes.encryptCBC(nativeFile, file->Length, key, currentIV, outputLength);
					array<byte>^ manageEncrypt = nativeArrayToManageArray(result, outputLength);
					File::WriteAllBytes(txtOutput->Text, manageEncrypt);
					MessageBox::Show("檔案加密完成", "資訊", MessageBoxButtons::OK, MessageBoxIcon::Information);
				} else {
					if (aes.shouldPadding(file->Length)) {
						MessageBox::Show("輸入檔案格式錯誤", "錯誤", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
					result = aes.decryptCBC(nativeFile, file->Length, key, currentIV);
					array<byte>^ manageDecrypt = nativeArrayToManageArray(result, file->Length);
					File::WriteAllBytes(txtOutput->Text, manageDecrypt);
					MessageBox::Show("檔案解密完成", "資訊", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			} catch (Exception^ ex) {
				MessageBox::Show("處理加解密時發生例外狀況 : " + ex->Message, "錯誤", MessageBoxButtons::OK, MessageBoxIcon::Error);
			} finally {
				if (result != NULL) {
					delete[] result;
				}
				if (nativeFile != NULL) {
					delete[] nativeFile;
				}
				if (currentIV != NULL) {
					delete[] currentIV;
				}
			}
		}
	};
}