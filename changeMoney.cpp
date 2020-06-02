#include <iostream>
#include <algorithm>
using namespace std;

int changeMoney(int m) {
	if(m < 1 || m > 1000) {
		return 1;
	}
	int denominations [3] = {1, 5, 10};
	int remainder = m;
	int counter = 0;

	while(remainder > 0) {
		int diffs [3];
		int ids [3];
		int pos = 0;

		for(int d=0;  d < (sizeof(denominations) / sizeof(*denominations)); d++) {
			if(remainder - denominations[d] >= 0) {
				diffs[d] = m - denominations[d];
				ids[d] = pos;
				
				pos++;
			} else {
			diffs[d] = 10000; //hack to replace with big number
			}
		}

		int *min = min_element(begin(diffs), end(diffs));
		int bestPosition;

		// finding index of best position
		for (int i=0; i < (sizeof(diffs) / sizeof(*diffs)); i++) {
			if (diffs[i] == *min) {
				bestPosition = i;
				break;
			}
		}

		remainder -= denominations[bestPosition];
		counter++;

	}

	return counter;
}

int main() {
	int coins = changeMoney(999);
	cout << coins << endl;
	return 0;
}
