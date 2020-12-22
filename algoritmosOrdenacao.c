#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
// Algoritmos de Ordenação
#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "heapsort.h"

//------------------------------------------------------------------------//
//         Implementação e Comparação de Algoritmos de Ordenação
//
//      Alunos: Ismael Assunção Costa, Leandro Oliveira, Weslley
//
//      Este programa possui 2 modos de execução: Teste e simulação
//
// 1) Teste:
//      Argumento: "teste"
//
//      ./algoritmosOrdenacao teste
//
//      Serão testados apenas vetores de dois tamanhos: 100 e 500.
//      Os vetores são gerados em ordem crescente, decrescente e aleatória.
//      Serão feitas 3 repetições. Tantos os vetores originais quanto os ordenados
//      são salvos no arquivo "vetores.txt". O tempo de execução e o número de comparações
//      são salvos nos arquivos "tempo.csv" e "comparacoes.csv", respectivamente.
//
// 2) Simulação:
//      Argumento: "simulacao"
//
//      ./algoritmosOrdenacao simulacao
//
//      Serão testados vetores de 9 tamanhos: 100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000.
//      Os vetores são gerados em ordem crescente, decrescente e aleatória.
//      Serão feitas 3 repetições. O tempo de execução e o número de comparações
//      são salvos nos arquivos "tempo.csv" e "comparacoes.csv", respectivamente.
//      O tempo de execução nesse modo é bastante demorado.
//
//-----------------------------------------------------------------------//

void geraVetor(int, int *, int);
void vetorCrescente(int *, int);
void vetorDecrescente(int *, int);
void vetorAleatorio(int *, int);
int ordena(int *, int, int);

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Número Inválido de Argumentos!\n");
        return;
    }

    FILE *arquivoTempo;
    arquivoTempo = fopen("tempo.csv", "w+");

    FILE *arquivoComparacoes;
    arquivoComparacoes = fopen("comparacoes.csv", "w+");

    FILE *arquivoVetores;
    //0 ou 9, para teste e simulaçõa, respectivamente
    int quantidadeVetores;

    int tamanhoVetores[9] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};

    //imprimirVetor é usado para saber se o vetor será impresso ou não na saída txt
    //Para saídas grandes é inviável, logo acontece somente nos casos de testes
    bool imprimirVetor;
    if (strcmp(argv[1], "teste") == 0)
    {
        imprimirVetor = true;
        arquivoVetores = fopen("vetores.txt", "w+");
        quantidadeVetores = 2;
    }
    else
    {
        if (strcmp(argv[1], "simulacao") == 0)
        {
            imprimirVetor = false;
            quantidadeVetores = 9;
        }
        else
        {
            printf("Argumento Inválido!\n");
            return;
        }
    }

    char *algoritmosOrdenacao[] = {"BUBBLESORT", "INSERTIONSORT", "MERGESORT", "HEAPSORT", "QUICKSORT"};

    //3 tipos de ordenação
    int i;
    
    for (i = 0; i < 3; i++)
    {
        char tipoOrdenacao[15];

        switch (i)
        {
        case 0:
            strcpy(tipoOrdenacao, "CRESCENTE");
            break;
        case 1:
            strcpy(tipoOrdenacao, "DECRESCENTE");
            break;
        case 2:
            strcpy(tipoOrdenacao, "ALEATORIO");
            break;
        }

        fprintf(arquivoTempo, "%s\n", tipoOrdenacao);
        fprintf(arquivoComparacoes, "%s\n", tipoOrdenacao);
        printf("Ordenacao: %s, ", tipoOrdenacao);
        if (imprimirVetor)
            fprintf(arquivoVetores, "Ordenação: %s\n", tipoOrdenacao);
        
	    int j;

        for (j = 0; j < 5; j++)
        {
            fprintf(arquivoTempo, "%s,", algoritmosOrdenacao[j]);
            fprintf(arquivoTempo, "REPETICAO 1, REPETICAO 2, REPETICAO 3\n");
            fprintf(arquivoComparacoes, "%s,", algoritmosOrdenacao[j]);
            fprintf(arquivoComparacoes, "REPETICAO 1, REPETICAO 2, REPETICAO 3\n");

            printf("Algoritmo: %s\n", algoritmosOrdenacao[j]);
            if (imprimirVetor)
                fprintf(arquivoVetores, "Algoritmo: %s\n", algoritmosOrdenacao[j]);

            // Para cada vetor de tamanho diferente
            int k;
            
            for (k = 0; k < quantidadeVetores; k++)
            {
                fprintf(arquivoTempo, "%i,", tamanhoVetores[k]);
                fprintf(arquivoComparacoes, "%i,", tamanhoVetores[k]);
                printf("Tamanho do Vetor: %i\n", tamanhoVetores[k]);
                if (imprimirVetor)
                    fprintf(arquivoVetores, "Tamanho do Vetor: %i\n", tamanhoVetores[k]);
                
                int l;

                for (l = 0; l < 3; l++)
                {
                    printf("Repetição: %i\n", l);
                    if (imprimirVetor)
                        fprintf(arquivoVetores, "Repetição: %i\n", l);

                    int vetor[tamanhoVetores[k]];
                    //i é o tipo de ordenação com que o vetor será gerado
                    geraVetor(i, vetor, tamanhoVetores[k]);

                    //Se for teste, o vetor gerado será impresso em um arquivo txt separado
                    if (imprimirVetor)
                    {
                        fprintf(arquivoVetores, "Vetor inicial: \n[");
                        
                        int m;
                        
                        for (m = 0; m < tamanhoVetores[k]; m++)
                        {
                            fprintf(arquivoVetores, "%i ", vetor[m]);
                        }
                        fprintf(arquivoVetores, "]\n");
                    }

                    int comparacoes;
                    clock_t t;
                    t = clock();
                    //j é o tipo de algoritmo de ordenação a ser aplicada no vetor
                    comparacoes = ordena(vetor, tamanhoVetores[k], j);
		    t = clock() - t;
                    // O vetor já ordernado será impresso no txt a fim de comparar com o vetor original
                    if (imprimirVetor)
                    {
                        fprintf(arquivoVetores, "Vetor ordenado: \n[");
                        
                        int m;
                        
                        for (m = 0; m < tamanhoVetores[k]; m++)
                        {
                            fprintf(arquivoVetores, "%i ", vetor[m]);
                        }
                        fprintf(arquivoVetores, "]\n");
                    }

                    fprintf(arquivoTempo, "%lf,", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
                    fprintf(arquivoComparacoes, "%i,", comparacoes);

                    if (l == 2)
                    {
                        fprintf(arquivoTempo, "\n");
                        fprintf(arquivoComparacoes, "\n");
                    }
                }
            }
            if (i == 4)
            {
                fprintf(arquivoTempo, "\n");
            }
        }
    }

    printf("Processo Finalizado.\n");
    fclose(arquivoTempo);
    fclose(arquivoVetores);
    fclose(arquivoComparacoes);
}

void vetorCrescente(int vetor[], int tamanho)
{
	int i;
	
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
    }
}

void vetorDecrescente(int vetor[], int tamanho)
{
	int i;
	
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = tamanho - i - 1;
    }
}

void vetorAleatorio(int vetor[], int tamanho)
{
	int i;
	
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100;
    }
}

void geraVetor(int ordem, int vetor[], int tamanho)
{
    switch (ordem)
    {
    case 0:
        return vetorCrescente(vetor, tamanho);
    case 1:
        return vetorDecrescente(vetor, tamanho);
    case 2:
        return vetorAleatorio(vetor, tamanho);
    }
}

//Ordena o vetor e retorna o número de comparações feitas para ordenar
int ordena(int *vetor, int tamanho, int tipoOrdenacao)
{
    switch (tipoOrdenacao)
    {
    case 0:
        return bubblesort(vetor, tamanho);
    case 1:
        return insertionsort(vetor, tamanho);
        break;
    case 2:
        return mergesort(vetor, 0, tamanho);
        break;
    case 3:
        return heapsort(vetor, tamanho);
        break;
    case 4:
        return quicksort(vetor, 0, tamanho-1);
        break;
    }
    
    return 0;
}
