/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yuelieth Rodriguez
 *
 * Created on 1 de mayo de 2019, 03:38 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "ManagementCredit.hpp"
#include "Credit.hpp"

using namespace std;

ManagementCredit* mngtCredit = new ManagementCredit();


void mainMenu();

void agregar() {

    cout << endl << "Ingrese el codigo del credito:" << endl;
    std::string id;
    cin>>id;
    cout << "Ingrese el valor del credito:" << endl;
    double amount;
    cin>>amount;
    cout << "Ingrese el plazo en meses:" << endl;
    short int term;
    cin>>term;
    cout << "Ingrese el interes:" << endl;
    float rate;
    cin>>rate;
    mngtCredit->addCredit(id, amount, term, rate);
    
    
    vector<Credit> credits = mngtCredit->getCredits();
   
       Credit* credit = mngtCredit->findCredit(id);
       if(credit != NULL){
        cout << " Codigo        Valor del Credito   Saldo Restante     Termino de pago en Meses     Interes " <<endl;
        cout << credit->toString() << endl;
        cout << " EL CREDITO SE AGREGO EXITOSAMENTE" << endl;
       }else{
         cout << " El Credito ya existe" << endl;  
       }
    cin.ignore();
}

void buscar() {
    cout << endl << "Ingrese el codigo del credito " << endl;
    std::string id;
    cin>>id;
    cin.ignore();
    Credit* aux = mngtCredit->findCredit(id);
    if (aux != NULL) {
        cout <<  " Codigo        Valor del Credito   Saldo Restante     Termino de pago en Meses     Interes    Nª cuotas pagas    Total cuotas pagas    Total interes pagos" <<endl;
        cout << aux->toString()<<"           "<<aux->getContPays()<< "                  "<<aux->paysamount()<<"                "<<aux->paysinterts()<< endl;
    } else {
        cout << "El credito no existe" << endl;
    }
}

void pagar(){
    cout << "Ingrese el Codigo del Credito:" << endl;
    std::string id;
    cin>>id;
    Credit* aux = mngtCredit->findCredit(id);
    if(aux!=NULL){
    cout << "Ingrese el valor del pago:" << endl;
    double amount;
    cin>>amount;
    if(mngtCredit->doPay(id,amount)==true){
     if(aux->getCambio()>0){
     cout << "saldo restante"<<aux->getAmount()<< endl; 
     cout<<"Su cambio es de:"<<aux->getCambio()<< endl; 
        }else{
      cout <<" saldo restante: "<<aux->getAmount()<< endl;   
       }
    }else{
        cout << "El pago no se puede realizar " << endl; 
    }
    }else{
        cout << "El codigo no es compatible con ningun credito existente " << endl; 
    }
    
    cin.ignore();
}
void actualizar(){
    cout << "Ingrese el Codigo del Credito" << endl;
    std::string id;
    cin>>id;
    Credit* aux = mngtCredit->findCredit(id);
    if(aux!=NULL){
     cout << " Saldo Restante "<<aux->getAmount() << endl;
    }else{
       cout << "El codigo no es compatible con ningun credito existente" << endl; 
    }
    cin.ignore();
}

void listarCreditos(){
    cout << " Codigo        Valor del Credito   Saldo Restante     Termino de pago en Meses     Interes    Nª cuotas pagas    Total cuotas pagas    Total interes pagos" <<endl;
    vector<Credit> credits = mngtCredit->getCredits();
    for (Credit credit : credits) {
    cout << credit.toString() <<"           "<<credit.getContPays()<< "                  "<<credit.paysamount()<<"                "<<credit.paysinterts()<<endl;
    }
}

void verPagos(){
    cout << "Ingrese el Codigo del Credito: " << endl;
    std::string id;
    cin>>id;
    Credit* credit=mngtCredit->findCredit(id);
    if(credit!=NULL){
    vector<Pay> pays = credit->getPays();
    for (Pay pay : pays) {
        cout << pay.toString() << endl;
    }
    }else{
        cout << "El codigo no es compatible con ningun credito existente" << endl;
    }
    cin.ignore();
}

void calcInteres(){
    cout << "Ingrese el Id del Credito: " << endl;
    std::string id;
    cin>>id;
    Credit* credit=mngtCredit->findCredit(id);
    if(credit!=NULL){
      cout<<" El interes correspondiente al credito es: " <<endl;
     cout<<credit->calcInterest()<<endl;   
    }else{
      cout<<"El id ingresado no corresponde a ningun credito"<<endl;  
    }
    
    cin.ignore();
}

int main(int argc, char** argv) {
    mainMenu();
    return EXIT_SUCCESS;
}

void mainMenu() {
    string menu = "MENU PRINCIPAL DEL BANCO DAVIVIENDA\n"
                  "DE CARACTER CREDITICIO\n"
            "1.Adicionar Credito\n"
            "2.Consultar Credito\n"
            "3.Pagar Cuota\n"
            "4.Actualizar saldo\n"
            "5.Calcular interes\n"
            "6.Ver pagos\n"
            "7.Listar Creditos\n"
            "8.salir\n";
    char option;
    while (option != '8') {
        cout << menu;
        cin.get(option);
        cin.ignore();

        switch (option) {
            case '1':
                agregar();
                break;
            case '2': 
                buscar();
                break;
            case '3':
                pagar();
                break;
            case '4':actualizar();
                break;
            case '5':calcInteres();
                break;
            case '6':verPagos();
                break;
            case '7':listarCreditos();
                break;     
            default: 
                break;
        }
    }

}




