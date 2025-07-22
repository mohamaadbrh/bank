#include "AdminWindow.h"
#include "userwindow.h"
#include "AddCustomerDialog.h"
#include "RemoveCustomerDialog.h"
#include "ViewCustomersDialog.h"
#include "ViewAccountsDialog.h"
#include "EditProfileDialog.h"
#include "LoginDialog.h"
#include <QPushButton>

AdminWindow::AdminWindow(Admin* admin,
                         LinkedList<User>* users,
                         QWidget* parent)
    : QMainWindow(parent)
    , m_admin(admin)
    , m_userList(users)
{
    ui.setupUi(this);
    connect(ui.btnAddCustomer,      &QPushButton::clicked, this, &AdminWindow::on_btnAddCustomer_clicked);
    connect(ui.btnRemoveCustomer,   &QPushButton::clicked, this, &AdminWindow::on_btnRemoveCustomer_clicked);
    connect(ui.btnViewAllCustomers, &QPushButton::clicked, this, &AdminWindow::on_btnViewAllCustomers_clicked);
    connect(ui.btnViewAllAccounts,  &QPushButton::clicked, this, &AdminWindow::on_btnViewAllAccounts_clicked);
    connect(ui.btnEditProfile,      &QPushButton::clicked, this, &AdminWindow::on_btnEditProfile_clicked);
    connect(ui.btnExit,             &QPushButton::clicked, this, &AdminWindow::on_btnExit_clicked);
}

void AdminWindow::on_btnAddCustomer_clicked() {
    AddCustomerDialog dlg(m_admin, m_userList, this);
    dlg.exec();
}

void AdminWindow::on_btnRemoveCustomer_clicked() {
    RemoveCustomerDialog dlg(m_admin, m_userList, this);
    dlg.exec();
}

void AdminWindow::on_btnViewAllCustomers_clicked() {
    ViewCustomersDialog dlg(m_userList, this);
    dlg.exec();
}

void AdminWindow::on_btnViewAllAccounts_clicked() {
    ViewAccountsDialog dlg(m_userList, this);
    dlg.exec();
}

void AdminWindow::on_btnEditProfile_clicked() {
    EditProfileDialog dlg(m_admin, m_userList, this);
    dlg.exec();
}

void AdminWindow::on_btnExit_clicked() {
    this->close();

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
