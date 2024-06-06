#ifndef TAULER
#define TAULER

#include "Figura.h"
#include "InfoJoc.h"

class Tauler
{
public:
	Tauler();
	Tauler(ColorFigura t[N_FILES_TAULER][N_COL_TAULER]);
	int eliminarFiles(const Figura& figura);
	bool baixarFigura(const Figura& figura) const;
	void setTauler(int fila, int col, ColorFigura color) { m_tauler[fila][col] = color; };
	ColorFigura getMatriu(int fila, int col) const { return m_tauler[fila][col]; };
	bool comprovarGir(const Figura& figura, DireccioGir direccio) const;
	bool comprovarMov(const Figura& figura, int dirX) const;
	void dibuixaTauler();

private:
	ColorFigura m_tauler[N_FILES_TAULER][N_COL_TAULER];
	void borrarFila(int fila);
	bool filaBuida(int fila) const;
	bool filaPlena(int fila) const;
	void igualarFiles(int f1, int f2);
};

ifstream& operator>>(ifstream& input, Tauler& tauler);
ofstream& operator<<(ofstream& output, const Tauler& tauler);
#endif