#include <iostream>
using namespace std;

#include "SeqStack.h"
//#include "LinkStack.h"

#define USAGE_1   0
#define USAGE_2   0
#define USAGE_3   1

#if   USAGE_1
/* 十进制转八进制 */
void Convert_8(int value)
{
	SeqStack st;
	InitStack(st);

	while (value) {
		Push(st, value % 8);
		value /= 8;
	}

	int e;
	while (!IsEmpty(st)) {
		GetTop(st, e);
		Pop(st);
		cout << e;
	}
	cout << endl;
	Destroy(st);
}

#elif USAGE_2
/* 括号匹配检验 */
bool Check(const char* str)
{
	SeqStack st;
	InitStack(st);

	char e;
	while (*str != '\0')
	{
		if (*str == '[' || *str == '(')
			Push(st, *str);
		else if (*str == ']') {
			GetTop(st, e);
			if (e != '[')
				return false;
			Pop(st);
		}
		else if (*str == ')') {
			GetTop(st, e);
			if (e != '(')
				return false;
			Pop(st);
		}
		str++;
	}
	bool flag = IsEmpty(st) ? true : false;
	Destroy(st);
	return flag;
}
#elif USAGE_3
/* 行编辑程序 */
void LineEdit()
{
	SeqStack st;
	InitStack(st);

	char ch = getchar();
	while (ch != '$') //结束符$
	{
		while (ch != '$' && ch != '\n') {
			switch (ch)
			{
				case '#':
					Pop(st);
					break;
				case '@':
					Clear(st);
					break;
				default:
					Push(st, ch);
					break;
			}
			ch = getchar();
		}
		for (int i = 0; i < st.top; i++)
			cout << st.base[i];
		cout << endl;
		ch = getchar();
	}
	Destroy(st);
}
#endif

int main()
{
#if   USAGE_1
	int value;
	cin >> value;
	Convert_8(value);
#elif USAGE_2
	const char* str = "[([()][][])]";
	bool flag = Check(str);
	if (flag == true)
		cout << "True" << endl;
	else
		cout << "False" << endl;
#elif USAGE_3
	LineEdit();
#endif
	return 0;
}