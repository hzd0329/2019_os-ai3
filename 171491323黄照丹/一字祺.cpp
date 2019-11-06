#include<iostream>

using namespace std;

int num=0;        //��¼���������ӵĸ���

int p,q;             

int tmpQP[3][3];  //��ʾ�������ݵ���ʱ���飬���е�Ԫ��0��ʾ�ø�Ϊ�գ�

int cur[3][3];    //�洢��ǰ���̵�״̬

const int depth=3; //��������������

void Init()        //��ʼ������״̬

{

for(int i=0;i<3;i++)

for(int j=0;j<3;j++)

{

cur[i][j]=0;

}

}

void PrintQP()    //��ӡ���̵�ǰ״̬

{

for(int i=0;i<3;i++)

{

for(int j=0;j<3;j++)

cout<<cur[i][j]<<'\t';

cout<<endl;

}

}

void UserInput()//�û�ͨ���˺������������ӵ�λ�ã����磺�û�����31�����ʾ�û��ڵ�3�е�1�����ӡ�

{

int pos,x,y;

L1: cout<<"Please input your qizi (xy): ";

cin>>pos;

x=pos/10,y=pos%10;

if(x>0&&x<4&&y>0&&y<4&&cur[x-1][y-1]==0)

{

cur[x-1][y-1]=-1;

}

else

{

cout<<"Input Error!";

goto L1;

}

}

int CheckWin() //����Ƿ���һ��Ӯ�壨���� 0��û���κ�һ��Ӯ��1�������Ӯ��-1����Ӯ��

{              //�÷���û���ж�ƽ��

for(int i=0;i<3;i++)

{

if(cur[i][0]==1&&cur[i][1]==1&&cur[i][2]==1)

{

return 1;

}

if(cur[i][0]==-1&&cur[i][1]==-1&&cur[i][2]==-1)

{

return -1;

}

}

for(i=0;i<3;i++)

{

if(cur[0][i]==1&&cur[1][i]==1&&cur[2][i]==1)

{

return 1;

}

if(cur[0][i]==-1&&cur[1][i]==-1&&cur[2][i]==-1)

{

return -1;

}

}

if((cur[0][0]==1&&cur[1][1]==1&&cur[2][2]==1)||(cur[2][0]==1&&cur[1][1]==1&&cur[0][2]==1))

{

return 1;

}

if((cur[0][0]==-1&&cur[1][1]==-1&&cur[2][2]==-1)||(cur[2][0]==-1&&cur[1][1]==-1&&cur[0][2]==-1))

{

return -1;

}

return 0;

}

int value()//������ǰ����״̬��ֵ��ͬʱ������p��q�ж��Ƿ�ƽ�֣�

{

p=0;

q=0;

for(int i=0;i<3;i++)      //�����һ��

{                          //�������еĿո������Լ������ӣ��Ƚ����������е�0��Ϊ1

for(int j=0;j<3;j++)

{

if(cur[i][j]==0)

{

tmpQP[i][j]=1;

}

else

{

tmpQP[i][j]=cur[i][j];

}

}

}

for(i=0;i<3;i++)          //���㹲�ж�������3��1����

{

p+=(tmpQP[i][0]+tmpQP[i][1]+tmpQP[i][2])/3;

}

for(i=0;i<3;i++)          //���㹲�ж�������3��1����

{

p+=(tmpQP[0][i]+tmpQP[1][i]+tmpQP[2][i])/3;

}

p+=(tmpQP[0][0]+tmpQP[1][1]+tmpQP[2][2])/3;//���㹲�ж�������3��1�ĶԽ���

p+=(tmpQP[2][0]+tmpQP[1][1]+tmpQP[0][2])/3;

for(i=0;i<3;i++)          //��һ��

{                        //�������еĿո������Լ������ӣ��Ƚ����������е�0��Ϊ-1

for(int j=0;j<3;j++)

{

if(cur[i][j]==0)

{

tmpQP[i][j]=-1;

}

else

{

tmpQP[i][j]=cur[i][j];

}

}

}

for(i=0;i<3;i++)          //���㹲�ж�������3��-1����

{

q+=(tmpQP[i][0]+tmpQP[i][1]+tmpQP[i][2])/3;

}

for(i=0;i<3;i++)          //���㹲�ж�������3��1����

{

q+=(tmpQP[0][i]+tmpQP[1][i]+tmpQP[2][i])/3;

}

q+=(tmpQP[0][0]+tmpQP[1][1]+tmpQP[2][2])/3;//���㹲�ж�������3��1�ĶԽ���

q+=(tmpQP[2][0]+tmpQP[1][1]+tmpQP[0][2])/3;

return p+q;                //����������������״̬��ֵ

}

int cut(int &val,int dep,bool max)//���㷨���֣�ʵ��a-B��֦���㷨��valΪ��һ��Ĺ���ֵ��depΪ������ȣ�max��¼��һ���Ƿ�Ϊ�����

{

if(dep==depth||dep+num==9)    //���������ȴﵽ�����ȣ�������ȼ��ϵ�ǰ�������Ѿ��ﵽ9����ֱ�ӵ��ù��ƺ���

{

return value();

}

int i,j,flag,temp;            //flag��¼����ļ�ֵ��temp��¼�²���õĹ���ֵ

bool out=false;              //out��¼�Ƿ��֦����ʼΪfalse

/*if(CheckWin()==1)          //��������Ӯ�ˣ�������һ��Ĺ���ֵΪ����úܴ��ֵ�������

{

val=10000;

return 0;

}*/

if(max)  //�����һ���Ǽ���㣬��������Ҫ�Ǽ�С�㣬��¼flagΪ����󣻷�֮����Ϊ��¼Ϊ�������

{

flag=10000;                //flag��¼����ڵ�ļ�ֵ

}

else

{

flag=-10000;

}

for(i=0;i<3 && !out;i++)      //˫��ѭ����������������λ��

{

for(j=0;j<3 && !out;j++)

{

if(cur[i][j]==0)            //�����λ����û������

{

if(max)                //������һ��Ϊ����㣬������Ϊ��С��,�ֵ��û�������ˡ�

{

cur[i][j]=-1;      //��λ�������û��������

if(CheckWin()==-1)  //����û����Ӯ��

{

temp=-10000;    //�����̹���ֵΪ������

}

else

{

temp=cut(flag,dep+1,!max); //�����������a-B��֦����

}

if(temp<flag)      //�����һ�����̵Ĺ���ֵС�ڱ���ڵ�ļ�ֵ�����ñ��㼫ֵΪ��С��

{

flag=temp;

}

if(flag<=val)      //������㼫ֵ��С����һ��Ĺ���ֵ������������ȥ����֦

{

out=true;

}

}

else                    //�����һ��Ϊ��С�㣬������Ϊ�����,�ֵ���������ˡ�

{

cur[i][j]=1;        //��λ�����ϼ��������

if(CheckWin()==1)  //��������Ӯ��

{

temp=10000;    //�����̹���ֵΪ����

}

else

{

temp=cut(flag,dep+1,!max);//�����������a-B��֦����

}

if(temp>flag)

{

flag=temp;

}

if(flag>=val)

{

out=true;

}

}

cur[i][j]=0;  //��ģ���µ�һ���廹ԭ������

}

}

}

if(max)      //������һ���Ƿ�Ϊ����㣬�ñ���ļ�ֵ�޸���һ��Ĺ���ֵ

{

if(flag>val)

{

val=flag;

}

}

else

{

if(flag<val)

{

val=flag;

}

}

return flag;  //�������ص��Ǳ���ļ�ֵ

}

int main()//������

{

int m=-10000,val=-10000,dep=1;  //m�����������val

int x_pos,y_pos;                //��¼����߲�������

Init();

cout<<"Qipan: "<<endl;

PrintQP();

char IsFirst;

cout<<"Do you want do first?(y/n)";

cin>>IsFirst;

while(IsFirst!='y'&&IsFirst!='n')

{

cout<<"ERROR!"<<"Do you want do first?(y/n)";

cin>>IsFirst;

}

if(IsFirst=='n')//---------------------------------���������--------------------------------------

{

L5:        for(int x=0;x<3;x++)

{

for(int y=0;y<3;y++)

{

if(cur[x][y]==0)

{

cur[x][y]=1;

cut(val,dep,1);//�������̽����һ���壬����״̬�ı��ˣ��ڸ�״̬�¼�������Ϊdep-1������״̬����ֵval

if(CheckWin()==1)

{

cout<<"The computer put the qizi at:"<<x+1<<y+1<<endl;

PrintQP();

cout<<"The computer WIN! GAME OVER."<<endl;

return 0;

}

if(val>m)      //mҪ��¼ͨ����̽��õ�����״̬��������ֵ

{

m=val;

x_pos=x;y_pos=y;

}

val=-10000;

cur[x][y]=0;

}

}

}
cur[x_pos][y_pos]=1;

val=-10000;

m=-10000;

dep=1;

cout<<"The computer put the qizi at:"<<x_pos+1<<y_pos+1<<endl;
PrintQP();

cout<<endl;

num++;

value();

if(p==0)

{

cout<<"DOWN GAME!"<<endl;

return 0;

}

UserInput();          //�����һ����

PrintQP();     

cout<<endl;

num++;

value();

if(p==0)

{

cout<<"DOWN GAME!"<<endl;

return 0;

}
if(CheckWin()==-1)

{

cout<<"Conguatulations! You Win! GAME OVER."<<endl;

return 0;

}

goto L5;

}

else //--------------------------------������-----------------------------------

{
L4:        UserInput();                               

PrintQP();

cout<<endl;

num++;

value();

if(q==0)

{

cout<<"DOWN GAME!"<<endl;

return 0;

}

if (CheckWin()==-1)

{

cout<<"You Win! GAME OVER."<<endl;

return 0;

}

for(int x=0;x<3;x++)

{

for(int y=0;y<3;y++)

{

if(cur[x][y]==0)

{
cur[x][y]=1;

cut(val,dep,1);

if(CheckWin()==1)

{

cout<<"The computer put the qizi at:"<<x+1<<y+1<<endl;

PrintQP();

cout<<"The computer WIN! GAME OVER."<<endl;

return 0;

}

if(val>m)

{

m=val;

x_pos=x;y_pos=y;
}
val=-10000;

cur[x][y]=0;

}

}

}

cur[x_pos][y_pos]=1;

val=-10000;

m=-10000;

dep=1;

cout<<"The computer put the qizi at:"<<x_pos+1<<y_pos+1<<endl;

PrintQP();

cout<<endl;

num++;

value();

if(q==0)

{

cout<<"DOWN GAME!"<<endl;

return 0;

}

goto L4;

}

return 0;

}
