#include"game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j]=' ';
		}
	}
}
/*void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
	printf("%c  |%c  |%c  \n",board[i][0],board[i][1],board[i][2]);
	if(i<row-1)
	printf("---|---|---\n");
	}
}*/
void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
		 	printf("|");   
	   }
	   printf("\n");
	   if(i<row-1)
	   {
	   for(j=0;j<col;j++)
	   {
		   printf("---");
	       if(j<col-1)
          
	       printf("|");
	   }
	   }
	   printf("\n");
	}
}
void PlayerMove(char board[ROW][COL],int row,int col)
{
	
	int i=0;
	int j=0;
	while(1)
	{
    printf("请玩家走,输入想要走的坐标\n");
	scanf("%d %d",&i,&j);
	//判断坐标的合法性
	if(i>=1&&i<=row&&j>=1&&j<=col)
	{
		//判断玩家想要走的坐标上面是否被占用
		   if(board[i-1][j-1]==' ')
		   {
		   board[i-1][j-1]='*';
		   break;
		   }  
		   else
			   printf("该坐标已经被占用\n");
	}
	else
		{
	      printf("非法输入\n");		
		}
	}
}
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x;
	int y;
	printf("电脑走\n");
	while(1)
	{
	x=rand()%ROW;
	y=rand()%COL;
	if(board[x][y]==' ')
	{
		board[x][y]='#';
		break;
	}
	}
}
//1表示棋盘满了，0表示棋盘没有满
int IsFull(char board[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
            return 0;//没满
		}
	}
	return 1;//满了
}
char Winner(char board[ROW][COL],int row,int col)
{
	int i;
	//判断行三个是否相等
	for(i=0;i<row;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
		return(board[i][1]);
	}
	//判断列三个是否相等
	for(i=0;i<col;i++)
	{
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' ')
		return(board[1][i]);
	}
	//判断对角线是否相等
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
		return (board[0][0]);
	if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[2][0]!=' ')
		return (board[2][0]);
	//判断棋盘是不是满了
	if(IsFull(board,ROW,COL)==1)
	{
	   return 'Q';
	}
	else
		return 'C';		
}