#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

const double eps = 1e-9;
int N, M, D;

typedef vector<double> vec;
typedef vector<vec> mat;

double a[20][20];

vec gauss_jordan(const mat& A, const vec& b)
{
    int n = A.size();
    mat B(n, vec(n + 1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            B[i][j] = A[i][j];

    for(int i = 0; i < n; i++) B[i][n] = b[i];

    for(int i = 0; i < n; i++)
    {
        int pivot = i;

        for(int j = i; j < n; j++)
            if(fabs(B[j][i]) > fabs(B[pivot][i]))
                pivot = j;

        swap(B[i], B[pivot]);

        if(fabs(B[i][i]) < eps) return vec();
        for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            for(int k = i + 1; k <= n; k++)
                B[j][k] -= B[j][i] * B[i][k];
        }
    }
    vec x(n);
    for(int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}



int main()
{
    int cnt = 0;
    while(~scanf("%d%d%d", &M, &N, &D), N + M + D)
    {
        if(cnt) puts("");
        cnt++;

        mat matrix(N * M, vec(N * M));
        vec coo(N * M);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf("%lf", &a[i][j]);

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                int cnt = 0;
                for(int u = 0 ; u < N; u++)
                {
                    for(int v = 0; v < M; v++)
                    {
                        if(abs(i - u) + abs(v - j) <= D)
                        {
                            matrix[i * M + j][u * M + v] = 1.0;
                            cnt++;
                        }
                    }
                }
                coo[i * M + j] = cnt * 1.0 * a[i][j];
            }
        }

        vec ans = gauss_jordan(matrix, coo);

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                printf("%8.2f", ans[i * M + j]);
            }
            printf("\n");
        }
    }
    return 0;
}
