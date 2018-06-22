/*************************************/
/*每次使用时修改typedef中的数据结构类型*/
/* 改进可以使用c++的模板进行书写 */
/* 通过修改宏定义中的DATATYPE可以修改其基础数据类型 */
/* 如果需要data域是一个结构体则修改datatype的定义 */
/* 默认为链式栈 */
#ifndef _STACK_LHZ_H
#define _STACK_LHZ_H
#include<stdlib.h>
//#define DATATYPE char
/* 宏定义空值 */
//#define EMPTYDATA
typedef char datatype;
typedef struct node{
  datatype data;
  struct node *next;
}snode,*slink,**slink2;
/************************************/
/* 函数名称：StackInit */
/* 函数参数： slink2 s*/
/* 函数功能：初始化一个链式栈 */
/***********************************/
void StackInit(slink2 s){
    *s=(slink)malloc(sizeof(snode));
    datatype tmp;
    tmp='\0';
    (*s)->data=tmp;
    (*s)->next=NULL;
}
/************************************/
/* 函数名称：EmptyStack */
/* 函数参数： slink s*/
/* 函数功能：检测栈空 */
/* 栈空为1，否则为0 */
/***********************************/
bool EmptyStack(slink s){
  if(s->next==NULL)return true;
  else return false;
}
/************************************/
/* 函数名称：Pop  */
/* 函数参数：slink2 s*/
/* 函数功能：弹出栈顶元素 */
/* 栈空返回! */
/***********************************/
datatype Pop(slink S){
  if(EmptyStack(S)){
  	datatype tmp;
  	tmp='\0';
    return tmp;
  }
  else{
    slink P=S->next;
    S->next=P->next;
    datatype tmp=P->data;
    free(P);
    return tmp;
  }
}
/************************************/
/* 函数名称：push  */
/* 函数参数：slink s,datatype data*/
/* 函数功能：压栈 */
/***********************************/
void push(slink s,datatype data){
  /* 除上述情况外其它情况为需要申请新的节点 */
    slink P=(slink)malloc(sizeof(snode));
    P->data=data;
    /* 建立P指针的链接 */
    P->next=s->next;
    /* 断开头指针,并重建链接 */
    s->next=P;
}
/************************************/
/* 函数名称：StackLength  */
/* 函数参数：slink s,*/
/* 函数功能：返回栈的长度 */
/***********************************/
int StackLength(slink s){
    slink P=s->next;
    int ans=0;
    while(P!=NULL){
      ans++;
      P=P->next;
    }
    return ans;
}
/************************************/
/* 函数名称：DestoryStack  */
/* 函数参数：slink s*/
/* 函数功能：释放整个栈空间 */
/***********************************/
void DestoryStack(slink s){
    int len=StackLength(s);
    /* 申请长度为len的临时数组，数组中存放一级指针的地址 */
    slink2 tmp=(slink2)calloc(len,sizeof(slink));
    slink P=s->next;
    /* 将单链表中的元素倒置 */
    int i=0;
	  for(i=0;i<len;i++){
      tmp[len-i-1]=P;
      P=P->next;
    }
    for(i=0;i<len;i++){
      free(tmp[i]);
    }
    free(tmp);
    free(s);
    return ;
}
/************************************/
/* 函数名称：ClearStack  */
/* 函数参数：slink s*/
/* 函数功能：压栈 */
/***********************************/
void ClearStack(slink s){
    DestoryStack(s->next);
    datatype tmp;
    tmp='\0';
    s->data=tmp;
    s->next=NULL;
}
/************************************/
/* 函数名称：Gettop  */
/* 函数参数：slink s*/
/* 函数功能：取栈顶元素 */
/* 栈空返回EMPTYDATA */
/***********************************/
datatype Gettop(slink s){
    slink P=s->next;
    if(!EmptyStack(s)){
        return P->data;
    }
    else{
      datatype tmp;
      tmp='\0';
      return tmp;
    }
}
#endif
