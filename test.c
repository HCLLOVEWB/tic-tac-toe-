//������������Ϸ
#include"game.h"
void menu()
{
	printf("---------------------------\n");
	printf("***************************\n");
	printf("*********��Ϸ�˵�**********\n");
	printf("*****ѡ������Ϸ������1 ****\n");
	printf("******�˳���Ϸ������0 *****\n");
	printf("***************************\n");
	printf("---------------------------\n");
}
void game()
{
	char get;
	char board[ROW][COL]={0};
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while(1)
	{
		//�����
		PlayerMove(board,ROW,COL);
		//��ӡ����
		DisplayBoard(board,ROW,COL);
		//�ж�����Ƿ�Ӯ
		//�������*�����Ӯ
		//�������#�����Ӯ
		//�������C�����
		//�������Q��ƽ��
		get=Winner(board,ROW,COL);
        if(get!='C')
		{
			break;
		}	
		//������
		ComputerMove(board,ROW,COL);
		//��ӡ����
		DisplayBoard(board,ROW,COL);
		//�жϵ����Ƿ�Ӯ
	    get=Winner(board,ROW,COL);
		if(get!='C')
		{
			break;
		}
	}
		if(get=='*')
		{
			printf("���Ӯ");
		}
		else if(get=='#')
		{
			printf("����Ӯ");
		}
		else
		{
			printf("ƽ��");
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
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
	}
	}while(input);
}
int main()
{
	test();
	return 0;
}