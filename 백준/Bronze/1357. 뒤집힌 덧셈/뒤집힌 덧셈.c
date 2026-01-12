#include <stdio.h>

int rev(int num){
    int n=1000, result=0, i=1;

    while(n > 0){
        if((num / n) == 0){
            n /= 10;
            continue;   
        }
        result += num / n % 10 * i;
        n = n / 10;
        i = i * 10;
    }
    return result;

}
int main(){

    int x=0, y=0, total=0;
    scanf("%d %d", &x, &y);
    total = rev(rev(x)+rev(y));
    printf("%d", total);
    return 0;

}