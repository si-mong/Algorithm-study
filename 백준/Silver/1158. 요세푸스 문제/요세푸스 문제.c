#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){

    int N=0, K=0, idx=0, cnt=0;
    int* check;

    int loop = 0;

    scanf("%d %d", &N, &K);

    check = calloc(N+1, sizeof(int));

    printf("<");

    while(cnt != N){
        
        // 아직 안나간 것들 중에서 다음 위치 찾기
        loop = 0;

        while(loop < K){
            //printf("loop: %d", loop);

                    // 인덱스 조절
            if(idx >= N)
                idx -= N;

            if(check[idx+1]==0){
                idx++;
                loop++;
            }
            else{
                idx++;
            }


        }

        // 인덱스 조절
        if(idx > N)
            idx -= N;

        if(check[idx] == 0){
            check[idx] = 1;
            printf("%d", idx);
            cnt++;

            if(cnt < N)
            {
                printf(", ");
            }

        }
    }
    printf(">");
    
}