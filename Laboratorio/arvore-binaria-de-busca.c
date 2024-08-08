#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Info
{
  char nome[100];
  int mat;
  int turma;
  float nota;
};

struct Node
{
  struct Info info;
  struct Node *esq;
  struct Node *dir;
};

typedef struct Info Info;
typedef struct Node Node;

Info criarInfo(char *nome, int mat, int turma, float nota);
Node *criarNode(Info info);

int comparar(Info a, Info b);
Node *inserir(Node *raiz, Info info);

int main()
{
  Info info[10];
  Node *raiz = 0;
  info[0] = criarInfo("Kennedy", 4, 1, rand() % 10);
  raiz = inserir(raiz, info[0]);
  info[1] = criarInfo("Matheus", 7, 1, rand() % 10);
  raiz = inserir(raiz, info[1]);
  return 0;
}

Info criarInfo(char *nome, int mat, int turma, float nota)
{
  Info res;
  strcpy(res.nome, nome);
  res.mat = mat;
  res.turma = turma;
  res.nota = nota;
  return res;
}

Node *criarNode(Info info)
{
  Node *res = (Node *)malloc(sizeof(Node));
  res->info = info;
  res->dir = 0;
  res->esq = 0;
  return res;
}

int comparar(Info a, Info b)
{
  return strcmp(a.nome, b.nome);
}

Node *inserir(Node *raiz, Info info)
{
  if (raiz == 0)
  {
    return criarNode(info);
  }
  int x = comparar(raiz->info, info);
  if (x > 0)
  {
    raiz->dir = inserir(raiz->dir, info);
  }
  else
  {
    raiz->esq = inserir(raiz->esq, info);
  }

  return raiz;
}