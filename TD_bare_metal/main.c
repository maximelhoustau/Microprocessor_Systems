
int fibo(int n);

//Calcule les termes de la suite de Fibonacci
int fib(int n){
  if (n < 2)
    return n;
  else
    return fib(n-1) + fib(n-2);
}

void init_bss();

int main() {
return fib(8);
}
