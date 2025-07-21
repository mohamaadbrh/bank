
#ifndef VIEWMYACCOUNTDIALOG_H
#define VIEWMYACCOUNTDIALOG_H

#include <QDialog>
#include "ui_ViewMyAccountDialog.h"
#include "User.h"

using namespace std;

class ViewMyAccountDialog : public QDialog {
    Q_OBJECT

public:
    explicit ViewMyAccountDialog(User* user, QWidget* parent = nullptr);

private:
    Ui::ViewMyAccountDialog ui;
    User*                   m_user;
};

#endif // VIEWMYACCOUNTDIALOG_H
