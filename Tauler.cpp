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


ostream& operator<<(ostream& output, const Tauler tauler)
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

    int altura = figuraSimulada.getAltura();
    int amplada = figuraSimulada.getAmplada();
    int fila = figuraSimulada.getFila();
    int columna = figuraSimulada.getColumna();

    if (columna < 0 || columna + amplada > MAX_COL || fila + altura > MAX_FILA) {
        return false;
    }

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < amplada; ++j) {
            if (m_tauler[i][j] != COLOR_NEGRE) {
                if (m_tauler[fila + i][columna + j] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}


bool Tauler::comprovarMov(const Figura& figura, int dirX, int x, int y) const
{
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            if (figura.getMatriu(i, j) != 0)
            {
                int ValX = x + j;
                int ValY = y + i;
                if (ValX < 0 || ValX >= 8 || ValY < 0 || ValY >= 8 || m_tauler[i][j] != 0)
                {
                    return false;
                }
            }
        }

        return true;
    }
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

