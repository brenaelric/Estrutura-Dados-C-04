#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct pilha_num
{
	int conteudo;
	struct pilha_num *proximo;
};
typedef struct pilha_num PilhaNumeros;

struct pilha_op
{
	char conteudo;
	struct pilha_op *proximo;
};
typedef struct pilha_op PilhaOp;

int isOp(char a);

PilhaNumeros *novoNum(int numero);
PilhaNumeros *empilhaNum(PilhaNumeros *num, int numero);
PilhaNumeros *desempilhaNum(PilhaNumeros *num);

PilhaOp *novoOp(char operador);
PilhaOp *empilhaOp(PilhaOp *op, char operador);
PilhaOp *desempilhaOp(PilhaOp *op);
