#ifndef CHORA_H
#define CHORA_H
#include<cstdio>
#include<iostream>
using namespace std;

class CHora
{
private:
	int m_nHoras; // AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos; // AM/PM/24 HORAS: 0 a 59
	int m_nSegundos; // AM/PM/24 HORAS: 0 a 59
	string m_pszFormato; //almacena los valores "AM", "PM" o "24 HORAS"
	bool AsignarFormato(string pszFormato);
	bool Formato24() const;
public:
	CHora(int hh = 0, int mm = 0, int ss = 0, string ff = "24 HORAS");
	CHora(const CHora& hora);
	~CHora();
	CHora& operator=(const CHora& hora);
	bool EsHoraCorrecta() const;
	void Iniciar();
	bool AsignarHora(int nHoras,int nMinutos,int nSegundos,string pszFormato);
	void ObtenerHora(int& nHoras,int& nMinutos,int& nSegundos,string& pszFormato) const;
	void Destruir();
};
#endif