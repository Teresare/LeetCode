#include <cmath>

using namespace std;
int trailingZeroes(int n) {
	const int base = 5;
	int result = 0;
	int exp = 1;
	while(true){
		int temp = n / static_cast<int>(pow(base, exp++));
		if(temp)
			result += temp;
		else
			break;
	}
	return result;
}