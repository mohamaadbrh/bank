#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "ui_LoginDialog.h"

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void on_btnLogin_clicked();
    void on_btnExit_clicked();

private:
    Ui::LoginDialog ui;
};

#endif // LOGINDIALOG_H
