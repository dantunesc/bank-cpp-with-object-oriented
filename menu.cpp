#include <iostream>
#include <memory>
#include <windows.h>
#include "menu.h"
#include "contaCorrente.h"
#include "contaPoupanca.h"
#include "Banco.h"
#include "Relatorio.h"


Menu::Menu(){
  Banco banco;
}

void Menu::mostrarMenu(){
  system("cls");
  int escolha = 0;
  while(escolha != 5){
    system("cls");
		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 261);
		std::cout << "((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((" << std::endl;
		std::cout << "(           ((((((((((     ((((((((    (((((((((  /(((((          ((((((((           (((((((((((((((((((((((((((((((((((" << std::endl;
		std::cout << "(  ((((((((  ((((((((   (  ((((((((      (((((((  /(((   ((((((((    ((((  (((((((((   (((((((((  (((((((((((((  (((((((" << std::endl;
		std::cout << "(  ((((((    ((((((    (((  (((((((   (    (((((  /(((   (((((((((((((((   (((((((((   (((((((((  (((((((((((((  (((((((" << std::endl;
		std::cout << "(          ((((((((   (((((  ((((((   (((   ((((  /(((   (((((((((((((((   ((((((((((   ((             (((             (" << std::endl;
		std::cout << "(  ((((((((  (((((   ((((((   (((((   (((((   ((  /(((   (((((((((((((((   ((((((((((   ((((((((  (((((((((((((  (((((((" << std::endl;
		std::cout << "(  ((((((((   (((   ((((((((   ((((   (((((((     /((((   ((((((((   (((    (((((((    (((((((((  (((((((((((((  (((((((" << std::endl;
		std::cout << "(            (((  (((((((((((   (((   ((((((((    /(((((            ((((((           (((((((((((  (((((((((((((  (((((((" << std::endl;
		std::cout << "((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((" << std::endl;
		SetConsoleTextAttribute(h, 262);
		    std::cout << "MENU - Escolha a opcao que desejar: " << std::endl;
		    std::cout << "1 - CRIAR UMA CONTA" << std::endl;
		    std::cout << "2 - ENTRAR EM UMA CONTA" << std::endl;
		    std::cout << "3 - EXCLUIR CONTA" << std::endl;
		    std::cout << "4 - GERAR RELATORIO" << std::endl;
		    std::cout << "5 - ENCERRAR" << std::endl;
		    std::cin >> escolha;
			
		while((escolha < 6) || (escolha > 0)){
			if(escolha==1)                            
			{
				menu_criarConta();          //criando conta
				break;
			}
			else{
				if(escolha==2){
					menu_selecionarConta();      //selecionando conta
					break;
				}
				else{
					if(escolha==3)				
					{	
						removerConta();				//apagando conta
						break;
					}
					else{
						if(escolha==4)
						{
							banco.mostrarDados();                //mostrando os dados
		        			std::cin.ignore();std::cin.ignore();
		        			break;
						}
						else{
							if(escolha==5){
								break;
							}
							else{
								std::cout<< "Erro. Por favor, insira um valor valido."<<std::endl;
								continue;                  //retornando ao menu
							}
						}
					}
				}
			}
		}
	
   
  	}
}



ContaBancaria* Menu::criarConta(int tipo, int numero, double saldo){
  ContaBancaria* p_novaConta;
  if(banco.procurarConta(numero)){
    return nullptr;
  } else {
    if (tipo == 1){
      p_novaConta = new ContaCorrente(numero, saldo);
    } else if (tipo == 2){
      p_novaConta = new ContaPoupanca(numero, saldo);
    }
  }
  banco.inserir(p_novaConta);
  return p_novaConta;
}

void Menu::menu_criarConta(){
  system("cls");
  int modelo;
  int numero;
  double saldo;
  ContaBancaria* p_novaConta;
  ContaBancaria* p_contaExistente;
  do{
    system("cls");
    std::cout << std::endl;
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    std::cout << " Criando uma conta no Banco++" << std::endl;
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    while(true){
      std::cout << "Escolha o modelo de conta que quer criar:" << std::endl;
      std::cout << "1 - CONTA CORRENTE" << std::endl;
      std::cout << "2 - CONTA POUPANCA" << std::endl;
      std::cout << "3 - RETORNAR" << std::endl;
      std::cin >> modelo;
      if(modelo >= 1 || modelo <= 3){
        break;
      } else {
        std::cout << "Erro. Por favor, insira uma opcao valida" << std::endl;                 //para cso o usuario tenha digitado opcao invalida
      }
    }
    if(modelo == 3) break;
    do{
      std::cout << "Digite o numero da conta:  ";
      std::cin >> numero;
      p_contaExistente = banco.procurarConta(numero);            
      if(p_contaExistente){                         //verificando se a conta existe
        std::cout << "Erro. Este numero de conta ja esta em utilizacao, digite novamente." << std::endl;
      }
    } while(p_contaExistente);
    do{
      std::cout << "Digite o valor do saldo da conta: ";
      std::cin >> saldo;
      if(saldo >= 0) break;  
      std::cout << "Erro. Valor inserido invalido, tente novamente" << std::endl;               //caso o valor digitado tenha sido negativo
    }while(saldo < 0);              
    p_novaConta = criarConta(modelo, numero, saldo);  //inserio o valor na conta com tal numero e tal modelo
    if(p_novaConta){
      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cout << "| conta " << p_novaConta->getTipo() << " #" << p_novaConta->getNumero() << " criada no Banco++" << std::endl;
      std::cout << " numero_de_contas++" << std::endl;
      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cin.ignore();std::cin.ignore();
    } else {
      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cout << "| " << "Falha em criar uma conta no Banco++, tente novamente." << std::endl;
      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cin.ignore();std::cin.ignore();
    }
  }while(!p_novaConta);
}

void Menu::menu_selecionarConta(){
  int numero;
  ContaBancaria* p_contaSelecionada;
  std::cout << std::endl;
  std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
  std::cout << " Escolha uma conta do Banco++ " << std::endl;
  std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
  do{
    std::cout << "Digite o numero da conta: " << std::endl;
    std::cin >> numero;
    p_contaSelecionada = banco.procurarConta(numero);     //para verificar se a conta selecionada existe
    if(!p_contaSelecionada){
      std::cout << "Erro. Conta nao encontrada, digite novamente." << std::endl;
      std::cout << std::endl;
    }
  }while(!p_contaSelecionada);

  menu_contaSelecionada(p_contaSelecionada);
}

void Menu::menu_contaSelecionada(ContaBancaria* p_contaSelecionada){
  double valor;
  int operacao = 0;
  int numero_destino;
  ContaBancaria* p_contaDestino;
  Relatorio relatorio;
  while(operacao != 5){
    system("cls");
    std::cout << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << p_contaSelecionada->getTipo() << ", numero " << p_contaSelecionada->getNumero() << " do Banco++ selecionado." << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Escolha a operacao que desejar: " << std::endl;
    std::cout << "1 - DEPOSITO" << std::endl;
    std::cout << "2 - SAQUE" << std::endl;
    std::cout << "3 - TRANSFERENCIA" << std::endl;
    std::cout << "4 - CRIAR RELATORIO" << std::endl;
    std::cout << "5 - VOLTAR" << std::endl;
    std::cin >> operacao;
    
    
    while((operacao < 6) || (operacao > 0)){
			if(operacao==1)                             //operacao de deposito
			{
				std::cout << std::endl;
		        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		        std::cout << "| Deposito " << p_contaSelecionada->getTipo() << ", numero " << p_contaSelecionada->getNumero() << std::endl;
		        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		        std::cout << "Insira um valor a ser depositado: ";
		        do{
		          std::cin >> valor;
		          if(valor < 0){                //para sacar só valores positivos
		            std::cout << std::endl;
		            std::cout << "Erro. Digite um valor valido" << std::endl;
		            std::cout << std::endl;           
		          }
		        }while(valor < 0);
		        p_contaSelecionada->depositar(valor);
		        std::cout << "R$ " << valor << " foi depositado em " << p_contaSelecionada->getTipo() <<  ", numero " << p_contaSelecionada->getNumero() << std::endl;
		        std::cin.ignore();std::cin.ignore();
		        break;
			}
			else{
				if(operacao==2){                      //operacao de saque
					std::cout << std::endl;
			        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
			        std::cout << "Saque em " << p_contaSelecionada->getTipo() << " # " << p_contaSelecionada->getNumero() << std::endl;
			        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
			        std::cout << "Digite o valor do saque: ";
			        do{
			          std::cin >> valor;
			          if(valor < 0){
			            std::cout << std::endl;
			            std::cout << "Erro. Digite um valor valido" << std::endl;
			          }
			        }while(valor < 0);
			        p_contaSelecionada->sacar(valor);
			        break;
				}
				else{
					if(operacao==3)				 //operacao de transferencia
					{	
						std::cout << std::endl;
				        std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
				        std::cout << " Transferindo valores no Banco++" << p_contaSelecionada->getNumero() << std::endl;
				        std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
				        do{
				          if(valor < 0){
				            std::cout << "Insira o valor a ser transferido: ";
				            std::cin >> valor;
				            std::cout << std::endl;
				            std::cout << "Erro. Insira um valor valido" << std::endl;
				          }
				        }while(valor < 0);
				        do{
				          std::cout << "Insira o numero da conta a receber a transferencia: ";
				          std:: cin >> numero_destino;
				          p_contaDestino = banco.procurarConta(numero_destino);
				
				          if(!p_contaDestino){
				            std::cout << std::endl;
				            std::cout << "Erro. Conta nao encontrada, digite novamete" << std::endl;
				          }
				        }while(!p_contaDestino);
				        p_contaSelecionada->transferir(p_contaDestino, valor);
				        break;
					}
					else{
						if(operacao==4)               //operacao para criar um relatorio
						{
							std::cout << std::endl;
					        relatorio.gerarRelatorio(*p_contaSelecionada);
					        std::cin.ignore();std::cin.ignore();
					        break;
						}
						else{
							if(operacao==5){          //voltar ao menu
								break;
							}
							else{
								operacao = 0;
       							break;            
							}
						}
					}
				}
			}
		}

	
  }
}

bool Menu::removerConta(){
  system("cls");
  int numero;
  ContaBancaria *p_conta;
  std::cout << std::endl;
  std::cout << "+++++++++++++++++++++++" << std::endl;
  std::cout << " Apagar conta bancaria" << std::endl;
  std::cout << "+++++++++++++++++++++++" << std::endl;
  do{
    std::cout << "Insira o numero da conta: " << std::endl;
    std::cin >> numero;
    p_conta = banco.procurarConta(numero);  //para verificar se a conta existe
    if(!p_conta){
      std::cout << std::endl;
      std::cout << "Erro. A conta nao foi encontrada, insira novamente.";
    }
  }while(!p_conta);
  std::cout << " RIP conta. " << p_conta->getNumero() << " :'( "<< std::endl;
  std::cout << " Foi um prazer fornecer nossos servicos a voce" << std::endl; 
  banco.remover(p_conta);       //removendo a conta
  std::cout << " numero_de_contas--" << std::endl;
  std::cin.ignore();std::cin.ignore();
  return true;
}


