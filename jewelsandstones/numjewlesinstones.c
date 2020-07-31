# include "numjewlesinstones.h"

int numJewlesInStones(char* J, char* S){
	char down[26];
	char up[26];
	char* p = S;
	int index, sum = 0;
	while(*p){
		if(*p >= 'a'){
			index = *p - 'a';
			down[index] = down[index] + 1;
		} else {
			index = *p - 'A';
			up[index] = up[index] + 1;
		}
		p++;
	}
	p = J;
	while(*p){
		if(*p >= 'a'){
			index = *p - 'a';
			sum += down[index];
		} else {
			index = *p - 'A';
			sum += up[index];
		}
		p++;
	}
	return sum;

}