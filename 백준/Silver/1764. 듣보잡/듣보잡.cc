#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    string temp;
    vector<string> nh, result;
    
    // 듣도 못한 사람 입력
    for(int i=0; i<N;i++){
        cin >> temp;
        nh.push_back(temp);
    }
    sort(nh.begin(), nh.end());

    // 보도 못한 사람 입력
    for(int i=0; i<M;i++){
        cin >> temp;
        if(binary_search(nh.begin(), nh.end(), temp))
            result.push_back(temp);
    }
    sort(result.begin(),result.end());
    cout << result.size() << endl;
    for(const string& s : result)
        cout << s << endl;   
    
    return 0;
}

