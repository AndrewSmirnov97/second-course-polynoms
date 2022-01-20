#pragma once

#include"polinom.h"
std::string str;
std::string text2;
std::string outstrA;
std::string outstrB;
std::string outstrC;
std::string outstrD;
std::string outstrT;
bool rdytocount;

namespace Polinomform {
	Polinom A;
	Polinom B;
	Polinom C;
	Polinom D;
	Polinom R;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label6;






	protected:

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(136, 15);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(299, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(136, 85);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(299, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 160);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"set as A";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::setasA);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 242);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"set as B ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(133, 285);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(126, 317);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 5;
			this->button3->Text = L"set as C";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::setasC);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(126, 382);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 28);
			this->button4->TabIndex = 6;
			this->button4->Text = L"set as D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::setasD);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(133, 206);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(133, 349);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(133, 414);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(465, 85);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 28);
			this->button5->TabIndex = 10;
			this->button5->Text = L"result";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::result);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(132, 126);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"result";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(646, 263);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(289, 222);
			this->dataGridView1->TabIndex = 12;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(646, 234);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 13;
			this->button6->Text = L"create";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::create);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(728, 233);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 14;
			this->button7->Text = L"count";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::count);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(646, 211);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 17);
			this->label6->TabIndex = 15;
			this->label6->Text = L"count result";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1023, 497);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 int len = textBox1->Text->Length;
				 str.resize(len);
				 for (int i = 0; i < len; i++){
					 str[i] = textBox1->Text[i];
				 }
				Polinom X(str);
				B = X;
				R = B;
				outstrB= B.createstringfrompol();
				label1->Text = gcnew String(outstrB.c_str());
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			
}
private: System::Void setasA(System::Object^  sender, System::EventArgs^  e) {
			 int len = textBox1->Text->Length;
			 str.resize(len);
			 for (int i = 0; i < len; i++){
				 str[i] = textBox1->Text[i];
			 }
			 Polinom X(str);
			 A = X;
			 R = A;
			 outstrA = A.createstringfrompol();
			 label2->Text = gcnew String(outstrA.c_str());
}
private: System::Void setasC(System::Object^  sender, System::EventArgs^  e) {
			 int len = textBox1->Text->Length;
			 str.resize(len);
			 for (int i = 0; i < len; i++){
				 str[i] = textBox1->Text[i];
			 }
			 Polinom X(str);
			 C = X;
			 R = C;
			 outstrC = C.createstringfrompol();
			 label3->Text = gcnew String(outstrC.c_str());
}
private: System::Void setasD(System::Object^  sender, System::EventArgs^  e) {
			 int len = textBox1->Text->Length;
			 str.resize(len);
			 for (int i = 0; i < len; i++){
				 str[i] = textBox1->Text[i];
			 }
			 Polinom X(str);
			 D = X;
			 R = D;
			 outstrD = D.createstringfrompol();
			 label4->Text = gcnew String(outstrD.c_str());
}
private: System::Void result(System::Object^  sender, System::EventArgs^  e) {
			 int len = textBox2->Text->Length;
			 text2.resize(len);
			 for (int i = 0; i < len; i++){
				 text2[i] = textBox2->Text[i];
			 }
			 if (len == 0){
				 return;
			 }
			 Polinom Left;
			 Polinom Right;
			 Polinom T;
			 
			 
			 if (text2[0] == 'A'){
				 Left = A;
			 }
			 if (text2[0] == 'B'){
				 Left = B;
			 }
			 if (text2[0] == 'C'){
				 Left = C;
			 }
			 if (text2[0] == 'D'){
				 Left = D;
			 }

			 if (len == 1){
				 T = Left;
				 outstrT = T.createstringfrompol();
				 label5->Text = gcnew String(outstrT.c_str());
				 return;
			 }
			


			 if (text2[2] == 'A'){
				Right = A;
			 }
			 if (text2[2] == 'B'){
				 Right = B;
			 }
			 if (text2[2] == 'C'){
				 Right = C;
			 }
			 if (text2[2] == 'D'){
				 Right = D;
			 }


			 if (text2[1] == '+'){
				 T = Left + Right;

			 }
			 if (text2[1] == '-'){
				 T = Left - Right;

			 }
			 if (text2[1] == '*'){
				 T = Left *  Right;
				 R = T;

			 }
			 if (text2[1] == '/0'){
				 T = Left;
			 }
			 
				 outstrT = T.createstringfrompol();
				 label5->Text = gcnew String(outstrT.c_str());
			 

}

private: System::Void create(System::Object^  sender, System::EventArgs^  e) {
			 dataGridView1->ColumnCount = 2;
			 dataGridView1->RowCount = 3;
			 dataGridView1->Rows[0]->Cells[0]->Value = "x";
			 dataGridView1->Rows[1]->Cells[0]->Value = "y";
			 dataGridView1->Rows[2]->Cells[0]->Value = "z";
}
private: System::Void count(System::Object^  sender, System::EventArgs^  e) {
			 double x = 0;
			 double y = 0;
			 double z = 0;
			 /*string xx;
			 xx = dataGridView1->Rows[0]->Cells[1]->ToString();
			 x = stof(xx);*/
			 
			 
			 x = Convert::ToDouble(dataGridView1->Rows[0]->Cells[1]->Value);
			 y = Convert::ToDouble(dataGridView1->Rows[1]->Cells[1]->Value);
			 z = Convert::ToDouble(dataGridView1->Rows[2]->Cells[1]->Value);
			 double res=R.count(x,y,z);
			 string result = to_string(res);
			 label2->Text = gcnew String(result.c_str());
			 
}
};
}
