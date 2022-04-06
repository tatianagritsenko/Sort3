#include <iostream>
using namespace std;

void qsort(int *mas, int size) {
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	int mid = mas[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (mas[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (mas[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		qsort(mas, j + 1);
	}
	if (i < size) {
		//"Првый кусок"
		qsort(&mas[i], size - i);
	}
}

int main()
{
	int size = 10;
	int *arr = new int[size] {3, 7, 80, -8, 3, 1, 6, 2, 72, 14};

	cout << "Source array: ";

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	cout << endl;

	qsort(arr, size);

	cout << "Sorted array: ";

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}