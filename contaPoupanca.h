#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "contaBancaria.h"
#include "imprimivel.h"

class ContaPoupanca : public ContaBancaria 
{
public:
    ContaPoupanca(int numero_, double saldo_, double credito_=50);

    void sacar(double valor);
    void depositar(double valor);

private:
    double credito;
};

#endif