
#include "ManagementCredit.hpp"
#include "Credit.hpp"
#include <string>

int cont=0;

ManagementCredit::ManagementCredit() {

}

 Credit* ManagementCredit::findCredit(std::string id){
    for(int i=0; i<credits.size(); i++){
        if(credits.at(i).getId().compare(id) == 0){
            return &credits.at(i);
        }
    }
    return NULL;
 }
 
  bool ManagementCredit::addCredit(std::string id,double amount,short int term,float rate){
      
       if(findCredit(id) == NULL){
        double amounts=amount;
         credits.push_back(Credit(id,amount,term,rate,amounts));       
        return true;
    }
    return false;
  }
  
  bool ManagementCredit:: doPay(std::string id,double amount){
      Credit* credit=findCredit(id);
      if(credit!= NULL){
         credit->doPay(amount);
         return true;         
     }
      return false;
  }
  std::vector<Credit> ManagementCredit::getCredits() {
    return credits;
}
  

ManagementCredit::~ManagementCredit() {
}

