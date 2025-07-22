#include <iostream>
using namespace std;

#include "SparseMatrix.h"
#include "GenList.h"

int main()
{
	GenList gl;
	InitGenList(gl);

	const char* ga = "(1,2,3)";
	const char* gb = "(1,(2,3))";
	const char* gc = "(1,(2),3)";
	const char* gd = "((1,2),3)";
	const char* ge = "((1,2,3))";
	const char* gf = "(1,(2,(3,4)),5)";
	const char* gg = "()";

	CreateGenList(gl, gf);
	ShowGenList(gl);
	cout << endl;
	cout << GenListDepth(gl) << endl;

	DestroyGenList(gl);
	return 0;
}