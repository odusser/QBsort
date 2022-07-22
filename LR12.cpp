#include <Windows.h>
#include <stdio.h> 
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#define N 999
using namespace std;


//Declaring prototype functions
void rmas(int n, int mas[N]);
int* quick(int* s, int low, int hi);
int LineS(int a[N], int size, int key);


int main()
{
	

	//entering array data and checking it

	int  n, a, b;
	cout << " n : the number of array elements \n a,b : limits of random numbers \n ";
pos1: cout << "Input n<1000 : ";
	cin >> n;
	if (n > 999) { goto pos1; }
pos2: cout << "Input a : ";
	cin >> a;
	cout << "Input b : ";
	cin >> b;
	if (a > b) { goto pos2; }

	
	//creation and filling of a dynamic array
	int* mas;
	mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = a + rand() % (b - a + 1);
	}
	//array output using a function
	rmas(n, mas);
	//Search for the number entered by the user in the array by calling its own function
	int Numb;
	cout << "Input number for search : ";
	cin >> Numb;
	cout << "i = " << LineS(mas, n, Numb) << endl;
	//array output using a function
	rmas(n, mas);
	//Bubble array sorting
clock_t tic = clock();
	for (int i = 0; i < n; i++)
	{
		int amax = i;
		for(int j=i+1;j<n;j++)
		{
			if (mas[j] > mas[amax]) { amax = j; }
		}
		int t = mas[i];
		mas[i] = mas[amax];
		mas[amax] = t;
	}
	//array output using a function
	rmas(n, mas);
	clock_t toc = clock();
    //Let's calculate the time spent on sorting the array and its output
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	cout << endl;





//entering array data and checking it

pos11: cout << "Input n<1000 : ";
	cin >> n;
	if (n > 999) { goto pos11; }
pos22: cout << "Input a : ";
	cin >> a;
	cout << "Input b : ";
	cin >> b;
	if (a > b) { goto pos22; }

	//creation and filling of a dynamic array
	int* mas1;
	mas1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = a + rand() % (b - a + 1);
	}
	//array output using a function
	rmas(n, mas1);
	clock_t tic1 = clock();
	//A call to the array output function in the middle of which is a call to the array quicksort function
	rmas(n,quick(mas1, 0, n-1));
	clock_t toc1 = clock();

	//Let's calculate the time spent on sorting the array and its output
	printf("Elapsed: %f seconds\n", (double)(toc1 - tic1) / CLOCKS_PER_SEC);

    return 0;
	delete mas;
	delete mas1;
}

//linear search function
int LineS(int a[N], int size, int key)
{
	for (int i = 0; i < size; i++)
		if (a[i] == key)
			return i;
	return -1;
}

//array element output function
void rmas(int n, int mas[N])
{
	cout << "------------------------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
}

//quicksort function
int* quick(int* s, int low, int hi)
{
	double cnt, aux;
		int i, j;
		if (hi > low)
		{
			i = low; j = hi;
				cnt = s[i];
			while (i < j)
			{
				if (s[i + 1] >= cnt)
				{
					s[i] = s[i + 1];
					s[i + 1] = cnt;
					i++;
				}
				else {
					if (s[j] >= cnt)
					{
						aux = s[j];
						s[j] = s[i + 1];
						s[i + 1] = aux;
					}
					j--;
				}
			}
			quick(s, low, i - 1);
			quick(s, i + 1, hi);
		}
	return(s);
}