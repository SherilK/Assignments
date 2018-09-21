// ConsoleApplication29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
	char *UserName;
	char *firstName;
	char *lastName;
	char *displayName;
	char *jobTitle;
	char *department;
	char *officeNumber;
	char *officePhone;
	char *mobilePhone;
	char *fax;
	char *address;
	char *city;
	char *state;
	char *zip;
	char *country;
} contact;

FILE *openfile(char*fileName, char*mode);
void closeFile(FILE*fptr);

void printContact(contact *theContact[]);

int main()
{
	FILE *fptr;
	char delimiter[10] = "\,";
	char *token;
	//contact *ptr;
	int x = 10;
	char line[300];
	int i = 0;
	int j=0;
	int k,p;
	int h = 0;
	char test[130][50];


	fptr = openfile("F:\\mycontacts.txt", "r");

	if (fptr == NULL)
	{
		printf("File could not be opened000 !!\n");
	}
	//circle * moreCircles = (circle *)malloc(x * sizeof(circle));


	contact *ptr[5];
	for (k = 0; k < 5; k++)
	{
		*(ptr + k) = (contact*)malloc(x * sizeof(contact));
	}

	fgets(line, 300, fptr);

	
		fgets(line, 300, fptr);
		
		for (h = 0; h != 5; h++)
		{
			//while (!feof(fptr))
			//{
				token = strtok(line, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->UserName = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->firstName = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->lastName = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->displayName = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->jobTitle = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->department = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->officeNumber = test[i];
				i++;


				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->officePhone = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->mobilePhone = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->fax = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->address = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->city = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->state = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->zip = test[i];
				i++;

				token = strtok(NULL, delimiter);
				if (token != NULL)strcpy(test[i], token);
				ptr[j]->country = test[i];
				i++;
				j++;

				fgets(line, 300, fptr);

			//}
		}
	

	printContact(ptr);
	closeFile(fptr);
}

FILE *openfile(char *fileName, char*mode)
{
	FILE *fptr = fopen(fileName, mode);
	if (fptr == NULL)
	{
		printf("Error opening file!000\n");
	}
	return fptr;
}

void closeFile(FILE*fptr)
{
	fclose(fptr);
}


void printContact(contact *theContact[])
{
	int y;
	for (y = 0; y < 5; y++)
	{
		printf(" User name: %s \n", theContact[y]->UserName);
		printf(" First name: %s \n", theContact[y]->firstName);
		printf(" Last name: %s \n", theContact[y]->lastName);
		printf(" Display name: %s \n", theContact[y]->displayName);
		printf(" Job title: %s \n", theContact[y]->jobTitle);
		printf(" Department: %s \n", theContact[y]->department);
		printf(" Office Number: %s \n", theContact[y]->officeNumber);
		printf(" Office Phone: %s \n", theContact[y]->officePhone);
		printf(" Mobile Phone: %s \n", theContact[y]->mobilePhone);
		printf(" Fax: %s \n", theContact[y]->fax);
		printf(" Address: %s \n", theContact[y]->address);
		printf(" City: %s \n", theContact[y]->city);
		printf(" State: %s \n", theContact[y]->state);
		printf(" ZIP: %s \n", theContact[y]->zip);
		printf(" Country:%s \n", theContact[y]->country);
		printf("\n");
	}
	
}

