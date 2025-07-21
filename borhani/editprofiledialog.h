#ifndef EDITPROFILEDIALOG_H
#define EDITPROFILEDIALOG_H

#include <QDialog>
#include "ui_EditProfileDialog.h"
#include "User.h"
#include "Admin.h"
#include "LinkedList.h"

using namespace std;

class EditProfileDialog : public QDialog {
    Q_OBJECT

public:
    explicit EditProfileDialog(Admin* admin,
                               LinkedList<User>* users,
                               QWidget* parent = nullptr);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::EditProfileDialog ui;
    Admin*             m_admin;
    LinkedList<User>*  m_userList;
};

#endif // EDITPROFILEDIALOG_H
