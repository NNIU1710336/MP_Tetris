class Tetris
{
public:
	void Menu();
	void Dificultat(int m_lvl);
	int Nivell();
	int getLvl() const& { return m_lvl; }
	int getPuntuacio() const& { return m_puntuacio; }
private:
	int m_puntuacio;
	int m_lvl;
	int m_puntuacio_nou;
	int m_velocitat;
	Partida m_joc;
};


