#include <stdio.h>

int main(void)
{
   char text[20];
   char *c = 0;

   printf("Please enter a text: ");
   c = gets(text);
   printf("Output: %s\n",text);
   printf("Return Value: %p\n",c);

   return 0;
}