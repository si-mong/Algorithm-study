#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N, M;
	int size, num, top, bottom;
	bool result = false;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		stack<int> s;
		cin >> size;   

		for (int j = 0; j < size; j++)
		{
			cin >> num;
			s.push(num);
		}
		top = s.top(); 
		s.pop();
		
		while (s.empty() != 1 && result != true)
		{
			bottom = s.top(); 
			s.pop();

			if (top > bottom)
				result = true;

			top = bottom;
		}
		
	}
	if (result == true) cout << "No";
	else cout << "Yes";
}