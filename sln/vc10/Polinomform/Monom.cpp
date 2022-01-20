#include"Monom.h"


	Monom::Monom(){

	}
	Monom::Monom(std::string str){  //моном из строки (строка вида (знак, коэфициент даже 1, три буквы со степенями через галочку


		sign = str[0]; //случай есть все три переменные указаны степени
		int i = 1;
		coef = 0;
		degx = 0;
		degy = 0;
		degz = 0;
		if (str[0] == '+')
			sign = 1;
		if (str[0] == '-')
			sign = -1;
		int len = str.length();
		while (str[i] != 'x'){
			coef = coef * 10 + stoi(str.substr(i, 1));
			i++;
		}
		i = i + 2;
		while (str[i] != 'y'){
			degx = degx * 10 + stoi(str.substr(i, 1));
			i++;
		}
		i = i + 2;
		while (str[i] != 'z'){
			degy = degy * 10 + stoi(str.substr(i, 1));
			i++;
		}
		i = i + 2;
		while (i != len){
			degz = degz * 10 + stoi(str.substr(i, 1));
			i++;
		}

		hide = degx + degy * 20 + degz * 400;
	}


	Monom::Monom(Monom &m){ //конструктор из параметров копрования
		sign = m.sign;
		coef = m.coef;
		degx = m.degx;
		degy = m.degy;
		degz = m.degz;
		hide = m.hide;
	}
	Monom  Monom::operator*(Monom &right){
		Monom T(right);
		T.coef = T.coef*this->coef;
		T.sign = T.sign*this->sign;
		T.degx = T.degx + this->degx;
		T.degy = T.degy + this->degy;
		T.degz = T.degz + this->degz;
		T.hide = T.degx + T.degy * 20 + T.degz * 400;
		return T;
	}

	bool  Monom::operator==(const Monom &T)const{


		if (sign != T.sign){
			return false;
		}

		if (coef != T.coef){
			return false;
		}

		if (degx != T.degx){
			return false;
		}

		if (degy != T.degy){
			return false;
		}

		if (degz != T.degz){
			return false;
		}
		if (hide != T.hide){
			return false;
		}






		return true;
	}


	int Monom::getsign(){
		return sign;
	}
	int Monom::getcoef(){
		return coef;
	}
	int Monom::getx(){
		return degx;
	}
	int Monom::gety(){
		return degy;
	}
	int Monom::getz(){
		return degz;
	}
	int Monom::gethide(){
		return hide;

	}



	void Monom::show(){

		cout << sign << endl;
		cout << coef << endl;
		cout << degx << endl;
		cout << degy << endl;
		cout << degz << endl;
		cout << hide << endl;

	}
	

