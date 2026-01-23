#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){

    string r;
    int stick=0, cnt=0;
    stack <char> st;

    cin >> r;

    for(char c:r){
        switch(c){
            case '(':
                st.push(c);
                cnt++;
                break;
            case ')':
                // 레이저일때
                if(st.top() == '('){
                    cnt--;
                    stick += cnt;
                    st.push(c);

                }
                // 막대기일때
                else{
                    st.push(c);
                    stick++;
                    cnt--;
                }
                break;
        }
    }
    cout << stick;
    return 0;
}