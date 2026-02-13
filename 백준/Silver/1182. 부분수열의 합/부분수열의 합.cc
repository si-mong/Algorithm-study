// 1182: 부분수열의 합 - 스터디
#include <iostream>
#include <vector>
using namespace std;

int N, S, cnt=0;
vector <int> v, comb;

void combination(int depth, int start, int num){
    if(depth == num){
        int num=0;
        for(int a : comb)
            num+=a;
        if(num == S)
            cnt++;
    }
    for(int i = start; i < N; i++){
        //comb[depth] = v[i];
        comb.push_back(v[i]);
        combination(depth+1, i+1, num);
        comb.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    int n;
    for(int i=0; i<N; i++){
        cin >> n;
        v.push_back(n);
    }
    for(int i=1; i <= N; i++){
        //comb.resize(i);
        combination(0,0,i);
    }
    cout << cnt;
}
