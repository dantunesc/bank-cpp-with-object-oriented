#ifndef BANCO_H
#define BANCO_H
#include <vector>
#include "contaBancaria.h"
#include "imprimivel.h"

class Banco
{
public:
    Banco();

    void inserir(ContaBancaria* nova_conta);
    void remover(ContaBancaria* conta);
    void mostrarDados() const;

    ContaBancaria* procurarConta(int numero_conta);

    ~Banco();

private:
    std::vector <ContaBancaria*> contas_list;
};

#endif
