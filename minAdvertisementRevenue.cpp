/* Given two sequences a 1 , a 2 , . . . , a n (a i is the profit per click of
the i-th ad) and b 1 , b 2 , . . . , b n (b i is the average number of clicks 
per day of the i-th slot), we need to partition them into n pairs (a i , b j ) 
such that the sum of their products is maximized.
 
 implemented with data structures from stdlib
 */

#include <vector>
#include <bits/stdc++.h>
using namespace std;

 int minAdvertisementRevenue(int numAds,
		 vector <int> profits,
		 vector <int> clicks) {
	int numProfits = sizeof(profits) / sizeof(profits[0]);
	int numClicks = sizeof(clicks) / sizeof(clicks[0]);
	int revenue = 0;

	sort(profits.begin(), profits.begin() + numProfits);
	sort(clicks.begin(), clicks.begin() + numClicks);

	for (int i; i <= numProfits; i++) {
		for (int j; j <= numClicks; j++) {
			if (i != j) {
				continue;
			}

			else {
				revenue += profits[i] * clicks[j];
			}
		}
	}

	return revenue;

	
 }

 int main() {
	vector <int> profits = {1, 3, -5};
	vector <int> clicks = {-2, 4, 1};

 	minAdvertisementRevenue(3, profits, clicks);
 }

