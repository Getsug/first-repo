#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	FILE *outfile; 
	char pass[20];
	
	printf("Enter password: ");
	scanf("%s", pass);
	
	
	//create a file to store the password
	outfile = fopen("plainPass.txt", "w");
	fprintf(outfile, "%s", pass);
	fclose(outfile);
	
	
	//process to hash user password using sha256 algorithm
	int pid = fork();

	if(pid < 0)
	{
		perror("Can't create a new process!\n");
		exit(1);
	}

	if(pid == 0)
	{
		//int len = strlen(pass);
		
		char *argv[] = {"openssl", "aes-256-cbc", "-in", "plainPass.txt", "-out", "hashPass.txt",  "-a", "-salt", "-pbkdf2", "-pass", "pass:trivialmatter", NULL};
		//write(0, pass, len);
		execvp(argv[0], argv);
	}

	printf("Waiting for child process1...\n");
	wait(NULL);
	printf("child process1 done.\n");
	
	
	
	//process to decrypt customer passwords
	int id = fork();

	if(id < 0)
	{
		perror("Can't create a new process!\n");
		exit(1);
	}

	if(id == 0)
	{
		//int len = strlen(pass);
		
		char *argv[] = {"openssl", "aes-256-cbc", "-in", "hashPass.txt", "-out", "newPlainPass.txt", "-d", "-a", "-salt", "-pbkdf2", "-pass", "pass:trivialmatter", NULL};
		//write(0, pass, len);
		execvp(argv[0], argv);
	}

	printf("Waiting for child process2...\n");
	wait(NULL);
	printf("child process2 done.\n");
	
	int length = strlen("U2FsdGVkX19E02FnNTTDRYPJtXocCjE/Bzt0BupPtxU=");
	printf("%d\n", length);
	
	
	//process to delete files
	/*int id3 = fork();

	if(id3 < 0)
	{
		perror("Can't create a new process!\n");
		exit(1);
	}

	if(id3 == 0)
	{
		//int len = strlen(pass);
		
		char *argv[] = {"rm", "testfile.txt", "jj.txt", "newjj.txt" , NULL};
		//write(0, pass, len);
		execvp(argv[0], argv);
	}

	printf("removing files...\n");
	wait(NULL);
	printf("complete...\n");  */
	
	
	
	
}
