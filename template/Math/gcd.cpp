void exgcd(long long a, long long b, long long &x, long long &y){
	if (b) {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	} else {
		x = 1; y = 0;
	}
}

int gcd(int x, int y) {
    return x ? gcd(y % x, x) : y;
}