#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convertgrade(char x){//this function returns the point a grade carries
//next line of action would be to introduce arrays scan grades int a char array, return the integer value of grade to a variable which would now multiply the no of units of the course also scanned into unit array. tomorrow morning unfailingly.
//char letter;
	switch (x){
    	case 'a'://sth called fallthrough instead of using the or logical operator
    	case 'A':
        	return 5;
    	break;
    	case 'b':
    	case 'B':
        	return 4;
    	break;
    	case 'c':
    	case 'C':
        	return 3;
    	break;
    	case 'd':
    	case 'D':
        	return 2;
    	break;
    	case 'e':
    	case 'E':
        	return 1;
    	break;
    	case 'f':
    	case 'F':
        	return 0;
    	break;
    	default :
        	printf("please enter a value between a to f");
}
}
//gpa function
double calcgpa(double tcredu,double tqualu){
	double gpa;
	gpa=tqualu/tcredu;
	return gpa;
}
//cgpa function
double calccgpa(double tcredall,double tqualall){
	double cgpa;
	cgpa=tqualall/tcredall;
	return cgpa;
}

int check(char *answer){//use strcmp for string
	if(strcmp (answer,"new")==0){
    	return 2;
	}
	else if(strcmp(answer,"yes")==0){
    	return 5;
	}
	else if(strcmp (answer,"find")==0){
    	return 4;
	}
	else if(strcmp(answer,"done")==0){
    	return 6;
	}
	else if(strcmp(answer,"again")==0){
    	return 3;
	}
	else {
    	return 0;
	}
}

//function to check if input is a digit
int checkdigit(char *semstr){
int retval[100];   //returnvalue from isdigit
int x;
int store;
char reply[4];
int length=strlen(semstr);

for(int i=0;i<length;i++){
	retval[i]=isdigit(semstr[i]);
	if(retval[i]!=0){
	x+=retval[i];
	}
	else{
	return 0;
	break;  //if the function returns 0, then the input is invalid. if it enters greater than 0, then the digits are indeed digits.
	}
}
return x;
}



int checkalpha(char *word){
int retval[100];   //returnvalue from isdigit
int y;
int length=strlen(word);
	if(length != 1){return 0;
	}//if more than one character is entered, invalid input
  	for(int i=0;i<1;i++){
    	retval[i]=isalpha(word[i]);
        	if(retval[i]!=0){
            	if( (word[0]>='a' && word[0]<='f') || (word[0]>='A' && word[0]<='F')){
            	y+=retval[i];
            	}
        	}
        	else{
            	return 0;
            	break;  //if the function returns 0, then the input is invalid. if it enters greater than 0, then the digits are indeed digits.
        	}
  	}
return y;
}

int checkans(int numb){
char ans[10];
int g;
do{
	if(numb==5 || numb==6 || numb==4)
	{
  	return numb;
	}
	else
	{
  	printf("invalid input. Please enter a valid one.\n");
  	scanf(" %s",ans);
  	numb=check(ans);
  	g=2;
	}
  }while(g==2);

}




int main(void){

char ans[7];
int count;
int noc[1000];//no of courses
int semno[1000];//current semester no
double tquforall;//total quality units for all semesters
double tcuforall;//total credit units for all semesters
int semval;//semester number that is bein searched for
int answer;//
double gpaval[1000];
double cgpaval[1000];//arrays to store gpa and cgpa
int ah;
char semnoo[4];
char noco[4];
int lensem; //length of semester no string
int lennoc;//lenth of no of courses string
int a;
int b;
int replya;
int replyb;
int replyg;
int replyu;
int startloop;
char grade[10];
int u;
char unit[100];
int g;
int h;
int temp;
int cumnoc;
int countA;
int countB;
int countC;
int countD;
//int countF;
//use boolean variable startloop= true || so ask question y
printf("\nDo you wish to begin? 'yes' or 'no':  ");
scanf("\n%s",ans);
h=check(ans);
if(h==5){
	startloop=0;
	}
else{
	return 0;
	}
while(startloop==0 || ah==5 ){
//nth semester//remember to add 1 when u want to reference in future
//check if it's a digit

do{
   printf("\nplease enter semester number:");
   scanf("%s",semnoo);
   a=checkdigit(semnoo);
	if(a==0){
    	printf("Invalid input.");
    	replya=5;
	}
	else{
	semno[count]=atoi(semnoo);//TO FIGURE OUT:WHY IS IT SHOWING CURRENT SEMESTER'S GPA AND CGPA INSTEAD OF THE ONE TO BE FOUND -------working now
	replya=1;
	}
  }while(replya==5);


//for number of courses for that semester
do{
   printf("Please enter a valid number of courses:\n");
   scanf("%s",noco);
   b=checkdigit(noco);
   if(b==0){
    	printf("Invalid input.");
    	replyb=3;
    	}
	else{
    	noc[count]=atoi(noco);
    	replyb=1;
    	}
  }while(replyb==3);

int partsem;//no of courses for this particular semester
partsem=noc[count];
cumnoc = cumnoc+partsem; //cummulative no of courses

char grades[partsem+1];
int val=0;//must reinitialise each semester
int units[10000];
int i;
int qualunit;
double tcuforsem=0.00;//total quality units for semester
double tquforsem=0.00;//total credit units for semester

 for(i=0;i<partsem;i++){
   do {
  	printf("please enter the grade:\n");
  	scanf("%s",grade);//the space b4 the percentage c  will allow it to run well
  	replyg=checkalpha(grade);//checking if it's an alphabet
    	if(replyg==0){
    	printf("invalid input.Please enter a valid answer.\n");
    	g=1;
    	}
    	else{
    	strcpy((grades+i),grade);
    	g=2;
    	}
  	}while(g==1);
	}

for(i=0;i<partsem;i++){
 do{
  	printf("\nplease enter the unit:\n");
  	scanf(" %s",unit);
  	replyu=checkdigit(unit);

  	if(replyu==0){//hmm
    	printf("Invalid input.Please enter a valid input:\n");
    	u=1;
  	}
  	else{
       	units[i]=atoi(unit);
       	u=2;
  	}

   }while(u==1);
}

for(i=0;i<partsem;i++){
   tcuforsem= tcuforsem+units[i];
   tcuforall=tcuforall+units[i];
   //tcuforall here stores the cummulative total credit units for all semesters
   val=convertgrade(grades[i]);
   switch(val){ //to take note of number of each grade so far
    	case 5:
    	countA++;
    	break;
    	case 4:
    	countB++;
    	break;
    	case 3:
    	countC++;
    	break;
    	case 2:
    	countD++;
    	break;
    	default:
    	countD++;
    	}
   qualunit= units[i]*val;
   tquforsem=tquforsem + qualunit;
   tquforall=tquforall + qualunit;
   //tquforall here stores the cummulative total quality units for all semesters
}

gpaval[count]=calcgpa(tcuforsem,tquforsem);
cgpaval[count]=calccgpa(tcuforall,tquforall);
//printf("number of courses registered in this semester is %d\n",noc[count]);
printf("current semester is %d\n",semno[count]);
printf("the cummulative quality unit at semester%d is %.2f\n",semno[count],tquforall);
printf("the cummulative credit unit at semester%d is %.2f\n",semno[count],tcuforall);
//no of semesters so far would be value of count+1
//
printf("gpa for this semester is %.2f\n",gpaval[count]);
printf("the current cgpa at this semester is %.2f\n",cgpaval[count]);
printf("To calculate new semester gpa and cgpa,enter 'yes'.\n To search for semester result, enter 'find'.\n To exit the program, enter 'done'.\n");
scanf("%s",ans);

temp=check(ans);//function of this is to return a corresponding integer
ah=checkans(temp);


while(ah==4){
	printf("\nPlease enter semester number:");
	scanf("%d",&semval);//semester no entered after calc
   if(semval>count+1){
 	printf("this semester has not been entered.\n\n");
 	printf("please enter 'yes' to calculate new semester gpa and cgpa,'find' to search for another semester or 'done' to exit the program\n");
 	scanf(" %s",ans);
 	temp=check(ans);
 	ah=checkans(temp);//to see if it's a valid word
	}//to check if the semester even exists

	else{
 	printf("the gpa at semester %d is %.2f\n",semval, gpaval[semval-1]);//issue sigh
 	printf("the cgpa at semester %d is %.2f\n",semval, cgpaval[semval-1]);
 	printf("please enter 'yes' to calculate new semester gpa and cgpa, 'find' to search for another semester or 'done' to exit the program\n\n");
 	scanf(" %s",ans);
 	temp=check(ans);
 	ah=checkans(temp);
}
}

if(ah==6){
	break;  //this is to leave the loop  and program once done is entered
	}
startloop=1;
count++;

}//end of loop statement

printf("\n\n You have calculated for %d semester(s)",count+1);
printf("\n\n Total number of courses taken so far is %d",cumnoc);
printf("\n\n Total number of units so far is %.2f",tcuforall);
printf("\n\n No of As so far is %d",countA);
printf("\n\n No of Bs so far is %d",countB);
printf("\n\n No of Cs so far is %d",countC);
printf("\n\n No of Ds and below so far is %d",countD);
//printf("startloop is %d",startloop);
return 0;
}


