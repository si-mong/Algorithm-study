#include <iostream>
#include <deque>
using namespace std;

struct PRT{
    int idx;
    int num;
};

int main(){

    int t=0, N=0,num=0, find=0;

    cin >> t;

    while(t--){
        cin >> N;
        cin >> find;
        deque <PRT> q;
        int cnt = 0;
        
        for(int i=0; i<N;i++){
            cin >> num;
            q.push_back({i, num});
        }

        while(!q.empty()){
            int pflg=1;
            PRT cur = q.front();
            PRT temp;

            for(int i=1; i<q.size();i++){
                if(cur.num < q[i].num){
                    temp = q.front();
                    q.pop_front();
                    q.push_back(temp);
                    pflg = 0;
                    break;
                }
            }

            if(pflg){
                temp = q.front();
                q.pop_front();
                cnt++;
                
                if(temp.idx == find){
                    cout << cnt << endl;
                    break;
                }
            }

        }
    }
}