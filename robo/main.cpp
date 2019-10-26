#include <iostream>
#include "robotME.h" //Inclui a classe do robô
#include <malloc.h> //Inclui o memory allocation
#include "mainMenu.h" //Inclui a classe do menu

using namespace std;

int main(){
    //Intanciação de classes
    Menu menu;
    robot robotME;

    //Defina o numero de entradas e os pontos aqui:
    
    int tamanho=22; //Define o tamanho (Qtd de entradas)
    
    //Entradas (X,Y,X,Y....)
    float entradas[] = {2.5,2.5,3.0,2.0,8.5,5.0,2.3,11.0,1.0,1.0,5.2,3.0,7.2,7.0,9.0,5.0,2.0,5.2,8.0,1.0,5.0,3.0};

    //------------------------------------------------

    float **saida; //(Cria uma variavel saida apontando para o endereço do ponteiro)
    //Alocação dinamica da array saida baseada no tamanho
    saida = new float*[tamanho];
    //saida=(float **)malloc((tamanho-2)*sizeof(float*));
    for(int i=0; i<((tamanho/2)+2); i++){
        saida[i]=(float*)malloc((tamanho-2)*sizeof(float));
    };

    //Menu principal
    while(!menu.getSair()){
      menu.main();

      switch(menu.getOpcao()){
        case 1:
          cout << "\x1B[2J\x1B[H"; //Limpa a tela
          //Executa a maquina
          robotME.transduce(entradas,tamanho,saida); 
          robotME.chegada();
          //Finaliza
          return 0;
      }
    }

    //Saída do programa
    cout << "Até logo!" << endl;
    return 0;

}
