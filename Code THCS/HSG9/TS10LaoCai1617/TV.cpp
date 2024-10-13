#include <iostream>

int median(int *ai, int *aj, int k) {
	int i = 0, j = 0;
	int count = 1;
	while (count < k) {
		ai[i] <= aj[j] ? i++ : j++;
		count++;
	}
	return ai[i] < aj[j] ? ai[i] : aj[j];
}


int main() {
	freopen("TV.inp", "r", stdin);
	freopen("TV.out", "w", stdout);
	int n,l;
	std::cin >> n >> l;
	int arr[n][l] = {{0}};
	int sum = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			std::cin >> arr[i][j];

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			sum += median(arr[i], arr[j], l);

	std::cout << "\nSum is: " << sum;
	return 0;
}
