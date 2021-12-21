#include <iostream>
#include <iomanip>	//для форматованого виведення
using namespace std;

int inputSize();								//введення розміру масиву
float** arrayDecl(int, int);					//оголошення двовимірного масиву
void arrayRand(float**, int, int, int, int);	//генерація двовимірного масиву з випадкових значень
void arrayOutput(float*, int, int, int);		//вивід одновимірного масиву
void arrayOutput(float**, int, int, int, int);	//вивід двовимірного масиву
void arrayDiag(float**, float*, int);			//наповнення одновимірного масиву діагональними елементами двовимірного 
void arrayChange(float**, float*, int);			//заміна стобців з нульовими значеннями матриці елементами одновимірного масиву 
void arrayDelete(float**, int, int);			//видалення двовимірного масиву

int main()
{
	srand(time(NULL));
	int an = 1, pn = 1;		//кількість всіх цифр і цифр після коми
	int n = inputSize();	//введення розміру масиву

	//оголошення та ініціалізація двовимірного масиву
	float** arr = arrayDecl(n, n);
	arrayRand(arr, n, n, an, pn);
	cout << "Generated array:" << endl;
	arrayOutput(arr, n, n, an, pn);

	//оголошення та ініціалізація масиву для діагональних елементів
	float* d = new float[n];
	arrayDiag(arr, d, n);
	cout << "Diagonal elements:" << endl;
	arrayOutput(d, n, an, pn);

	//заміна стобців з нульовими значеннями елементами діагоналі
	arrayChange(arr, d, n);
	cout << endl << "Final result:" << endl;
	arrayOutput(arr, n, n, an, pn);

	//видалення динамічних масивів
	arrayDelete(arr, n, n);
	delete[]d;

	cout << endl;
	system("pause");
}

//введення розміру масиву
int inputSize()
{
	int s;
	cout << "Enter the size of array: ";
	cin >> s;
	return s;
}

//оголошення двовимірного масиву
float** arrayDecl(int n, int j)
{
	float** arr = new float* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new float[j];
	return arr;
}

//генерація двовимірного масиву з випадкових значень
void arrayRand(float** arr, int n, int j, int an, int pn)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < j; k++)
		{
			arr[i][k] = rand() % int(2 * pow(10, an) - 1)
				- (pow(10, an) - 1);
			arr[i][k] /= pow(10, pn);
		}
	}
}

//вивід одновимірного масиву
void arrayOutput(float* arr, int n, int an, int pn)
{
	int w = an + pn + 3;
	for (int k = 0; k < n; k++)
		cout << setbase(pn) << setw(w) << arr[k];
}

//вивід двовимірного масиву
void arrayOutput(float** arr, int n, int j, int an, int pn)
{
	for (int k = 0; k < n; k++)
	{
		arrayOutput(&arr[k][0], j, an, pn);
		cout << endl;
	}
}

//наповнення одновимірного масиву діагональними елементами двовимірного 
void arrayDiag(float** arr, float* d, int n)
{
	for (int i = 0; i < n; i++)
		d[i] = arr[i][i];
}

/*заміна стобців з нульовими значеннями матриці
елементами одновимірного масиву*/
void arrayChange(float** arr, float* d, int n)
{
	bool check;
	for (int i = 0; i < n; i++)
	{
		check = true;
		for (int k = 0; k < n && check; k++)
		{
			if (arr[k][i] == 0)
			{
				for (int l = 0; l < n; l++)
					arr[l][i] = d[l];
				check = false;
			}
		}
	}
}

//видалення двовимірного масиву
void arrayDelete(float** arr, int n, int m)
{
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}