/*
	Указники. Приклад 12
Указники на указники
дано:
- масив A [N] = {0,1,2,3,4}
- масив указників p [N] на елементи масиву A [N]
- указник рр на масив указників p [N]
необхідно:
Виконати наступні операції і простежити їх виконання:
		---------------------------------------
	    | Операції |   pp  | *pp   |   **pp   |
		---------------------------------------
		|          | &p[0] | &A[0] | A[0] = 0 |
		---------------------------------------
		| pp++     | &p[1] | &A[1] | A[1] = 1 |
		---------------------------------------
		| *++pp    | &p[2] | &A[2] | A[2] = 2 |
		| =&A[2]   |       |       |          |
		---------------------------------------
		| *(++pp)  | &p[3] | &A[3] | A[3] = 3 |
		| =&A[3]   |       |       |          |
		---------------------------------------
		| ++(*pp)  | &p[3] | &A[4] | A[4] = 4 |
		| =&A[4]   |       |       |          |
		---------------------------------------
		|  pp = p  | &p[1] | &A[1] | A[1] = 1 |
		| **++pp   |       |       |          |
		| A[1]=1   |       |       |          |
		---------------------------------------
		| *(++(*pp)| &p[1] | &A[2] | A[2] = 2 |
		|  A[2]=2  |	   |       |          |
		---------------------------------------
		| ++(**pp) | &p[1] | &A[2] | A[2] = 2 |
		|  A[2]=3  |	   |       |          |
		---------------------------------------
*/

#include <iostream>
#include <Windows.h>
#define N 5
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int A[N] = { 0,1,2,3,4 };
	int* p[N] = { A, A + 1, A + 2, A + 3, A + 4 };
	int** pp = p;
	
	cout << "pp : " << pp << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "&p[" << i << "] = " << &p[i];
		cout << " | p[" << i << "] = &A[" << i;
		cout << "] = " << p[i];
		cout << " | *p[" << i << "] = ";
		cout << *p[i] << endl;
	}
	// Виконуємо дію pp++
	cout << "pp++ = " << pp++ << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	// Виконуємо дію *++pp
	cout << "*++pp = " << *++pp << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	// Виконуємо дію *(++pp)
	cout << "*(++pp) = " << *(++pp) << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	// Виконуємо дію ++(*pp)
	cout << "++(*pp) = " << ++(*pp) << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "&p[" << i << "] = " << &p[i];
		cout << " | p[" << i << "] = " << p[i];
		cout << " | *p[" << i << "] = ";
		cout << *p[i] << endl;
	}
	// Виконуємо дію pp = p
	pp = p;
	cout << "pp = p = " << pp << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	// Виконуємо дію **++pp
	cout << "**++pp = " << **++pp << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	// Виконуємо дію *(++(*pp))
	cout << "*(++(*pp)) = " << *(++(*pp));
	cout << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "&p[" << i << "] = " << &p[i];
		cout << " | p[" << i << "] = " << p[i];
		cout << " | *p[" << i << "] = ";
		cout << *p[i] << endl;
	}
	// Виконуємо дію ++(**pp)
	cout << "++(**pp) = " << ++(**pp) << " : " << endl;
	cout << "pp = " << pp << " | *pp = ";
	cout << *pp << " | **pp = " << **pp << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "&p[" << i << "] = " << &p[i];
		cout << " | p[" << i << "] = " << p[i];
		cout << " | *p[" << i << "] = ";
		cout << *p[i] << endl;
	}

	cout << endl << "==============================";
	cout << "==============================" << endl;
	// Повертаємо в початковий стан 
	// указник на масив указників
	cout << "Повертаємо в початковий стан";
	cout << " указник на масив указників : " << endl;
	pp = p;
	cout << "pp : " << pp << endl;
	cout << "Повертаємо в початковий стан";
	cout << " масив указників : " << endl;
	// Повертаємо в початковий стан масив указників
	for (int i = 0; i < N; i++)
	{
		p[i] = &A[i];
		cout << "&p[" << i << "] = " << &p[i];
		cout << " | p[" << i << "] = &A[" << i;
		cout << "] = " << p[i];
		cout << " | *p[" << i << "] = ";
		cout << *p[i] << endl;
	}
}