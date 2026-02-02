#include <iostream>
#include <list>
using namespace std;

int main(){
    list <string> li, lo;
    int N, N2;
    string s;

    cin >> N;
    N2=N;

    while(N--){
        cin >> s;
        li.push_front(s);

    }
    while(N2--){
        cin >> s;
        lo.push_front(s);
    }
    auto it = li.begin();
    int cnt = 0;

    while(!li.empty()){
        int c=0;
        for(auto i = lo.begin(); i != lo.end(); i++){
            if(c==0 && *it != *i){
                cnt++;
                c++;
            }
            if(*it == *i){
                it = li.erase(it);  // 다음요소 자동으로 가르킴
                i = lo.erase(i);
                break;
            }
        }
    }
    cout << cnt <<endl;
}