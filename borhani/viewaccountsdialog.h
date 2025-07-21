
#ifndef VIEWACCOUNTSDIALOG_H
#define VIEWACCOUNTSDIALOG_H

#include <QDialog>
#include "ui_ViewAccountsDialog.h"
#include "LinkedList.h"
#include "User.h"

using namespace std;

class ViewAccountsDialog : public QDialog {
    Q_OBJECT

public:
    explicit ViewAccountsDialog(LinkedList<User>* users,
                                QWidget* parent = nullptr);

private:
    Ui::ViewAccountsDialog ui;
    LinkedList<User>*       m_userList;
};

#endif // VIEWACCOUNTSDIALOG_H
