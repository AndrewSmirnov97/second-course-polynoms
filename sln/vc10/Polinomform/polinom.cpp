#include "polinom.h"



	link::link(std::string str)
	{
		A = Monom(str);
		n = NULL;
	}
	link::link(Monom B)
	{
		A = Monom(B);
		n = NULL;
	}


	

	Polinom::Polinom(){ //умолчание
		h = NULL;
	}
	Polinom::Polinom(std::string str){ //cстрока вида (знак)(коэфициенты даже единица)трибуквы со степенями в галочках
		std::string substr;
		substr.resize(30);
		h = NULL;
		int j = 1;
		int n = 0;
		substr[0] = str[0];
		n++;
		for (int i = 1; i <str.length(); i++){
			if ((str[i] != '+') && (str[i] != '-')){
				substr[j] = str[i];
				n++;
			}
			else{
				substr.resize(n);
				this->push(substr);
				j = 0;
				n = 1;

				substr.resize(30);
				for (int b = 0; b < 30; b++){
					substr[b] = '\0';
				}
				substr[0] = str[i];

			}

			if (i == str.length() - 1){
				substr.resize(n);
				this->push(substr);
				n = 0;
				substr.resize(30);
				for (int b = 0; b < 30; b++){
					substr[b] = '\0';
				}

			}
			j++;


		}

	}
	void Polinom::makeunique(){ //пройти по всем звеньям ,сложить, вычесть с одинаковой версткой, если два коэфициента друг друга деморализовали - удалить оба звена
		link* cur = h;
		link* exh;
		link *next = h->n;
		link* todel1;
		link* todel2;
		bool flag = false; //удаления не было
		while (next->n != NULL){

			if ((next->A.hide) == (cur->A.hide)){
				int coef1 = (cur->A.coef)*(cur->A.sign);
				int coef2 = (next->A.coef)*(next->A.sign);
				coef1 = coef2 + coef1;
				cur->A.coef = abs(coef1); //первому найденному звену зальем коэф и если отрицательный знак - то знак меняем
				exh = h;
				if (coef1 > 0){
					cur->A.sign = 1;
					todel1 = next;


					dellink(todel1);
					next = cur->n;
					flag = true;

				}
				else if (coef1 < 0){
					cur->A.sign = -1;
					todel1 = next;


					dellink(todel1);
					next = cur->n;
					flag = true;
				}
				else{
					todel1 = cur;
					todel2 = next;

					if (next->n == NULL){
					}
					else if (next->n->n == NULL) {
						cur = cur->n;
						next = next->n;
					}
					else {
						cur = cur->n->n;
						next = next->n->n;
					}

					flag = true;

					dellink(todel1);


					dellink(todel2);
				}

			}
			if (flag != true){
				cur = cur->n;
				next = next->n;

			}
			flag = false;

		}




		if (next->A.hide == cur->A.hide){
			int coef1 = (cur->A.coef)*(cur->A.sign);
			int coef2 = (next->A.coef)*(next->A.sign);
			coef1 = coef2 + coef1;
			cur->A.coef = abs(coef1); //первому найденному звену зальем коэф и если отрицательный знак - то знак меняем
			exh = h;
			if (coef1 > 0){
				cur->A.sign = 1;
				todel1 = next;


				dellink(todel1);
			}
			else if (coef1 < 0){
				cur->A.sign = -1;
				todel1 = next;


				dellink(todel1);

			}
			else{
				todel1 = cur;
				todel2 = next;




				dellink(todel1);
				dellink(todel2);
			}

		}
	}
	void Polinom::dellink(link* todel){ //удаление звена из списка по указателю
		link* cur = h;
		if (todel == h){
			h = h->n;
			delete todel;
			return;

		}
		while (true){
			if (cur->n == todel){ // найти указатель на звено перед удаленным
				link* left = cur;
				link* right = todel->n;
				left->n = right;
				delete todel; //при удалении того что по указателю удалится ли сама стркутура(она статична)
				//cвяжем указатели

				break;
			}
			else
				cur = cur->n;
		}


	}
	void Polinom::push(string str){ //add chain of str



		if (h != NULL){

			link * air = new link(str);
			//air->A = Monom(str); //оператор не реализован, поверхностое копирование

			link *cur = h;
			if ((h->n == NULL) && (air->A.hide >= cur->A.hide)){ //если только одно звено и новое больше

				h = air;
				air->n = cur;
				return;
			}
			if ((h->n == NULL) && (air->A.hide < cur->A.hide)){ //если только одно звено и новое больше

				h->n = air;
				air->n = NULL;
				return;
			}

			cur = h->n;

			link *prev = h;
			if (h->A.hide <= air->A.hide){
				h = air;
				air->n = prev;
				return;

			}
			while (true){
				if (cur->A.hide <= air->A.hide){



					prev->n = air;
					air->n = cur;
					return;

					//create  earlier cur
				}
				else if ((cur->n == NULL) && (cur->A.hide > air->A.hide)) //cur в позиции последнего звена, новое - меньше всех
				{
					cur->n = air;
					air->n = NULL;
					return;
				}

				cur = cur->n;
				prev = prev->n;
			}
		}
		else { //иф и элс для создания звена если звеньев нет
			link * air = new link(str);
			//air->A = Monom(str);
			h = air;
			h->n = NULL;
		}


		//h->n = next;
	}
	void Polinom::push(Monom B){ //add chain of monom

		if (h != NULL){

			link * air = new link(B);
			//air->A = Monom(str); //оператор не реализован, поверхностое копирование

			link *cur = h;
			if ((h->n == NULL) && (air->A.hide >= cur->A.hide)){ //если только одно звено и новое больше

				h = air;
				air->n = cur;
				return;
			}
			if ((h->n == NULL) && (air->A.hide < cur->A.hide)){ //если только одно звено и новое больше

				h->n = air;
				air->n = NULL;
				return;
			}

			cur = h->n;

			link *prev = h;

			if (h->A.hide <= air->A.hide){
				h = air;
				air->n = prev;
				return;

			}

			while (true){
				if (cur->A.hide <= air->A.hide){



					prev->n = air;
					air->n = cur;
					return;

					//create  earlier cur
				}
				else if ((cur->n == NULL) && (cur->A.hide > air->A.hide)) //cur в позиции последнего звена, новое - меньше всех
				{
					cur->n = air;
					air->n = NULL;
					return;
				}

				cur = cur->n;
				prev = prev->n;
			}
		}
		else { //иф и элс для создания звена если звеньев нет
			link * air = new link(B);
			//air->A = Monom(str);
			h = air;
			h->n = NULL;
		}


		//h->n = next;
	}
	string Polinom::createstringfrompol(){ //работает
		string temp;

		string sub;
		sub.resize(40);
		link *cur = h;
		while (cur != NULL){

			if (cur->A.sign == 1)
				temp = temp + '+';
			if (cur->A.sign == -1)
				temp = temp + '-';

			sub = to_string(cur->A.coef);
			temp = temp + sub;

			temp = temp + "x^";
			sub = to_string(cur->A.degx);
			temp = temp + sub;

			temp = temp + "y^";
			sub = to_string(cur->A.degy);
			temp = temp + sub;

			temp = temp + "z^";
			sub = to_string(cur->A.degz);
			temp = temp + sub;



			cur = cur->n;
		}


		return temp;

	}

	void Polinom::testshow(){
		link* cur = h;
		while (cur != NULL){
			cur->A.show();
			cur = cur->n;

		}

	}
	Polinom  Polinom::operator+(Polinom &right){
		Polinom T;
		link* cur1 = h; //для левого
		while (cur1 != NULL){
			T.push(cur1->A); //
			cur1 = cur1->n;
		}
		link* cur2 = right.h;
		while (cur2 != NULL){
			T.push(cur2->A); //
			cur2 = cur2->n;
		}
		//к этому моменту должен быть составлен полином просто из отстортированных по верстке звеньев, еще не сложенных
		T.makeunique();
		return T;
	}
	Polinom  Polinom::operator-(Polinom &right){
		Polinom T;
		link* cur1 = h; //для левого
		while (cur1 != NULL){
			T.push(cur1->A); //
			cur1 = cur1->n;
		}
		link* cur2 = right.h;
		while (cur2 != NULL){
			Monom temp(cur2->A);
			temp.sign = -(cur2->A.sign);
			T.push(temp); //
			//cur2->A.sign = -(cur2->A.sign); // противопложный знак, мб не раболтает
			cur2 = cur2->n;
		}
		//к этому моменту должен быть составлен полином просто из отстортированных по верстке звеньев, еще не сложенных
		T.makeunique();
		return T;
	}

	Polinom Polinom::operator*(Polinom &right){
		Polinom T;
		link* cur1 = h; //для левого
		link* cur2 = right.h;
		while (cur1 != NULL){
			while (cur2 != NULL){
				Monom temp = (cur1->A)*(cur2->A); //
				T.push(temp);
				cur2 = cur2->n;
			}
			cur2 = right.h;
			cur1 = cur1->n;
		}

		//к этому моменту должен быть составлен полином просто из отстортированных по верстке звеньев, еще не сложенных
		T.makeunique();
		return T;
	}

