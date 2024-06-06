#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "Joc.h"
#include "InfoJoc.h"

using namespace std;

class Partida 
{
public:
    Partida();
    void Nivell();
    void Puntuacio();
    void setPuntuacio(const int puntuacio) { m_puntuacio = puntuacio; }
    void setNivell(const int nivell) { m_nivell = nivell; }
    int getNivell() const  { return m_nivell; }
    void actualitza(double deltaTime);
    int getPuntuacio() const { return m_puntuacio; }
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFiugres, const string& fitxerMoviments);
    bool getgameOver() const { return m_joc.getgameOver(); }
    double getTemps() const { return m_temps; }
private:
    int m_puntuacio;
    int m_nivell;
    int m_dificultat;
    double m_temps;
    // Atributs necessaris només pels exemples d'utilització de la llibreria. 
    // S'hauran d'eliminar per la implementació del projecte
    static const int MIDA = 4;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna;
    Joc m_joc;
};

#endif 
