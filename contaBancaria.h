#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <iostream>
#include <string>
#include "imprimivel.h"

class ContaBancaria : public Imprimivel
{
public:
    ContaBancaria(std::string tipo_, int conta_numero_, double saldo_);
    
    virtual void sacar(double valor);
    virtual void depositar(double valor);
    virtual void mostrarDados() const;

    virtual int getNumero() const;
	std::string getTipo() const;
    virtual void transferir(ContaBancaria* conta_destino, double valor);

    //~ContaBancaria();
protected:
    std::string tipo;
    int conta_numero;
    double saldo;


};

#endif
