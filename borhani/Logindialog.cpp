#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(LinkedList<User>* userList, Admin* admin, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::LoginDialog),
    m_userList(userList),
    m_admin(admin)
{
    ui->setupUi(this);
    ui->lePassword->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::on_btnLogin_clicked() {
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both username and password.");
        return;
    }

    // چک ادمین
    if (username == QString::fromStdString(m_admin->getUserName()) &&
        password == QString::fromStdString(m_admin->getPass1())) {
        m_adminLoggedIn = true;
        accept();
        return;
    }

    // چک کاربران معمولی
    for (Node<User>* cur = m_userList->getHead(); cur; cur = cur->next) {
        User* u = cur->data;
        if (username == QString::fromStdString(u->getUserName()) &&
            password == QString::fromStdString(u->getPass1())) {
            m_loggedInUser = u;
            accept();
            return;
        }
    }

    QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
}

void LoginDialog::on_btnExit_clicked() {
    reject();
}

User* LoginDialog::getLoggedInUser() const { return m_loggedInUser; }
bool   LoginDialog::isAdminLoggedIn() const { return m_adminLoggedIn; }
