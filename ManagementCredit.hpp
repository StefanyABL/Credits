
#ifndef MANAGEMENTCREDIT_HPP
#define MANAGEMENTCREDIT_HPP
#include <string>
#include <vector>
#include "Credit.hpp"
#include <stdlib.h>

class ManagementCredit {
public:
    ManagementCredit();
    std::vector<Credit> getCredits();
    Credit* findCredit(std::string id);
    bool addCredit(std::string id,double amount,short int term,float rate);
    bool doPay(std::string id,double amount);
    
    virtual ~ManagementCredit();
private:
    std::vector<Credit> credits;
   
};

#endif /* MANAGEMENTCREDIT_HPP */

