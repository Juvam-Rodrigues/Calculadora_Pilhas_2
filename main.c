#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no
{
  char* dado;
  struct no *proximo;
} No;

int esta_vazia(No *topo)
{
  return topo == NULL;
}

void push(No **topo, char *valor)
{
  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->dado = malloc(20); //Quantidade de caracteres máxima
  strcpy(novo_no->dado, valor);
  novo_no->proximo = *topo;
  *topo = novo_no;
}

char *pop(No **topo)
{
  if (!esta_vazia(*topo))
  {
    No *temp = *topo;
    char* valor = malloc(strlen(temp->dado) + 1); //Pegando o tamanho do dado + 1 para caber os caracteres;
    strcpy(valor,temp->dado);
    *topo = (*topo)->proximo;

    free(temp);

    return valor;
  }

  printf("Erro: Pilha vazia!\n");

  return NULL;
}

char *peek(No **topo)
{
  if (!esta_vazia(*topo))
  {
    return (*topo)->dado;
  }

  printf("Erro: Pilha vazia!\n");

  return NULL;
}

char *fazerConta(char *operando1, char *operando2, char *operacao)
{
  int op1 = atoi(operando1);
  int op2 = atoi(operando2);
  int resultado = 0;
  char *numero = malloc(20);
  switch (operacao[0])
  {
  case '+':
    resultado = op1 + op2;
    break;
  case '-':
    resultado = op1 - op2;
    break;
  case '*':
    resultado = op1 * op2;
    break;
  case '/':
    resultado = op1 / op2;
    break;
  default:
    printf("Formato inválido.");
    break;
  }
  sprintf(numero, "%d", resultado);
  return numero;
}

int main()
{
  No *pilha = NULL;

  char *resultado = NULL;
  char *operando1 = NULL;
  char *operando2 = NULL;
  char *operacao = NULL;


  push(&pilha, "3");
  push(&pilha, "4");
  push(&pilha, "+");

  operacao = pop(&pilha);
  operando2 = pop(&pilha);
  operando1 = pop(&pilha);
  
  resultado = fazerConta(operando1, operando2, operacao);
  printf("Resultado parcial: %s\n", resultado);
  free(operacao);
  free(operando1);
  free(operando2);

  push(&pilha, resultado);
  push(&pilha, "2");
  push(&pilha, "*");
  free(resultado);

  operacao = pop(&pilha);
  operando2 = pop(&pilha);
  operando1 = pop(&pilha);

  resultado = fazerConta(operando1, operando2, operacao);
  printf("Resultado parcial: %s\n", resultado);
  free(operacao);
  free(operando1);
  free(operando2);

  push(&pilha, resultado);
  push(&pilha, "7");
  push(&pilha, "/");
  free(resultado);

  operacao = pop(&pilha);
  operando2 = pop(&pilha);
  operando1 = pop(&pilha);

  resultado = fazerConta(operando1, operando2, operacao);
  printf("Resultado final: %s\n", resultado);
  free(operacao);
  free(operando1);
  free(operando2);
  free(resultado);

  return 0;
  
}
