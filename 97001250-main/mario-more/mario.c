#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // Prompting User to input Pyramid Height
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
// Prints the left half with proper spaces
        printf("%.*s", (n - i), "        ");
        printf("%.*s", i, "########");
// The Gap
        printf("  ");
// prints the right half
        printf("%.*s", i, "########");
        printf("\n");
    }

}