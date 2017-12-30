#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <windows.h>

double PI;
typedef double complex cplx;

void _fft(cplx buf[], cplx out[], int n, int step)
{
    int i;
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);

		for (i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}

void fft(cplx buf[], int n)
{int i;
	cplx out[n];
	for ( i = 0; i < n; i++) out[i] = buf[i];

	_fft(buf, out, n, 1);
}


void show(const char * s, cplx buf[],int n) {
    int i;
	printf("%s", s);
	for ( i = 0; i < n; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
}

int main()
{   int j;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;
	PI = atan2(1, 1) * 4;
	cplx buf[4]={1,2,3,4,5,6,7,8,9};
    /// for (j=1;j<=4;j++)
       // buf[j] = j;
	show("Data: ", buf,4);
	QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
	fft(buf, 8);
	  QueryPerformanceCounter(&end);
  interval = (double)(end.QuadPart - start.QuadPart)/frequency.QuadPart;
	show("\nFFT : ", buf,4);

    printf("%f\n",interval);
	return 0;
}

