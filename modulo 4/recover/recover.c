#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
   typedef uint8_t BYTE;
   const int byt = 512;

 if(argc != 2 )
 {
    printf("Deve-se utilizar UM argumento de command-line\n");
    printf("USO: ./recover imagem\n");
    return 1;
 }
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
      printf("Não foi possivel abrir %s\n",argv[1]);
    }

    BYTE BUFFER[byt];
    char *recuperar = malloc(8);
    FILE *jpg;
    int x = 0;

    do{
      if(BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
      {
         sprintf(recuperar, "%03i.jpg", x);
         jpg = fopen(recuperar, "w");
         fwrite(BUFFER, 1, byt, jpg);
         x++;
      }
      else
      {
         if(x>0)
         {
            fwrite(BUFFER, 1, byt, jpg);
         }
      }

    }
    while(fread(&BUFFER, 1, byt, file));
    free(recuperar);
    fclose(jpg);
    fclose(file);
    return 0;


}