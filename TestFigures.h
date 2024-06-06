#ifndef TESTFIGURA_H
#endif TESTFIGURA_H

#include "Joc.h"
#include "InfoJoc.h"

class TestFigures
{
private:
	TipusFigura m_figures;
	int m_fil;
	int m_col;
	int m_gir;
	TestFigures* m_seguent;

public:
	TestFigures() { m_figures = NO_FIGURA; m_fil = 0; m_col = 0; m_gir = 0; m_seguent = nullptr; }
	TestFigures(const TipusFigura& figura, int fila, int columna, int gir) { m_figures = figura; m_fil = fila; m_col = columna; m_gir = gir; m_seguent = nullptr; }
	TipusFigura getFigura() const { return m_figures; }
	int getFila() const { return m_fil; }
	int getColumna() const { return m_col; }
	int getGir() const { return m_gir; }
	TestFigures* getSeguent() const { return m_seguent; }
	void setSeguent(TestFigures* seguent) { m_seguent = seguent; }
};