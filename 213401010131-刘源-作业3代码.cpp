#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <cstring>

typedef struct {
	//ѧ��רҵ
	char major[20];
	//ѧ������
	char name[10];
	//������洢�ĿƳɼ����ֱ������Ρ�Ӣ���ѧ��רҵ�Σ�
	int g[4];
} Student;

typedef struct Node {
	//������
	Student data;
	//ָ����
	struct Node *next;
} Node, *LinkList;

//�ļ�ָ��
FILE *fp;
//�ļ���
char filename[20];

//��ʼ������
void InitList(LinkList &L) {
	L = (Node *)malloc(sizeof(LinkList));
	L->next = NULL;
}

//��ʾ�˵�
void showmenu() {
	printf("*----------------------------------------------------*\n");
	printf("*        ��ӭʹ���о����������Գɼ��������          *\n");
	printf("*----------------------------------------------------*\n");
	printf("*               1�� ��ȡ�ļ�                         *\n");
	printf("*               2�� �޳��ɼ�δ��Ҫ���ѧ��           *\n");
	printf("*               3�� �ɼ�����                         *\n");
	printf("*               4�� ���ѧ������                     *\n");
	printf("*               0�� �˳�ϵͳ                         *\n");
	printf("*----------------------------------------------------*\n");
	printf("ѡ�����<0-4>                                         \n");
	return;
}

//��ȡ�ļ�C:\Users\ASUS\Desktop\students.txt
void OpenFile(LinkList &L) {
	InitList(L);
	//p�Ǵ������µĽ��
	Node *p, *q;
	//q��ָ��ͷ����ָ�룬���ڴ�������
	q = L;
	while (true) {
		cout << "�������ļ���:";
		cin >> filename;
		//û�и��ļ�
		if ((fp = fopen(filename, "r")) == NULL) {
			cout << "û�и��ļ���Ϣ" << endl << endl;
			continue;
		} else
			break;
	}
	while (true) {
		//Ϊ�´����Ľ��p����ռ�
		p = new Node;
		//���ļ�������Ϣ
		if (fscanf(fp, "%s %s %d %d %d %d\n", &p->data.major, &p->data.name, &(p->data.g[0]), &(p->data.g[1]), &(p->data.g[2]),
		           &(p->data.g[3])) == EOF) {
			//û�ж�����,��Ҫ�ͷŵ��ý��ռ�
			free(p);
			cout << "����ɹ���" << endl ;
			break;
		}
		//β�巨��������:�´����Ľ��pָ������Ϊ��,��ͷ���ָ��p ,q������һλ
		p->next = NULL;
		q->next = p;
		q = q->next;
	}
	//�ر��ļ�
	fclose(fp);
}

//�޳���ͬרҵ�ɼ�δ��Ҫ���ѧ��
void Delete(LinkList &L) {
	Node *p, *pre;
	p = L->next;
	int major = 0;
	int math = 0;
	int policy = 0;
	int english = 0;
	cout << "����������רҵ�� ��ѧ ���� Ӣ���Ҫ�����" << endl;
	cin >> major >> math >> policy >> english;
	cout << "�����޳��ɼ�δ��Ҫ���ѧ��" << endl << endl;
	while (p) {
		//�Լ������רҵ�γɼ�δ��Ҫ��ѧ���޳�
		if (strcmp(p->data.major, "�������ѧ�뼼��") == 0 || strcmp(p->data.major, "�������") == 0
		        || strcmp(p->data.major, "���繤��") == 0) {
			if (p->data.g[3] < major) {
				pre->next = p->next;
			}
		}
		//��ͳ��ѧ��ѧ�ɼ�δ��Ҫ��ѧ���޳�
		if (strcmp(p->data.major, "ͳ��ѧ") == 0) {
			if (p->data.g[2] < math) {
				pre->next = p->next;
			}
		}
		//�Է�ѧ���γɼ�δ��Ҫ��ѧ���޳�
		if (strcmp(p->data.major, "��ѧ") == 0) {
			if (p->data.g[0] < policy) {
				pre->next = p->next;
			}
		}
		//�������Ӣ��ɼ�δ��Ҫ��ѧ���޳�
		if (strcmp(p->data.major, "�����") == 0) {
			if (p->data.g[1] < english) {
				pre->next = p->next;
			}
		}
		pre = p;
		p = p->next;
	}
	cout << "�޳��ɹ���" << endl;
}

//ѧ���ɼ�����
void Sort(LinkList &L) {
	cout << "���ڰ�ѧ���ɼ���������" << endl << endl;
	Node *q = L->next;
	int len = 0;
	//��ȡ������
	while (q != NULL) {
		len++;
		q = q->next;
	}
	Node *p1, *p2;
	int x = 0;
	cout << "��ѡ��ѧ���ܷ���ͬʱ��Ҫ����Ŀγ�(0:���� 1:Ӣ�� 2:��ѧ 3:רҵ��)" << endl;
	cin >> x;
	//ð������:�Ȱ����Ƴɼ�����
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
	//ð������:�ٰ��ܳɼ�����
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
	cout << "����ɹ���" << endl;
}

//�������¼ȡ���������ѧ������
void SaveData(LinkList &L) {
	cout << "�������ѧ������" << endl << endl;
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
		cout << "��ѡ����:";
		cin >> flag;
		switch (flag) {
			case 0:
				cout << "�ڴ������´�ʹ��";
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
				printf("������������ԣ�\n");
				continue;
		}
	} while (flag != 0);
	cout << "�ڴ������´�ʹ��";
	return 0;
}
