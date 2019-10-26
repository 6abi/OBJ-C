#include "me.h"


int main() {
	
  cancela portao;
	int tamanho = 10;
	int entradas[] = {1, 1, 1, 0, 0, 1, 0, 1, 1, 0 };
	int saidas[tamanho];
  
  portao.transduce(entradas, tamanho, saidas);
  
  for (int i = 0; i < tamanho; i++) {
		cout << "entrada = "<<entradas[i]<<" saida = "<< saidas[i] << endl;
	}
	cout << endl;
  
  return 0;
}