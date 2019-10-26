#ifndef robotME_INCLUDED //Define inicio e fim do arquivo
#define robotME_INCLUDED
#define PI 3.14159265
#include <math.h> 
#include <iomanip> //Biblioteca para o Alinhamento
#include <unistd.h> // Biblioteca para o comando sleep

//Alinhamento das informações na tela
using std::setw;
using std::left;
using std::right;
const auto TAX_WIDTH = 4;
const auto LABEL_WIDTH = 4;

class robotME{
  protected:
  float grau;
  float distancia;

  public:
  robotME(){
    distancia=0.0;
    grau = 90.0;
  }

  //destrutor
  ~robotME(){};

  void step(float iniciOx, float fimX, float inicioY, float fimY, float giro, int posicao, float **saida){
    proximoValor(iniciOx, fimX, inicioY, fimY, giro, posicao, saida);
  }

  void transduce(float* entradas,int tamanho,float **saidas){
    for(int i=0, j=0; i <=(tamanho/2)-2; i=i+2,j++){
        if((i+2)<=tamanho){
            step(entradas[i], entradas[2+i], entradas[1+i], entradas[3+i], grau, j, saidas);

        }else{
        	std::cout<<"fim"<<std::endl;
        }

    }
  }
  float Posicao(){
      //return (x,y);
      return 0;
  }

  virtual float proximoValor(float inicioX, float fimX, float inicioY, float fimY, float giro, int posicao, float **saida) {
    return 0;
  }
};


class Anda:public robotME{
protected:
    float distancia;
    float eixoX;
    float eixoY;
public:
    Anda(){
    }
    Anda(float distanciaI){
        distancia = distanciaI;
        eixoX=0.0;
        eixoY=0.0;
    }
    float proximoValor(float inicioX, float fimX, float inicioY, float fimY, float giro, int posicao, float **saida){
      //Definicao do vetor do angulo
      int v = (posicao);
      //definição da velocidade
      int timer; 
      std::cout << std::endl; // Separacao de linhas
        //Cabeçalho (Indo para o ponto ...)
        std::cout<<"Indo para o ponto "<<(posicao+1)<<std::endl;
        //distancia
        distancia = sqrt(pow((fimX-inicioX),2) + pow((fimY-inicioY),2));
        //Print do angulo
            std::cout << "Angulo: " << saida[(posicao)][0] << " graus" << std::endl;
            v++;
        for (int i=1, j=2, k=1; i<=20; i=i+2, j=j+2, k++){
            //Calculos para meidir a distancia em relacao ao eixo
            eixoX=((fimX-inicioX)/10)*(k)+inicioX;
            eixoY=((fimY-inicioY)/10)*(k)+inicioY;
            //Calculo para medir a distancia do objeto
            distancia = distancia - ((distancia/10)*k);
            //Atribuindo valores as variaveis
            saida[posicao][i] = eixoX;
            saida[posicao][j] = eixoY; 
            //Print de coordenadas e distancia
            std::cout << setw(20) <<"Movimento em X: "<< setw(TAX_WIDTH) << right << saida[posicao][i]  << "  |"<< setw(TAX_WIDTH-3) << std::right << setw(LABEL_WIDTH) << right <<"  Movimento em Y: "<<setw(TAX_WIDTH) << right <<saida[posicao][j]<< "  | "<< setw(LABEL_WIDTH-5) << right <<" Distância: "<< setw(TAX_WIDTH-2) << std::setprecision(3) << distancia << " metros" <<std::endl;
            //Poe um delay no print
            float velocidade = (distancia + 0.5);
            usleep(1000000/velocidade);
  
        }

        return distancia;
    }
};

class Giro:public robotME{
private:
    float atanX;
protected:
    float giroAtual;
public:
    Giro(){
        atanX = 0.0;
        giroAtual = 0.0;
    }
    float proximoValor(float inicioX, float fimX, float inicioY, float fimY, float giro, int posicao, float **saida){
        //Calcula o arco cujo a tangente vale z em relação ao ponto ordenado.
        atanX = (float)atan(sqrt(pow((fimY-inicioY),2))/sqrt(pow((fimX-inicioX),2))) * 180 / PI;

        if (posicao == 0){
            giroAtual = grau;
        }

        if (fimX == inicioX){
            if(fimY < inicioY){
                giroAtual = 180.0;
            }else{
                giroAtual = 0.0;
            }
        }

        if (fimY == inicioY){
            if(fimX > inicioX){
                giroAtual = 90.0;
            }else{
                giroAtual = -90.0;
            }
        }

        if(fimX > inicioX){
            if(fimY < inicioY){
                giroAtual = grau + atanX;
                grau = grau + giroAtual;
            }
            else{
                giroAtual = grau - (180.0 - atanX);
                grau = 90.0 + atanX;
            }
        }

        else{
            if (fimY < inicioY){
                giroAtual =  grau - (270.0 - atanX);
                grau = 180 - atanX;
            }
            else{
                giroAtual = grau - atanX;
                grau = atanX;
            }
        }

        saida[(posicao)][0] = giroAtual;
        return grau;
  }
};

class robot:public robotME{
private:
    robotME *gira;
    robotME *ando;
protected:
    float distancia;

public:
    robot(){
        gira = new Giro();
        ando = new Anda();
    };
    float proximoValor(float inicioX, float fimX, float inicioY, float fimY, float giro, int posicao, float **saida){
        gira->proximoValor(inicioX, fimX, inicioY, fimY, giro, posicao, saida);
        distancia = ando->proximoValor(inicioX, fimX, inicioY, fimY, giro, posicao, saida);
        return distancia;
    }

    void chegada(){
      std::cout << std::endl;
      std::cout<<"Você chegou ao seu destino!" << std::endl;
    }
};


#endif // ROBOT ME
