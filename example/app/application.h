#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <qappindicator.h>

class MainWindow;

class Application : public QApplication
{
Q_OBJECT
public:
	Application(int &argc, char **argv);

	void showMainWindow();

private:
	GtkMenu *buildIndicatorMenu();

	QAppIndicator *indicator_;
	MainWindow *win_;
};

#endif // APPLICATION_H
