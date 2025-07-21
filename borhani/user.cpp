#include "User.h"

User::User(const string& firstName,
           const string& lastName,
           const string& nationalCode,
           int age,
           const string& userName,
           const string& pass1,
           const string& cardNumber,
           const string& expiryDate,
           const string& cvv2,
           const string& pass2Static,
           long long balance)
    : firstName(firstName)
    , lastName(lastName)
    , nationalCode(nationalCode)
    , age(age)
    , userName(userName)
    , pass1(pass1)
    , cardNumber(cardNumber)
    , expiryDate(expiryDate)
    , cvv2(cvv2)
    , pass2Static(pass2Static)
    , balance(balance)
{}
