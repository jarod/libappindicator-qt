#ifndef QAPPINDICATOR_H
#define QAPPINDICATOR_H

#include <QObject>
#define QT_SIGNALS_ signals
#undef signals
extern "C"
{
#include <gtk/gtk.h>
#include <libappindicator/app-indicator.h>
}
#define signals QT_SIGNALS_
#undef QT_SIGNALS_

class QAppIndicator: public QObject
{
Q_OBJECT

public:
	QAppIndicator(QString id, QString iconName, AppIndicatorCategory category);
	QAppIndicator(QString id, QString iconName, AppIndicatorCategory category, QString iconThemePath);

	QString id();
	AppIndicatorCategory category();

	void setStatus(AppIndicatorStatus status);
	AppIndicatorStatus status();

	/**
	 * @brief setMenu set menu and show all menu items
	 * @param menu
	 */
	void setMenu(GtkMenu *menu);
	GtkMenu* menu();

	void setAttentionIcon(QString iconName);
	void setAttentionIconFull(QString iconName, QString iconDesc);
	QString attentionIcon();
	QString attentionIconDesc();

	void setIcon(QString iconName);
	void setIconFull(QString iconName, QString iconDesc);
	void setIconThemePath(QString iconThemePath);
	QString icon();
	QString iconDesc();
	QString iconThemePath();

	void setLabel(QString label, QString guide);
	QString label();
	QString labelGuide();

	void setTitle(QString title);
	QString title();

	void setOrderingIndex(quint32 orderingIndex);
	quint32 orderingIndex();

	void setSecondaryActivateTarget(GtkWidget *menuitem);
	GtkWidget *secondaryActivateTarget();

	void buildMenuFromDesktop(QString desktopFile, QString desktopProfile);

private:
	void init(QString id, QString iconName, AppIndicatorCategory category, QString iconThemePath);
private:
	AppIndicator *self_;
};

#endif // QAPPINDICATOR_H
