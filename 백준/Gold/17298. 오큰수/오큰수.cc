#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct Ktop{
    int num;
    int idx;
};

int main(){
    int N, n;
    string result="", t;
    stack <Ktop> s;
    
    cin >> N;
    vector <int> rst(N, 0);

    for(int i=0; i<N; i++){
        cin >> n;
        if(!s.empty()){
            while(!s.empty() && s.top().num < n){
                rst[s.top().idx] = n;
                s.pop();
            }
        }
        s.push({n, i});
    }

    if(!s.empty()){
        while(!s.empty()){
            rst[s.top().idx] = -1;
            s.pop();
        }
    }
    for(int r : rst)
        cout << r << " ";

}