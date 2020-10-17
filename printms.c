#include <stdio.h>

void hello(char *p, char male);

int main() {
	char name[10], male;
	printf("이름을 입력하세요.\n");
	scanf_s("%s", name, sizeof name); //&s:문자열(string)
	getchar();
	printf("성별을 입력하세요(m/f).\n");
	scanf_s("%c", &male);
	
	hello(name, male); 

	return 0;
}

void hello(char *p, char male) {

	if (male=='m') 
		printf("Hello Mr.%s\n", p);
	else if (male=='f')
		printf("Hello Ms.%s\n", p);
	else 
		printf("Hello %s\n", p); //*p아님 주의, %s로 입력받았으니 문자열로 출력해줘야함(%c아님)
}

