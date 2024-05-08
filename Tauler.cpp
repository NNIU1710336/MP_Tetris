#include "Tauler.h"

using namespace std;


Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
			m_tauler[i][j] = COLOR_NEGRE;
	}
}

Tauler::Tauler(ColorFigura t[MAX_FILA][MAX_COL])
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
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
				if (figura.getX() + j + dirX >= MAX_COL or figura.getX() + j + dirX < 0)
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
				if (figura.getY() + i >= MAX_FILA)
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
		if (i <= MAX_FILA)
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
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
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
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
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
		for (i = 0; i < MAX_COL; i++)
			m_tauler[0][i] = COLOR_NEGRE;
	}
}

bool Tauler::filaBuida(int fila) const
{
	bool b = true;
	int i = 0;
	while (b and i < MAX_COL)
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
	while (b and i < MAX_COL)
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
	for (int i = 0; i < MAX_COL; i++)
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
				if (i >= MAX_FILA or i < 0)
					potGir = true;
				else if (j >= MAX_COL or j < 0)
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
