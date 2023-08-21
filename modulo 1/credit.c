#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char str[19], str2[19];
    long int num2 = 0, num3, result1 = 0, aux, aux2, result2 = 0, endresult = 0;
    long int num = get_long("Numero do cartão (apenas numeros)? \n");

    aux2 = num;
    do
    {
        // soma dos segundos digitos
        aux = result1;
        num2 = (num % 10);
        num3 = (num / 100);
        num = (num3);
        result1 = (aux + num2);
    }
    while (num > 0);

    num = aux2 / 10;
    do
    {
        // inicio da conversao dos 1 digitos para string
        num2 = (num % 10);
        num3 = (num / 100);
        num = (num3);
        num2 = (num2 * 2);
        sprintf(str, "%li", num2);
        strcat(str2, str);
    }
    while (num > 0);
    long int num4 = atol(str2); // conversao de str para long int

    do
    {
        // soma dos primeiros digitos
        aux = result2;
        num2 = (num4 % 10);
        num3 = (num4 / 10);
        num4 = (num3);
        result2 = (aux + num2);
    }
    while (num4 > 0);

    endresult = (result1 + result2); // soma final


    num = aux2;
    do
    {
        // verificando qual cartão é coletando os 2 primeiros numeros
        num3 = (num / 10);
        num = (num3);
    }
    while (num3 >= 99);

    sprintf(str, "%li", aux2); //conversao

    if (endresult % 10 == 0) //imprimindo qual cartão é
    {
        if (strlen(str) > 16 || strlen(str) < 13)
        {
            printf("INVALID\n");
        }
        else if (num3 / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (num3 == 34 || num3 == 37)
        {
            printf("AMEX\n");
        }
        else if (num3 >= 51 && num3 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}