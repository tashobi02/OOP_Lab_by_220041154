#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long int lli;
typedef long double ld;

class SavingsAccount {
   private:
    string account_name;
    string account_holder_name;
    string address;
    ld annual_interest_rate;
    ld current_balance;
    ld minimum_balance;

   public:
    SavingsAccount()
        : account_name("Unknown"),
          account_holder_name("Unknown"),
          address("Unknown"),
          annual_interest_rate(0),
          current_balance(0),
          minimum_balance(0) {}

    SavingsAccount(string acc_name, string holder_name, string addr,
                   ld interest_rate, ld balance)
        : account_name(acc_name),
          account_holder_name(holder_name),
          address(addr),
          annual_interest_rate(interest_rate),
          current_balance(balance),
          minimum_balance(balance) {}

    string getAccountName() const { return account_name; }
    void setAccountName(const string& acc_name) { account_name = acc_name; }

    string getAccountHolderName() const { return account_holder_name; }
    void setAccountHolderName(const string& holder_name) {
        account_holder_name = holder_name;
    }

    string getAddress() const { return address; }
    void setAddress(const string& addr) { address = addr; }

    ld getAnnualInterestRate() const { return annual_interest_rate; }
    void setAnnualInterestRate(ld interest_rate) {
        annual_interest_rate = interest_rate;
    }

    ld getCurrentBalance() const { return current_balance; }
    void setCurrentBalance(ld balance) { current_balance = balance; }

    ld calculateInterest(lli periodInMonths) const {
        ld interest =
            (minimum_balance * annual_interest_rate * periodInMonths) /
            (100 * 12);
        return interest;
    }

    void disburseInterest(lli periodInMonths) {
        ld interest = calculateInterest(periodInMonths);
        current_balance += interest;
        minimum_balance = current_balance;
    }

    void deposit(ld amount) {
        if (amount > 0) {
            current_balance += amount;
            if (current_balance < minimum_balance)
                minimum_balance = current_balance;
        }
    }

    void withdraw(ld amount) {
        if (amount > 0 && current_balance >= amount) {
            current_balance -= amount;
        }
    }
};

#endif
