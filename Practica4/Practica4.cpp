#include <cstdio>
#include <cstdlib>
#include "Utils.h"
#include "MemoryManager.h"
#include"CHora.h"
using namespace std;
using namespace Utils;

int main() {
	{
		const char* menu[5]{ "Crear un objeto local","Crear un objeto dinamicamente","Constructor copia","Operador de asignacion", "Terminar"};
		const char* submenu[6]{ "Con una Hora predeterminada","Introduciento la hora", "Introduciento la hora y los minutos", "Introduciento la hora, los minutos y los segundos",
			"Introduciento la hora, los minutos, los segundos y el formato","Volver al menu principal" };
		int funcion = 0;
		int subfuncion = 0;
		int nHoras = 0;
		int nMinutos = 0;
		int nSegundos = 0;
		bool aux;
		CHora* HoraDinamica{};
		string pszFormato;
		while (funcion != 5) {
			CUtils::CrearMenu(menu, 5);
			CUtils::LeerDato(funcion);
			switch (funcion) {
			case 1:
			{
				while (subfuncion != 6)
				{
					CUtils::CrearMenu(submenu, 6);
					CUtils::LeerDato(subfuncion);
					switch (subfuncion)
					{
					case 1:
					{
						CHora hora;
						CUtils::VisualizarHora(hora);
						break;
					}
					case 2:
					{
						cout << "Introduzca la Hora: ";
						CUtils::LeerDato(nHoras);
						cout << endl;
						CHora hora(nHoras);
						CUtils::VisualizarHora(hora);
						break;
					}
					case 3:
					{
						cout << "Introduzca la Hora: ";
						CUtils::LeerDato(nHoras);
						cout << endl;
						cout << "Introduzca los Minutos: ";
						CUtils::LeerDato(nMinutos);
						cout << endl;
						CHora hora(nHoras, nMinutos);
						CUtils::VisualizarHora(hora);
						break;
					}
					case 4:
					{
						cout << "Introduzca la Hora: ";
						CUtils::LeerDato(nHoras);
						cout << endl;
						cout << "Introduzca los Minutos: ";
						CUtils::LeerDato(nMinutos);
						cout << endl;
						cout << "Introduzca los Segundos: ";
						CUtils::LeerDato(nSegundos);
						cout << endl;
						CHora hora(nHoras, nMinutos, nSegundos);
						CUtils::VisualizarHora(hora);
						break;
					}
					case 5:
					{
						cout << "Introduzca la Hora: ";
						CUtils::LeerDato(nHoras);
						cout << endl;
						cout << "Introduzca los Minutos: ";
						CUtils::LeerDato(nMinutos);
						cout << endl;
						cout << "Introduzca los Segundos: ";
						CUtils::LeerDato(nSegundos);
						cout << endl;
						cout << "Introduzca el Formato horario (AM/PM o 24 HORAS): " << endl;
						CUtils::LeerDato(pszFormato); 
						cout << endl;
						CHora hora(nHoras, nMinutos, nSegundos, pszFormato);
						CUtils::VisualizarHora(hora);
						break;
					}
					case 6:
					{
						cout << "Volvemos al menu principal. " << endl;
						cout << endl;
					}
					}
				}
				break;
			}
			case 2:
			{
				if (HoraDinamica != NULL) 
				{
					delete HoraDinamica;
					HoraDinamica = NULL;
					cout << "Se ha borrado el Objeto, ya se puede crear otro nuevo" << endl;
				}
				cout << "Introduzca la Hora: ";
				CUtils::LeerDato(nHoras);
				cout << endl;
				cout << "Introduzca los Minutos: ";
				CUtils::LeerDato(nMinutos);
				cout << endl;
				cout << "Introduzca los Segundos: ";
				CUtils::LeerDato(nSegundos);
				cout << endl;
				cout << "Introduzca el Formato horario (AM/PM o 24 HORAS): " << endl;
				CUtils::LeerDato(pszFormato);
				cout << endl;
				HoraDinamica = new CHora(nHoras, nMinutos, nSegundos, pszFormato);
				CUtils::VisualizarHora(*HoraDinamica);
				cout << endl;
				break;
			}
			case 3:
			{
				if (HoraDinamica == NULL)
				{
					cout << "Primero tenemos que crear el objeto dinamico." << endl<<endl;
				}
				else
				{
				CHora hora(*HoraDinamica);
				CUtils::VisualizarHora(hora);
				cout << endl;
				}
				break;
			}
			case 4:
			{
				if (HoraDinamica == NULL)
				{
					cout << "Primero tenemos que crear el objeto dinamico." << endl << endl;
				}
				else
				{
				CHora hora;
				hora = *HoraDinamica;
				CUtils::VisualizarHora(hora);
				cout << endl;
				}
				break;

			}
			case 5:
			{
				delete HoraDinamica;
				break;
			}
			}
		}
	}
	MemoryManager::dumpMemoryLeaks();
}
