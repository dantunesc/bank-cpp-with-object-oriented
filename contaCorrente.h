#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H
#include "contaBancaria.h"
#include "imprimivel.h"

class ContaCorrente : public ContaBancaria
{
public:
    ContaCorrente(int conta_numero_, double saldo_);

    void sacar(double valor);
    void depositar(double valor);

    //~ContaCorrente();
private:
    double taxaDeOperacao;

};

#endif
