//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include "Tetris.h"
#include "Partida.h"

int main(int argc, const char* argv[])
{
    do {
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    //Mostrem la finestra grafica
    pantalla.show();

    Partida game;
    

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    int x = 0;
    
        cout << "1. Jugar en mode normal" << endl;
        cout << "2. Juga en mode test" << endl;
        cout << "3. Llista de puntuacions" << endl;
        cout << "4. Sortir" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            game.inicialitza(1, "a", "a", "e");
            game.setPuntuacio(0);
            game.setNivell(1);
            do
            {
                LAST = NOW;
                NOW = SDL_GetPerformanceCounter();
                deltaTime = (0.001/game.getNivell());

                // Captura tots els events de ratolí i teclat de l'ultim cicle
                pantalla.processEvents();

                game.actualitza(deltaTime);
                game.Nivell();

                // Actualitza la pantalla
                pantalla.update();

                if (game.getgameOver())
                {
                    while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
                    {


                        GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
                        string missatge = "GAME OVER";
                        string missatge2 = "Ben Jugat";
                        string missatge3 = "Puntuacio: " + to_string(game.getPuntuacio());
                        GraphicManager::getInstance()->drawFont(FONT_GREEN_30, POS_X_TAULER, POS_Y_TAULER + 130, 2.0, missatge);
                        GraphicManager::getInstance()->drawFont(FONT_GREEN_30, POS_X_TAULER + 100, POS_Y_TAULER + 200, 1.0, missatge2);
                        GraphicManager::getInstance()->drawFont(FONT_GREEN_30, POS_X_TAULER + 30, POS_Y_TAULER + 240, 1.0, missatge3);
                        
                        pantalla.update();
                    }
                }

            } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !game.getgameOver());
            break;

        case 2:
            do
            {
                game.inicialitza(0, "fitxerInicial", "fitxerFigures", "fitxerMoviments");
                pantalla.update();
            } while ((!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && !game.getgameOver()));
            break;

        case 3:
            break;

        case 4:
            Keyboard_GetKeyTrg(KEYBOARD_ESCAPE);
            break;
        }
    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
    
    // Sortim del bucle si pressionem ESC

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();
    return 0;
}

