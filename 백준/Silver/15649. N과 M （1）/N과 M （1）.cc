#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> arr, perm;
vector <bool> vis;

void permutation(int depth){
    if(depth == M){
        for(int i : perm){
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(vis[i])
            continue;

        vis[i] = true;
        perm.push_back(i);
        permutation(depth+1);
        perm.pop_back();
        vis[i] = false;
    
    }
}

int main(){

    ios::sync_with_stdio(false);   
    cin.tie(nullptr);

    cin >> N >> M;

    vis.resize(M, 0);
    //perm.resize(M, 0);

    for(int i=0; i<N; i++){
        arr.push_back(i+1);
    }
    permutation(0);

}