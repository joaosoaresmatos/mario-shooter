#include "fundo.h"
#include "posicao.h"
#include "tamanho.h"
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <SOIL.h>

void inicializaTexturaFundo(fundo *telaDeFundo)
{
    telaDeFundo[0].textura =  SOIL_load_OGL_texture(
                                  "fundoMenu.png",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
    if (telaDeFundo[0].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDAtelaDeFundo
    telaDeFundo[1].textura =  SOIL_load_OGL_texture(
                                  "fundoFase1.jpg",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
    if (telaDeFundo[1].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDAtelaDeFundo
    telaDeFundo[2].textura =  SOIL_load_OGL_texture(
                                  "opcoes.png",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
    if (telaDeFundo[2].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    telaDeFundo[3].textura =  SOIL_load_OGL_texture(
                                  "creditos.png",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
    if (telaDeFundo[3].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    telaDeFundo[4].textura =  SOIL_load_OGL_texture(
                                  "gameOver.png",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
    if (telaDeFundo[4].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

}
void inicializaFundos(fundo *telaDeFundo)
{
    int i;
    for(i=0; i<5; i++)
    {
        telaDeFundo[i].p.x= 0;
        telaDeFundo[i].p.y= 0;
        telaDeFundo[i].t.altura= 600;
        telaDeFundo[i].t.largura= 800;
    }
}
void desenhaFundo(fundo telaDeFundo)
{

    glEnable(GL_TEXTURE_2D);//TEXTURA*********************************************************
    glEnable( GL_BLEND );
    glBindTexture(GL_TEXTURE_2D, telaDeFundo.textura);//TEXTURA*********************************************************
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glTexCoord2f(0,1);
    glVertex3f(telaDeFundo.p.x, telaDeFundo.p.y, 0);
    glTexCoord2f(1,1);
    glVertex3f(telaDeFundo.p.x + telaDeFundo.t.largura, telaDeFundo.p.y, 0);
    glTexCoord2f(1,0);
    glVertex3f(telaDeFundo.p.x + telaDeFundo.t.largura,  telaDeFundo.p.y + telaDeFundo.t.altura, 0);
    glTexCoord2f(0,0);
    glVertex3f(telaDeFundo.p.x, telaDeFundo.p.y + telaDeFundo.t.altura, 0);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);//TEXTURA*********************************************************

}
