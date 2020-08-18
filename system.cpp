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
	printf("\t\t南昌航空大学平面图(括号内为相对应的数字编号)\n\n");
	printf("               二食堂(1)--------快递(2)---------大活(3)--------三食堂(4)\n");
	printf("                  |             |                 |               |  \n");
	printf("                  |             |                 |               |  \n");
	printf("后山(5)--------实验楼(6)--------图书馆(7)------一食堂(8)--------宿舍(9)--------北门(10)\n");
    printf("                  |             |                 |                 \n");
	printf("                  |             |                 |                 \n");
	printf("              教学楼DEGF(11)---正门(12)---------教学楼ABCD(13)\n");
}

void init()
{
	int i,j;
	ver[1].number=1;
	strcpy(ver[1].name,"二食堂");
	strcpy(ver[1].introduce,"有寿司,汉堡,一般改善伙食去那\n");
	ver[2].number=2;
	strcpy(ver[2].name,"快递");
	strcpy(ver[2].introduce,"拿快递的地方\n");
	ver[3].number=3;
	strcpy(ver[3].name,"大活");
	strcpy(ver[3].introduce,"充卡，办晚会的地方\n");
	ver[4].number=4;
	strcpy(ver[4].name,"三食堂");
	strcpy(ver[4].introduce,"有麻辣烫,超市,有时候会去吃\n");
	ver[5].number=5;
	strcpy(ver[5].name,"后山");
	strcpy(ver[5].introduce,"跑步,约会的地方\n");
	ver[6].number=6;
	strcpy(ver[6].name,"实验楼");
	strcpy(ver[6].introduce,"做实验的地方\n");
	ver[7].number=7;
	strcpy(ver[7].name,"图书馆");
	strcpy(ver[7].introduce,"学习的地方\n");
	ver[8].number=8;
	strcpy(ver[8].name,"一食堂");
	strcpy(ver[8].introduce,"经常去吃饭的地方\n");
	ver[9].number=9;
	strcpy(ver[9].name,"宿舍");
	strcpy(ver[9].introduce,"堕落的地方\n");
	ver[10].number=10;
	strcpy(ver[10].name,"北门");
	strcpy(ver[10].introduce,"回家,去网吧的必经之路\n");
	ver[11].number=11;
	strcpy(ver[11].name,"教学楼DEGF");
	strcpy(ver[11].introduce,"专业课上课的地方\n");
	ver[12].number=12;
	strcpy(ver[12].name,"正门");
	strcpy(ver[12].introduce,"出去浪的必经之路\n");
	ver[13].number=13;
	strcpy(ver[13].name,"教学楼ABC");
	strcpy(ver[13].introduce,"基础课程上课的地方\n");
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
	printf("输入s来查询最短路径\n");
	printf("输入i来查询信息\n");
	printf("输入e来退出程序\n");
	printf("请输入对应的英文小写字母,谢谢:\n\t");
	scanf("%s",&i);
	return i;
}

void information()
{
	int i;
	while(1){
		printf("请输入查询地点的编号:\n\t");
		scanf("%d",&i);
		if(i<=Num&&i>=1){
			printf("\n@名称:%s\n#简介: %s\n",ver[i].name,ver[i].introduce);
		}
		else{
			printf("输入有误!");
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
		printf("\n%从%s到%s的最短路径为:\n",ver[i].name,ver[j].name);
		printf("%s",ver[i].name);
		while(path[i][j]!=0){
			k=path[i][j];
			while(path[i][k]!=0){
				k=path[i][k];
			}
			printf("-到-%s;\n",ver[k].name);
			i=k;
		}
		printf("-到-%s;\n",ver[j].name);
	    printf("\n最短距离为: %d米。\n",shortest[a][b]);
		printf("\n数据均为测试数据，和实际有误差，敬请谅解.\n\n");
		}
		else
			printf("从%s不能到达5%s.",ver[i].name,ver[j].name);
}
	

void shortestpath()
{
	int i=0,j=0;
	while(1){
		printf("请输入要查询的两点的编号:  (用空格间隔)");
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
	printf("\t\t\t欢迎使用南昌航空大学导航系统\n\n");
	init();
	map();
	while(1){
		i=menu();
		switch(i){
		case 's':shortestpath();break;
		case 'i':information();break;
		case 'e':printf("\n\n\n\t\t\t\t谢谢使用!\n");return 0;
		default:printf("输入错误!\n");break;
		}
	}
}
