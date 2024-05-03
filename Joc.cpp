#include "Joc.h"
#include "Tauler.h"
using namespace std;

void Joc::inicialitza(const string& nomFitxer) {

	ifstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open()) {
	fitxer >> m_figura;
	fitxer >> m_tauler;
	fitxer.close();
	}
	ColocarFigura();
	
}

void Joc::ColocarFigura()
{
    int figuraX = m_figura.getX();
    int figuraY = m_figura.getY();

    for (int i = 0; i < m_figura.getAmplada(); i++)
    {
        for (int j = 0; j < m_figura.getAltura(); j++)
        {
            if (m_figura.getMatriu(i, j) == 1)
            {
                m_tauler.setTauler(figuraX + i, figuraY + j, m_figura.getColor());
            }
        }
    }
}





void Joc::escriuTauler(const string& nomFitxer)
{

	ofstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open()) {
	fitxer << m_tauler;
	fitxer.close();
	}
}



void Joc::mouFigura(int dirX)
{
	Figura figuraActual = m_figura;
	figuraActual.MouFiguraHoritzontal(dirX);
	if (m_tauler.comprovarMov(figuraActual, figuraActual.getX(), figuraActual.getY())) 
	{
	    ColocarFigura();
		m_figura = figuraActual;
	}
}

int Joc::baixaFigura()
{
    Figura figuraActual = m_figura;

    if (m_tauler.comprovarMov(figuraActual, figuraActual.getX(), figuraActual.getY())) 
    {
        figuraActual.baixar();
        m_figura = figuraActual;
        ColocarFigura();
    }
}



void Joc::giraFigura(DireccioGir direccio)
{
	bool girCorrecte;
	Figura figuraGirada = m_figura;
	if (m_tauler.comprovarGir(figuraGirada, direccio)) {
		m_figura = figuraGirada;
		girCorrecte = true; 
	}

	girCorrecte = false;

	if (girCorrecte)
	{
		figuraGirada.girarFigura(direccio);
	}
}

void Joc::eliminaFila()
{
	for (int fila = 0; fila < MAX_FILA; ++fila) {
	bool filaPlena = true;
	for (int columna = 0; columna < MAX_COL; ++columna) {
		if (m_tauler.getTauler(fila, columna) == COLOR_NEGRE) {
			filaPlena = false;
			break;
		}
	}
	if (filaPlena) {
		m_tauler.borrarFila(fila);
	}
}
}

