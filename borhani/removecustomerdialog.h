
#ifndef REMOVECUSTOMERDIALOG_H
#define REMOVECUSTOMERDIALOG_H

#include <QDialog>
#include "ui_RemoveCustomerDialog.h"
#include "User.h"
#include "Admin.h"
#include "LinkedList.h"

using namespace std;

class RemoveCustomerDialog : public QDialog {
    Q_OBJECT

public:
    explicit RemoveCustomerDialog(Admin* admin,
                                  LinkedList<User>* users,
                                  QWidget* parent = nullptr);

private slots:
    void on_btnRemove_clicked();
    void on_btnCancel_clicked();

private:
    Ui::RemoveCustomerDialog ui;
    Admin*            m_admin;
    LinkedList<User>* m_userList;
};

#endif // REMOVECUSTOMERDIALOG_H
