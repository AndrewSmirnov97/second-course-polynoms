// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0)   // 
		throw 1;  //создадется исключение если длина отриц (вроде как переменная которую потом можно как то обрабатывать и т.д)
	BitLen = len; // так заполнится поле количества битов приндлежащее объекту
	MemLen = (len + 15) >> 4; //по сути - количество интовых чисел которое займут эти биты. в байте 8 бит, а int в 64 архитектуре это 2 ,байта = 16 бит 
	pMem = new TELEM[MemLen]; // создание массива по указателю. телем как инт по размеру. 
	if (pMem != NULL)
	for (int i = 0; i < MemLen; i++)  //каждый элемент массива становится нулевого значения. в двоичном коде - как биты это 00000000
		pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen; 
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (bf.pMem != NULL)
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete pMem; //память на которую казывает указатель будет почищена
	pMem = NULL; // null сделать саму ссылку в памяти этого указателя , указывашую на память =0, то есть по сути никуда не указывающей
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{                           // метод (функция) константна. на самом деле это просто показывает что этот метод ничего не меняет в самом объекте, просто отдает число. Изменить нельзя, но никто и не пытался = поэтому просто показатель что объект не будет меняться
	return n >> 4; //нужно вернуть число что соответствует номеру в массиве где находится сей бит. без+15 потому что целочисленное деление на 16 для например 8ого бита скажет что индекс =0. все норм. ведь индексация с нуля.

}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{          
	if (n >= BitLen || n < 0)
		throw 3;               //ну как бы бит под отрицательным номером или за пределом пусть будет исключением с кодом 3ж
		//эта шняга должна крч сделать целое интовое число в 2 байта в котором будет бит под номером n     типо 2  бит   (еще 1 байт)00000100  нумерация с конца с нуля. Вот не важно, пусть в объекте 4 байта и бит под номером 34 просится - для того и деление - чтобы сделать маску и ровно 2 байт (интовое)
		// чтобы так получилось нужно создать число = 1 - в битах это (1байт)00000001 и сдвинуть его (на номер бита) разрядов влево (не больше 16)
		return 1 << (n % 16);
	
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{

  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ((n > -1) && (n < BitLen)){ //ограничение 
		pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
		//getindemem даст номер целого числа в массиве где находится бит, и в него запишется логическое или(от маски и данного целого числа) т.е в любом случае под номером н будет единичка ....01|....10 = ....11
	}
 else 
	throw 3;
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ((n > -1) && (n < BitLen)){ 
		pMem[GetMemIndex(n)] &=~GetMemMask(n);  // логическое "и" для числа и  отрицеание от маски. в отрицании нужный бит равен 0, а все остальные единички. "и" сохранит изначальные биты в числе а под номером н сделает равным 0.
	}
	else throw 3;
}

int TBitField::GetBit(const int n) const // получить значение бита   (по сути переведет  2 байта с битом под номером н в целое число) так, 3 бит это 16или0 а 0евой - это 1или0
{
	if ((n > -1) && (n < BitLen)){
		return 	pMem[GetMemIndex(n)] & GetMemMask(n); //целое    находящееся по индексу в массиве где находится бит номер н & маска - в битовом представлении преобразует pmem{номер целого] как в маску, а в интовом числе 
	}
	else
		throw 3;
  return 0;

}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (BitLen != bf.BitLen){

		BitLen = bf.BitLen;
	}
	if (MemLen != bf.MemLen){

	MemLen = bf.MemLen;
}
	delete[] pMem; //чтобы один и тот же класс не уводил указатель на новую память во избежание утечки
	pMem = new TELEM[MemLen];
	if (bf.pMem != NULL)
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];
	return *this;
	
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	int res = 1;
	if (BitLen != bf.BitLen){ //сразу по длине сравнить а потом более детальная проверка поцелочисленно 
		res = 0;
	}
	else 
	for (int i = 0; i < MemLen; i++){
		if (pMem[i] != bf.pMem[i]){
			//(значения чисел будут равными если равны одинаковые биты)
			res = 0; 
			break; //
		}

	}
  return res;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	int res = 0;
	if (BitLen != bf.BitLen){ //сразу по длине сравнить а потом более детальная проверка поцелочисленно 
		res = 1;
	}
	else
	for (int i = 0; i < MemLen; i++){
		if (pMem[i] != bf.pMem[i]){
			//(значения чисел будут равными если равны одинаковые биты)
			res = 1;
			break; //
		}

	}
	return res;

  
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	int len = BitLen;    //создание промежуточного класса через конструктор,
	if (bf.BitLen > BitLen)
		len = bf.BitLen;
	TBitField temp(len);
	for (int i = 0; i < MemLen; i++)// копирование в его память памяти объекта вызвавшего
		temp.pMem[i] = pMem[i];
	for (int i = 0; i < bf.MemLen; i++)
		temp.pMem[i] |= bf.pMem[i];   //и все его элементы логически сложены с элементами объекта справа
	return temp;
	
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int len = BitLen;
	if (bf.BitLen > BitLen)
		len = bf.BitLen;
	TBitField temp(len);              //аналогично и для умножения битов
	for (int i = 0; i < MemLen; i++)
		temp.pMem[i] = pMem[i];
	for (int i = 0; i < bf.MemLen; i++)
		temp.pMem[i] &= bf.pMem[i];
	return temp;
	
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField temp(BitLen);

	int n = BitLen -1;//по идее исходя из длины количества бит определит под каким номером будет последний
	int dl = GetMemIndex(n); //длина битовой строки в количестве целых чисел-1
	/*for (int i = 0; i < dl ; i++)
		temp.pMem[i] = ~pMem[i];*/ //перевернуть целые числа побитово можно, а там где хвост - нельзя. потому ищется индекс в массиве где последний бит и до него(до индекса инвертируется)
	
	//for (int i = (dl)*16 ; i < BitLen ; i++){
	for (int i = 0; i < BitLen; i++)
	{	
		if (GetBit(i) != 0){
			temp.ClrBit(i);
		}
		else
			temp.SetBit(i);

	}
	
	return temp;
	
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	int i = 0;
	char ch;
	do {
		istr >> ch;
	} while (ch != ' ');
	while (1) {
		istr >> ch;
		if (ch == '0') bf.ClrBit(i++);
		else if (ch == '1')
			bf.SetBit(i++);
		else break;
	}
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for (int i = 0; i < bf.BitLen; i++)
	if (bf.GetBit(i))
		ostr << '1';
	else
		ostr << '0';
	
	return ostr;
}
