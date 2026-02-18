// 2529: 부등호 -> long long 형을 알아보자
#include <iostream>
#include <vector>
#include <climits> // LONG_MAX / LONG_LONG_MAX 는 이거 필요 없음
using namespace std;

string s, pm, mins, maxs;
vector <bool> vis(10, false);
int N;
long minV = LONG_MAX, maxV = -10;

void perm(int depth){
    if(depth == N+1){
        long result = stoll(pm);
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

        //숫자 중복되면 안됨
        if(vis[i])
            continue;

        // 부등식이 안맞을 때 무시
        if(depth > 0){
            char a = s[depth-1];
            if(a == '<'){
                if(!(pm[depth-1]-'0' < i))
                    continue;
            }
            else{
                // ir가 증가해도 부등식이 안맞음
                if(!(pm[depth-1]-'0' > i))
                    return;    
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