#include "CardToCardDialog.h"
#include <QMessageBox>
#include <QDate>
#include <cstdlib>

using namespace std;

CardToCardDialog::CardToCardDialog(User* currentUser,
                                   LinkedList<User>* users,
                                   QWidget* parent)
    : QDialog(parent)
    , m_currentUser(currentUser)
    , m_userList(users)
{
    ui.setupUi(this);
}

void CardToCardDialog::on_btnTransfer_clicked() {

    string srcCard   = ui.lineEdit->text().toStdString();
    QString expStr   = ui.lineEdit_2->text();
    string cvv2      = ui.lineEdit_3->text().toStdString();
    string dstCard   = ui.lineEdit_4->text().toStdString();
    long long amount = ui.lineEdit_5->text().toLongLong();
    string pass2Input= ui.lineEdit_6->text().toStdString();


    if (m_currentUser->getCardNumber() != srcCard) {
        QMessageBox::warning(this, "Error", "Invalid source card.");
        return;
    }

    if (!validateExpiry(expStr)) {
        QMessageBox::warning(this, "Error", "Card expired.");
        return;
    }

    if (m_currentUser->getCvv2() != cvv2) {
        QMessageBox::warning(this, "Error", "Invalid CVV2.");
        return;
    }

    User* dst = findByCard(dstCard);
    if (!dst) {
        QMessageBox::warning(this, "Error", "Destination card not found.");
        return;
    }

    ui.labelDestName->setText(
        QString::fromStdString(dst->getFirstName() + " " + dst->getLastName())
        );

    if (amount > 3000000LL) {
        QMessageBox::warning(this, "Error", "Transfer limit is 3,000,000.");
        return;
    }

    string otp;
    if (amount > 100000LL) {

        otp = generateOtp();
        QMessageBox::information(
            this,
            "One-Time Password",
            QString("Your dynamic pass2 is: %1")
                .arg(QString::fromStdString(otp))
            );
        if (pass2Input != otp) {
            QMessageBox::warning(this, "Error", "Invalid dynamic pass2.");
            return;
        }
    } else {

        if (pass2Input != m_currentUser->getPass2Static()) {
            QMessageBox::warning(this, "Error", "Invalid static pass2.");
            return;
        }
    }
    if (m_currentUser->getBalance() < amount) {
        QMessageBox::warning(this, "Error", "Insufficient balance.");
        return;
    }

    double fee     = amount * 0.0001;  // 0.01%
    long long net  = amount - (long long)fee;
    m_currentUser->adjustBalance(-amount);
    dst->adjustBalance(net);

    QMessageBox::information(this, "Success", "Transfer completed.");
    accept();
}

void CardToCardDialog::on_btnCancel_clicked() {
    reject();
}

bool CardToCardDialog::validateExpiry(const QString& exp) {
    QDate today = QDate::currentDate();
    QDate d     = QDate::fromString(exp, "yyyy/MM");
    return d.isValid() && d > today;
}

User* CardToCardDialog::findByCard(const string& cardNo) {
    return m_userList->find([&](const User* u){
        return u->getCardNumber() == cardNo;
    });
}

string CardToCardDialog::generateOtp(int length) {
    string otp;
    otp.reserve(length);
    for (int i = 0; i < length; ++i)
        otp += char('0' + (rand() % 10));
    return otp;
}
