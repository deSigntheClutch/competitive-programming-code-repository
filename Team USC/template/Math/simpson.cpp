double f(double x) {
    return x;
}

double cal(double a, double b) {
    double h = (b - a) / N, s = 0;
    for (int i = 0; i <= N; ++i) {
        double x = a + h * i;
        s += f(x) * ((i == 0 || i == N) ? 1 : ((i & 1) == 0) ? 2 : 4);
    }
    s *= h / 3;
    return s;
}