#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2) //verificando se o usuario digitou apenas 2 argumentos na commandline
    {
        printf("\nUse: ./substitution key\n\n");
        return 1;
    }

    for (int a = 0, a2 = strlen(&argv[1][a]); a < a2; a++) // verificando se o usuario digitou numerais
    {
        if (isalpha(argv[1][a]) == 0)
        {
            printf("\nA Chave deve conter apenas digitos\n\n");
            return 1;
        }
        int b = 0;
        for (b = 0; b < a; b++) // verificando se há caracteres repetidos
        {
            if (tolower(argv[1][b]) == tolower(argv[1][a]))
            {
                printf("A Chave nao deve conter caracteres repetidos\n");
                return 1;
            }
        }
    }
    if (strlen(argv[1]) != 26) //verificando se há 26 caracteres
    {
        printf("A Chave deve conter 26 caracteres\n");
        return 1;
    }

    string text = get_string("texto simples: "); //recebendo o texto
    printf("\nciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++) //criptografando
    {
        if (islower(text[i]) != 0) // criptografando as minusculas e imprimindo
        {

            text[i] = (((text[i] - 97) % 26));
            char k = text[i];
            printf("%c", tolower(argv[1][(int)k]));

        }
        else if (isupper(text[i]) != 0)//maiusculas
        {

            text[i] = (((text[i] - 65) % 26));
            char k = text[i];
            printf("%c", toupper(argv[1][(int)k]));
        }
        else // especiais
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");
    return 0;
}
