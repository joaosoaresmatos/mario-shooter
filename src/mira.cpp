#include "mira.h"
#include <stdio.h>
#include <SOIL.h>
#include <GL/freeglut.h>
posicao posicaoMouse;

void atualizaMira(mira *arma)
{
    int i;
    for(i=0; i<3; i++)
    {
        arma[i].p.x =posicaoMouse.x-arma[i].t.largura/2;
        arma[i].p.y =posicaoMouse.y-arma[i].t.altura/2;
    }
}
void desenhaMira(mira arma)
{


    glColor3f(1, 1, 1);

    glEnable(GL_TEXTURE_2D);//TEXTURA*********************************************************
    glEnable( GL_BLEND );
    glBindTexture(GL_TEXTURE_2D,arma.textura);//TEXTURA*********************************************************
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glTexCoord2f(1,1);
    glVertex3f(arma.p.x, arma.p.y, 0);
    glTexCoord2f(0,1);
    glVertex3f(arma.p.x + arma.t.largura, arma.p.y, 0);
    glTexCoord2f(0,0);
    glVertex3f(arma.p.x + arma.t.largura, arma.p.y + arma.t.altura, 0);
    glTexCoord2f(1,0);
    glVertex3f(arma.p.x, arma.p.y + arma.t.altura, 0);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glFlush();
}
void inicializaMira(mira *arma)
{
    glClearColor(1, 1, 1, 0);
    int i;
    for(i=0; i<3; i++)
    {
        arma[i].p.x = 0;
        arma[i].p.y = 0;
        arma[i].t.largura = 50;
        arma[i].t.altura = 50;
    }
}
void inicializaTexturaMira(mira *arma)
{

    int i;
    //TEXTURA DA PRIMEIRA ARMA
    arma[0].textura =  SOIL_load_OGL_texture(
                           "mira6.png",
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );
    if (arma[0].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDA ARMA
    arma[1].textura =  SOIL_load_OGL_texture(
                           "A.png",
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );
    if (arma[1].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDA ARMA
    arma[2].textura =  SOIL_load_OGL_texture(
                           "A.png",
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );
    if (arma[2].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}


void movimentoMouse(int x, int y)
{
    posicaoMouse.x = x;
    posicaoMouse.y = y;
}

