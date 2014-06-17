#include "application.h"
#include "mainwindow.h"

extern "C" {

void on_menu_main_win_trigger(GtkMenu*, gpointer data)
{
	auto app = static_cast<Application*>(data);
	app->showMainWindow();
}

void on_menu_exit_trigger(GtkMenu*, gpointer data)
{
	auto app = static_cast<Application*>(data);
	app->quit();
}

}


Application::Application(int &argc, char **argv)
		: QApplication(argc, argv)
		, win_(new MainWindow)
{
	setQuitOnLastWindowClosed(false);

	indicator_ = new QAppIndicator(QStringLiteral("ExampleApp"),
			QStringLiteral("clock"),
			APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
	indicator_->setStatus(APP_INDICATOR_STATUS_ACTIVE);
	indicator_->setAttentionIconFull(
			QStringLiteral("system-hibernate"),
			QStringLiteral("window showed"));
	indicator_->setMenu(buildIndicatorMenu());
}

GtkMenu *Application::buildIndicatorMenu()
{
	auto menu = gtk_menu_new();

	auto item = gtk_menu_item_new_with_label("Show Window");
	g_signal_connect(item, "activate", G_CALLBACK(on_menu_main_win_trigger), this);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);

	// seperator
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), gtk_menu_item_new());

	item = gtk_menu_item_new_with_label("Exit");
	g_signal_connect(item, "activate", G_CALLBACK(on_menu_exit_trigger), this);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);

	return GTK_MENU(menu);
}

void Application::showMainWindow()
{
	win_->show();
	indicator_->setStatus(APP_INDICATOR_STATUS_ATTENTION);
}
