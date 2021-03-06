#include <stdio.h>
#include <math.h> 
int main(void)
{
	float x, x0, f, f1;
	x = 1.5;
	int n = 0;
	do {
		x0 = x;
		f = 2 * x0 * x0 * x0 - 4 * x0 * x0 + 3 * x0 - 6;     //f(x)
		f1 = 6 * x0 * x0 - 8 * x0 + 3;                       //f'(x)
		x = x0 - f / f1;   
		n++;
		printf("��%d�ε���  f=%f\n", n,f);
		printf("��%d�ε���  f1=%f\n", n,f1);
		printf("��%d�ε���  x=%f\n", n,x);
	} while (fabs(x - x0) >= 1e-5);
	printf("���̵Ľ�Ϊ��%f\n", x);
	return 0;
}