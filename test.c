//测试三子棋游戏
#include"game.h"
void menu()
{
	printf("---------------------------\n");
	printf("***************************\n");
	printf("*********游戏菜单**********\n");
	printf("*****选择玩游戏请输入1 ****\n");
	printf("******退出游戏请输入0 *****\n");
	printf("***************************\n");
	printf("---------------------------\n");
}
void game()
{
	char get;
	char board[ROW][COL]={0};
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while(1)
	{
		//玩家走
		PlayerMove(board,ROW,COL);
		//打印棋盘
		DisplayBoard(board,ROW,COL);
		//判断玩家是否赢
		//如果返回*则玩家赢
		//如果返回#则电脑赢
		//如果返回C则继续
		//如果返回Q则平局
		get=Winner(board,ROW,COL);
        if(get!='C')
		{
			break;
		}	
		//电脑走
		ComputerMove(board,ROW,COL);
		//打印棋盘
		DisplayBoard(board,ROW,COL);
		//判断电脑是否赢
	    get=Winner(board,ROW,COL);
		if(get!='C')
		{
			break;
		}
	}
		if(get=='*')
		{
			printf("玩家赢");
		}
		else if(get=='#')
		{
			printf("电脑赢");
		}
		else
		{
			printf("平局");
		}
}
void test()
{
	int input;
	do
	{
	menu();
	scanf("%d",&input);
	switch(input)
	{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
	}
	}while(input);
}
int main()
{
	test();
	return 0;
}