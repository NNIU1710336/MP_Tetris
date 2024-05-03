#include "Tauler.h"
#include <fstream>
#include <iostream>
using namespace std;


ifstream& operator>>(ifstream& input, Tauler& tauler) {
    int color;
    ColorFigura c;
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            input >> color;
            c = static_cast<ColorFigura>(color);
            tauler.setTauler(i, j, c);
        }
    }
    return input;
}


ofstream& operator<<(ofstream& output, const Tauler tauler)
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            output << tauler.getTauler(i,j) << " ";
        }
        output << endl;
    }
    return output;
}


Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = COLOR_NEGRE;
        }
    }
}


void Tauler::borrarFila(int fila)
{
    for (int i = fila; i > 0; --i) {
        for (int j = 0; j < MAX_FILA; ++j) {
            m_tauler[i][j] = m_tauler[i - 1][j];
        }
    }
    for (int j = 0; j < MAX_COL; ++j) {
        m_tauler[0][j] = COLOR_NEGRE;
    }
}

bool Tauler::filaBuida(int fila) const
{
    for (int j = 0; j < MAX_COL; ++j) {
        if (m_tauler[fila][j] != COLOR_NEGRE) {
            return false;
        }
    }
    return true;
}

bool Tauler::filaPlena(int fila) const
{
    for (int j = 0; j < MAX_COL; ++j) {
        if (m_tauler[fila][j] == COLOR_NEGRE) {
            return false;
        }
    }
    return true;
}

void Tauler::igualarFiles(int f1, int f2)
{
    for (int j = 0; j < MAX_COL; ++j) {
        m_tauler[f1][j] = m_tauler[f2][j];
    }
}

bool Tauler::comprovarGir(const Figura& figura, DireccioGir direccio) const
{
    Figura figuraSimulada = figura;
    figuraSimulada.girarFigura(direccio);

int PosX = figuraSimulada.getX();
int PosY = figuraSimulada.getY();

figuraSimulada.girarFigura(direccio);
    for (int i = 0; i < MAX_ALCADA; ++i) 
    {
        for (int j = 0; j < MAX_AMPLADA; ++j) 
        {
            int novaPosX = PosX + i;
            int novaPosY = PosY + j;
                if (novaPosX < 0 ||novaPosX > MAX_COL || novaPosY < 0 ||novaPosY > MAX_FILA)
                {
                    return false;
                }
            
            if (m_tauler[novaPosX][novaPosY] != COLOR_NEGRE) {
                    return false;
                }
            }
        }
        return true;
    }

bool Tauler::comprovarMov(const Figura& figura, int x, int y) const
{
    bool mov = true;
    int i = 0;
    while (i <figura.getAltura() && mov)
    {
        int j = 0;
        while (j < figura.getAmplada() && mov)
        {
            if (figura.getPosFigura(i, j) != COLOR_NEGRE)
                if (x + j >= MAX_COL || x + j < 0 || y + i < 0 || y + i >= MAX_COL || m_tauler[y + i][x+j] != COLOR_NEGRE)
                mov = false;
                j++;
        }
        i++;
    }
    
    return mov;
}


int Tauler::eliminarFiles(const Figura& figura)
{
    int numFilesEliminades = 0;
    for (int fila = 0; fila < MAX_FILA; fila++) {
        if (filaPlena(fila)) {
            borrarFila(fila);
            igualarFiles(fila, fila - 1);
            ++numFilesEliminades;
        }
    }
    return numFilesEliminades;
}

