// dialogs/UserWindow.cpp
#include "UserWindow.h"
#include "ViewMyAccountDialog.h"
#include "CardToCardDialog.h"
#include "EditProfile2Dialog.h"
#include "LoginDialog.h"
#include "AdminWindow.h"

UserWindow::UserWindow(User* user,
                       LinkedList<User>* users,
                       Admin* admin,
                       QWidget* parent)
    : QMainWindow(parent)
    , m_currentUser(user)
    , m_userList(users)
    , m_admin(admin)
{
    ui.setupUi(this);

    connect(ui.btnViewMyAccounts, &QPushButton::clicked,
            this, &UserWindow::on_btnViewMyAccounts_clicked);
    connect(ui.btnCardToCard,     &QPushButton::clicked,
            this, &UserWindow::on_btnCardToCard_clicked);
    connect(ui.btnEditProfile,    &QPushButton::clicked,
            this, &UserWindow::on_btnEditProfile_clicked);
    connect(ui.btnExit,           &QPushButton::clicked,
            this, &UserWindow::on_btnExit_clicked);
}

void UserWindow::on_btnViewMyAccounts_clicked() {
    ViewMyAccountDialog dlg(m_currentUser, this);
    dlg.exec();
}

void UserWindow::on_btnCardToCard_clicked() {
    CardToCardDialog dlg(m_currentUser, m_userList, this);
    dlg.exec();
}

void UserWindow::on_btnEditProfile_clicked() {
    EditProfile2Dialog dlg(m_currentUser, this);
    dlg.exec();
}

void UserWindow::on_btnExit_clicked() {
    this->close();

    // بازگشت به صفحه لاگین
    LoginDialog dlg(m_userList, m_admin, this);
    if (dlg.exec() == QDialog::Accepted) {
        if (dlg.isAdminLoggedIn()) {
            auto *w = new AdminWindow(m_admin, m_userList);
            w->show();
        } else {
            auto *w = new UserWindow(dlg.getLoggedInUser(), m_userList, m_admin);
            w->show();
        }
    }
}
