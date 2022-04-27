#include "contaBancaria.h"
#include "contaCorrente.h"
#include "imprimivel.h"

ContaCorrente::ContaCorrente(int numero, double saldo):
    ContaBancaria("CORRENTE", numero, saldo), taxaDeOperacao(1) {}


void ContaCorrente::sacar(double valor){
    if (this->saldo - valor - taxaDeOperacao >= 0){
        this->saldo -= valor + taxaDeOperacao;
    }

};

void ContaCorrente::depositar(double valor){
    if (valor > 0) {
        this->saldo += valor;
    }
    
};
