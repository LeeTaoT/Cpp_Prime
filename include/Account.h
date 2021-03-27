#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <string>

class Account
{

private:
    std::string ower;
    double amount = 0.0;
    static double interestRate;
    static double initRate()    {return .0225;}
    static const std::string accountType;
    static constexpr int period = 30;
    double daily_tbl[period];

public:
    Account() = default;
    Account(const std::string &s, double amt):
        ower(s), amount(amt){ }
    
    void calculate(){amount += amount * interestRate;}
    double balance(){return amount;}
public:
    static double rate(){return interestRate;}
    static void rate(double);

    ~Account() = default;
};




#endif