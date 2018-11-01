#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>				//ʹ�÷��ؾ���·������char* getcwd(char* buffer ,int len); 
#include <windows.h>
#define MAX_STU 1000			//��󴢴�1000��ѧ������ 
#define PASSWORD_INPUT_MAX 5	//�������ĵ�¼������� 

void Welcome();             //����һ����ӭ����
void menu();				//����һ���˵�
void stu_add();             //����ѧ�����ݵ����
int stu_output();          //����ѧ�����ݵ����
int stu_find();            	//����ѧ�����ݵĲ���
int stu_revise();          	//����ѧ�����ݵ��޸�
void stu_delete();          //����ѧ�����ݵ�ɾ��
void delete_way(int t);		//����ɾ��ѧ�����ݵķ���
void stu_subsection();      //����ѧ�����ݵķֶ�
void stu_fileClass();       //�����ļ��Ĵ���
int stu_over();            //�������������
int file_storage();        	//�����ļ��Ĵ���
int file_show();         	//�����ļ������
int file_import();        	//�����ļ��ĵ���
void avg_lesson();			//������ÿ�ſε�ƽ���ɼ�
void avg_student();			//����ÿ��ѧ����ƽ���ɼ�����ֵ��ṹ��������
void sort();				//����������
void find_id();				//���尴ѧ�Ų��Һ���
void find_name();			//���尴�������Һ���  
void cls();					//�������Ի����������� 
void password_input();		//������������� 


struct Student              //����һ��ѧ���ṹ��
{
	char names[30];         //����
	long long stu_id;       //ѧ��
	int stu_class;       	//�༶
	double lesson1;         //�ߵ���ѧ����
	double lesson2;         //Ӣ������˵
	double lesson3;         //��ѧ���������
	double lesson4;         //������̵���
	double lesson5;         //C���Գ������
	double avg;
}student[MAX_STU];


char password_real[30]  = "123456";					//�ڴ˴��������� 
int now_index=0;									//��������ʼ¼���now_index��ѧ��
int i;												//��������i����forѭ��
double avg1=0,avg2=0,avg3=0,avg4=0,avg5=0,avg0;		//Ϊ��ƽ����׼�� 
FILE * fp;
char temp_cls;										//������������ʱ�س�ѡ�� 


int main()
{
	//system("color 0A");
	Welcome();			//��ӭ����
	password_input();	//�������� 
    for(;;)
	{
		menu();				//��ʾ�˵��������˵�
	}
	return 0;
}

void Welcome()				//��ӭ�����ʵ��
{
	char enter;
    printf("��ӭʹ��Junking��˾��Ʒ��ѧ����Ϣ����ϵͳ��\n");
    printf("��л����Junking��˾��֧����������\n");
    printf("**************************************************************************************************\n");
    printf("��ܰ��ʾ��\n"); 
    printf("һ��Ϊ����������ʹ�ã���ȫ��״̬�²������\n");
    printf("�����ó���������ƽ���ɼ������ִ�����ݵĴ�����\n");
    printf("�������������������棬�����ܴ洢1000��ѧ�����ݡ�������߿ɴ洢�������µ����ǹ����Ա�棡\n");
    printf("**************************************************************************************************\n");


//    printf("��ʼʹ�������������ַ����س���");
// 	scanf("%c",&enter);
// 	system("cls");


}

void menu()
{
    int menu_id;
	printf("**********************************************************************************\n");
    printf("1������µ�ѧ������\t\t\t2�����������ǰѧ������(����ƽ���ɼ�)\n");
    printf("3��ѧ�����ݵĲ���\t\t\t4��ѧ�����ݵ��޸�\n");
    printf("5��ѧ�����ݵ�ɾ��\t\t\t6��ѧ���ɼ��ķֶ�\n");
    printf("7���ļ�����\t\t\t\t8������ϵͳ\n");
    printf("**********************************************************************************\n");
 	printf("��������Ҫ���еĲ���ǰ������:");

	loop_menu:scanf("%d",&menu_id);
    switch(menu_id)				//ѡ��˵�
        {
            case 1: stu_add();break;
            case 2: stu_output();cls();break;
            case 3: stu_find();cls();break;
            case 4: stu_revise();cls();break;
            case 5: stu_delete();cls();break;
            case 6: stu_subsection();cls();break;
            case 7: stu_fileClass();break;
            case 8: stu_over();cls();break;
            default : {
            				fflush(stdin) ;
                            printf("���������������������룺");
                            goto loop_menu;	//ѭ���ò˵�
                       }
        }
}


void stu_add()
{
	char y_n;				//�ж��Ƿ�Ҫ����¼��ѧ������
    int stu_index=0;		//ѧ���±꣬ʵ������¼��ṹ������
	printf("����������ѧ����������ѧ�š��༶(����������)���Լ��ߵ���ѧ���ϡ�Ӣ������˵����ѧ�����������������̵��ۡ�C���Գ�����Ƶĳɼ������Կո�ָ�\n");
loop_add:
	stu_index = now_index++;	//����Ѿ������ѧ�����������ں��������
	scanf("%s %lld %d %lf %lf %lf %lf %lf",student[stu_index].names,&student[stu_index].stu_id,&student[stu_index].stu_class,&student[stu_index].lesson1,&student[stu_index].lesson2,&student[stu_index].lesson3,&student[stu_index].lesson4,&student[stu_index].lesson5);
	printf("�Ƿ�Ҫ��������ѧ������:(Y/N)\n");
	fflush(stdin);
loop_y_n:
	scanf("%c",&y_n);
	if(y_n=='y' || y_n=='Y')
	{goto loop_add;}			//ѭ������ѧ������ֱ���ж��ս�
	else if(y_n=='n' || y_n=='N')
	{
		fflush(stdin);
		system("cls");
	}
	else 						//�жϵ�û������ָ���ַ�ʱ
	{
		fflush(stdin);
		printf("���������������������룺");
		goto loop_y_n;

	}

}

int stu_output()
{
	if(now_index == 0) 		//�ж��Ƿ���ѧ�����ݵ����
	{
		printf("ϵͳ�в�δ�������ݣ������Գ������������ѧ�����ݻ���ļ���¼�������ٽ���ѧ�����ݵ�չʾ��\n");
		return 0;	 
	}
	avg_student();			//����ÿ��ѧ����ƽ���ɼ�
	sort();					//���� 
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");

	for(i = 0 ; i < now_index ;i++)
	{
		printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
	}
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    avg_lesson();			//���ÿ�ƿ�Ŀ��ƽ���ɼ�
    
	
    return 0;
    
}

int stu_find()
{ 
	if(now_index == 0) 		//�ж��Ƿ���ѧ�����ݵ����
	{
		printf("ϵͳ�в�δ�������ݣ������Գ������������ѧ�����ݻ���ļ���¼�������ٽ���ѧ�����ݵĲ��ҡ�\n");
		return 0;	 
	}
	int find_index;
	printf("1����ѧ�Ų���\t\t\t2������������\t\t\t3�����ز˵�\n"); 
	printf("��ѡ���Ӧ���:");
loop_find:
	scanf("%d",&find_index);
	switch(find_index)
	{
		case 1:find_id();break;
		case 2:find_name();break;
		case 3:return 0;
		default:
			{
				fflush(stdin);
				printf("����������������������:"); 
				goto loop_find;
			}
	}
	return 0;
	
}

int stu_revise()
{	
	if(now_index == 0) 		//�ж��Ƿ���ѧ�����ݵ����
	{
		printf("ϵͳ�в�δ�������ݣ������Գ������������ѧ�����ݻ���ļ���¼�������ٽ���ѧ�����ݵ��޸ġ�\n");
		return 0;	 
	}
	int if_exit=-1;
	double k;
	int j,m;		//��ʱ������������� 
	long long revise_id;
	printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
loop_refind:
	scanf("%lld",&revise_id);
	for(i=0;i<now_index;i++)
	{
		if(revise_id == student[i].stu_id)
		{
				printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
				printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");
				printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
				printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
				if_exit = 1;
				break;
				
		}
		
	
	}
	if(if_exit == -1 )
	{
		printf("δ�ҵ���ѧ�ţ���Ҫ��������������0\n");
		scanf("%d",&m);
		switch(m)
		{
			case 0:
				{
					fflush(stdin);
					printf("������������Ҫ���ҵ�ѧ����ѧ�ţ�");
					goto loop_refind;
					
				}break;
			
			default:return 0;
		}
		
	}
		printf("��������Ҫ�޸ĵĿ�Ŀ����ţ�\n");
		printf("1���ߵ���ѧ����\n");
		printf("2��Ӣ������˵\n");
		printf("3����ѧ���������\n");
		printf("4��������̵���\n");;
		printf("5��c���Գ������\n");
		fflush(stdin);
loop_revise:
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				{
					printf("���뽫�ɼ��޸ĳɣ�");
					scanf("%lf",&k);
					student[i].lesson1 = k;
				}break;
			case 2:
				{
					printf("���뽫�ɼ��޸ĳɣ�");
					scanf("%lf",&k);
					student[i].lesson2 = k;
				}break;
			case 3:
				{
					printf("���뽫�ɼ��޸ĳɣ�");
					scanf("%lf",&k);
					student[i].lesson3 = k;
				}break;
			case 4:
				{
					printf("���뽫�ɼ��޸ĳɣ�");
					scanf("%lf",&k);
					student[i].lesson4 = k;
				}break;
			case 5:
				{
					printf("���뽫�ɼ��޸ĳɣ�");
					scanf("%lf",&k);
					student[i].lesson5 = k;
				}break;
			default:
			{
				fflush(stdin);
				printf("���������������������룺"); 
				goto loop_revise;
			}
		}
		return 0;
}
	


void stu_delete()
{
	
	if(now_index<=0)		//�ж������ݵ���� 
	{
		printf("ϵͳ��û��ѧ�����ݣ�����¼���ٽ������ݵ�ɾ����\n"); 
	}else
	{
				int if_exit=-1;
				double k;
				int j,m;		//��ʱ������������� 
				long long delete_id;
				printf("��������Ҫɾ����ѧ����ѧ�ţ�");
			loop_redelete:
				scanf("%lld",&delete_id);
				for(i=0;i<now_index;i++)
				{
					if(delete_id == student[i].stu_id)
					{
						delete_way(i);
						printf("��ѧ�������ѳɹ�ɾ����\n");
							if_exit = 1;
							break;
							
					}
					
				
				}
				if(if_exit == -1 )
				{
					printf("δ�ҵ���ѧ�ţ���Ҫ����ɾ��������1\n");
					scanf("%d",&m);
					switch(m)
					{
						case 1:
							{
								fflush(stdin);
								printf("������������Ҫɾ����ѧ����ѧ�ţ�");
								goto loop_redelete;
								
							}break;
						
						default:break; 
					}
					
				}
	} 
}

void stu_subsection()				//���ݵķֶ� 
{ 
	if(now_index == 0)		//�ж��Ƿ���ѧ�����ݵ����
	{
		printf("ϵͳ�в�δ�������ݣ������Գ������������ѧ�����ݻ���ļ���¼�������ٽ������ݵķֶΡ�\n");
		
	} else
		{ 
		sort();
		int stu_s[5]={};				//ÿ��������������ʱ����
		printf("����20�ֲַ��ƽ���ɼ����зֶΣ�\n"); 
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		
		for(i=0;i<now_index;i++)
		{
			if(student[i].avg > 80)
			{
				stu_s[0]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">80��<=100��ѧ����%d��:\n",stu_s[0]);	
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	
		for(i=stu_s[0];i<now_index;i++)
		{
			if(student[i].avg <= 80 && student[i].avg>60)
			{
				stu_s[1]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">60��<=80��ѧ����%d��\n",stu_s[1]);
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		
		 
		for(i=stu_s[0]+stu_s[1];i<now_index;i++)
		{
			if(student[i].avg <= 60 && student[i].avg>40)
			{
				stu_s[2]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		}
		 printf(">40��<=60��ѧ����%d��\n",stu_s[2]);
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		
		for(i=stu_s[0]+stu_s[1]+stu_s[2];i<now_index;i++)
		{
			if(student[i].avg <= 40 && student[i].avg>20)
			{
				stu_s[3]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">20��<=40��ѧ����%d��\n",stu_s[3]);
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		
		for(i=stu_s[0]+stu_s[1]+stu_s[2]+stu_s[3];i<now_index;i++)
		{
			if(student[i].avg <= 20 && student[i].avg>0)
			{
				stu_s[4]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 	
		printf(">0��<=20��ѧ����%d��\n",stu_s[4]);
		printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	}	
}

void stu_fileClass()
{
    int file_id;
	printf("1�����浽�ļ���\n2���ļ����ݵ�չʾ\n3���򿪲��������\n4���������˵�\n");
    printf("��������Ҫ���ļ����еĲ�������ţ�\n");
   
    loop_file:scanf("%d",&file_id);
    switch(file_id)
    {
        case 1:file_storage();cls();break;
        case 2:file_show();cls();break;
        case 3:file_import();cls();break;
        case 4:cls();break;
        default:{
        			fflush(stdin);
                    printf("���������������������룺");
                    goto loop_file;
                }
    }
}

int stu_over()
{
	int ifSure; 
	printf("��ܰ��ʾ�������ȷ�����ݱ��Ѿ������ļ��л��߲���Ҫ�˲�����\n");
	printf("�����Ҫ���ص��˵�������0\n");
	scanf("%d",&ifSure);
	if(ifSure == 0) 
	{	
		return 0;
	} 
	printf("�뿪��ʱ�����������ֿ��ף������л���㣬�ټ���\n");
	exit(0);		//�������� 
	
}

int file_storage()
{
	char *buffer; 
	if((fp =  fopen("Student datas.txt","w"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0); 
	}
	if(now_index==0)
	{
		printf("ע�⣺���ڸù���ϵͳ�в�δ�������ݣ����赼�뵽�ı��ĵ��У�\n"); 
		return 0; 
	}
	fprintf(fp,"%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");
	for(i=0;i<now_index;i++)
	{
		fprintf(fp,"%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
	}
	fprintf(fp,"%-48s%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n","ÿһ�ſγ̵�ƽ���ɼ���",avg1,avg2,avg3,avg4,avg5,avg0);
	printf("�ļ��洢�ɹ�����Ӧ�ļ������ڣ�\n");
	
	if((buffer = getcwd(NULL,0))==NULL)
	{
		printf("·����ȡʧ�ܣ�\n"); 
	}else
	{
		printf("%s\n",buffer);
		printf("�ļ���Ϊ:Student datas.txt\n"); 
		free(buffer);
	}
	fclose(fp);
	return 0;
}

int file_show()
{
	char file_ch;
	int line =0;
	fp =fopen("Student datas.txt","r");			//ֻ���ļ������ļ� 
	int file_index = 0;			//�жϵ�ǰ�ļ��ж�������Ч���� 	
	
	for(;;)				//�ҵ����ж��������� 
	{
		if((file_ch = fgetc(fp)) == '\n')
		{
			line++;
		}
		if(file_ch == EOF)
		break;
	}
	rewind(fp); 
	file_index = line-2;
	if(file_index<=0)							//�ж�û�����ݵ������ 
	{
		printf("ע�⣺�ļ���û��¼��ѧ������,�뵱�ļ���������ʱ�ٲ���!\n"); 
		return 0;					
	}
	
	
	printf("Student datas.txt�е�������:\n"); 

	char ch;
	while((ch=fgetc(fp)) != EOF)				//һֱִ�е����ַ� 
	{
		putchar(ch); 
	}
	fclose(fp);
	return 0;
}

int file_import()
{
	char ch;						//����'\n' 
	int line = 0;					//�ҵ�����line������ 
	char temp_total[10][5000];
	if((fp =  fopen("Student datas.txt","r"))==NULL)
	{
		
		printf("���ļ�ʧ�ܣ�\n");
		exit(0); 
	}
	
	for(;;)				//�ҵ����ж��������� 
	{
		if((ch = fgetc(fp)) == '\n')
		{
			line++;
		}
		if(ch == EOF)
		break;
	}
		
	rewind(fp);									//��ָ������ָ���ļ��Ŀ�ͷ 

	
	fscanf(fp,"%[^\n]",temp_total[0]);			//����һ�еı����ȡ����������ʱ�����в����� 
	fgetc(fp);

	
	if(line -2<=0)							//�ж�û�����ݵ������ 
	{
		printf("ע�⣺�ļ���û��¼��ѧ������,�뵱�ļ���������ʱ�ٲ���!\n"); 
		return 0;					
	}
	
	now_index = line-2;			//����ǰѧ���������³�ʼ�����ļ��е����� 
	printf("����ɹ�!�����ǵ���������:\n"); 
	printf("%s\n",temp_total[0]);
	for(i=0;i<line-2;i++)
	{
		fscanf(fp,"%s %lld %d %lf %lf %lf %lf %lf %lf\n",student[i].names,&student[i].stu_id,&student[i].stu_class,&student[i].lesson1,&student[i].lesson2,&student[i].lesson3,&student[i].lesson4,&student[i].lesson5,&student[i].avg);
		printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
	}
	return 0;
	
}

void avg_lesson()
{
	double sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
	for(i=0;i<now_index;i++)
	{
		sum1 += student[i].lesson1;
		sum2 += student[i].lesson2;
		sum3 += student[i].lesson3;
		sum4 += student[i].lesson4;
		sum5 += student[i].lesson5;
	}
	avg1=sum1/now_index;
	avg2=sum2/now_index;
	avg3=sum3/now_index;
	avg4=sum4/now_index;
	avg5=sum5/now_index;
	avg0=(avg1+avg2+avg3+avg4+avg5)/5;
	printf("%-48s%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n","ÿһ�ſγ̵�ƽ���ɼ���",avg1,avg2,avg3,avg4,avg5,avg0);
	printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");


}

void avg_student()
{
    double sum=0;
	for(i=0;i<now_index;i++)
	{
	    sum=student[i].lesson1+student[i].lesson2+student[i].lesson3+student[i].lesson4+student[i].lesson5;
		student[i].avg = sum / 5;
	}
}

void sort()
{
	int j;
	struct Student temp;
	for(i=0;i<now_index;i++)
    {
        for(j=0;j<now_index-i-1;j++)
        {
            if(student[j].avg < student[j+1].avg)
            {
                temp = student[j+1];
                student[j+1] = student[j];
                student[j] = temp;
            }
        }
    }

}

void find_id()
{
    int if_wrong = -1;   //�ж��Ƿ��ҵ���ѧ��
	int sure;               //�ж��Ƿ��������ѧ��
	long long id; 
loop_con_find_id:	
	printf("��������Ҫ���ҵ�ѧ�ţ�");
	scanf("%ld",&id);
	for(i=0;i<now_index;i++)
	{
		if(id == student[i].stu_id)
        {	
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
           	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");
            printf("%-16s%-16ld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            if_wrong = 1;
            break;
            
        }
        
	}
	if(if_wrong == -1)
    {
        printf("δ�ҵ���ѧ�ţ��Ƿ�Ҫ�������ң�\n");
        printf("1����������\t\t2��ֹͣ����\n");
     loop_re_find_id:   
        scanf("%d",&sure);
        switch(sure)
        {
            case 1:goto loop_con_find_id;break;
            case 2:break;
            default:
                {
                    fflush(stdin);
                    printf("���������������������룺");
                    goto loop_re_find_id;
                }
        }
    }
	
}

void find_name()
{
	int if_wrong = -1;   //�ж��Ƿ��ҵ������� 
	int sure;               //�ж��Ƿ������������
	char name[30]; 
loop_con_find_name:	
	printf("��������Ҫ���ҵ�������");
	scanf("%s",name);
	for(i=0;i<now_index;i++)
	{
		if(strcmp(name,student[i].names)==0)
        {	
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
           	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","����","ѧ��","�༶","�ߵ���ѧ����","Ӣ������˵","��ѧ���������","������̵���","c���Գ������","ƽ���ɼ�");
            printf("%-16s%-16ld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
            printf("������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            if_wrong = 1;
            break;
            
        }
        
	}
	if(if_wrong == -1)
    {
        printf("δ�ҵ����������Ƿ�Ҫ�������ң�\n");
        printf("1����������\t\t2��ֹͣ����\n");
     loop_re_find_name:   
        scanf("%d",&sure);
        switch(sure)
        {
            case 1:goto loop_con_find_name;break;
            case 2:break;
            default:
                {
                    fflush(stdin);
                    printf("���������������������룺");
                    goto loop_re_find_name;
                }
        }
    }
} 

void delete_way(int t)
{ 
	int h;
	int temp_loop_num = now_index -t -1;
	for(h=0;h<MAX_STU-1;h++)		//��ɾ������ǰ��λ 
	{
		student[t] = student[t+1];
		t++;
	}
	now_index--;
}

void cls()
{
	fflush(stdin);
	printf("**********************************************************************************\n");
    printf("����ѡ��˵�ѡ����س��������\n"); 
	scanf("%c",&temp_cls);
	system("cls");
} 

void password_input()
{
	
	int password_input_num = 0; 
	char password_input[30];
	printf("��������������:\n");
loop_password_input:
	
	
	password_input_num++;
	if(password_input_num > PASSWORD_INPUT_MAX)
	{
		
		printf("���������������������ƴ������˳�ϵͳ��");
		exit(0); 
	}	
	
	
	scanf("%s",password_input);
	
	if(strcmp(password_real,password_input) != 0)
	{
		
		if(password_input_num != PASSWORD_INPUT_MAX)							//������������������ 
		printf("����������������������%d�Σ�\n",password_input_num+1); 
		fflush(stdin);
		goto loop_password_input;
	}else
	{
		system("cls");
		printf("����������ȷ����ӭʹ�ã�\n");
	}
	
	
}

