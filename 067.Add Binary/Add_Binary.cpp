//Given two binary strings, 
//return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include <string>

using namespace std;

string addBinary(string a, string b) {
	string::reverse_iterator aIter = a.rbegin();
	string::reverse_iterator bIter = b.rbegin();
	string result;
	int point = 0;
	while(aIter != a.rend() || bIter != b.rend() || 1 == point){
		int aNum = (aIter == a.rend()) ? 0 : *aIter++ - '0';
		int bNum = (bIter == b.rend()) ? 0 : *bIter++ - '0';
		int tmp = aNum + bNum + point;
		result.insert(result.begin(), tmp % 2 + '0');
		point = tmp / 2;
	}
	return result;
}