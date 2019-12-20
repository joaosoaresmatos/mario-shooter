#ifndef BOTAO_H_INCLUDED
#define BOTAO_H_INCLUDED
#include "posicao.h"
#include "tamanho.h"
#include "SOIL.h"
#include <GL/freeglut.h>

typedef struct botoes{
    posicao p;
    tamanho t;
    GLuint textura;
}botoes;
void inicializaTexturaBotoes(botoes*);
void inicializaBotoes(botoes*);
void desenhaBotao(botoes);
void verificaClickBotao(int botaoMouse, int estado, int x, int y, botoes *botao, int *tela);


#endif // BOTAO_H_INCLUDED
