#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <cstring>

typedef struct {
	//学生专业
	char major[20];
	//学生姓名
	char name[10];
	//用数组存储四科成绩（分别是政治、英语、数学和专业课）
	int g[4];
} Student;

typedef struct Node {
	//数据域
	Student data;
	//指针域
	struct Node *next;
} Node, *LinkList;

//文件指针
FILE *fp;
//文件名
char filename[20];

//初始化链表
void InitList(LinkList &L) {
	L = (Node *)malloc(sizeof(LinkList));
	L->next = NULL;
}

//显示菜单
void showmenu() {
	printf("*----------------------------------------------------*\n");
	printf("*        欢迎使用研究生招生考试成绩排序程序          *\n");
	printf("*----------------------------------------------------*\n");
	printf("*               1： 读取文件                         *\n");
	printf("*               2： 剔除成绩未达要求的学生           *\n");
	printf("*               3： 成绩排序                         *\n");
	printf("*               4： 输出学生名单                     *\n");
	printf("*               0： 退出系统                         *\n");
	printf("*----------------------------------------------------*\n");
	printf("选择操作<0-4>                                         \n");
	return;
}

//读取文件C:\Users\ASUS\Desktop\students.txt
void OpenFile(LinkList &L) {
	InitList(L);
	//p是创建的新的结点
	Node *p, *q;
	//q是指向头结点的指针，用于创建链表
	q = L;
	while (true) {
		cout << "请输入文件名:";
		cin >> filename;
		//没有该文件
		if ((fp = fopen(filename, "r")) == NULL) {
			cout << "没有该文件信息" << endl << endl;
			continue;
		} else
			break;
	}
	while (true) {
		//为新创建的结点p分配空间
		p = new Node;
		//从文件读入信息
		if (fscanf(fp, "%s %s %d %d %d %d\n", &p->data.major, &p->data.name, &(p->data.g[0]), &(p->data.g[1]), &(p->data.g[2]),
		           &(p->data.g[3])) == EOF) {
			//没有读出来,需要释放掉该结点空间
			free(p);
			cout << "读入成功！" << endl ;
			break;
		}
		//尾插法创建链表:新创建的结点p指针域置为空,将头结点指向p ,q向右移一位
		p->next = NULL;
		q->next = p;
		q = q->next;
	}
	//关闭文件
	fclose(fp);
}

//剔除不同专业成绩未达要求的学生
void Delete(LinkList &L) {
	Node *p, *pre;
	p = L->next;
	int major = 0;
	int math = 0;
	int policy = 0;
	int english = 0;
	cout << "请依次输入专业课 数学 政治 英语的要求分数" << endl;
	cin >> major >> math >> policy >> english;
	cout << "正在剔除成绩未达要求的学生" << endl << endl;
	while (p) {
		//对计算机类专业课成绩未达要求学生剔除
		if (strcmp(p->data.major, "计算机科学与技术") == 0 || strcmp(p->data.major, "软件工程") == 0
		        || strcmp(p->data.major, "网络工程") == 0) {
			if (p->data.g[3] < major) {
				pre->next = p->next;
			}
		}
		//对统计学数学成绩未达要求学生剔除
		if (strcmp(p->data.major, "统计学") == 0) {
			if (p->data.g[2] < math) {
				pre->next = p->next;
			}
		}
		//对法学政治成绩未达要求学生剔除
		if (strcmp(p->data.major, "法学") == 0) {
			if (p->data.g[0] < policy) {
				pre->next = p->next;
			}
		}
		//对外国语英语成绩未达要求学生剔除
		if (strcmp(p->data.major, "外国语") == 0) {
			if (p->data.g[1] < english) {
				pre->next = p->next;
			}
		}
		pre = p;
		p = p->next;
	}
	cout << "剔除成功！" << endl;
}

//学生成绩排序
void Sort(LinkList &L) {
	cout << "正在按学生成绩进行排序" << endl << endl;
	Node *q = L->next;
	int len = 0;
	//获取链表长度
	while (q != NULL) {
		len++;
		q = q->next;
	}
	Node *p1, *p2;
	int x = 0;
	cout << "请选择学生总分相同时需要排序的课程(0:政治 1:英语 2:数学 3:专业课)" << endl;
	cin >> x;
	//冒泡排序:先按单科成绩排序
	for (int i = 0; i < len - 1; i++) {
		q = L->next;
		for (int j = 0; j < len - i - 1 ; j++) {
			p1 = q;
			p2 = q->next;
			if (p1->data.g[x] < p2->data.g[x]) {
				Student temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
			q = q->next;
		}
	}
	//冒泡排序:再按总成绩排序
	for (int i = 0; i < len - 1; i++) {
		q = L->next;
		for (int j = 0; j < len - i - 1 ; j++) {
			p1 = q;
			p2 = q->next;
			if (p1->data.g[0] + p1->data.g[1] + p1->data.g[2] + p1->data.g[3] < p2->data.g[0] + p2->data.g[1] + p2->data.g[2] +
			        p2->data.g[3]) {
				Student temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
			q = q->next;
		}
	}
	cout << "排序成功！" << endl;
}

//输出按照录取规则排序的学生名单
void SaveData(LinkList &L) {
	cout << "正在输出学生名单" << endl << endl;
	Node *pre = L->next;
	while (pre) {
		printf("%s %s %d %d %d %d\n", &pre->data.major, &pre->data.name, pre->data.g[0], pre->data.g[1], pre->data.g[2],
		       pre->data.g[3]);
		pre = pre->next;
	}
}

int main() {
	Node *L;
	showmenu();
	int flag = 0;
	do {
		cout << endl;
		cout << "请选择功能:";
		cin >> flag;
		switch (flag) {
			case 0:
				cout << "期待您的下次使用";
				exit(0);
			case 1:
				OpenFile(L);
				break;
			case 2:
				Delete(L);
				break;
			case 3:
				Sort(L);
				break;
			case 4:
				SaveData(L);
				break;
			default:
				printf("输入错误，请重试！\n");
				continue;
		}
	} while (flag != 0);
	cout << "期待您的下次使用";
	return 0;
}
