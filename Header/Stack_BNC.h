/*************************************/
/*ÿ��ʹ��ʱ�޸�typedef�е����ݽṹ����*/
/* �Ľ�����ʹ��c++��ģ�������д */
/* ͨ���޸ĺ궨���е�DATATYPE�����޸�������������� */
/* �����Ҫdata����һ���ṹ�����޸�datatype�Ķ��� */
/* Ĭ��Ϊ��ʽջ */
#ifndef _STACK_LHZ_H
#define _STACK_LHZ_H
#include<stdlib.h>
//#define DATATYPE char
/* �궨���ֵ */
//#define EMPTYDATA
typedef char datatype;
typedef struct node{
  datatype data;
  struct node *next;
}snode,*slink,**slink2;
/************************************/
/* �������ƣ�StackInit */
/* ���������� slink2 s*/
/* �������ܣ���ʼ��һ����ʽջ */
/***********************************/
void StackInit(slink2 s){
    *s=(slink)malloc(sizeof(snode));
    datatype tmp;
    tmp='\0';
    (*s)->data=tmp;
    (*s)->next=NULL;
}
/************************************/
/* �������ƣ�EmptyStack */
/* ���������� slink s*/
/* �������ܣ����ջ�� */
/* ջ��Ϊ1������Ϊ0 */
/***********************************/
bool EmptyStack(slink s){
  if(s->next==NULL)return true;
  else return false;
}
/************************************/
/* �������ƣ�Pop  */
/* ����������slink2 s*/
/* �������ܣ�����ջ��Ԫ�� */
/* ջ�շ���! */
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
/* �������ƣ�push  */
/* ����������slink s,datatype data*/
/* �������ܣ�ѹջ */
/***********************************/
void push(slink s,datatype data){
  /* ������������������Ϊ��Ҫ�����µĽڵ� */
    slink P=(slink)malloc(sizeof(snode));
    P->data=data;
    /* ����Pָ������� */
    P->next=s->next;
    /* �Ͽ�ͷָ��,���ؽ����� */
    s->next=P;
}
/************************************/
/* �������ƣ�StackLength  */
/* ����������slink s,*/
/* �������ܣ�����ջ�ĳ��� */
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
/* �������ƣ�DestoryStack  */
/* ����������slink s*/
/* �������ܣ��ͷ�����ջ�ռ� */
/***********************************/
void DestoryStack(slink s){
    int len=StackLength(s);
    /* ���볤��Ϊlen����ʱ���飬�����д��һ��ָ��ĵ�ַ */
    slink2 tmp=(slink2)calloc(len,sizeof(slink));
    slink P=s->next;
    /* ���������е�Ԫ�ص��� */
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
/* �������ƣ�ClearStack  */
/* ����������slink s*/
/* �������ܣ�ѹջ */
/***********************************/
void ClearStack(slink s){
    DestoryStack(s->next);
    datatype tmp;
    tmp='\0';
    s->data=tmp;
    s->next=NULL;
}
/************************************/
/* �������ƣ�Gettop  */
/* ����������slink s*/
/* �������ܣ�ȡջ��Ԫ�� */
/* ջ�շ���EMPTYDATA */
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
