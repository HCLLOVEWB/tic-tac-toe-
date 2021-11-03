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
    printf("�������,������Ҫ�ߵ�����\n");
	scanf("%d %d",&i,&j);
	//�ж�����ĺϷ���
	if(i>=1&&i<=row&&j>=1&&j<=col)
	{
		//�ж������Ҫ�ߵ����������Ƿ�ռ��
		   if(board[i-1][j-1]==' ')
		   {
		   board[i-1][j-1]='*';
		   break;
		   }  
		   else
			   printf("�������Ѿ���ռ��\n");
	}
	else
		{
	      printf("�Ƿ�����\n");		
		}
	}
}
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x;
	int y;
	printf("������\n");
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
//1��ʾ�������ˣ�0��ʾ����û����
int IsFull(char board[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
            return 0;//û��
		}
	}
	return 1;//����
}
char Winner(char board[ROW][COL],int row,int col)
{
	int i;
	//�ж��������Ƿ����
	for(i=0;i<row;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
		return(board[i][1]);
	}
	//�ж��������Ƿ����
	for(i=0;i<col;i++)
	{
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' ')
		return(board[1][i]);
	}
	//�ж϶Խ����Ƿ����
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' ')
		return (board[0][0]);
	if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[2][0]!=' ')
		return (board[2][0]);
	//�ж������ǲ�������
	if(IsFull(board,ROW,COL)==1)
	{
	   return 'Q';
	}
	else
		return 'C';		
}