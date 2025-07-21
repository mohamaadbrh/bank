
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "ui_AdminWindow.h"
#include "LinkedList.h"
#include "User.h"
#include "Admin.h"
#include "LoginDialog.h"

using namespace std;

class AdminWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AdminWindow(Admin* admin,
                         LinkedList<User>* users,
                         QWidget* parent = nullptr);

private slots:
    void on_btnAddCustomer_clicked();
    void on_btnRemoveCustomer_clicked();
    void on_btnViewAllCustomers_clicked();
    void on_btnViewAllAccounts_clicked();
    void on_btnEditProfile_clicked();
    void on_btnExit_clicked();

private:
    Ui::AdminWindow    ui;
    Admin*             m_admin;
    LinkedList<User>*  m_userList;
};

#endif // ADMINWINDOW_H
