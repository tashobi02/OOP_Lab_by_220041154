#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "SavingsAccount.h"

#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> charDist(0, 25);

using namespace std;
string generateRandomString(int length) {
    string result;
    result.reserve(length);
    loop(i, length) { result += 'a' + charDist(gen); }
    return result;
}
string generateRandomName(int minWords, int maxWords, int minLen, int maxLen) {
    int numWords = uniform_int_distribution<>(minWords, maxWords)(gen);
    string name;
    loop(i, numWords) {
        if (i > 0)
            name += ' ';
        int wordLen = uniform_int_distribution<>(minLen, maxLen)(gen);
        name += generateRandomString(wordLen);
    }
    return name;
}
void generateInformationRandom(SavingsAccount& account) {
    uniform_real_distribution<> interestDist(2.0, 5.0);
    uniform_real_distribution<> balanceDist(1000, 50000);
    string randomAccountName = generateRandomName(2, 2, 4, 10);
    string randomHolderName = generateRandomName(2, 2, 4, 10);
    string randomAddress = generateRandomName(5, 5, 4, 10);
    account.setAccountName(randomAccountName);
    account.setAccountHolderName(randomHolderName);
    account.setAddress(randomAddress);
    account.setAnnualInterestRate(static_cast<int>(interestDist(gen) * 10) /
                                  10.0);
    account.setCurrentBalance(balanceDist(gen));
}
void EditInformationByKeyboard(SavingsAccount& account) {
    string accountName, accountHolderName, address;
    ld annualInterestRate, currentBalance;
    cout << "Enter Account Name (two words): ";
    getline(cin >> ws, accountName);
    cout << "Enter Account Holder's Name (two words): ";
    getline(cin, accountHolderName);
    cout << "Enter Address (five words): ";
    getline(cin, address);
    cout << "Enter Annual Interest Rate (2.0 ~ 5.0 with 0.10 steps): ";
    cin >> annualInterestRate;
    cout << "Enter Current Balance (1000 ~ 50000): ";
    cin >> currentBalance;
    account.setAccountName(accountName);
    account.setAccountHolderName(accountHolderName);
    account.setAddress(address);
    account.setAnnualInterestRate(annualInterestRate);
    account.setCurrentBalance(currentBalance);
}
void ShowInterestAll(SavingsAccount accounts[], int size) {
    int periodInMonths;
    cout << "Enter the period (in months) for interest calculation: ";
    cin >> periodInMonths;
    loop(i, size) {
        ld interest = accounts[i].calculateInterest(periodInMonths);
        cout << "Account: " << accounts[i].getAccountName()
             << " | Interest: " << interest << " tk" << endl;
    }
    char confirm;
    cout << "Do you want to disburse interest for all accounts? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        loop(i, size) { accounts[i].disburseInterest(periodInMonths); }
        cout << "Interest disbursed successfully." << endl;
    } else {
        cout << "Interest disbursement canceled." << endl;
    }
}
void ShowAllAlphabetically(SavingsAccount accounts[], int size) {
    vector<SavingsAccount> accountList(accounts, accounts + size);
    sort(accountList.begin(), accountList.end(),
         [](const SavingsAccount& a, const SavingsAccount& b) {
             return a.getAccountName() < b.getAccountName();
         });
    for (const auto& account : accountList) {
        cout << "Account: " << account.getAccountName()
             << " | Balance: " << account.getCurrentBalance() << " tk" << endl;
    }
}
int main() {
    srand(time(0));
    const int total_accounts = 100;
    SavingsAccount accounts[total_accounts];
    loop(i, 2) {
        cout << "Enter information for account #" << (i + 1) << ":\n";
        EditInformationByKeyboard(accounts[i]);
    }
    loop(i, total_accounts - 2) { generateInformationRandom(accounts[i + 2]); }
    ShowInterestAll(accounts, total_accounts);
    ShowAllAlphabetically(accounts, total_accounts);
    return 0;
}
