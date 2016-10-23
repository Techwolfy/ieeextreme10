#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A function to print all prime factors of a given number n
vector<long> primeFactors(long n) {
	vector<long> v;
	// Print the number of 2s that divide n
	while(n % 2 == 0) {
		n = n/2;
		v.push_back(2);
	}

	// n must be odd at this point, so we can skip one element
	for(int i = 3; i*i <= n; i += 2) {
		// While i divides n, print i and divide n
		while(n % i == 0) {
			n = n / i;
			v.push_back(i);
		}
	}

	// This condition is to handle the case whien n is a prime number
	// greater than 2
	if(n > 2) {
		v.push_back(n);
	}

	return v;
}

vector<long> combinations(vector<long> v, vector<long> c, long max) {
	if(c.size() == 0) {
		return c;
	}

	for(long l : c) {cout << l << " ";} cout << endl;

	vector<long> n;
	for(long l : c) {
		for(long m : v) {
			long tmp = m * l;
			if(tmp <= max) {n.push_back(tmp);}
		}
	}
	sort(n.begin(), n.end());
	auto it = unique(n.begin(), n.end());
	n.resize(distance(n.begin(), it));

	return combinations(v, n, max);
}

int main() {
	int numTestCases = 0;
	long n = 0, a = 0, b = 0;
	long sum = 0;
	bool flag = false;

	cin >> numTestCases;
	for(int testCase = 0; testCase < numTestCases; testCase++) {
		cin >> n;
		cin >> a;
		cin >> b;
		sum = 0;

		vector<long> v = primeFactors(n);
		v.resize(distance(v.begin(), unique(v.begin(), v.end())));
		vector<long> exclude = combinations(v, v, b);

		for(long i = a; i <= b; i++) {
			flag = false;
			for(long val : exclude) {
				if(val == i) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				sum = (sum + i) % 1000000007;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
