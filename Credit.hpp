/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Credit.hpp
 * Author: Yuelieth Rodriguez
 *
 * Created on 1 de mayo de 2019, 03:39 PM
 */

#ifndef CREDIT_HPP
#define CREDIT_HPP
#include <string>
#include <vector>
#include "Pay.hpp"


class Credit {
public:
    Credit();
    Credit(std::string, double, short int, float,double);
    void setId(std::string id);
    std::string getId();
    void setAmount(double amount);
    double getAmount();
    void setTerm(short int term);
    short int getTerm();
    void setRate(float rate);
    float getRate();
    double getResidue();
    void setResidue(double residue);
    double getCambio();
    void setCambio(double cambio);
    bool doPay(double amount);
    void setAmounts(double amounts);
    double getAmounts();
    std::string toString();
    int getContPays();
    void setContPays(int contPays);
    double paysamount();
    double paysinterts();
    std::vector<Pay> getPays();
    std::string getParse(std::string&, double);
    
    double calcInterest();
    virtual ~Credit();

private:
    int contPays = 0;
    std::vector<Pay> pays;
    std::string id;
    double amount;
    short int term;
    float rate;
    double residue;
    double interest; 
    int amounts;
    double cambio=0;
};

#endif /* CREDIT_HPP */

