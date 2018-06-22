#include<stdio.h>
#include<BigNumberCalc.h>
/* 内存清理 */
char *Fact(char *n){
  if(BigNumber_CMP(n,"+0")==0){
    return "+1";
  }
  char *backup[]={NULL};
  /* b=n-1 */
  char *b=BigNumber_Minus_son(n,"+1");
  char *ans=BigNumber_Mul_son(n,Fact(b));
  return ans;
}
int main(){
  int t=0;
  while(t<10000){
  	  t++;
  	  char n[1024];
	  printf("请按照格式输入n:");
	  scanf("%s",n);
	//  char *ans=Fact(n);
	//  printf("%s!=%s\n",n,ans);
	  printf("%s!=%s\n",n,BigNumber_Fact(n)); 
	  system("pause");
  }
  
}
