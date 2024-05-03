#ifndef FIGURA_H
#define FIGURA_H
#include <fstream>
#include <iostream>
using namespace std;


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
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura() : m_tipus(NO_FIGURA), m_color(NO_COLOR), m_amplada(MAX_AMPLADA),
        m_altura(MAX_ALCADA), m_fila(0), m_columna(0), m_gir(0) {};
	void inicialitza(TipusFigura tipusFigura, int Gir, int x, int y);
	void girarFigura(DireccioGir direccio);
	void MouFiguraHoritzontal(int dirX);
	void baixar();
	int getPosFigura(int fila, int columna) const { return m_Matriu[fila][columna]; }
	int getAltura() const { return m_altura; }
	int getAmplada() const { return m_amplada; }
	int getMatriu (int i, int j) const { return m_Matriu[i][j]; };
	int getFila() const { return m_fila; }
	int getColumna() const { return m_columna; }
	int getGir() const { return m_gir; }
	ColorFigura getColor() const { return m_color; }
	TipusFigura getTipus(int i, int j) const{ return m_tipus; }
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	void setFila(int fila) { m_fila = fila; };
	void setColumna(int columna) { m_columna = columna; };
	void setGir(int gir) { m_gir = gir; };
	void setTipus (TipusFigura tipus) { m_tipus = tipus; };
	void setX(int x) { m_x = x; };
	void setY(int y) { m_y = y; };

private:
	int m_Matriu[MAX_ALCADA][MAX_AMPLADA];
	int m_fila;
	int m_columna;
	int m_gir;
	TipusFigura m_tipus;
	ColorFigura m_color;
	int m_x;
	int m_y;
	int m_altura;
	int m_amplada;
};

ifstream& operator>>(ifstream& input, Figura& figura);

#endif
