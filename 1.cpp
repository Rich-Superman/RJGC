#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成一个随机的非负整数
int generateNumber(int max) {
    return rand() % (max + 1);
}

// 生成一个运算符（加减乘除）
char generateOperator(int grade) {
    if (grade <= 2) {
        return (rand() % 2 == 0) ? '+' : '-';
    } else if (grade == 3) {
        int op = rand() % 3;
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else return '*';
    } else {
        int op = rand() % 4;
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    }
}

// 生成一个四则运算式
void generateExpression(int grade) {
    int result;
    char operator1, operator2;

    if (grade == 1) {
        operator1 = generateOperator(1);
        printf("%d %c %d = ?\n", generateNumber(20), operator1, generateNumber(20));
    } else if (grade == 2) {
        operator1 = generateOperator(2);
        printf("%d %c %d = ?\n", generateNumber(25), operator1, generateNumber(25));
    } else if (grade == 3) {
        operator1 = generateOperator(3);
        printf("%d %c %d %c %d = ?\n", generateNumber(500), operator1, generateNumber(500), generateOperator(3), generateNumber(500));
    } else {
        operator1 = generateOperator(4);
        operator2 = generateOperator(4);
        printf("(%d %c %d) %c %d = ?\n", generateNumber(100), operator1, generateNumber(100), operator2, generateNumber(100));
    }
}

int main() {
    int grade, numExercises, i;

    srand(time(NULL));

    printf("请输入年级（1-6）：");
    scanf("%d", &grade);

    printf("请输入题目数量：");
    scanf("%d", &numExercises);

    printf("生成的四则运算题目如下：\n");
    for (i = 0; i < numExercises; i++) {
        generateExpression(grade);
    }

    return 0;
}
