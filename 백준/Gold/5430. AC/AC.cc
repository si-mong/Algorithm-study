#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    // R을 기준으로 cnt++
    int t, n;
    string x, p;
    cin >> t;
    
    while(t--){

        // 수행할 함수 p 입력
        int erflag = 0;
        int cnt = 0;
        cin >> p;
        cin >> n;
        cin >> x;  
        
        deque <int> dq;
        
        // "[ , , , ]" 형태에서 숫자만 뽑아서 벡터에 저장
        if(x!="[]"){
            x = x.substr(1, x.size()-2);

            //vector<int> v;
            stringstream ss(x);
            string token;

            while(getline(ss, token, ',')){
                dq.push_back(stoi(token));
            }
        }

        // 문자열 분리 종료
        for(char c : p){
            // cout << "현재: " << c << endl;
            if(c == 'R'){
                cnt++;
                // cout << "reverse -> cnt++: "<< cnt << endl;
            }
            else if(!dq.empty() && cnt%2==0){
                dq.pop_front();
                // cout << "삭제 -> cnt가 짝수이므로 앞에서 삭제" << endl;
            }
            else if(!dq.empty() && cnt%2==1){
                dq.pop_back();
                // cout << "삭제 -> cnt가 홀수이므로 뒤에서 삭제" << endl;
            }
            else{
                // cout << "덱이 비어있으므로 에러" << endl;
                erflag = 1;
                break;
            }
        }
        if(erflag){
            cout << "error" << endl;
            continue;
        }
        if(dq.empty())
            cout << "[]" << endl;
        else{
            cout << "[";    
            if(cnt%2==1){
                for(int i=dq.size()-1; i>=0; i--){
                    cout << dq[i];
                    if(i!=0)
                        cout << ",";
                }
            }
            else{
                for(int i=0; i<dq.size(); i++){
                    cout << dq[i];
                    if(i!=dq.size()-1)
                        cout << ",";
                }
            }
            cout << "]" << endl; 
        }
    }
}