/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

///////////////////////
// Ben Morledge-Hampton
// 
// Recursion
//
// 4/25/2017
///////////////////////

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {

	// If an empty vector is passed, return -1 to tell that the target is not in the list.
	if (last - first < 0)
		return -1;
	// If the center is less than the target, the target can only be above it, so recursively call the function with the values above the center.
	else if (items[(last + first) / 2] < target)
		return binary_search(items, (last + first) / 2 + 1, last, target);
	// If the center is greater than the target, the target can only be below it, so recursively call the function with the values below the center.
	else if (items[(last + first) / 2] > target)
		return binary_search(items, first, (last + first) / 2 - 1, target);
	// If you get this far, it means that the center is the target!  Hooray!
	else return ((last + first) / 2);

}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size()-1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
		haystack.push_back(rand());

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		} else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}