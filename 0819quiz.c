#include <stdio.h>

int main() {
	char board[3][3];   // 보드를 나타내는 2차원 배열
	int x, y, k, i;
	int invalid_input;	// 입력이 잘못되었지 여부
	int decided;		// 게임 승부 결정 여부, 
	char turn;			// 순번에 따라 'X' 또는 'O' 값을 가지는 문자

	for (x = 0; x < 3; x++)   // 보드 초기화
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	decided = 0;	// 처음에는 승부가 결정되지 않았음
	for (k = 0; k < 9 && !decided; k++) {	// 9번 이내이고 승부 안났으면 반복
		do {
			invalid_input = 0;	// 입력이 잘못되지 않은 상태로 시작
			printf("행 열 입력 : ");
			scanf_s("%d %d", &x, &y);
			if (x < 0 || x > 2 || y < 0 || y > 2) {
				printf("범위를 벗어 났습니다. 다시 입력하세요.\n");
				invalid_input = 1;	// 입력에 문제가 있음을 표시
			}
			else if (board[x][y] != ' ') {
				printf("같은 자리에 놓을 수 없습니다. 다시 입력하세요.\n");
				invalid_input = 1;	// 입력에 문제가 있음을 표시	
			}
		} while (invalid_input);	// 잘못되었으면 다시 입력 받음

		turn = (k % 2 == 0) ? 'X' : 'O'; // 순번에 따라 'X' 또는 'O' 값
		board[x][y] = turn;

		printf("   | 0 | 1 | 2 \n");

		for (i = 0; i < 3; i++) {
			printf("---|---|---|---\n");
			printf(" %d | %c | %c | %c \n", i, board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---|---\n");

		// 이번에 놓은(turn) 문자로 게임 승부 확인 : 대각선 2개
		if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn
			|| board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
			decided = 1;	// 승부 결정
		else	// 대각선 없으면 가로, 세로 각 3개 검사
			for (x = 0; x < 3; x++)
				if (board[x][0] == turn && board[x][1] == turn && board[x][2] == turn
					|| board[0][x] == turn && board[1][x] == turn && board[2][x] == turn)
					decided = 1;	// 승부 결정
	}

	if (decided)	// 승부가 났으면
		printf("%c의 승리!!\n", turn);
	else
		printf("무승부\n");

	return 0;
}