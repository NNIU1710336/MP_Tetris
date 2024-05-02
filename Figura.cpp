#include "Figura.h"
#include <iostream>
using namespace std;

void Figura::inicialitza(TipusFigura tipusFigura, int Gir, int x, int y)
{
	m_tipus = tipusFigura;
	m_x = x;
	m_y = y;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matriu[i][j] = 0;
		}
	}
	switch (m_tipus)
	{
	case TipusFigura::FIGURA_T:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][1] = 1;
		m_Matriu[1][1] = 1;
		m_Matriu[1][2] = 1;
		m_Matriu[1][3] = 1;
		break;

	case TipusFigura::FIGURA_O:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][0] = 1;
		m_Matriu[0][1] = 1;
		m_Matriu[1][0] = 1;
		m_Matriu[1][1] = 1;
		break;

	case TipusFigura::FIGURA_S:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][1] = 1;
		m_Matriu[0][2] = 1;
		m_Matriu[1][0] = 1;
		m_Matriu[1][1] = 1;
		break;

	case TipusFigura::FIGURA_Z:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][0] = 1;
		m_Matriu[0][1] = 1;
		m_Matriu[1][1] = 1;
		m_Matriu[3][1] = 1;
		break;

	case TipusFigura::FIGURA_I:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[1][0] = 1;
		m_Matriu[1][1] = 1;
		m_Matriu[1][2] = 1;
		m_Matriu[1][3] = 1;
		break;

	case TipusFigura::FIGURA_L:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][2] = 1;
		m_Matriu[1][0] = 1;
		m_Matriu[1][1] = 1;
		m_Matriu[1][2] = 1;
		break;

	case TipusFigura::FIGURA_J:
		m_altura = 3;
		m_amplada = 3;
		m_x = x - 1;
		m_y = y - 1;
		m_color = COLOR_MAGENTA;
		m_Matriu[0][0] = 1;
		m_Matriu[1][0] = 1;
		m_Matriu[1][1] = 1;
		m_Matriu[1][2] = 1;
		break;
	}

	for (int i = 0; i < Gir; i++)
	{
		girarFigura(GIR_HORARI);
	}
}



void Figura::MouFiguraHoritzontal(int dirX)
{
	m_columna += dirX;
}

void Figura::baixar()
{
	m_fila++;
}

void Figura::girarFigura(DireccioGir direccion)
{
	if (direccion == GIR_HORARI) {
		int nuevaMatriu[MAX_ALCADA][MAX_AMPLADA];
		for (int i = 0; i < m_altura; ++i) {
			for (int j = 0; j < m_amplada; ++j) {
				nuevaMatriu[j][m_altura - 1 - i] = m_Matriu[i][j];
			}
		}
		for (int i = 0; i < m_amplada; ++i) {
			for (int j = 0; j < m_altura; ++j) {
				m_Matriu[i][j] = nuevaMatriu[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 3; ++i) {
			girarFigura(GIR_HORARI);
		}
	}
}
