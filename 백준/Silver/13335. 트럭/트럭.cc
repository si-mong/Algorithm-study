#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {

   int N, W, L;

   cin >> N >> W >> L;
   deque <int> d(W, 0);  // 다리 만들기
   int sum = 0, rst=0;
   vector<int> v;


   while (N--) {
      int n;
      cin >> n;
      v.push_back(n);
   }
   int i = 0;
   while (1) {
        if(i>=v.size()){
        int t=W;

        while(t--){
            d.push_back(0);
            d.pop_front();
            rst++;
        }
        break;
      }
      int n = v[i];
      sum += n;

      // 하중 내에 있을 때
      if (sum <= L) {            
            d.push_back(n);
            d.pop_front();
            sum -= d.front();
            rst++;
            i++;

            //cout << "==다리 위 상황==" << endl;
            //for(int a : d)
            //    cout << a << " ";
      }
      // 하중을 넘을 때
      else {
         d.push_back(0);
         d.pop_front();
         sum -= n;
         sum -= d.front();
         rst++;
      }

   }
   cout << rst;
}