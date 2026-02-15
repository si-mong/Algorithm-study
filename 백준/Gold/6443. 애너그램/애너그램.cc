// 6443: 애너그램
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s, ani;
vector <int> cnt(26, 0);
vector <bool> vis;

void anigma(int depth){
    if(depth == s.size()){
        cout << ani << "\n";
        return;
    }
    for(int i=0; i<s.size(); i++){
        // cout << "<" << depth << "번 자리 정하기>\n";
        // cout << "선택된 것: " << s[i] << ", 알파벳 인덱스: " << s[i] - 'a' << endl;
        // int j = s[i] - 'a';

        if(vis[i]){
            continue;
        }
       
        ani.push_back(s[i]);
        vis[i] = true;


        anigma(depth + 1);

        vis[i] = false;
        ani.pop_back();
        
        // 같은 depth에 한해서 동일 알파벳은 무시하도록 해야됨
        int con = 0;
        for(int t = i+1; t<s.size(); t++){
            if(s[t] == s[i])
                con++;
        }
        i += con;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    while(N--){
        cin >> s;
        sort(s.begin(), s.end());
        vis.resize(s.size(), 0);
        for(char a : s){
            int i = a - 'a';
            cnt[i]++;
        }
        anigma(0);
    }
}