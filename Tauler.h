#ifndef TAULER
#define TAULER

#include "Figura.h"
#define MAX_COL 8
#define MAX_FILA 8
class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura t[MAX_FILA][MAX_COL]);
	int eliminarFiles(const Figura& figura);
	bool baixarFigura(const Figura& figura) const;
	void setTauler(int fila, int col, ColorFigura color) { m_tauler[fila][col] = color; };
	ColorFigura getMatriu(int fila, int col) const { return m_tauler[fila][col]; };
	bool comprovarGir(const Figura& figura, DireccioGir direccio) const;
	bool comprovarMov(const Figura& figura, int dirX) const;

private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];
	void borrarFila(int fila);
	bool filaBuida(int fila) const;
	bool filaPlena(int fila) const;
	void igualarFiles(int f1, int f2);
};

ifstream& operator>>(ifstream& input, Tauler& tauler);
ofstream& operator<<(ofstream& output, const Tauler& tauler);
#endif