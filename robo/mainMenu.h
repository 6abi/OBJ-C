#ifndef mainMenu_INCLUDED // Define inicio e fim do arquivo
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Menu {
  private:
  int opcao;

//variaveis de controle
  bool sair = false;
  bool voltar = false;

  public:
  void limpar() {
    cout << "\x1B[2J\x1B[H";
  }
//função chamada quando a opção for != de 1 ou != de 2
  void invalidar() {
    limpar();
    cout << "Opção inválida! "<< endl;
    cout << "" << endl;
  }

  void exit() {
    limpar();
    cout << "Você saiu do programa!" << endl;
  }

  bool getSair() {
    limpar();
    return sair;
  }

  int getOpcao() {
    return opcao;
  }

  void main() {
    opcao = 0;
    
    while (opcao < 1 || opcao > 2) {
      cout<<"===============================================" << endl;
      cout<<"             ROBÔ - MAQUINA DE ESTADO          " << endl;
      cout<<"                                               " << endl;
      cout<<"  Escolha uma opção:                           " << endl;
      cout<<"                                               " << endl;
      cout<<"                                               " << endl;
      cout<<"                                               " << endl;
      cout<<"            (1) - Executar                     " << endl;
      cout<<"            (2) - Sair                         " << endl;
      cout<<"                                               " << endl;
      cout<<"                                               " << endl;
      cout<<"               Desenvolvido por:               " << endl;
      cout<<"                Barbara Cardoso                " << endl;
      cout<<"           Vinicius Lima Fernandes             " << endl;
      cout<<"                                               " << endl;
      cout<<"               POO - 3º Periodo                " << endl;
      cout<<"===============================================" << endl;
      cout << "" << endl;

      cin >> opcao;

      if (opcao == 2) {
        sair = true;
      }
    
      if (opcao < 1 || opcao > 2) {
        invalidar();
      }
    }
  }

};

#endif