
#ifndef VIEWCUSTOMERSDIALOG_H
#define VIEWCUSTOMERSDIALOG_H

#include <QDialog>
#include "ui_ViewCustomersDialog.h"
#include "LinkedList.h"
#include "User.h"

using namespace std;

class ViewCustomersDialog : public QDialog {
    Q_OBJECT

public:
    explicit ViewCustomersDialog(LinkedList<User>* users,
                                 QWidget* parent = nullptr);

private:
    Ui::ViewCustomersDialog ui;
    LinkedList<User>*       m_userList;
};

#endif // VIEWCUSTOMERSDIALOG_H
