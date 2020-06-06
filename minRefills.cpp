#include <iostream>
#include <cstdarg>

using namespace std;

int minRefills(int distance, int capacity, int n_stops, ...) {
	va_list arguments;
	va_start(arguments, n_stops);

	int stops [n_stops + 2]; // add origin & destination points to stops
	stops[0] = 0;
	stops[n_stops + 1] = distance;

	for (int i = 1; i <= n_stops; i++) {
		stops[i] = va_arg(arguments, int);
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