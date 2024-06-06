#ifndef FIGURA_H
#define FIGURA_H

#include <fstream>
#include <string>
#include "InfoJoc.h"
#include "GraphicManager.h"

class Figura
{
public:
	Figura();
	void inicialitza(TipusFigura tipusFigura, int codiGir, int x, int y);
	void girarFigura(DireccioGir direccio);
	void moureFigura(int dirX);
	void baixar();
	int getMatriu(int i, int j) const { return matriuFigura[i][j]; };
	int getCodiGir() const { return m_codiGir; };
	TipusFigura getTipus() const { return tFigura; };
	int getX() const { return m_x; };
	int getY() const { return m_y; };
	ColorFigura getColor() const { return color; };
	int getFila() const { return m_files; };
	int getColumna() const { return m_columnes; };
	void dibuixaFigura();


private:
	void transposarMatriu(int matriu[][4]);
	void invertirFiles(int matriu[][4]);
	void invertirColumnes(int matriu[][4]);
	ColorFigura color;
	TipusFigura tFigura;
	int m_codiGir;
	int m_files, m_columnes;
	int matriuFigura[MAX_ALCADA][MAX_AMPLADA];
	int m_x;
	int m_y;
};

ifstream& operator>>(ifstream& input, Figura& figura);
#endif