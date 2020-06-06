#include <iostream>
#include <cstdarg>

using namespace std;

int minRefills(int distance, int capacity, int n_stops, ...) {
	va_list arguments;
	int stops [n_stops];

	for (int i = 0; i < n_stops; i++) {
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

		if (lastRefill <= n_stops) {
			numRefills++;
		}
	}

	return numRefills;

}

int main() {
	cout << minRefills(950, 400, 4, 200, 375, 550, 750) << endl;
	return 0;
}