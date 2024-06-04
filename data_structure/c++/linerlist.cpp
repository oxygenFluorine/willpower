//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
}TestList;

//初始化线性表
void InitList(TestList *L) {
    L->length = 0;
}


//获取线性表长度,获取线性表个数
int ListLength(TestList L)
{
    return L.length;
}

//获取指定位置的元素
bool getElem(TestList L,int i,ElemType *e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    //将位置i-1的元素赋值给e
    *e=L.data[i-1];
    return true;
}

//在线性表里查找元素
bool localElem(TestList L,ElemType e)
{
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i]==e)
        {
            return true;
        }
    }
    return false;
}

//在线性表里插入元素
bool insertElem(TestList *L,int i,ElemType e)
{
    if (i<1||i>L->length+1||L->length>MAXSIZE)
    {
        return false;
    }
    for (int j = L->length; j >=i ; --j) {
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    ++L->length;
    return true;
}

//删除线性表的元素
bool ListDelete(TestList *L,int i,ElemType *e)
{
    if (i<1||i>L->length)
    {
        return false;
    }
    for(int j=i;j<L->length;j++)
    {
        L->data[j-1]=L->data[j];
    }
    *e=L->data[i-1];
    --L->length;
    return true;
}
//将所有在线性表lb，但不在la的元素，插入到la中
void unionList(TestList *la, TestList lb)
{
    int len_la,len_lb,i;
    ElemType e;
    len_la = ListLength(*la);
    len_lb = ListLength(lb);
    for(i=1;i<=len_lb;i++)
    {
        getElem(lb,i,&e);
        if (!localElem(*la,e))
        {
            insertElem(la,++len_la,e);
        }
    }
}

//清空线性表
void ClearList(TestList *L)
{
    L->length = 0; // 将线性表的长度设置为 0，表示清空线性表
}

int main(){
    TestList la;
    TestList lb;
    InitList(&la);
    InitList(&lb);
    ElemType e;

    for (int i = 1; i <=5 ; i++) {
        insertElem(&la,i,i);
        insertElem(&lb,i,i+3);
    }

    unionList(&la,lb);
    for (int i = 1; i <=la.length; ++i) {
      //  cout<<"从lb插入到la中"<<endl;
        cout<<la.data[i-1];
    }
    int j=2;
    ListDelete(&lb, j,&e);
    for (int i = 1; i <=lb.length; ++i) {
       // cout << "删除b的元素" << endl;
        cout<< lb.data[i - 1];
    }
    ClearList(&lb);
    return 0;   
}
