#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int num1, num2, born = 0, n2 = 0, dead = 0, y = 0, aux = 0, aux2, aux3, aux4;

    do
    {
        num1 = get_int("Numero inicial de lhamas:"); // TODO: Solicite o valor inicial ao usuário
    }
    while (num1 < 9);
    do
    {
        num2 = get_int("Numero final de lhamas:"); // TODO: Solicite o valor final ao usuário
    }
    while (num2 < num1);

    if (num1 != num2)
    {
        do
        {
            aux = num1;
            aux2 = num1;
            aux4 = num1;
            born = (aux4 / 3);
            dead = (aux / 4);
            n2 = (aux2 + (born - dead));
            aux3 = n2;
            y++; // TODO: Calcule o número de anos até o limite
            n2 = aux3;
            num1 = n2;

        }
        while (n2 < num2);
    }


    printf("Years: %i\n", y); // TODO: Imprima o número de anos

}