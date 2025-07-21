
#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
public:

    User(const string& firstName,
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
    virtual ~User() = default;

    const string& getFirstName()    const { return firstName;    }
    const string& getLastName()     const { return lastName;     }
    const string& getNationalCode() const { return nationalCode; }
    int          getAge()           const { return age;          }
    const string& getUserName()     const { return userName;     }
    const string& getPass1()        const { return pass1;        }
    const string& getCardNumber()   const { return cardNumber;   }
    const string& getExpiryDate()   const { return expiryDate;   }
    const string& getCvv2()         const { return cvv2;         }
    const string& getPass2Static()  const { return pass2Static;  }
    long long    getBalance()       const { return balance;      }
    void setUserName(const string& u) { userName = u; }
    void setPass1    (const string& p) { pass1    = p; }

    virtual bool isAdmin() const { return false; }

    string generateDynamicPass2(int length = 6);

    void adjustBalance(long long delta) { balance += delta; }

private:
    string firstName;
    string lastName;
    string nationalCode;
    int    age;

    string userName;
    string pass1;


    string cardNumber;
    string expiryDate;
    string cvv2;
    string pass2Static;

    long long balance;
};

#endif // USER_H
