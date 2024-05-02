#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

class Joc
{
public:
    void setTauler(const Tauler& tauler) { m_tauler = tauler; }
	void setFigura(const Figura& figura) { m_figura = figura; } 
	
	void AfegeixFitxa();
	void eliminaFila();
	void inicialitza(const string& nomFitxer);
	void giraFigura(DireccioGir direccio);
	void mouFigura(int dirX);
	int baixaFigura();
	void ColocarFigura();
	void escriuTauler(const string& nomFitxer);
private:
	Tauler m_tauler;
	Figura m_figura;
};

#endif