#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> v, comb;
void combination(int depth, int start){
    if(depth == M){
        for(int m : comb)
            cout << m << " ";
        cout << "\n";
        return;
    }
    for(int i=start; i<N; i++){
        
        comb[depth] = v[i];
        combination(depth+1, i+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    comb.resize(M, 0);

    for(int i=0; i<N; i++){
        v.push_back(i+1);
    }

    combination(0, 0);
}