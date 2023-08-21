#include "helpers.h"
#include <math.h>
double media = 0;
RGBTRIPLE aux;
RGBTRIPLE med;

// Convert image to grayscale
//                 altura      largura                  l       c
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {

            media = round(((image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed))/3);

            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtRed = media;


        }
    }
    return;
}
//                                                  l       c
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            aux.rgbtBlue = image[i][j].rgbtBlue;
            aux.rgbtGreen = image[i][j].rgbtGreen;
            aux.rgbtRed = image[i][j].rgbtRed;
            float blue= round(.272 * aux.rgbtRed + .534 * aux.rgbtGreen + .131 * aux.rgbtBlue);
            float green = round(.349 * aux.rgbtRed + .686 * aux.rgbtGreen + .168 * aux.rgbtBlue);
            float red = round(.393 * aux.rgbtRed + .769 * aux.rgbtGreen + .189 * aux.rgbtBlue);

            if(blue>255)
            {
                blue = 255;
            }

            if(red>255)
            {
                red= 255;
            }
            if(green>255)
            {
                green = 255;
            }

            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;

        }
    }

}

// Reflect image horizontally                          l      c
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j<width/2; j++)
        {
            aux = image[i][width-j-1];
            image[i][width-j-1]=image[i][j];
            image[i][j] = aux;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE img[height][width];
//img backup
    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            img[i][j]=image[i][j];
        }
    }
//linhas
    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j<width; j++) // colunas
        {

            float mediab = 0, mediag = 0, mediar = 0;
            int c = 0;

            for(int x = -5; x<6; x++)//range de media de pixels, loops para a media
            {
                for(int y = -5; y<6; y++)
                {

                    int a = i + x;
                    int b = j + y;

                    if(!(a<0 || a>=height || b<0 || b>=width))//verifica se tal bit esta fora da imagem
                    {
                    mediab = img[a][b].rgbtBlue+mediab;
                    mediag = img[a][b].rgbtGreen+mediag;
                    mediar = img[a][b].rgbtRed+mediar;
                    c = c+1;
                    }

                }
            }
            //obtem imagem desfocada
            image[i][j].rgbtBlue = round(mediab / c);
            image[i][j].rgbtGreen = round(mediag / c);
            image[i][j].rgbtRed = round(mediar / c);
        }
    }
    return;
}




// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE img[height][width];

    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            img[i][j]=image[i][j];
        }
    }


    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j<width; j++)
        {

            float xblue, xgreen, xred;
            float yblue, ygreen, yred;

            xblue = 0;
            yblue = 0;
            xgreen = 0;
            ygreen = 0;
            xred = 0;
            yred = 0;

            for(int x = -1; x<2; x++)
            {
                for(int y = -1; y<2; y++)
                {
                    int a = i + x;
                    int b = j + y;

                    if(!(a<0 || a>=height || b<0 || b>=width))
                    {
                    xblue = xblue + img[a][b].rgbtBlue * gx[x+1][y+1];
                    xgreen = xgreen + img[a][b].rgbtGreen * gx[x+1][y+1];
                    xred = xred + img[a][b].rgbtRed * gx[x+1][y+1];

                    yblue = yblue + img[a][b].rgbtBlue * gy[x+1][y+1];
                    ygreen = ygreen + img[a][b].rgbtGreen * gy[x+1][y+1];
                    yred = yred + img[a][b].rgbtRed * gy[x+1][y+1];
                    }

                }
            }

            float vermelho = round(sqrt(pow(xred, 2) + pow(yred, 2)));
            float azul = round(sqrt(pow(xblue, 2) + pow(yblue, 2)));
            float verde = round(sqrt(pow(xgreen, 2) + pow(ygreen, 2)));


            if (vermelho > 255)
            {
                vermelho = 255;
            }
            if (azul > 255)
            {
                azul = 255;
            }
            if (verde > 255)
            {
                verde = 255;
            }

            image[i][j].rgbtRed = vermelho;
            image[i][j].rgbtBlue = azul;
            image[i][j].rgbtGreen = verde;
        }
    }

    return;
}
