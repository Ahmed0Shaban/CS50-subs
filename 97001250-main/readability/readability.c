#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{

    string text = get_string("Text: ");


    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // avr num of letters per 100 words
    float l_avr = ((float)100 * (float)letters) / (float)words;

    // avr num of sentences per 100 words
    float s_avr = ((float)100 * (float)sentences) / (float)words;

    // Coleman-Liau index
    int grade = (int) round(0.0588 * (float)l_avr - 0.296 * (float)s_avr - 15.8);



// print grade indicated
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %d\n", grade);
    }


// out of range grades
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }


}

// func that count letters in the input text
int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters ++;
        }

    }
    return letters;
}

// func that count words
int count_words(string text)
{
    int n = strlen(text);
    int words = 1;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            words ++;
        }
    }
    return words;
}

// func that count sentences
int count_sentences(string text)
{
    int n = strlen(text);
    int sentences = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 63 || text[i] == 33 || text[i] == 46)
        {
            sentences ++;
        }
    }
    return sentences;
}