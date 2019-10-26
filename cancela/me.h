#include <iostream>
using namespace std;

class ME{
  protected:
  int estado;
  
  public:
  ME(){
    estado=0;
  }
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

class cancela:public ME{
  //0 = fechada, 1= aberta, 2=abrindo, 3=fechando
  int proximoValor(int entrada, int posicao, int* saida){
    if (((estado==0)||(estado==3))&&(entrada==1)){
      *saida=2;
    }
    else if(((estado==1)||(estado==2))&&(entrada==0)){
      *saida=3;
    }
    else if((estado==2)&&(entrada==1)){
      *saida=1;
    }
    else if((estado==3)&&(entrada==0)){
      *saida=0;
    }
    else{
      *saida=estado;
    }
    
    return *saida;
  }
};
