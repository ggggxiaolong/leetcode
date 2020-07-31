#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target) {
    int *res = (int*)malloc(2*sizeof(int));
    int i, j, done = 0;
    for(i = 0; i< numsSize -1; i++){
        for(j = i + 1; j< numsSize; j++){
            if(nums[i] + nums[j] == target){
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}