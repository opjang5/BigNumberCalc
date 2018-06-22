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
    char op;
	  char ans2[1024];
	  int A=rand();int B=rand();
    printf("a:");
    scanf("%s",a);
    printf("b:");
    scanf("%s",b);
    printf("operation:");
    fflush(stdin);
    scanf("%c",&op);
    A=atoi(a);
    B=atoi(b);
//    sprintf(a,"%d",A);
//	sprintf(b,"%d",B);
    switch (op) {
      case '+':sprintf(ans2,"%d",A+B);break;
      case '-':sprintf(ans2,"%d",A-B);break;
      default:continue;
    }
    int lena=strlen(a);
	  int lenb=strlen(b);
	  int lenans2=strlen(ans2);
	  if(a[0]!='-'){
	  	for(int i=lena;i>=0;i--){
	      a[i+1]=a[i];
	    }
	    a[0]='+';	
	  }
	  if(b[0]!='-'){
	  	for(int i=lenb;i>=0;i--){
	      b[i+1]=b[i];
	    }
	    b[0]='+';	
	  }
	  int CMP=BigNumber_CMP(a,b);
	  if(CMP>=0){
	  	for(int i=lenans2;i>=0;i--){
	      ans2[i+1]=ans2[i];
	  	}
	  	ans2[0]='+';	
	  }
//	  else if(CMP==-1)
	//  	ans2[0]='-';
	  printf("a:%s\n",a);
	  printf("b:%s\n",b);
	  printf("ans2:%s\n",ans2);
	  char *ans=BigNumber_PlusAndMinus(a,b,op);
	  printf("ans:%s\n",ans);
	  if(strcmp(ans,ans2)!=0){
	  	system("pause");
	  	char *ans=BigNumber_PlusAndMinus(a,b,op);
	  }
	  free(ans);
	  printf("\r    ");
	  printf("\r%.2lf%%",(double)t/10000.0f*100.0);
	  system("pause");
	  system("cls");
  }
  printf("³É¹¦\n");
  system("pause");
}
