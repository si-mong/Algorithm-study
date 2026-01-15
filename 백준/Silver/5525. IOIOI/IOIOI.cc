#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    string s, sn = "I";

    cin >> N >> M >> s;

    // Sn 문자열을 만들어줌
    for(int i=0; i< N; i++)
        sn += "OI";

    // 전체 문자열에서 검색, 존재하면 시작 인덱스 +2, 없으면 종료
    int idx=0, cnt=0;
    while(1){
        if((idx = s.find(sn, idx))!= string::npos){
            cnt++;
            idx +=2;
        }
        else
            break;
    }
    cout << cnt;
}