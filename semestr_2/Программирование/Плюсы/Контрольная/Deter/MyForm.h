#pragma once

namespace Deter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtFirstRow;
	private: System::Windows::Forms::TextBox^ txtSecondRow;


	private: System::Windows::Forms::Button^ btnCalculate;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lblResult;

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtFirstRow = (gcnew System::Windows::Forms::TextBox());
			this->txtSecondRow = (gcnew System::Windows::Forms::TextBox());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(516, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Расчет определителя матрицы 2х2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(366, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введите элементы 1-ой строки (через пробел)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(366, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Введите элементы 2-ой строки (через пробел)";
			// 
			// txtFirstRow
			// 
			this->txtFirstRow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtFirstRow->Location = System::Drawing::Point(20, 88);
			this->txtFirstRow->Name = L"txtFirstRow";
			this->txtFirstRow->Size = System::Drawing::Size(509, 35);
			this->txtFirstRow->TabIndex = 2;
			// 
			// txtSecondRow
			// 
			this->txtSecondRow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSecondRow->Location = System::Drawing::Point(20, 160);
			this->txtSecondRow->Name = L"txtSecondRow";
			this->txtSecondRow->Size = System::Drawing::Size(509, 35);
			this->txtSecondRow->TabIndex = 2;
			// 
			// btnCalculate
			// 
			this->btnCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCalculate->Location = System::Drawing::Point(20, 228);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(509, 83);
			this->btnCalculate->TabIndex = 3;
			this->btnCalculate->Text = L"Рассчитать определитель";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::btnCalculate_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(21, 338);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(171, 37);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Результат:";
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblResult->Location = System::Drawing::Point(21, 386);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(44, 37);
			this->lblResult->TabIndex = 0;
			this->lblResult->Text = L"...";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(587, 451);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->txtSecondRow);
			this->Controls->Add(this->txtFirstRow);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Контрольная С++";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtFirstRow->Text == "" || txtSecondRow->Text == "") {
			lblResult->Text = "Не введены данные";
			return;
		}
		int a11 = 0, a12 = 0, a21 = 0, a22 = 0;
		cli::array<String^>^ el1 = txtFirstRow->Text->Split(' ');
		cli::array<String^>^ el2 = txtSecondRow->Text->Split(' ');
		try
		{
			a11 = Int32::Parse(el1[0]);
			a12 = Int32::Parse(el1[1]);

			a21 = Int32::Parse(el2[0]);
			a22 = Int32::Parse(el2[1]);
		}
		catch (...)
		{
			MessageBox::Show("Не удалось получить число", "Ошибка", MessageBoxButtons::OK);
		}
		
		lblResult->Text = Convert::ToString(getDeterminant(a11, a12, a21, a22));
	}

	private: int getDeterminant(int a11, int a12, int a21, int a22) {
		return a11 * a22 - a12 * a21;
	}
};
}
