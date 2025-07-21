#include "EditProfile2Dialog.h"
#include <QMessageBox>

EditProfile2Dialog::EditProfile2Dialog(User* user,
                                       QWidget* parent)
    : QDialog(parent)
    , m_user(user)
{
    ui.setupUi(this);

    ui.lineEdit->setText(QString::fromStdString(m_user->getUserName()));
}

void EditProfile2Dialog::on_btnSave_clicked() {
    string newUserName = ui.lineEdit->text().toStdString();
    string newPass     = ui.lineEdit_2->text().toStdString();

    m_user->setUserName(newUserName);
    m_user->setPass1(newPass);

    QMessageBox::information(this, "Success", "Profile updated.");
    accept();
}

void EditProfile2Dialog::on_btnCancel_clicked() {
    reject();
}
