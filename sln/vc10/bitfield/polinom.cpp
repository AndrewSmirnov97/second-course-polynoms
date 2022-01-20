#include "Monom.h"
#include "polinom.h"
using namespace std;
#include <sstream>

	link::link(string str)
	{
		A = Monom(str);
		n = NULL;
	}
	link::link(Monom B)
	{
		A = Monom(B);
		n = NULL;
	}


	


Polinom::Polinom(){ //���������
		h = NULL;
	}
Polinom::Polinom(string str){ //c������ ���� (����)(����������� ���� �������)�������� �� ��������� � ��������
		string substr;
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
		this->makeunique();
	}
void Polinom::makeunique(){ //������ �� ���� ������� ,�������, ������� � ���������� ��������, ���� ��� ����������� ���� ����� �������������� - ������� ��� �����
	if (h->n == NULL){
		return;
	}
	link* cur = h;
		link* exh;
		link *next = h->n;
		link* todel1;
		link* todel2;
		bool flag = false; //�������� �� ����
		while (next->n != NULL){

			if ((next->A.hide) == (cur->A.hide)){
				double coef1 = (cur->A.coef);
				double coef2 = (next->A.coef);
				coef1 = coef2 + coef1;
				cur->A.coef = coef1; //������� ���������� ����� ������ ���� � ���� ������������� ���� - �� ���� ������
				exh = h;
				if (coef1 > 0){

					todel1 = next;


					dellink(todel1);
					next = cur->n;
					flag = true;

				}
				else if (coef1 < 0){

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
			double coef1 = (cur->A.coef);
			double coef2 = (next->A.coef);
			coef1 = coef2 + coef1;
			cur->A.coef = coef1; //������� ���������� ����� ������ ���� � ���� ������������� ���� - �� ���� ������
			exh = h;
			if (coef1 > 0){

				todel1 = next;


				dellink(todel1);
			}
			else if (coef1 < 0){

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
	void Polinom::dellink(link* todel){ //�������� ����� �� ������ �� ���������
		link* cur = h;
		if (todel == h){
			h = h->n;
			delete todel;
			return;

		}
		while (true){
			if (cur->n == todel){ // ����� ��������� �� ����� ����� ���������
				link* left = cur;
				link* right = todel->n;
				left->n = right;
				delete todel; //��� �������� ���� ��� �� ��������� �������� �� ���� ���������(��� ��������)
				//c����� ���������

				break;
			}
			else
				cur = cur->n;
		}


	}
	void Polinom::push(string str){ //add chain of str



		if (h != NULL){

			link * air = new link(str);
			//air->A = Monom(str); //�������� �� ����������, ������������ �����������

			link *cur = h;
			if ((h->n == NULL) && (air->A.hide >= cur->A.hide)){ //���� ������ ���� ����� � ����� ������

				h = air;
				air->n = cur;
				return;
			}
			if ((h->n == NULL) && (air->A.hide < cur->A.hide)){ //���� ������ ���� ����� � ����� ������

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
				else if ((cur->n == NULL) && (cur->A.hide > air->A.hide)) //cur � ������� ���������� �����, ����� - ������ ����
				{
					cur->n = air;
					air->n = NULL;
					return;
				}

				cur = cur->n;
				prev = prev->n;
			}
		}
		else { //�� � ��� ��� �������� ����� ���� ������� ���
			link * air = new link(str);
			//air->A = Monom(str);
			h = air;
			h->n = NULL;
		}


		//h->n = next;
	}
	void Polinom::pushl(Monom B){
		link *air = new link(B);
		link *check = h;
		if (check == NULL){
			h = air;
			air->n = NULL;
			return;
		}
		while (1){
			if (check->n == NULL){
				check->n = air;
				air->n = NULL;
				return;
			}
			else
				check = check->n;

		}


	}
	void Polinom::push(Monom B){ //add chain of monom

		if (h != NULL){

			link * air = new link(B);
			//air->A = Monom(str); //�������� �� ����������, ������������ �����������

			link *cur = h;
			if ((h->n == NULL) && (air->A.hide >= cur->A.hide)){ //���� ������ ���� ����� � ����� ������

				h = air;
				air->n = cur;
				return;
			}
			if ((h->n == NULL) && (air->A.hide < cur->A.hide)){ //���� ������ ���� ����� � ����� ������

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
				else if ((cur->n == NULL) && (cur->A.hide > air->A.hide)) //cur � ������� ���������� �����, ����� - ������ ����
				{
					cur->n = air;
					air->n = NULL;
					return;
				}

				cur = cur->n;
				prev = prev->n;
			}
		}
		else { //�� � ��� ��� �������� ����� ���� ������� ���
			link * air = new link(B);
			//air->A = Monom(str);
			h = air;
			h->n = NULL;
		}


		//h->n = next;
	}
	string Polinom::createstringfrompol(){ //��������
		string temp;

		string sub;
		sub.resize(40);
		link *cur = h;
		while (cur != NULL){



			sub = to_string(cur->A.coef);
			if (sub[0] == '-')
				temp = temp + sub;
			else
				temp = temp + '+' + sub;

			temp = temp + "x^";
			sub = to_string(cur->A.getx());
			temp = temp + sub;

			temp = temp + "y^";
			sub = to_string(cur->A.gety());
			temp = temp + sub;

			temp = temp + "z^";
			sub = to_string(cur->A.getz());
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
		link* up = this->h;
		link * down = right.h;
		while (1){
			if (up->A.hide >= down->A.hide){
				T.pushl(up->A);
				up = up->n;
			}
			else
			{
				T.pushl(down->A);
				down = down->n;
			}
			if (up == NULL){
				while (1){
					if (down == NULL){
						T.makeunique();
						return T;
					}
					T.pushl(down->A);
					down = down->n;
					
				}

			}

			if (down == NULL){
				while (1){
					if (up == NULL){
						T.makeunique();
						return T;
					}
					T.pushl(up->A);
					up = up->n;
					
				}

			}


		}
		//link* cur1 = h; //��� ������
		//while (cur1 != NULL){
		//	T.push(cur1->A); //
		//	cur1 = cur1->n;
		//}
		//link* cur2 = right.h;
		//while (cur2 != NULL){
		//	T.push(cur2->A); //
		//	cur2 = cur2->n;
		//}
		//� ����� ������� ������ ���� ��������� ������� ������ �� ���������������� �� ������� �������, ��� �� ���������
		/*T.makeunique();
		return T;*/
	}

	double Polinom::count(double x, double y, double z){
		double res = 0;
		if (h == NULL){
			throw - 1;
		}
		link* check = h;
		while (1){
			if (check == NULL){
				return res;

			}
			else
			{ 
				res = (check->A.coef)*pow(x, check->A.getx())*pow(y, check->A.gety())*pow(z, check->A.getz());
				check = check->n;
			}
		}
		


		
	}

	Polinom  Polinom::operator-(Polinom &right){
		Polinom T;
		link* up = this->h;
		link* chdown = right.h;
		while (1){
			if (chdown == NULL){
				break;
			}
			else
			{
				chdown->A.coef = chdown->A.coef*(-1);
				chdown = chdown->n;
			}
		}
		link * down = right.h;
		while (1){
			if (up->A.hide >= down->A.hide){
				T.pushl(up->A);
				up = up->n;
			}
			else
			{
				T.pushl(down->A);
			down = down->n;





			}
			if (up == NULL){
				while (1){
					if (down == NULL){
						T.makeunique();
						return T;
					}
					T.pushl(down->A);
					down = down->n;

				}

			}

			if (down == NULL){
				while (1){
					if (up == NULL){
						T.makeunique();
						return T;
					}
					T.pushl(up->A);
					up = up->n;

				}

			}


		}
		//Polinom T;
		//link* cur1 = h; //��� ������
		//while (cur1 != NULL){
		//	T.push(cur1->A); //
		//	cur1 = cur1->n;
		//}
		//link* cur2 = right.h;
		//while (cur2 != NULL){
		//	Monom temp(cur2->A);

		//	T.push(temp); //
		//	//cur2->A.sign = -(cur2->A.sign); // �������������� ����, �� �� ���������
		//	cur2 = cur2->n;
		//}
		////� ����� ������� ������ ���� ��������� ������� ������ �� ���������������� �� ������� �������, ��� �� ���������
		//T.makeunique();
		//return T;
	}

	Polinom Polinom::operator*(Polinom &right){
		Polinom T;
		link* cur1 = h; //��� ������
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

		//� ����� ������� ������ ���� ��������� ������� ������ �� ���������������� �� ������� �������, ��� �� ���������
		T.makeunique();
		return T;
	}

