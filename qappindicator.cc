#include "qappindicator.h"

QAppIndicator::QAppIndicator(QString &id, QString &iconName, AppIndicatorCategory category, QString &iconThemePath)
{
	init(id, iconName, category, iconThemePath);
}
QAppIndicator::QAppIndicator(QString &id, QString &iconName, AppIndicatorCategory category)
{
	QString iconThemePath;
	init(id, iconName, category, iconThemePath);
}
void QAppIndicator::init(QString &id, QString &iconName, AppIndicatorCategory category, QString &iconThemePath)
{
	if (iconThemePath.isEmpty())
	{
		self_ = ::app_indicator_new(id.toStdString().c_str(), iconName.toStdString().c_str(),
				category);
	}
	else
	{
		self_ = ::app_indicator_new_with_path(id.toStdString().c_str(), iconName.toStdString().c_str(),
				category, iconThemePath.toStdString().c_str());
	}
}

QString QAppIndicator::id()
{
	return QString::fromUtf8(::app_indicator_get_id(self_));
}

AppIndicatorCategory QAppIndicator::category()
{
	return ::app_indicator_get_category(self_);
}

void QAppIndicator::setStatus(AppIndicatorStatus status)
{
	::app_indicator_set_status(self_, status);
}
AppIndicatorStatus QAppIndicator::status()
{
	return ::app_indicator_get_status(self_);
}

void QAppIndicator::setMenu(GtkMenu *menu)
{
	::app_indicator_set_menu(self_, menu);
}
GtkMenu* QAppIndicator::menu()
{
	return ::app_indicator_get_menu(self_);
}

void QAppIndicator::setAttentionIcon(QString &iconName)
{
	::app_indicator_set_attention_icon(self_, iconName.toStdString().c_str());
}
void QAppIndicator::setAttentionIconFull(QString &iconName, QString &iconDesc)
{
	::app_indicator_set_attention_icon_full(self_, iconName.toStdString().c_str(), iconDesc.toStdString().c_str());
}
QString QAppIndicator::attentionIcon()
{
	return QString::fromUtf8(::app_indicator_get_attention_icon(self_));
}
QString QAppIndicator::attentionIconDesc()
{
	return QString::fromUtf8(::app_indicator_get_attention_icon_desc(self_));
}

void QAppIndicator::setIcon(QString &iconName)
{
	::app_indicator_set_icon(self_, iconName.toStdString().c_str());
}
void QAppIndicator::setIconFull(QString &iconName, QString &iconDesc)
{
	::app_indicator_set_icon_full(self_, iconName.toStdString().c_str(), iconDesc.toStdString().c_str());
}
void QAppIndicator::setIconThemePath(QString &iconThemePath)
{
	::app_indicator_set_icon_theme_path(self_, iconThemePath.toStdString().c_str());
}
QString QAppIndicator::icon()
{
	return QString::fromUtf8(::app_indicator_get_icon(self_));
}
QString QAppIndicator::iconDesc()
{
	return QString::fromUtf8(::app_indicator_get_icon_desc(self_));
}
QString QAppIndicator::iconThemePath()
{
	return QString::fromUtf8(::app_indicator_get_icon_theme_path(self_));
}

void QAppIndicator::setLabel(QString &label, QString &guide)
{
	::app_indicator_set_label(self_, label.toStdString().c_str(), guide.toStdString().c_str());
}
QString QAppIndicator::label()
{
	return QString::fromUtf8(::app_indicator_get_label(self_));
}
QString QAppIndicator::labelGuide()
{
	return QString::fromUtf8(::app_indicator_get_label_guide(self_));
}

void QAppIndicator::setTitle(QString &title)
{
	::app_indicator_set_title(self_, title.toStdString().c_str());
}
QString QAppIndicator::title()
{
	return QString::fromUtf8(::app_indicator_get_title(self_));
}

void QAppIndicator::setOrderingIndex(quint32 orderingIndex)
{
	::app_indicator_set_ordering_index(self_, orderingIndex);
}
quint32 QAppIndicator::orderingIndex()
{
	return ::app_indicator_get_ordering_index(self_);
}

void QAppIndicator::setSecondaryActivateTarget(GtkWidget *menuitem)
{
	::app_indicator_set_secondary_activate_target(self_, menuitem);
}
GtkWidget *QAppIndicator::secondaryActivateTarget()
{
	return ::app_indicator_get_secondary_activate_target(self_);
}

void QAppIndicator::buildMenuFromDesktop(QString &desktopFile, QString &desktopProfile)
{
	::app_indicator_build_menu_from_desktop(self_, desktopFile.toStdString().c_str(),
			desktopProfile.toStdString().c_str());
}
