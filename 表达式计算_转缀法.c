#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 辅助函数：获取运算符优先级
int getPriority(char op) {
    switch (op) {
        case '+': 
        case '-': return 1;
        case '*': return 2;
        default: return 0; // 括号
    }
}

// 执行运算
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}

// 中缀表达式转后缀表达式
void infixToPostfix(char* s, char* postfix, int* postfixLen) {
    char stack[100];  // 运算符栈
    int top = -1;
    int len = strlen(s);
    int pi = 0;  // postfix index
    
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        
        // 跳过空格
        if (ch == ' ') continue;
        
        // 如果是数字，直接添加到后缀表达式
        if (isdigit(ch)) {
            // 读取完整数字
            while (i < len && isdigit(s[i])) {
                postfix[pi++] = s[i++];
            }
            i--;  // 回退，因为for循环会i++
            postfix[pi++] = '#';  // 添加数字结束标记
        }
        // 如果是左括号，压入栈
        else if (ch == '(') {
            stack[++top] = ch;
        }
        // 如果是右括号，将栈中元素弹出直到遇到左括号
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[pi++] = stack[top--];
            }
            if (top >= 0) top--;  // 弹出左括号
        }
        // 如果是运算符
        else if (ch == '+' || ch == '-' || ch == '*') {
            // 当栈非空且栈顶运算符优先级不低于当前运算符时，弹出并添加到后缀表达式
            while (top >= 0 && getPriority(stack[top]) >= getPriority(ch)) {
                postfix[pi++] = stack[top--];
            }
            // 当前运算符入栈
            stack[++top] = ch;
        }
    }
    
    // 将栈中剩余运算符添加到后缀表达式
    while (top >= 0) {
        postfix[pi++] = stack[top--];
    }
    
    postfix[pi] = '\0';  // 添加字符串结束符
    *postfixLen = pi;
}

// 计算后缀表达式
int calculatePostfix(char* postfix) {
    int stack[100];
    int top = -1;
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];
        
        if (ch == '#') {
            // 跳过数字结束标记，数字已经在下面处理了
            continue;
        }
        else if (isdigit(ch)) {
            // 解析完整数字
            int num = 0;
            while (i < len && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;  // 回退，因为for循环会i++
            
            // 数字入栈
            stack[++top] = num;
        }
        else {
            // 运算符，弹出两个操作数进行计算
            int b = stack[top--];
            int a = stack[top--];
            int result = applyOp(a, b, ch);
            stack[++top] = result;
        }
    }
    
    return stack[top];
}

//计算主函数 
int solve(char* s) {
    char postfix[200];  // 后缀表达式，最大长度约为原表达式的2倍
    int postfixLen;
    
    // 1. 中缀转后缀
    infixToPostfix(s, postfix, &postfixLen);
    
    // 2. 计算后缀表达式
    return calculatePostfix(postfix);
}

int main(){
	
	char init[100];
	scanf("%s",init);
	
	printf("%d\n",solve(init));
	
	return 0;
}
