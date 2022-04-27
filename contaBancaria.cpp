#include "contaBancaria.h"
#include <iostream>
#include <string>

ContaBancaria::ContaBancaria(std::string tipo_, int conta_numero_, double saldo_){
    this->tipo = tipo_;
    this->conta_numero = conta_numero_;
    this->saldo = saldo_;
}

void ContaBancaria::sacar(double valor){
    if(this->saldo - valor >= 0 && valor > 0){
        this->saldo -= valor;
    }
}

void ContaBancaria::depositar(double valor){
    if(valor > 0){
        this->saldo += valor;
    }
}

void ContaBancaria::transferir(ContaBancaria* conta_destino, double valor){
    if(valor > 0){
        this->sacar(valor);
        conta_destino->depositar(valor);
    }
}

std::string ContaBancaria::getTipo() const{
  return tipo;
}

int ContaBancaria::getNumero() const{
    return this->conta_numero;
}

void ContaBancaria::mostrarDados() const{
  std::cout << std::endl;
  std::cout << "==============================================================" << std::endl;
  std::cout << "| CONTA: " << getTipo() << std::endl;
  std::cout << "| NUMERO: " << this->conta_numero << std::endl;
  std::cout << "| SALDO: R$ " << this->saldo << std::endl;
  std::cout << "==============================================================" << std::endl;
  std::cout << std::endl;
}
