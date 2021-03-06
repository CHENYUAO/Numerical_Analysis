#include<stdio.h>
#include<math.h>

double f(double x){
	return 1/(1+pow(x,6));	//Define the function f(x)
}

double Simpson(double a, double b, int n) {
    double h = (b - a) / n, s1 = f(a + h / 2), s2 = 0;

    for (int i = 1; i < n; i++) {  //1 <= k <= n - 1
        s1 += f(a + i * h + h / 2);
        s2 += f(a + i * h);
        printf("�� %d �ε���  s1=%f��\n", i, s1);
        printf("�� %d �ε���  s2=%f��\n", i, s2);
    }
    return h * (f(a) + 4 * s1 + 2 * s2 + f(b)) / 6;
}

int main() {
    int n = 8;  //����ȷ���
    double a = 1, b = 2;  //������

    printf("answer = %f\n", Simpson(a, b, n));
    return 0;
}