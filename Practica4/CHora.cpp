#include "CHora.h"
#include"Utils.h"
using namespace std;
using namespace Utils;
CHora::CHora(int hh, int mm, int ss, string ff) :m_nHoras{ hh }, m_nMinutos{ mm }, m_nSegundos{ ss }, m_pszFormato(ff) {
	cout << "Llamada al contructor" << endl;
	AsignarFormato(m_pszFormato);
	bool aux = EsHoraCorrecta();
	if (aux==false)
	{
		cout << "Formato de hora incorrecto creamos objeto predeterminado." << endl;
		Iniciar();
		m_nHoras = 0;
		m_nMinutos = 0;
		m_nSegundos = 0;
		m_pszFormato = "24 HORAS";
	}
}
CHora::CHora(const CHora& hora) :m_nHoras(hora.m_nHoras), m_nMinutos(hora.m_nMinutos),
m_nSegundos(hora.m_nSegundos), m_pszFormato(hora.m_pszFormato) {
	cout << "LLamada al constructor copia" << endl;
}
CHora::~CHora() {
	cout << "LLamada al destructor" << endl;
	cout << endl;
}
CHora& CHora::operator=(const CHora& hora) {
	if (this != &hora)
	{
		m_nHoras = (hora.m_nHoras);
		m_nMinutos = (hora.m_nMinutos);
		m_nSegundos = (hora.m_nSegundos);
		m_pszFormato = hora.m_pszFormato;
		cout << "Llamada al operador sobrecargado" << endl;
		return *this;
	}
	else
		cout << "Mismo Objeto no se realizara la asignacion" << endl;
}
	void CHora::Iniciar(){
		m_nHoras = 0;
		m_nMinutos = 0;
		m_nSegundos = 0;
		m_pszFormato = "";
	}
	bool CHora::AsignarHora(int nHoras,int nMinutos,int nSegundos,string pszFormato){
		m_nHoras = nHoras;
		m_nMinutos = nMinutos;
		m_nSegundos = nSegundos;
		AsignarFormato(pszFormato);
		bool aux = EsHoraCorrecta();
		return aux;

	}
	void CHora::ObtenerHora(int& nHoras,int& nMinutos,int& nSegundos,string& pszFormato)const {
		nHoras = m_nHoras;
		nMinutos = m_nMinutos;
		nSegundos = m_nSegundos;
		pszFormato = m_pszFormato;
	}
	void CHora::Destruir()
	{
		cout << "procedemos a detruir"<< endl;
		m_pszFormato = "";

	}
	bool CHora::EsHoraCorrecta() const{
		if ((m_pszFormato == "24 HORAS") && (m_nHoras <= 23) && (m_nHoras >= 0) && (m_nMinutos <= 59) && (m_nMinutos >= 0) && (m_nSegundos <= 59) && (m_nSegundos >= 0))
			return true;
		else if (((m_pszFormato == "AM") || (m_pszFormato == "PM")) && (m_nHoras <= 12) && (m_nHoras >= 1) && (m_nMinutos <= 59) && (m_nMinutos >= 0) && (m_nSegundos <= 59) && (m_nSegundos >= 0))
			return true;
		else
			return false;
	
	}
	bool CHora::Formato24() const {							
		if (m_pszFormato == "24 HORAS") {
		return true;
		}
		else
			return false;
	}	 							//Realizado
	bool CHora::AsignarFormato(string pszFormato) {
		if (pszFormato.empty() == false) 
		{		
			m_pszFormato = CUtils::ConverMayus(pszFormato);
			return true;
		}
		return false;
	}