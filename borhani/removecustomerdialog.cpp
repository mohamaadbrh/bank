
#include "RemoveCustomerDialog.h"
#include <QMessageBox>

RemoveCustomerDialog::RemoveCustomerDialog(Admin* admin,
                                           LinkedList<User>* users,
                                           QWidget* parent)
    : QDialog(parent),
    m_admin(admin),
    m_userList(users)
{
    ui.setupUi(this);
}

void RemoveCustomerDialog::on_btnRemove_clicked() {
    string code = ui.lineEdit->text().toStdString();
    bool ok = m_admin->removeUser(*m_userList, code);
    if (ok) {
        QMessageBox::information(this, "Success", "Customer removed.");
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Customer not found.");
    }
}

void RemoveCustomerDialog::on_btnCancel_clicked() {
    reject();
}
