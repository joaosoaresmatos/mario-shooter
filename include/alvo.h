#ifndef ALVO_H_INCLUDED
#define ALVO_H_INCLUDED
#include "posicao.h"
#include "tamanho.h"
#include <GL/freeglut.h>
#include <SOIL.h>

typedef struct alvo
{
    int identificador;
    posicao p;
    tamanho t;
    float velocidade;
    int vidas;
    GLuint textura;

} alvo;

void inicializaAlvo(alvo*);
void desenhaAlvo(alvo monstro);
void desenhaAlvos(alvo*);
void movimentaAlvo(alvo *monstro);
void verificaColisaoAlvo(int,int,int,int,alvo*);
void inicializaTexturaAlvo(alvo*);
#endif // ALVO_H_INCLUDED
