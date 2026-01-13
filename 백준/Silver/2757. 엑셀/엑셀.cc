#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using std::string;

int main(){
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(1){
        string s, rs, cs, result;
        int size=0, ri=0, ci=0, i=1;

        cin >> s;
        if(s=="R0C0")
            break;

        // 행번호는 R 과 C 사이임 
        i=1;
        while(s[i]!='C')
            rs.push_back(s[i++]);
        
        ri = stoi(rs);

        // 열번호는 C 다음 부터 순회하면서 저장
        //i++;    // 현재 위치가 C니까 +1해줌
        size = s.size();
        for(int j=i+1; j<size; j++)
            cs.push_back(s[j]);
        ci = stoi(cs);

        int share=ci;
        cs = "";
        while(share){
            // cout << "몫:" << share << " 나머지:" << share % 26 << endl;
            share--;
            cs.push_back(al[share % 26]);
            share /= 26;
        }
        reverse(cs.begin(), cs.end());

        result = result + cs + to_string(ri);
        cout << result <<endl;

    }
    return 0;
}