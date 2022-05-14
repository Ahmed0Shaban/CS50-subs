#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// func that ckecks if s is a string
bool isString(string s);

int main(int counter, string list[])

{

// exit if input isn't 2 args only (./caesar and key)
    if (counter != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

// converts key to an int
    int key = atoi(list[1]);

    while (key >= 26)
    {
        key = key - 26;
    }

// checking if key is a string
    bool word = isString(list[1]);

// exit if key is a string or a negative number
    if (word == true || key < 0)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

// Get the text to cipher ...
    string input = get_string("plaintext:  ");

// Getting number of input chars (we will iterate n times through this array of chars)
    int n = strlen(input);

    for (int i = 0; i < n; i++)
    {
        // rotate alphabetical chars only - lowercases
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            if (input[i] + key > 'z')
            {
                input[i] = input[i] + key - 26;
            }
            else
            {
                input[i] = input[i] + key;
            }
        }

        // rotate alphabetical chars only - uppercases
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            if (input[i] + key > 'Z')
            {
                input[i] = input[i] + key - 26;
            }
            else
            {
                input[i] = input[i] + key;
            }
        }

    }

// print the ciphered text
    printf("ciphertext: %s\n", input);

    return 0;

}

// func that ckecks if s is a string
bool isString(string s)
{
    bool word;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(s[i]) == false)
        {
            word = true;
        }
        else
        {
            word = false;
        }

    }
    return word;
}

