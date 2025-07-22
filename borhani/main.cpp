#include <QApplication>
#include <ctime>

#include "LoginDialog.h"
#include "LinkedList.h"
#include "User.h"
#include "Admin.h"
#include "AdminWindow.h"
#include "UserWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(nullptr));

    Admin admin(
        "mohamad",                 // firstName
        "borhani",               // lastName
        "1274847532",          // nationalCode
        19,                    // age
        "admin",               // userName
        "1234",                // pass1
        "6037991234567890",    // cardNumber
        "1406/12",             // expiryDate (yyyy/MM)
        "1212",                 // cvv2
        "123456",              // pass2Static
        0                      // balance
        );

    LinkedList<User> userList;

    LoginDialog loginDlg(&userList, &admin);
    if (loginDlg.exec() == QDialog::Accepted) {
        if (loginDlg.isAdminLoggedIn()) {
            auto *w = new AdminWindow(&admin, &userList);
            w->show();
            return a.exec();
        } else {
            User* u = loginDlg.getLoggedInUser();
            auto *w = new UserWindow(u, &userList, &admin);
            w->show();
            return a.exec();
        }
    }
    return 0;
}
