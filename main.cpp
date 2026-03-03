#include "main.h"               // Подключаем заголовки классов
#include "tsnsoft.xpm"          // Подключаем иконку (должна быть в папке проекта)

IMPLEMENT_APP(MainApp);         // Макрос создания точки входа в приложение

// ============================================================================
// Реализация вспомогательных окон (MyDialog и SecondFrame)
// ============================================================================

// Конструктор диалога
MyDialog::MyDialog(wxWindow* parent) : MyDialog1(parent) {
	// В wxFormBuilder заголовки должны быть обернуты в _(), тогда они обновятся сами
	m_button3->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) { Close(); }); // Закрытие по кнопке
}

// Конструктор второго окна
SecondFrame::SecondFrame(wxWindow* parent) : MyFrame2(parent) {
	m_button5->Bind(wxEVT_BUTTON, &SecondFrame::OnButtonPress, this); // Привязка клика
}

// Обработка кнопки во втором окне
void SecondFrame::OnButtonPress(wxCommandEvent& event) {
	// Вывод сообщения (текст будет взят из .mo файла для текущего языка)
	wxMessageBox(_("Button pressed in second window!"), _("Information"), wxOK);
}

// ============================================================================
// Реализация основного класса приложения (MainApp)
// ============================================================================

bool MainApp::OnInit() {
	// Инициализируем конфиг (хранит настройки в реестре или файле)
	wxConfig::Set(new wxConfig("MyApp736"));
	
	// Читаем последний язык (по умолчанию ставим Английский, если записи нет)
	int lastLang = wxConfigBase::Get()->ReadLong("/Language", wxLANGUAGE_ENGLISH);
	
	// Применяем локализацию
	SetLanguage(lastLang);
	
	// Создаем и показываем главное окно
	MainFrame* frame = new MainFrame(NULL);
	SetTopWindow(frame);
	frame->Show();
	
	return true; // Запуск цикла обработки сообщений
}

int MainApp::OnExit() {
	if (m_locale) delete m_locale; // Удаляем локаль для очистки памяти
	delete wxConfig::Set(nullptr); // Очищаем объект конфигурации
	return wxApp::OnExit();
}

// Метод для настройки локали
void MainApp::SetLanguage(int lang) {
	if (m_locale) {
		delete m_locale; // Удаляем старую локаль, если она была
		m_locale = nullptr;
	}
	
	m_locale = new wxLocale;
	
	// Пытаемся инициализировать выбранный язык
	if (!m_locale->Init(lang)) {
		// Если язык не найден в системе, ставим Английский как запасной
		m_locale->Init(wxLANGUAGE_ENGLISH);
	}
	
	// Указываем папку, где лежат переводы (.mo файлы)
	m_locale->AddCatalogLookupPathPrefix("locale");
	
	// Загружаем файлы переводов (ru.mo, pt.mo и т.д.)
	m_locale->AddCatalog("kk");       // Казахский перевод
	m_locale->AddCatalog("ru");       // Русский перевод
	m_locale->AddCatalog("uz");       // Узбекский перевод
	
}

// ============================================================================
// Реализация главного окна (MainFrame)
// ============================================================================

MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent) {
	this->SetIcon(wxIcon(tsnsoft_xpm)); // Устанавливаем иконку окна
	
	// Читаем активный язык из конфига для правильной отметки в списке Choice
	int currentLang = wxConfigBase::Get()->ReadLong("/Language", wxLANGUAGE_ENGLISH);
	
	// en pt ru uz
	// Синхронизируем выбор в выпадающем списке (индексы должны совпадать с OnLanguageSelected)
	if (currentLang == wxLANGUAGE_KAZAKH)
		m_choice1->SetSelection(1);
	else if (currentLang == wxLANGUAGE_RUSSIAN)
		m_choice1->SetSelection(2);
	else if (currentLang == wxLANGUAGE_UZBEK)
		m_choice1->SetSelection(3);
	else
		m_choice1->SetSelection(0);
	
	// Привязываем события смены языка и нажатия на кнопку "Далее"
	m_choice1->Bind(wxEVT_CHOICE, &MainFrame::OnLanguageSelected, this);
	m_button1->Bind(wxEVT_BUTTON, &MainFrame::OnNextButtonClick, this);
}

MainFrame::~MainFrame() {}

// Обработчик закрытия окна (обязательно должен быть в .cpp)
void MainFrame::OnCloseFrame(wxCloseEvent& event) {
	Destroy(); 
}

// Вызывается при выборе языка в Choice
void MainFrame::OnLanguageSelected(wxCommandEvent& event) {
	int sel = m_choice1->GetSelection();
	int newLang;
	
	// en pt ru uz
	// Сопоставляем индекс выбора с константами wxWidgets
	if (sel == 1)
		newLang = wxLANGUAGE_KAZAKH;          
	else if (sel == 2)
		newLang = wxLANGUAGE_RUSSIAN;       
	else if (sel == 3)                      
		newLang = wxLANGUAGE_UZBEK;         
	else
		newLang = wxLANGUAGE_ENGLISH;       
	
	// 1. Сохраняем новый выбор в настройки
	wxConfigBase::Get()->Write("/Language", newLang);
	wxConfigBase::Get()->Flush();
	
	// 2. Сначала ПОЛНОСТЬЮ обновляем локаль в объекте приложения
	wxGetApp().SetLanguage(newLang);
	
	// 3. Теперь создаем НОВОЕ окно. Его конструктор вызовет _() и подтянет новый язык.
	MainFrame* newFrame = new MainFrame(NULL);
	newFrame->Show();
	
	// 4. Подменяем указатель на главное окно
	wxGetApp().SetTopWindow(newFrame);
	
	// 5. Уничтожаем старое окно (на старом языке)
	this->Close(true); 
	
	// Выводим сообщение (уже переведенное на новый язык)
	wxMessageBox(_("Language changed successfully!"), _("Information"), wxOK | wxICON_INFORMATION);
}

// Кнопка перехода к другим окнам
void MainFrame::OnNextButtonClick(wxCommandEvent& event) {
	MyDialog dlg(this); // Показываем модальный диалог
	dlg.ShowModal();
	
	SecondFrame* f2 = new SecondFrame(this); // Создаем и открываем второе окно
	f2->Show();
}
