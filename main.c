#include <stdio.h>
#include "twoSum/twosum.h"
#include "jewelsandstones/numjewlesinstones.h"

int main(int argc, char const *argv[])
{
    char* J = "Aa";
    char* S = "a";
    int sum ;
    sum = numJewlesInStones(J, S);
    printf("%d", sum);
    return 0;
}
