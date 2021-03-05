// 1) T - ����� ���� int*, � �� ������ int?
// 2) �������� � Allocate() T** (����� ����� �������/�������) ��� T**& (����� �.�. void)?
// 3) ��� ���������� � Cleal(), ����� ������� ��, ��� ����� (�� �����)?
// 4) ������� switch ��� if ��� ������ ���� ������ (� �.�. ��� ������ 1D ��� 2D)
// 5) FillRand() - ����������
// 6) ������������� ����������� ��������� - T()?

#include <iostream>
using namespace std;

int* Allocate(int n);
void Clear(int arr[], int n);
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

//int* push_back(int arr[], int& n, int value);
void push_back(int*& arr, int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int index); //��������� �������� �� ���������� �������

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index); //������� �������� �� ���������� �������

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

int** Allocate(int m, int n);
void Clear(int** arr, int m, int n);
int** push_row_back(int** arr, int& m, int n);
int** push_row_front(int** arr, int& m, int n);
int** insert_row(int** arr, int& m, int n, int& index);

int** pop_row_back(int** arr, int& m, int n);
int** pop_row_front(int** arr, int& m, int n);
int** erase_row(int** arr, int& m, int n, int& index);

int** push_col_back(int** arr, int m, int& n);
int** push_col_front(int** arr, int m, int& n);
int** insert_col(int** arr, int m, int& n, int& index);

int** pop_col_back(int** arr, int m, int& n);
int** pop_col_front(int** arr, int m, int& n);
int** erase_col(int** arr, int m, int& n, int& index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = Allocate(n);
		//new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;

	cout << "������� ����������� ��������: "; cin >> value;
	//arr = push_back(arr, n, value);
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "�������� ���������� �������� �� �������: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "�������� ������� �������� �� �������: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	int index = 0;
	cout << "������� ����� ��������, ������� ����� �������� � ������ (�� 0 �� " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << n - 1 << "): ";
		cin >> index;
	}
	arr = insert(arr, n, index);
	cout << "\n�������� " << index << "-� ������� �������: \n";
	Print(arr, n);

	cout << "������� ����� ��������, ������� ����� ������� �� ������� (�� 0 �� " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << n - 1 << "): ";
		cin >> index;
	}
	arr = erase(arr, n, index);
	cout << "\n����� " << index << "-� ������� �������: \n";
	Print(arr, n);
	system("color 02");
	Clear(arr,n);
	//delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	using std::cin;
	using std::cout;
	using std::endl;

	int m; //���������� �����
	int n; //���������� ��������� ������

	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	// 1) ������� ������ ����������:
	int** arr = Allocate(m,n);
		//new int* [m];

	/*cout << **arr << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << arr[i] << '\t' << endl;
	}*/

	// 2) �������� ������ ��� ������ ���������� �������:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "\n�������� ������ � ����� �������: \n";
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "\n�������� ������ � ������ �������: \n";
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	int index = 0;
	arr = insert_row(arr, m, n, index);
	cout << "\n�������� ������  " << index << "  � ������: \n";
	Print(arr, m, n);

	cout << "\n������� ��������� ������ �� �������: \n";
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "\n������� ������ ������ �� �������: \n";
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = erase_row(arr, m, n, index);
	cout << "\n������� ������ " << index << " �� �������: \n";
	Print(arr, m, n);

	cout << "\n�������� ������� � ����� �������: \n";
	arr = push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "\n�������� ������� � ������ �������: \n";
	arr = push_col_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = insert_col(arr, m, n, index);
	cout << "\n�������� ������� " << index << " � ������: \n";
	Print(arr, m, n);

	cout << "\n������� ������� � ����� �������: \n";
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "\n������� ������� � ������ �������: \n";
	arr = pop_col_front(arr, m, n);
	Print(arr, m, n);

	index = 0;
	arr = erase_col(arr, m, n, index);
	cout << "\n������� ������� " << index << " �� �������: \n";
	Print(arr, m, n);
	system("color 04");

	Clear(arr, m, n);
	////�������� ���������� ������������� �������:
	//// 1) ������� ������
	//for (int i = 0; i < m; i++)
	//	delete[] arr[i];
	//// 2) ������� ������ ����������
	//delete[] arr;
#endif // DYNAMIC_MEMORY_2
}

int* Allocate(int n)
{
	int* arr = new int[n] {};
	return arr;
}

void Clear(int arr[], int n)
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

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

//int* push_back(int arr[], int& n, int value)
//{
//	//1) ������� �������� ������ ������� �������
//	int* buffer = new int[n + 1]{};
//	//2) �������� �������� �� ��������� ������� � ��������
//	for (int i = 0; i < n; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	//3)������� �������� ������
//	delete[] arr;
//	//4) ��������� ����� ������� ������� ������� ������ �������
//	arr = buffer;
//	// 5) ���������� �������� � ����� �������
//	arr[n] = value;
//	// 6) ����� ���������� ��������, ������ ������� ������������� �� 1
//	n++;	
//	return arr;
//}

void push_back(int*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������
	delete[] arr;
	//4) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	// 5) ���������� �������� � ����� �������
	arr[n] = value;
	// 6) ����� ���������� ��������, ������ ������� ������������� �� 1
	n++;
	//return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = Allocate(n+1);
		//new int[n + 1]{};
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

int* insert(int arr[], int& n, int index)
{
	int* buffer = Allocate(++n);
		//new int[++n]{};
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else if (i == index) buffer[i] = 555;
		else buffer[i] = arr[i - 1];
	}
	delete[] arr;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** Allocate(int m, int n) //�������� ������ ��� ������������ ������
{
	int** memory = new int* [m];
	for (int i = 0; i < m; i++)
		memory[i] = new int[n];
	return memory;
}

void Clear(int** arr, int m, int n) //������� ������������ ������
{
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}

void Print(int** arr, const int m, const int n)
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

int** push_row_back(int** arr, int& m, int n)
{
	//1) ������� �������� ������ ������� �������
	int** buffer = new int* [m + 1];
	//2) �������� �������� �� ��������� ������� � ��������
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n];
		for (int j = 0; j < n; j++)
			buffer[i][j] = arr[i][j];
	}
	buffer[m] = new int[n] {};
	/*for (int j = 0; j < n; j++)
		buffer[i][j] = rand() % 100;*/
		//3)������� �������� ������
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	m++;
	return buffer;
}

int** push_row_front(int** arr, int& m, int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = new int[n];
		for (int j = 0; j < n; j++)
			buffer[i + 1][j] = arr[i][j];
	}
	buffer[0] = new int[n] {};
	/*for (int j = 0; j < n; j++)
		buffer[i][j] = rand() % 100;*/
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	m++;
	return buffer;
}

int** insert_row(int** arr, int& m, int n, int& index)
{
	cout << "������� ����� ������, ������� ����� �������� � ������ (�� 0 �� " << m - 1 << "): "; cin >> index;
	while (index < 0 || index >= m)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << m - 1 << "): ";
		cin >> index;
	}
	int** buffer = new int* [++m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n];
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

int** pop_row_back(int** arr, int& m, int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n];
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

int** pop_row_front(int** arr, int& m, int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n];
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

int** erase_row(int** arr, int& m, int n, int& index)
{
	cout << "������� ����� ������, ������� ����� ������� �� ������� (�� 0 �� " << m - 1 << "): "; cin >> index;
	while (index < 0 || index >= m)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << m - 1 << "): ";
		cin >> index;
	}
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n];
		for (int j = 0; j < n; j++)
			i < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i + 1][j];
	}
	for (int i = 0; i <= m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

int** push_col_back(int** arr, int m, int& n)
{
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
			(j < n) ? buffer[i][j] = arr[i][j] : buffer[i][j] = 0;
	}
	n++;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

int** push_col_front(int** arr, int m, int& n)
{
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
			(j == 0) ? buffer[i][j] = 0 : buffer[i][j] = arr[i][j - 1];
	}
	n++;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

int** insert_col(int** arr, int m, int& n, int& index)
{
	cout << "������� ����� �������, ������� ����� �������� � ������ (�� 0 �� " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << n - 1 << "): ";
		cin >> index;
	}
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1];
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

int** pop_col_back(int** arr, int m, int& n)
{
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1];
		for (int j = 0; j < n - 1; j++)
			buffer[i][j] = arr[i][j];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

int** pop_col_front(int** arr, int m, int& n)
{
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1];
		for (int j = 0; j < n - 1; j++)
			buffer[i][j] = arr[i][j + 1];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}

int** erase_col(int** arr, int m, int& n, int& index)
{
	cout << "������� ����� �������, ������� ����� ������� �� ������� (�� 0 �� " << n - 1 << "): "; cin >> index;
	while (index < 0 || index >= n)
	{
		cout << "�� ����� ������������ �����, ���������� ��� ��� (����� ������ ���� �� 0 �� " << n - 1 << "): ";
		cin >> index;
	}
	int** buffer = new int* [m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1];
		for (int j = 0; j < n - 1; j++)
			j < index ? buffer[i][j] = arr[i][j] : buffer[i][j] = arr[i][j + 1];
	}
	n--;
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	return buffer;
}