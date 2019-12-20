#ifndef MIRA_H_INCLUDED
#define MIRA_H_INCLUDED

#include "posicao.h"
#include "tamanho.h"
#include <GL/freeglut.h>
#include <SOIL.h>
typedef struct mira
{
    posicao p;
    tamanho t;
    int quantidadeDeTiros;
    GLuint textura;
} mira;

void desenhaMira(mira arma);
void inicializaTexturaMira(mira *arma);
void movimentoMouse(int x, int y);
void atualiza(int indice);
void inicializaMira(mira *arma);
void atualizaMira(mira *arma);




#endif // MIRA_H_INCLUDED
