#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
int con=0, vow=0; //자음, 모음
string v, cb;


void comb(int depth, int start){
    if(depth == L){
        if(con >= 2 && vow >=1)
            cout << cb << "\n";
        return;
    }
    for(int i=start; i < v.size(); i++){
        if(L - depth - 1  >= v.size() - i)
            return;

        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o'|| v[i] == 'u')
            vow++;
        else
            con++;

        cb.push_back(v[i]);
        comb(depth+1, i+1);

        if(cb.back() == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o'|| v[i] == 'u')
            vow--;
        else
            con--;

        cb.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // C는 주어진 알파벳수
    // L은 뽑을 수
    cin >> L >> C;

    while(C--){
        char n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    comb(0, 0);
}