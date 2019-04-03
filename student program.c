#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef  struct Student            //结构体函数
{
	char num[10];     //班级
	char name[10];     //姓名
    long long int xh;       //学号
	float eng;        //英语成绩
	float math;       //高数成绩
	float   ty;        //体育成绩
	float   cyy;         //C语言成绩
	float   com;       //计算机成绩
	float ave;      //平均成绩
	float sum;       //总成绩
}stu;
stu p[200];
char filename[20];
void debug()
{
    printf("您输入的有误,请重新输入:");
    getchar();
    fflush(stdin);
}
 void welcome()                     //欢迎界面
{ printf(" ==================学生管理系统===================\n");
  printf("|            版本号：v1.20                        |\n");
  printf("|            最后更新：2018.11.06                 |\n");
  printf("|            作者：king                           |\n");
  printf("|    本软件仅供测试，如需使用完整版请联系作者     |\n");
  printf("|        邮箱:zs15938542780@163.com               |\n");
  printf(" =================================================\n");
}

int menu()
{
		double c;            //以下是菜单选择界面
		do{
		printf(" =欢迎使用学生管理系统= \n");
		printf("|       1* 添加信息    |\n");
		printf("|       2* 统计信息    |\n");
		printf("|       3* 学生查询    |\n");
		printf("|       4* 成绩排名    |\n");
		printf("|       5* 修改信息    |\n");
		printf("|       6* 删除信息    |\n");
		printf("|       0* 退出系统    |\n");
		printf(" ====================== \n");
		printf(" 请输入数字0-6选择功能\n输入错误将会重新选择\n为了您的体验，建议您全屏使用此软件\n");
		scanf("%lf",&c);
		fflush(stdin);
	} while(c!=1&&c!=2&&c!=3&&c!=4&&c!=5&&c!=6&&c!=0);
   return (c);
   }
void add()
{
    void debug();
	FILE *fp;             //定义一个指向文件的指针变量
	int i=0,n=0;
	char input='y';
	system("cls");        //调用系统清屏函数
	while(input!='n'&&input!='N')
	{
		printf("添加学生成绩(0-100)：（请注意，空格以后的数据是输入不进去的！）\n");
		printf("班级：");
		scanf("%s",p[i].num);
				fflush(stdin);
		printf("姓名：");
		scanf("%s",p[i].name);
		fflush(stdin);
		printf("学号：");
		scanf("%lld",&p[i].xh);
		fflush(stdin);
		printf("英语成绩：");
	    eng_0:while(scanf("%f",&p[i].eng)==0)
            debug();
	    if(p[i].eng<0||p[i].eng>100)
        {
            debug();
            goto eng_0;
        }
	    fflush(stdin);
		printf("高数成绩：");
		math_0:while(scanf("%f",&p[i].math)==0)
		debug();
		if(p[i].math<0||p[i].math>100)
        {
            debug();
            goto math_0;
        }
		fflush(stdin);
		printf("体育成绩：");
		ty_0:while(scanf("%f",&p[i].ty)==0)
		debug();
		if(p[i].ty<0||p[i].ty>100)
        {
            debug();
            goto ty_0;
        }
		fflush(stdin);
		printf("c语言成绩：");
		cyy_0:while(scanf("%f",&p[i].cyy)==0)
		debug();
		if(p[i].cyy<0||p[i].cyy>100)
            {
                debug();
                goto cyy_0;
            }
		fflush(stdin);
		printf("计算机成绩：");
		com_0:while(scanf("%f",&p[i].com)==0)
		debug();
		if(p[i].com<0||p[i].com>100)
        {
            debug();
            goto com_0;
        }
		fflush(stdin);
		printf("是否继续？(Y/N)");
		scanf("%c",&input);
		fflush(stdin);
		p[i].ave=(p[i].eng+p[i].math+p[i].ty+p[i].cyy+p[i].com)/5;
        p[i].sum=p[i].com+p[i].cyy+p[i].eng+p[i].math+p[i].ty;
		i++;
		n++;
		system("cls");
	}
	if((fp=fopen("student.txt","a"))==NULL)
	      {
	         printf("can not open the files\n");
	         return;
       }
       for(i=0;i<n;i++)
        {
            fprintf(fp,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",p[i].num,p[i].name,p[i].xh,p[i].eng,p[i].math,p[i].ty,p[i].cyy,p[i].com,p[i].ave,p[i].sum);
        }
        fclose(fp);                                       //关闭文件
  }
void scan()
{
	FILE *fp;
		system("cls");
		if((fp=fopen("student.txt","r"))==NULL)
      {
         printf("cannot open the files\n");
         return;
       }
    int i=0;
    printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
	while(fscanf(fp,"%s%s%lld%f%f%f%f%f%f%f",p[i].num,p[i].name,&p[i].xh,&p[i].eng,&p[i].math,&p[i].ty,&p[i].cyy,&p[i].com,&p[i].ave,&p[i].sum)!=EOF)
	{
    printf("___________________________________________________________________________________________________________________________\n");
	printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",p[i].num,p[i].name,p[i].xh,p[i].eng,p[i].math,p[i].ty,p[i].cyy,p[i].com,p[i].ave,p[i].sum);
	i++;
    }system("pause");
    system("cls");
}
void find()
{

    void debug();
    system("cls");
  stu p[200];
  FILE *fp1;
  int m,n,i=0;
  printf("1.按学号\n2.按姓名\n3.返回\n");
  printf("请输入:(1/2/3)\n");
  f_0:scanf("%d",&m);
  fflush(stdin);
  while(m!=1&&m!=2&&m!=3)
  {
     debug();
     goto f_0;
     fflush(stdin);
  }
  if((fp1=fopen("student.txt","r"))==NULL)
  {
      printf("can't open the file\n");
      return;
  }
        while(fscanf(fp1,"%s%s%lld%f%f%f%f%f%f%f",p[i].num,p[i].name,&p[i].xh,&p[i].eng,&p[i].math,&p[i].ty,&p[i].cyy,&p[i].com,&p[i].ave,&p[i].sum)!=EOF)
            {
                i++;
                n++;
            }
    switch  (m)
        {
        case 1:
            {
            int m=0;
            long long int x;
            printf("请输入学号(查询不到将会返回主菜单!）:");
            scanf("%lld",&x);
            for(i=0;i<n;i++)
            {
            if(p[i].xh!=x)  m++;
               else {   printf("班级：%s\n",p[i].num);
                        printf("姓名：%s\n",p[i].name);
                        printf("学号：%lld\n",p[i].xh);
                        printf("英语：%.2f\n",p[i].eng);
                        printf("高数：%.2f\n",p[i].math);
                        printf("体育：%.2f\n",p[i].ty);
                        printf("C语言：%.2f\n",p[i].cyy);
                        printf("计算机：%.2f\n",p[i].com);
                        printf("平均成绩：%.2f\n",p[i].ave);
                        printf("总成绩：%.2f\n",p[i].sum);
                    }
           system("pause");
            system("cls");
            fclose(fp1);

         return;
            }
        case 2:
            {int j=0;
            char a[10];
            printf("请输入姓名：");
            scanf("%s",a);
            fflush(stdin);
           while(strcmp(p[j].name,a)!=0&&j<n) j++;
          if(j==n)  {printf("没有此人！\n");
                        system("pause");
                        system("cls");
                        return;}

                printf("班级：%s\n",p[j].num);
                printf("姓名：%s\n",p[j].name);
                printf("学号：%lld\n",p[j].xh);
                printf("英语：%.2f\n",p[j].eng);
                printf("高数：%.2f\n",p[j].math);
                printf("体育：%.2f\n",p[j].ty);
                printf("C语言：%.2f\n",p[j].cyy);
                printf("计算机：%.2f\n",p[j].com);
                printf("平均分:%.2f\n",p[j].ave);
                printf("平均成绩：%.2f\n",p[j].ave);
                printf("总成绩：%.2f\n",p[j].sum);
                system("pause");
                system("cls");
            }fclose(fp1);
            break;
        case 3:system("cls");
            return;
        }
    }
}
void sort()//排序
{
    int a1=0,a2=0,a3=0,a4=0,a5=0;
    float sum;
     stu pe[200];
     FILE *fp;
     struct Student temp;         //用于排序的时候暂存交换数据
     int i=0,n=0,j;
     double m;
     system("cls");
      do{
        printf("请选择：\n1.排序\n2.分段\n");
        scanf("%lf",&m);
        fflush(stdin);
        }while(m!=1&&m!=2);
    if((fp=fopen("student.txt","r"))==NULL)
      {
         printf("can not open the files\n");
         system("cls");
         return;
      }


    while(fscanf(fp,"%s%s%lld%f%f%f%f%f%f%f",pe[i].num,pe[i].name,&pe[i].xh,&pe[i].eng,&pe[i].math,&pe[i].ty,&pe[i].cyy,&pe[i].com,&pe[i].ave,&pe[i].sum)!=EOF)
            {
                i++;
                n++;
            }
         if(m==1)
         {
         {
             for(j=0;j<n-1;j++)
                for(i=0;i<n-1-j;i++)
                    if(pe[i].ave<pe[i+1].ave)
                {temp=pe[i];pe[i]=pe[i+1];pe[i+1]=temp;}
         }
            printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
                 for(i=0;i<n;i++)
            {
            printf("_________________________________________________________________________________________________________________________\n");
	        printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,pe[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
            }
            system("pause");
            system("cls");
             fclose(fp);
             return;
         }
          if(m==2)
                {

                 printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
                  printf("____________________________________________________________________________________________________________________\n");
              for(i=0;i<n;i++)
            {
                  if(pe[i].sum<=100)
                  {
                      a1++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,pe[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }
                }printf("0~100分共有%d人\n",a1);
                {
                printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
                  printf("____________________________________________________________________________________________________________________\n");

                 for(i=0;i<n;i++)
            {
                if(pe[i].sum>100&&pe[i].sum<=200)
                  {
                      a2++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("100~200分共有%d人\n",a2);
                }
               {
                  printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
                  printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                 if(pe[i].sum>200&&pe[i].sum<=300)
                  {
                      a3++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("200~300分共有%d人\n",a3);
              }
              {
              printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
              printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                  if(pe[i].sum>300&&pe[i].sum<=400)
                  {
                      a4++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("300~400分共有%d人\n",a4);
              }
                {
              printf("班级       姓名         学号     英语成绩    数学成绩     体育成绩   c语言成绩   计算机成绩  平均成绩   总成绩\n");
              printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                  if(pe[i].sum>400&&pe[i].sum<=500)
                  {
                      a5++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("400~500分共有%d人\n",a5);
                }

              system("pause");
              system("cls");
           return;
         }
void change()
{
    void debug();
    stu p[200];
    FILE *fp;
    int m,i=0,n=0,m1=0,m2=0;
    printf("1.按学号\n2.按姓名\n3.返回\n");
    printf("请输入:(1/2/3)\n");
 f_x:scanf("%d",&m);
  fflush(stdin);
  while(m!=1&&m!=2&&m!=3)
  {
     debug();
     goto f_x;
     fflush(stdin);
     return;
  }
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("can not open the file\n");
        system("pause");
        system("cls");
        return;
    }
        while(fscanf(fp,"%s%s%lld%f%f%f%f%f%f%f",p[i].num,p[i].name,&p[i].xh,&p[i].eng,&p[i].math,&p[i].ty,&p[i].cyy,&p[i].com,&p[i].ave,&p[i].sum)!=EOF)
        {
            i++;
            n++;
        }
        fclose(fp);


  if(m==1)
  {
      stu new1;
      long long int x;
      int k=0;
        printf("请输入学号：（查询不到将自动返回！）");
        scanf("%lld",&x);
        while(p[k].xh!=x&&k<n)    k++;
        if(i==k)     {printf("没有此人\n");
                             return;}
               else {
                    printf("请输入更改信息\n班级：\n");
                               scanf("%s",&new1.num);
                        printf("姓名：\n");
                              scanf("%s",&new1.name);
                        printf("学号：\n");
                               scanf("%lld",&new1.xh);
                        printf("英语：\n");
                             eng_9:   while(scanf("%f",&new1.eng)==0)
                             debug();
                             if(new1.eng<0||new1.eng>100)
                             {
                                 debug();
                                 goto eng_9;
                             }
                             fflush(stdin);
                        printf("高数：\n");
                             math_9:while(scanf("%f",&new1.math)==0)
                             debug();
                             if(new1.math<0||new1.math>100)
                             {
                                 debug();
                                 goto math_9;
                             }
                             fflush(stdin);
                        printf("体育：\n");
                                ty_9:while(scanf("%f",&new1.ty)==0)
                             debug();
                             if(new1.ty<0||new1.ty>100)
                             {
                                 debug();
                                 goto ty_9;
                             }
                             fflush(stdin);
                        printf("C语言：\n");
                               cyy_9:while(scanf("%f",&new1.cyy)==0)
                             debug();
                             if(new1.cyy<0||new1.cyy>100)
                             {
                                 debug();
                                 goto cyy_9;
                             }
                             fflush(stdin);
                        printf("计算机：\n");
                               com_9:   while(scanf("%f",&new1.com)==0)
                             debug();
                             if(new1.com<0||new1.com>100)
                             {
                                 debug();
                                 goto com_9;
                             }
                             fflush(stdin);
                            new1.ave=(new1.eng+new1.math+new1.ty+new1.cyy+new1.com)/5.0;
                            new1.sum=new1.eng+new1.math+new1.ty+new1.cyy+new1.com;
                        FILE *fp3;
                        fp3=fopen("student.txt","r+");


                    if(x!=p[m1].xh&&m1<n)
                       {
                            fprintf(fp3,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",p[m1].num,p[m1].name,p[m1].xh,p[m1].eng,p[m1].math,p[m1].ty,p[m1].cyy,p[m1].com,p[m1].ave,p[m1].sum);
                            m1++;
                       }
                     fprintf(fp3,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",new1.num,new1.name,new1.xh,new1.eng,new1.math,new1.ty,new1.cyy,new1.com,new1.ave,new1.sum);

                         fclose(fp3);
                          printf("修改成功！\n");
                            system("pause");
                            system("cls");
                    return;
  }
  }

   if(m==2)
    {

            char a[10];
            stu new2;
            printf("请输入姓名：");
            scanf("%s",a);
           while(strcmp(p[m1].name,a)!=0&&m1<n) m1++;
          if(m1==n)  {printf("没有此人！\n");
                      return;}
              else
                {
                    FILE *fp5;
              fp5=fopen("student.txt","w");
              if(fp5==NULL)
              {
                  printf("can not open the file!\n");
                  exit(0);
              }
                    printf("请输入更改信息\n班级：\n");
                               scanf("%s",&new2.num);
                        printf("姓名：\n");
                              scanf("%s",&new2.name);
                        printf("学号：\n");
                               scanf("%lld",&new2.xh);
                        printf("英语：\n");
                             eng_8:   while(scanf("%f",&new2.eng)==0)
                             debug();
                             if(new2.eng<0||new2.eng>100)
                             {
                                 debug();
                                 goto eng_8;
                             }
                             fflush(stdin);
                        printf("高数：\n");
                             math_8:while(scanf("%f",&new2.math)==0)
                             debug();
                             if(new2.math<0||new2.math>100)
                             {
                                 debug();
                                 goto math_8;
                             }
                             fflush(stdin);
                        printf("体育：\n");
                                ty_8:while(scanf("%f",&new2.ty)==0)
                             debug();
                             if(new2.ty<0||new2.ty>100)
                             {
                                 debug();
                                 goto ty_8;
                             }
                             fflush(stdin);
                        printf("C语言：\n");
                               cyy_8:while(scanf("%f",&new2.cyy)==0)
                             debug();
                             if(new2.cyy<0||new2.cyy>100)
                             {
                                 debug();
                                 goto cyy_8;
                             }
                             fflush(stdin);
                        printf("计算机：\n");
                               com_8:   while(scanf("%f",&new2.com)==0)
                             debug();
                             if(new2.com<0||new2.com>100)
                             {
                                 debug();
                                 goto com_8;
                             }
                             fflush(stdin);
                new2.ave=(new2.eng+new2.math+new2.ty+new2.cyy+new2.com)/5.0;
                new2.sum=new2.eng+new2.math+new2.ty+new2.cyy+new2.com;
                FILE *fp6;
                fp6=fopen("student.txt","r+");
                       if(strcmp(p[m2].name,a)!=0&&m2<n)
                        {
                            fprintf(fp6,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",p[m2].num,p[m2].name,p[m2].xh,p[m2].eng,p[m2].math,p[m2].ty,p[m2].cyy,p[m2].com,p[m2].ave,p[m2].sum);
                            m2++;
                        }
                            fprintf(fp6,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",new2.num,new2.name,new2.xh,new2.eng,new2.math,new2.ty,new2.cyy,new2.com,new2.ave,new2.sum);
                            fclose(fp6);
                            printf("修改成功！\n");
                            system("pause");
                            system("cls");
                            return;
                    }
                }
}
void del()
{
    stu p[200];
    FILE *fp;
    char a[10];
    int i=0,j=0,n=0;
    if(((fp=fopen("student.txt","r"))==NULL))
    {
        printf("can not open the file\n");
        system("pause");
        return;
    }
        while(fscanf(fp,"%s%s%lld%f%f%f%f%f%f%f",p[i].num,p[i].name,&p[i].xh,&p[i].eng,&p[i].math,&p[i].ty,&p[i].cyy,&p[i].com,&p[i].ave,&p[i].sum)!=EOF)
        {
            i++;
            n++;
        }
        fclose(fp);
        printf("请输入要删除的学生姓名：");
        scanf("%s",a);
        while(strcmp(p[j].name,a)!=0&&j<n)
          {
              j++;
          }
        if(j==n)
        {
            printf("没有此人！\n");
            system("pause");
            system("cls");
            return;
        }
        else
        {
            FILE *fp1;
            fp1=fopen("student.txt","w");
            if(fp1==NULL)
                    {
                        printf("can not open the file\n");
                        exit(0);
                    }
                int m=0;
                while(m<n)
                {
               if (strcmp(p[m].name,a)!=0)
               {
                   fprintf(fp1,"%s	%s	%lld	%f	%f	%f	%f	%f	%f	%f\n",p[m].num,p[m].name,p[m].xh,p[m].eng,p[m].math,p[m].math,p[m].ty,p[m].cyy,p[m].com,p[m].ave,p[m].sum);
               }
                  m++;
               }
            fclose(fp1);
            printf("操作成功！\n");
            system("pause");
            system("cls");
        }

}
int main()
{
    system("mode con cols=200 lines=50");//窗口大小
    system("color 03");      //窗口颜色
    welcome();
  for(; ; )          //循环输出界面
	{
		switch (menu())
		{
		case 1:
			add();
			break;
		case 2:
			scan();
			break;
		case 3:
		    printf("学生成绩查找\n");
		    find();
		    break;
		case 4:
			printf("学生成绩排序/分段\n");
			sort();			break;
		case 5:
			printf("修改学生成绩\n");
			change();
			break;
		case 6:
			printf("删除学生成绩\n");
			del();
			break;
		case 0:
		    welcome();

				char *cnm[16];
    cnm[0]  ="期待您的下次使用！\n";
	cnm[1]  ="  ┏┓　　　   ┏┓\n";
	cnm[2]  ="┏┛┻━━——--━┛┻ ┓\n";
	cnm[3]  ="┃　　　　　　  ┃\n";
	cnm[4]  ="┃　　　━　　   ┃\n";
	cnm[5]  ="┃　＞　　＜　  ┃\n";
	cnm[6]  ="┃　　　　　　  ┃\n";
	cnm[7]  ="┃... ⌒ ...    ┃\n";
	cnm[8]  ="┃　　　　　　  ┃\n";
	cnm[9]  ="┗━—┓　　　┏--━┛    \n";
	cnm[10]  ="    ┃　　　┃　　　　  \n";
	cnm[11] ="    ┃　　　┃    \n";
	cnm[12] ="　  ┃　　　┃　　　　　　　　　　　    \n";
	cnm[13] ="　　┃　　　┗━━━┓   \n";
	cnm[14] ="　　┣┣┃　    ┣┣┃      \n";
	cnm[15] ="　　┗┻┛　    ┗┻┛      \n";
	int i=0,j=0,t=0;

	while(t<10)
	{
		system("cls");
		i=0;
		while(i<16)
		{
			j=0;
			while(j<t)
			{
				printf("  ");
				j++;
			}
			printf("%s",cnm[i]);
			i++;
		}
		Sleep(200);
		t++;
	}
	 getchar();
     exit(0);
	    }
      }


	return 0;
}
