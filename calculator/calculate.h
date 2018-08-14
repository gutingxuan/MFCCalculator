#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

class RPN//reverse polish notation
{
public:
	RPN()//构造函数
	{
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				num[i][j] = '#';
	}
	//~RPN();//析构函数
	void Change(CString);//中缀表达式转换成后缀表达式
	double Compute(char a[][100]);//后缀表达式的执行
	int icp(char);//栈外优先级 in coming priority
	int isp(char);//栈内优先级 in stack priority
	char num[100][100];//存放逆波兰表达式的数组
	stack<char>oper;//运算符栈
	CString err;//用以检查输入算式是否有误
};
int RPN::icp(char c)//栈外优先级 in coming priority
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
int RPN::isp(char c)//栈内优先级 in stack priority
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
void RPN::Change(CString str)//中缀表达式转换成后缀表达式
{
	int i = 0,j=0;
	oper.push('#');
	for(int m=0; m < str.GetLength();m++)
	{
		if (str[m] == ')')//遇右括号
		{
			while (oper.top() != '(')
			{
				i++;
				j = 0;
				num[i][j] = oper.top();//将左右括号之间的运算符依次存入逆波兰式数组
				oper.pop();//依次出栈
				if(oper.top()=='#') 
				{
					err="bracket";//括号输入错误
					break;
				}
			}
			if(oper.top!='#') oper.pop();
			continue;
		}
		if ((str[m] >= '0' && str[m] <= '9')||str[m]=='.')//遇操作数或小数点，存入逆波兰数组 
		{
			num[i][j] = str[m];
			j++;
			continue;
		}
		//遇运算符
		if (icp(str[m]) > isp(oper.top()))//读入符号优先级高于栈顶元素，进栈
		{
			oper.push(str[m]);
			if (str[m] == '(') i--;
			i++;
			j = 0;
		}
		else//读入符号优先级低于或等于当前栈顶元素
		{
			i++;
			j = 0;
			if(oper.top()=='(') oper.pop();//左括号不存
			num[i][j] = oper.top();//当前栈顶元素存入逆波兰数组
			i++;
			oper.pop();//当前栈顶元素出栈
			oper.push(str[m]);//后进运算符入栈
		}
	}
	if(str[str.GetLength()-1]<'0'||str[str.GetLength()-1]>'9') 
		if(str[str.GetLength()-1]!=')') err="symbol";//运算符输入错误，最后以非括号的符号结尾

	//遇中缀表示式结束符后
	i++;
	while (!oper.empty())
	{
		num[i][0] = oper.top();//把运算符栈内所有运算符依次存入逆波兰式数组
		oper.pop();//弹出栈外
		i++;
	}
}
double RPN::Compute(char num[][100])//后置表达式的执行
{
	stack<double> number;
	int i = 0, j = 0;
	while (num[i][0] != '#')//从数组中依次读入符号
	{
		string NUM = "0";//用来表示当下的操作数
		if((num[i][j] >= '0' && num[i][j] <= '9') || num[i][j] == '.')
		{
			while ((num[i][j] >= '0' && num[i][j] <= '9')||num[i][j]=='.')
			{
				NUM += num[i][j];
				j++;
			}
			number.push(atof(NUM.c_str()));//如果是操作数，压入堆栈
		}
		else switch (num[i][0])//如果是运算符，对栈顶操作数进行运算
		{
			double temp;//用以运算操作数
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
