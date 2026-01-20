#include <iostream>
#include <string>
using namespace std;

int main(){ 
    string s, b, st;
    
    cin >> s >> b;
    //int prcnt = 0, cnt = 0;

    for(int i=0; i< s.size(); i++){
        st.push_back(s[i]);
        // cout << s[i];
        // cout << ", 스택상태: " << st; 
        // cout << ", 조건 식: " b[b.size()-1] << st.size() << ", " << b.size() << st.find(b)
        if((b[b.size()-1] == s[i]) && (st.size() >= b.size()) && (st.find(b, st.size()-b.size())!=string::npos))
            for(int j=0; j< b.size(); j++)
                    st.pop_back();
        //cout << endl << "제거 후: " << st << endl;
    }
    if(st.empty())
        cout << "FRULA" << endl;
    else
        cout << st;

}