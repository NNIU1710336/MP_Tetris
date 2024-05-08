#include "Joc.h"


void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		fitxer >> m_figura;
		fitxer >> m_tauler;
		fitxer.close();
	}
	afegirFigura();
}

void Joc::escriuTauler(const string& nomFitxer) const
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	fitxer << m_tauler;
	fitxer.close();
}

bool Joc::giraFigura(DireccioGir direccio)
{
	borrarFigura(m_figura.getX(), m_figura.getY());
	bool girar = m_tauler.comprovarGir(m_figura, direccio);
	if (girar)
		m_figura.girarFigura(direccio);

	afegirFigura();
	return girar;
}
bool Joc::mouFigura(int dirX)
{
	borrarFigura(m_figura.getX(), m_figura.getY());
	bool moure = m_tauler.comprovarMov(m_figura, dirX);
	if (moure)
	{
		m_figura.moureFigura(dirX);
	}
	afegirFigura();
	return moure;
}
int Joc::baixaFigura()
{
    int numFilesEliminades = 0;

    borrarFigura(m_figura.getX(), m_figura.getY());

    if (m_tauler.baixarFigura(m_figura)) {
        m_figura.baixar();
        afegirFigura();
    } else {
        afegirFigura();
        numFilesEliminades = m_tauler.eliminarFiles(m_figura);
    }

    return numFilesEliminades;
}


void Joc::borrarFigura(int x1, int y1)
{
    int filaFigura = m_figura.getFila();
    int columnaFigura = m_figura.getColumna();
    int num = 0;

    for (int i = 0; i < filaFigura && num < 4; ++i) {
        for (int j = 0; j < columnaFigura && num < 4; ++j) {
            if (m_figura.getMatriu(i, j) == 1) {
                m_tauler.setTauler(y1 + i, x1 + j, COLOR_NEGRE);
                num++;
            }
        }
    }
}

void Joc::afegirFigura()
{
    int filaFigura = m_figura.getFila();
    int columnaFigura = m_figura.getColumna();
    int num = 0;

    for (int i = 0; i < filaFigura && num < 4; ++i) {
        for (int j = 0; j < columnaFigura && num < 4; ++j) {
            if (m_figura.getMatriu(i, j) == 1) {
                m_tauler.setTauler(m_figura.getY() + i, m_figura.getX() + j, m_figura.getColor());
                num++;
            }
        }
    }
}

void Joc::actualitzarTauler(int x1, int y1)
{
	borrarFigura(x1, y1);
	afegirFigura();

}