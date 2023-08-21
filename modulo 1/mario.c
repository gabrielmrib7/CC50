#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int tamanho, i = 0, h = 0, vazio = 0;
    do
    {
        tamanho = get_int("Tamanho de 1 a 8: \n"); //pede tamanho
    }
    while (tamanho <= 0 || tamanho > 8);

    for (h = 1; h <= tamanho; h++) //imprime a piramide
    {

        for (vazio = tamanho - h; vazio >= 1; vazio--) //adiciona espaço
        {
            printf(" ");
        }

        for (i = 1; i <= h; i++) //adiciona caracteres para largura
        {
            printf("#");
        }
        printf("  "); //espaço no meio

        for (i = 1; i <= h; i++) //adiciona caracteres da direita
        {
            printf("#");
        }


        printf("\n");
    }


}