#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int knapSack(int capacity, int weights[], int values[], int n) { // n is the number of items
	
	int i, j;
	vector<vector<int>> K(n + 1, vector<int>(capacity + 1));

	for (i = 0; i <= n; i++) { //check every item
		for (j = 0; j <= capacity; j++) { //check every capacity
			if (i == 0 || j == 0) {
				K[i][j] = 0;
			}
			else if (weights[i - 1] <= j) { //if the item weights less than the capcity, there's a chance to fit it into the bag
				K[i][j] = max(values[i - 1] + K[i - 1][j - weights[i - 1]], K[i - 1][j]); //compare and find out if the new item can add to a higher value in total
			}
			else {
				K[i][j] = K[i - 1][j]; //else we dont include the item and the current capicity stay the same
			}
		}
	}
	return K[n][capacity];
}

int main() {
	int values[] = { 200, 300, 110, 210, 330, 80, 250 };
	int weights[] = { 50, 30, 10, 80, 200, 15, 110 };
	int capacity = 280;
	int numItems = sizeof(values) / sizeof(values[0]);

	cout << knapSack(capacity, weights, values, numItems);
	return 0;
}