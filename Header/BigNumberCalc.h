#ifndef _BIGNUMBERCALC_H_
#define _BIGNUMBERCALC_H_
#include<string>
#include<Stack_BNC.h>
int max(int a,int b){
  if(a>=b){
    return a;
  }
  return b;
}
/* �Ƚ�a b��ֵ�д����λ��ʼ */
int BigNumber_CMP2(char *a,char *b){

}
char *BigNumber_Power_son_Positive(char *a,char *b);
int BigNumber_CMP(char *a,char *b);
/* ͨ��a>0,b>0 a+b a-b ʵ�� a+b a-b -a+b -a-b */
/* �������ƣ�BigNumber_Plus_son */
/* ����������char *a,char *b */
/* a,b��һλΪ����λ+����-���Ϊ��ֵ */
/* �������ܣ�����������a+b */
/* ����Ҫ��a>0,b>0 */
char *BigNumber_Plus_son(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  /* �������ֵ�õ��ĵ�����ֵ��󳤶����ֵ+1��ͬʱ��һλ����λ */
  int lenans=max(lena-1,lenb-1)+2;
  char *ans=(char *)calloc(lenans+1,sizeof(char));
  if(BigNumber_CMP(a,"+0")==0){
  	/* 0+b=b */
  	free(ans);
  	ans=(char *)calloc(lenb+1,sizeof(char));
  	strcpy(ans,b);
  	return ans;
  }
  if(BigNumber_CMP(b,"+0")==0){
  	/* a+0=a */
	free(ans);
  	ans=(char *)calloc(lena+1,sizeof(char));
  	strcpy(ans,a);
  	return a;
  }
  slink sa=NULL,sb=NULL,sc=NULL;
  StackInit(&sa);
  StackInit(&sb);
  StackInit(&sc);
  /* ����aѹ��ջ�� */
  for(int i=1;i<lena;i++){
    push(sa,a[i]);
  }
  /* ����bѹ��ջ�� */
  for(int i=1;i<lenb;i++){
    push(sb,b[i]);
  }
  /* ȫ���� */
  /* AΪA���� BΪB���� CΪ��λ */
  int A=0;int B=0;int C=0;
  int sum=0;
  /* ��ʱջ�ж�Ϊ��λ���� */
  for(int i=0;i<lenans;i++){
    A=0;B=0;sum=0;
    if(!EmptyStack(sa)){
      A=Pop(sa)-'0';
    }
    if(!EmptyStack(sb)){
      B=Pop(sb)-'0';
    }
    /* ����A+B+C */
    sum=A+B+C;
    if(sum<10){
      push(sc,sum+'0');
      /* �����λ */
      C=0;
    }
    else if(sum>=10){
      push(sc,sum-10+'0');
      /* �����λ */
      C=sum/10;
    }
  }
  int flag=false;
  ans[0]='+';
  int i=1;
  while(true){
    char tmp=Pop(sc);
    if(flag==false && tmp=='0'){
      continue;
    }
    else if(flag==false && tmp!='0'){
      flag=true;
    }
    ans[i++]=tmp;
    if(EmptyStack(sc)){
      break;
    }
  }
  ans[i]='\0';
  DestoryStack(sa);
  DestoryStack(sb);
  DestoryStack(sc);
  return ans;
}
/* Ĭ������ʱ�Ϸ� */
/* 1 a>b 0 a=b -1 a<b */
int BigNumber_CMP(char *a,char *b){
  /* ���ȸ��ݷ��Ž����б� */
  if(a[0]=='+' && b[0]=='-'){
    return 1;
  }
  else if(a[0]=='-' && b[0]=='+'){
    return -1;
  }
  /* ���¿�ʼ�ȽϾ���ֵ�Ĵ�С */
  int lena=strlen(a);
  int lenb=strlen(b);
  int ans=0;
  if(lena>lenb){
    if(a[0]=='+'){
      return 1;
    }
    else if(a[0]=='-'){
      return -1;
    }
  }
  else if(lena<lenb){
    if(a[0]=='+'){
      return -1;
    }
    else if(a[0]=='-'){
      return 1;
    }
  }
  /* �����¿�ʼ����λ��ȣ�lenֵ��� */
  for(int i=1;i<lena;i++){
    if(a[i]<b[i]){
      if(a[0]=='+')
        return -1;
      else if(a[0]=='-')
        return 1;
    }
    else if(a[i]>b[i]){
      if(a[0]=='+')
        return 1;
      else if(a[0]=='-')
        return -1;
    }
  }
  return 0;
}
int BigNumber_CMP_abs(char *a,char *b){
  char *tmpa=(char *)calloc(strlen(a)+1,sizeof(char));
  char *tmpb=(char *)calloc(strlen(b)+1,sizeof(char));
  tmpa[0]='+';tmpb[0]='+';
  return BigNumber_CMP(tmpa,tmpb);
}
/* ʵ��a-b a>0 b>0 */
char *BigNumber_Minus_son(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  int lentmpa=0;
  int lentmpb=0;
  int lenans=max(lena-1,lenb-1)+1;
  char *tmpa=NULL;
  char *tmpb=NULL;
  char *ans=(char *)calloc(lenans+1,sizeof(char));
  slink sa=NULL;
  slink sb=NULL;
  slink sc=NULL;
  /* ջ�ĳ�ʼ�� */
  StackInit(&sa);
  StackInit(&sb);
  StackInit(&sc);
  int CMP=BigNumber_CMP(a,b);
  if(CMP==0){
    ans[0]='+';
    ans[1]='0';
    ans[2]='\0';
    realloc(ans,sizeof(char)*3);
    return ans;
  }
  else if(CMP==1){
    /* a>b */
    /* ������������ */
    ans[0]='+';
    tmpa=a;
    tmpb=b;
    lentmpa=lena;
    lentmpb=lenb;
  }
  else if(CMP==-1){
    /* a<b */
    /* ������Ϊ���� */
    ans[0]='-';
    tmpa=b;
    tmpb=a;
    lentmpa=lenb;
    lentmpb=lena;
  }
  /* assert tmpa>tmpb */
  for(int i=1;i<lentmpa;i++){
    push(sa,tmpa[i]);
  }
  for(int i=1;i<lentmpb;i++){
    push(sb,tmpb[i]);
  }
  /* sa,sbջ��ջ���ǵ�λ */
  /* scջ��ջ���Ǹ�λ */
  int A=0;int B=0;
  for(int i=1;i<lenans;i++){
    A=0;B=0;
    if(!EmptyStack(sa)){
      A=Pop(sa)-'0';
    }
    if(!EmptyStack(sb)){
      B=Pop(sb)-'0';
    }
    if(A>=B){
      push(sc,A-B+'0');
    }
    else if(A<B){
      int *p=(int *)calloc(lentmpa,sizeof(int));
      int popnum=0;
      int tmp=Pop(sa)-'0';
      /* �洢��Ҫ��ѹ��ջ�е����� */
      if(tmp==0)
      	p[popnum++]=tmp+10-1;
      else if (tmp>0)
      	p[popnum++]=tmp-1;
      /* ѭ����λ,���ܴ�λΪ0���ܽ�λ��Ҫ�����Ͻ�һλ */
      while(tmp==0){
        /* ����һλ */
        tmp=Pop(sa)-'0';
        if(tmp==0)
          p[popnum++]=tmp+10-1;
        else if(tmp>0)
          p[popnum++]=tmp-1;
      }
      A=A+10;
      /* ��λ֮�����·Ż�ȥ */
      for(int j=popnum-1;j>=0;j--){
          push(sa,p[j]+'0');
      }
      push(sc,A-B+'0');
      free(p);
    }
  }
  bool flag=false;
  int i=1;
  /* scջ���Ǹ�λ */
  while(true){
    char tmp=Pop(sc);
    if(flag==false && tmp=='0'){
      continue;
    }
    else if(flag==false && tmp!='0'){
      flag=true;
    }
    ans[i++]=tmp;
    if(EmptyStack(sc)){
      break;
    }
  }
  ans[i]='\0';
  DestoryStack(sa);
  DestoryStack(sb);
  DestoryStack(sc);
  return ans;
}
char BigNumber_Reverse(char c){
  if(c=='+'){
    return '-';
  }
  else if(c=='-'){
    return '+';
  }
  return c;
}
/* a+b a-b -a+b -a-b */
/*  1   2   3    4 */
char *BigNumber_PlusAndMinus(char *a,char *b,char c){
  char *ans=NULL;
  int type=0;
  int lena=strlen(a);
  int lenb=strlen(b);
  char *tmpa=(char *)calloc(lena+1,sizeof(char));
  char *tmpb=(char *)calloc(lenb+1,sizeof(char));
  strcpy(tmpa,a);
  strcpy(tmpb,b);
  tmpa[0]=tmpb[0]='+';
  if(c=='+'){
    if(a[0]=='+' && b[0]=='+'){
      /* a+b */
      type=1;
    }
    else if(a[0]=='+' && b[0]=='-'){
      /* a-b */
      type=2;
    }
    else if(a[0]=='-' && b[0]=='+'){
      /* -a+b */
      type=3;
    }
    else if(a[0]=='-' && b[0]=='-'){
      /* -a-b */
      type=4;
    }
  }
  else if(c=='-'){
    /* a+b a-b -a+b -a-b */
    /*  1   2   3    4 */
    if(a[0]=='+' && b[0]=='+'){
      /* a-b */
      type=2;
    }
    else if(a[0]=='+' && b[0]=='-'){
      /* a+b */
      type=1;
    }
    else if(a[0]=='-' && b[0]=='+'){
      /* -a-b */
      type=4;
    }
    else if(a[0]=='-' && b[0]=='-'){
      /* -a+b */
      type=3;
    }
  }
  switch (type) {
    case 1:/*a+b*/ans=BigNumber_Plus_son(tmpa,tmpb);break;
    case 2:/*a-b*/ans=BigNumber_Minus_son(tmpa,tmpb);break;
    case 3:/*-a+b*/ans=BigNumber_Minus_son(tmpa,tmpb);ans[0]=BigNumber_Reverse(ans[0]);break;
    case 4:/*-a-b*/ans=BigNumber_Plus_son(tmpa,tmpb);ans[0]=BigNumber_Reverse(ans[0]);break;
    default:free(ans);ans=NULL;break;
  }
  return ans;
}
/* ����a*b */
/* a>0 b>0 */
char *BigNumber_Mul_son(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  int lenans=lena-1+lenb-1+1;
  char *ans=(char *)calloc(lenans+1,sizeof(char));
  char *i=NULL;char *end=NULL;char *mul=NULL;
  int CMP=BigNumber_CMP(a,b);
  if(CMP>=0){
    /* a>=b */
    i=(char *)calloc(lenb+1,sizeof(char));
    end=(char *)calloc(lenb+1,sizeof(char));
    mul=(char *)calloc(lena+1,sizeof(char));
    strcpy(end,b);end[0]='+';
    strcpy(mul,a);mul[0]='+';
  }
  else if(CMP==-1){
    /* a<b */
    i=(char *)calloc(lena+1,sizeof(char));
    end=(char *)calloc(lena+1,sizeof(char));
    mul=(char *)calloc(lenb+1,sizeof(char));
    strcpy(end,a);end[0]='+';
    strcpy(mul,b);mul[0]='+';
  }
  /* ��ʼ��ansΪ0 */
  ans[0]='+';ans[1]='0';ans[2]='\0';
  /* ��ʼ��iΪ0 */
  i[0]='+';i[1]='0';i[2]='\0';
  char *backup=NULL;
  char *backupi=NULL;
  for(;BigNumber_CMP(i,end)==-1;){
    /* ans+=mul */
    backup=ans;
    ans=BigNumber_Plus_son(ans,mul);
    free(backup);
    /* i++ */
    char tmp[3]="+1";
    backupi=i;
    i=BigNumber_Plus_son(i,tmp);
    free(backupi);
  }
  if(a[0]==b[0])
    ans[0]='+';
  else
    ans[0]='-';
  return ans;
}
char *BigNumber_Mul(char *a,char *b){
	int lena=strlen(a);
	int lenb=strlen(b);
	char *tmpa=(char *)calloc(lena+1,sizeof(char));
	char *tmpb=(char *)calloc(lenb+1,sizeof(char));
	strcpy(tmpa,a);strcpy(tmpb,b);
	tmpa[0]='+';tmpb[0]='+';
	char *ans=BigNumber_Mul_son(tmpa,tmpb);
	if(a[0]==b[0]){
		ans[0]='+';
	}
	else{
		ans[0]='-';
	}
	free(tmpa);free(tmpb);
	return ans;
}
/* ����a/b���� */
char *BigNumber_div_Integer(char *a,char *b){
  char *ans=NULL;
  int lena=strlen(a);
  int lenb=strlen(b);
  if(BigNumber_CMP(b,"+1")==0){
  	ans=(char *)calloc(lena+1,sizeof(char));
  	strcpy(ans,a);
  	return ans;
  }
  if(BigNumber_CMP(b,"-1")==0){
    ans=(char *)calloc(lena+1,sizeof(char));
  	strcpy(ans,a);
    ans[0]=BigNumber_Reverse(a[0]);
    return ans;
  }
  char *tmpa=(char *)calloc(lena+1,sizeof(char));
  char *tmpb=(char *)calloc(lenb+1,sizeof(char));
  char *tmp=(char *)calloc(lena+1,sizeof(char));
  strcpy(tmpa,a);strcpy(tmpb,b);
  tmpa[0]=tmpb[0]='+';
  char *i=(char *)calloc(lena+1,sizeof(char));
  i[0]='+';i[1]='0';i[2]='\0';
  strcpy(tmp,tmpa);
  char *backup=NULL;
  int CMP=BigNumber_CMP(tmp,tmpb);
  /* pp���ڼ��ٽ����ݴη� */
  char *pp=NULL;
  int lentmp=0;
  for(;CMP==1||CMP==0;){
    backup=tmp;
    lentmp=strlen(tmp);
    /* ��������һ���� */
    pp=(char *)calloc(20,sizeof(char));
    sprintf(pp,"+%d",(lentmp-lenb-1));
    char *backuppp=pp;
    pp=BigNumber_Power_son_Positive("+10",pp);
    if(lentmp==lenb)
      tmp=BigNumber_Minus_son(tmp,tmpb);
    else{
      char *backup2=BigNumber_Mul_son(tmpb,pp);
      tmp=BigNumber_Minus_son(tmp,backup2);
      free(backup2);
    }
    free(backup);
    CMP=BigNumber_CMP(tmp,tmpb);
    backup=i;
	  if(lentmp==lenb)
    	i=BigNumber_Plus_son(i,"+1");
    else{
      i=BigNumber_Plus_son(i,pp);
    }
    free(backup);
    free(pp);
    free(backuppp);
  }
  ans=(char *)calloc(strlen(i)+1,sizeof(char));
  strcpy(ans,i);
  if(a[0]==b[0]){
    ans[0]='+';
  }
  else{
    ans[0]='-';
  }
  free(tmp);
  free(tmpa);
  free(tmpb);
  free(i);
  return ans;
}
/* ����a/b �����ȼ��� */
char *BigNumber_div(char *a,char *b,int significant_digit){
  int cmpb=BigNumber_CMP(b,"+0");
  if(cmpb==0){
  	return " ";
  }
  int lena=strlen(a);
  int lenb=strlen(b);
  char *i=(char *)calloc(lena+1+significant_digit+20,sizeof(char));
  char *Integer=(char *)calloc(lena+1+significant_digit+10,sizeof(char));
  char *ans=(char *)calloc(lena+1+significant_digit+10,sizeof(char));
  int cmpa=BigNumber_CMP(a,"+0");
  if(cmpa==0){
  	free(i);
  	free(Integer);
  	ans[0]='+';ans[1]='0';ans[2]='\0';
  	return ans;
  }
  i[0]='+';i[1]='0';i[2]='\0';
  char *tmp=(char *)calloc((lena+1)+significant_digit+10,sizeof(char));
  char *tmpb=(char *)calloc(lenb+1,sizeof(char));
  strcpy(tmp,a);tmp[0]='+';
  strcpy(tmpb,b);tmpb[0]='+';
  int CMP=0;
  CMP=BigNumber_CMP(tmp,tmpb);
  char *backup=NULL;
  /* ������������ */
  for(;CMP==1||CMP==0;){
    backup=tmp;
    tmp=BigNumber_Minus_son(tmp,tmpb);
    free(backup);
    backup=i;
    i=BigNumber_Plus_son(i,"+1");
    free(backup);
    CMP=BigNumber_CMP(tmp,tmpb);
  }
  strcpy(Integer,i);
  int lentmp=strlen(tmp);
  int lenInteger=strlen(Integer);
  int j=0;
  /* �����ж��Ƿ����С���� */
  bool flag=true;
  /* С���������� */
  int zeronum=0;
  if(BigNumber_CMP(tmp,"+0")==1){
  	for(j=lentmp;j<(lena-1)+significant_digit+1;j++){
    	tmp[j]='0';
    	tmp[j+1]='\0';
		if(BigNumber_CMP(tmp,tmpb)==-1){
			zeronum++;
		}
  	}
  	tmp[j]='\0';
	  /* ����С������ */
	if(zeronum<significant_digit){
		CMP=BigNumber_CMP(tmp,tmpb);
	    i[0]='+';i[1]='0';i[2]='\0';
	    for(;CMP==1||CMP==0;){
	      backup=tmp;
	      tmp=BigNumber_PlusAndMinus(tmp,tmpb,'-');
	      free(backup);
	      backup=i;
	      i=BigNumber_Plus_son(i,"+1");
	      free(backup);
	      CMP=BigNumber_CMP(tmp,tmpb);
	//      printf("\r%s",tmp);
	    }
	}

  }
  else{
  	flag=false;
  }
  for(j=0;j<lenInteger;j++){
     ans[j]=Integer[j];
  }
  /* ���С���� */
  if(flag){
  	ans[j]='.';
  	for(j=lenInteger+1;j<lenInteger+1+zeronum;j++){
  		ans[j]='0';
  	}
    for(;j<lenInteger+1+significant_digit;j++){
      ans[j]=i[j-(lenInteger+1+zeronum)+1];
    }
  }
  ans[j]='\0';
  if(a[0]==b[0]){
    ans[0]='+';
  }
  else{
    ans[0]='-';
  }
  /* ���������������� */
  /* �����־�ͨ��������� */
  /* С������ */
  /* ������ƴ����һ���������ֳ��Ⱥ���Чλ����ͬ */
  free(Integer);
  free(tmp);
  free(tmpb);
  free(i);
  return ans;
}
/* ��ģ���� */
/* a mod b */
/* 0������mod */
char *BigNumber_Mod(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  //char *tmpa=(char *)calloc(lena+1,sizeof(char));
  char *tmpb=(char *)calloc(lenb+1,sizeof(char));
  char *ans=(char *)calloc(lena+1,sizeof(char));
  char *pp=NULL;
  ans[0]='+';ans[1]='0';ans[2]='\0';
  strcpy(tmpb,b);tmpb[0]='+';
  int CMP=0;
  /* a mod 1=0 */
  CMP=BigNumber_CMP(b,"+1");
  if(CMP==0){
    ans[1]='0';
    free(tmpb);
    return ans;
  }
  CMP=BigNumber_CMP(b,"+0");
  if(CMP==0){
    //free(tmpa);
    free(tmpb);
    return NULL;
  }
  CMP=BigNumber_CMP(a,"+0");
  if(CMP==0){
  //  free(tmpa);
    free(tmpb);
    return ans;
  }
  else if(CMP==1){
    strcpy(ans,a);
    CMP=BigNumber_CMP(b,"+2");
    if(CMP==0){
      ans[0]='+';
      ans[1]=a[lena-1];
      ans[2]='\0';
    }
    char *backup=NULL;
    CMP=BigNumber_CMP(ans,tmpb);
    for(;CMP==1||CMP==0;){
      backup=ans;
      int lenans=strlen(ans);
      char *backuppp=NULL;
      pp=(char *)calloc(20,sizeof(char));
      sprintf(pp,"+%d",(lenans-lenb-1));
      backuppp=pp;
      pp=BigNumber_Power_son_Positive("+10",pp);
      if(lenans==lenb)
        ans=BigNumber_PlusAndMinus(ans,tmpb,'-');
      else{
        char *backup2=BigNumber_Mul_son(tmpb,pp);
        ans=BigNumber_PlusAndMinus(ans,backup2,'-');
        free(backup2);
      }
      free(backup);
      CMP=BigNumber_CMP(ans,tmpb);
      free(pp);
      free(backuppp);
    }
    //free(tmpa);
    free(tmpb);
    return ans;
  }
  else if(CMP==-1){
    strcpy(ans,a);
    CMP=BigNumber_CMP(b,"+2");
    if(CMP==0){
      ans[0]='+';
      ans[1]=a[lena-1];
      ans[2]='\0';
    }
    char *backup=NULL;
    for(;BigNumber_CMP(ans,"+0")==-1;){
      backup=ans;
      int lenans=strlen(ans);
      char *backuppp=NULL;
      pp=(char *)calloc(20,sizeof(char));
      sprintf(pp,"+%d",(lenans-lenb-1));
      backuppp=pp;
      pp=BigNumber_Power_son_Positive("+10",pp);
      if(lenans==lenb)
        ans=BigNumber_PlusAndMinus(ans,tmpb,'+');
      else{
        char *backup2=BigNumber_Mul_son(tmpb,pp);
        ans=BigNumber_PlusAndMinus(ans,backup2,'+');
        free(backup2);
      }
      free(backup);
      free(backuppp);
      free(pp);
    }
    //free(tmpa);
    free(tmpb);
    return ans;
  }
}
/* �������ƣ�BigNumber_Power_son_Positive */
/* ����������char *a,char *b */
/* ����a^b */
/* b>=0 */
char *BigNumber_Power_son_Positive(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  int lenans=(lena+1)*(lenb+1);
  char *ans=(char *)calloc(lenans+1,sizeof(char));
  char *i=(char *)calloc(lenb+1,sizeof(char));
  i[0]='+';i[1]='0';i[2]='\0';
  ans[0]='+';ans[1]='1';ans[2]='\0';
  if(BigNumber_CMP(a,"+0")==0){
    ans[1]='0';
    free(i);
    return ans;
  }
  if(BigNumber_CMP(b,"+0")==0){//6478 1
    ans[1]='1';
    free(i);
    return ans;
  }
  char *backup;
  for(;BigNumber_CMP(i,b)==-1;){
    backup=ans;
    /* ans=ans*a */
    ans=BigNumber_Mul(a,ans);
    free(backup);
    /* i++ */
    backup=i;
    i=BigNumber_Plus_son(i,"+1");
    free(backup);
  }
  free(i);
  return ans;
}
/* �������ƣ�Fact_son */
/* ����������char *n,int i,char **p */
/* �������ܣ�����n! */
char *Fact_son(char *n,int i,char **p){
  if(BigNumber_CMP(n,"+0")==0){
    return "+1";
  }
  /* b=n-1 */
  char *b=BigNumber_Minus_son(n,"+1");
  char *ans=BigNumber_Mul_son(n,Fact_son(b,i+1,p));
  p[2*i]=b;
  p[2*i+1]=ans;
  return ans;
}
/* �������ƣ�BigNumber_Fact */
/* ����������char *n */
/* �������ܣ�����n! */
/* ����Ҫ��n��Ҫ�������λΪ����λ��Ҫ�󣬷���λ��+-��ʾ */
char *BigNumber_Fact(char *n){
  char **p=(char **)calloc((atoi(n)+1)*2,sizeof(char *));
  char *ans=Fact_son(n,0,p);
  int len=atoi(n);
  for(int i=1;i<len;i++){
    free(p[2*i]);
    free(p[2*i+1]);
  }
  free(p[0]);
  return ans;
}
/* �������ƣ�BigNumber_IsPrime */
/* ����������char *n */
/* �������ܣ��ж�n�Ƿ�Ϊ���� */
/* n>0 */
bool BigNumber_IsPrime(char *n){
  int len=strlen(n);
  char *i=(char *)calloc(len+1,sizeof(char));
  i[0]='+';i[1]='2';i[2]='\0';
  int CMP=0;
  char *I2;
  I2=BigNumber_Power_son_Positive(i,"+2");
  CMP=BigNumber_CMP(I2,n);
  free(I2);
  char *tmp=NULL;
  char *backup;
  for(;CMP==-1||CMP==0;){
    /* n mod i */
    tmp=BigNumber_Mod(n,i);
    CMP=BigNumber_CMP(tmp,"+0");
    if(CMP==0){
      return false;
    }
    I2=BigNumber_Power_son_Positive(i,"+2");
    /* �����յ���sqrt(n) */
    CMP=BigNumber_CMP(I2,n);
    free(I2);
    /* i++ */
    backup=i;
    i=BigNumber_Plus_son(i,"+1");
    free(backup);
  }
  free(i);
  return true;
}
/* ��ȡGCD(a,b)a��b�����Լ�� */
char *BigNumber_Power_Mod_Positive(char *a,char *b,char *c){
  if(BigNumber_CMP(c,"+0")<=0)
    return NULL;
  int lena=strlen(a);
  int lenb=strlen(b);
  int lenc=strlen(c);
  int lenans=(lena+1)*(lenb+1);
  char *ans=(char *)calloc(lenans+1,sizeof(char));
  char *tmpa=BigNumber_Mod(a,c);
  char *i=(char *)calloc(lenb+1,sizeof(char));
  i[0]='+';i[1]='0';i[2]='\0';
  ans[0]='+';ans[1]='1';ans[2]='\0';
  if(BigNumber_CMP(a,"+0")==0){
    ans[1]='0';
    free(i);
    return ans;
  }
  if(BigNumber_CMP(b,"+0")==0){//6478 1
    ans[1]='1';
    free(i);
    char *backup=ans;
    ans=BigNumber_Mod(ans,c);
    free(backup);
    return ans;
  }
  char *backup;
  for(;BigNumber_CMP(i,b)==-1;){
    backup=ans;
    /* ans=ans*a */
    ans=BigNumber_Mul(tmpa,ans);
    if(strlen(ans)-lenc>=20){
      char *backup=ans;
      ans=BigNumber_Mod(ans,c);
      free(backup);
    }
    free(backup);
    /* i++ */
    backup=i;
    i=BigNumber_Plus_son(i,"+1");
    free(backup);
  }
  free(i);
  backup=ans;
  ans=BigNumber_Mod(ans,c);
  free(backup);
  free(tmpa);
  return ans;
}
char *BigNumber_GCD(char *a,char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  char *ans=NULL;
  char *tmp=NULL;
  char *tmpa=(char *)calloc(lena+1,sizeof(char));
  char *tmpb=(char *)calloc(lenb+1,sizeof(char));
  strcpy(tmpa,a);strcpy(tmpb,b);
  tmpa[0]='+';tmpb[0]='+';
  int CMP=BigNumber_CMP(tmpa,tmpb);
  if(CMP==-1){
    /* tmpa<tmpb */
    char *swap=NULL;
    swap=tmpa;
    tmpa=tmpb;
    tmpb=swap;
  }
  char *backup=NULL;
  /* շת�������ȡ���Լ�� */
  do{
  	/* ����һ��freeһ�μ��� */
    /* �������� */
    tmp=BigNumber_Mod(tmpa,tmpb);
    /* ׼����һ������ */
    backup=tmpa;
    tmpa=tmpb;
    tmpb=tmp;
    free(backup);
  }while((BigNumber_CMP(tmp,"+0"))==1);
  int lentmpa=strlen(tmpa);
  ans=(char *)calloc(lentmpa+1,sizeof(char));
  strcpy(ans,tmpa);
  free(tmpa);
  free(tmpb);
  free(tmp);
  return ans;
}
/* LCM(a,b)��ȡ��С������ */
/* a>0 b>0 */
char *BigNumber_LCM(char *a,char *b){
  if(a[0]!='+'||b[0]!='+')
    return NULL;
  char *tmp=BigNumber_Mul_son(a,b);
  char *tmpgcd=BigNumber_GCD(a,b);
  char *ans=BigNumber_div_Integer(tmp,tmpgcd);
  free(tmp);
  free(tmpgcd);
  return ans;
}
/* ��a^b mod c */
/* b>=0 c>0 */
// char* BigNumber_Power_Mod(char *a,char *b,char *c){
//   if(BigNumber_CMP(c,"+0")==0)
//     return NULL;
//   int cmpa=BigNumber_CMP(a,"+0");
//   int cmpb=BigNumber_CMP(b,"+0");
//   if(cmpb==-1){
//     return NULL;
//   }
//   if(cmpa==0 && cmpb==0){
//     return NULL;
//   }
//   if(cmpa==0){
//     /* cmpa==0 cmpb!=0 */
//     char *ans=(char *)calloc(3,sizeof(char));
//     ans[0]='+';ans[1]='0';ans[2]='\0';
//     return ans;
//   }
//   if(cmpb==0){
//     /* cmpa!=0 cmpb==0 */
//     char *ans=(char *)calloc(3,sizeof(char));
//     ans[0]='+';ans[1]='1';ans[2]='\0';
//     char *backup=ans;
//     ans=BigNumber_Mod(ans,c);
//     free(backup);
//     return ans;
//   }
//   /* cmpa!=0 cmpb!=0 cmpc!=0 */
//   if(BigNumber_CMP(b,"+1")==0)
//     return BigNumber_Mod(a,c);
//   char *tmp=BigNumber_Mul(BigNumber_Power_Mod(BigNumber_Power_son_Positive(a,"+2"),BigNumber_div_Integer(b,"+2"),c),BigNumber_Power_Mod(a,BigNumber_Mod(b,"+2"),c));
//   return BigNumber_Mod(tmp,c);
// }
/* a^-1 mod b */
char *BigNumber_Mod_Reverse(char *a,char *b){
  if(BigNumber_CMP(b,"+0")<=0)
    return NULL;
  if(BigNumber_CMP(a,"+0")==0)
    return NULL;
  int lena=strlen(a);
  int lenb=strlen(b);
  char *tmpb=BigNumber_Mod(a,b);
  if(BigNumber_CMP(tmpb,"+0")==0){
  	free(tmpb);
  	return NULL;
  }
  char *tmpa=(char *)calloc(lenb+1,sizeof(char));
  char *tmp=NULL;
  char *ans=NULL;
  char *backup=NULL; 
  /* tmpa=b tmpb=a mod b */
  /* ���ڼ�¼ Atmpa + Btmpb */
  // char *A[3]={NULL};
  char *B[3]={NULL};
  strcpy(tmpa,b);
  // A[0]=BigNumber_Plus_son("+0","+1");
  B[0]=BigNumber_Plus_son("+0","+0");
  // A[1]=BigNumber_Plus_son("+0","+0");
  B[1]=BigNumber_Plus_son("+0","+1");
  // A[2]=BigNumber_Plus_son("+0","+0");
  B[2]=BigNumber_Plus_son("+0","+0");
  do{
  	/* ����һ��freeһ�μ��� */
    /* �������� */
    tmp=BigNumber_Mod(tmpa,tmpb);
    char *tmp2=BigNumber_div_Integer(tmpa,tmpb);
    // char *tmp3=BigNumber_PlusAndMinus(A[0],A[1],'-');
    char *tmp4=BigNumber_Mul(B[1],tmp2);
    // A[2]=BigNumber_Mul(tmp3,tmp2);
    B[2]=BigNumber_PlusAndMinus(B[0],tmp4,'-');
    free(tmp2);
    // free(tmp3);
    free(tmp4);
    /* ׼����һ������ */
    char *backup2[2]={NULL};
    backup=tmpa;
    // backup2[0]=A[0];
    backup2[1]=B[0];
    tmpa=tmpb;
    // A[0]=A[1];
    B[0]=B[1];
    tmpb=tmp;
    // A[1]=A[2];
    B[1]=B[2];
    /* ����ϵ�� */
    free(backup);
//    free(backup2[0]);
    free(backup2[1]);
  }while((BigNumber_CMP(tmp,"+0"))==1);
  if(BigNumber_CMP(tmpa,"+1")!=0)
    ans=NULL;
  else{
    ans=(char *)calloc(strlen(B[0])+1,sizeof(char));
    strcpy(ans,B[0]);
  }
  free(tmpa);
  if(tmpb!=NULL)
  	free(tmpb);
  if(tmp!=NULL)
  	free(tmp);
  free(B[0]);free(B[1]);free(B[2]);
  return ans;
}
#endif
