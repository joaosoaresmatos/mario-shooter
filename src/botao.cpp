#include "botao.h"
#include "posicao.h"
#include "tamanho.h"
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <SOIL.h>
#include "som.h"

extern Mix_Chunk *s_fundoJogo;

void inicializaTexturaBotoes(botoes *botao)
{
    botao[0].textura =  SOIL_load_OGL_texture(
                            "play.png",
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
    if (botao[0].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDAbotao
    botao[1].textura =  SOIL_load_OGL_texture(
                            "options.png",
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
    if (botao[1].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //TEXTURA DA SEGUNDAbotao
    botao[2].textura =  SOIL_load_OGL_texture(
                            "credits.png",
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
    if (botao[2].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    botao[3].textura =  SOIL_load_OGL_texture(
                            "exit.png",
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
    if (botao[3].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    botao[4].textura =  SOIL_load_OGL_texture(
                            "pause.png",
                            SOIL_LOAD_AUTO,
                            SOIL_CREATE_NEW_ID,
                            SOIL_FLAG_INVERT_Y
                        );
    if (botao[4].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }



}
void inicializaBotoes(botoes *botao)
{
    int i,centro,distanciaDoTopo,intervalo;

    for(i=0; i<5; i++)
    {

        botao[i].t.altura= 40;
        botao[i].t.largura= 180;
        centro = (800-botao[i].t.largura)*0.5;
        distanciaDoTopo = 100;
        intervalo = 60;
        botao[i].p.x= centro;
        botao[i].p.y= distanciaDoTopo+(i*intervalo);
    }
    botao[4].p.y = 200;

}
void desenhaBotao(botoes botao)
{

    glEnable(GL_TEXTURE_2D);//TEXTURA*********************************************************
    glEnable( GL_BLEND );
    glBindTexture(GL_TEXTURE_2D, botao.textura);//TEXTURA*********************************************************
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glTexCoord2f(0,1);
    glVertex3f(botao.p.x, botao.p.y, 0);
    glTexCoord2f(1,1);
    glVertex3f(botao.p.x + botao.t.largura, botao.p.y, 0);
    glTexCoord2f(1,0);
    glVertex3f(botao.p.x + botao.t.largura,  botao.p.y + botao.t.altura, 0);
    glTexCoord2f(0,0);
    glVertex3f(botao.p.x, botao.p.y + botao.t.altura, 0);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);//TEXTURA*********************************************************

}
void verificaClickBotao(int botaoMouse, int estado, int x, int y, botoes *botao, int *tela)
{

    if(botaoMouse== GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
    {
        int i=0;
        for(i=0; i<5; i++)
        {
            if(botao[i].p.x<= x && x <= (botao[i].p.x + botao[i].t.largura) && botao[i].p.y<= y && y <= (botao[i].p.y + botao[i].t.altura))
            {
                *tela = (i+1);

                if(*tela==4)
                {
                    exit(0);
                }
                if(i==4)
                {
                        *tela=1;
                }

            }
        }
    }
}
