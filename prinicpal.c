#include <stdio.h>

#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 200

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
void lerArquivo();
void lerDiretorio();

int i;
int contLinhas =0;
FILE *arquivo; 
char vetorNomeArquivo[23][200];
char nomeArquivo[];
int v[1000000];
char pasta[] = "c:\\Users\\HP\\Documents\\mestrado_estrutura_de_dados\\trabalho_estrutura_mestrado_ordenacao\\aleatorios\\";
char caminhoFinal[200];
int *totalElementos;
clock_t t,t2;
double  tempo_ordenar_Final;

DIR *dir;

int main (void) {    
 
  lerDiretorio();
  
   //strcpy( nomeArquivo, vetorNomeArquivo[1]);
   /*
  for (int i = 0; i < 6; i++){
     
    if(i > 1){   
      
      totalElementos = 0;
      printf("entrei vetor :: %i\n", i);
      printf("Iniciando ordenação do arquivo %s\n",vetorNomeArquivo[i]);
      memccpy(memccpy(caminhoFinal, pasta, '\0', MAX) - 1, vetorNomeArquivo[i], '\0', MAX);
      lerArquivo();   

     
      mergesort(v, contLinhas);      
      
      /*
      //for para teste de ordenação megesort    
      for (int j = 0; j < contLinhas; j++){
        printf("%d ", v[j]);               
      }      
     
    }   
  }*/  
     t = clock();
     printf("aa %lf\n", t); 
    memccpy(memccpy(caminhoFinal, pasta, '\0', MAX) - 1, vetorNomeArquivo[2], '\0', MAX);
    printf("arquivo %s\n", vetorNomeArquivo[2]);
    lerArquivo();  
    
   
    
    mergesort(v, contLinhas);   /*
     for (int j = 0; j < contLinhas; j++){
        printf("%d ", v[j]);               
      } */  
     t2 = clock() - t; //tempo final - tempo inicial
    printf("bb %lf\n", t2);
    tempo_ordenar_Final = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
  


  return 0;

}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) { 
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c); 
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}


void lerDiretorio(){

    int cont = 0;
    struct dirent *lsdir;

    dir = opendir("c:\\Users\\HP\\Documents\\mestrado_estrutura_de_dados\\trabalho_estrutura_mestrado_ordenacao\\aleatorios\\");

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        strcpy( vetorNomeArquivo[cont],lsdir->d_name );         
        //printf ("%s\n", lsdir->d_name);
        cont++;
    }

    closedir(dir);



}

void lerArquivo(){   

    FILE *arquivo;   
    char info[100];
    arquivo = fopen(caminhoFinal, "r");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }else{
        while( (fgets(info, sizeof(info), arquivo))!=NULL ){
            v[contLinhas] =  atoi(info);
            contLinhas = contLinhas + 1;    
        }
            
    }
    fclose(arquivo);   
 
 
}


