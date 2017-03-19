//Compare Version Numbers
//
//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//0.1 < 1.1 < 1.2 < 13.37

#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int compareVersion(string version1, string version2) {
	vector<int> ver1, ver2;
	ver1.push_back(-1);
	ver2.push_back(-1);
	for(int i = 0; i != version1.size(); ++i){
		if('.' == version1[i]){
			ver1.push_back(i);
		}
	}
	for(int i = 0; i != version2.size(); ++i){
		if('.' == version2[i]){
			ver2.push_back(i);
		}
	}
	ver1.push_back(version1.size());
	ver2.push_back(version2.size());
	int i = 0;
	for(; i < ver1.size() - 1 || i < ver2.size() - 1; ++i){
		int num1 = 0, num2 = 0;
		if(i < ver1.size() - 1){
			string tempStr1 = version1.substr(ver1[i] + 1, ver1[i + 1] - ver1[i]);
			num1 = atoi(tempStr1.c_str());
		}
		if(i < ver2.size() - 1){
			string tempStr2 = version2.substr(ver2[i] + 1, ver2[i + 1] - ver2[i]);
			num2 = atoi(tempStr2.c_str());
		}
		if(num1 > num2)
			return 1;
		else if(num1 < num2)
			return -1;
	}
	return 0;
}