#ifndef HASHING_H
#define HASHING_H

/* O Metodo da Divisao retorna o resultado da divisao inteira entre
 * a chave (key) e o tamanho da tabela hash (m).
 *
 * Caso o valor seja calculado com sucesso, ele eh retornado em uma
 * variavel 'r' passada pelo usuario e a funcao retorna o valor 1,
 * indicando sucesso. Caso contrario, retorna 0.
 *
 * Caso algum dos parametros possua valor menor do que zero, a funcao
 * retornara um erro.
 */
int chaveDivisao(int key, int m, int* r);

/* O Metodo da Multiplicacao retorna a parte inteira da multiplicacao
 * entre o tamanho da tabela hash (m) e um valor (value). Esse valor eh
 * a parte inteira da multiplicao entre a chave (key) e o coeficiente a.
 *
 * Caso o valor seja calculado com sucesso, ele eh retornado em uma
 * variavel 'r' passada pelo usuario e a funcao retorna o valor 1,
 * indicando sucesso. Caso contrario, retorna 0.
 *
 * Caso algum dos parametros possua valor menor do que zero, a funcao
 * retornara um erro.
 */
int chaveMultiplicacao(int key, int m, float a, int* r);

#endif // HASHING_H
