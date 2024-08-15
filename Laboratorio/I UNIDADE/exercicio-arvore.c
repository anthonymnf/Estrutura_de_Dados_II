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

// Função para criar um struct Info
Info criarInfo(char *nome, int mat, int turma, float nota);
// Função para criar um nó da árvore
Node *criarNode(Info info);
// Função para comparar dois struct Info
int comparar(Info a, Info b);
// Função para inserir um struct Info na árvore
Node *inserir(Node *raiz, Info info);
// Função para ler dados dos arquivos e inserir na árvore
void lerEInserirDados(const char *nomeArquivo, int turma, Node **raiz);

int main()
{
  Info info[69];
  Node *raiz = NULL;
  srand(time(NULL)); // Inicializa o gerador de números aleatórios

  // Ler dados dos arquivos e inserir na árvore
  lerEInserirDados("alunosT1.txt", 1, &raiz);
  lerEInserirDados("alunosT2.txt", 2, &raiz);
  lerEInserirDados("alunosT3.txt", 3, &raiz);

  return 0;
}

// Função para criar um struct Info
Info criarInfo(char *nome, int mat, int turma, float nota)
{
  Info res;
  strcpy(res.nome, nome);
  res.mat = mat;
  res.turma = turma;
  res.nota = nota;
  return res;
}

// Função para criar um nó da árvore
Node *criarNode(Info info)
{
  Node *res = (Node *)malloc(sizeof(Node));
  res->info = info;
  res->dir = NULL;
  res->esq = NULL;
  return res;
}

// Função para comparar dois struct Info
int comparar(Info a, Info b)
{
  return strcmp(a.nome, b.nome);
}

// Função para inserir um struct Info na árvore
Node *inserir(Node *raiz, Info info)
{
  if (raiz == NULL)
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

// Função para ler dados dos arquivos e inserir na árvore
void lerEInserirDados(const char *nomeArquivo, int turma, Node **raiz)
{
  FILE *file = fopen(nomeArquivo, "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return;
  }

  char linha[150];
  while (fgets(linha, sizeof(linha), file))
  {
    int mat;
    char nome[100];
    sscanf(linha, "%d %[^\n]", &mat, nome); // Lê a matrícula e o nome do aluno

    Info info = criarInfo(nome, mat, turma, rand() % 10); // Cria a struct Info
    *raiz = inserir(*raiz, info);                         // Insere na árvore
  }

  fclose(file);
}
