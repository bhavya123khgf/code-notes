#include <iostream>
#include <string>
using namespace std;

// Custom Exception Class
class BankingException {
public:
    string message;
    BankingException(string msg) : message(msg) {}
};
//Examples-
/*if (amount <= 0) throw BankingException("Deposit must be positive");
  if (amount <= 0) throw BankingException("Withdrawal must be positive");
  if (amount > balance) throw BankingException("Insufficient balance");
  */
// now in int main() when we call the funtions... call all of them in try{} and then after that ... write...
int main()
{
    try{}
    
    catch (BankingException& e) {
            cout << "Error: " << e.message << endl;
        }
}
