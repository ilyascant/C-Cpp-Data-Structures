#include <stdio.h>
#include <limits.h>

#define MAX(a,b) (a > b ? a : b)

int maxSumArr (int A[], int l, int h){
    if (h <= l) return A[l];
    
    int mid = (l + h) / 2;
    int LEFT_RIGHT_MAX = MAX(maxSumArr(A, l, mid), maxSumArr(A, mid + 1, h)); 
    
    int LEFT_MAX = INT_MIN;
    int sum = 0;
    
    for(int i = mid; i >= l; i--){
        sum += A[i];
        if(sum > LEFT_MAX) LEFT_MAX = sum;
    }
    
    int RIGHT_MAX = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i <= h; i++){
        sum += A[i];
        if(sum > RIGHT_MAX) RIGHT_MAX = sum;
    }
    
    return MAX(LEFT_RIGHT_MAX, LEFT_MAX + RIGHT_MAX);
};

int main() {
    
    int numbers[] = {1, 5, -2, 6, -3, -4, 5, 3, -5, 4, 7};
    
    int N = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("%d\n",maxSumArr(numbers, 0, N -1));
    printf("END\n");
    


    return 0;
}