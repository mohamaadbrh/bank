#ifndef EDITPROFILE2DIALOG_H
#define EDITPROFILE2DIALOG_H

#include <QDialog>
#include "ui_EditProfile2Dialog.h"
#include "User.h"

using namespace std;

class EditProfile2Dialog : public QDialog {
    Q_OBJECT

public:
    explicit EditProfile2Dialog(User* user,
                                QWidget* parent = nullptr);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::EditProfile2Dialog ui;
    User*                 m_user;
};

#endif // EDITPROFILE2DIALOG_H
