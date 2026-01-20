#include <iostream>
#include <string>
using namespace std;

int main(){ 
    string s, b, st;
    cin >> s >> b;

    for(int i=0; i< s.size(); i++){
        st.push_back(s[i]);

        if((b[b.size()-1] == s[i]) && (st.size() >= b.size()) && (st.find(b, st.size()-b.size())!=string::npos))
            for(int j=0; j< b.size(); j++)
                    st.pop_back();
    }
    if(st.empty())
        cout << "FRULA" << endl;
    else
        cout << st;


}
