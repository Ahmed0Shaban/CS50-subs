#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
string input = get_string("enter the ciphertext: ");

int n = strlen(input);

string output = input;

for (int i = 0; i < n; i++)
{
    if ((input[i] >= 'a' && input[i] <= 'z' ) || ( input[i] >= 'A' && input[i] <= 'Z') )

output[i] = input[i] - 1;
}
printf("Message: %s \n",output);
}


