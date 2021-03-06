#ifndef BUDDYFORM_H
#define BUDDYFORM_H
#include "getaddressform.h"
#include "presence/buddy.h"
#include <QTreeWidgetItem>
#include "user.h"
#include "ui_buddyform.h"

class BuddyForm : public QDialog, public Ui::BuddyForm
{
	Q_OBJECT

public:
    BuddyForm(QWidget* parent = 0);
	~BuddyForm();

public slots:
    virtual void showNew( t_buddy_list & _buddy_list, QTreeWidgetItem * _profileItem );
	virtual void showEdit( t_buddy & buddy );
	virtual void validate();
	virtual void showAddressBook();
	virtual void selectedAddress( const QString & name, const QString & phone );

protected slots:
	virtual void languageChange();

private:
	GetAddressForm *getAddressForm;
	t_user *user_config;
	bool edit_mode;
	t_buddy_list *buddy_list;
	t_buddy *edit_buddy;
    QTreeWidgetItem *profileItem;

	void init();
	void destroy();

};


#endif
