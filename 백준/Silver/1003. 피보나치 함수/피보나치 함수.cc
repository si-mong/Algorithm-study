#include <iostream>
using namespace std;

int main()
{
	int testcase, number;
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++)
	{
		cin >> number;

		int times_0[3] = { 1,0 }, times_1[3] = { 0,1 };

		if (number == 0)
			cout << times_0[number] << " " << times_1[number] << endl;

		else if (number == 1)
			cout << times_0[number] << " " << times_1[number] << endl;


		else if (number >= 2)
		{
			for (int j = 1; j < number; j++)
			{
				times_0[2] = times_0[0] + times_0[1];
				times_1[2] = times_1[0] + times_1[1];

				for (int j = 0; j < 2; j++)				// 다음 항의 계산을 위해 배열 갱신
				{
					times_0[j] = times_0[j + 1];
					times_1[j] = times_1[j + 1];
				}

			}
			cout << times_0[2] << " " << times_1[2] << endl;

		}
	}
}