#include <vector>

using namespace std;

int numTrees(int n){
	vector<int> ary(n + 1, 0);
	ary[0] = 1;
	ary[1] = 1;

	for(int i = 2; i != n + 1; ++i)
		for(int j = 1; j != i + 1; ++j)
			ary[i] += ary[j - 1] * ary[i - j];
	
	return ary[n];
}