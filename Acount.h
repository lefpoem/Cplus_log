#include <string>
using namespace std;
class Account{
public:
    void applyint(){amount += amount*interestRate;}
    static double rate() {return interestRate;}
    static void rate(double); // sets a new rate
private:
    string owner;
    double amount;
    static double interestRate;
    static const int period = 30;//static const member defined in the class
    static double initRate();
};
//static member must defined in the outer of class
double Account::interestRate = initRate();
void Account::rate(double newRate)
{
    interestRate = newRate;
}
