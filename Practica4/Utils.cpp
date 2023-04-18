#include <cstdio>
#include <iostream>
#include "Utils.h"
#include <string>
using namespace std;
using namespace Utils;
void CUtils::CrearMenu(const char* opcionesmenu[], int num_opciones) {
	string* menu = new string[num_opciones];
	for (int i = 0; i < num_opciones; i++) {
		menu[i] = opcionesmenu[i];
		cout << i + 1 << " " << menu[i] << endl;
	}
	cout << endl;
}
bool CUtils::LeerDato(int& dato) {
	bool fallo = false;
	do {
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		fallo = cin.fail();
		if (fallo) {
			cout << "ERROR: no es un numero\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fallo);
	return true;
}
bool CUtils::LeerDato(float& dato) {
	bool fallo = false;
	do {
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		fallo = cin.fail();
		if (fallo) {
			cout << "ERROR: no es un numero\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fallo);
	return fallo;
}
bool CUtils::LeerDato(string& dato) {
	getline(cin, dato);
	return true;
}
string& CUtils::ConverMayus(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		str.at(i) = toupper(str.at(i));
		return str;
}
void CUtils::VisualizarHora(const CHora& hora) {
	int nHoras = 0, nMinutos = 0, nSegundos = 0;
	string pszFormato = "";
	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);
	cout << "La hora sera la siguiente : " << nHoras << ":" << nMinutos << ":" << nSegundos << "  Formato: " << pszFormato << endl;
}