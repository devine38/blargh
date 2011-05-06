#include <stdio.h>
#include <sys/time.h>

/******************************************************************************\
* Function Prototypes                                                          *
\******************************************************************************/
void readboard(void);
void freeboard(void);

/******************************************************************************\
* Global Variables                                                             *
\******************************************************************************/
char *board;
int columns;
int rows;
int last_move;
int total_time;
int player_1_time;
int last_move_time;

/******************************************************************************\
* readboard                                                                    *
\******************************************************************************/
void readboard(void)
{
	int i, j;

	scanf("(%d,%d,%d,%d,%d,%d", &columns, &rows, &last_move, &total_time, &player_1_time, &last_move_time);
	board = (char *)calloc(sizeof(char), rows * columns);
	for (i = 0; i < columns; i++)
		for (j = 0; j < rows; j++)
			scanf(",%c", &board[i*rows+j]);
} /* readboard */

/******************************************************************************\
* freeboard                                                                    *
\******************************************************************************/
void freeboard(void)
{
	free(board);
} /* freeboard */

/******************************************************************************\
* main                                                                         *
\******************************************************************************/
int main(void)
{
	int col;
	char p;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srandom(getpid() ^ ~getuid() ^ tv.tv_sec ^ tv.tv_usec);

	readboard();
	
	do
		col = random() % columns;
	while (board[col * rows + rows - 1] != 's');

	if (random() % 8)
		p = 'b';
	else
		p = 'g';

	freeboard();

	printf("(%d,%c)", col+1, p);

	return 0;
} /* main */

