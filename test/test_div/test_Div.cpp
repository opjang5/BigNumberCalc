#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<BigNumberCalc.h>
#include<math.h>
int strcmp2(char *a,char *b); 
int main(){
  srand(time(0));
  int t=0;
  while(t<100){
  	  t++;
  	  char a[1024];
	  char b[1024];
      char op;
	  char ans2[1024];
	  int A=rand();int B=rand();
	  // if(rand()%2==0){
	  // 	A=-A;
	  // }
	  // if(rand()%2==0){
	  // 	B=-B;
	  // }
//	system("cls");
//    printf("a:");
//    scanf("%d",&A);
//    printf("b:");
//    scanf("%d",&B);
    sprintf(a,"%d",A);
	sprintf(b,"%d",B);
	sprintf(ans2,"%.2lf",(double)A/B);
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
	  char *ans=BigNumber_div(a,b,3);
	  system("cls");
	  printf("a:%s\n",a);
	  printf("b:%s\n",b);
	  printf("ans2:%s\n",ans2);
	  printf("ans:%s\n",ans);
	  if(strcmp2(ans,ans2)!=0){
	  	system("pause");
	  	char *ans=BigNumber_div(a,b,3);//9288 12
	  }
	  free(ans);
	  printf("\r    ");
	  printf("\r%.2lf%%",(double)t/100.0f*100.0);
//	  system("pause");
  }
  printf("�ɹ�\n");
  system("pause");
}
int strcmp2(char *a,char *b){
	double af=atof(a);
	double bf=atof(b);
	if(fabs(af-bf)<0.01){
		return 0;
	}
	return -1;
}
