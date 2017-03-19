//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: 
//Starting with any positive integer, 
//replace the number by the sum of the squares of its digits, 
//and repeat the process until the number equals 1 (where it will stay), 
//or it loops endlessly in a cycle which does not include 1. 
//Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
#include <unordered_map>

using namespace std;

bool isHappy(int n) {
	unordered_map<int, int> imap;
	while(true){
		int result = 0;
		while(0 != n){
			int temp = n % 10;
			result += temp * temp;
			n /= 10;
		}
		if(1 == result) return true;
		if(imap.find(result) == imap.end())
			imap[result];
		else
			break;
		n = result;
	}
	return false;
}