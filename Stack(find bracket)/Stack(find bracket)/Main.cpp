#include "String.h"

int main() {
	String math("(5+4)+{2*[5-1]-10}/((100))+[2(4}]-90");
	cout << math.checkBracket();
	String math2("4+{(4-2))-{6}");
	cout << math2.checkBracket();
	String math3("{[()]}((4-2))");
	cout << math3.checkBracket();
}