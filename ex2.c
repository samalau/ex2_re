/******************
Name: Samantha Newmark
ID: ---------
Assignment: 2
*******************/
#include <stdio.h>

#define TERMINATE -1
#define UNSELECTED 0
#define HAPPYFACE 1
#define DIGITBALANCE 2
#define ABUNDANCE 3
#define PRIME 4
#define BRINGHAPPINESS 5
#define FESTIVAL 6
#define GOODBYE 7

int terminate();
long long enterNumber(int task);
double absDif(double n, double m);
double sqRt(long long n);
void festival();
void bringHappiness();
void prime();
void abundance();
void digitBalance();
void happyFace();

int mainMenuOption;

int terminate() {
	mainMenuOption = GOODBYE;
	printf("Thank you for your journey through Numeria!\n");
	return TERMINATE;
}

long long enterNumber(int task) {
	switch(task) {
		case UNSELECTED: {
			printf("Choose an option:");
			printf("\n\t1. Happy Face");
			printf("\n\t2. Balanced Number");
			printf("\n\t3. Generous Number");
			printf("\n\t4. Circle Of Joy");
			printf("\n\t5. Happy Numbers");
			printf("\n\t6. Festival Of Laughter");
			printf("\n\t7. Exit\n");
			break;
		}
		case HAPPYFACE: {
			printf("Enter face size:\n");
			break;
		}
		case FESTIVAL: {
			printf("Enter maximum number for the festival:\n");
			break;
		}
		default: {
			printf("Enter a number:\n");
			break;
		}
	}
	
	long long number = 0;
	int input = 0;
	char caution = 0;
	while ((input = scanf(" %lld%c", &number, &caution)) != 2 || caution != '\n' || number <= 0) {
		if (input != TERMINATE) {
			if (caution != '\n') {
				scanf("%*[^\n]");
			}
			switch(task) {
				case UNSELECTED: {
					if (number == GOODBYE) {
						return terminate();
					}
					if (number >= HAPPYFACE || number < GOODBYE) {
						return number;
					}
					printf("This option is not available, please try again.\n");
					break;
				}
				case HAPPYFACE: {
					printf("The face's size must be an odd and positive number, please try again:\n");
					break;
				}
				case FESTIVAL: {
					printf("Only positive maximum number is allowed, please try again:\n");
					break;
				}
				default: {
					printf("Only positive number is allowed, please try again:\n");
					break;
				}
			}
			continue;
		}
		return terminate();
	}
	return number;
}

double absDif(double n, double m) {
	return (n - m) < 0 ? (m - n) : (n - m);
}

double sqRt(long long n) {
	double t = (double)n;
	double m = 1;
	while (absDif(t, m) > 0.000001) {
		t = (t + m) / 2;
		m = (double)n / t;
	}
	return t;
}

// CASE 1
void happyFace() {
	printf("Enter symbols for the eyes, nose, and mouth:\n");
	char eyes = ' ';
	int input = 0;
	while ((input = scanf(" %c", &eyes)) != 1) {
		if (input == TERMINATE) {
			terminate();
			return;
		}
	}
	char nose = ' ';
	input = 0;
	while ((input = scanf(" %c", &nose)) != 1) {
		if (input == TERMINATE) {
			terminate();
			return;
		}
	}
	char mouth = ' ';
	input = 0;
	while ((input = scanf(" %c", &mouth)) != 1) {
		if (input == TERMINATE) {
			terminate();
			return;
		}
	}
	scanf("%*[^\n]");

	long long size = enterNumber(HAPPYFACE);

	printf("%c", eyes);
	for (long long i = 1; i < size + 1; i++) {
		printf(" ");
	}
	printf("%c\n", eyes);

	for (long long i = 0; i < (size + 1) / 2; i++) {
		printf(" ");
	}
	printf("%c\n", nose);

	printf("\\");
	for (long long i = 0; i < size + 1; i++) {
		printf("%c", mouth);
	}
	printf("/\n");
}

// CASE 2
void digitBalance() {
	long long number = enterNumber(DIGITBALANCE);
	if (number != TERMINATE) {
		int len = 0;
		long long t = number;
		while (t != 0) {
			t /= 10;
			len++;
		}
		if (len == 1) {
			printf("This number is balanced and brings harmony!\n");
			return;
		}

		int div = 1;
		for (int i = 0; i < len / 2; i++) {
			div *= 10;
		}
		if ((len % 2)) {
			div *= 10;
		}

		long long left = number / (long long)div;
		while (left > 9) {
			left = (left % 10) + (left / 10);
		}

		div = 1;
		for (int i = 1 + len/2; i < len; i++) {
			div *= 10;
		}
		if (!(len % 2)) {
			div *= 10;
		}

		long long right = number % (long long)div;
		while (right > 9) {
			right = (right % 10) + (right / 10);
		}

		(left - right)
			? printf("This number isn't balanced and destroys harmony.\n")
		: printf("This number is balanced and brings harmony!\n");
	}
}

// CASE 3
void abundance() {
	long long number = enterNumber(ABUNDANCE);
	if (number != TERMINATE) {
		long long sum = 0;
		for (long long i = 1; i * i <= number; i++) {
			if (!(number % i || number == number / i)) {
				sum += i;
				if (i != number / i) {
					sum += number / i;
				}
			}
		}
		sum > number
			? printf("This number is generous!\n")
		: printf("This number does not share.\n");
	}
}

// CASE 4
void prime() {
	long long number = enterNumber(PRIME);
	if (number != TERMINATE) {
		if (number == 1 || !(number % 2) || !(number % 3)) {
			printf("The circle remains incomplete.\n");
			return;
		}

		if (number == 2 || number == 3) {
			printf("This number completes the circle of joy!\n");
			return;
		}

		for (long long i = 5; i <= sqRt(number); i++) {
			if (!(number % i)) {
				printf("The circle remains incomplete.\n");
				return;
			}
		}
		printf("This number completes the circle of joy!\n");
	}
}

// CASE 5
void bringHappiness() {
	long long number = enterNumber(BRINGHAPPINESS);
	if (number != TERMINATE) {
		long long tag, digit, sum;
		printf("Between 1 and %lld only these numbers bring happiness: ", number);
		for (long long i = 1; i <= number; i++) {
			tag = i;
			while (tag != 1 && tag != 4 && tag < 1000) {
				sum = 0;
				while (tag > 0) {
					digit = tag % 10;
					sum += digit * digit;
					tag /= 10;
				}
				tag = sum;
			}
			if (tag == 1) {
				printf("%lld ", i);
			}
		}
		printf("\n");
	}
}

// CASE 6
void festival() {
	printf("Enter a smile and cheer number:\n");
	int smileNumber = 0, cheerNumber = 0, input = 0;
	char caution = 0;
	while ((input = scanf(" smile : %d , cheer : %d%c", &smileNumber, &cheerNumber, &caution)) != 3 || caution != '\n' || smileNumber <= 0 || cheerNumber <= 0 || cheerNumber == smileNumber) {
		if (input != TERMINATE) {
			if (caution != '\n') {
				scanf("%*[^\n]");
			}
			printf("Only 2 different positive numbers in the given format"
			" are allowed for the festival, please try again:\n"
			);
		}
		terminate();
		return;
	}

	long long maxNum = enterNumber(FESTIVAL);
	if (maxNum != TERMINATE) {
		for (int i = 1; i <= maxNum; i++) {
			!(i % smileNumber || i % cheerNumber) ? printf("Festival!\n")
			: !(i % smileNumber) ? printf("Smile!\n")
			: !(i % cheerNumber) ? printf("Cheer!\n")
			: printf("%d\n", i);
		}
	}
}

int main() {
	while (mainMenuOption != GOODBYE && mainMenuOption != TERMINATE) {
		mainMenuOption = enterNumber(UNSELECTED);
		if (mainMenuOption == TERMINATE || mainMenuOption == GOODBYE) {
			return TERMINATE;
		}
		switch (mainMenuOption) {
			case HAPPYFACE: {
				happyFace();
				break;
			}
			case DIGITBALANCE: {
				digitBalance();
				break;
			}
			case ABUNDANCE: {
				abundance();
				break;
			}
			case PRIME: {
				prime();
				break;
			}
			case BRINGHAPPINESS: {
				bringHappiness();
				break;
			}
			case FESTIVAL: {
				festival();
				break;
			}
			default: {
				break;
			}
		}
	}
	return TERMINATE;
}
