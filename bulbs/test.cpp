#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string message = get_string("Message: ");

int n = strlen(message);
  for (int i = 0; i < n; i++)
  {
    printf("%c\n", message[i]);
    while (message[i] > 0)
    {
      int m = message[i] % 2;
      message[i] = message[i] / 2;
      printf("%i", m);
    }
    printf("\n");
  }
}
