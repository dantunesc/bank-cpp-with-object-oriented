#include "contaCorrente.h"
#include "contaPoupanca.h"
#include "Relatorio.h"
#include "Executavel.h"

Executavel::Executavel(){}

void Executavel::executando(){
    ContaCorrente conta1(123, 0);
    conta1.depositar(100);
    conta1.sacar(50);

    ContaPoupanca conta2(321, 0);
    conta2.depositar(50);
    conta2.sacar(120);

    Relatorio relatorio;
    relatorio.gerarRelatorio(conta1);
    relatorio.gerarRelatorio(conta2);
}
