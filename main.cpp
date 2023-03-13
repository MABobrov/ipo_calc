#include <stdio.h>
#include <math.h>

int main() {
	double creditSum, initPayment, rate, monthRate;
	int year, month;

	printf("Введите общую сумму ипотеки: ");
	scanf("%lf", &creditSum);

	printf("Введите сумму первого платежа: ");
	scanf("%lf", &initPayment);

	printf("Введите годовую процентную ставку: ");
	scanf("%lf", &rate);

	monthRate = rate / 1200; // расчет месячной процентной ставки



	printf("|  Месяц/год  |   Платеж   |   Остаток задолженности  |   Проценты   |\n");
	printf("|-------------|------------|--------------------------|--------------|\n");
	double balance = creditSum + (creditSum * monthRate);
	// расчет и вывод каждого месячного платежа до полного погашения кредита
	for(year = 2023; balance > 0.000; year++) {
		for(month = 1; (month < 13&&balance > 0); month++) {
			double monthPayment = fmin(balance + (balance * monthRate), initPayment + (balance * monthRate)); // расчет ежемесячного платежа
			double sumRate = balance * monthRate; // расчет суммы процентов
			printf("| %02d/%d  |  %9.2lf  |  %24.2lf  |  %10.2lf  |\n", month, year, monthPayment, balance, sumRate); // вывод информации о платеже
			balance -= monthPayment; // расчет остатка задолженности после платежа}
	}

	return 0;
}
