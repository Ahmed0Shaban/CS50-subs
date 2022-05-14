#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// POINTS count from 0 to 25 (26 letters)


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int n = strlen(word1);
    int m = strlen(word2);

// make letters of word1 lowercase
    for (int i = 0; i < n; i++)
    {
        if isupper(word1[i])
        {
            word1[i] = word1[i] + 32;
        }
    }
// make letters of word2 lowercase
    for (int x = 0; x < m; x++)
    {
        if isupper(word2[x])
        {
            word2[x] = word2[x] + 32;
        }
    }


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function that computes score of each player -aka- word
int compute_score(string word)
{
    // TODO: Compute and return score for string
    // example word: Moon
    int score = 0;
    int letterCounter = strlen(word);
    // letterCounter = 4, i = 0, 1, 2, 3
    for (int i = 0; i < letterCounter; i++)
    {
        if ((int) word[i] >= 97 && (int) word[i] <= 122)
        {
            score = score + POINTS[(int) word[i] - 97];
        }
    }
    // for every letter in the word
    // get its value number from points
    // Then, add it to score
    return score;

}
