#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    stack <int> s;
    vector<int> num, rsnum;
    string result;

    int m, t, n=1, psn=0;

    cin >> t;

    while(t--){
        cin >> m;
        num.push_back(m);
    }
    for(int i : num){
        // cout << "현재 요소 i: " << i << ", 누적 push 횟수: " << psn <<endl;
    
        if(i > psn){
            int j = i - psn;
            // cout << "진행할 push 횟수: "<< j << endl;
            
            while(j--){
                s.push(n++);
                result += "+\n";
                psn++;                
            }
            rsnum.push_back(s.top());
            s.pop();
            result += "-\n";

        }
        else{
            // cout << "pop 한 번만 진행" << endl;
            rsnum.push_back(s.top());
            s.pop();
            result += "-\n";
        }
    }
    if(num == rsnum)
        cout << result <<endl;
    else
        cout << "NO" << endl;    

}