#ifndef horas_h
#define horas_h
#include <cstddef> 
#include <stdexcept>
#include <iostream>
#include <iomanip>

class tiempo
{
public:
	tiempo(int horas, int minutos, int segundos){// constructor
		if (horas>=0 && horas<=23 && minutos>=0 && minutos <= 59 && segundos >=0 && segundos<=59){
			this->horas = horas;
			this->minutos = minutos;
			this->segundos = segundos;
		}
		else
			throw std::invalid_argument("");
	}
	tiempo(){
		this->horas = 00;
		this->minutos = 00;
		this->segundos = 00;
	}
	bool operator <(const tiempo &t) const {
		if (this->horas == t.horas){
			if (this->minutos == t.minutos){
				if (this->segundos >= t.segundos){
					return false;
				}
				else
					return true;
			}
			else if (this->minutos > t.minutos)
				return false;
			else
				return true;
		}
		else if (this->horas > t.horas)
			return false;
		else
			return true;

	}
	bool operator ==(const tiempo &t)const{
		return (this->horas == t.horas && this->minutos == t.minutos && this->segundos == t.segundos);
	}
	friend std::ostream & operator <<(std::ostream & out, const tiempo & t);
	friend std::istream & operator >> (std::istream & in, const tiempo & t);

private:
	int horas, minutos, segundos;


};

std::ostream & operator << (std::ostream & out, const tiempo & t) {
	const char c = '0';
	if (t.horas >= 0 && t.horas <= 23 && t.minutos >= 0 && t.minutos <= 59 && t.segundos >= 0 && t.segundos <= 59){
		//out << t.horas << ":" << t.minutos << ":" << t.segundos << "\n";
		out << std::setfill(c) << std::setw(2) << t.horas << ":" << std::setfill(c) << std::setw(2) << t.minutos << ":" << std::setfill(c) << std::setw(2) << t.segundos << "\n";
	}
	

	return out;
}
std::istream & operator >> (std::istream & in, tiempo & t) {
	int h, m, s;
	char aux;//Coge los dos puntos
	in >> h>>aux>> m>> aux>>s;
	t= tiempo(h, m, s);
	return in;
}
#endif