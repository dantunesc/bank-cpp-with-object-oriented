#include "contaBancaria.h"
#include "contaPoupanca.h"
#include "imprimivel.h"

ContaPoupanca::ContaPoupanca(int numero, double saldo, double credito_):
    ContaBancaria("POUPANCA", numero, saldo), credito(credito_) {}


void ContaPoupanca::sacar(double valor){
    if (this->saldo - valor >= -this->credito){
        this->saldo -= valor;
    }

};

void ContaPoupanca::depositar(double valor){
    if (valor > 0) {
        this->saldo += valor;
    }
    
};