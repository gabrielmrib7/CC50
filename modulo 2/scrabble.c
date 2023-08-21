#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
             // a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q   r  s  t  u  v  w  x  y  z

int compute_score(string word);

int main()
{
    // Get input words from both players
    string text1 = get_string("Player 1: ");
    string text2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(text1);
    int score2 = compute_score(text2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int compute_score(string text)
{
    int soma = 0, aux = 0;
    // TODO: Compute and return score for string

    for (int i = 0, n = strlen(text); i < n; i++) //somando
    {

        if (islower(text[i]) != 0) // soma das minusculas
        {

            text[i] = (((text[i] - 97) % 26));
            soma = ((POINTS[(int)text[i]] + aux));
            aux = soma;


        }
        else if (isupper(text[i]) != 0)//soma das maiusculas
        {

            text[i] = (((text[i] - 65) % 26));
            soma = ((POINTS[(int)text[i]] + aux));
            aux = soma;
        }
        else // especiais
        {


        }

    }


    return soma;
}