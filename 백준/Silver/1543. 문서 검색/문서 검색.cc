#include <iostream>
#include <string>
using namespace std;

int main(){

    string doc, s;
    getline(cin, doc);
    getline(cin, s);

    int ds = doc.size(), ss = s.size(), cnt=0;
    size_t idx=0;

    while(idx+ss <= ds){
        idx = doc.find(s, idx);
        // 찾는 문자가 존재하면 계속 찾기
        if(idx != string::npos){
            idx += ss;
            cnt++;
        }
        else    // 없다면 걍 0
            break;
        if(ss <= 0)
            break;
    }
    cout << cnt;
    return 0;
}