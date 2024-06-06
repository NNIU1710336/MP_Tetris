#include "Joc.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
#include "Partida.h"
#include "Moviment.h"
#include "Cua.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void Joc::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    gameOver = false;
    if (mode)
    {
        for (int i = 0; i < N_FILES_TAULER; i++)
        {
            for (int j = 0; j < N_COL_TAULER; j++)
            {
                m_tauler.setTauler(i, j, COLOR_NEGRE);
            }
        }
        generarFigura();
    }
}
void Joc::IniInicial(const string& fitxerInicial)
{
    
        ifstream fitxer;
        fitxer.open(fitxerInicial);
        if (fitxer.is_open())
        {
            fitxer >> m_figura;
            fitxer >> m_tauler;
            fitxer.close();
        }
    
}




void Joc::generarFigura()
{
    int figura = rand() % 7 + 1;
    int posX = rand() % 7 + 2;
    int gir = rand() % 4;
    TipusFigura f = static_cast<TipusFigura>(figura);
    m_figura.inicialitza(f, gir, posX, 1);

    if (!m_tauler.baixarFigura(m_figura))
    {
        gameOver = true;
    }
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

	bool girar = m_tauler.comprovarGir(m_figura, direccio);
	if (girar)
		m_figura.girarFigura(direccio);

	return girar;
}
bool Joc::mouFigura(int dirX)
{
	
	bool moure = m_tauler.comprovarMov(m_figura, dirX);
	if (moure)
	{
		m_figura.moureFigura(dirX);
	}
	return moure;
}

int Joc::figuraColocada()
{
    int numFilesEliminades = 0;
    afegirFigura();
    numFilesEliminades = m_tauler.eliminarFiles(m_figura);
    generarFigura();
    

    return numFilesEliminades;


}

bool Joc::PucBaixar()
{
    bool baixar = m_tauler.baixarFigura(m_figura);
    if (baixar)
    {
        return true;
    }
    return false;
}

void Joc::baixaFigura()
{
    if (m_tauler.baixarFigura(m_figura)) {
        m_figura.baixar();

    }
    else {
        m_files_eleiminades = figuraColocada();
    }
}

bool Joc::colocarFigura()
{
    while (m_tauler.baixarFigura(m_figura))
    {
        m_figura.baixar();
    }
    m_files_eleiminades = figuraColocada();
   return true;
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



void Joc::actualitza(double deltaTime)
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
}

void Joc::dibuixa()
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
    m_tauler.dibuixaTauler();
    m_figura.dibuixaFigura();
}