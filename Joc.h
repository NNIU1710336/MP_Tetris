#ifndef JOC_H
#define JOC_H

#include "Tauler.h"


class Joc
{
public:
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer) const;

private:
	void actualitzarTauler(int x1, int y1);
	void borrarFigura(int x1, int y1);
	void afegirFigura();
	Tauler m_tauler;
	Figura m_figura;

};



#endif