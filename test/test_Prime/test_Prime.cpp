#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<BigNumberCalc.h>
#include<math.h>
bool Prime(int n);
int main(){
  srand(time(0));
  int t=0;
  while(t<10000){
  	  t++;
  	  char a[1024];
	  char b[1024];
      char op;
	  char ans2[1024];
	  int A=t;
	  // B=1;
	  // if(rand()%2==0){
	  // 	A=-A;
	  // }
	  // if(rand()%2==0){
	  // 	B=-B;
	  // }
//	  system("cls");
//    printf("a:");
//    scanf("%d",&A);
    // printf("b:");
    // scanf("%d",&B);
    sprintf(a,"%d",A);
//	  sprintf(b,"%d",B);
	  sprintf(ans2,"%s",Prime(A)?"true":"false");
      int lena=strlen(a);
//	  int lenb=strlen(b);
//	  int lenans2=strlen(ans2);
	  if(a[0]!='-'){
	  	for(int i=lena;i>=0;i--){
	      a[i+1]=a[i];
	    }
	    a[0]='+';
	  }
	  // if(b[0]!='-'){
	  // 	for(int i=lenb;i>=0;i--){
	  //     b[i+1]=b[i];
	  //   }
	  //   b[0]='+';
	  // }
	  // if(ans2[0]!='-'){
	  // 	for(int i=lenans2;i>=0;i--){
	  //     ans2[i+1]=ans2[i];
	  // 	}
	  // 	ans2[0]='+';
	  // }
//	  else if(CMP==-1)
	//  	ans2[0]='-';
    char ans[10];
    system("cls");
	printf("%s\n",a);
//	if(A==15){
//		system("pause");
//	}
    if(BigNumber_IsPrime(a)){
      strcpy(ans,"true");
    }
    else{
      strcpy(ans,"false");
    }
	  printf("a:%s\n",a);
	  // printf("b:%s\n",b);
	  printf("ans2:%s\n",ans2);
	  printf("ans:%s\n",ans);
	  if(strcmp(ans,ans2)!=0){
	   	system("pause");
	   	Prime(A);
	   	BigNumber_IsPrime(a);//9288 12
	   }
	   // free(ans);
	  printf("\r    ");
	  printf("\r%.2lf%%",(double)t/10000.0f*100.0);
	  //system("pause");
  }
  printf("³É¹¦\n");
  system("pause");
}
bool Prime(int n){
  int end=pow((double)n,0.5)+1;
//  printf("%d:%d\n",n,end);
  for(int i=2;i<end;i++){
    if(n%i==0){
//      printf("%d:%d\n",n,i);
//      system("pause");
      return false;
    }
  }
  return true;
}
