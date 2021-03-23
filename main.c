#include <stdio.h>
#include "hashing.h"

/* Cria um vetor de inteiros de len posicoes e inicializa
 * todas elas com o valor 0.
 */
int* createArray(int len) {
    int* newArray = (int*) malloc(len * sizeof(int));
    if(newArray == NULL)
        exit(1);

    for(int i = 0; i < len; i++)
        newArray[i] = 0;

    return newArray;
}

/* Abre um arquivo com nome passado como parametro no modo
 * attach, onde comeca a escrever no seu final. Caso o arquivo
 * nao exista, ele eh criado.
 */
FILE* createFile(int filename) {
    FILE* file = fopen(filename, "a");
    if(file == NULL)
        exit (1);

    return file;
}

/* Escreve os dados de um vetor em um arquivo. */
void printFile(FILE* file, int* array, int len, char* header) {
    fprintf(file, header);

    for(int i = 0; i < len; i++)
        fprintf(file, "%d, %d\n", i, array[i]);
}

/* Executa o experimento 1a e 1b onde sao testados os valores para chaves
 * no intervalo entre 0 e 100 utilizando a funcao chaveDivisao para uma
 * tabela de tableLen posicoes. Eh preciso imprimir no console a chave quando
 * h(key) = 3.
 */
void ex1ab(int tableLen) {
    int value;
    int result;

    for(int key = 0; key <= 100; key++) {
        result = chaveDivisao(key, tableLen, &value);
        if(result == 0)
            exit (1);

        if(value == 3)
            printf("Chave = %d => Valor = %d\n", key, value);
    }
}

/* Executa o experimento 1c, onde sao testados os valores para chaves
 * no intervalo entre 1 e 10.000 utilizando a funcao chaveDivisao para
 * uma tabela hash de tableLen posicoes. O vetor counter armazena o
 * numero de colisoes para cada posicao da tabela.
 */
void ex1c(int tableLen, char* filename) {
    FILE *file = createFile(filename);

    int* counter = createArray(tableLen);

    int value;
    int result;
    for(int key = 1; key <= 10000; key++) {
            result = chaveDivisao(key, tableLen, &value);
            if(result == 0)
                exit(1);

            counter[value]++;
    }

    printFile(file, counter, tableLen, "h(k), Quantidade\n");
    fclose(file);
}

/* Executa os experimento 2a e 2b, que possuem a mesma ideia do experimento
 * 1c, porem, utilizando a funcao de chaveMultiplicacao.
 */
void ex2ab(int tableLen, float a, char* filename) {
    FILE *file = createFile(filename);

    int* counter = createArray(tableLen);

    int value;
    int result;
    for(int key = 1; key <= 500000; key++) {
            result = chaveMultiplicacao(key, tableLen, a, &value);
            if(result == 0)
                exit(1);

            counter[value]++;
    }

    printFile(file, counter, tableLen, "h(k), Quantidade\n");
    fclose(file);
}

int main() {
    printf("Iniciando experimentos nas Funcoes de Espalhamento...\n");

    printf("\n##### Metodo da Divisao #####\n");

    printf("\nExperimento a:\n\n");
    ex1ab(12);

    printf("\nExperimento b:\n\n");
    ex1ab(11);

    printf("\nExperimento c:\n");
    ex1c(97, "saida_experimento1c.txt");
    printf("Saida impressa no arquivo saida_experimento1c.txt.\n");

    printf("\n##### Metodo da Multiplicacao #####\n");

    printf("\nExperimento a:\n");
    ex2ab(200, 0.62, "saida_experimento2a.txt");
    printf("Saida impressa no arquivo saida_experimento2a.txt.\n");

    printf("\nExperimento b:\n");
    ex2ab(200, 0.61803398875, "saida_experimento2b.txt");
    printf("Saida impressa no arquivo saida_experimento2b.txt.\n");

    return 0;
}
