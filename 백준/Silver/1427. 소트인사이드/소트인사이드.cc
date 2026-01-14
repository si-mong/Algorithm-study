#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using std::string;

int main(){

    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);

    for(int i=0;i<n;i++)
        v[i] = s[i] - '0';

    sort(v.begin(), v.end(), greater<int>());

    for(int i=0;i<n;i++)
        cout << v[i];
}