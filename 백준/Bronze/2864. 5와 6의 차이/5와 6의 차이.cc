#include <iostream>
#include <cmath>
using namespace std;

int _min(string s){
    int size = s.size();

    for(int i=0; i<size; i++)
        if(s[i]=='6')
            s[i]='5';
    
    return stoi(s);
}
int _max(string s){
    int size = s.size();

    for(int i=0; i<size; i++)
        if(s[i]=='5')
            s[i]='6';
    
    return stoi(s);
}
int main(){

    string A, B;
    cin >> A >> B;
    cout << _min(A) + _min(B) << " " << _max(A) + _max(B);

}