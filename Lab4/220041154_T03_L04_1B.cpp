#include <iostream>
#include <string>
typedef long long int lli;
typedef long double ld;
#define loop(i, n) for (lli i = 0; i < (n); i++)
#define endl "\n"
using namespace std;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
class BankAccount {
   private:
    lli account_number;
    string holder_name;
    string account_type;
    ld current_balance;
    const ld minimum_balance;

   public:
    static lli total_accounts;
    static ld total_source_tax;
    BankAccount(lli acc_num, string name, string acc_type, ld balance,
                ld min_balance)
        : account_number(acc_num),
          holder_name(name),
          account_type(acc_type),
          current_balance(balance),
          minimum_balance(min_balance) {
        total_accounts++;
    }
    ~BankAccount() {
        cout << "Account of Mr. " << holder_name << " with account no "
             << account_number << " is destroyed with a balance BDT "
             << current_balance << endl;
        total_accounts--;
    }
    void showInfo() {
        cout << "Account Number: " << account_number << endl;
        cout << "Holder Name: " << holder_name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Current Balance: " << current_balance << endl;
        cout << "Minimum Balance: " << minimum_balance << endl;
    }
    void showBalance() {
        cout << "Current Balance: " << current_balance << endl;
    }
    void deposit(ld amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
        } else {
            current_balance += amount;
            cout << "Deposit successful!" << endl;
        }
    }
    void withdraw(ld amount) {
        if (amount <= 0 || (current_balance - amount) < minimum_balance) {
            cout << "Invalid withdrawal amount!" << endl;
        } else {
            current_balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
    }
    void giveInterest(ld interest_rate = 3.0) {
        ld interest = (current_balance * interest_rate) / 100;
        ld source_tax = (interest * 10) / 100;
        total_source_tax += source_tax;
        current_balance += (interest - source_tax);
        cout << "Interest applied, Source Tax deducted!" << endl;
    }
    ld getBalance() const { return current_balance; }
    static void display_stat() {
        cout << "Total Accounts Created: " << total_accounts << endl;
        cout << "Total Source Tax Collected: " << total_source_tax << endl;
    }
};
lli BankAccount::total_accounts = 0;
ld BankAccount::total_source_tax = 0;
BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    if (A.getBalance() > B.getBalance())
        return A;
    else
        return B;
}

int main() {
    fast();
    BankAccount acc1(1234, "John Doe", "Savings", 5000, 1000);
    BankAccount acc2(5678, "Jane Smith", "Current", 7000, 1500);
    acc1.showInfo();
    acc2.showInfo();
    acc1.deposit(1500);
    acc1.showBalance();
    acc2.withdraw(1000);
    acc2.showBalance();
    acc1.giveInterest();
    acc1.showBalance();
    BankAccount largerAcc = Larger(acc1, acc2);
    cout << "The account with a larger balance is: " << endl;
    largerAcc.showInfo();
    BankAccount::display_stat();
    return 0;
}
