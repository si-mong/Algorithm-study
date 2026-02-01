#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k=0, sum=0;
    vector<int> v;

    cin >> k;

    while(k--){
        int n;
        cin >> n;

        if(n==0){
            v.pop_back();
        }
        else{
            v.push_back(n);
        }
    }
    for(int a : v){
        sum+=a;
    }
    cout << sum;
}