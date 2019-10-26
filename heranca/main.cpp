#include <iostream> 

using namespace std;

class ponto{
  protected:
     float x,y;
  
  public:
  ponto(){
    x=y=0.0;
  }
  
  ponto(float dx, float dy){
    x=dx;
    y=dy;
  }
  
  void setX(float dx){
    x=dx;
  }
  
  void setY(float dy){
    y=dy;
  }
  
  void setXY(float dx, float dy){
    setX(dx);
    setY(dy);
  }
  
  void deslocaX(float dx){
    x+=dx;
  }
  
  void deslocaY(float dy){
    y+=dy;
  }
  
  void deslocaXY(float dx, float dy){
    deslocaX(dx);
    deslocaY(dy);
  }
  
  void imprime(){
    cout<<"X = "<<x<<" Y = "<<y<<endl;
  }
};

class circulo:public ponto{
  private:
    float raio;
    const float PI=3.1415926;
    
    bool testaPosicao(float dx, float dy){
      int flag=0;
      if(((x+dx)>-100.0)&&((x+dx)<100)){
        flag=1;
      }
      if(((y+dy)>-100)&&((y+dy)<100)){
        return 1*flag;
      }
      return 0;
    }
  
  public:
  circulo(){
    raio=1.0;
  }
  
  circulo(float r){
    if(r>0){
       raio=r;
    }
  }
  
  circulo(float x1, float y1):ponto(x1,y1){
    raio=1.0;
  }
  
  void alteraRaio(float r){
    raio=r;
  }
  
  void move(float dx, float dy){
    if(testaPosicao(dx,dy)){
      ponto::deslocaXY(dx,dy);
    }
    else{
      cout<<"Erro - mudanca nao permitida."<<endl;
    }
  }
  
  void mostra(){
    cout<<"Circulo"<<endl;
    cout<<"Raio = "<< raio<<endl;
    cout<<"Posicao -> ";
    ponto::imprime();
  }
  
  float area(){
    float a=PI*raio*raio;
    cout<<"Area = "<<a<<endl;
    return a;
  }
  
  float perimetro(){
    float p=2*PI*raio;
    cout<<"Perimetro = "<<p<<endl;
    return p;
  }
};

class quadrado:public ponto{
  private:
     float lado;
     
     bool testaPosicao(float dx, float dy){
      int flag=0;
      if(((x+dx)>-150.0)&&((x+dx)<150)){
        flag=1;
      }
      if(((y+dy)>-150)&&((y+dy)<150)){
        return 1*flag;
      }
      return 0;
    }
  
  public:
  quadrado(){
    lado=1.0;
  }
  
  quadrado(float q){
    if(q>0){
      lado=q;
    }
  }
  
  quadrado(float x1, float y1):ponto(x1,y1){
    lado=1.0;
  }
  
  void alteraLado(float l){
    lado=l;
  }
  
  void move(float dx, float dy){
    if(testaPosicao(dx,dy)){
      ponto::deslocaXY(dx,dy);
    }
    else{
      cout<<"Erro - mudança nao permitida."<<endl;
    }
  }
  
  void mostra(){
    cout<<"Quadrado"<<endl;
    cout<<"Lado = "<< lado<<endl;
    cout<<"Posicao -> ";
    ponto::imprime();
  }
  
  float area(){
    float a=lado*lado;
    cout<<"Area = "<<a<<endl;
    return a;
  }
  
  float perimetro(){
    float p=4*lado;
    cout<<"Perimetro = "<<p<<endl;
    return p;
  }
};

int main(){
  circulo c1;
  circulo c2(10);
  quadrado q1;
  quadrado q2(50.0, 50.0);
  
  c1.mostra();
  
  c1.move(2.5, 5.2);
  
  c1.mostra();
  c2.mostra();
  
  q1.mostra();
  
  q1.move(-5.0, +10.0);
  
  q1.mostra();
  
  q2.mostra();
  q2.move(200.0, 100.0);
  q2.mostra();
  
  c1.area();
  q1.perimetro();
}