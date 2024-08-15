/*
Considere:
- Chamada recursiva = 2ns * 979 = 1958ns
- Retorno de chamada recursiva = 1ns * 979 = 979ns
- Atribuição e soma = 0.5ns * (326) * 2 = 326
- Subtração = 0.3ns * (979-1) = 293,4
Total = 3556,4 ns
Calcule o tempo desse algoritmo para n=12
*/

int fib3(int n)
{
  if (n < 3)
  {
    return 1;
  }
  else
  {
    return fib3(n - 1) + fib3(n - 2) + fib3(n - 3);
  }
}

int main()
{
  fib3(12);
  return 0;
}
