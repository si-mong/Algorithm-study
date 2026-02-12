#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> v, comb;

void combination(int depth, int start){
    if(depth == M){
        for(int a : comb)
            cout << a << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < N; i++){
        comb[depth] = i+1;
        combination(depth+1, i);
    }
}
int main(){
    cin >> N >> M;
    comb.resize(M);
    combination(0, 0);
}
