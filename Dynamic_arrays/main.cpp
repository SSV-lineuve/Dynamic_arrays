#include <iostream>
using namespace std;

template<typename T> T* Allocate(int n);
template<typename T> void Clear(T arr[], int n);
void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
template<typename T> void Print(T arr[], const int n);

template<typename T> void push_back(T*& arr, int& n, T value);
template<typename T> T* push_front(T arr[], int& n, T value);
template<typename T> T* insert(T arr[], int& n, int index);

template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);
template<typename T> T* erase(T arr[], int& n, int index);

void FillRand(int** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n);
template<typename T> void Print(T** arr, const int m, const int n);

template<typename T> void Allocate(T**& arr, int m, int n);
template<typename T> void Clear(T** arr, int m, int n);
template<typename T> T** push_row_back(T** arr, int& m, int n);
template<typename T> T** push_row_front(T** arr, int& m, int n);
template<typename T> T** insert_row(T** arr, int& m, int n, int& index);

template<typename T> T** pop_row_back(T** arr, int& m, int n);
template<typename T> T** pop_row_front(T** arr, int& m, int n);
template<typename T> T** erase_row(T** arr, int& m, int n, int& index);

template<typename T> T** push_col_back(T** arr, int m, int& n);
template<typename T> T** push_col_front(T** arr, int m, int& n);
template<typename T> T** insert_col(T** arr, int m, int& n, int& index);

template<typename T> T** pop_col_back(T** arr, int m, int& n);
template<typename T> T** pop_col_front(T** arr, int m, int& n);
template<typename T> T** erase_col(T** arr, int m, int& n, int& index);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1

	int n;

	cout << "Введите размер массива: "; cin >> n;
	int* arr = Allocate<int>(n);
	//double* arr = Allocate<double>(n);
	//char* arr = Allocate<char>(n);

	FillRand(arr, n);
	Print(arr, n);

	int value;
	//double value;
	//char value;
	cout << "Введите добавляемое значение: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаление последнего элемента из массива: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление первого элемента из массива: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	int index = 0;
	cout << "Введите номер элемента, который нужно вставить в массив (от 0 до " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << n - 1 << "): ";
		cin >> index;
	}
	arr = insert(arr, n, index);
	cout << "\nВставлен " << index << "-й элемент массива: \n";
	Print(arr, n);

	cout << "Введите номер элемента, который нужно удалить из массива (от 0 до " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << n - 1 << "): ";
		cin >> index;
	}
	arr = erase(arr, n, index);
	cout << "\nУдалён " << index << "-й элемент массива: \n";
	Print(arr, n);
	system("color 02");
	Clear(arr, n);
	//delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	using std::cin;
	using std::cout;
	using std::endl;

	int m; //Количество строк
	int n; //Количество элементов строки

	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;

	double** arr;
	Allocate(arr, m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "\nДобавили строку в конец массива: \n";
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "\nДобавили строку в начало массива: \n";
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	int index = 0;
	arr = insert_row(arr, m, n, index);
	cout << "\nДобавили строку  " << index << "  в массив: \n";
	Print(arr, m, n);

	cout << "\nУдалили последнюю строку из массива: \n";
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "\nУдалили первую строку из массива: \n";
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = erase_row(arr, m, n, index);
	cout << "\nУдалили строку " << index << " из массива: \n";
	Print(arr, m, n);

	cout << "\nДобавили столбец в конец массива: \n";
	arr = push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "\nДобавили столбец в начало массива: \n";
	arr = push_col_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = insert_col(arr, m, n, index);
	cout << "\nВставили столбец " << index << " в массив: \n";
	Print(arr, m, n);

	cout << "\nУдалили столбец в конце массива: \n";
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "\nУдалили столбец в начале массива: \n";
	arr = pop_col_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = erase_col(arr, m, n, index);
	cout << "\nУдалили столбец " << index << " из массива: \n";
	Print(arr, m, n);
	system("color 04");

	Clear(arr, m, n);
#endif // DYNAMIC_MEMORY_2
}

template<typename T> T* Allocate(int n)
{
	T* arr = new T[n]{};
	return arr;
}

template<typename T> void Clear(T arr[], int n)
{
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arr[i] /= 10;
	}
}

void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		int minElem = 65; //ASCII код буквы A (91: [, 92: \, 93: ], 94: ^, 95: _, 96: ')
		int maxElem = 122; //ASCII код буквы z (97-122)
		arr[i] = rand() % (maxElem - minElem) + minElem;
	}
}

template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

template<typename T> void push_back(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}

template<typename T> T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

template<typename T> T* insert(T arr[], int& n, int index)
{
	T* buffer = new T[++n]{};
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index) buffer[i] = T();
		else buffer[i] = arr[i - 1];
	}
	delete[] arr;
	return buffer;
}

template<typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template<typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

template<typename T> T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T> void Allocate(T**& arr, int m, int n)
{
	T** memory = new T * [m];
	for (int i = 0; i < m; i++)
		memory[i] = new T[n]{};
	arr = memory;
	//return memory;
}

template<typename T> void Clear(T** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			arr[i][j] /= 10;
		}
	}

}

void FillRand(char** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int minElem = 65; //ASCII код буквы A (91: [, 92: \, 93: ], 94: ^, 95: _, 96: ')
			int maxElem = 122; //ASCII код буквы z (97-122)
			arr[i][j] = rand() % (maxElem - minElem) + minElem;
		}
	}
}

template<typename T> void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

template<typename T> T** push_row_back(T** arr, int& m, int n)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n];
		for (int j = 0; j < n; j++)
			buffer[i][j] = arr[i][j];
	}
	buffer[m] = new T[n]{};
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	m++;
	return buffer;
}

template<typename T> T** push_row_front(T** arr, int& m, int n)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = new T[n];
		for (int j = 0; j < n; j++)
			buffer[i + 1][j] = arr[i][j];
	}
	buffer[0] = new T[n]{};
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	m++;
	return buffer;
}

template<typename T> T** insert_row(T** arr, int& m, int n, int& index)
{
	cout << "Введите номер строки, которую нужно вставить в массив (от 0 до " << m - 1 << "): "; cin >> index;
	while (index < 0 || index >= m)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << m - 1 << "): ";
		cin >> index;
	}
	T** buffer = new T * [++m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n];
		for (int j = 0; j < n; j++)
		{
			if (i < index) buffer[i][j] = arr[i][j];
			else if (i == index) buffer[i][j] = 0; //buffer[i][j] = rand() % 100;
			else buffer[i][j] = arr[i - 1][j];
		}
	}
	for (int i = 0; i < m - 1; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** pop_row_back(T** arr, int& m, int n)
{
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n];
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i <= m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** pop_row_front(T** arr, int& m, int n)
{
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n];
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i <= m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** erase_row(T** arr, int& m, int n, int& index)
{
	cout << "Введите номер строки, которую нужно удалить из массива (от 0 до " << m - 1 << "): "; cin >> index;
	while (index < 0 || index >= m)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << m - 1 << "): ";
		cin >> index;
	}
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n];
		for (int j = 0; j < n; j++)
			i < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i + 1][j];
	}
	for (int i = 0; i <= m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** push_col_back(T** arr, int m, int& n)
{
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1];
		for (int j = 0; j <= n; j++)
			(j < n) ? buffer[i][j] = arr[i][j] : buffer[i][j] = T();
	}
	n++;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** push_col_front(T** arr, int m, int& n)
{
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1];
		for (int j = 0; j <= n; j++)
			(j == 0) ? buffer[i][j] = T() : buffer[i][j] = arr[i][j - 1];
	}
	n++;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** insert_col(T** arr, int m, int& n, int& index)
{
	cout << "Введите номер столбца, который нужно вставить в массив (от 0 до " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << n - 1 << "): ";
		cin >> index;
	}
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1];
		for (int j = 0; j <= n; j++)
		{
			if (j < index) buffer[i][j] = arr[i][j];
			else if (j == index) buffer[i][j] = 0; //buffer[i][j] = rand() % 100;
			else buffer[i][j] = arr[i][j - 1];
		}
	}
	n++;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** pop_col_back(T** arr, int m, int& n)
{
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1];
		for (int j = 0; j < n - 1; j++)
			buffer[i][j] = arr[i][j];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** pop_col_front(T** arr, int m, int& n)
{
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1];
		for (int j = 0; j < n - 1; j++)
			buffer[i][j] = arr[i][j + 1];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T** erase_col(T** arr, int m, int& n, int& index)
{
	cout << "Введите номер столбца, который нужно удалить из массива (от 0 до " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "Вы ввели неправильное число, попробуйте еще раз (число должно быть от 0 до " << n - 1 << "): ";
		cin >> index;
	}
	T** buffer = new T * [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1];
		for (int j = 0; j < n - 1; j++)
			j < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i][j + 1];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}