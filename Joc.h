#ifndef JOC_H
#define JOC_H

#include "Tauler.h"
#include <cstdlib>
#include <time.h>


class Joc
{
public:
	Joc() { srand(time(NULL)); gameOver = false; }
	bool PucBaixar();
	void IniInicial(const string& fitxerInicial);
	void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	void generarFigura();
	void baixaFigura();
	bool colocarFigura();
	void escriuTauler(const string& nomFitxer) const;
	void actualitza(double deltaTime);
	void dibuixa();
	bool getgameOver() const {return gameOver ;}
	int getFilEliminades() { return m_files_eleiminades; }
	int figuraColocada();


private:
	void actualitzarTauler(int x1, int y1);
	void borrarFigura(int x1, int y1);
	void afegirFigura();
	bool gameOver;
	Tauler m_tauler;
	Figura m_figura;
	int m_files_eleiminades;
	int m_puntuacio;

};



#endif