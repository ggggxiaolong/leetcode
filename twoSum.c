#include <stdio.h>
int* twoSum(int* , int, int);
int main(){
    int arr[] = {3,2,4};
    int* r;
    r = twoSum(arr,3, 6);
    printf("[%d,%d]",r[0],r[1]);
}

int* twoSum(int* nums, int numsSize, int target) {
    int *res = (int*)malloc(2*sizeof(int));
    int i, j, done = 0;
    for(i = 0; i< numsSize -1; i++){
        for(j = i + 1; j< numsSize; j++){
            if(nums[i] + nums[j] == target){
                res[0] = i;
                res[1] = j;
                done = 1;
                break;
            }
        }
        if(done == 1){
            break;
        }
    }
    return res;
}