
/* ************************************************ */
/* Apelido para a estrutura definida no arquivo .c
   que sera manipulada pela TAD.*/

typedef struct ponto Ponto;

/* ************************************************ */


/* ***************************************************** */
/* Funcao pto_cria */
/* Manipulacoa da TAD especifica para criacao de um
   ponto (coordenada cartesiana) no R².
   Recebe, por valor, dois valores do tipo de dado float;
   responsaveis por caracterizar o ponto.
   Retorna uma ponteiro para Ponto.*/

Ponto* pto_cria(float x, float y);

/* ****************************************************** */


/* *************************************************** */
/* Funcao pto_libera */
/* Manipulacoa da TAD especifica para liberacao de um
   ponto (coordenada cartesiana) no R².
   Recebe, por referencia, o ponto que sera liberado. */

void pto_libera(Ponto* p);

/* *************************************************** */


/* *************************************************** */
/* Funcao ptos_libera */
/* Manipulacoa da TAD especifica para liberacao de,
   pelo menos um ponto (coordenada cartesiana) no R².
   Recebe, por valor, a quantidade de pontos que
   serao liberados e os pontos.*/

void ptos_libera(int qnt_ptos, ...);

/* *************************************************** */


/* *************************************************** */
/* Funcao pto_acessa */
/* Manipulacoa da TAD especifica para acesso a um ponto
   (coordenada cartesiana) no R².
   Recebe, por referencia, o ponto especifico.
   Retorna, por referencia, as coordenadas do ponto. */

void pto_acessa(Ponto* p, float* x, float *y);

/* *************************************************** */


/* *************************************************** */
/* Funcao pto_atribui */
/* Manipulacoa da TAD especifica para atribuicao a um
   ponto (coordenada cartesiana) no R².
   Recebe, por referencia, as coordenadas que serao
   atribuidas ao ponto. */

void pto_atribui(Ponto* p, float x, float y);

/* *************************************************** */


/* *************************************************** */
/* Funcao pto_distancia */
/* Manipulacoa da TAD especifica para calculo da
   distancia entre dois pontos (coordenadas cartesianas)
   no R².
   Recebe, por referencia, os dois pontos especificos.
   Retorna um dado tipo primitivo float.*/

float pto_distancia(Ponto* p1, Ponto* p2);

/* *************************************************** */
