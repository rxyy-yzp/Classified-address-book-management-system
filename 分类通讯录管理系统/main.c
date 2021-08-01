#include"stdio.h"
#include"string.h"
#include"stdlib.h"

#define NUM 500

int menu();
int getN(int n);
void loadData(struct extPersonType addressBook[NUM], int N);
void findXING(struct extPersonType addressBook[NUM], int N);
void sortXING(struct extPersonType addressBook[NUM], int N);
void findName(struct extPersonType addressBook[NUM], int N);
void findBirthday(struct extPersonType addressBook[NUM], int N);
void classify(struct extPersonType addressBook[NUM], int N);

struct extPersonType
{
	char personType[20];
	struct addressType
    {
	    char address[50];
	    char city[20];
	    char province[20];
	    int postcode;
    }addresstype;
	struct dataType
	{
		char firstname[6];
		char lastname[10];
		char name[16];
		int phoneNum;
	    int year;
		int month;
		int day;
    }datatype;
	
}addressBook[NUM];
struct extPersonType* p = &addressBook[0];

int main()
{
	int k, N = 0, n = 0;
	do {
		k = menu();
		switch (k)
		{
		case 0:
			break;
		case 1:
			N = getN(n);
			n += N;
			break;
		case 2:
			loadData(addressBook, N);
			break;
		case 3:
			sortXING(addressBook, n);
			break;
		case 4:
			findXING(addressBook, n);
			break;
		case 5:
			findName(addressBook, n);
			break;
		case 6:
			findBirthday(addressBook, n);
			break;
		case 7:
			classify(addressBook, n);
			break;
		default:
			printf("错误选择\n");
			system("pause");
			system("cls");
		}
	} while (k);
	return 0;
}

//提供菜单
int menu()
{
	int n = 0;
	printf("                                分类通讯录管理系统\n");
	printf("┌──────────────────────────────────────────────────────────────────────────────────┐\n");
	printf("│         [1]:输入本次需要添加的人数                                               │\n");                                            
	printf("│         [2]:请输入本次添加的数据                                                 │\n"); 
	printf("│         [3]:按照姓对通讯录排序                                                   │\n");                                                
	printf("│         [4]:输出指定姓所对应的地址、电话号码、出生日期等信息                     │\n");
	printf("│         [5]:输出指定姓名所对应的地址、电话号码、出生日期等信息                   │\n");
	printf("│         [6]:输出并打印在指定两个日期之间出生的所有人的名字到一个文件中           │\n");
	printf("│         [7]:分类输出所有家庭成员、朋友和商业伙伴的姓名                           │\n");
	printf("│         [0]:退出                                                                 │\n");
	printf("└──────────────────────────────────────────────────────────────────────────────────┘\n");
	printf("请选择: ");
	scanf("%d", &n);
	return n;
}

//输入统计人数
int getN(int n)
{
	int N;
	printf("请输入本次操作要录入通讯录的人数(通讯录最多容纳500人):\n");
	while(1)
	{ 
		scanf("%d", &N);
		if ((N > 0) && (N <= 500) && (n + N <= 500))
		{
			break;
		}
		else
		{
			printf("输入错误或人数超出通讯录上限，请重新输入!\n");
		}
	}
	printf("\n输入完毕!\n");
	system("pause");
	system("cls");
	return N;
}

//装载数据
void loadData(struct extPersonType addressBook[NUM], int N)
{
	int i;
	printf("请输入要录入通讯录的信息\n");
	printf("请输入姓、名、类型、街道地址、城市、省、邮政编码、出生年份、出生月份、出生日期和电话号码:\n");
	for (i = 0;i < N;i++,p++)
	{
		scanf("%s%s%s%s%s%s%d%d%d%d%d", p->datatype.firstname, p->datatype.lastname, p->personType, p->addresstype.address, p->addresstype.city, p->addresstype.province, &p->addresstype.postcode, &p->datatype.year, &p->datatype.month, &p->datatype.day, &p->datatype.phoneNum);
	}
	printf("\n录入完毕!\n");
	system("pause");
	system("cls");
}

//按照姓对通讯录排序
void sortXING(struct extPersonType addressBook[NUM], int N)
{
	int i, j, num;
	struct extPersonType temp;
	for (i = 0;i < N - 1;i++)
	{
		num = i;
		for (j = i + 1;j < N;j++)
		{
			if (strcmp(addressBook[j].datatype.firstname, addressBook[num].datatype.firstname) > 0)
				num = j;
		}
		if (num != i)
		{
			temp = addressBook[num];
			addressBook[num] = addressBook[i];
			addressBook[i] = temp;
		}
	}
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{		
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
	}
	printf("\n排序完毕!\n");
	system("pause");
	system("cls");
}

//输出指定姓所对应的地址、电话号码、出生日期等信息
void findXING(struct extPersonType addressBook[NUM], int N)
{
	int i, flag = 0;
	char find[10];
	printf("请输入想查找的姓:\n");
	scanf("%s", find);
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{
		if (strcmp(find, addressBook[i].datatype.firstname) == 0)
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
	}
	if (flag == 0)
	{
		printf("\n未有找到该姓!\n");
	}
	printf("\n查找完毕!\n");
	system("pause"); 
	system("cls");
}

//输出指定姓名所对应的地址、电话号码、出生日期等信息。
void findName(struct extPersonType addressBook[NUM], int N)
{
	int i, flag = 0;
	char findname[10];
	for (i = 0;i < N;i++)
	{
		strcpy(addressBook[i].datatype.name, addressBook[i].datatype.firstname);
		strcat(addressBook[i].datatype.name, addressBook[i].datatype.lastname);
	}
	printf("请输入想查找的姓名:\n");
	scanf("%s", findname);
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{
		if (strcmp(findname, addressBook[i].datatype.name) == 0)
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
	}
	if (flag == 0)
	{
		printf("\n未有找到该姓!\n");
	}
	printf("\n查找完毕!\n");
	system("pause");
	system("cls");
}

//输出并打印在指定两个日期之间出生的所有人的名字到一个文件中
void findBirthday(struct extPersonType addressBook[NUM], int N)
{
	int i, findyear1, findmonth1, findday1, findyear2, findmonth2, findday2, flag = 0;
	printf("请输入想要查找的日期范围((第一个日期)-(第二个日期))\n");
	printf("请输入想要查找的第一个日期(年、月、日):");
	scanf("%d%d%d", &findyear1, &findmonth1, &findday1);
	printf("请输入想要查找的第二个日期(年、月、日):");
	scanf("%d%d%d", &findyear2, &findmonth2, &findday2);
	FILE* fp;
	if ((fp = fopen("maillist.txt", "w")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fprintf(fp, "************************************************************************************************\n");
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");fprintf(fp, "姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n\n");
	for (i = 0;i < N;i++)
	{
		if ((addressBook[i].datatype.year == findyear1) && (addressBook[i].datatype.year == findyear2))
		{
			if (addressBook[i].datatype.month == findmonth1)
			{
				if (addressBook[i].datatype.day >= findday1)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
			else if (addressBook[i].datatype.month > findmonth1)
			{
				if (addressBook[i].datatype.month < findmonth2)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
				else if (addressBook[i].datatype.month == findmonth2)
				{
					if (addressBook[i].datatype.day <= findday2)
					{
						flag = 1;
						printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
						fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					}
				}
			}
		}
		else if ((addressBook[i].datatype.year == findyear1) && (addressBook[i].datatype.year < findyear2))
		{
			if (addressBook[i].datatype.month == findmonth1)
			{
				if (addressBook[i].datatype.day >= findday1)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
			else if (addressBook[i].datatype.month > findmonth1)
			{
				flag = 1;
				printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			}
		}
		else if ((addressBook[i].datatype.year > findyear1) && (addressBook[i].datatype.year < findyear2))
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
		else if ((addressBook[i].datatype.year > findyear1) && (addressBook[i].datatype.year == findyear2))
		{
			if (addressBook[i].datatype.month < findmonth2)
			{
				flag = 1;
				printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			}
			else if (addressBook[i].datatype.month == findmonth2)
			{
				if (addressBook[i].datatype.day <= findday2)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
		}
	}
	fprintf(fp, "************************************************************************************************\n");
	fclose(fp);
	if (flag == 0)
	{
		printf("\n未有查找到!\n");
	}
	printf("\n查找并打印完毕!\n");
	system("pause");
	system("cls");
}

//分类输出所有家庭成员、朋友和商业伙伴的姓名
void classify(struct extPersonType addressBook[NUM], int N)
{
	int i, j = 0, k = 0, l = 0;
	struct extPersonType friend[500];
	struct extPersonType family[500];
	struct extPersonType business[500];
	for (i = 0;i < N;i++)
	{
		if (strcmp(addressBook[i].personType, "朋友")==0)
		{
			friend[j] = addressBook[i];
			j++;
		}
		else if (strcmp(addressBook[i].personType, "家庭成员")==0)
		{
			family[k] = addressBook[i];
			k++;
		}
		else if (strcmp(addressBook[i].personType, "商业伙伴")==0)
		{
			business[l] = addressBook[i];
			l++;
		}
	}
	printf("************************************************************************************************\n");
	printf("\n朋友:\n");
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < j;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", friend[i].datatype.firstname, friend[i].datatype.lastname, friend[i].personType, friend[i].addresstype.address, friend[i].addresstype.city, friend[i].addresstype.province, friend[i].addresstype.postcode, friend[i].datatype.year, friend[i].datatype.month, friend[i].datatype.day, friend[i].datatype.phoneNum);
	}
	printf("\n************************************************************************************************\n");
	printf("\n家庭成员:\n");
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < k;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", family[i].datatype.firstname, family[i].datatype.lastname, family[i].personType, family[i].addresstype.address, family[i].addresstype.city, family[i].addresstype.province, family[i].addresstype.postcode, family[i].datatype.year, family[i].datatype.month, family[i].datatype.day, family[i].datatype.phoneNum);
	}
	printf("\n************************************************************************************************\n");
	printf("\n商业伙伴:\n");
	printf("姓名     类型              街道地址          城市        省   邮政编码    出生日期      电话号码\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < l;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d年%2d月%2d日   %d\n", business[i].datatype.firstname, business[i].datatype.lastname, business[i].personType, business[i].addresstype.address, business[i].addresstype.city, business[i].addresstype.province, business[i].addresstype.postcode, business[i].datatype.year, business[i].datatype.month, business[i].datatype.day, business[i].datatype.phoneNum);
	}
	printf("\n分类完毕!\n");
	system("pause");
	system("cls");
}
//完