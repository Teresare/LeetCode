//Best_Time_to_Buy_and_Sell_Stock
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction 
//(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
	if(prices.size() < 2) return 0;
	int profit = 0;
	int cur_min = prices[0];
	for(int i = 1; i < prices.size(); ++i){
		profit = max(profit, prices[i] - cur_min);
		cur_min = min(prices[i], cur_min);
	}
	return profit;
}