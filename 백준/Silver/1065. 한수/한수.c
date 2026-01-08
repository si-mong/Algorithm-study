#include <stdio.h>
#include <stdlib.h>

int main(){

    int num = 0, cnt = 0;
    int th, h, t, o;

    scanf("%d", &num);

    for(int i=1;i<=num;i++){

        // 각 자리수 다 분리하기
        th = i / 1000;
        h = i / 100 % 10;
        t = i / 10 % 10;
        o = i % 100 % 10;
        
        // 일의자리수랑 십의자리수는 무조건 한수임 
        if(th == 0 && h == 0){
            cnt++;
            continue;
        }
        else if(th == 0 && h == 0 && t == 0){
            cnt++;
            continue;
        }

        // 세 자리 일 때
        if((th == 0)&& (h - t == t - o)){
            cnt++;
            continue;
        }
        // 1000까지만 입력받으니까 천의 자리는 처리하지 않았음
    }
    
    printf("%d\n", cnt);
    return 0;
}