#include <iostream>
using namespace std;

int main()
{
	int testcase, k, n;
	int arr_number[15] = {};
	int arr_number2[15] = {};

	cin >> testcase;
	int* T = new int[testcase];


	for (int t = 0; t < testcase; t++)
	{
		cin >> k >> n;
	
		int number = 0;
		for (int i = 1; i <= n; i++)
		{
			number = number + i;
			arr_number[i] = number;
		}
		if (k <= 1)			
		{
			T[t] = arr_number[n];
		}
		else if (k > 1)
		{
			for (int i = 1; i < k; i++)			// 층수만큼 반복
			{
				arr_number2[1] = 1;
				for (int j = 1; j <= n; j++)
				{
					arr_number2[j + 1] = arr_number2[j] + arr_number[j + 1];
				}
				for (int j = 1; j <= n; j++)
				{
					arr_number[j] = arr_number2[j];
				}

				T[t] = arr_number[n];
			}
		}
	}
	for (int t = 0; t < testcase; t++)
		cout << T[t] << endl;

	delete[]T;
}