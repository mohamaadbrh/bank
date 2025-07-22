// dialogs/UserWindow.h
#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include "ui_UserWindow.h"
#include "User.h"
#include "LinkedList.h"
#include "Admin.h"

using namespace std;

class UserWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit UserWindow(User* user,
                        LinkedList<User>* users,
                        Admin* admin,
                        QWidget* parent = nullptr);

private slots:
    void on_btnViewMyAccounts_clicked();
    void on_btnCardToCard_clicked();
    void on_btnEditProfile_clicked();
    void on_btnExit_clicked();

private:
    Ui::UserWindow    ui;
    User*             m_currentUser;
    LinkedList<User>* m_userList;
    Admin*            m_admin;
};

#endif // USERWINDOW_H
