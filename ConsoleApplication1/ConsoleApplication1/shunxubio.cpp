#include <stdio.h>
#include <stdlib.h>
//��̬����
#define MaxSize //������󳤶�
typedef struct {
	int data[10];//�þ�̬������������Ԫ��
	int length;  //˳�������Ͷ���
}Sqlist;
//��ʼ��
void Initlist(Sqlist& L) {
	for(int i=0;i<10;i++)
		L.data[i] = 0;//����������Ԫ������ΪĬ�ϳ�ʼֵ
	L.length = 0; //˳����ʼ����Ϊ��
}

//��������
void ListInsert(Sqlist& L, int i, int e) {
	for (int j = L.length;j >= i;j--) {//����i��Ԫ�ؼ��Ժ��Ԫ�غ��ƶ�һλ
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//��λ��i������e
	L.length++;       //���ȼ�1
}

//ɾ������
bool Listdelete(Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length)   //�ж�i��ȡֵ��Χ�Ƿ���Ч
		return false;
	e = L.data[i - 1];  //��ɾ����Ԫ�ظ�ֵ��e
	for (int j = i;j < L.length;j++) //����i��λ�ú��Ԫ��ǰ��һλ
		L.data[j - 1] = L.data[j];
	L.length--; //���Ա��ȼ�1
	return true;
}

int main() {
	Sqlist L;   //����һ��˳���
	Initlist(L);//��ʼ��˳���
	for (int i = 0; i < 10;i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	return 0;
}


/*
//#��̬����
#define InitSize 10 //Ĭ�ϵ���󳤶�
typedef struct {
	int *data;  //ָʾ��̬���������ָ��
	int length; //˳�����������
	int MaxSize;//˳���ĵ�ǰ����
}Seqlist;

void InitList(Seqlist& L) {
	//��malloc ��������һƬ�����Ĵ洢�ռ�
	L.data = (int*)malloc(10 * sizeof(int));
	L.length = 0;
	L.MaxSize = 10;
}
//���Ӷ�̬����ĳ���
void IncreasseSize(Seqlist& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0;i < L.length;i++) {
		L.data[i] = p[i];     //�����ݸ��Ƶ��µ�����
	}
	L.MaxSize = L.MaxSize + len;//˳�����󳤶�����len
	free(p);       //�ͷ�ԭ�����ڴ�ռ�
}

int main() {
	Seqlist L;    //����
	InitList(L);   //��ʼ��
//...����Ԫ��
	IncreasseSize(L, 5);
	return 0;

}
*/