#include "lista04.h"

int main()
{
	PilhaNumeros *num = NULL;
	PilhaOp *op = NULL;
	int i, j;
	char expressao[100];
	for (i = 0; i < 100; i++)
		expressao[i] = '\0';

	printf("Digite sua expressao:\n");
	scanf("%s", expressao);

	char subexpressao[100];
	for (i = 0, j = 0; expressao[i] != '\0'; i++)
	{
		if (isOp(expressao[i]))
		{
			if (op == NULL)
				op = novoOp(expressao[i]);
			else
				op = empilhaOp(op, expressao[i]);
			/*Depois de empilhar o operador, irei
			 empilhar o numero que deverá estar na subexpressao*/
			if (j == 0)
			{
				printf("A expressao deve começar com um numero!\n");
				break;
			}
			int numero;
			sscanf(subexpressao, "%d", &numero);
			if (num == NULL)
				num = novoNum(numero);
			else
				num = empilhaNum(num, numero);
			memset(subexpressao, '\0', j);
			j = 0;
		}
		else if (isdigit(expressao[i]))
		{
			subexpressao[j] = expressao[i];

			j++;
		}
		else if (isspace(expressao[i]))
		{
		}
		else
			printf("Você digitou uma expressao invalida!\n");
	}
	if (j > 0)
	{
		int numero;
		sscanf(subexpressao, "%d", &numero);
		if (num == NULL)
			num = novoNum(numero);
		else
			num = empilhaNum(num, numero);
		memset(subexpressao, '\0', j);
		j = 0;
	}

	int resultado;
	while (num != NULL && num->proximo !=NULL)
	{
		int v1 = num->conteudo;
		num = desempilhaNum(num);
		int v2 = num->conteudo;
		num = desempilhaNum(num);
		char o = op->conteudo;
		op = desempilhaOp(op);
		resultado = calculo(o, v1, v2);
		num = empilhaNum(num, resultado);
	}
	printf("O resultado e: %d\n", resultado);
	system("pause");
	return 0;
}
