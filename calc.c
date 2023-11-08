#include <stdio.h>
// #include <stdlib.h>

long power(long int a, long int b)
{
  long int iter_power = 1;
  long int is_negative_b;
  if (b == 0)
  {
    return 1;
  }
  if (a == 0)
  {
    return 0;
  }
  if (b > 0)
  {
    for (int i = 0; i < b; ++i)
    {
      iter_power *= a;
    }
  }
  return iter_power;
}
long isprime(long k)
{
  if (k <= 0 || k == 1 || (k % 2 == 0 && k != 2))
  {
    return 0;
  }
  else if (k == 2 || k == 3 || k == 5 || k == 7 || k == 11)
  {
    return 1;
  }
  for (int i = 3; i * i < k; i += 2)
  {
    if (k % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
int main()
{
  long int input1;
  long int input2;
  while (1)
  {
    printf("Welcome to the Calculator! Please make a choice:\n");
    printf("1 - Add.\n");
    printf("2 - Subtract.\n");
    printf("3 - Multiply.\n");
    printf("4 - Divide.\n");
    printf("5 - Power.\n");
    printf("6 - Check if prime.\n");
    printf("Input your choice:");

    char c = getchar();
    printf("Input your numbers, separated by one space:\n");
    printf("Your numbers:");
    if (scanf("%ld %ld", &input1, &input2) == 2)
    {
      printf("First number: %ld\n", input1);
      printf("Second number: %ld\n", input2);
    }
    else
    {
      printf("Failed to read integer.\n");
    }
    if (c == '1')
    {
      long int sum = input1 + input2;
      printf("%ld", sum);
    }
    else if (c == '2')
    {
      long int subtract = input1 - input2;
      printf("%ld", subtract);
    }
    else if (c == '3')
    {
      long int prod = input1 * input2;
      printf("%ld", prod);
    }
    else if (c == '4')
    {
      long div = input1 / input2;
      printf("%ld", div);
    }
    else if (c == '5')
    {
      long pow = power(input1, input2);
      printf("%ld", pow);
    }
    else if (c == '6')
    {
      printf("Is input1 prime: %ld\n", isprime(input1));
      printf("Is input2 prime: %ld\n", isprime(input2));
    }
  }

  return 0;
}