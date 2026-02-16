// 15664: N과 M(10) -> 더 효율적인 방법 찾아보기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <int> v, cb, cnt(10, 0);
vector <bool> vis;

void comb(int depth, int start){
    if(depth == M){
        for(int a : cb)
            cout << a << " ";
        cout << "\n";
        return;
    }
    for(int i = start; i<v.size(); i++){
        cb.push_back(v[i]);
        comb(depth+1, i+1);
        cb.pop_back();

        int jp=0;
        for(int j = i+1; j<v.size(); j++){
            if(v[j-1] == v[j])
                jp++;
            else 
                break;
        }
        i+=jp;
    }
}

int main(){
    cin >> N >> M;
    while(N--){
        int n;
        cin >> n;
        v.push_back(n);
        cnt[n]++;
    }
    sort(v.begin(), v.end());
    comb(0, 0);
}