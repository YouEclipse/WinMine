//#############������еĺ������ڴ˶���##########################//


#include<time.h>
#include"winmine.h"

static unsigned int map[MAX_ROW_NUM][MAX_COL_NUM];
static unsigned int counter[MAX_ROW_NUM][MAX_COL_NUM];

/***************************����*******************************/
void layMine(int mineRowNum,int mineColNum,int mineBombNum)
{
	srand((unsigned)time(NULL));
	int i,j,count ;
	for (count = 0; count < mineBombNum; count++)
	{
		i = rand() % (mineRowNum-1) ;
		j = rand() % (mineColNum-1) ;
		map[i][j] = BOMB;
	}
	for (int i = 0; i < mineRowNum; i++)
	for (int j = 0; j < mineColNum; j++)
	{
		if (map[i][j] != BOMB)
			map[i][j] = NOBOMB;
	}
}

void countAroundMine(int mineRowNum, int mineColNum)
{
	for (int i = 0; i < mineRowNum; i++)
	for (int j = 0; j < mineColNum; j++)
	{
		if (map[i][j] == BOMB)
		for (int r = i - 1; r <= i + 1; r++)
		for (int c = j - 1; c <= j + 1; c++)
		if (map[r][c] != BOMB && r >=0 && c >= 0 && r < mineRowNum && c < mineColNum)
			counter[r][c]++;
	}

}
