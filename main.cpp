#include "posicao.h"
#include "tamanho.h"
#include "fundo.h"
#include "mira.h"
#include "botao.h"
#include "alvo.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <time.h>
#include <SOIL.h>
#include "som.h"
#include <SDL_mixer.h>

#define telaDoMenu 0
#define telaDeJogo 1
#define telaOpcoes 2
#define telaCreditos  3
#define telaDerrota  4
#define telaVitoria  5

extern Mix_Music *s_fundo;
extern Mix_Chunk *s_passou;
extern Mix_Chunk *s_pause;
extern Mix_Chunk *s_fundoFase1;
extern int ponto;
extern int vidasDoJogador;

int pause=-1;
int tela=telaDoMenu;
int musica=0;
int tipoDeMira=0;


int alvoInicializado;
alvo monstro[10];
mira arma[3];
fundo telaDeFundo[5];
botoes botao[5];
botoes vida[5];
botoes botoesOpcao[3];



void gerenciaClick(int botaoMouse, int estado, int x, int y)
{
    if(pause==-1)
    {
        verificaColisaoAlvo(botaoMouse, estado, x, y, monstro);
    }
    if(tela==0)
    {
        verificaClickBotao(botaoMouse, estado, x, y, botao , &tela);
    }
}
void escreveTexto(void * font, char *s, float x, float y, float z)
{
    int i;
    glRasterPos3f(x, y, z);

    for (i=0; i < strlen(s); i++)
        glutBitmapCharacter(font, s[i]);
}
void escrever(void)
{
    glColor3f (0, 0, 0);
    char p[5];
    sprintf(p, "%i", ponto);
    char v[5];
    sprintf(v, "%i", vidasDoJogador);

    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "Pontos:", 20, 500, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, p, 100, 500, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, "Vidas:", 140, 500, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, v, 220, 500, 0);
    glColor3f (1.0, 1.0, 1.0);
}

void atualiza(int indice)
{
    atualizaMira(arma);
    glutPostRedisplay();
    glutTimerFunc(17, atualiza, 0);
}

void inicializaTudo(void)
{
    inicializaFundos(telaDeFundo);
    inicializaTexturaFundo(telaDeFundo);
    inicializaMira(arma);
    inicializaTexturaMira(arma);
    inicializaAlvo(monstro);
    inicializaTexturaAlvo(monstro);
    inicializaBotoes(botao);
    inicializaTexturaBotoes(botao);
    inicializar_musicas();
    carregar_musicas();
    Mix_PlayMusic( s_fundo, -1);


}


// Rotina principal
void teclado(unsigned char key, int x, int y)
{
    switch(key)
    {
    // Tecla ESC
    case 27:
        tela = 0;
        break;
    case 'P':
    case 'p':
        Mix_PlayChannel( -1,s_pause, 0);
        pause=pause*(-1);
        break;
    case 'R':
    case 'r':
            tela = telaDoMenu;
            inicializaAlvo(monstro);
            pause = -1;
            ponto = 0;
        break;
    case ' ':
        if(pause==-1)
        {
            verificaColisaoAlvo(0, 0, x, y, monstro);
        }
        if(tela==0)
        {
            verificaClickBotao(0, 0, x, y, botao , &tela);
        }
        break;
    default:
        break;
    }
}
void redimensiona(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenhaCena()
{
    glClear(GL_COLOR_BUFFER_BIT);
    srand(GetTickCount());
    glEnable(GL_TEXTURE_2D);
    switch(tela)
    {
    // Tecla ESC
    case telaDoMenu:
        Mix_ResumeMusic();
        desenhaFundo(telaDeFundo[0]);
        desenhaBotao(botao[0]);
        desenhaBotao(botao[1]);
        desenhaBotao(botao[2]);
        desenhaBotao(botao[3]);


        break;

    case telaDeJogo:

        desenhaFundo(telaDeFundo[1]);


        if(pause==-1)
        {
            movimentaAlvo(&monstro[0]);
            Mix_ResumeMusic();
        }
        desenhaAlvos(monstro);
        escrever();
        if(pause==1)
        {
            desenhaBotao(botao[4]);
            Mix_PauseMusic();
        }
        if(vidasDoJogador < 0)
        {
            tela=telaDerrota;
        }
        if(vidasDoJogador > 5){
            vidasDoJogador--;
        }
        break;

    case telaOpcoes:
        desenhaFundo(telaDeFundo[2]);



        break;
    case telaCreditos:
        desenhaFundo(telaDeFundo[3]);


        break;

    case telaDerrota:
        desenhaFundo(telaDeFundo[4]);


        break;
    case telaVitoria:
        desenhaFundo(telaDeFundo[4]);



        break;


    default:

        break;
    }

    desenhaMira(arma[0]);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

}
int main(int argc, char **argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Mario shooter");
    inicializaTudo();
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutDisplayFunc(desenhaCena);
    glutPassiveMotionFunc(movimentoMouse);
    glutMotionFunc(movimentoMouse);
    glutMouseFunc(gerenciaClick);

    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();
    fechar_musicas();

    return 0;
}
