//��Ŀ��ѧ���ɼ�����ϵͳ 
//  �༶����184 
//  �����������
//  ѧ�ţ�1813021104 
#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;
int count1=0;//��¼ѧ������ 
struct stu{
	string num;
	string name;
	double math;
	double chinese;
	double english;
	double all;
} a[1001];
void Input(string num,string name,double chinese,double math,double english,double all){
	a[count1].num=num;
	a[count1].name=name; 
	a[count1].math=math;
	a[count1].chinese=chinese;
	a[count1].english=english;
	a[count1].all=all;
	count1++;
} 
int ReadFile(){
	int n=0;
	ifstream file;
	string num;
	string name;
	double math;
	double chinese;
	double english;
	double all;
	file.open("./stud.txt",ios::in);
	while(file.good())
	{
		file>>num;
		file>>name;
		file>>chinese;
		file>>math;
		file>>english;
		file>>all;
		if(file.fail())
			break; 
		Input(num,name,math,chinese,english,all);
		n++;
	}
	return n;
}
bool cmp(stu a,stu b){
	return a.all>b.all;
}
int main(){
	string num;
	string name;
	double math;
	double chinese;
	double english;
	double all;
	int n,i;
	cout<<"��ȡ�ļ���"<<endl;
	int tt=ReadFile(); 
	cout<<"��ȡ"<<tt<<"��"<<endl; 
	cout<<"��������ѧ����Ŀ��"<<endl;
	cin>>n; 
	if(n!=0)
	cout<<"����ѧ����Ϣ��ѧ�š�����������Ӣ"<<endl;
	for(i=0;i<n;i++){
		cin>>num>>name;
		cin>>chinese>>math>>english;
		all=math+chinese+english;
		Input(num,name,math,chinese,english,all);
	}
	//cout<<count1<<endl;
	// �������ļ�
	ofstream allf;
	allf.open("stud.txt");
	for(i=0;i<count1;i++){
		allf<<a[i].num<<' '<<a[i].name<<' '<<a[i].chinese<<' '<<a[i].math<<' '<<a[i].english<<' '<<a[i].all<<endl;
	}
	//���������ļ� 
	ofstream sortf;
	sortf.open("stud_sort.txt");
	sort(a,a+count1,cmp);
	for(i=0;i<count1;i++){
		sortf<<a[i].num<<' '<<a[i].name<<' '<<a[i].chinese<<' '<<a[i].math<<' '<<a[i].english<<' '<<a[i].all<<endl;
	}
	//�����������ܷ� 
	ofstream sumf;
	sumf.open("stud_sum.dat");
	for(i=0;i<count1;i++){
		sumf<<a[i].name<<' '<<a[i].all<<endl;
	}
	//���������� 
	ofstream unpf;
	unpf.open("unpassed.dat");
	for(i=0;i<count1;i++){
		int flag=0;
		if(a[i].chinese<60){
			flag++;
		}
		if(a[i].english<60){
			flag++;
		}
		if(a[i].math<60){
			flag++;
		}
		if(flag>=2){
			a[i].num="0";
			unpf<<a[i].num<<' '<<a[i].name<<' '<<a[i].chinese<<' '<<a[i].math<<' '<<a[i].english<<' '<<a[i].all<<endl;
		}
	}
	//��ѧ�Ų�ѯ 
	int flag=0;
	cout<<"����ѧ�Ų�ѯ��"<<endl;
	string id;
	cin>>id;
	for(i=0;i<count1;i++){
		if(a[i].num==id){
			flag=1;
			cout<<a[i].num<<' '<<a[i].name<<' '<<a[i].chinese<<' '<<a[i].math<<' '<<a[i].english<<' '<<a[i].all<<endl;
		} 
	}
	if(flag!=1){
		cout<<"��ѯʧ�ܣ�"<<endl; 
	}
	return 0;
}
/*
123 jack 1 2 3
234 mark 3 2 1
432 tony 4 2 1
341 rose 5 4 2
543 tom 5 6 7
*/
