#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float fx,fy;
int err=0;
int a[2][2] ={{0,0},{0,0}};
int b[2]={0,0};
int main()
{
	void string_reader();
	string_reader();
	if(err)
		printf("RESULT cannot be DETERMINED\n");
	else
		printf("X = %.3f\t Y = %.3f",fx,fy);
}
void string_reader(){
	void matrix();
	int nbit,i,temp=0,eqlbit=1,z;
	char c,*cpeqn = (char*) malloc(60*1);
	for(int j=0;j<2;j++){
	printf("ENTER THE %d st/nd LINER EQUATION\t",(j	+1));
	scanf("%c",&c);
	z=0;
	do{
		if(c!=' ')
			cpeqn[z++] = c;
		scanf("%c",&c);
	}while(c!='\n');
	i=0;
	eqlbit=1;
	nbit=1;
	while(i<z){
		if(cpeqn[i]=='-' && temp==0)
			nbit *= -1;
		else if(cpeqn[i]=='-' && temp!=0)
		{
			b[j] = temp*nbit*eqlbit*-1;
			temp=0;
			nbit=-1;
		}
		else if(cpeqn[i]=='x'||cpeqn[i]=='X'){
			if(temp==0)
			{
				temp=1;
			}
			a[j][0]=nbit*temp*eqlbit;
			nbit=1;
			temp=0;
		}
		else if(cpeqn[i]=='y'||cpeqn[i]=='Y'){
			if(temp==0)
			{
				temp=1;
			}
			a[j][1] = nbit*temp*eqlbit;
			nbit=1;
			temp=0;
		}
		else if((cpeqn[i]=='=' || cpeqn[i]=='+')&&(b[j]==0))
		{
			b[j] = temp*nbit*-1*eqlbit;
			nbit=1;
			temp=0;
			if(cpeqn[i]=='=')
				eqlbit=-1;
		}
		else if(cpeqn[i]=='-' && b[j]==0){
			b[j] = temp*nbit*-1*eqlbit;
			nbit=-1;
			temp=0;
		}
		else if(cpeqn[i]!='+' && cpeqn[i]!='='){
			temp= (temp*10)+(cpeqn[i]-'0');
		}
		if(cpeqn[i]=='=')
			eqlbit=-1;
		i++;
//		if(temp!=0)
//		printf("%d \t %c temp\n",temp,cpeqn[i-1]);
	}
	if(temp!=0)
	{
		b[j] = temp*nbit*-1*eqlbit;
		nbit=1;
		temp=0;  
	}
}

	matrix();
	
}
/*
* determinant of matrix is found 
* A * X = B
* so X = A^-1 *B 
* where A^-1 = (1/|A|)* A^T
* used to solve linear equa 
*/
void matrix(){
	int det = (a[0][0] *a[1][1] )- (a[0][1] *a[1][0]);
//	printf("%d",det);
	if(det==0)
		err=1;
	else{
	fx = ((float)(a[1][1] * b[0] + a[0][1]*-1 * b[1]))/(float)det;
	fy = ((float)(a[1][0] * -1 *b[0] + a[0][0] * b[1])) / (float)det;
		
	}
}
