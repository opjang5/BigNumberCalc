#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<BigNumberCalc.h>
int Mod_Reverse(int a,int b);
int main(){
  srand(time(0));
  int t=0;
  char zero[5]="+0";
  while(t<=10000){
  	  t++;
  	  char a[1024];
	  char b[1024];
      char op;
	  char ans2[1024];
	  int A=rand()+1;int B=rand()%10+1;
//	  A=15111;B=7;
	  // if(rand()%2==0){
	  // 	A=-A;
	  // }
	  // if(rand()%2==0){
	  // 	B=-B;
	  // }
//	system("cls");
//   printf("a:");
//   scanf("%d",&A);
//   printf("b:");
//   scanf("%d",&B);
    sprintf(a,"%d",A);
	sprintf(b,"%d",B);
	system("cls");
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	sprintf(ans2,"%d",Mod_Reverse(A,B));
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
	  if(ans2[0]!='-'){
	  	for(int i=lenans2;i>=0;i--){
	      ans2[i+1]=ans2[i];
	  	}
	  	ans2[0]='+';
	  }
//	  else if(CMP==-1)
	//  	ans2[0]='-';
	  char *ans=BigNumber_Mod_Reverse(a,b);
	  if(ans==NULL)
	  	ans=zero;
	  printf("c:%d\n",20);
	  printf("ans2:%s\n",ans2);
	  printf("ans:%s\n",ans);
	  if(strcmp(ans,ans2)!=0){
	  	system("pause");
	  	char *ans=BigNumber_Mod_Reverse(a,b);//15111 7
	  }
	  free(ans);
	  printf("\r    ");
	  printf("\r%.2lf%%",(double)t/10000.0f*100.0);
//	  system("pause");
  }
  printf("成功\n");
  system("pause");
}
/* a^-1 mod b */
int Mod_Reverse(int a,int b){
	int tmpb=a%b;
	if(tmpb==0){
		return 0;
	}
	int tmpa=b;
	int r=0;
	int B[3]={0};
	B[1]=1;
	do{
		r=tmpa%tmpb;
		B[2]=B[0]-B[1]*(tmpa/tmpb);
		tmpa=tmpb;
		B[0]=B[1];
		tmpb=r;
		B[1]=B[2];
	}while(r!=0);
	if(tmpa!=1){
		return 0;
	}
	else {
		if(B[0]*a%b!=1 && B[0]*a%b+b!=1){
			system("pause");
			printf("算法出现问题！");
		}
		return B[0];
	}
}
