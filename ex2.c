/******************
Name: Samantha Newmark
ID: ---------
Assignment: 2
*******************/
#include <stdio.h>

#define UNSELECTED 0
#define HAPPYFACE 1
#define DIGITBALANCE 2
#define ABUNDANCE 3
#define PRIME 4
#define BRINGHAPPINESS 5
#define FESTIVAL 6
#define GOODBYE 7

double absDif(double n, double m);
double sqRt(int n);
void festival();
void bringHappiness();
void prime();
void abundance();
void digitBalance();
void happyFace();

double absDif(double n, double m) {
	return (n - m) < 0 ? (m - n) : (n - m);
}

double sqRt(int n) {
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
	char eyes; scanf(" %c", &eyes);
	char nose; scanf(" %c", &nose);
	char mouth; scanf(" %c", &mouth);
	scanf("%*[^\n]");

	printf("Enter face size:\n");
	int size;
	while (!(scanf(" %d", &size) && size > 0 && size % 2)) {
		scanf("%*[^\n]");
		printf("The face's size must be an odd and positive number, please try again:\n");
	}
	scanf("%*[^\n]");

	printf("%c", eyes);
	for (int i = 1; i < size + 1; i++) {
		printf(" ");
	}
	printf("%c\n", eyes);

	for (int i = 0; i < (size + 1) / 2; i++) {
		printf(" ");
	}
	printf("%c\n", nose);

	printf("\\");
	for (int i = 0; i < size + 1; i++) {
		printf("%c", mouth);
	}
	printf("/\n");
}

// CASE 2
void digitBalance() {
	printf("Enter a number:\n");
	long long n;
	while (!(scanf(" %lld", &n))) {
		scanf("%*[^\n]");
		printf("Only positive number is allowed, please try again:\n");
	}
	scanf("%*[^\n]");

	int len = 0;
	long long t = n;
	while (t != 0) {
		t /= 10;
		len++;
	}
	if (len == 1) {
		printf("This number is balanced and brings harmony!\n");
		return;
	}

	long long div = 1;
	for (int i = 0; i < len / 2; i++) {
		div *= 10;
	}
	if ((len % 2)) {
		div *= 10;
	}

	long long left = n / div;
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

	long long right = n % div;
	while (right > 9) {
		right = (right % 10) + (right / 10);
	}

	(left - right)
		? printf("This number isn't balanced and destroys harmony.\n")
		: printf("This number is balanced and brings harmony!\n");
}

// CASE 3
void abundance() {
	printf("Enter a number:\n");
	int n;
	while (!(scanf(" %d", &n) && n > 0)) {
		scanf("%*[^\n]");
		printf("Only positive number is allowed, please try again:\n");
	}
	scanf("%*[^\n]");

	int sum = 0;
	for (int i = 1; i * i <= n; i++) {
		if (!(n % i || n == n / i)) {
			sum += i;
			if (i != n / i) {
				sum += n / i;
			}
		}
	}
	sum > n ? printf("This number is generous!\n") : printf("This number does not share.\n");
}

// CASE 4
void prime() {
	printf("Enter a number:\n");
	int n;
	while (!(scanf(" %d", &n) && n > 0)) {
		scanf("%*[^\n]");
		printf("Only positive number is allowed, please try again:\n");
	}
	scanf("%*[^\n]");

	if (n == 1 || !(n % 2) || !(n % 3)) {
		printf("The circle remains incomplete.\n");
		return;
	}

	if (n == 2 || n == 3) {
		printf("This number completes the circle of joy!\n");
		return;
	}

	for (int i = 5; i <= sqRt(n); i++) {
		if (!(n % i)) {
			printf("The circle remains incomplete.\n");
			return;
		}
	}
	printf("This number completes the circle of joy!\n");
}

// CASE 5
void bringHappiness() {
	printf("Enter a number:\n");
	// int *seen[1000];
	int n, tag, digit, sum;
	// int n, tag, t, digit, sum;
	while (!(scanf(" %d", &n) && n > 0)) {
		scanf("%*[^\n]");
		printf("Only positive number is allowed, please try again:\n");
	}
	scanf("%*[^\n]");

	printf("Between 1 and %d only these numbers bring happiness: ", n);
	for (int i = 1; i <= n; i++) {
		// *seen = 0;
		tag = i;
		while (tag != 1 && tag != 4 && tag < 1000) {
		// while (tag != 1 && tag != 4 && tag < 1000 && ! (*seen[tag])) {
			// seen[tag] = 1;
			// t = tag;
			sum = 0;
			while (tag > 0) {
				digit = tag % 10;
				sum += digit * digit;
				tag /= 10;
			}
			// while (t > 0) {
			// 	digit = t % 10;
			// 	sum += digit * digit;
			// 	t /= 10;
			// }
			tag = sum;
		}
		if (tag == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// CASE 6
void festival() {
	printf("Enter a smile and cheer number:\n");
	int smileNumber, cheerNumber, maxNum;
	while (!(scanf(" smile : %d , cheer : %d", &smileNumber, &cheerNumber) == 2
	&& smileNumber > 0 && cheerNumber > 0 && smileNumber != cheerNumber)) {
		scanf("%*[^\n]");
		printf("Only 2 different positive numbers"
		" in the given format are allowed"
		" for the festival, please try again:\n");
	}
	scanf("%*[^\n]");

	printf("Enter maximum number for the festival:\n");
	while (!(scanf(" %d", &maxNum) && maxNum > 0)) {
		scanf("%*[^\n]");
		printf("Only positive maximum number is allowed, please try again:\n");
	}
	scanf("%*[^\n]");

	for (int i = 1; i <= maxNum; i++) {
		!(i % smileNumber || i % cheerNumber) ? printf("Festival!\n")
		: !(i % smileNumber) ? printf("Smile!\n")
		: !(i % cheerNumber) ? printf("Cheer!\n")
		: printf("%d\n", i);
	}
}

int main() {
	int option = UNSELECTED;
	while (option != GOODBYE) {
		option = UNSELECTED;
		printf("Choose an option:");
		printf("\n\t1. Happy Face");
		printf("\n\t2. Balanced Number");
		printf("\n\t3. Generous Number");
		printf("\n\t4. Circle Of Joy");
		printf("\n\t5. Happy Numbers");
		printf("\n\t6. Festival Of Laughter");
		printf("\n\t7. Exit\n");
		
		if (!(scanf(" %d", &option) && option >= HAPPYFACE && option <= GOODBYE)) {
			scanf("%*[^\n]");
			printf("This option is not available, please try again.\n");
			continue;
		}
		scanf("%*[^\n]");

		switch (option) {
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
	printf("Thank you for your journey through Numeria!\n");
	return 0;
}
