#include <iostream>
#include<string>
using namespace std;

int main()
{
	string number;
	int size, sum, count = 0;
	cin >> number;							// 한문자씩 저장됨 '1' '2' '3' ...
	
	string result = number;					// 반복문을 돌면서 raw값을 유자하기 위해서 별도의 배열 추가
		
	while (result.size() > 1)
	{
		sum = 0;
	

		for (size_t i = 0; i < result.size(); i++)  // 어차피 사이즈 만큼만 사용하니까 새로 선언필요x
		{
			
			sum += result[i] - '0';
		}
		
		result = to_string(sum);
		count++;
	}

	if ((result[0] - '0') % 3 == 0)
		cout << count << endl << "YES" << endl;
	else
		cout << count << endl << "NO" << endl;
}