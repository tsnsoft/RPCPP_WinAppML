#ifndef __main__
#define __main__

#include <wx/wx.h>              // Библиотека wxWidgets
#include <wx/config.h>          // Работа с конфигом
#include "gui.h"                // Базовые классы из wxFormBuilder

// Главный класс приложения
class MainApp : public wxApp {
private:
	wxLocale* m_locale;         // Указатель на локаль
public:
	MainApp() : m_locale(nullptr) {} // Конструктор
	virtual bool OnInit();      // Старт приложения
	virtual int OnExit();       // Выход
	void SetLanguage(int lang); // Метод смены языка
};

DECLARE_APP(MainApp)            // Доступ через wxGetApp()

// Объявление класса диалога
class MyDialog : public MyDialog1 {
public:
	MyDialog(wxWindow* parent); // Конструктор
	virtual ~MyDialog() {}      // Деструктор
};

// Объявление класса второго окна
class SecondFrame : public MyFrame2 {
private:
	void OnButtonPress(wxCommandEvent& event); // Нажатие кнопки
public:
	SecondFrame(wxWindow* parent); // Конструктор
	virtual ~SecondFrame() {}      // Деструктор
};

// Объявление главного окна
class MainFrame : public MainFrameBase {
private:
	void UpdateUILanguage();    // Обновить тексты
	void SaveLanguage(int lang); // Сохранить язык
public:
	MainFrame(wxWindow* parent); // Конструктор
	virtual ~MainFrame();        // Деструктор
	void OnLanguageSelected(wxCommandEvent& event); // Выбор языка
	void OnNextButtonClick(wxCommandEvent& event);  // Кнопка перехода
	virtual void OnCloseFrame(wxCloseEvent& event); // Закрытие
};

#endif
