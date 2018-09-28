#include <stdio.h>
#include <omp.h>

typedef long long ll;

// Complexity O(n) --> n = exp
ll naive_power(ll base, ll exp, ll &naive_power_call) {
	naive_power_call++;
	if(exp == 1) return base;
	return base * naive_power(base, exp - 1, naive_power_call);
}

// Complexity O(log n) --> n = exp
ll power(ll base, ll exp, ll &power_call) {
	power_call++;
	if(exp == 1) return base;
	ll pow = power(base, exp / 2, power_call);
	ll res = pow * pow;
	if(exp % 2 == 1) {
		res = res * base;
	}
	return res;
}

int main() {
	ll base, exp, naive_power_call = 0, power_call = 0;
	scanf("%I64d %I64d", &base, &exp);
	ll naive_power_result = naive_power(base, exp, naive_power_call);
	ll power_result = power(base, exp, power_call);
	printf("Result = %I64d | naive_power function total call = %I64d\n", naive_power_result, naive_power_call);
	printf("Result = %I64d | power function total call = %I64d\n", power_result, power_call);
	return 0;
}