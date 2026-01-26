#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Ktop{
    int num;
    int idx;
};

int main(){

    int N, n=0;

    vector<Ktop> k;
    string result = "";
    string ts = "";

    cin >> N; 
    
    for(int i=0; i < N; i++){
        
        cin >> n;

        // 비어있는 경우  
        if(k.empty())
            result += "0";
        

        // 비어있지 않은 경우
        else{
            while(!k.empty() && k.back().num < n)
                k.pop_back();
            
            if(k.empty()){
                result += "0";
            }
            else{
                ts = to_string(k.back().idx);
                result += ts;
            }

        }
        
        k.push_back({n, i+1});

        if(i != N-1)
            result += " ";

    }
    cout << result;
}