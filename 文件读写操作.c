#include <stdio.h>
#include <string.h>

typedef struct Man
{
	char name[20];
	char age;
	char sex;
	float height;
	float weight;
}Man;

int main()
{
  Man m;
  char buff[255] = {};
  FILE* fwp = fopen("sunling.bin","w");
  for(int i=0; i<5; i++)
	{
	  //获取一个结构
		scanf("%s %hhd %c %f %f",m.name,&m.age,&m.sex,&m.height,&m.weight);
		//把结构体转换成字符串
		sprintf(buff,"%s %hhd %c %f %f\n",m.name,m.age,m.sex,m.height,m.weight);
		fwrite(buff,1,strlen(buff),fwp);
		//buff可以通过网络发送
		//buff可以拼接到sql语句中保存到数据库
	}
	fclose(fwp);
	
	FILE* frp = fopen("sunling.bin","r");
	for(int i=0; i<5; i++)
	{
		//读取一行数据
		fgets(buff,255,frp);//遇到回车停止
		//从字符串中提取结构体变量
		sscanf(buff,"%s %hhd %c %f %f",m.name,&m.age,&m.sex,&m.height,&m.weight);
		printf("%s %hhd %c %f %f\n",m.name,m.age,m.sex,m.height,m.weight);
	}
	fclose(frp);
}