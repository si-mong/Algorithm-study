#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int R, C, cnt=1, maxV= -10;
vector <string> bd;
vector <vector<bool>> vis;
vector <bool> ap(26);

void move(int row, int col){

    // 알파벳 방문 체크
    int a = bd[row][col] - 'A';
    // cout << "현재 위치: " << row << col << ": "  << bd[row][col] << endl;
    
    // 이미 방문한 알파벳이면 되돌아감.
    if(ap[a]){
        // cout << bd[row][col] << "는 이미 방문했으므로 돌아갑니다." << endl;
        return;
    }

    // 방문을 처음한다면 비트 체킹
    ap[a] = true;       // 해당 알파벳 방문함
    vis[row][col] = true;

    //상
    if(row-1 >= 0 && !vis[row-1][col]){
        // cout << "위로 이동\n";
        cnt++;
        move(row-1, col);
        cnt--;
    }

    //하
    if(row+1 < R && !vis[row+1][col]){
        // cout << "아래로 이동\n";
        cnt++;
        move(row+1, col);
        cnt--;
    }

    //좌
    if(col-1 >= 0 && !vis[row][col-1]){
        // cout << "좌로 이동\n";
        cnt++;
        move(row, col-1);
        cnt--;
    }
    //우
    if(col+1 < C && !vis[row][col+1]){
        // cout << "우로 이동\n";
        cnt++;
        move(row, col+1);
        cnt--;
    }
    maxV = (maxV < cnt) ? cnt : maxV;
    ap[a] = false;       // 해당 알파벳 방문함
    vis[row][col] = false;

    // cout << "돌아갑니다." << endl;
    return;
    // // 갈 곳이 없으면 cnt 저장 및 출력
    // if(!go){
    //     maxV = (maxV < cnt) ? cnt : maxV;
    //     return;
    // }
}

int main(){
    cin >> R >> C;

    string temp;
    int r=R;
    vis.resize(R, vector<bool>(C));

    while(r--){
        cin >> temp;
        bd.push_back(temp);
    }
    move(0, 0);
    cout << maxV;
}