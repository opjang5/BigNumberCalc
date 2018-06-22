#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<BigNumberCalc.h>
int main(){
  srand(time(0));
  int t=0;
  while(t<=10000){
  	  t++;
  	  char a[1024];
	  char b[1024];
	  char ans2[1024];
	  int A=rand();int B=rand();
	  sprintf(a,"%d",A);
	  sprintf(b,"%d",B);
	  sprintf(ans2,"%d",A+B);
	  int lena=strlen(a);
	  int lenb=strlen(b);
	  int lenans2=strlen(ans2);
	  for(int i=lena;i>=0;i--){
	    a[i+1]=a[i];
	  }
	  a[0]='+';
	  for(int i=lenb;i>=0;i--){
	    b[i+1]=b[i];
	  }
	  b[0]='+';
	  for(int i=lenans2;i>=0;i--){
	    ans2[i+1]=ans2[i];
	  }
	  ans2[0]='+';
	  printf("a:%s\n",a);
	  printf("b:%s\n",b);
	  printf("ans2:%s\n",ans2);
	  char *ans=BigNumber_Plus_son(a,b);
	  printf("ans:%s\n",ans);
	  if(strcmp(ans,ans2)!=0){
	  	system("pause");
	  	char *ans=BigNumber_Plus_son(a,b);
	  }
	  free(ans);
	  printf("\r    ");
	  printf("\r%.2lf%%",(double)t/10000.0f*100.0);
	  system("cls");
  }
  printf("�ɹ�\n");
  system("pause");
}
