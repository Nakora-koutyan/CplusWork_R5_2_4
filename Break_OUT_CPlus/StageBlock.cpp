#include "StageBlock.h"
#include "Ball.h"
int StageBlock::StageUpdate;

//ObjectBlock StageBlock::block[BLOCK_HEIGHT][BLOCK_WIDTH];

StageBlock::StageBlock()
{
	LoadDivGraph("Images/Block.bmp", 8, 8, 1, 40, 8, block_images);
	for (int i = 0; i < 8; i++)
	{
		if (block_images[i] == -1)
		{
			throw"Images/Block.bmp";
		}
	}
	
	stage = 0;
	InitBlock();
}
void StageBlock::Draw()const
{
	for (int i = 0; i < BLOCK_HEIGHT; i++)
	{
		for (int j = 0; j < BLOCK_WIDTH; j++)
		{
			if (block[i][j].flg == 1)
			{
				DrawGraph(block[i][j].x, block[i][j].y, block_images[block[i][j].image], TRUE);
			}
		}
	}
}
void StageBlock::Update()
{
	CheckBlock();
	HitStage();
}

int StageBlock::CheckBlock()
{
	//ブロック配列の初期化
	for (int i = 0; i < BLOCK_HEIGHT; i++)
	{
		for (int j = 0; j < BLOCK_WIDTH; j++)
		{
			if (block[i][j].flg == 1)
			{
				return -1;
			}
		}
	}

	return 0;
}

void StageBlock::HitStage()
{
	int x = Ball::location_ball.x / 40;
	int y = (Ball::location_ball.y - 80) / 16;

	if (x >= 0 && x < BLOCK_WIDTH &&
		y >= 0 && y < BLOCK_HEIGHT &&
		block[y][x].flg != 0)
	{
		block[y][x].flg = 0;

		Ball::change_angle = (1 - Ball::change_angle);
		Ball::ChangeBallAngle();
	}
}

void StageBlock::InitBlock()
{
	//0ステージ目のデータ分の配列を書き込む
	for (int i = 0; i < BLOCK_HEIGHT; i++)
	{
		for (int j = 0; j < BLOCK_WIDTH; j++)
		{
			if (g_block_data[StageUpdate][i][j] != 0)
			{
				block[i][j].flg = 1;
				block[i][j].x = j * 40;
				block[i][j].y = i * 16 + 80;
				block[i][j].w = 40;
				block[i][j].h = 8;
				block[i][j].image = g_block_data[StageUpdate][i][j];
				block[i][j].score = block[i][j].image * 10;
			}
		}
	}
}