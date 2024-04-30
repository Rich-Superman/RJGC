#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʾ�˵�
void showmenu() {
	printf("*----------------------------------------------------*\n");
	printf("*        ��ӭʹ��Сѧ���������Զ����ɳ���            *\n");
	printf("*          ��������²�����ɳ�ʼ������              *\n");
	printf("*----------------------------------------------------*\n");
	printf("*               1�� �����꼶                         *\n");
	printf("*               2�� ������Ŀ����                     *\n");
	printf("*               3�� ���������                       *\n");
	printf("*               4�� ѡ���Ƿ�����ʹ������             *\n");
	printf("*               5�� ѡ���Ƿ���������С��             *\n");
	printf("*               6�� ѡ�������                       *\n");
	printf("*               7�� ѡ�������ʽ                     *\n");
	printf("*----------------------------------------------------*\n");
}

// ��������������� allowDecimals ����ȷ���Ƿ�����С��
float generateNumber(int max, int allowDecimals) {
    if (allowDecimals) {
        return (float)(rand() % (max * 10)) / 10.0;
    } else {
        return rand() % (max + 1);
    }
}

// ������������
char generateOperator(int grade) {
    if (grade == 1) {
        return (rand() % 2 == 0) ? '+' : '-';
    } else if (grade == 2) {
        int op = rand() % 4; // ����һ������ 0 �� 3 ֮��������
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    } else if (grade == 3) {
        int op = rand() % 3; // ����һ������ 0 �� 2 ֮��������
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else return '*';
    } else if (grade == 4 || grade == 5 || grade == 6) {
        int op = rand() % 4; // ����һ������ 0 �� 3 ֮��������
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    } else {
        // ������Ч�ȼ�
        return '?';
    }
}


// ���ɱ��ʽ
void generateExpression(int grade, int maxNumber, char operators[], int allowParentheses, int allowDecimals) {
    char operator1, operator2;

    // �޸�����������ĺ�������
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
        operator1 = generateOperator(grade); // ʹ���꼶�������� generateOperator
        operator2 = generateOperator(grade); // ʹ���꼶�������� generateOperator
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

    printf("�������꼶��1-6����");
    scanf("%d", &grade);

    printf("��������Ŀ������");
    scanf("%d", &numExercises);

    printf("�������������");
    scanf("%d", &maxNumber);

    printf("�Ƿ�����ʹ�����ţ�(1: ��, 0: ��)��");
    scanf("%d", &allowParentheses);

    printf("�Ƿ���������С����(1: ��, 0: ��)��");
    scanf("%d", &allowDecimals);

    printf("��ѡ���������+ - * /������ѡ�� +* ��ʾֻ����ӷ��ͳ˷�����");
    scanf("%s", operators);
    
    printf("��ѡ�������ʽ (1: �ļ�, 0: ��ӡ��)��");
    scanf("%d", &output_choice);

    // ���δ�ṩ���������ȷ�����������ĸ����������
    if (operators[0] == '\0') {
        operators[0] = '+';
        operators[1] = '-';
        operators[2] = '*';
        operators[3] = '/';
    }

    printf("���ɵ�����������Ŀ���£�\n");
    for (i = 0; i < numExercises; i++) {
        generateExpression(grade, maxNumber, operators, allowParentheses, allowDecimals);
    }

    return 0;
}

