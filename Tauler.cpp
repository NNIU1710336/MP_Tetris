#include "Tauler.h"
#include <iostream>

using namespace std;


Tauler::Tauler()
{
	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
			m_tauler[i][j] = COLOR_NEGRE;
	}
}

Tauler::Tauler(ColorFigura t[N_FILES_TAULER][N_COL_TAULER])
{
	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			m_tauler[i][j] = t[i][j];
		}
	}
}

bool Tauler::comprovarMov(const Figura& figura, int dirX) const
{
	bool moviment = true;
	int i = 0;
	int j;
	while (i < figura.getFila() and moviment)
	{
		j = 0;
		while (j < figura.getColumna() and moviment)
		{
			if (figura.getMatriu(i, j) == 1)
			{
				if (figura.getX() + j + dirX >= N_COL_TAULER or figura.getX() + j + dirX < 0)
					moviment = false;
				else if (m_tauler[figura.getY() + i][figura.getX() + j + dirX] != 0)
					moviment = false;
			}
			j++;
		}
		i++;
	}
	return moviment;
}

bool Tauler::baixarFigura(const Figura& figura) const
{
	int i = 0;
	int j = 0;
	bool noProblema = true;
	while (i < figura.getFila() && noProblema)
	{
		j = 0;
		while (j < figura.getColumna() && noProblema)
		{
			if (figura.getMatriu(i, j) != 0)
			{
				if (figura.getY() + i + 1 >= N_FILES_TAULER)
					noProblema = false;
				else if (m_tauler[figura.getY() + i + 1][figura.getX() + j] != COLOR_NEGRE)
					noProblema = false;
			}
			j++;
		}
		i++;
	}
	return noProblema;
}


int Tauler::eliminarFiles(const Figura& fColocada)
{
	bool limitTauler = false;
	int nFilesEliminar = 0;
	int i = fColocada.getY();

	while (i < fColocada.getY() + 4 and !limitTauler)
	{
		if (i < N_FILES_TAULER)
		{
			if (filaPlena(i))
			{
				nFilesEliminar++;
				borrarFila(i);
				
			} 

			
			i++;
		}
		else
			limitTauler = true;
	}
	return nFilesEliminar;
}



ifstream& operator>>(ifstream& input, Tauler& tauler)
{
	int color;
	ColorFigura c;
	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			input >> color;
			c = static_cast<ColorFigura>(color);
			tauler.setTauler(i, j, c);
		}
	}
	return input;
}

ofstream& operator<<(ofstream& output, const Tauler& tauler)
{
	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			output << tauler.getMatriu(i, j) << " ";
		}
		output << endl;
	}
	return output;
}


void Tauler::borrarFila(int fila)
{
	bool filaB = false;
	int i = fila;
	while (i > 0 and !filaB)
	{
		if (!filaBuida(i))
		{
			igualarFiles(i, i - 1);
			i--;
		}
		else
			filaB = true;
	}

	if (i == 0)
	{
		for (i = 0; i < N_COL_TAULER; i++)
			m_tauler[0][i] = COLOR_NEGRE;
	}
}

bool Tauler::filaBuida(int fila) const
{
	bool b = true;
	int i = 0;
	while (b and i < N_COL_TAULER)
	{
		if (m_tauler[fila][i] != 0)
			b = false;
		else
			i++;
	}
	return b;
}

bool Tauler::filaPlena(int fila) const
{
	bool b = true;
	int i = 0;
	while (b and i < N_COL_TAULER)
	{
		if (m_tauler[fila][i] == 0)
			b = false;
		else
			i++;
	}
	return b;
}

void Tauler::igualarFiles(int f1, int f2)
{
	for (int i = 0; i < N_COL_TAULER; i++)
		m_tauler[f1][i] = m_tauler[f2][i];
}


bool Tauler::comprovarGir(const Figura& figura, DireccioGir direccio) const
{
	Figura figuraSim = figura;

	figuraSim.girarFigura(direccio);

	int i = figuraSim.getY(), j;
	bool potGir = false;

	while (i < figuraSim.getFila() + figuraSim.getY() and !potGir)
	{
		j = figuraSim.getX();
		while (j < figuraSim.getColumna() + figuraSim.getX() and !potGir)
		{
			if (figuraSim.getMatriu(i - figuraSim.getY(), j - figuraSim.getX()) == 1)
			{
				if (i >= N_FILES_TAULER or i < 0)
					potGir = true;
				else if (j >= N_COL_TAULER or j < 0)
					potGir = true;
				else if (m_tauler[i][j] != COLOR_NEGRE)
					potGir = true;
			}
			j++;
		}
		i++;

	}

	return !potGir;

}



void Tauler::dibuixaTauler()
{
	int i = N_FILES_TAULER - 1;
	bool acabat = false;
	while (i >= 0 and !acabat)
	{
		int j = 0;
		acabat = true;
		while (j < N_COL_TAULER)
		{
			if (m_tauler[i][j] != COLOR_NEGRE)
			{
				GraphicManager::getInstance()->drawSprite(static_cast<IMAGE_NAME>(m_tauler[i][j] + 1),
					POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
				acabat = false;
			}
			j++;
		}
		i--;
	}

}



