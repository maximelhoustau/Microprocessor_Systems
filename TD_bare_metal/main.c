int fibo(int n);

//Calcule les termes de l asuite de Fibonacci
int fibo(int n){
  int f0 = 0;
  int f1 = 1;
  for(int i=0, i<n, i++ ){
    f2 = f1 + f0;
    f0 = f1;
    f1 = f2;
  }
  return (f2)
}

int main() {
return fibo(8);
}
