#include <stdio.h>

#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 200

int i,TAM=0;

FILE *arquivo; 
char vetorNomeArquivo[23][200];
char nomeArquivo[];
char pasta[] = "c:\\Users\\HP\\Documents\\mestrado_estrutura_de_dados\\trabalho_estrutura_mestrado_ordenacao\\ordenados\\";
char caminhoFinal[200];
char nome_busca[20];
int *totalElementos;
FILE *arquivo;
double tempoOrdenacaoMerge=0,  tempoOrdenacaoQuick=0;
clock_t t;
char novoNome[200];
DIR *dir;
int contLinhas =0;  
int *v;


//função auxiliar para realizar as trocas de elementos
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[], int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    int a = A[inicio];
    int b = A[meio];
    int c = A[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(A, medianaIndice, fim);
        
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = A[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j] <= pivo) {
            i = i + 1;
            swap(A, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(A, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}
//Quicksort mediana de três
void quicksortMedianaDeTres(int A[], int inicio, int fim) {
    if (inicio < fim) {
        //realiza a partição
        int q = partition(A, inicio, fim);
        //ordena a partição esquerda
        quicksortMedianaDeTres(A, inicio, q - 1);
        //ordena a partição direita
        quicksortMedianaDeTres(A, q + 1, fim);
    }
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

    dir = opendir("c:\\Users\\HP\\Documents\\mestrado_estrutura_de_dados\\trabalho_estrutura_mestrado_ordenacao\\ordenados\\");

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        strcpy( vetorNomeArquivo[cont],lsdir->d_name );         
        //printf ("%s\n", lsdir->d_name);
        cont++;
    }

    closedir(dir);



}

void lerArquivo(int tamanhoVetor){    
    printf("tamanho vetor %i\n", contLinhas);
    FILE *arquivo;   
    char info[tamanhoVetor];
    arquivo = fopen(caminhoFinal, "r");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }else{
        printf("entrando no while\n");
        while( (fgets(info, sizeof(info), arquivo))!=NULL ){
            v[contLinhas] =  atoi(info);
            contLinhas = contLinhas + 1;    
        }
            
    }  
    printf("saindo do lerArquivo\n");
    fclose(arquivo);  
    
}

void criaArquivo(){
   arquivo = fopen("tabela.csv", "w");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }
}

retornaTamanhoVetor(char nome[]){
    int cont =1;
    while (nome[cont] != '.')
        {       
            novoNome[cont-1] = nome[cont];   
            cont++;            
        }        
   TAM =  atoi(novoNome);  
   memset(novoNome, 0, 200); 
}
   
int main (void) {   
 
  criaArquivo();
  fprintf(arquivo,"Algoritmo;Vetor;Tempo\n");
  lerDiretorio(); 
  for (int i = 0; i < 22; i++){     
    if(i > 1){         
      totalElementos = 0;
      contLinhas = 0;
      printf("Iniciando ordenação do arquivo %s\n",vetorNomeArquivo[i]);
      memccpy(memccpy(caminhoFinal, pasta, '\0', MAX) - 1, vetorNomeArquivo[i], '\0', MAX);
      retornaTamanhoVetor(vetorNomeArquivo[i]); 
      v = (int*) malloc(TAM * sizeof(int));
      int result = TAM + 10;
      printf("result %i\n", result);
      lerArquivo(TAM);       

      strcpy( nome_busca, "mergesort");
      clock_t ticMerge = clock();     
      mergesort(v, contLinhas);  
      clock_t tocMerge = clock();    
      tempoOrdenacaoMerge = (double)(tocMerge - ticMerge)/ (CLOCKS_PER_SEC/1000);    
      fprintf(arquivo, "%s; %s; %lf\n",nome_busca,vetorNomeArquivo[i], tempoOrdenacaoMerge);     

      strcpy( nome_busca, "quick_sort");
      clock_t ticQuick = clock();
      //quick_sort(v, 0, contLinhas - 1);
      quicksortMedianaDeTres(v, 0, contLinhas - 1);
      clock_t tocQuick = clock();  
      tempoOrdenacaoQuick = (double)(tocQuick - ticQuick)/ (CLOCKS_PER_SEC/1000);
      fprintf(arquivo, "%s; %s; %f\n",nome_busca,vetorNomeArquivo[i], tempoOrdenacaoQuick);
     

      
      //for para teste de ordenação megesort    
     /* for (int j = 0; j < contLinhas; j++){
        printf("%d ", v[j]);               
      }*/       
    }
       
  }  

   return 0;

}

