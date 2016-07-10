#include "lista04.h"

PilhaNumeros *novoNum(int numero)
{
	PilhaNumeros *novo = malloc(sizeof(PilhaNumeros));
	novo->proximo = NULL;
	novo->conteudo = numero;
	return novo;
}

PilhaNumeros *empilhaNum(PilhaNumeros *num, int numero)
{
	PilhaNumeros *novo = novoNum(numero);
	novo->proximo = num;
	return novo;
}

PilhaNumeros *desempilhaNum(PilhaNumeros *num)
{
	PilhaNumeros *temp1 = num;
	num = num->proximo;
	free(temp1);
	return num;
}

PilhaOp *novoOp(char operador)
{
	PilhaOp *novo = malloc(sizeof(PilhaOp));
	novo->proximo = 0;
	novo->conteudo = operador;
	return novo;
}

PilhaOp *empilhaOp(PilhaOp *op, char operador)
{
	PilhaOp *novo = novoOp(operador);
	novo->proximo = op;
	return novo;
}

PilhaOp *desempilhaOp(PilhaOp *op)
{
	PilhaOp *temp1 = op;
	op = op->proximo;
	free(temp1);
	return op;
}

int isOp(char a)
{
	if(a=='*' || a=='+' || a=='-' || a=='/')
		return 1;
	return 0;
}

int calculo(char op, int num1, int num2)
{

	switch(op)
	{
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		case '*':
			return num1*num2;
		case'/':
			return num1/num2;
	}
	printf("Operador invalido: %c\n", op);
	return 0;
}

