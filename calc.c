#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char *input = NULL; // Pointer to dynamically allocated memory
  size_t input_size = 0;

  long int input1;
  long int input2;
  printf("Welcome to the Calculator! Please make a choice:\n");
  while (1)
  {
    printf("1 - Add.\n");
    printf("2 - Subtract.\n");
    printf("3 - Multiply.\n");
    printf("4 - Divide.\n");
    printf("5 - Power.\n");
    printf("6 - Check if prime.\n");
    printf("7 - Exit.\n");
    printf("Input your choice:");

    char c = getchar();
    while (getchar() != '\n')
    {
    };
    if (c == '7')
    {
      exit(0);
    }

    if (c >= '1' && c <= '6')
    {

      printf("Input your numbers, separated by one space:\n");
      if (getline(&input, &input_size, stdin) == -1)
      {
        break;
      }

      size_t len = strlen(input);
      if (len > 0 && input[len - 1] == '\n')
      {
        input[len - 1] = '\0';
      }
      if (sscanf(input, "%ld %ld", &input1, &input2) == 2)
      {
        printf("Input: %ld and %ld\n", input1, input2);
      }
      else
      {
        printf("Invalid input. Please enter two integers separated by a space.\n");
      }

      if (c == '1')
      {
        long int sum = input1 + input2;
        printf("%ld\n", sum);
      }
      else if (c == '2')
      {
        long int subtract = input1 - input2;
        printf("%ld\n", subtract);
      }
      else if (c == '3')
      {
        long int prod = input1 * input2;
        printf("%ld\n", prod);
      }
      else if (c == '4')
      {
        if (input2 == 0)
        {
          printf("Cannot divide by 0");
        }
        else
        {

          long div = input1 / input2;
          printf("%ld\n", div);
        }
      }
      else if (c == '5')
      {
        long pow = power(input1, input2);
        printf("%ld\n", pow);
      }
      else if (c == '6')
      {
        printf("Is input1 prime: %ld\n", isprime(input1));
        printf("Is input2 prime: %ld\n", isprime(input2));
      }
    }
    else
    {
      printf("This is not a valid choice. Please make another choice.\n");
      continue;
    }
  }
  free(input);
  return 0;
}