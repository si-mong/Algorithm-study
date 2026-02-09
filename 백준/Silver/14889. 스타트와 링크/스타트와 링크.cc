#include <iostream>
#include <vector>

using namespace std;

int N=0;
int r=0;
int minV = 100000;
vector <int> comb, arr;
vector <vector<int>> v;

void combination(int depth, int start){

    int sum1 = 0, sum2=0, result = 0;

    if(depth == r){
        // cout << "!!방문 시작!!" << endl;
        vector<int> isSel(N,0);

        // 조합 방문 
        // cout << "[조합]" << endl;
        for(int i=0; i< r; i++){

            // cout << comb[i] << endl;
            isSel[comb[i]] = 1;

            for(int j=i+1; j<r; j++){
                if(i==j)
                    continue;

                // cout << "v[comb[i]][comb[j]]: " << comb[i] << ", " << comb[j]<<endl;
                // cout << "sum1 += v[comb[i]][comb[j]] + v[comb[j]][comb[i]];" << endl;
                // cout << "==> " << sum1 << "+" << v[comb[i]][comb[j]] << " + " << v[comb[j]][comb[i]] << endl;

                sum1 += v[comb[i]][comb[j]] + v[comb[j]][comb[i]];

            }
        }
        vector<int> other;
        for(int i=0; i< N; i++){
            if(isSel[i])
                continue;
            other.push_back(i);
        }
        //방문 안한 곳 방문
        // cout << "조합의 합 sum1: " << sum1 << endl;
        // cout << "[또 다른 조합]" << endl;
        for(int i=0; i < r; i++){
            for(int j=i+1; j < r; j++){
                if(i==j)
                    continue;
                // cout << "v[other[i]][other[j]] " << i << ", " << j <<endl;
                // cout << "sum2 += v[other[i]][other[j]] + v[other[j]][other[i]]" << endl;
                // cout << "==> " << sum2 << "+" << v[other[i]][other[j]] << " + " << v[other[j]][other[i]] << endl;
                sum2 += v[other[i]][other[j]] + v[other[j]][other[i]];
            }
        }
        result = (sum1 > sum2) ? sum1 - sum2 : sum2 - sum1;
        // cout << "result: " << result << endl << endl;
        minV = (minV > result) ? result : minV;
        return;
    }
    for(int i= start; i < N; i++){
        comb[depth] = arr[i];
        combination(depth + 1, i + 1);
    }
}

int main(){

    cin >> N;
    r = N/2;
    comb.resize(r);
    vector<int> temp;

    // 행렬 입력
    for(int i=0; i<N; i++){
        // 중요함....
        temp.clear();
        arr.push_back(i);
        for(int j=0; j < N; j++){
            int n;
            cin >> n;
            temp.push_back(n);
        }
        v.push_back(temp);
    }

    // 조합 만들기
    // cout << endl << "조합 시작"<< endl;
    combination(0,0);
    cout << minV;
    return 0;
}