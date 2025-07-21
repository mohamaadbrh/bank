#ifndef CARDTOCARDDIALOG_H
#define CARDTOCARDDIALOG_H

#include <QDialog>
#include "ui_CardToCardDialog.h"
#include "User.h"
#include "LinkedList.h"

using namespace std;

class CardToCardDialog : public QDialog {
    Q_OBJECT

public:
    explicit CardToCardDialog(User* currentUser,
                              LinkedList<User>* users,
                              QWidget* parent = nullptr);

private slots:
    void on_btnTransfer_clicked();
    void on_btnCancel_clicked();

private:
    Ui::CardToCardDialog ui;
    User*             m_currentUser;
    LinkedList<User>* m_userList;

    bool validateExpiry(const QString& exp);
    User* findByCard(const string& cardNo);
    string generateOtp(int length = 6);
};

#endif // CARDTOCARDDIALOG_H
