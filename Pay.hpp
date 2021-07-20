

#ifndef PAY_HPP
#define PAY_HPP
#include <string>
//#include "Credit.hpp"


class Pay {
    private:
       short int number;
       double amount;
       float interest;
       float calcRate();
public:
    pay();
    Pay(short int,double,double);
    short int getNumber();
    double getAmount();
    double getInterest();
    std::string toString();
    std::string getParse(std::string&, double);
    virtual ~Pay();
};

#endif /* PAY_HPP */

