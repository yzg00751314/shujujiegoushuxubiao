#include <stdio.h>
#include <stdlib.h>
//静态分配
#define MaxSize //定义最大长度
typedef struct {
	int data[10];//用静态的数组存放数据元素
	int length;  //顺序表的类型定义
}Sqlist;
//初始化
void Initlist(Sqlist& L) {
	for(int i=0;i<10;i++)
		L.data[i] = 0;//将所有数据元素设置为默认初始值
	L.length = 0; //顺序表初始长度为零
}

//插入数据
void ListInsert(Sqlist& L, int i, int e) {
	for (int j = L.length;j >= i;j--) {//将第i个元素及以后的元素后移动一位
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//在位置i处放入e
	L.length++;       //长度加1
}

//删除数据
bool Listdelete(Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length)   //判断i的取值范围是否有效
		return false;
	e = L.data[i - 1];  //将删除的元素赋值给e
	for (int j = i;j < L.length;j++) //将第i个位置后的元素前移一位
		L.data[j - 1] = L.data[j];
	L.length--; //线性表长度减1
	return true;
}

int main() {
	Sqlist L;   //声明一个顺序表
	Initlist(L);//初始化顺序表
	for (int i = 0; i < 10;i++)
		printf("data[%d]=%d\n", i, L.data[i]);
	return 0;
}


/*
//#动态分配
#define InitSize 10 //默认的最大长度
typedef struct {
	int *data;  //指示动态分配数组的指针
	int length; //顺序表的最大容量
	int MaxSize;//顺序表的当前长度
}Seqlist;

void InitList(Seqlist& L) {
	//用malloc 函数申请一片连续的存储空间
	L.data = (int*)malloc(10 * sizeof(int));
	L.length = 0;
	L.MaxSize = 10;
}
//增加动态数组的长度
void IncreasseSize(Seqlist& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0;i < L.length;i++) {
		L.data[i] = p[i];     //将数据复制到新的区域
	}
	L.MaxSize = L.MaxSize + len;//顺序表最大长度增加len
	free(p);       //释放原来的内存空间
}

int main() {
	Seqlist L;    //声明
	InitList(L);   //初始化
//...插入元素
	IncreasseSize(L, 5);
	return 0;

}
*/