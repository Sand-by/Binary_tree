#pragma once
namespace treevisual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

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
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: List<Panel^>^ listpanels;//—писок панелек



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Location = System::Drawing::Point(212, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(232, 181);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 82);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 38);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(80, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 38);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->panel2->Location = System::Drawing::Point(482, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(621, 576);
			this->panel2->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1124, 600);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel = gcnew Panel();
		Panel^ panel2 = gcnew Panel();

		Label^ label = gcnew Label();
		Label^ label2 = gcnew Label();

		label->Text = "1";
		label->AutoSize = true;
		label->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		
		label2->Text = "2";
		label2->AutoSize = true;
		label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		panel->Controls->Add(label);
		panel->Size = System::Drawing::Size(label->Width, label->Height);
		panel->BackColor = Color::Red;
		panel->Location = Point(panel1->Width / 2 - panel->Width/2, panel1->Height / 2 - panel->Height/2);
		
		panel2->Controls->Add(label2);
		panel2->Size = System::Drawing::Size(label->Width, label->Height);
		panel2->BackColor = Color::Green;
		panel2->Location = Point((panel1->Width / 2 - panel2->Width/2)+panel2->Width*2, 
								 (panel1->Height / 2 - panel2->Height/2)+panel2->Height*2
		);
		panel1->Controls->Add(panel);
		panel1->Controls->Add(panel2);

		Graphics^ pg = panel1->CreateGraphics();

		Pen^ red_pen = gcnew Pen(Color::Red,5.0f);
		pg->DrawLine(red_pen, panel->Location.X+panel->Width/2, panel->Location.Y+panel->Height/2, panel2->Location.X, panel2->Location.Y);
		delete pg;
	}

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {

	array<Point>^ curvePoints = gcnew array<Point>(20);
	List<Point>^ list_points = gcnew List<Point>();

	Graphics^ pg = panel2->CreateGraphics();

	Pen^ red_pen = gcnew Pen(Color::Red, 2.0f);

	for (int i = 0; i < 10;i++) {
		Panel^ pane = gcnew Panel();
		pane->Size = System::Drawing::Size(20, 20);
		pane->BackColor = Color::FromArgb(231, 234, 98);
		if (i==0) {

			pane->Location = Point((panel2->Width / 2 - pane->Width / 2)+pane->Width*i ,0);
		}
		else {
			pane->Location = Point((panel2->Width / 2 - pane->Width / 2) + pane->Width * i*2,
				pane->Height * i*2
			);
		}
		Label^ label = gcnew Label();

		label->Text = i.ToString();
		label->AutoSize = true;
		label->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		pane->Controls->Add(label);
		listpanels->Add(pane);
		list_points->Add(Point(pane->Location.X+pane->Width/2, pane->Location.Y+pane->Height/2));
	}
		
	for (int i = 0; i < list_points->Count; i++) {
		curvePoints[i] = list_points[i];
	}
	
	for each (Panel ^ panel in listpanels) {
		panel2->Controls->Add(panel);
	}
	for (int i = 1; i < list_points->Count; i++) {
		pg->DrawLine(red_pen, curvePoints[i-1].X, curvePoints[i-1].Y, curvePoints[i].X, curvePoints[i].Y);
	}
		delete pg;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->listpanels = (gcnew List<Panel^>());
	}

};
}
