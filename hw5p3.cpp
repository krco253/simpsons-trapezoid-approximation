#include <stdio.h>
#include <math.h>


int main(){
	float sum1 = 0;
	float sum2 = 0;
	//integral of e^x from 0 to 1
	float firstIntegralValue = exp(1) - 1;
	//integral of xln(x) from 1 to 2
	float secondIntegralValue = 2 * log(2);
	//integral of sin(x) from 0 to 1 
	float periodicIntegralValue = 1- cos(1);
	for(int n =10; n <= 1000; n+=10){
		printf("n = %d \n",n);
//---------------Trapezoid Rule------------
//FIRST INTEGRAL		
		float h = 1 /n;
		sum1 = 0;
		for(int i = 1; i <= n-1; i++){
			sum1 += exp(i*h);
		}
		float trapApprox = h*((1+exp(1))/2)*sum1;
		float trapError = firstIntegralValue - trapApprox;
		printf("First integral Trapezoid Error: %4.6e \n", trapError);
//SECOND INTEGRAL
		sum1 = 0;
		for(int i = 1; i <= n-1; i++){
			sum1 += (1 + i*h)*log(1 + i*h);
		}
		trapApprox = h*((2*log(2))/2)*sum1;
		trapError = secondIntegralValue - trapApprox;
		printf("Second integral Trapezoid Error: %4.6e \n", trapError);
//PERIODIC INTEGRAL
		sum1 = 0;
		for(int i = 1; i <= n-1; i++){
			sum1 += sin(i*h);
		}
		trapApprox = h*((1+sin(1)/2) + sum1);
		trapError = periodicIntegralValue - trapApprox;
		printf("Periodic integral Trapezoid Error: %4.6e \n", trapError);

//--------------Simpson's Rule-----------
//FIRST INTEGRAL
//			
      		sum1 = 0;
		for (int i = 1; i <= (n-1); i++){
			sum1 += exp(i*h);
		}
		sum2 = 0;
		for (int i = 1; i <= n; i++){
			sum2 += exp((2*(i-1)/2)*h);
		}	
		float simpsonsApprox = (h/6)*(1+exp(1) + 2*sum1 + 4 * sum2);
		float simpsonsError = firstIntegralValue - simpsonsApprox;
		printf("First Integral Simpson's Error: %4.6e \n", simpsonsError);
//SECOND INTEGRAL
		sum1 = 0;
		for (int i = 1; i <= (n-1); i++){
			sum1 += (1+i*h)*log(1+i*h);
		}
		sum2 = 0;
		for (int i = 1; i <= n; i++){
			sum2 += (1+ 2*(i-1)/2 * h)*log(1+ 2*(i-1)/2 * h);
		}
		simpsonsApprox = (h/6)*(2*log(2) + 2*sum1 + 4*sum2);
		simpsonsError = secondIntegralValue - simpsonsApprox;
		printf("Second Integral Simpson's Error: %4.6e \n", simpsonsError);
//PERIODIC INTEGRAL
		sum1 = 0;
		for (int i = 1; i <= (n-1); i++){
			sum1 += sin(i*h);
		}
		sum2 = 0;
		for (int i = 1; i <= n; i++){
			sum2 += sin(2*(i-1)/2*h);
		}
		simpsonsApprox = (h/6)*(1+sin(1) + 2*sum1 + 4* sum2);
		simpsonsError = periodicIntegralValue - simpsonsApprox;
		printf("Periodic Integral Simpson's Error: %4.6e \n", simpsonsError);

	}
	return 0;
}
