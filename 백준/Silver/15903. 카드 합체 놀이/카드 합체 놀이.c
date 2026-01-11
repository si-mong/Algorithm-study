#include <stdio.h>
#include <stdlib.h>

int main(){

    long long int n, m, add, result;   // n은 카드의 수, m은 진행 횟수
    long long int idx[2]= {0};

    // 첫 번째 입력 - 카드의 수와 진행 횟수
    scanf("%lld %lld", &n, &m);
    long long int *arr = (long long int*)malloc(sizeof(long long int)*n);

    // 두 번째 입력 - 카드의 상태
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);

    // 카드 합치기 진행 - m번
    for(long long int j=0;j<m;j++){

        // 카드 중 바꿀 두 개 찾기
        for(int i=0; i<n;i++)
            if(arr[idx[0]] > arr[i])
                idx[0] = i;
        
        // 두 번째 최소 값
        if(idx[0] == 0)
            idx[1] = 1;

        for(int i=1; i<n;i++){
            if(idx[0]==i)
                continue;

            if(arr[idx[1]] > arr[i])
                idx[1] = i;
        }
        
        // 카드 합치기 진행
        add = arr[idx[0]] + arr[idx[1]];
        arr[idx[0]] = add;
        arr[idx[1]] = add;

    }

    // 최종 배열의 합 출력
    result = 0;
    for(int i =0; i<n; i++)
        result += arr[i];
    
    printf("%lld", result);

    free(arr);
    return 0;
}