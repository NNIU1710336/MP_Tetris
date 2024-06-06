#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include "Joc.h"
#include <iostream>
#include "Partida.h"
#include "Tetris.h"
#include "InfoJoc.h"
using namespace std;





void Tetris::Dificultat(int m_lvl)
{
    // Fórmula logarítmica para la velocidad de caída
    // La velocidad base es 1000 ms, y disminuye a medida que aumenta el nivel.
    // La fórmula logarítmica hace que los cambios sean más suaves en niveles más altos.

        if (m_lvl >= 1) 
        {
            m_velocitat = static_cast<int>(1000 / (1 + log(m_lvl)));
        }
}

int Tetris::Nivell()
{
    int punts = m_puntuacio_nou / 1000 + 1;
    if (punts >= m_puntuacio)
    {
        m_lvl =+ 1;
        m_puntuacio = m_puntuacio_nou;
    }
    return m_lvl;
}


