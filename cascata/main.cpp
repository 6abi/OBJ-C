/*************************************************
****** Bárbara Cardoso - BEC 3º SEMESTRE - *******
**************************************************
*/

#include "me.h"
using namespace std;
#include <iostream>



int main() {
	// Maquinas de estado simples

  Contador ct(0); // incializando a contagem em zero
  Delay dl(0);
   cascata csct(&ct, &dl);
   paraleloSoma pl(&dl, &ct);
  
	int tamanho = 10;
	int entradas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -45};
	int saidas[tamanho];
  int i;


  ct.transduce(entradas, tamanho, saidas);
  cout << "===============Contador==================" << endl;
  for (i = 0; i < tamanho; i++) {
		cout << "entrada = "<<entradas[i]<<" saida = "<< saidas[i] << endl;
	}
  cout << endl;

  dl.transduce(entradas, tamanho, saidas);
  cout << "===============Delay==================" << endl;
  for (i = 0; i < tamanho-1; i++) {
		cout << "entrada = "<<entradas[i]<<" saida = "<< saidas[i] << endl;
	}
  //d.delay(2);
  cout << "entrada = "<<entradas[i-1]<<" saida = "<< saidas[i-1] << endl;
	cout << endl;

  csct.transduce(entradas, tamanho, saidas);
  cout << "===============Cascata==================" << endl;
  for (int i = 0; i < tamanho; i++) {
		cout << "entrada = "<<entradas[i]<<" saida = "<< saidas[i] << endl;
	}
	cout << endl;

  pl.transduce(entradas, tamanho, saidas);
  cout << "===============ParaleloSoma==================" << endl;
  for (int i = 0; i < tamanho; i++) {
		cout << "entrada = "<<entradas[i]<<" saida = "<< saidas[i] << endl;
	}
	cout << endl;


}