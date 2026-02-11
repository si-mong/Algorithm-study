#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CT{
    int r;
    int c;
};

int N, M, n;
// N X N 행렬 만들기
vector <CT> ck, hs, comb;
vector <int> result;

void combination(int depth, int start){
    if(depth == M){
        // 조합 방문 
        // cout << "[조합]" << endl;
        int sum = 0;
        for(int i = 0; i < hs.size(); i++){
            int mn = 10000, dis=0;
    
            for(int j = 0 ; j < M; j++){
                dis = ((hs[i].r > comb[j].r) ?  (hs[i].r - comb[j].r) : comb[j].r - hs[i].r) 
                + ((hs[i].c > comb[j].c) ?  (hs[i].c- comb[j].c) : comb[j].c - hs[i].c);

                mn = (mn > dis) ? dis : mn;
            }
            sum += mn;
        }
        result.push_back(sum);
        return;
    }
    for(int i = start; i < ck.size(); i++){
        comb[depth] = ck[i];
        combination(depth + 1, i + 1);
    }
}

int main(){

    cin >> N >> M;

    vector<vector <int>> v (N, vector<int>(N));
    comb.resize(M);

    // 입력
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cin >> n;
            v[i][j] = n;
            if(n == 1)
                hs.push_back({i, j});
            else if(n == 2)
                ck.push_back({i, j});
        }
    }
    
    // cout << "입력 완료" << endl;

    combination(0,0);
    auto it = min_element(result.begin(), result.end());
    // int minValue = *it;
    
    cout << *it;

    return 0;
}