#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H


#include <QMainWindow>
#include "ui_main_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass *ui;
};


#endif