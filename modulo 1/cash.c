#include<stdio.h>
#include<cs50.h>
#include <math.h>

int main(void)
{
    float quantia = 0;
    int cent25 = 0, cent10 = 0, cent5 = 0, cent1 = 0, resultado = 0 ;

    do
    {
        quantia = get_float("Quantia de troco: \n");
    }
    while (quantia < 0);
    
    do
    {
        if(quantia >= 0.25)
        {
        quantia= (quantia - 0.25);
        cent25++;

        }
        else if (quantia > 0.09 && quantia < 0.25)
        {

            quantia = (quantia-0.10);
            cent10++;


        }
        else if (quantia <= 0.09 && quantia >= 0.05)
        {
            quantia = (quantia-0.05);
            cent5++;

            if (quantia <= 0.4 && quantia >= 0.001) {
            quantia = (quantia-0.01);
            cent1++;
        }
        }

    }
    while (quantia > 0.01);

    resultado = cent25 + cent10 + cent5 + cent1;
    printf("25 Centavos: %i\n", cent25);
    printf("10 Centavos: %i\n", cent10);
    printf("5 Centavos: %i\n", cent5);
    printf("1 Centavo: %i\n", cent1);


    printf("\nQuantidade minimas de moedas: %i\n", resultado);

    return 0;

}