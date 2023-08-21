#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int spaces = 0, frases = 0, n, i, words = 0;
    float l;

    string text = get_string("Digite o texto: ");

    for (i = 0, n = (strlen(text)); i <= n; i++) // contagem de letras, palavras e frases
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) // letras
        {
            words++;
        }
        if (text[i] == 32) //palavras
        {
            spaces++;

        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) // frases
        {
            frases++;

        }
    }
    spaces = spaces + 1; //correção de bugs
    printf("Numero de letras: %i\n",  words);
    printf("Numero de palavras: %i\n", spaces);
    printf("Numero de sentenças: %i\n", frases);
    l = ((0.0588 * (((float) words / spaces) * 100) - (0.296 * (((float) frases / spaces) * 100)) - 15.8)); // indice de coleman-liau
    if (l >= 16) //condições para mostrar o resultado
    {
        printf("\nGrade 16+\n");
    }
    else if (l < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else
    {
        printf("\nGrade %.0f\n", round(l));
    }


}
