#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 2
#define epsilon  0.005

void main()
{
    void matrixTimesVec(double A[N][N], double b[N], double Ab[N]);
    double scalarProduct(double vec1[], double vec2[]);
    void vecPlus(double vec1[], double vec2[], double vec[]);
    void numPlusVec(double num, double vec0[], double vec[]);
    void showVec(double vec[]);
    int i, j;
    static double A[N][N] = { {6.0,3.0},{3.0,2.0,} };
    static double b[N] = { 0.0,-1.0 };
    static double x0[N] = { 0,0 };
    double x[N], r[N], p[N], w[N], alpha, rho00, rho0, rho1, beta;
    //生成一个大规模稀疏矩阵A，这里以三对角为例。



    /*
    for (i = 1; i < N - 1; i++)
    {
        A[i][i - 1] = 2;
        A[i][i] = 3;
        A[i][i + 1] = 1;
    }
    A[0][0] = 3; A[0][1] = 1;
    A[N - 1][N - 2] = 2; A[N - 1][N - 1] = 3;
    */

    printf("\n要求解的示例方程组为：\n A ||| b ||| x0\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%f ", A[i][j]);
        }
        printf("||| %f||| %f\n", b[i], x0[i]);
    }
    printf("\n\n");

    //init
    memcpy(x, x0, N * sizeof(double));
    double Ax0[N];
    matrixTimesVec(A, x0, Ax0);
    numPlusVec(-1.0, Ax0, Ax0);
    vecPlus(b, Ax0, r);
    rho0 = scalarProduct(r, r);
    rho00 = rho0;
    memcpy(p, r, N * sizeof(double));
    int count = 0;
    do
    {
        printf("****************迭代第%d次*************\n\n",count + 1);
        matrixTimesVec(A, p, w);
        alpha = rho0 / (scalarProduct(p, w));
        printf("alpha %d = %f\n\n", count, alpha);

        double temp[N];
        numPlusVec(alpha, p, temp);
        double x_temp[N];
        vecPlus(x, temp, x_temp);
        memcpy(x, x_temp, N * sizeof(double));
        printf("x%d :\n", count+1);
        showVec(x_temp);
        printf("\n");

        numPlusVec(-alpha, w, temp);
        double r_temp[N];
        vecPlus(r, temp, r_temp);
        memcpy(r, r_temp, N * sizeof(double));
        printf("r%d :\n", count+1);
        showVec(r_temp);
        printf("\n");

        rho1 = scalarProduct(r, r);

        beta = rho1 / rho0;
        numPlusVec(beta, p, temp);
        vecPlus(r, temp, p);
        rho0 = rho1;
        printf("p%d :\n", count + 1);
        showVec(p);
        printf("beta %d = %f\n", count, beta);
        printf("\n\n");
        count++;
    } while (rho1 > epsilon);

    printf("\n\n");
    printf("方程组的解为：\n");
    for (i = 0; i < N; i++)
        printf("%f\n", x[i]);
    //getchar();
}

void matrixTimesVec(double A[N][N], double b[N], double Ab[N])
{
    int i, j;


    for (i = 0; i < N; i++)
    {
        Ab[i] = 0.0;
        for (j = 0; j < N; j++)
        {
            Ab[i] = Ab[i] + A[i][j] * b[j];
        }
    }
}

double scalarProduct(double vec1[], double vec2[])
{
    double s = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        s = s + vec1[i] * vec2[i];
    }
    return s;
}
void vecPlus(double vec1[], double vec2[], double vec[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        vec[i] = vec1[i] + vec2[i];
    }
}
void numPlusVec(double num, double vec0[], double vec[])
{
    int i;
    for (i = 0; i < N; i++)
        vec[i] = num * vec0[i];

}

void showVec(double vec[]) {
    for (int i = 0; i < N; i++) {
        printf("%f\n", vec[i]);
    }
}