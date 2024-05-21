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
    };
int main(){
cout<<"";
return 0;
}