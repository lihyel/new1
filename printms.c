#include <stdio.h>

void hello(char *p, char male);

int main() {
	char name[10], male;
	printf("�̸��� �Է��ϼ���.\n");
	scanf_s("%s", name, sizeof name); //&s:���ڿ�(string)
	getchar();
	printf("������ �Է��ϼ���(m/f).\n");
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
		printf("Hello %s\n", p); //*p�ƴ� ����, %s�� �Է¹޾����� ���ڿ��� ����������(%c�ƴ�)
}

