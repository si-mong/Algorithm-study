#include <stdio.h>
#include <stdlib.h>

int add_cycle(int num){

    int add=0, assemble=0;

    // 각 자리 수 합산
    add = num / 10 + num % 10;

    // 새로 만들어진 수랑 결합
    assemble = (num % 10 * 10) + add % 10;
    return assemble;
}

int main(){

    int num=0, result=0, time=0;
    scanf("%d", &num);
    result = num;

    do{
      result = add_cycle(result);
      time++;
    }
    while(result != num);

    printf("%d\n", time);

    return 0;
}