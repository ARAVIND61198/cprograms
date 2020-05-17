#include<stdio.h>
int main(){
	int solution,answer,choice,score=0,number_of_question=0;
	extern int generate_question(); //declaration of funtion which genetares random questions
	do{	
		number_of_question++;
		solution = generate_question(); // solution of the displayed question will be returned 
		scanf("%d",&answer); 
		if(solution == answer)
		{
			score++;
			printf("\nCONGRATULATIONS YOUR RIGHT!!");
		}
		else if((answer>=solution-2)&&(answer<=solution+2))
			printf("\nTRY HARD! YOUR CLOSE TO THE ANSWER");
		else
			printf("\nSORRY! WRONG ANWER");
		printf("\n PRESS 1 TO CONTINUE/ 0 TO EXIT \t ");
		scanf("%d",&choice);
	}while(choice); //loop is carried using users choice
	printf("\nYOU HAVE ANSWER %d OF %d QUESTIONS",score,number_of_question);
	return 0;
}
