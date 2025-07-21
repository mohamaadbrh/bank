
#include "ViewCustomersDialog.h"
#include <QTableWidgetItem>
#include <QHeaderView>

ViewCustomersDialog::ViewCustomersDialog(LinkedList<User>* users,
                                         QWidget* parent)
    : QDialog(parent)
    , m_userList(users)
{
    ui.setupUi(this);

    ui.tableWidget->setColumnCount(4);
    ui.tableWidget->setHorizontalHeaderLabels({
        "First Name",
        "Last Name",
        "National Code",
        "Username"
    });
    ui.tableWidget->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);
    int row = 0;
    for (Node<User>* cur = m_userList->getHead(); cur; cur = cur->next) {
        User* u = cur->data;
        if (!u->isAdmin()) {
            ui.tableWidget->insertRow(row);
            ui.tableWidget->setItem(row, 0,
                                    new QTableWidgetItem(QString::fromStdString(u->getFirstName())));
            ui.tableWidget->setItem(row, 1,
                                    new QTableWidgetItem(QString::fromStdString(u->getLastName())));
            ui.tableWidget->setItem(row, 2,
                                    new QTableWidgetItem(QString::fromStdString(u->getNationalCode())));
            ui.tableWidget->setItem(row, 3,
                                    new QTableWidgetItem(QString::fromStdString(u->getUserName())));
            ++row;
        }
    }
}
