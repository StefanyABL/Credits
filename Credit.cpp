
#include "Credit.hpp"
#include<string>
#include<iostream>
#include <sstream>



Credit::Credit() {
}

Credit::Credit(std::string id, double amount, short int term, float rate,double amounts) {
    setId(id);
    setAmount(amount);
    setTerm(term);
    setRate(rate);
    setAmounts(amounts);
}

bool Credit::doPay(double amount) {
      contPays++;
      
      double saldo=getAmount()-(amount-calcInterest());
      if(saldo>=0){
      double interest=calcInterest();
      double newamount=amount-calcInterest();
      setAmount(saldo);
      pays.push_back(Pay(contPays,newamount,interest));
      
    return true;
      }else{
      double amount1=(amount-calcInterest())-getAmount();
      double amount2=amount-amount1;
      double interest=calcInterest();
      double newamount=amount2-calcInterest();
      setAmount(0);
      pays.push_back(Pay(contPays,newamount,interest)); 
          setCambio(amount1);
          return true;
     }
      setContPays(contPays);
        return false;  
     
}

double Credit::calcInterest() {
    residue=(amount*rate)/100;
    return residue;
}

void Credit::setId(std::string id) {
    this->id = id;
}

std::string Credit::getId() {
    return id;

}

void Credit::setAmount(double amount) {
    this->amount = amount;
}

double Credit::getAmount() {
    return amount;
}

void Credit::setTerm(short int term) {
    this->term = term;
}

short int Credit::getTerm() {
    return term;
}

void Credit::setRate(float rate) {
    this->rate = rate;
}

float Credit::getRate() {
    return rate;
}

double Credit::getResidue() {
    return residue;
}

void Credit::setResidue(double residue) {
    this->residue=residue;
}


double Credit::getAmounts() {
    return amounts;
}

void Credit::setAmounts(double amounts) {
    this->amounts=amounts;
}
double Credit::getCambio() {
    return cambio;
}

void Credit::setCambio(double cambio) {
    this->cambio=cambio;
}

int Credit::getContPays() {
    return contPays;
}

void Credit::setContPays(int contPays) {
    this->contPays=contPays;
}

std::string Credit::getParse(std::string& out, double n) {
    std::ostringstream output;
    output << n;
    out = output.str();
    return out;
}

double Credit::paysamount() {
    double cuotas=0;
for(int i=0; i<pays.size(); i++){  
    cuotas+=pays.at(i).getAmount();
}
 return cuotas;
}

double Credit::paysinterts() {
  double interes=0;
for(int i=0; i<pays.size(); i++){  
    interes+=pays.at(i).getInterest();
}
 return interes;
}

std::string Credit::toString() {
    std::string outPut = "";
    std::string c = "";
    std::string m = "";
    std::string p = "";
    std::string a = "";
    getParse(c,amount);  
    getParse(m,term);
    getParse(p,rate);
    getParse(a,amounts);
    outPut += "  " + id + "             "+a+"               " + c + "                    " + m + "                     " + p + "% ";
    return outPut;

}
  std::vector<Pay> Credit::getPays() {
    return pays;
}

Credit::~Credit() {
}

