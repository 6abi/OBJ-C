//me.h
/*************************************************
****** Bárbara Cardoso - BEC 3º SEMESTRE - *******
**************************************************
*/

#include <iostream>
#include <unistd.h>
using namespace std;

class ME{
  protected:
  int estado;
  
  public:
  //inicializa o construtor
  ME(){
    estado=0;
  }
  //sobrecarga do construtor
  ME(int valor){
    estado=valor;
  }
  void step(int entrada, int posicao, int* saida){
    estado=proximoValor(entrada, posicao, saida);
  }
  void transduce(int* entradas,int tamanho,int *saidas){
    for(int i=0; i < tamanho; i++){
       step(entradas[i], i, &saidas[i]);
    }
  }
  void imprime(){
    cout<<"estado: "<<estado<<endl;
  }
  virtual int proximoValor(int entrada, int posicao, int* saida){
    return estado;
  }
  
  int getEstado(){
    return estado;
  }
};

class UpDown:public ME{
  public:
  UpDown(int valor){
    estado=valor;
  }

  int proximoValor(int entrada, int posicao, int* saida){
    if(entrada==1){
      estado=estado+1;
      *saida=estado;
    }
    else{
      estado=estado-1;
      *saida=estado;
    }
    return estado;
  }
};

//novas classes criadas

//class filha responsavel pelo delay
class Delay: public ME{
    public:
    Delay(int valor);
    int proximoValor(int entrada, int posicao, int* saida);
    void delay(int time){
      usleep(estado*time);
    }
};
//contrutor
Delay::Delay(int valor){
      estado=valor;
}

//armazena os proximos valores
int Delay::proximoValor(int entrada, int posicao, int* saida){
    *saida=estado;
    estado = entrada;
    return estado;
}
// class irá armazenar o valor anterior  + o novo
class Contador:public ME{
  public:
  Contador(int valor){
    estado=valor;
  }
  int proximoValor(int entrada, int posicao, int* saida);
};
// função responsavel pelo armazenamento de acordo com valor anterior + novo
int Contador::proximoValor(int entrada, int posicao, int* saida){
      
    estado=estado+entrada;
    *saida=estado;
    return estado;
}

// Criação class cascata

class cascata:public ME{
  private:
  ME *me1, *me2;

  public:
  cascata(ME *m1, ME *m2){
    me1=m1;
    me2=m2;
  }


  int proximoValor(int entrada, int posicao, int *saida){
    entrada = 0;
    posicao = 0;
    int temp;
    me1->proximoValor(entrada, posicao, &temp);
    me2->proximoValor(temp, posicao, saida);

    return *saida;
  }
};

class paraleloSoma:public ME{
  private:
  ME *me1, *me2;

  public:
  paraleloSoma(ME *m1, ME *m2){
    me1=m1;
    me2=m2;
  }

  int proximoValor(int entrada, int posicao, int *saida){
    int temp;
    me1->proximoValor(entrada, posicao, &temp);
    me2->proximoValor(entrada, posicao, saida);
    *saida=*saida+temp;

    return *saida;
  }
};




