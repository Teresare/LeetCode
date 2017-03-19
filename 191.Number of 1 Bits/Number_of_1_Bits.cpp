//Write a function that takes an unsigned integer and returns the number of '1' bits 
//it has (also known as the Hamming weight).
//
//For example, the 32-bit integer '11' 
//has binary representation 00000000000000000000000000001011, 
//so the function should return 3.

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n) {
	int count = 0;
	while(0 != n){
		if(0 != n % 2)
			++count;
		n /= 2;
	}
	return count;
}