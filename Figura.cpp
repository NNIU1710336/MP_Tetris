#include "Figura.h"

Figura::Figura()
{
	inicialitza(NO_FIGURA, 0, 0, 0);
}

void Figura::inicialitza(TipusFigura tipusFigura, int codiGir, int x, int y)
{
	tFigura = tipusFigura;
	m_codiGir = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matriuFigura[i][j] = 0;
		}
	}
	switch (tFigura)
	{
	case FIGURA_O:
		color = COLOR_GROC;
		m_files = 2;
		m_columnes = 2;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][0] = 1;
		matriuFigura[0][1] = 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
		break;
	case FIGURA_I:
		color = COLOR_BLAUCEL;
		m_files = 4;
		m_columnes = 4;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
		matriuFigura[1][2] = 1;
		matriuFigura[1][3] = 1;
		break;
	case FIGURA_T:
		color = COLOR_MAGENTA;
		m_files = 3;
		m_columnes = 3;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][1] = 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
		matriuFigura[1][2] = 1;
		break;
	case FIGURA_L:
		color = COLOR_TARONJA;
		m_files = 3;
		m_columnes = 3;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][2] = 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
		matriuFigura[1][2] = 1;
		break;
	case FIGURA_J:
		color = COLOR_BLAUFOSC;
		m_files = 3;
		m_columnes = 3;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][0] = 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
		matriuFigura[1][2] = 1;
		break;
	case FIGURA_Z:
		color = COLOR_VERMELL;
		m_files = 3;
		m_columnes = 3;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][0] = 1;
		matriuFigura[0][1] = 1;
		matriuFigura[1][1] = 1;
		matriuFigura[1][2] = 1;
		break;
	case FIGURA_S:
		color = COLOR_VERD;
		m_files = 3;
		m_columnes = 3;
		m_x = x - 1;
		m_y = y - 1;
		matriuFigura[0][1] = 1;
		matriuFigura[0][2] = 1;
		matriuFigura[1][0] = 1;
		matriuFigura[1][1] = 1;
	}

	for (int i = 0; i < codiGir; i++)
	{
		girarFigura(GIR_HORARI);
	}
}

void Figura::baixar()
{
	m_y++;
}

void Figura::moureFigura(int dirX)
{
	m_x += dirX;
}

void Figura::girarFigura(DireccioGir direccio)
{
	if (!direccio)
	{
		transposarMatriu(matriuFigura);
		invertirColumnes(matriuFigura);
		if (direccio != 3)
			m_codiGir++;
		else m_codiGir = 0;
	}
	else
	{
		transposarMatriu(matriuFigura);
		invertirFiles(matriuFigura);
		if (direccio != 0)
			m_codiGir--;
		else m_codiGir = 3;
	}
}


void Figura::invertirFiles(int matriu[][4])
{
	int matriuAux[4][4];
	for (int i = 0; i < m_files; i++)
	{
		for (int j = 0; j < m_columnes; j++)
		{
			matriuAux[i][j] = matriu[m_files - i - 1][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matriu[i][j] = matriuAux[i][j];
		}
	}
}

void Figura::invertirColumnes(int matriu[][4])
{
	int matriuAux[4][4];
	for (int i = 0; i < m_files; i++)
	{
		for (int j = 0; j < m_columnes; j++)
		{
			matriuAux[i][j] = matriu[i][m_columnes - j - 1];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matriu[i][j] = matriuAux[i][j];
		}
	}

}
void Figura::transposarMatriu(int matriu[][4])
{
	int matriuF[4][4];
	for (int i = 0; i < m_files; i++)
	{
		for (int j = 0; j < m_columnes; j++)
		{
			matriuF[i][j] = matriu[j][i];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matriu[i][j] = matriuF[i][j];
		}
	}
}

void Figura::dibuixaFigura() //Funció per dibuixar una figura.
{
	for (int i = 0; i < m_files; i++) //Recorrem cada posició que ocupa la figura i la pintem amb el seu color corresponent a la posició corresponent.
	{
		for (int j = 0; j < m_columnes; j++)
		{
			if (matriuFigura[i][j] != 0)
			{
				GraphicManager::getInstance()->drawSprite((IMAGE_NAME)(color + 1), //Color de la figura.
					POS_X_TAULER + ((m_x + j+1) * MIDA_QUADRAT), POS_Y_TAULER + ((m_y + i) * MIDA_QUADRAT), false);
			}

		}
	}
}

ifstream& operator>>(ifstream& input, Figura& figura)
{
	int tFigura;
	int x, y;
	int codiGir;

	input >> tFigura >> y >> x >> codiGir;
	TipusFigura f = static_cast<TipusFigura>(tFigura);
	figura.inicialitza(f, codiGir, x, y);

	return input;
}