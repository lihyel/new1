#include <stdio.h>

void hello(char p, char male) {
	char p;
	printf("이름을 입력하세요.");
	scnaf("%c", &p);
	
	char male;
	printf("성별을 입력하세요(m/f).");
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