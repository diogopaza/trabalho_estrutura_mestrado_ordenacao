#include <stdio.h>
#include <stdlib.h> 


int *vv;

int main(){

    int *ai = (int *) calloc (1000000, sizeof(int));
    vv =  (int *) malloc(20 * sizeof(int));
    int n2 = sizeof(ai)/sizeof(int);
    printf("Tamanho do vetor %i\n", ai);  

}

 