
#include "AddCustomerDialog.h"
#include <QMessageBox>

AddCustomerDialog::AddCustomerDialog(Admin* admin,
                                     LinkedList<User>* users,
                                     QWidget* parent)
    : QDialog(parent)
    , m_admin(admin)
    , m_userList(users)
{
    ui.setupUi(this);
}

void AddCustomerDialog::on_btnSave_clicked() {

    std::string firstName    = ui.lineEdit->text().toStdString();
    std::string lastName     = ui.lineEdit_2->text().toStdString();
    std::string nationalCode = ui.lineEdit_3->text().toStdString();
    int         age          = ui.lineEdit_4->text().toInt();
    std::string userName     = ui.lineEdit_5->text().toStdString();
    std::string pass1        = ui.lineEdit_6->text().toStdString();
    std::string cardNumber   = ui.lineEdit_7->text().toStdString();
    std::string expiryDate   = ui.lineEdit_8->text().toStdString();
    std::string cvv2         = ui.lineEdit_9->text().toStdString();
    std::string pass2Static  = ui.lineEdit_10->text().toStdString();
    long long   balance      = ui.lineEdit_11->text().toLongLong();

    User* newUser = new User(
        firstName, lastName, nationalCode,
        age, userName, pass1,
        cardNumber, expiryDate,
        cvv2, pass2Static,
        balance
        );
    m_admin->addUser(*m_userList, newUser);
    accept();
}

void AddCustomerDialog::on_btnCancel_clicked() {
    reject();
}
