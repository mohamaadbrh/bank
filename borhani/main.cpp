#include <QApplication>
#include "LoginDialog.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginDialog loginDlg;
    if (loginDlg.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return app.exec();
    }
    return 0;
}
