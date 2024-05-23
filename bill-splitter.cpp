#include<iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <vector>

class BillSplitter {
private:
    unordered_map<string, double> balances;

public:
    void addFriend( string &name) {
        if (balances.find(name) == balances.end()) {
            balances[name] = 0;
        } else {
            cout << name << " is already added." << endl;
        }
    }

    void addExpense( string &payer,  vector<string> &payees, double amount) {
        if (balances.find(payer) == balances.end()) {
            cout << "Payer " << payer << " not found." << endl;
            return;
        }

        double share = amount / payees.size();

        balances[payer] += amount;
        for (const string &payee : payees) {
            if (balances.find(payee) == balances.end()) {
                cout << "Payee " << payee << " not found." << endl;
                continue;
            }
            if (payee != payer) {
                balances[payee] -= share;
            }
        }}
        void displayBalance() const {
        for (const auto &pair : balances) {
            if (pair.second > 0) {
                cout << pair.first << " needs to collect " << pair.second << " from others." << endl;
            } else if (pair.second < 0) {
                cout << pair.first << " needs to pay " << -pair.second << " to others." << endl;
            } else {
                cout << pair.first << " has no balance." << endl;
            }
        }
    }
    };
int main(){
cout<<"";
cout << "Final Balances:"<<endl;
    splitter.displayBalance();
return 0;
}
