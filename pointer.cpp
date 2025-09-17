#include <iostream>
using namespace std;

void suma(int n){
  n++;
  cout<<n<<endl;
}


int main() {
  int k=10;
  //PtrK almacena la direccion de K
  int* PtrK=&k;
  
  cout<<"Valor de k: "<<k<<endl;
  cout<<"Direccion de K: "<<PtrK<<endl;
  cout<<"Valor de k por puntero: "<<*PtrK<<endl;

  //Por lo tanto, De referencia de K será igual a K
  //*PtrK==K
  //Mediante *PtrK podremos modificar el valor de K
  
  *PtrK=105;
  cout<<"Nuevo valor de K por su referencia: "<<*PtrK<<endl;
  cout<<"Nuevo valor de K: "<<k<<endl;

  //Puntero doble
  //P almacena la direccion del puntero
  
  int** P=&PtrK;
  cout<<"Direccion del puntero: "<<P<<endl;

  //referencia de k
  int& R=k;
  suma(k);
  suma(*PtrK);
  suma(R);

  
  return 0;
}
