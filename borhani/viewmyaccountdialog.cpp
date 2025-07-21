#include "ViewMyAccountDialog.h"

ViewMyAccountDialog::ViewMyAccountDialog(User* user, QWidget* parent)
    : QDialog(parent)
    , m_user(user)
{
    ui.setupUi(this);


    ui.lineEdit->setText(QString::fromStdString(m_user->getFirstName()));
    ui.lineEdit_2->setText(QString::fromStdString(m_user->getLastName()));
    ui.lineEdit_3->setText(QString::fromStdString(m_user->getNationalCode()));
    ui.lineEdit_4->setText(QString::number(m_user->getAge()));
    ui.lineEdit_5->setText(QString::fromStdString(m_user->getCardNumber()));
    ui.lineEdit_6->setText(QString::fromStdString(m_user->getExpiryDate()));
    ui.lineEdit_7->setText(QString::fromStdString(m_user->getCvv2()));
    ui.lineEdit_8->setText(QString::fromStdString(m_user->getPass2Static()));
    ui.lineEdit_9->setText(QString::number(m_user->getBalance()));


}
