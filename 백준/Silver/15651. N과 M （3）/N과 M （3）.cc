#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> perm;

void permutation(int depth){
    if(depth == M){
        for(int a : perm)
            cout << a <<" ";
        cout << "\n";
        return;
    }
    // 중복을 허용하니까 visted 필요없을 듯
    for(int i=1; i<=N; i++){
        perm[depth] = i;
        permutation(depth+1);
    }
}
int main(){
    cin >> N >> M;
    perm.resize(M);
    permutation(0);
}