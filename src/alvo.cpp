#include "alvo.h"
#include "posicao.h"
#include "tamanho.h"
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <SOIL.h>
#include <SDL_mixer.h>
int ponto = 0;
int vidasDoJogador = 5;
int tamanhoDosAlvos=46;
int corDourada = 0;

clock_t tempo1;
clock_t tempo2;
clock_t tempo3;

extern Mix_Chunk *s_click;
extern Mix_Chunk *s_acerto;
extern Mix_Chunk *s_acertoVida;
extern Mix_Chunk *s_acertoVermelho;
void inicializaTexturaAlvo(alvo *monstro)
{
    int i;
    for(i=0; i<10; i++)
    {
        monstro[i].textura =  SOIL_load_OGL_texture(
                                  "cogumeloGreen.png",
                                  SOIL_LOAD_AUTO,
                                  SOIL_CREATE_NEW_ID,
                                  SOIL_FLAG_INVERT_Y
                              );
        if (monstro[i].textura == 0)
        {
            printf("Erro do SOIL: '%s'\n", SOIL_last_result());
        }
    }

    //MONSTRO 2

    monstro[1].textura =  SOIL_load_OGL_texture(
                              "cogumeloRed.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[1].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    //MONSTRO 3

    monstro[2].textura =  SOIL_load_OGL_texture(
                              "cogumeloGold.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[2].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }


    //MONSTRO 4
    monstro[3].textura =  SOIL_load_OGL_texture(
                              "folha.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[3].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    //MONSTRO 5
    monstro[4].textura =  SOIL_load_OGL_texture(
                              "dentuco.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[4].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }


    //MONSTRO 6
    monstro[5].textura =  SOIL_load_OGL_texture(
                              "estrela.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[5].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }


    //MONSTRO 7
    monstro[6].textura =  SOIL_load_OGL_texture(
                              "koopa.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[6].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }


    //MONSTRO 8
    monstro[7].textura =  SOIL_load_OGL_texture(
                              "nuvem.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[7].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    //MONSTRO 9
    monstro[8].textura =  SOIL_load_OGL_texture(
                              "bomba.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[8].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    //MONSTRO 10
    monstro[9].textura =  SOIL_load_OGL_texture(
                              "A.png",
                              SOIL_LOAD_AUTO,
                              SOIL_CREATE_NEW_ID,
                              SOIL_FLAG_INVERT_Y
                          );
    if (monstro[9].textura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

}
void inicializaAlvo(alvo *monstro)
{
    int i,j=0;
    for(i=0; i<10; i++)
    {
        monstro[i].p.x= -80;
        monstro[i].p.y=j;
        monstro[i].t.altura=tamanhoDosAlvos;
        monstro[i].t.largura=tamanhoDosAlvos;
        monstro[i].velocidade = (rand()%4+1);
        monstro[i].vidas = 1;
        monstro[i].identificador =-1;
        j=j+50;
        vidasDoJogador = 5;
    }


}

void desenhaAlvo(alvo monstro)
{

    glEnable(GL_TEXTURE_2D);//TEXTURA*********************************************************
    glEnable( GL_BLEND );
    glBindTexture(GL_TEXTURE_2D, monstro.textura);//TEXTURA*********************************************************
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glTexCoord2f(1,1);
    glVertex3f(monstro.p.x, monstro.p.y, 0);
    glTexCoord2f(0,1);
    glVertex3f(monstro.p.x + monstro.t.largura, monstro.p.y, 0);
    glTexCoord2f(0,0);
    glVertex3f(monstro.p.x + monstro.t.largura,  monstro.p.y + monstro.t.altura, 0);
    glTexCoord2f(1,0);
    glVertex3f(monstro.p.x, monstro.p.y + monstro.t.altura, 0);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);//TEXTURA*********************************************************

}
void desenhaAlvos(alvo *monstro)
{
    int i;

    for(i=0; i<10; i++)
    {
        glColor3f(1, 1, 1);
        desenhaAlvo(monstro[i]);
    }
    tempo2= time(0);

    if((tempo2-tempo1)==4)
    {
        tamanhoDosAlvos = 46;
    }
    if((tempo2-tempo3)==5)
    {

        //glColor3f(1,1,1);
    }




}
void verificaColisaoAlvo(int botao, int estado, int x, int y, alvo *monstro)
{

    if(botao== GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
    {
        int i=0;
        for(i=0; i<10; i++)
        {
            if(monstro[i].p.x<= x && x <= (monstro[i].p.x + monstro[i].t.largura) && monstro[i].p.y<= y && y <= (monstro[i].p.y + monstro[i].t.altura))
            {
                Mix_PlayChannel( -1,s_acerto, 0);
                monstro[i].vidas--;
                if(monstro[i].vidas==0)
                {

                    monstro[i].p.x = -200*(rand()%2+1);
                    monstro[i].velocidade = (rand()%3+3);
                    monstro[i].vidas=+1;
                    ponto++;
                    if(i==0)
                    {

                        monstro[i].p.x = -1000*(rand()%4+1);

                        vidasDoJogador++;
                    }
                    if(i==1)
                    {
                        monstro[i].p.x = -1000*(rand()%4+1);
                        Mix_PlayChannel( -1,s_acertoVermelho, 0);
                        tamanhoDosAlvos=62;
                        tempo1 = time(0);

                    }

                    if(i==2){
                        //glColor3f(0.87,0.65,0.137);
                        monstro[i].p.x = -1000*(rand()%4+1);
                        tempo3 = time(0);
                        ponto=ponto+5;
                    }
                }

            }
            else
                Mix_PlayChannel( -1,s_click, 0);
        }
    }
}




void movimentaAlvo(alvo *monstro)
{

    int i;
    for(i=0; i<10; i++)
    {
        monstro[i].p.x += monstro[i].velocidade;
        monstro[i].t.altura = tamanhoDosAlvos;
        monstro[i].t.largura = tamanhoDosAlvos;
        if(monstro[i].p.x > 800 )
        {
            monstro[i].p.y = 50*(rand()%9);
            monstro[i].p.x = -200*(rand()%4+1);
            monstro[i].velocidade = (rand()%4+1);
            monstro[i].vidas = 1;
            vidasDoJogador--;
            if(i==0)
            {
                monstro[i].p.x = -700*(rand()%4+1);
            }
            if(i==1)
            {
                monstro[i].p.x = -700*(rand()%4+1);
            }
            if(i==2)
            {
                monstro[i].p.x = -700*(rand()%4+1);
            }
        }

        if(monstro[i].p.y >= 430 || monstro[i].identificador==1)
        {
            monstro[i].p.y-=monstro[i].velocidade;

            if(monstro[i].p.y <= 0)
            {
                monstro[i].identificador=-1;
                monstro[i].velocidade = (rand()%4+1);
            }
        }

        if(monstro[i].p.y <= 0 || monstro[i].identificador==-1)
        {
            monstro[i].p.y+=monstro[i].velocidade;
            if(monstro[i].p.y >= 430)
            {
                monstro[i].identificador=1;
                monstro[i].velocidade = (rand()%4+1);
            }
        }
    }

}
//VIDA É O PRIMEIRO COGUMELO

