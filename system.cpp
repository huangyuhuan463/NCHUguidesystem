#include <stdio.h>
#include <string.h>
#define Num 13
#define Maxedge 32760
typedef struct{
	char name[10];
	int number;
	char introduce[100];
}vertex;

vertex ver[Num];
int edge[Num][Num];
int shortest[Num][Num];
int path[Num][Num];

void map()
{
	printf("\t\t�ϲ����մ�ѧƽ��ͼ(������Ϊ���Ӧ�����ֱ��)\n\n");
	printf("               ��ʳ��(1)--------���(2)---------���(3)--------��ʳ��(4)\n");
	printf("                  |             |                 |               |  \n");
	printf("                  |             |                 |               |  \n");
	printf("��ɽ(5)--------ʵ��¥(6)--------ͼ���(7)------һʳ��(8)--------����(9)--------����(10)\n");
    printf("                  |             |                 |                 \n");
	printf("                  |             |                 |                 \n");
	printf("              ��ѧ¥DEGF(11)---����(12)---------��ѧ¥ABCD(13)\n");
}

void init()
{
	int i,j;
	ver[1].number=1;
	strcpy(ver[1].name,"��ʳ��");
	strcpy(ver[1].introduce,"����˾,����,һ����ƻ�ʳȥ��\n");
	ver[2].number=2;
	strcpy(ver[2].name,"���");
	strcpy(ver[2].introduce,"�ÿ�ݵĵط�\n");
	ver[3].number=3;
	strcpy(ver[3].name,"���");
	strcpy(ver[3].introduce,"�俨�������ĵط�\n");
	ver[4].number=4;
	strcpy(ver[4].name,"��ʳ��");
	strcpy(ver[4].introduce,"��������,����,��ʱ���ȥ��\n");
	ver[5].number=5;
	strcpy(ver[5].name,"��ɽ");
	strcpy(ver[5].introduce,"�ܲ�,Լ��ĵط�\n");
	ver[6].number=6;
	strcpy(ver[6].name,"ʵ��¥");
	strcpy(ver[6].introduce,"��ʵ��ĵط�\n");
	ver[7].number=7;
	strcpy(ver[7].name,"ͼ���");
	strcpy(ver[7].introduce,"ѧϰ�ĵط�\n");
	ver[8].number=8;
	strcpy(ver[8].name,"һʳ��");
	strcpy(ver[8].introduce,"����ȥ�Է��ĵط�\n");
	ver[9].number=9;
	strcpy(ver[9].name,"����");
	strcpy(ver[9].introduce,"����ĵط�\n");
	ver[10].number=10;
	strcpy(ver[10].name,"����");
	strcpy(ver[10].introduce,"�ؼ�,ȥ���ɵıؾ�֮·\n");
	ver[11].number=11;
	strcpy(ver[11].name,"��ѧ¥DEGF");
	strcpy(ver[11].introduce,"רҵ���Ͽεĵط�\n");
	ver[12].number=12;
	strcpy(ver[12].name,"����");
	strcpy(ver[12].introduce,"��ȥ�˵ıؾ�֮·\n");
	ver[13].number=13;
	strcpy(ver[13].name,"��ѧ¥ABC");
	strcpy(ver[13].introduce,"�����γ��Ͽεĵط�\n");
	for(i=1;i<Num;i++)
		for(j=1;j<Num;j++)
			edge[i][j]=Maxedge;
		for(i=1;i<Num;i++)
			edge[i][i]=0;
		edge[1][2]=edge[2][1]=264;
		edge[2][3]=edge[3][2]=264;
		edge[3][4]=edge[4][3]=198;
		edge[1][6]=edge[6][1]=198;
		edge[2][7]=edge[7][2]=594;
		edge[3][8]=edge[8][3]=250;
		edge[4][9]=edge[9][4]=264;
		edge[5][6]=edge[6][5]=330;
		edge[6][7]=edge[7][6]=330;
		edge[7][8]=edge[8][7]=400;
		edge[8][9]=edge[9][8]=264;
		edge[9][10]=edge[10][9]=330;
		edge[6][11]=edge[11][6]=330;
		edge[7][12]=edge[12][7]=462;
		edge[8][13]=edge[13][8]=396;
		edge[11][12]=edge[12][11]=396;
		edge[12][13]=edge[13][12]=198;
}


char menu()
{
	char i;
	printf("����s����ѯ���·��\n");
	printf("����i����ѯ��Ϣ\n");
	printf("����e���˳�����\n");
	printf("�������Ӧ��Ӣ��Сд��ĸ,лл:\n\t");
	scanf("%s",&i);
	return i;
}

void information()
{
	int i;
	while(1){
		printf("�������ѯ�ص�ı��:\n\t");
		scanf("%d",&i);
		if(i<=Num&&i>=1){
			printf("\n@����:%s\n#���: %s\n",ver[i].name,ver[i].introduce);
		}
		else{
			printf("��������!");
		}
	}
}


void floyd()
{
	int i=1,j=1,k=1,l=1;
	for(i=1;i<Num;i++){
		for(j=1;j<Num;j++){
			shortest[i][j]=edge[i][j];
			path[i][j]=0;
		}
	}
	for(k=1;k<Num;k++){
		for(i=1;i<=Num;i++){
			for(j=1;j<=Num;j++){
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j])){
					shortest[i][j]=(shortest[i][k]+shortest[k][j]);
					path[i][j]=path[j][i]=k;
				}
			}
		}
	}
}

	

void way(int i,int j)
{
	int k=0,a=i,b=j;
	if(shortest[i][j]!=Maxedge){
		printf("\n%��%s��%s�����·��Ϊ:\n",ver[i].name,ver[j].name);
		printf("%s",ver[i].name);
		while(path[i][j]!=0){
			k=path[i][j];
			while(path[i][k]!=0){
				k=path[i][k];
			}
			printf("-��-%s;\n",ver[k].name);
			i=k;
		}
		printf("-��-%s;\n",ver[j].name);
	    printf("\n��̾���Ϊ: %d�ס�\n",shortest[a][b]);
		printf("\n���ݾ�Ϊ�������ݣ���ʵ�����������½�.\n\n");
		}
		else
			printf("��%s���ܵ���5%s.",ver[i].name,ver[j].name);
}
	

void shortestpath()
{
	int i=0,j=0;
	while(1){
		printf("������Ҫ��ѯ������ı��:  (�ÿո���)");
		scanf("%d%d",&i,&j);
		if(i<Num&&i>0&&j<=Num&&j>0){
			floyd();
			way(i,j);
			return ;
		}
	}
}

int main()
{
	char i;
	printf("\t\t\t��ӭʹ���ϲ����մ�ѧ����ϵͳ\n\n");
	init();
	map();
	while(1){
		i=menu();
		switch(i){
		case 's':shortestpath();break;
		case 'i':information();break;
		case 'e':printf("\n\n\n\t\t\t\tллʹ��!\n");return 0;
		default:printf("�������!\n");break;
		}
	}
}
