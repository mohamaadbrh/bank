#ifndef ADDCUSTOMERDIALOG_H
#define ADDCUSTOMERDIALOG_H

#include <QDialog>
#include "ui_AddCustomerDialog.h"
#include "User.h"
#include "Admin.h"
#include "LinkedList.h"

class AddCustomerDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddCustomerDialog(Admin* admin,
                               LinkedList<User>* users,
                               QWidget* parent = nullptr);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::AddCustomerDialog ui;
    Admin*               m_admin;
    LinkedList<User>*    m_userList;
};

#endif // ADDCUSTOMERDIALOG_H
