// N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <vector<int>> result;
vector<int> v, perm;
vector<bool> vis;

void permutation(int depth){

    if(depth == M){
        result.push_back(perm);
        return;
    }
    for(int i=0; i<N; i++){
        if(vis[i])
            continue;
            
        vis[i] = true;
        perm.push_back(v[i]);
        permutation(depth+1);
        perm.pop_back();
        vis[i] = false;   
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int nn = N, n=0;
    vis.resize(N);  // N개 중에 M개를 뽑아야되니까 N크기의 방문 배열이 필요함

    while(nn--){
        cin >> n;
        v.push_back(n);
    }
    permutation(0);

    sort(result.begin(), result.end());

    for(vector <int> a : result){
        for(int b : a)
            cout << b << " ";
        cout << "\n";
    }
}