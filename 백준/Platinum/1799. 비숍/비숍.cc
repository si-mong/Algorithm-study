#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BS{
    int r;
    int c;
};

vector<BS> blackPos, whitePos;
vector<bool> pls, mns;

int N;
int maxV;

void comb(const vector<BS>& pos, int depth, int start){
    maxV = max(maxV, depth);

    for(int i = start; i < pos.size(); i++){
        int p = pos[i].r + pos[i].c;
        int m = pos[i].r - pos[i].c + N;

        if(pls[p] || mns[m]) continue;

        pls[p] = true;
        mns[m] = true;

        comb(pos, depth+1, i+1);

        pls[p] = false;
        mns[m] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int n;
            cin >> n;
            if(n == 1){
                if((i + j) % 2 == 0)
                    blackPos.push_back({i, j});
                else
                    whitePos.push_back({i, j});
            }
        }
    }

    pls.resize(N*2);
    mns.resize(N*2);

    // 검은 칸
    maxV = 0;
    comb(blackPos, 0, 0);
    int blackMax = maxV;

    fill(pls.begin(), pls.end(), false);
    fill(mns.begin(), mns.end(), false);

    // 흰 칸
    maxV = 0;
    comb(whitePos, 0, 0);
    int whiteMax = maxV;

    cout << blackMax + whiteMax;
}