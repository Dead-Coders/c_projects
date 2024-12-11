#include <stdio.h>
#include <stdlib.h>

char fileName[20];
	
int createFile(){	
    /* file is created in current working directory */
	FILE * fptr = NULL;
	int mode = 2;
	printf("\n Enter name of file : ");
	scanf(" %s", fileName);
	
	fptr = fopen(fileName, "w");

	
if(fptr!=NULL)
fclose(fptr);

return 0;	
}

void displayFileContents(){
	FILE *fptr = fopen(fileName, "r");	
	char c;
	long int count = 0;
	printf("\n---- File Content ---- \n\n");
	while ((c = getc(fptr)) != EOF){
	putchar(c); count++;
	}
	
	if(count==0)
	printf("\n Warning: File is empty!!");
	else
	fclose(fptr);
		
}

void addInfo(){
char name[50];
unsigned char age;
getchar();
printf("\n\n Enter Name : ");
gets(name);

/* check if name already exist */
FILE* fptr = fopen(fileName, "r");
char line[500];

char alreadyExist = 0;
while (fgets(line, sizeof(line), fptr)) {
if(strstr(line, name))
alreadyExist = 1;
}

fclose(fptr);

if(alreadyExist==1)
{
	printf("\n Record already exist !!");
	printf(" %s ", line);
}
else{
fptr = fopen(fileName, "a");
fputs(name, fptr);	

printf("\n Enter Age : ");
scanf("%d",&age);

char buffage[5];
char temp[5];
strcpy(temp, " | ");

itoa(age, buffage, 10);

strcat(temp, buffage);
strcat(temp, "\n");
fputs(temp, fptr);

/* close the file */
fclose(fptr);
}

}

void calcualteAvgAge(){
FILE* fptr = fopen(fileName, "r");
char line[500];
char *ptr = NULL;
float avg = 0;	
char alreadyExist = 0;
int count =0;
while (fgets(line, sizeof(line), fptr)) {
ptr = strtok(line, "|");
ptr = strtok(NULL, "|");
avg += atoi(ptr);
count++;
}
if(count>0){
avg = avg/count;
printf("\nAverage Age is : %.2f",avg)	;
}
else{
printf("\n No data to calcualte avg age.");
}

}

void sortFileContents(){
FILE* fptr = fopen(fileName, "r");
char line[500];
float tempArr[500];
char *ptr = NULL;
int i=0, count=0;
while (fgets(line, sizeof(line), fptr)) {
count++;
ptr = strtok(line, "|");
ptr = strtok(NULL, "|");
tempArr[i++] = atoi(ptr);
}

int order=0;
printf("\n\n Press 1 for Assending order  ");
printf("\n Press 2 for Desending order : ");
scanf("%d",&order);

/* sort the Age array in Descendin order */
float temp =0;
int j;
for(i=0; i<count; i++){
	for(j=i+1; j<count;j++){
		
		if(order==2){		
		if(tempArr[j] > tempArr[i])
		{	temp=tempArr[j];
			tempArr[j] = tempArr[i];
			tempArr[i] = temp;
		}
		}
		else{
		if(tempArr[i] > tempArr[j])
		{
			temp=tempArr[j];
			tempArr[j] = tempArr[i];
			tempArr[i] = temp;
		}	
		}
		
	}
}

for(i=0; i<count; i++){
rewind(fptr);
while (fgets(line, sizeof(line), fptr)) {
float temp=0;
char tempLine[500];
memset(tempLine, NULL, sizeof(tempLine));
strcpy(tempLine, line);
ptr = strtok(line, "|");
ptr = strtok(NULL, "|");
temp = atoi(ptr);

if(temp == tempArr[i]){
	printf("\n %s", tempLine);
	break;
}

}
}
	
}

void removePerson(char *nameptr){
printf("\n --- Remove Person from Records ---");
char name[50];
memset(name, NULL, sizeof(name));

if(nameptr==NULL){
printf("\n\n Enter Name : ");
getchar(); gets(name);
}
else
strcpy(name, nameptr);

FILE* fptr = fopen(fileName, "r");

if(fptr==NULL){
	printf("\n Error: No record exist");
	return;
}

char temp[]="temp";
//file mode should be same as bas file
FILE* fptrTmp = fopen(temp, "w");
if(fptrTmp==NULL){
	printf("\n Error: Unable to perform this operation");
	return;
}

char line[500];
int count =0;
while (fgets(line, sizeof(line), fptr)) {
if(strstr(line, name)){
	//don't copy it
	count++;
	
	printf("\n---debug: name matched line is : %s",line);
	memset(line, NULL, sizeof(line));
	continue;
}
else{
fputs(line, fptrTmp);		
printf("\n putting : %s in new file", line);
}
memset(line, NULL, sizeof(line));
}

fclose(fptrTmp); 
fclose(fptr);

if(count>0){
printf("fileName : %s removed ", fileName);	

if(remove(fileName) == 0)
printf("\n File %s is deleted successfully", fileName);
else
printf("\n Error while deleting file %s ", fileName);

getchar(); getchar();
rename(temp, fileName);
printf("\n Success ! Reocrd found & deleted");
}
else{
printf("\n Error: Record not found");
}
remove(temp);	
}

void correctInfo(){
/* create a temporary file */
FILE* fptr = fopen(fileName, "r");

if(fptr==NULL){
	printf("\n Error: No record exist");
	return;
}

char temp[]="temp1";
char line[500];
//file mode should be same as bas file
FILE* fptrTmp = fopen(temp, "w");
while (fgets(line, sizeof(line), fptr)) {
fputs(line, fptrTmp);		
//printf("\n putting : %s in new file", line);
memset(line, NULL, sizeof(line));
}
fclose(fptrTmp); 
fclose(fptr);
	
	
fptrTmp = fopen(temp, "r");

float tempArr[500];
char *ptr = NULL;
char name[50]; 
memset(name, NULL, sizeof(name));

int i=0, count=0;
char choice='\0';
memset(line, NULL, sizeof(line));
while (fgets(line, sizeof(line), fptr)) {
count++;
printf("\n %s ", line);

printf("\n Do u want to update this record? y/n :");
scanf(" %c",&choice);

if(choice=='y'){
ptr = strtok(line, "|");
strcpy(name, ptr);
removePerson(name);
printf("\n\n Please enter new values  ");
addInfo();
break;
}
}
close(fptr);
}
				
void menu(){
	char choice = -1;
	
	while(choice!=8){
		printf("\n\n\n #### Main Menu  ####\n\n");
		printf("\n 1. File creation");
		printf("\n 2. Display the contents of the file");
		printf("\n 3. Add Info to file");
		printf("\n 4. Age average calcualtion");
		printf("\n 5. Sort file contents");
		printf("\n 6. Person removal");
		printf("\n 7. Correctness information analysis");
		printf("\n 8. End program");
		
		printf("\n\n Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:  
				if(createFile() == 0) 
				printf("\n Success : File created successfully!");
				else
				printf("\n Error: Can't create file'");
			break; 
			case 2: 
				displayFileContents();
			break;
			case 3:
				addInfo();
			 break;
			case 4: 
				calcualteAvgAge();
			break;
			case 5:
				sortFileContents();
			 break;
			case 6: 
				removePerson(NULL);
			break;
			case 7: 
				correctInfo();
			break;
			case 8: printf("\n thanks for using the application \n ");
			default: printf("\n Error: Invalid Choice! Enter again");
			         getchar();			        
		}
	}
		
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}