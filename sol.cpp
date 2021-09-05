#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// create a separate list of odd and even numbers
		vector<int> even, odd;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				even.push_back(a[i]);
			} else {
				odd.push_back(a[i]);
			}
		}
		int even_index = 0;
		int odd_index = 0;
		a.clear();
		// place the even numbers in odd indices (1-based), while odd numbers in even indices (1-based)
		for (int i = 0; i < n; i++) {
			if ((i + 1) & 1 && even_index < (int) even.size()) {
				a.push_back(even[even_index++]);
			} else if ((i + 1) % 2 == 0 && odd_index < (int) odd.size()) {
				a.push_back(odd[odd_index++]);
			}
		}
		// store the remaining elements
		while (even_index < (int) even.size()) {
			a.push_back(even[even_index++]);
		}
		while (odd_index < (int) odd.size()) {
			a.push_back(odd[odd_index++]);
		}
		// calculate the sum based on the formula in the problem statement
		int sum = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			sum += ((a[i] + (i + 1)) % 2);
		}
		cout << sum << '\n';
	}
	return 0;
}
