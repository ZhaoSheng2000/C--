#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef  struct Student            //�ṹ�庯��
{
	char num[10];     //�༶
	char name[10];     //����
    long long int xh;       //ѧ��
	float eng;        //Ӣ��ɼ�
	float math;       //�����ɼ�
	float   ty;        //�����ɼ�
	float   cyy;         //C���Գɼ�
	float   com;       //������ɼ�
	float ave;      //ƽ���ɼ�
	float sum;       //�ܳɼ�
}stu;
stu p[200];
char filename[20];
void debug()
{
    printf("�����������,����������:");
    getchar();
    fflush(stdin);
}
 void welcome()                     //��ӭ����
{ printf(" ==================ѧ������ϵͳ===================\n");
  printf("|            �汾�ţ�v1.20                        |\n");
  printf("|            �����£�2018.11.06                 |\n");
  printf("|            ���ߣ�king                           |\n");
  printf("|    ������������ԣ�����ʹ������������ϵ����     |\n");
  printf("|        ����:zs15938542780@163.com               |\n");
  printf(" =================================================\n");
}

int menu()
{
		double c;            //�����ǲ˵�ѡ�����
		do{
		printf(" =��ӭʹ��ѧ������ϵͳ= \n");
		printf("|       1* �����Ϣ    |\n");
		printf("|       2* ͳ����Ϣ    |\n");
		printf("|       3* ѧ����ѯ    |\n");
		printf("|       4* �ɼ�����    |\n");
		printf("|       5* �޸���Ϣ    |\n");
		printf("|       6* ɾ����Ϣ    |\n");
		printf("|       0* �˳�ϵͳ    |\n");
		printf(" ====================== \n");
		printf(" ����������0-6ѡ����\n������󽫻�����ѡ��\nΪ���������飬������ȫ��ʹ�ô����\n");
		scanf("%lf",&c);
		fflush(stdin);
	} while(c!=1&&c!=2&&c!=3&&c!=4&&c!=5&&c!=6&&c!=0);
   return (c);
   }
void add()
{
    void debug();
	FILE *fp;             //����һ��ָ���ļ���ָ�����
	int i=0,n=0;
	char input='y';
	system("cls");        //����ϵͳ��������
	while(input!='n'&&input!='N')
	{
		printf("���ѧ���ɼ�(0-100)������ע�⣬�ո��Ժ�����������벻��ȥ�ģ���\n");
		printf("�༶��");
		scanf("%s",p[i].num);
				fflush(stdin);
		printf("������");
		scanf("%s",p[i].name);
		fflush(stdin);
		printf("ѧ�ţ�");
		scanf("%lld",&p[i].xh);
		fflush(stdin);
		printf("Ӣ��ɼ���");
	    eng_0:while(scanf("%f",&p[i].eng)==0)
            debug();
	    if(p[i].eng<0||p[i].eng>100)
        {
            debug();
            goto eng_0;
        }
	    fflush(stdin);
		printf("�����ɼ���");
		math_0:while(scanf("%f",&p[i].math)==0)
		debug();
		if(p[i].math<0||p[i].math>100)
        {
            debug();
            goto math_0;
        }
		fflush(stdin);
		printf("�����ɼ���");
		ty_0:while(scanf("%f",&p[i].ty)==0)
		debug();
		if(p[i].ty<0||p[i].ty>100)
        {
            debug();
            goto ty_0;
        }
		fflush(stdin);
		printf("c���Գɼ���");
		cyy_0:while(scanf("%f",&p[i].cyy)==0)
		debug();
		if(p[i].cyy<0||p[i].cyy>100)
            {
                debug();
                goto cyy_0;
            }
		fflush(stdin);
		printf("������ɼ���");
		com_0:while(scanf("%f",&p[i].com)==0)
		debug();
		if(p[i].com<0||p[i].com>100)
        {
            debug();
            goto com_0;
        }
		fflush(stdin);
		printf("�Ƿ������(Y/N)");
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
        fclose(fp);                                       //�ر��ļ�
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
    printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
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
  printf("1.��ѧ��\n2.������\n3.����\n");
  printf("������:(1/2/3)\n");
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
            printf("������ѧ��(��ѯ�������᷵�����˵�!��:");
            scanf("%lld",&x);
            for(i=0;i<n;i++)
            {
            if(p[i].xh!=x)  m++;
               else {   printf("�༶��%s\n",p[i].num);
                        printf("������%s\n",p[i].name);
                        printf("ѧ�ţ�%lld\n",p[i].xh);
                        printf("Ӣ�%.2f\n",p[i].eng);
                        printf("������%.2f\n",p[i].math);
                        printf("������%.2f\n",p[i].ty);
                        printf("C���ԣ�%.2f\n",p[i].cyy);
                        printf("�������%.2f\n",p[i].com);
                        printf("ƽ���ɼ���%.2f\n",p[i].ave);
                        printf("�ܳɼ���%.2f\n",p[i].sum);
                    }
           system("pause");
            system("cls");
            fclose(fp1);

         return;
            }
        case 2:
            {int j=0;
            char a[10];
            printf("������������");
            scanf("%s",a);
            fflush(stdin);
           while(strcmp(p[j].name,a)!=0&&j<n) j++;
          if(j==n)  {printf("û�д��ˣ�\n");
                        system("pause");
                        system("cls");
                        return;}

                printf("�༶��%s\n",p[j].num);
                printf("������%s\n",p[j].name);
                printf("ѧ�ţ�%lld\n",p[j].xh);
                printf("Ӣ�%.2f\n",p[j].eng);
                printf("������%.2f\n",p[j].math);
                printf("������%.2f\n",p[j].ty);
                printf("C���ԣ�%.2f\n",p[j].cyy);
                printf("�������%.2f\n",p[j].com);
                printf("ƽ����:%.2f\n",p[j].ave);
                printf("ƽ���ɼ���%.2f\n",p[j].ave);
                printf("�ܳɼ���%.2f\n",p[j].sum);
                system("pause");
                system("cls");
            }fclose(fp1);
            break;
        case 3:system("cls");
            return;
        }
    }
}
void sort()//����
{
    int a1=0,a2=0,a3=0,a4=0,a5=0;
    float sum;
     stu pe[200];
     FILE *fp;
     struct Student temp;         //���������ʱ���ݴ潻������
     int i=0,n=0,j;
     double m;
     system("cls");
      do{
        printf("��ѡ��\n1.����\n2.�ֶ�\n");
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
            printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
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

                 printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
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
                }printf("0~100�ֹ���%d��\n",a1);
                {
                printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
                  printf("____________________________________________________________________________________________________________________\n");

                 for(i=0;i<n;i++)
            {
                if(pe[i].sum>100&&pe[i].sum<=200)
                  {
                      a2++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("100~200�ֹ���%d��\n",a2);
                }
               {
                  printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
                  printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                 if(pe[i].sum>200&&pe[i].sum<=300)
                  {
                      a3++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("200~300�ֹ���%d��\n",a3);
              }
              {
              printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
              printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                  if(pe[i].sum>300&&pe[i].sum<=400)
                  {
                      a4++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("300~400�ֹ���%d��\n",a4);
              }
                {
              printf("�༶       ����         ѧ��     Ӣ��ɼ�    ��ѧ�ɼ�     �����ɼ�   c���Գɼ�   ������ɼ�  ƽ���ɼ�   �ܳɼ�\n");
              printf("____________________________________________________________________________________________________________________\n");

                  for(i=0;i<n;i++)
            {
                  if(pe[i].sum>400&&pe[i].sum<=500)
                  {
                      a5++;
	                  printf("%s%12s%12lld%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f%12.2f\n ",pe[i].num,pe[i].name,pe[i].xh,pe[i].eng,pe[i].math,p[i].ty,pe[i].cyy,pe[i].com,pe[i].ave,pe[i].sum);
                      printf("____________________________________________________________________________________________________________________\n");
                  }

            }printf("400~500�ֹ���%d��\n",a5);
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
    printf("1.��ѧ��\n2.������\n3.����\n");
    printf("������:(1/2/3)\n");
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
        printf("������ѧ�ţ�����ѯ�������Զ����أ���");
        scanf("%lld",&x);
        while(p[k].xh!=x&&k<n)    k++;
        if(i==k)     {printf("û�д���\n");
                             return;}
               else {
                    printf("�����������Ϣ\n�༶��\n");
                               scanf("%s",&new1.num);
                        printf("������\n");
                              scanf("%s",&new1.name);
                        printf("ѧ�ţ�\n");
                               scanf("%lld",&new1.xh);
                        printf("Ӣ�\n");
                             eng_9:   while(scanf("%f",&new1.eng)==0)
                             debug();
                             if(new1.eng<0||new1.eng>100)
                             {
                                 debug();
                                 goto eng_9;
                             }
                             fflush(stdin);
                        printf("������\n");
                             math_9:while(scanf("%f",&new1.math)==0)
                             debug();
                             if(new1.math<0||new1.math>100)
                             {
                                 debug();
                                 goto math_9;
                             }
                             fflush(stdin);
                        printf("������\n");
                                ty_9:while(scanf("%f",&new1.ty)==0)
                             debug();
                             if(new1.ty<0||new1.ty>100)
                             {
                                 debug();
                                 goto ty_9;
                             }
                             fflush(stdin);
                        printf("C���ԣ�\n");
                               cyy_9:while(scanf("%f",&new1.cyy)==0)
                             debug();
                             if(new1.cyy<0||new1.cyy>100)
                             {
                                 debug();
                                 goto cyy_9;
                             }
                             fflush(stdin);
                        printf("�������\n");
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
                          printf("�޸ĳɹ���\n");
                            system("pause");
                            system("cls");
                    return;
  }
  }

   if(m==2)
    {

            char a[10];
            stu new2;
            printf("������������");
            scanf("%s",a);
           while(strcmp(p[m1].name,a)!=0&&m1<n) m1++;
          if(m1==n)  {printf("û�д��ˣ�\n");
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
                    printf("�����������Ϣ\n�༶��\n");
                               scanf("%s",&new2.num);
                        printf("������\n");
                              scanf("%s",&new2.name);
                        printf("ѧ�ţ�\n");
                               scanf("%lld",&new2.xh);
                        printf("Ӣ�\n");
                             eng_8:   while(scanf("%f",&new2.eng)==0)
                             debug();
                             if(new2.eng<0||new2.eng>100)
                             {
                                 debug();
                                 goto eng_8;
                             }
                             fflush(stdin);
                        printf("������\n");
                             math_8:while(scanf("%f",&new2.math)==0)
                             debug();
                             if(new2.math<0||new2.math>100)
                             {
                                 debug();
                                 goto math_8;
                             }
                             fflush(stdin);
                        printf("������\n");
                                ty_8:while(scanf("%f",&new2.ty)==0)
                             debug();
                             if(new2.ty<0||new2.ty>100)
                             {
                                 debug();
                                 goto ty_8;
                             }
                             fflush(stdin);
                        printf("C���ԣ�\n");
                               cyy_8:while(scanf("%f",&new2.cyy)==0)
                             debug();
                             if(new2.cyy<0||new2.cyy>100)
                             {
                                 debug();
                                 goto cyy_8;
                             }
                             fflush(stdin);
                        printf("�������\n");
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
                            printf("�޸ĳɹ���\n");
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
        printf("������Ҫɾ����ѧ��������");
        scanf("%s",a);
        while(strcmp(p[j].name,a)!=0&&j<n)
          {
              j++;
          }
        if(j==n)
        {
            printf("û�д��ˣ�\n");
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
            printf("�����ɹ���\n");
            system("pause");
            system("cls");
        }

}
int main()
{
    system("mode con cols=200 lines=50");//���ڴ�С
    system("color 03");      //������ɫ
    welcome();
  for(; ; )          //ѭ���������
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
		    printf("ѧ���ɼ�����\n");
		    find();
		    break;
		case 4:
			printf("ѧ���ɼ�����/�ֶ�\n");
			sort();			break;
		case 5:
			printf("�޸�ѧ���ɼ�\n");
			change();
			break;
		case 6:
			printf("ɾ��ѧ���ɼ�\n");
			del();
			break;
		case 0:
		    welcome();

				char *cnm[16];
    cnm[0]  ="�ڴ������´�ʹ�ã�\n";
	cnm[1]  ="  ����������   ����\n";
	cnm[2]  ="�����ߩ�������--������ ��\n";
	cnm[3]  ="��������������  ��\n";
	cnm[4]  ="��������������   ��\n";
	cnm[5]  ="��������������  ��\n";
	cnm[6]  ="��������������  ��\n";
	cnm[7]  ="��... �� ...    ��\n";
	cnm[8]  ="��������������  ��\n";
	cnm[9]  ="����������������--����    \n";
	cnm[10]  ="    ������������������  \n";
	cnm[11] ="    ����������    \n";
	cnm[12] ="��  ��������������������������������    \n";
	cnm[13] ="����������������������   \n";
	cnm[14] ="�����ǩǩ���    �ǩǩ�      \n";
	cnm[15] ="�������ߩ���    ���ߩ�      \n";
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
