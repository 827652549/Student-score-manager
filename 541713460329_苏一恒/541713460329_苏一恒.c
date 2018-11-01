#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>				//使用返回绝对路径函数char* getcwd(char* buffer ,int len); 
#include <windows.h>
#define MAX_STU 1000			//最大储存1000个学生数据 
#define PASSWORD_INPUT_MAX 5	//最大输入的登录密码次数 

void Welcome();             //定义一个欢迎界面
void menu();				//定义一个菜单
void stu_add();             //定义学生数据的添加
int stu_output();          //定义学生数据的输出
int stu_find();            	//定义学生数据的查找
int stu_revise();          	//定义学生数据的修改
void stu_delete();          //定义学生数据的删除
void delete_way(int t);		//定义删除学生数据的方法
void stu_subsection();      //定义学生数据的分段
void stu_fileClass();       //定义文件的处理
int stu_over();            //定义结束的内容
int file_storage();        	//定义文件的储存
int file_show();         	//定义文件的输出
int file_import();        	//定义文件的导入
void avg_lesson();			//定义求每门课的平均成绩
void avg_student();			//定义每个学生的平均成绩并赋值入结构体数组中
void sort();				//定义排序函数
void find_id();				//定义按学号查找函数
void find_name();			//定义按姓名查找函数  
void cls();					//定义人性化的清屏函数 
void password_input();		//定义密码的输入 


struct Student              //定义一个学生结构体
{
	char names[30];         //姓名
	long long stu_id;       //学号
	int stu_class;       	//班级
	double lesson1;         //高等数学·上
	double lesson2;         //英语视听说
	double lesson3;         //大学计算机基础
	double lesson4;         //软件工程导论
	double lesson5;         //C语言程序设计
	double avg;
}student[MAX_STU];


char password_real[30]  = "123456";					//在此处设置密码 
int now_index=0;									//接下来开始录入第now_index个学生
int i;												//定义整形i用来for循环
double avg1=0,avg2=0,avg3=0,avg4=0,avg5=0,avg0;		//为求平均做准备 
FILE * fp;
char temp_cls;										//清屏函数的临时回车选项 


int main()
{
	//system("color 0A");
	Welcome();			//欢迎界面
	password_input();	//输入密码 
    for(;;)
	{
		menu();				//显示菜单并操作菜单
	}
	return 0;
}

void Welcome()				//欢迎界面的实现
{
	char enter;
    printf("欢迎使用Junking公司出品的学生信息管理系统！\n");
    printf("感谢您对Junking公司的支持与信赖！\n");
    printf("**************************************************************************************************\n");
    printf("温馨提示：\n"); 
    printf("一、为了您的正常使用，请全屏状态下操作软件\n");
    printf("二、该程序仅当求出平均成绩后才能执行数据的处理功能\n");
    printf("三、本程序是免费体验版，最多仅能存储1000个学生数据。如需提高可存储量，请致电我们购求会员版！\n");
    printf("**************************************************************************************************\n");


//    printf("开始使用请输入任意字符并回车：");
// 	scanf("%c",&enter);
// 	system("cls");


}

void menu()
{
    int menu_id;
	printf("**********************************************************************************\n");
    printf("1、添加新的学生数据\t\t\t2、降序输出当前学生数据(包括平均成绩)\n");
    printf("3、学生数据的查找\t\t\t4、学生数据的修改\n");
    printf("5、学生数据的删除\t\t\t6、学生成绩的分段\n");
    printf("7、文件操作\t\t\t\t8、结束系统\n");
    printf("**********************************************************************************\n");
 	printf("请输入你要进行的操作前面的序号:");

	loop_menu:scanf("%d",&menu_id);
    switch(menu_id)				//选择菜单
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
                            printf("您的输入有误，请重新输入：");
                            goto loop_menu;	//循环该菜单
                       }
        }
}


void stu_add()
{
	char y_n;				//判断是否要继续录入学生数据
    int stu_index=0;		//学生下标，实现依次录入结构体数组
	printf("请依次输入学生的姓名、学号、班级(阿拉伯数字)、以及高等数学·上、英语视听说、大学计算机基础、软件工程导论、C语言程序设计的成绩，并以空格分隔\n");
loop_add:
	stu_index = now_index++;	//检查已经输入的学生数量，并在后依次添加
	scanf("%s %lld %d %lf %lf %lf %lf %lf",student[stu_index].names,&student[stu_index].stu_id,&student[stu_index].stu_class,&student[stu_index].lesson1,&student[stu_index].lesson2,&student[stu_index].lesson3,&student[stu_index].lesson4,&student[stu_index].lesson5);
	printf("是否要继续输入学生数据:(Y/N)\n");
	fflush(stdin);
loop_y_n:
	scanf("%c",&y_n);
	if(y_n=='y' || y_n=='Y')
	{goto loop_add;}			//循环输入学生数据直到判断终结
	else if(y_n=='n' || y_n=='N')
	{
		fflush(stdin);
		system("cls");
	}
	else 						//判断当没有输入指定字符时
	{
		fflush(stdin);
		printf("您的输入有误请重新输入：");
		goto loop_y_n;

	}

}

int stu_output()
{
	if(now_index == 0) 		//判断是否有学生数据的情况
	{
		printf("系统中并未保存数据！您可以尝试先在先添加学生数据或从文件中录入数据再进行学生数据的展示。\n");
		return 0;	 
	}
	avg_student();			//计算每个学生的平均成绩
	sort();					//排序 
	printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");

	for(i = 0 ; i < now_index ;i++)
	{
		printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
	}
	printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
    avg_lesson();			//输出每科科目的平均成绩
    
	
    return 0;
    
}

int stu_find()
{ 
	if(now_index == 0) 		//判断是否有学生数据的情况
	{
		printf("系统中并未保存数据！您可以尝试先在先添加学生数据或从文件中录入数据再进行学生数据的查找。\n");
		return 0;	 
	}
	int find_index;
	printf("1、按学号查找\t\t\t2、按姓名查找\t\t\t3、返回菜单\n"); 
	printf("请选择对应序号:");
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
				printf("您的输入有误请重新输入:"); 
				goto loop_find;
			}
	}
	return 0;
	
}

int stu_revise()
{	
	if(now_index == 0) 		//判断是否有学生数据的情况
	{
		printf("系统中并未保存数据！您可以尝试先在先添加学生数据或从文件中录入数据再进行学生数据的修改。\n");
		return 0;	 
	}
	int if_exit=-1;
	double k;
	int j,m;		//临时储存输入的数字 
	long long revise_id;
	printf("请输入你要修改的学生的学号：");
loop_refind:
	scanf("%lld",&revise_id);
	for(i=0;i<now_index;i++)
	{
		if(revise_id == student[i].stu_id)
		{
				printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
				printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");
				printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
				printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
				if_exit = 1;
				break;
				
		}
		
	
	}
	if(if_exit == -1 )
	{
		printf("未找到该学号，需要继续查找请输入0\n");
		scanf("%d",&m);
		switch(m)
		{
			case 0:
				{
					fflush(stdin);
					printf("请重新输入您要查找的学生的学号：");
					goto loop_refind;
					
				}break;
			
			default:return 0;
		}
		
	}
		printf("请输入你要修改的科目的序号：\n");
		printf("1、高等数学·上\n");
		printf("2、英语视听说\n");
		printf("3、大学计算机基础\n");
		printf("4、软件工程导论\n");;
		printf("5、c语言程序设计\n");
		fflush(stdin);
loop_revise:
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				{
					printf("您想将成绩修改成：");
					scanf("%lf",&k);
					student[i].lesson1 = k;
				}break;
			case 2:
				{
					printf("您想将成绩修改成：");
					scanf("%lf",&k);
					student[i].lesson2 = k;
				}break;
			case 3:
				{
					printf("您想将成绩修改成：");
					scanf("%lf",&k);
					student[i].lesson3 = k;
				}break;
			case 4:
				{
					printf("您想将成绩修改成：");
					scanf("%lf",&k);
					student[i].lesson4 = k;
				}break;
			case 5:
				{
					printf("您想将成绩修改成：");
					scanf("%lf",&k);
					student[i].lesson5 = k;
				}break;
			default:
			{
				fflush(stdin);
				printf("您的输入有误，请重新输入："); 
				goto loop_revise;
			}
		}
		return 0;
}
	


void stu_delete()
{
	
	if(now_index<=0)		//判断无数据的情况 
	{
		printf("系统中没有学生数据，请先录入再进行数据的删除：\n"); 
	}else
	{
				int if_exit=-1;
				double k;
				int j,m;		//临时储存输入的数字 
				long long delete_id;
				printf("请输入你要删除的学生的学号：");
			loop_redelete:
				scanf("%lld",&delete_id);
				for(i=0;i<now_index;i++)
				{
					if(delete_id == student[i].stu_id)
					{
						delete_way(i);
						printf("该学生数据已成功删除！\n");
							if_exit = 1;
							break;
							
					}
					
				
				}
				if(if_exit == -1 )
				{
					printf("未找到该学号，需要继续删除请输入1\n");
					scanf("%d",&m);
					switch(m)
					{
						case 1:
							{
								fflush(stdin);
								printf("请重新输入您要删除的学生的学号：");
								goto loop_redelete;
								
							}break;
						
						default:break; 
					}
					
				}
	} 
}

void stu_subsection()				//数据的分段 
{ 
	if(now_index == 0)		//判断是否有学生数据的情况
	{
		printf("系统中并未保存数据！您可以尝试先在先添加学生数据或从文件中录入数据再进行数据的分段。\n");
		
	} else
		{ 
		sort();
		int stu_s[5]={};				//每个区间人数的临时变量
		printf("按照20分分差对平均成绩进行分段：\n"); 
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
		
		for(i=0;i<now_index;i++)
		{
			if(student[i].avg > 80)
			{
				stu_s[0]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">80且<=100的学生有%d人:\n",stu_s[0]);	
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
	
		for(i=stu_s[0];i<now_index;i++)
		{
			if(student[i].avg <= 80 && student[i].avg>60)
			{
				stu_s[1]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">60且<=80的学生有%d人\n",stu_s[1]);
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
		
		 
		for(i=stu_s[0]+stu_s[1];i<now_index;i++)
		{
			if(student[i].avg <= 60 && student[i].avg>40)
			{
				stu_s[2]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		}
		 printf(">40且<=60的学生有%d人\n",stu_s[2]);
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
		
		for(i=stu_s[0]+stu_s[1]+stu_s[2];i<now_index;i++)
		{
			if(student[i].avg <= 40 && student[i].avg>20)
			{
				stu_s[3]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 
		printf(">20且<=40的学生有%d人\n",stu_s[3]);
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
		
		for(i=stu_s[0]+stu_s[1]+stu_s[2]+stu_s[3];i<now_index;i++)
		{
			if(student[i].avg <= 20 && student[i].avg>0)
			{
				stu_s[4]++;
			
			printf("%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
			}
		} 	
		printf(">0且<=20的学生有%d人\n",stu_s[4]);
		printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
	}	
}

void stu_fileClass()
{
    int file_id;
	printf("1、保存到文件中\n2、文件内容的展示\n3、打开并导入软件\n4、返回主菜单\n");
    printf("请输入你要对文件进行的操作的序号：\n");
   
    loop_file:scanf("%d",&file_id);
    switch(file_id)
    {
        case 1:file_storage();cls();break;
        case 2:file_show();cls();break;
        case 3:file_import();cls();break;
        case 4:cls();break;
        default:{
        			fflush(stdin);
                    printf("您的输入有误，请重新输入：");
                    goto loop_file;
                }
    }
}

int stu_over()
{
	int ifSure; 
	printf("温馨提示：您最好确认数据保已经存在文件中或者不需要此操作。\n");
	printf("如果需要返回到菜单请输入0\n");
	scanf("%d",&ifSure);
	if(ifSure == 0) 
	{	
		return 0;
	} 
	printf("离开的时候请带走我真挚的祝福，感谢有你，再见！\n");
	exit(0);		//结束程序 
	
}

int file_storage()
{
	char *buffer; 
	if((fp =  fopen("Student datas.txt","w"))==NULL)
	{
		printf("打开文件失败！\n");
		exit(0); 
	}
	if(now_index==0)
	{
		printf("注意：您在该管理系统中并未保存数据，无需导入到文本文档中！\n"); 
		return 0; 
	}
	fprintf(fp,"%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");
	for(i=0;i<now_index;i++)
	{
		fprintf(fp,"%-16s%-16lld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
	}
	fprintf(fp,"%-48s%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n","每一门课程的平均成绩：",avg1,avg2,avg3,avg4,avg5,avg0);
	printf("文件存储成功！对应文件储存在：\n");
	
	if((buffer = getcwd(NULL,0))==NULL)
	{
		printf("路径读取失败！\n"); 
	}else
	{
		printf("%s\n",buffer);
		printf("文件名为:Student datas.txt\n"); 
		free(buffer);
	}
	fclose(fp);
	return 0;
}

int file_show()
{
	char file_ch;
	int line =0;
	fp =fopen("Student datas.txt","r");			//只读文件，打开文件 
	int file_index = 0;			//判断当前文件有多少行有效数据 	
	
	for(;;)				//找到共有多少行数据 
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
	if(file_index<=0)							//判断没有数据的情况下 
	{
		printf("注意：文件中没有录入学生数据,请当文件中有数据时再操作!\n"); 
		return 0;					
	}
	
	
	printf("Student datas.txt中的内容是:\n"); 

	char ch;
	while((ch=fgetc(fp)) != EOF)				//一直执行到无字符 
	{
		putchar(ch); 
	}
	fclose(fp);
	return 0;
}

int file_import()
{
	char ch;						//查找'\n' 
	int line = 0;					//找到共有line行数据 
	char temp_total[10][5000];
	if((fp =  fopen("Student datas.txt","r"))==NULL)
	{
		
		printf("打开文件失败！\n");
		exit(0); 
	}
	
	for(;;)				//找到共有多少行数据 
	{
		if((ch = fgetc(fp)) == '\n')
		{
			line++;
		}
		if(ch == EOF)
		break;
	}
		
	rewind(fp);									//将指针重新指向文件的开头 

	
	fscanf(fp,"%[^\n]",temp_total[0]);			//将第一行的标题读取出来存入临时变量中并换行 
	fgetc(fp);

	
	if(line -2<=0)							//判断没有数据的情况下 
	{
		printf("注意：文件中没有录入学生数据,请当文件中有数据时再操作!\n"); 
		return 0;					
	}
	
	now_index = line-2;			//将当前学生人数重新初始化于文件中的数据 
	printf("导入成功!下面是导入后的数据:\n"); 
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
	printf("%-48s%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n","每一门课程的平均成绩：",avg1,avg2,avg3,avg4,avg5,avg0);
	printf("——————————————————————————————————————————————————————————————————————————————————————————\n");


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
    int if_wrong = -1;   //判断是否找到该学号
	int sure;               //判断是否继续查找学号
	long long id; 
loop_con_find_id:	
	printf("请输入你要查找的学号：");
	scanf("%ld",&id);
	for(i=0;i<now_index;i++)
	{
		if(id == student[i].stu_id)
        {	
            printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
           	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");
            printf("%-16s%-16ld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
            printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
            if_wrong = 1;
            break;
            
        }
        
	}
	if(if_wrong == -1)
    {
        printf("未找到该学号，是否要继续查找？\n");
        printf("1、继续查找\t\t2、停止查找\n");
     loop_re_find_id:   
        scanf("%d",&sure);
        switch(sure)
        {
            case 1:goto loop_con_find_id;break;
            case 2:break;
            default:
                {
                    fflush(stdin);
                    printf("您的输入有误，请重新输入：");
                    goto loop_re_find_id;
                }
        }
    }
	
}

void find_name()
{
	int if_wrong = -1;   //判断是否找到该姓名 
	int sure;               //判断是否继续查找姓名
	char name[30]; 
loop_con_find_name:	
	printf("请输入你要查找的姓名：");
	scanf("%s",name);
	for(i=0;i<now_index;i++)
	{
		if(strcmp(name,student[i].names)==0)
        {	
            printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
           	printf("%-16s%-16s%-16s%-25s%-24s%-24s%-22s%-17s%-19s\n","姓名","学号","班级","高等数学·上","英语视听说","大学计算机基础","软件工程导论","c语言程序设计","平均成绩");
            printf("%-16s%-16ld%-16d%-25.2lf%-24.2lf%-24.2lf%-22.2lf%-17.2lf%-19.2lf\n",student[i].names,student[i].stu_id,student[i].stu_class,student[i].lesson1,student[i].lesson2,student[i].lesson3,student[i].lesson4,student[i].lesson5,student[i].avg);
            printf("——————————————————————————————————————————————————————————————————————————————————————————\n");
            if_wrong = 1;
            break;
            
        }
        
	}
	if(if_wrong == -1)
    {
        printf("未找到该姓名，是否要继续查找？\n");
        printf("1、继续查找\t\t2、停止查找\n");
     loop_re_find_name:   
        scanf("%d",&sure);
        switch(sure)
        {
            case 1:goto loop_con_find_name;break;
            case 2:break;
            default:
                {
                    fflush(stdin);
                    printf("您的输入有误，请重新输入：");
                    goto loop_re_find_name;
                }
        }
    }
} 

void delete_way(int t)
{ 
	int h;
	int temp_loop_num = now_index -t -1;
	for(h=0;h<MAX_STU-1;h++)		//从删除处向前补位 
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
    printf("重新选择菜单选项请回车后操作！\n"); 
	scanf("%c",&temp_cls);
	system("cls");
} 

void password_input()
{
	
	int password_input_num = 0; 
	char password_input[30];
	printf("请输入您的密码:\n");
loop_password_input:
	
	
	password_input_num++;
	if(password_input_num > PASSWORD_INPUT_MAX)
	{
		
		printf("您的密码输出超过最大限制次数，退出系统！");
		exit(0); 
	}	
	
	
	scanf("%s",password_input);
	
	if(strcmp(password_real,password_input) != 0)
	{
		
		if(password_input_num != PASSWORD_INPUT_MAX)							//设置密码最大输入次数 
		printf("密码输入错误，请重新输入第%d次：\n",password_input_num+1); 
		fflush(stdin);
		goto loop_password_input;
	}else
	{
		system("cls");
		printf("密码输入正确，欢迎使用！\n");
	}
	
	
}

