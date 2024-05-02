#include "Joc.h"
#include "Tauler.h"
using namespace std;


void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer.c_str());
    int tipus, fila, columna, gir, color;

    if (!fitxer.is_open()) {
        cerr << "Error: No es pot obrir el fitxer " << nomFitxer << endl;
        return;
    }

    fitxer >> tipus >> fila >> columna >> gir;
    while (!fitxer.eof()) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                ColorFigura colorFigura;
                fitxer >> color;
                colorFigura = static_cast<ColorFigura>(color);
                m_tauler.setTauler(i, j, colorFigura); 
            }
        }
    }

    fitxer.close();
}




void Joc::AfegeixFitxa()
{
    m_tauler.setTauler(3, 1, COLOR_MAGENTA); 
    m_tauler.setTauler(3, 2, COLOR_MAGENTA);
    m_tauler.setTauler(3, 3, COLOR_MAGENTA);
    m_tauler.setTauler(4, 2, COLOR_MAGENTA);
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer(nomFitxer);
    if (!fitxer.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    AfegeixFitxa();

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            fitxer << m_tauler.getTauler(i,j);
        }
        fitxer << endl;
    }

    fitxer.close();
}

void Joc::ColocarFigura()
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < m_figura.getAltura() && k < 4)
	{
		while (j < m_figura.getAmplada() && k < 4)
		{
			if (m_figura.getTipus(i, j))
			{
				m_tauler.setTauler(m_figura.getX() + i, m_figura.getY() + j, m_figura.getColor());
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void Joc::mouFigura(int dirX)
{
	Figura figuraActual = m_figura;
	figuraActual.MouFiguraHoritzontal(dirX);
	if (m_tauler.comprovarMov(figuraActual, dirX, figuraActual.getX(), figuraActual.getY())) {
		m_figura = figuraActual;
	}
}

int Joc::baixaFigura()
{
    Figura figuraActual = m_figura;

    if (m_tauler.comprovarMov(figuraActual, 0, figuraActual.getX(), figuraActual.getY())) 
    {
        figuraActual.baixar();
        m_figura = figuraActual;
        return 1;
    }
    else {
        ColocarFigura();
        return 0;
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

