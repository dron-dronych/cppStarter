#include <iostream>
#include <cstdarg>

using namespace std;

/*
calculates min number of refills required to travel
from A to B, with gas station stops along the way
 */
int minRefills(int distance, int capacity, int n_stops, ...) {
	va_list arguments;
	va_start(arguments, n_stops);

	int stops [n_stops + 2]; // add origin & destination points to stops
	stops[0] = 0;
	stops[n_stops + 1] = distance;

	if (distance < 1 || distance > 100000) {
		throw "Distance is out of range [1, 100000]";
	}

	if (capacity < 1 || capacity > 400) {
		throw "Capacity is out of range [1, 400]";
	}

	if (n_stops < 1 || n_stops > 300) {
		throw "Num of stops out of range [1, 300]";
	
	}
	
	for (int i = 1; i <= n_stops; i++) {
		stops[i] = va_arg(arguments, int);

		if (stops[i] <= stops[i-1]) {
			throw "Every next stop must be > than previous!";
		}
	}

	if (distance <= stops[n_stops]) {
		throw "Destination must be greater than the final gas station!";
	}

	va_end(arguments);

	int position = 0;
	int numRefills = 0;

	while (position <= n_stops) {
		int lastRefill = position;

		while (position <= n_stops && stops[position + 1] - stops[lastRefill] <= capacity) {
			position++;
		}

		if (lastRefill == position) {
			return -1;
		}

		if (position <= n_stops) {
			numRefills++;
		}
	}

	return numRefills;

}

int main() {
	cout << minRefills(950, 400, 4, 200, 375, 550, 750) << endl;
	cout << minRefills(10, 3, 4, 1, 2, 5, 9) << endl;
	cout << minRefills(200, 250, 2, 100, 150) << endl;
	return 0;
}
