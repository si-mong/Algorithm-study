#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int x=0, top=1, half=0, sum=0;
    int stick[50]={64,0};

    cin >> x;

    if(x == 64){
        cout << top;
        return 0;
    }

    while(1){
        
        // 가장 작은 막대 찾기
        sort(stick, stick + top, [](int a, int b) {
            return a > b;   // 내림차순
        });

        // 절반으로 자르기
        half = stick[top-1] / 2;
        stick[top-1] = half;
        stick[top++] = half;

        sum=0;
        for(int i=0; i<top-1; i++)
            sum += stick[i];
        
        if(sum > x)
            stick[(top--)-1]=0;

        else if(sum == x){
            cout << top-1 << endl;
            break;
        }
    }
    return 0;
}