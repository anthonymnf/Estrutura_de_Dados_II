// invertexto.com/naxb11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Info
{
  char nome[100];
};

struct Node
{
  struct Info info;
  struct Node *esq;
  struct Node *dir;
};

struct Info criarInfo(char *nome);
struct Node *criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);
void preOrdem(struct Node *raiz);
void posOrdem(struct Node *raiz);
void inOrdem(struct Node *raiz);
int maior(int a, int b);
int altura(struct Node *raiz);
int main()
{
  struct Info info[10];
  info[0] = criarInfo("Kennedy");
  info[1] = criarInfo("Mikael");
  info[2] = criarInfo("Joao");
  info[3] = criarInfo("Francisco");
  info[4] = criarInfo("Maria");

  struct Node *raiz = 0;
  for (size_t i = 0; i < 5; i++)
  {
    raiz = inserir(raiz, info[i]);
  }
  printf("Pre-ordem:\n");
  preOrdem(raiz);
  printf("\nPos-ordem:\n");
  posOrdem(raiz);
  printf("\nIn-ordem:\n");
  inOrdem(raiz);
  int alt = altura(raiz);
  printf("\nAltura da raiz: %d", alt);
}

int maior(int a, int b) { return a > b ? a : b; }
int altura(struct Node *raiz)
{
  if (raiz == 0)
  {
    return -1;
  }
  else
  {
    int he = altura(raiz->esq);
    int hd = altura(raiz->dir);
    return 1 + maior(he, hd);
  }
}

void preOrdem(struct Node *raiz)
{
  if (raiz != 0)
  {
    printf("%s\n", raiz->info.nome); // Visita raiz
    preOrdem(raiz->esq);             // Visita sub-arvore esq
    preOrdem(raiz->dir);             // Visita sub-arvore dir
  }
}
void posOrdem(struct Node *raiz)
{
  if (raiz != 0)
  {
    posOrdem(raiz->esq);             // Visita sub-arvore esq
    posOrdem(raiz->dir);             // Visita sub-arvore dir
    printf("%s\n", raiz->info.nome); // Visita raiz
  }
}
void inOrdem(struct Node *raiz)
{
  if (raiz != 0)
  {
    preOrdem(raiz->esq);             // Visita sub-arvore esq
    printf("%s\n", raiz->info.nome); // Visita raiz
    preOrdem(raiz->dir);             // Visita sub-arvore dir
  }
}

struct Info criarInfo(char *nome)
{
  struct Info res;
  strcpy(res.nome, nome);
  return res;
}

struct Node *criarNode(struct Info info)
{
  struct Node *res = (struct Node *)malloc(sizeof(struct Node));
  res->info = info;
  res->dir = 0;
  res->esq = 0;
  return res;
}

int comparar(struct Info a, struct Info b) { return strcmp(a.nome, b.nome); }

struct Node *inserir(struct Node *raiz, struct Info info)
{
  if (raiz == 0)
  {
    return criarNode(info);
  }
  int x = comparar(raiz->info, info);
  if (x < 0)
  {
    raiz->dir = inserir(raiz->dir, info);
  }
  else if (x > 0)
  {
    raiz->esq = inserir(raiz->esq, info);
  }
  return raiz;
}