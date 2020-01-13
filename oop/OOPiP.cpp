#include <iostream>
#include <iomanip>

const int capacity=200;

using namespace std;

class arr {                                            // создаем класс arr
	int arrX[capacity];                                // в нем создаем массив с максимальной величиной
	int realSize;                                      // создаем переменную для настоящего размера

	void full_rand();                                  // прототипы функций, о функциях читайте ниже
	void enterSize();                             
	void delPos(int);
	void add_0(int);
public:
	void printArr();
	arr();                                             // конструкторы с парметрами и без параметров
	arr(int);
	void multiSeven();
	void oddElem();
};                          

arr::arr(){
	enterSize();
	full_rand();

}

arr::arr(int size){
	realSize = size;
	full_rand();
}



void arr::enterSize(){                                                //функция для ввода реального размера массива
	while (realSize > 100 || realSize < 1)
	{
		cout << "Enter the arr size from 1 to 100." << endl;
		cin >> this->realSize;
	}
	
}         

void arr::full_rand(){                                          //функция заполнения псевдослучайными числами
	for (int i = 0; i < capacity; i++)
	{
		arrX[i] = rand();
	}

}

void arr::printArr(){                                              // функция вывода массива в консоль
	for (int i = 0; i < realSize; i++){
		cout << setw(3) << (i+1) << "   " << arrX[i] << endl;
	}
	cout << endl;
}

void arr::add_0(int iterator){                               //функция добавления 0 в массив
	realSize++;
	for (int i = realSize; i > iterator; i--)
	{
		arrX[i] = arrX[i - 1];
	}
	arrX[iterator] = 0;
}

void arr::delPos(int iterator){                              //функция удаления массива
	if (iterator >= 0 && iterator < realSize)
	{
		for (int i = iterator; i < realSize; i++)
		{
			arrX[i] = arrX[i + 1];
		}
		realSize--;
	}
}

void arr::multiSeven(){                                //функция проверки на кратность 7 и последующего удаления элемента
	int i = 0;
	while (i < realSize)
	{

		if ( !(arrX[i]%7) )
		{
			delPos(i);

		}
		else 
		{
			i++;
		}
		
	}
}

void arr::oddElem(){                                //функция проверяет элументы на четность и ставит после них 0
	for (int i = 0; i < realSize; i++)
	{
		if (arrX[i]%2)
		{
			add_0(i+1);
		}
	}
	}
	



int main(){
	arr arrX;                 //инициализируем объект
	arrX.printArr();          //выводим в консоль
	arrX.multiSeven();        //проверяем на кратность семи
	arrX.oddElem();           //проверка на четность
	arrX.printArr();          //выводим в консоль
	system("pause");
	return 0;
}