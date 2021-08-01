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
			printf("����ѡ��\n");
			system("pause");
			system("cls");
		}
	} while (k);
	return 0;
}

//�ṩ�˵�
int menu()
{
	int n = 0;
	printf("                                ����ͨѶ¼����ϵͳ\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��         [1]:���뱾����Ҫ��ӵ�����                                               ��\n");                                            
	printf("��         [2]:�����뱾����ӵ�����                                                 ��\n"); 
	printf("��         [3]:�����ն�ͨѶ¼����                                                   ��\n");                                                
	printf("��         [4]:���ָ��������Ӧ�ĵ�ַ���绰���롢�������ڵ���Ϣ                     ��\n");
	printf("��         [5]:���ָ����������Ӧ�ĵ�ַ���绰���롢�������ڵ���Ϣ                   ��\n");
	printf("��         [6]:�������ӡ��ָ����������֮������������˵����ֵ�һ���ļ���           ��\n");
	printf("��         [7]:����������м�ͥ��Ա�����Ѻ���ҵ��������                           ��\n");
	printf("��         [0]:�˳�                                                                 ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��ѡ��: ");
	scanf("%d", &n);
	return n;
}

//����ͳ������
int getN(int n)
{
	int N;
	printf("�����뱾�β���Ҫ¼��ͨѶ¼������(ͨѶ¼�������500��):\n");
	while(1)
	{ 
		scanf("%d", &N);
		if ((N > 0) && (N <= 500) && (n + N <= 500))
		{
			break;
		}
		else
		{
			printf("����������������ͨѶ¼���ޣ�����������!\n");
		}
	}
	printf("\n�������!\n");
	system("pause");
	system("cls");
	return N;
}

//װ������
void loadData(struct extPersonType addressBook[NUM], int N)
{
	int i;
	printf("������Ҫ¼��ͨѶ¼����Ϣ\n");
	printf("�������ա��������͡��ֵ���ַ�����С�ʡ���������롢������ݡ������·ݡ��������ں͵绰����:\n");
	for (i = 0;i < N;i++,p++)
	{
		scanf("%s%s%s%s%s%s%d%d%d%d%d", p->datatype.firstname, p->datatype.lastname, p->personType, p->addresstype.address, p->addresstype.city, p->addresstype.province, &p->addresstype.postcode, &p->datatype.year, &p->datatype.month, &p->datatype.day, &p->datatype.phoneNum);
	}
	printf("\n¼�����!\n");
	system("pause");
	system("cls");
}

//�����ն�ͨѶ¼����
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
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{		
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
	}
	printf("\n�������!\n");
	system("pause");
	system("cls");
}

//���ָ��������Ӧ�ĵ�ַ���绰���롢�������ڵ���Ϣ
void findXING(struct extPersonType addressBook[NUM], int N)
{
	int i, flag = 0;
	char find[10];
	printf("����������ҵ���:\n");
	scanf("%s", find);
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{
		if (strcmp(find, addressBook[i].datatype.firstname) == 0)
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
	}
	if (flag == 0)
	{
		printf("\nδ���ҵ�����!\n");
	}
	printf("\n�������!\n");
	system("pause"); 
	system("cls");
}

//���ָ����������Ӧ�ĵ�ַ���绰���롢�������ڵ���Ϣ��
void findName(struct extPersonType addressBook[NUM], int N)
{
	int i, flag = 0;
	char findname[10];
	for (i = 0;i < N;i++)
	{
		strcpy(addressBook[i].datatype.name, addressBook[i].datatype.firstname);
		strcat(addressBook[i].datatype.name, addressBook[i].datatype.lastname);
	}
	printf("����������ҵ�����:\n");
	scanf("%s", findname);
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < N;i++)
	{
		if (strcmp(findname, addressBook[i].datatype.name) == 0)
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
	}
	if (flag == 0)
	{
		printf("\nδ���ҵ�����!\n");
	}
	printf("\n�������!\n");
	system("pause");
	system("cls");
}

//�������ӡ��ָ����������֮������������˵����ֵ�һ���ļ���
void findBirthday(struct extPersonType addressBook[NUM], int N)
{
	int i, findyear1, findmonth1, findday1, findyear2, findmonth2, findday2, flag = 0;
	printf("��������Ҫ���ҵ����ڷ�Χ((��һ������)-(�ڶ�������))\n");
	printf("��������Ҫ���ҵĵ�һ������(�ꡢ�¡���):");
	scanf("%d%d%d", &findyear1, &findmonth1, &findday1);
	printf("��������Ҫ���ҵĵڶ�������(�ꡢ�¡���):");
	scanf("%d%d%d", &findyear2, &findmonth2, &findday2);
	FILE* fp;
	if ((fp = fopen("maillist.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fprintf(fp, "************************************************************************************************\n");
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");fprintf(fp, "����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n\n");
	for (i = 0;i < N;i++)
	{
		if ((addressBook[i].datatype.year == findyear1) && (addressBook[i].datatype.year == findyear2))
		{
			if (addressBook[i].datatype.month == findmonth1)
			{
				if (addressBook[i].datatype.day >= findday1)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
			else if (addressBook[i].datatype.month > findmonth1)
			{
				if (addressBook[i].datatype.month < findmonth2)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
				else if (addressBook[i].datatype.month == findmonth2)
				{
					if (addressBook[i].datatype.day <= findday2)
					{
						flag = 1;
						printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
						fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
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
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
			else if (addressBook[i].datatype.month > findmonth1)
			{
				flag = 1;
				printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			}
		}
		else if ((addressBook[i].datatype.year > findyear1) && (addressBook[i].datatype.year < findyear2))
		{
			flag = 1;
			printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
		}
		else if ((addressBook[i].datatype.year > findyear1) && (addressBook[i].datatype.year == findyear2))
		{
			if (addressBook[i].datatype.month < findmonth2)
			{
				flag = 1;
				printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
			}
			else if (addressBook[i].datatype.month == findmonth2)
			{
				if (addressBook[i].datatype.day <= findday2)
				{
					flag = 1;
					printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
					fprintf(fp, "%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", addressBook[i].datatype.firstname, addressBook[i].datatype.lastname, addressBook[i].personType, addressBook[i].addresstype.address, addressBook[i].addresstype.city, addressBook[i].addresstype.province, addressBook[i].addresstype.postcode, addressBook[i].datatype.year, addressBook[i].datatype.month, addressBook[i].datatype.day, addressBook[i].datatype.phoneNum);
				}
			}
		}
	}
	fprintf(fp, "************************************************************************************************\n");
	fclose(fp);
	if (flag == 0)
	{
		printf("\nδ�в��ҵ�!\n");
	}
	printf("\n���Ҳ���ӡ���!\n");
	system("pause");
	system("cls");
}

//����������м�ͥ��Ա�����Ѻ���ҵ��������
void classify(struct extPersonType addressBook[NUM], int N)
{
	int i, j = 0, k = 0, l = 0;
	struct extPersonType friend[500];
	struct extPersonType family[500];
	struct extPersonType business[500];
	for (i = 0;i < N;i++)
	{
		if (strcmp(addressBook[i].personType, "����")==0)
		{
			friend[j] = addressBook[i];
			j++;
		}
		else if (strcmp(addressBook[i].personType, "��ͥ��Ա")==0)
		{
			family[k] = addressBook[i];
			k++;
		}
		else if (strcmp(addressBook[i].personType, "��ҵ���")==0)
		{
			business[l] = addressBook[i];
			l++;
		}
	}
	printf("************************************************************************************************\n");
	printf("\n����:\n");
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < j;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", friend[i].datatype.firstname, friend[i].datatype.lastname, friend[i].personType, friend[i].addresstype.address, friend[i].addresstype.city, friend[i].addresstype.province, friend[i].addresstype.postcode, friend[i].datatype.year, friend[i].datatype.month, friend[i].datatype.day, friend[i].datatype.phoneNum);
	}
	printf("\n************************************************************************************************\n");
	printf("\n��ͥ��Ա:\n");
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < k;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", family[i].datatype.firstname, family[i].datatype.lastname, family[i].personType, family[i].addresstype.address, family[i].addresstype.city, family[i].addresstype.province, family[i].addresstype.postcode, family[i].datatype.year, family[i].datatype.month, family[i].datatype.day, family[i].datatype.phoneNum);
	}
	printf("\n************************************************************************************************\n");
	printf("\n��ҵ���:\n");
	printf("����     ����              �ֵ���ַ          ����        ʡ   ��������    ��������      �绰����\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < l;i++)
	{
		printf("%s%-6s %-8s %20s %10s %10s   %d   %4d��%2d��%2d��   %d\n", business[i].datatype.firstname, business[i].datatype.lastname, business[i].personType, business[i].addresstype.address, business[i].addresstype.city, business[i].addresstype.province, business[i].addresstype.postcode, business[i].datatype.year, business[i].datatype.month, business[i].datatype.day, business[i].datatype.phoneNum);
	}
	printf("\n�������!\n");
	system("pause");
	system("cls");
}
//��