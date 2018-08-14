#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

class RPN//reverse polish notation
{
public:
	RPN()//���캯��
	{
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				num[i][j] = '#';
	}
	//~RPN();//��������
	void Change(CString);//��׺���ʽת���ɺ�׺���ʽ
	double Compute(char a[][100]);//��׺���ʽ��ִ��
	int icp(char);//ջ�����ȼ� in coming priority
	int isp(char);//ջ�����ȼ� in stack priority
	char num[100][100];//����沨�����ʽ������
	stack<char>oper;//�����ջ
	CString err;//���Լ��������ʽ�Ƿ�����
};
int RPN::icp(char c)//ջ�����ȼ� in coming priority
{
	switch (c)
	{
	case'#':return 0; break;
	case'+':return 2; break;
	case'-':return 2; break;
	case'*':return 4; break;
	case'/':return 4; break;
	case'(':return 8; break;
	case')':return 1; break;
	default:return -1; break;
	}
}
int RPN::isp(char c)//ջ�����ȼ� in stack priority
{
	switch (c)
	{
	case'#':return 0; break;
	case'+':return 3; break;
	case'-':return 3; break;
	case'*':return 5; break;
	case'/':return 5; break;
	case'(':return 1; break;
	case')':return 8; break;
	default:return -1; break;
	}
}
void RPN::Change(CString str)//��׺���ʽת���ɺ�׺���ʽ
{
	int i = 0,j=0;
	oper.push('#');
	for(int m=0; m < str.GetLength();m++)
	{
		if (str[m] == ')')//��������
		{
			while (oper.top() != '(')
			{
				i++;
				j = 0;
				num[i][j] = oper.top();//����������֮�����������δ����沨��ʽ����
				oper.pop();//���γ�ջ
				if(oper.top()=='#') 
				{
					err="bracket";//�����������
					break;
				}
			}
			if(oper.top!='#') oper.pop();
			continue;
		}
		if ((str[m] >= '0' && str[m] <= '9')||str[m]=='.')//����������С���㣬�����沨������ 
		{
			num[i][j] = str[m];
			j++;
			continue;
		}
		//�������
		if (icp(str[m]) > isp(oper.top()))//����������ȼ�����ջ��Ԫ�أ���ջ
		{
			oper.push(str[m]);
			if (str[m] == '(') i--;
			i++;
			j = 0;
		}
		else//����������ȼ����ڻ���ڵ�ǰջ��Ԫ��
		{
			i++;
			j = 0;
			if(oper.top()=='(') oper.pop();//�����Ų���
			num[i][j] = oper.top();//��ǰջ��Ԫ�ش����沨������
			i++;
			oper.pop();//��ǰջ��Ԫ�س�ջ
			oper.push(str[m]);//����������ջ
		}
	}
	if(str[str.GetLength()-1]<'0'||str[str.GetLength()-1]>'9') 
		if(str[str.GetLength()-1]!=')') err="symbol";//����������������Է����ŵķ��Ž�β

	//����׺��ʾʽ��������
	i++;
	while (!oper.empty())
	{
		num[i][0] = oper.top();//�������ջ��������������δ����沨��ʽ����
		oper.pop();//����ջ��
		i++;
	}
}
double RPN::Compute(char num[][100])//���ñ��ʽ��ִ��
{
	stack<double> number;
	int i = 0, j = 0;
	while (num[i][0] != '#')//�����������ζ������
	{
		string NUM = "0";//������ʾ���µĲ�����
		if((num[i][j] >= '0' && num[i][j] <= '9') || num[i][j] == '.')
		{
			while ((num[i][j] >= '0' && num[i][j] <= '9')||num[i][j]=='.')
			{
				NUM += num[i][j];
				j++;
			}
			number.push(atof(NUM.c_str()));//����ǲ�������ѹ���ջ
		}
		else switch (num[i][0])//��������������ջ����������������
		{
			double temp;//�������������
			case'+':
				temp = number.top();
				number.pop();
				temp += number.top();
				number.pop();
				number.push(temp);
				break;
			case'-':
				temp = number.top();
				number.pop();
				temp = number.top()-temp;
				number.pop();
				number.push(temp);
				break;
			case'*':
				temp = number.top();
				number.pop();
				temp *= number.top();
				number.pop();
				number.push(temp);
				break;
			case'/':
				temp = number.top();
				number.pop();
				temp = number.top()/temp;
				number.pop();
				number.push(temp);
				break;
		}
		i++;
		j = 0;
	}
	return number.top();
}
