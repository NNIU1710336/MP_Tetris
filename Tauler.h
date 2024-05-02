#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	void setTauler(int fila, int columna, ColorFigura valor) {
		if (fila >= 0 && fila < MAX_FILA && columna >= 0 && columna < MAX_COL)
		{
			m_tauler[fila][columna] = valor;
		}
	}
	int eliminarFiles(const Figura& figura);
	bool comprovarGir(const Figura& figura, DireccioGir direccion) const;
	bool comprovarMov(const Figura& figura, int dirX, int x, int y) const;
	void borrarFila(int fila);
	bool filaBuida(int fila) const;
	bool filaPlena(int fila) const;
	void igualarFiles(int f1, int f2);
	ColorFigura getTauler(int i, int j) const { return m_tauler[i][j]; };
private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];
}

ifstream& operator>>(ifstream& input, Tauler& tauler);

ostream& operator<<(ostream& output, const Tauler tauler);


#endif
