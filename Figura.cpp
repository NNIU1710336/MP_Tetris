#include "Figura.h"
#include <iostream>
using namespace std;

void Figura::inicialitza(TipusFigura tipus, int y, int x, int gir)
{
    m_tipus = tipus;
    m_x = x;
    m_y = y;
    
    for (int i = 0; i < MAX_ALCADA; i++)
        for (int j = 0; j < MAX_AMPLADA; j++)
            m_Matriu[i][j] = 0;

    switch (m_tipus) 
    {
    case TipusFigura::FIGURA_O:
        m_color = COLOR_GROC;
        m_fila = 2;
        m_columna = 2;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][0] = 1;
        m_Matriu[0][1] = 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
        break;

    case TipusFigura::FIGURA_L:
    {
        m_color = COLOR_TARONJA;
        m_fila = 3;
        m_columna = 3;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][2] = 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
        m_Matriu[1][2] = 1;
    }
    break;

    case TipusFigura::FIGURA_T:
    {
        m_color = COLOR_MAGENTA;
        m_fila = 3;
        m_columna = 3;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][1] = 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
        m_Matriu[1][2] = 1;
    }
    break;

    case TipusFigura::FIGURA_S:

    {
        m_color = COLOR_VERD;
        m_fila = 3;
        m_columna = 3;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][1] = 1;
        m_Matriu[0][2] = 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
    }

    break;

    case TipusFigura::FIGURA_Z:
    {
        m_color = COLOR_VERMELL;
        m_fila = 3;
        m_columna = 3;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][0] = 1;
        m_Matriu[0][1] = 1;
        m_Matriu[1][1] = 1;
        m_Matriu[1][2] = 1;
    }

    break;

    case TipusFigura::FIGURA_I:

    {
        m_color = COLOR_BLAUCEL;
        m_fila = 4;
        m_columna = 4;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
        m_Matriu[1][2] = 1;
        m_Matriu[1][3] = 1;
    }
    break;
    case TipusFigura::FIGURA_J:
    {
        m_color = COLOR_BLAUFOSC;
        m_fila = 3;
        m_columna = 3;
        m_x = x - 1;
        m_y = y - 1;
        m_Matriu[0][0] = 1;
        m_Matriu[1][0] = 1;
        m_Matriu[1][1] = 1;
        m_Matriu[1][2] = 1;
    }
    break;
    }

    for (int i = 0; i < gir; i++)
    {
        girarFigura(GIR_HORARI);
    }
}


ifstream& operator>>(ifstream& input, Figura& figura)
{
    int tipus;
    int fila, columna;
    int gir;

    input >> tipus >> fila >> columna >> gir;
    TipusFigura m_tipus = static_cast<TipusFigura>(tipus);
    figura.inicialitza(m_tipus, fila, columna, gir);

    return input;
}

void Figura::MouFiguraHoritzontal(int dirX)
{
	m_columna += dirX;
}

void Figura::baixar()
{
	m_y += 1;
}

void Figura::girarFigura(DireccioGir direccio)
{
    int novaMatriu[MAX_AMPLADA][MAX_ALCADA];
if (direccio == GIR_HORARI)
{
    for (int i = 0; i < m_altura; ++i) {
        for (int j = 0; j < m_amplada; ++j) {
            novaMatriu[j][m_altura - 1 - i] = m_Matriu[i][j];
        }
    }

    for (int i = 0; i < m_amplada; ++i) 
    {
        for (int j = 0; j < m_altura; ++j) 
        {
            m_Matriu[i][j] = novaMatriu[i][j + 1];
        }
    }

    swap(m_altura, m_amplada);
}
else
{
    for (int i = 0; i < 3; i++)
    {
        girarFigura(GIR_HORARI);
    }
}
}
