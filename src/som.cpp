#include "som.h"
#include <SDL.h>
#include <SDL_mixer.h>

Mix_Music *s_fundo;
Mix_Chunk *s_pause;
Mix_Chunk *s_fundoFase1;
Mix_Chunk *s_click;
Mix_Chunk *s_acerto;
Mix_Chunk *s_passou;
Mix_Chunk *s_acertoVida;
Mix_Chunk *s_acertoVermelho;

bool inicializar_musicas()
{
    bool success = true;
    SDL_Init(SDL_INIT_AUDIO );
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    return success;
}

bool carregar_musicas()
{
    bool success = true;
    s_fundo = Mix_LoadMUS( "fundo.wav" );
    s_pause = Mix_LoadWAV( "pause.wav");
    s_fundoFase1 = Mix_LoadWAV( "fundoFase1.wav");
    s_click = Mix_LoadWAV( "click.wav" );
    s_acerto = Mix_LoadWAV( "acerto.wav" );
    s_passou = Mix_LoadWAV( "passou.wav" );
    s_acertoVida = Mix_LoadWAV( "vida.wav" );
    s_acertoVermelho = Mix_LoadWAV( "scale.wav" );
    return success;
}


void fechar_musicas()
{
    Mix_FreeMusic( s_fundo );
    Mix_FreeChunk( s_pause );
    Mix_FreeChunk(s_fundoFase1 );
    Mix_FreeChunk( s_click );
    Mix_FreeChunk( s_acerto );
    Mix_FreeChunk( s_passou );
    Mix_FreeChunk( s_acertoVida );
    Mix_FreeChunk( s_acertoVermelho );

    s_fundo = NULL;
    s_pause = NULL;
    s_fundoFase1 = NULL;
    s_click = NULL;
    s_acerto = NULL;
    s_passou = NULL;
    s_acertoVida = NULL;
    s_acertoVermelho = NULL;
    Mix_Quit();
    SDL_Quit();
}
