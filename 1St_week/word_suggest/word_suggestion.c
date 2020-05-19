#include<stdio.h>
#include<stdlib.h>
#include "os.h"
#include<string.h>
int main(){
	/*
	*The variable pos is used to find pointer position.
	*Varible choice is used to get the character and desion.
	*Variable size is used to know the size of  list at any time
	*Variable length is length of currrent length at any time.
	*list hass the words the can be suggested.
	*Current_list is used to reduce list of suggest using word typed.
	*word is a string which is used to find that current_list. 
	*/
	int pos=0,choice=0,size=10,length; 
	char temp,list[10][6]={"their","the","there","they","them","those","hello","hai","who","where"};
	char current_list[10][6],temp_sub_string[10];
	char *word = calloc(7,1);
	int interupt();
	/*
	*If initially arrows are press then current list should have all values.
	*/
	for(int i=0;i<size;i++)
		strcpy(current_list[i],list[i]);
	/*
	*Initally the choice will be 0 so all the words in the list will be suggested.
	*If a character is pressed the current_list will be reduced and the letter will be added to the typed word.
	*Then the current_list is reduced based the words in the string word.
	*If the size of current_list is 0 then there might be no words to suggest stop this process.
	*If there is only one word to suggest that word will be displayed. 
	*/
	do{
		if(choice>='a' && choice<='z'){
			temp = choice;
			word = strncat(word,&temp,1);
			length=0;
			for(int j=0;j<size;j++)
			{
				strncpy(temp_sub_string,list[j],strlen(word));
				if(strcmp(temp_sub_string,word)==0)
				{
					strcpy(current_list[length++],list[j]); 
				}
			}
			size=length;
			pos=0;
		}
		if(strlen(word)!=0)
			printf("Typed words is : %s\n",word);
		if(choice==2)
		{
			if(pos==size-1)
				pos=0;
			else
				pos++;
		}
		else if(choice==1)
		{
			if(pos==0)
				pos=size-1;
			else
				pos--;
		}
	/*
	*This loop will print the all suggested words with current pointer position.
	*Then inpterupt function is called and the choice value will be get from it.
	*/
	for(int i=0;i<size;i++){
		if(i==pos)
			printf("->");
		else
			printf("  ");
		printf("%s",current_list[i]);
	}
	printf("\n");
	for(int j=0;j<size;j++)
		strcpy(list[j],current_list[j]);
	if(size==0 || size ==1){
			break;
	}
	choice = interupt();
	}while(choice!=3);
	if(size!=0)
		printf("\n you have selected the word : %s\n",list[pos]);
	else
		printf("\nSorry no word to suggest ,the letters u typed is :%s\n",word);
	free(word);
	return 0;
}
/*
*The variable chr1 and chr2 is used to get input and arrow interupts.
*interupt function is used to get input from console and return an integer value based on the input type. 
*/
int interupt(){
	int chr1, chr2;
	chr1 = getch();
	if (chr1 == interuptor) //to check scroll key interrupt
	{
	chr2 = getch();  //to read arrow key
  	switch(chr2)
	{
   		case left: 
			return 1;	//If left arrow is pressed 1 will be returned. 
   		case right: 
					//If right arrow is pressed then 2 will be returned.
   			return 2;
   		default:
		   	return 0;	//If up and down arrow is pressed then 0 will be returned.
  };
 }
	else if(chr1 == 13){
 		return 3;	//If enter is pressed then 3 will be returned.
		 }
		 /*
		 *If alphabets is pressed the then its ASCII value will be returned.
		 *If upper_case letter is pressed then lower cases of the alphabet will be returned.
		 */
 	else if(chr1>='a' && chr1<= 'z'){
	 	return chr1; 	
	 }
	else if(chr1>='A' && chr1<='Z'){
		return chr1+32;
	}
}

