#include <iostream>
#include <stack>
using namespace std;

int operate(char op, int op1, int op2){
	switch(op){
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		case '^':
			int result = 1;
			for(int i=1; i<=op2; i++){
				result *= op1;
			}
			return result;
	}
}

int evaluatePostfix(string input){
	int current = 0; 
	stack<int> s;
	string operators = "+-*/^";
	char e;
	int op1 = 0;
	int op2 = 0;
	int value = 0;
	while(current<input.length()){
		e = input[current];
		if(operators.find(e) != string::npos){
			op2 = s.top();
			s.pop();
			op1 = s.top();
			s.pop();
			value = operate(e, op1, op2);
			s.push(value);
		}
		else{
			s.push(e - '0');			
		}
		current++;
	}
	return s.top();	
}

int main(){
	string input = "53+";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "27-";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "234*+";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "623+-382/+*2^3+";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "23^";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "51^";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	input = "50^";
	cout<<"Postfix expression: "<<input<<"\n";
	cout<<"Result of postfix expression: "<<evaluatePostfix(input)<<"\n";
	return 0;
}

