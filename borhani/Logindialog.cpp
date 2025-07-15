#include "LoginDialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

void LoginDialog::on_btnLogin_clicked() {
    const QString u = ui.leUsername->text();
    const QString p = ui.lePassword->text();
    // TODO: جایگزین کنید با منطق واقعی احراز هویت
    if (u == "admin" && p == "123") {
        accept();   // ورود موفق
    } else {
        QMessageBox::warning(this, "Login Failed", "نام‌کاربری یا رمز عبور اشتباه است");
    }
}

void LoginDialog::on_btnExit_clicked() {
    reject();      // خروج از برنامه
}
