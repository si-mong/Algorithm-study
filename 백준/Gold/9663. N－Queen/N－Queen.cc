#include <iostream>
#include <vector>
using namespace std;

int N, result=0;
vector <vector<bool>> vis;
vector <bool> col;


void comb(int row){
    // cout << "===현재 행: " << row << "==="<< endl;
    if(row == N){
        // cout << "조합이 완성됨 result++ 진행\n\n";
        result++;
        return;
    }    
    for(int i = 0; i<N; i++){
        // cout << "현재 위치: " << row << ", " << i << endl;

        // 열 확인
        if(col[i])
            continue;
        
        // cout << "* 열 공격 가능" << endl;

        // 대각선 확인
        // cout << "대각선을 확인합니다!" << endl;
        int j=1;
        bool ck=false;
         
        //좌상
        while(row-j >=0 && i-j >= 0){
            if(vis[row-j][i-j])
                ck=true;
            j++;
        }
        if(ck)
            continue;

        //우상
        ck = false;
        j = 1;
        while( row-j >= 0 && i+j < N){
            if(vis[row-j][i+j])
                ck=true;
            j++;
        }
        if(ck)
            continue;

        // cout << "대각선 공격 가능, 다음 행으로 이동합니다.\n";
        // 공격 가능할 때만 방문표시 해야됨!!!!
        vis[row][i] = true;
        col[i] = true;

        comb(row+1);

        vis[row][i] = false;
        col[i] = false;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vis.resize(N, vector<bool>(N,false));
    col.resize(N, false);

    comb(0);
    cout << result;
}