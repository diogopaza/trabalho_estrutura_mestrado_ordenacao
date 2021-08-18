#include <stdio.h>

#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char nome[] = "a7500.txt";
char novoNome[200];

int main(){

    
   
/*
   while (nome[cont] == '.')
   {
       printf("imprimindo %c\n", nome[cont]);
       cont++;
   }*/
   /*
   if(nome[7] == '.'){
       printf("imprimindo %s", nome);
   }*/
    int cont =1;
    
     while (nome[cont] != '.')
        {       
            novoNome[cont-1] = nome[cont];   
            cont++;            
        }
       
        
       // printf("Novo nome ==  %s\n", novoNome);
   
   
    printf("Novo nome fora do FOR ==%s\n", novoNome); 
   
    


    return 0;
}