#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int value_col(char* col);
void mul_num(char* col, char* result);

int value_col(char* col){

    if(strcmp("black", col)==0)
        return 0;

    else if(strcmp("brown", col)==0)
        return 1;

    else if(strcmp("red", col)==0)
        return 2;

    else if(strcmp("orange", col)==0)
        return 3;

    else if(strcmp("yellow", col)==0)
        return 4;

    else if(strcmp("green", col)==0)
        return 5;

    else if(strcmp("blue", col)==0)
        return 6;

    else if(strcmp("violet", col)==0)
        return 7;

    else if(strcmp("grey", col)==0)
        return 8;

    else if(strcmp("white", col)==0)
        return 9;

    else{
        printf("ERROR\n");
        exit(0);
    }
}

int main() {

    char color1[20], color2[20], color3[20];
    //char result[20];
    long long result=0;

    scanf("%s", color1);
    scanf("%s", color2);
    scanf("%s", color3);


    //return_col = value_col(color1);
    // 순서대로 연산하기
    result=10*value_col(color1)+value_col(color2);
    result*=pow(10, value_col(color3));
    printf("%lld\n", result);

    // 정수를 문자열로 변환
    // sprintf(result, "%d", result_num);

    // 세 번째 곱하기
    // mul_num(color3, result);
    // printf("%s\n", result);
}