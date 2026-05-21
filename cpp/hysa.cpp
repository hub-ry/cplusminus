#include <stdio.h>




int main() {
	/* double investment = 1000.00;
	double profit = investment;
	double rate = 4.0/12.0;
	int months = 12;
	double contribute = 20;
	*/

	double investment;
	double profit;
	double rate;
	int months;
	double contribute;
	
	printf("init: ");
	scanf("%lf", &investment);
	printf("\napy: ");
	scanf("%lf", &rate);
	printf("\nmonths: ");
	scanf("%d", &months);
	profit = investment;

	rate = (rate / 12.0);

	for (int i = 0; i < months; i++) {
		investment *= rate;
		investment += contribute;
	}
	profit = investment - profit;
	printf("total: %.2f\nprofit: %.2f\n", investment, profit);
	return 0;

}
