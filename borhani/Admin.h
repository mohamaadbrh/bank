
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "LinkedList.h"

class Admin : public User {
public:

    Admin(const string& firstName,
          const string& lastName,
          const string& nationalCode,
          int age,
          const string& userName,
          const string& pass1,
          const string& cardNumber,
          const string& expiryDate,
          const string& cvv2,
          const string& pass2Static,
          long long balance);

    bool isAdmin() const override { return true; }


    void addUser(LinkedList<User>& list, User* newUser) {
        list.append(newUser);
    }

    bool removeUser(LinkedList<User>& list, const string& nationalCode) {

        User* u = list.find([&](const User* usr){
            return usr->getNationalCode() == nationalCode;
        });
        if (!u) return false;

        return true;
    }
};

#endif // ADMIN_H
