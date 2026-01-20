#include <iostream>
#include<string>
#include <vector>
using namespace std;

int main(){

    int k, t;
	string w, temp, str;
    vector <string> result;
    cin >> t;

    // t번 반복
    for(int i=0; i<t; i++){
        cin >> w >> k;
        
        vector<vector<int>> alpha (26);
        vector<string> result;

        int alp=0, sti=0, edi = 0, size=0;
        int min =0, max=0, cnt=0;

        for(int a=0; a < w.size(); a++){
            
            alp = w[a] - 'a';

            alpha[alp].push_back(a);    // 해당 알파벳 자리에 현재 인덱스 저장
            
            if(alpha[alp].size()>=k){
                sti = alpha[alp][alpha[alp].size() - k];
                edi = a;
                size = edi - sti + 1;

                if(cnt == 0 || min > size)
                    min = size;
                
                if((cnt == 0) || (max < size))
                    max = size;

                cnt++;
            }
        }
        if(min == 0)
            cout << -1;
        else
            cout << min << " " << max;
        
        cout <<endl;
    }
}