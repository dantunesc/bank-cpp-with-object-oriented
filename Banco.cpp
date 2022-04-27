#include "Banco.h"
#include "contaBancaria.h"
#include <vector>
#include <iostream>
#include <algorithm>

Banco::Banco(){};

void Banco::inserir(ContaBancaria* nova_conta){
    contas_list.push_back(nova_conta);
}


void Banco::remover(ContaBancaria* conta){
    for(int i = 0; i < contas_list.size(); i++){
        if(contas_list[i] == conta){
          contas_list.erase(contas_list.begin() + i);
        }
    }
}


void Banco::mostrarDados() const{
    for(auto &s : this->contas_list){
        s->mostrarDados();
    }

}

ContaBancaria* Banco::procurarConta(int numero_conta){
    for (auto &s : this->contas_list)
    {
       if (s->getNumero() == numero_conta)
       {
           return s;
       }
       
    }
 
    return nullptr;
}

Banco::~Banco(){
    contas_list.clear();
}
