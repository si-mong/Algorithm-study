#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector <vector <char>> per;
int N, K;


void swap(char &a, char &b){
    // cout << "swap 진행 합니다: " << a << ", " << b << endl;
    char temp = a;
    a = b;
    b = temp;
}
void permutation(string data, int depth){
    vector <char> temp;
    // cout<< "depth: " << depth << endl;

    if(depth == N-1){
        for(int i=0; i < N-1; i++)
            temp.push_back(data[i]);
        per.push_back(temp);
        return;
    }

    for(int i=depth; i < N-1; i++){
        // cout << "i: " << i << ", data[i]: " << data[i] <<endl;
        swap(data[depth], data[i]);
        permutation(data, depth+1);
        swap(data[i], data[depth]);
    }
}
int main(){
    int n;
    vector <int> A, result;
    string cals;

    cin >> K;
    N = K;

    while(K--){
        cin >> n;
        A.push_back(n); 
    }

    for(int i=0; i < 4 ;i++){
        cin >> n;
        for(int j=0; j<n; j++){
            switch(i){
                case 0:
                    cals.push_back('+');
                    break;
                case 1:
                    cals.push_back('-');
                    break;
                case 2:
                    cals.push_back('*');
                    break;
                case 3:
                    cals.push_back('/');
                    break;
            }
        }
    }
    //////////// 입력 완료
    // cout << cals << endl;

    permutation(cals, 0);

    // cout << "순열 진행 완료" << endl;
    // for (const auto& row : per) {
    //     for (char c : row) {
    //         cout << c << " ";
    //     }
    //     cout << '\n';
    // }
    ////// 모두 연산 해서 최대, 최소 찾기

    for(const auto& row : per){
        int i=0;
        int sum = A[i++];
        for (char c : row) {
            switch(c){
                case '+':
                    sum += A[i++];
                    break;
                case '-':
                    sum -= A[i++];
                    break;
                case '*':
                    sum *= A[i++];

                    break;
                case '/':
                    sum /= A[i++];
                    break;
            }
        }
        result.push_back(sum);
    }
    auto p = minmax_element(result.begin(), result.end());
    int min = *p.first;
    int max = *p.second;

    cout << max << endl << min << endl;
}