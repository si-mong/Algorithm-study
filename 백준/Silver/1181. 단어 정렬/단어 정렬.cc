#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<string> r;
    vector<vector<string>> s(50);
    string temp, result;
    int N=0;
    cin >> N;

    for(int i=0; i<N;i++){
        cin >> temp;
        int idx = temp.size()-1;

        if(find(s[idx].begin(), s[idx].end(), temp) != s[idx].end())
            continue;
    
        s[idx].push_back(temp);
    }
    // 길이가 같은 것들끼리 사전 순으로 정렬
    for(int i=0; i<50; i++){
        
        sort(s[i].begin(), s[i].end());         
    }
    
    // 출력
    for(int i=0; i<50; i++){
        for(int j=0; j < s[i].size();j++){
           cout << s[i][j] << endl;
        }        
    }

    return 0;

}