#pragma once
#include "MyForm1.h"
#include "Devices.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <chrono>

namespace LeftARM 
{

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: MyForm1^ loginWin = gcnew MyForm1;
	private: Devices dev;

	public:
		MyForm(void)
		{
			InitializeComponent();
			dev.LoadDevices();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button12;
	private: System::ComponentModel::IContainer^ components;

	private:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->button10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(13, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(212, 315);
			this->groupBox1->TabIndex = 1;

			this->groupBox1->Text = L"Устройства";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(99, 286);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Статус: ";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(7, 281);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(86, 23);
			this->button11->TabIndex = 18;
			this->button11->Text = L"Артериоскоп";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(99, 257);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(47, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Статус: ";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(7, 252);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(86, 23);
			this->button10->TabIndex = 16;
			this->button10->Text = L"Ангиоскоп";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(99, 228);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 13);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Статус: ";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(7, 223);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(86, 23);
			this->button9->TabIndex = 14;
			this->button9->Text = L"Протезы";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(99, 199);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(47, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Статус: ";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(7, 194);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(86, 23);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Из.излучения";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(99, 170);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Статус: ";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(7, 165);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(86, 23);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Диоптриметр";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(99, 141);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Статус: ";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(7, 136);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(86, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Кейджи";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(99, 112);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Статус: ";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(7, 107);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(86, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Ан. ИВД";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(99, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Статус: ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(7, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(86, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Оч. воздуха";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(99, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Статус: ";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(7, 49);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Ингалятор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(99, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Статус: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 20);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Бронхоскоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(95, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Пользователь не вошёл";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(63, 365);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(113, 23);
			this->button12->TabIndex = 3;
			this->button12->Text = L"Отправить отчёт";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(249, 400);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ARM";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (login == "")
		{
			loginWin = gcnew MyForm1;
			loginWin->Show();
		}
		else
		{
			auto msg = MessageBox::Show("Вы уверены, что хотите выйти?", "Информация", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (msg == System::Windows::Forms::DialogResult::Yes) 
			{
				login = "";
				password = "";
			}
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (loginWin->Visible)
		{
			button1->Enabled = false;
		}
		else
		{
			button1->Enabled = true;
		}

		if (login != "")
		{
			button1->Text = L"Выйти";
			label1->Text = L"Пользователь: " + msclr::interop::marshal_as<System::String^>(login);

			groupBox1->Enabled = true;
			button12->Enabled = true;
		}
		else
		{
			button1->Text = L"Войти";
			label1->Text = L"Пользователь не вошёл";

			groupBox1->Enabled = false;
			button12->Enabled = false;
		}

		UpdateDeviceStatus();
	}

	private: void ChangeStatus(int id) 
	{
		if (dev.devices[id].status + 1 > 2)
			dev.devices[id].status = 0;
		else
			dev.devices[id].status++;
	}

	private: void UpdateDeviceStatus()
	{
		label2->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[0].GetStatus());
		label3->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[1].GetStatus());
		label4->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[2].GetStatus());
		label5->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[3].GetStatus());
		label6->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[4].GetStatus());
		label7->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[5].GetStatus());
		label8->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[6].GetStatus());
		label9->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[7].GetStatus());
		label10->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[8].GetStatus());
		label11->Text = L"Статус: " + msclr::interop::marshal_as<System::String^>(dev.devices[9].GetStatus());
	}

	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		bool success = false;

		for (int i = 0; i < numberOfDev; i++)
			if (dev.devices[i].status == 0)
			{
				success = false;
				break;
			}
			else
				success = true;

		if (success) 
		{
			auto now = std::chrono::system_clock::now();
			std::time_t end_time = std::chrono::system_clock::to_time_t(now);
			ofstream log("отчёт.txt");

			log << "Отчёт за " << std::ctime(&end_time) << endl;

			for (int i = 0; i < numberOfDev; i++)
				log << "Прибор: " << dev.devices[i].GetName() << endl << "Статус: " << dev.devices[i].GetStatus() << endl << endl;

			log.close();

			MessageBox::Show("Отчёт был отправлен!", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
			MessageBox::Show("Вы не можете отправить отчёт, пока не проверите все приборы.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ChangeStatus(8);
	}

	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ChangeStatus(9);
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(1);
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(2);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ChangeStatus(3);
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(4);
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(5);
	}

	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(6);
	}

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ChangeStatus(7);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ChangeStatus(0);
	}
};
}
