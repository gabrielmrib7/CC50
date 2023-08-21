#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //verificando se o usuario digitou apenas 2 argumentos na commandline
    {
        printf("\nUse: ./caesar key\n\n");
        return 1;
    }

    for (int a = 0, a2 = strlen(&argv[1][a]); a < a2; a++) // verificando se o usuario digitou numerais
    {
        if (isalpha(argv[1][a]) != 0)
        {
            printf("\nUse: ./caesar key\n\n");
            return 1;
        }
    }


    int k = atoi(argv[1]);
    string text = get_string("plaintext: "); // recebendo o texto
    printf("\n");
    for (int i = 0, n = (strlen(text)); i < n; i++) //criptografando
    {
        if (islower(text[i]) != 0) // criptografando as minusculas
        {
            text[i] = (((text[i] - 97 + k) % 26) + 97);
        }
        else if (isupper(text[i]) != 0)
        {
            text[i] = (((text[i] - 65 + k) % 26) + 65); //maiusculas

        }

        else if (isalpha(text[i]) != 0) // caracteres especiais
        {
            text[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", text); //imprimindo a criptografia
    return 0;
}
