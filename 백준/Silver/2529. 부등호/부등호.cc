#include <iostream>
#include <vector>
using namespace std;

string s, pm, mins, maxs;
vector <bool> vis(10, false);
int N;
long long minV = __LONG_LONG_MAX__, maxV = -10;

void perm(int depth){
    // cout << "==현재 depth: " << depth << "==" << endl;
    if(depth == N+1){
        long long result = stoll(pm);
        if(minV > result){
            minV = result;
            mins = pm;
        }
        if(maxV < result){
            maxV = result;
            maxs = pm;
        }
        return;
    }
    for(int i=0; i<10; i++){
        //0번째 짜리면 0은 되면 안됨
        //숫자 중복되면 안됨
        // cout << "선택한 숫자: " << i << endl;

        if(vis[i]){
            // cout << "이미 방문했으니 건너띄겠음" <<endl;
            continue;
        }

        // 부등식이 안맞을 때 무시
        if(depth > 0){
            // cout << "부등식 조사를 진행합니다.\n";
            char a = s[depth-1];
            if(a == '<'){
                // cout << pm[depth-1]-'0' << " < " << i <<endl;
                if(!(pm[depth-1]-'0' < i)){
                    // cout << "부등호가 안맞음\n";
                    continue;
                }
            }
            else{
                // ir가 증가해도 부등식이 안맞음
                if(!(pm[depth-1]-'0' > i)){
                    // cout << pm[depth-1]-'0' << " > " << i <<endl;
                    // cout << "부등호가 계속 안맞을 거임!" <<endl;
                    return;
                }
            }
        }

        vis[i]=true;
        pm.push_back(i + '0');

        perm(depth+1);

        vis[i]=false;
        pm.pop_back();
    }
}

int main(){
    cin >> N;
    int n = N;
    char c;
    while(n--){
        cin >> c;
        s.push_back(c);
    }
    perm(0);
    cout << maxs << endl << mins << endl;
}