#include <stdio.h>

void hello(char p, char male) {
	char p;
	printf("�̸��� �Է��ϼ���.");
	scnaf("%c", &p);
	
	char male;
	printf("������ �Է��ϼ���(m/f).");
	scanf("%c", &male);

	if (male == 'm') {
		printf("Hello Mr.%c", &p);
	}
	else if (male == 'f') {
		printf("Hello Ms.%c", &p);
	}
	else {
		printf("Hello %c", &p);
	}
}

int main(void) {
	hello;

	return 0; 
}