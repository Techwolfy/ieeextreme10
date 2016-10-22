#include <iostream>
using namespace std;

//Calculate greatest common divisor (extended Euclidean algorithm)
long extGCD(long a, long b, long *s, long *t) {
	if(a == 0) {
		*s = 0;
		*t = 1;
		return b;
	}

	long stmp = 0;
	long ttmp = 0;
	long gcd = extGCD(b % a, a, &stmp, &ttmp);
	*s = ttmp - (b/a)*stmp;
	*t = stmp;

	return gcd;
}

int main() {
	int numTestCases = 0;
	long n = 0, a = 0, b = 0;
	long s = 0;
	long t = 0;
	long long sum = 0;
	int incVal = 1;

	cin >> numTestCases;
	for(int testCase = 0; testCase < numTestCases; testCase++) {
		cin >> n;
		cin >> a;
		cin >> b;
		s = 0;
		t = 0;
		sum = 0;
		incVal = 1;
		if(n % 2 == 0) {
			incVal = 2;
		}
		for(long i = a; i <= b; i += incVal) {
			if(extGCD(i, n, &s, &t) == 1) {
				sum += i;
			}
		}
		cout << sum % 1000000007 << endl;
	}

	return 0;
}
