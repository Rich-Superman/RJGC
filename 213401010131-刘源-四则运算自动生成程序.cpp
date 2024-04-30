#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//显示菜单
void showmenu() {
	printf("*----------------------------------------------------*\n");
	printf("*        欢迎使用小学四则运算自动生成程序            *\n");
	printf("*          请根据如下步骤完成初始化设置              *\n");
	printf("*----------------------------------------------------*\n");
	printf("*               1： 输入年级                         *\n");
	printf("*               2： 输入题目数量                     *\n");
	printf("*               3： 输入最大数                       *\n");
	printf("*               4： 选择是否允许使用括号             *\n");
	printf("*               5： 选择是否允许生成小数             *\n");
	printf("*               6： 选择运算符                       *\n");
	printf("*               7： 选择输出方式                     *\n");
	printf("*----------------------------------------------------*\n");
}

// 生成随机数，根据 allowDecimals 参数确定是否生成小数
float generateNumber(int max, int allowDecimals) {
    if (allowDecimals) {
        return (float)(rand() % (max * 10)) / 10.0;
    } else {
        return rand() % (max + 1);
    }
}

// 生成随机运算符
char generateOperator(int grade) {
    if (grade == 1) {
        return (rand() % 2 == 0) ? '+' : '-';
    } else if (grade == 2) {
        int op = rand() % 4; // 生成一个介于 0 和 3 之间的随机数
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    } else if (grade == 3) {
        int op = rand() % 3; // 生成一个介于 0 和 2 之间的随机数
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else return '*';
    } else if (grade == 4 || grade == 5 || grade == 6) {
        int op = rand() % 4; // 生成一个介于 0 和 3 之间的随机数
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    } else {
        // 处理无效等级
        return '?';
    }
}


// 生成表达式
void generateExpression(int grade, int maxNumber, char operators[], int allowParentheses, int allowDecimals) {
    char operator1, operator2;

    // 修改生成随机数的函数调用
    if (grade == 1) {
        operator1 = generateOperator(1);
        printf("%.1f %c %.1f = ?\n", generateNumber(maxNumber, allowDecimals), operator1, generateNumber(maxNumber, allowDecimals));
    } else if (grade == 2) {
        operator1 = generateOperator(2);
        printf("%.1f %c %.1f = ?\n", generateNumber(maxNumber, allowDecimals), operator1, generateNumber(maxNumber, allowDecimals));
    } else if (grade == 3) {
        operator1 = generateOperator(3);
        printf("%.1f %c %.1f %c %.1f = ?\n", generateNumber(maxNumber, allowDecimals), operator1, generateNumber(maxNumber, allowDecimals), generateOperator(3), generateNumber(maxNumber, allowDecimals));
    } else if (grade >= 4 && grade <= 6) {
        operator1 = generateOperator(grade); // 使用年级参数调用 generateOperator
        operator2 = generateOperator(grade); // 使用年级参数调用 generateOperator
        if (allowParentheses && rand() % 2 == 0) {
            printf("(%.1f %c %.1f) %c %.1f = ?\n", generateNumber(maxNumber, allowDecimals), operator1, generateNumber(maxNumber, allowDecimals), operator2, generateNumber(maxNumber, allowDecimals));
        } else {
            printf("%.1f %c %.1f %c %.1f = ?\n", generateNumber(maxNumber, allowDecimals), operator1, generateNumber(maxNumber, allowDecimals), operator2, generateNumber(maxNumber, allowDecimals));
        }
    }
}


int main() {
    int grade, numExercises, i, maxNumber, allowParentheses, allowDecimals, output_choice;
    char operators[5] = "+-*/";
    showmenu();

    srand(time(NULL));

    printf("请输入年级（1-6）：");
    scanf("%d", &grade);

    printf("请输入题目数量：");
    scanf("%d", &numExercises);

    printf("请输入最大数：");
    scanf("%d", &maxNumber);

    printf("是否允许使用括号？(1: 是, 0: 否)：");
    scanf("%d", &allowParentheses);

    printf("是否允许生成小数？(1: 是, 0: 否)：");
    scanf("%d", &allowDecimals);

    printf("请选择运算符（+ - * /，例如选择 +* 表示只允许加法和乘法）：");
    scanf("%s", operators);
    
    printf("请选择输出方式 (1: 文件, 0: 打印机)：");
    scanf("%d", &output_choice);

    // 如果未提供运算符，则确保包含所有四个基本运算符
    if (operators[0] == '\0') {
        operators[0] = '+';
        operators[1] = '-';
        operators[2] = '*';
        operators[3] = '/';
    }

    printf("生成的四则运算题目如下：\n");
    for (i = 0; i < numExercises; i++) {
        generateExpression(grade, maxNumber, operators, allowParentheses, allowDecimals);
    }

    return 0;
}

