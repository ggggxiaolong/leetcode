#include <stdio.h>
#include "twoSum/twosum.h"
int main(){
    int arr[] = {3,2,4};
    int* r;
    r = twoSum(arr,3, 6);
    printf("[%d,%d]",r[0],r[1]);
    free(r);
}