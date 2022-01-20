// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp) //вызов конструктора для битфилда , но в неявном виде, в тсет два поля- одно - целый класс битой строки, второе - максимальное количество элементов.  сами 1 и 0 в битовой строке видимо отвечают за некий абстракный элемент, либо он есть, либо -нет
{
	MaxPower = mp; 
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower; // конструктор коп для битового поля уже копирует  в поле битфилд из поля битфилд класса с что (выделяет новую память там же)
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();  //просто мощность множества отображается как длина
	
}

TSet::operator TBitField()
{
	return BitField; //просто возвращает поле битфилд, оно не является объектом, но, видимо можно вмест с оператором = так из tset выделить поле tbitfield, проще говоря оператор позволяющий преобразовывтаь обратно
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (Elem >= MaxPower || Elem < 0)
		throw 4;
	else
	return BitField.GetBit(Elem); //гетбит вернет либо ноль либо неноль в зависимости от номера элемента
}

void TSet::InsElem(const int Elem) // включение элемента множества
{

	if (Elem >= MaxPower || Elem < 0)
		throw 4;
	else
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if (Elem >= MaxPower || Elem < 0)
		throw 4;
	else 
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	return 	(BitField == s.BitField); //в левый операнд так или иначе возвращется число от уже реалихованнного метода
  
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return 	(BitField != s.BitField);
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet temp(BitField | s.BitField);
	return temp;

}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet temp = *this;
	//temp.InsElem(Elem);
	temp.BitField.SetBit(Elem); //для класса который является полем тсета доступный его методы
	return temp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet temp = *this;
	temp.BitField.ClrBit(Elem);
	return temp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet temp(BitField & s.BitField);
	return temp;
	
}

TSet TSet::operator~(void) // дополнение
{
	TSet temp(~BitField);
	return temp; 
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{

	int temp;
	char ch;
	do { istr >> ch; } while (ch != '{');
	do
	{
		istr >> temp;
		s.InsElem(temp);
		do
		{
			istr >> ch;

		} while ((ch != ',') && (ch != '}'));
	} while (ch != '}');
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
/*	int i, n;
	char ch = ' ';
	ostr << "{";
	n = s.GetMaxPower();
	for ( i = 0; i < n; i++){
		if (s.IsMember(i))  //проверка на условие явля
		{
			ostr << ch << ' ' << i;
			ch = ',';
		}
	}
	ostr << "}"; */
	return ostr; 
}
