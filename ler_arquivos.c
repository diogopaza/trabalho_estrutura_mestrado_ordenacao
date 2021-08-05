#include <stdio.h>
#include <time.h>
#include <math.h>

//void lerArquivo(int *v, int n);

int main () {

    FILE *arquivo;   
    char url[]="a100.txt",
      info[100];
    arquivo = fopen(url, "r");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }else{
        while( (fgets(info, sizeof(info), arquivo))!=NULL )
            printf("%s", info);
            if(info>500){
                /*int soma =10;                
                soma = atoi(info) + soma;
                printf("Valor maior = %i", soma);*/
            }
    }
    
    fclose(arquivo);   
 
 return 0;

    }

