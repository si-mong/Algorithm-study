#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Number{
    int numI;
    string numS;
};
int main(){
    vector<string> word = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten"
    };
    vector<Number> result;
    string M, N;
    cin >> M >> N;

    int m = stoi(M), n = stoi(N);

    // M <= N 사이의 숫자 -> 문자 형태로 저장
    for(int i=m; i<=n ;i++){
        if(i/10 > 0)
             result.push_back({i, word[i/10] + " " + word[i%10]});
        else
            result.push_back({i, word[i]});
    }
    int min, size = result.size();
    Number temp;
    // 사전 순으로 정렬
    for (int i = 0; i < size - 1; i++){
        min = i;
        for(int j = i+1; j < size; j++)
            if(result[min].numS > result[j].numS)
                min = j;
        
        temp = result[min];
        result[min] = result[i];
        result [i] = temp;
    }
    // 숫자로 출력
    for(int i=0; i<size; i++){
        cout << result[i].numI << " ";
        if((i+1)%10==0)
            cout << endl;
    }
}