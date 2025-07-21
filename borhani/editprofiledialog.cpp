#include "EditProfileDialog.h"
#include <QMessageBox>

EditProfileDialog::EditProfileDialog(Admin* admin,
                                     LinkedList<User>* users,
                                     QWidget* parent)
    : QDialog(parent)
    , m_admin(admin)
    , m_userList(users)
{
    ui.setupUi(this);
}

void EditProfileDialog::on_btnSave_clicked() {
    string code         = ui.lineEdit->text().toStdString();
    string newUserName  = ui.lineEdit_2->text().toStdString();
    string newPass      = ui.lineEdit_3->text().toStdString();
    long long newBalance= ui.lineEdit_4->text().toLongLong();


    User* u = m_userList->find([&](const User* usr){
        return usr->getNationalCode() == code;
    });

    if (!u) {
        QMessageBox::warning(this, "Error", "Customer not found.");
        return;
    }


    u->setUserName(newUserName);
    u->setPass1(newPass);

    long long delta = newBalance - u->getBalance();
    u->adjustBalance(delta);

    QMessageBox::information(this, "Success", "Profile updated.");
    accept();
}

void EditProfileDialog::on_btnCancel_clicked() {
    reject();
}
