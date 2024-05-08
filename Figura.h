#ifndef FIGURA_H
#define FIGURA_H

#include <fstream>
#include <string>

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

using namespace std;

typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;


typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

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
	int getFila() const { return files; };
	int getColumna() const { return columnes; };


private:
	void transposarMatriu(int matriu[][4]);
	void invertirFiles(int matriu[][4]);
	void invertirColumnes(int matriu[][4]);
	ColorFigura color;
	TipusFigura tFigura;
	int m_codiGir;
	int files, columnes;
	int matriuFigura[MAX_ALCADA][MAX_AMPLADA];
	int m_x;
	int m_y;
};

ifstream& operator>>(ifstream& input, Figura& figura);
#endif