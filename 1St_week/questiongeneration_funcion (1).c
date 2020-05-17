#include<stdlib.h>
#include<stdio.h>
#include<string.h>
static char names[9][10] = {"Sam","Hari","Ben","West","Allen","Dhinesh","John","kevin","Wilson"};
static char words[8][10] = {"Mangos","Rupees","Apples","Balls","Pens","Pencils","Oranges","Toys"};
static char pronoun[3][5] = {"has","have","had"};
static char second_pronoun[5][8] = {"gives","borrows","gets","takes","brings"};
int generate_question(){
	int a,b,c,solution;
	a = rand()%30;
	b = rand()%10;
	c = rand()%10;
	while(a<=10) // to fix non zero positive value to a
		a = rand()%30;
	while(b<=0) // to fix b with non zero positive value
		b = rand()%10;
	while(c<=0) 
		c = rand()%10;
	char first_person[10],object[10],sp[7];
	strcpy (first_person,names[rand()%9]);
	strcpy (object,words[rand()%8]);
	strcpy(sp,second_pronoun[rand()%5]);
	printf("%s %s %d %s,%s ",first_person,pronoun[rand()%3],a,object,names[rand()%9]);
	if((strcmp(sp,"gives")==0)||(strcmp(sp,"brings")==0)){
		solution = a+b;
		printf("%s %d more and",sp,b);
	}
	else{
		solution = a-b;
		printf("%s %d from %s and",sp,b,first_person);
	}
	printf(" %s ",names[rand()%9]);
	strcpy(sp,second_pronoun[rand()%5]);
	if((strcmp(sp,"gives")==0)||(strcmp(sp,"brings")==0)){
		solution += c;
		printf("%s %d more",sp,c);
	}
	else{
		solution -=c;
		if(solution>=0)
			printf("%s %d from %s",sp,c,first_person);
		else{
			printf("%s %d from %s",sp,(solution-1),first_person);
		}
	}
	printf(".How many %s is %s left with?",object,first_person);
	return solution;
}

