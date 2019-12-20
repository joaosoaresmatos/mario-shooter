#ifndef FUNDO_H_INCLUDED
#define FUNDO_H_INCLUDED
#include "posicao.h"
#include "tamanho.h"
#include <GL/freeglut.h>
#include <SOIL.h>


typedef struct fundo
{
    posicao p;
    tamanho t;
    GLuint textura;
} fundo;
void inicializaTexturaFundo(fundo*);
void inicializaFundos(fundo*);
void desenhaFundo(fundo);
#endif // FUNDO_H_INCLUDED
