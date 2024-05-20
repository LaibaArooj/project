#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class BillSplitter
{
private:
  unordered_map<string, double> balances;

public:
  void addFriend(const string &name)
  {
    if (balances.find(name) == balances.end())
    {
      balances[name] = 0.0;
    }
    else
    {
      cout << name << " is already added." << endl;
    }
  }
};
int main()
{

  return 0;
}