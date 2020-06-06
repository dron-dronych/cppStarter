#include <iostrem>
#include <cstdarg>

using namespace std;

int minRefills(int distance, int capacity, int n_stops, ...) {
	va_list arguments;
	int [n_stops] stops;

	for (int i = 0; i < n_stops; i++) {
		stops[i] = va_arg(arguments, int);
	}

	va_end(arguments);

}