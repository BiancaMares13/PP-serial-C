#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long gcd_recursive(long long a, long long b)
{
	if (b)
		return gcd_recursive(b, a % b);
	else
		return a;
}


long long lcm(long long a, long long b) {
	long long gcd = gcd_recursive(a, b);
	return a * b / gcd;
	
}
 long long int long_pow(long long base, int exp){
	unsigned long long int result = 1ULL;
	while (exp)
	{
		if (exp & 1)
		{
			result *= (unsigned long long int)base;
		}
		exp >>= 1;
		base *= base;
	}
	return result;
}



int main() {

	const int n = 16847;
	unsigned long long numerator;
	unsigned long long denominator;
	unsigned long long numeratorPrev;

	int i, p, j, r;
	int k = 0;
	long unsigned long lcm_Value;
	long long list[2];


	bool primes[n + 1];
	for (i = 0; i<n; i++)
		primes[i] = true;

	for (p = 2; p*p <= n; p++)
	{
		if (primes[p])
		{
			for (i = p * 2; i <= n; i += p)
				primes[i] = false;
		}
	}
	numerator = 1;
	denominator = 1;
	int lastPrime = 1;
	for (i = 3; i <= n; i += 2) {
		if (primes[i]) {

			for (j = lastPrime; j < i; j++) {
				lcm_Value = lcm(denominator, j);
				numeratorPrev = numerator;
				if (j > 1) {
					numerator = numeratorPrev * (lcm_Value / denominator) + lcm_Value / j;
				}
				denominator = lcm_Value;
			}
			long long power = long_pow(i, 3);
			
			lastPrime = i;
			if (i == 5) {
				printf("5Numerator: %lld", numerator);
				printf("5Power: %lld", power);
				getchar();
			}
			if (i == 16843) {
				printf("Numerator: %lld", numerator);
				printf("Power: %lld", power);
				getchar();
			}
			if (numerator % power == 0) {
				list[k] = i;
				k++;
				printf("Wolstenholme prime :   %lld", i);
				getchar();
			}
		}
	}

	return 0;

}