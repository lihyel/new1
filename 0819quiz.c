#include <stdio.h>

int main() {
	char board[3][3];   // ���带 ��Ÿ���� 2���� �迭
	int x, y, k, i;
	int invalid_input;	// �Է��� �߸��Ǿ��� ����
	int decided;		// ���� �º� ���� ����, 
	char turn;			// ������ ���� 'X' �Ǵ� 'O' ���� ������ ����

	for (x = 0; x < 3; x++)   // ���� �ʱ�ȭ
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	decided = 0;	// ó������ �ºΰ� �������� �ʾ���
	for (k = 0; k < 9 && !decided; k++) {	// 9�� �̳��̰� �º� �ȳ����� �ݺ�
		do {
			invalid_input = 0;	// �Է��� �߸����� ���� ���·� ����
			printf("�� �� �Է� : ");
			scanf_s("%d %d", &x, &y);
			if (x < 0 || x > 2 || y < 0 || y > 2) {
				printf("������ ���� �����ϴ�. �ٽ� �Է��ϼ���.\n");
				invalid_input = 1;	// �Է¿� ������ ������ ǥ��
			}
			else if (board[x][y] != ' ') {
				printf("���� �ڸ��� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
				invalid_input = 1;	// �Է¿� ������ ������ ǥ��	
			}
		} while (invalid_input);	// �߸��Ǿ����� �ٽ� �Է� ����

		turn = (k % 2 == 0) ? 'X' : 'O'; // ������ ���� 'X' �Ǵ� 'O' ��
		board[x][y] = turn;

		printf("   | 0 | 1 | 2 \n");

		for (i = 0; i < 3; i++) {
			printf("---|---|---|---\n");
			printf(" %d | %c | %c | %c \n", i, board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---|---\n");

		// �̹��� ����(turn) ���ڷ� ���� �º� Ȯ�� : �밢�� 2��
		if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn
			|| board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
			decided = 1;	// �º� ����
		else	// �밢�� ������ ����, ���� �� 3�� �˻�
			for (x = 0; x < 3; x++)
				if (board[x][0] == turn && board[x][1] == turn && board[x][2] == turn
					|| board[0][x] == turn && board[1][x] == turn && board[2][x] == turn)
					decided = 1;	// �º� ����
	}

	if (decided)	// �ºΰ� ������
		printf("%c�� �¸�!!\n", turn);
	else
		printf("���º�\n");

	return 0;
}