#include<iostream>

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class BillSplitter {
private:
    unordered_map<string, double> balances;

public:
    void addFriend( string &name){
        if(balances.find(name) == balances.end()) {
            balances[name] = 0;
        }else{
            cout<<name<<"is already added."<<endl;
        }
    }
        void addExpense(string &payer,vector<string> &payees,double amount){
        if(balances.find(payer) == balances.end()){
            cout<<"Payer"<<payer<<"not found."<<endl;
            return;
        }
        double share = amount/payees.size();
         balances[payer] += amount;
        for (const string &payee:payees){
            if (balances.find(payee)==balances.end()){
                cout<<"Payee"<<payee<<"not found."<<endl;
                continue;
            }
            if(payee != payer){
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

BillSplitter splitter;
   cout<<"";
    int numFriends;
    cout<<"Enter the number of friends:";
    cout<<"";
    cin>>numFriends;
    cin.ignore();

    for(int i = 0; i<numFriends; ++i) {
        string name;
        cout<<"Enter the name of friend"<< i + 1 << ": ";
        getline(cin, name);
        splitter.addFriend(name);
    }
    int numExpenses;
    cout<<"Enter the number of expenses:";
    cin>>numExpenses;
    cin.ignore();
    for(int i = 0; i<numExpenses; ++i){
        string payer;
        cout<<"Enter the name of the payer:";
        getline(cin, payer);
        int numPayees;
        cout<<"Enter the number of payees:";
        cin>>numPayees;
        cin.ignore();
        vector<string>payees;
        for(int j = 0; j<numPayees; ++j){
            string payee;
            cout<<"Enter the name of payee"<< j + 1 << ": ";
            getline(cin, payee);
            payees.push_back(payee);
        }
        double amount;
        cout<<"Enter the total amount: ";
        cin>>amount;
        cin.ignore();
        splitter.addExpense(payer, payees, amount);
    }

return 0;
}
