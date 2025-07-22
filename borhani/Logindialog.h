#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"
#include "admin.h"
#include "linkedlist.h"

using namespace std;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(LinkedList<User>* userList, Admin* admin, QWidget *parent = nullptr);
    ~LoginDialog();

    User* getLoggedInUser() const;
    bool isAdminLoggedIn() const;

private slots:
    void on_btnLogin_clicked();
    void on_btnExit_clicked();

private:
    Ui::LoginDialog *ui;
    LinkedList<User>* m_userList;
    Admin* m_admin;
    User* m_loggedInUser = nullptr;
    bool m_adminLoggedIn = false;
};

#endif // LOGINDIALOG_H
