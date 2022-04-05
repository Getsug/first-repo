#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void logoDisplay();


int main()
{
	system("clear");    //clear everything in terminal
	
	logoDisplay();

}


void logoDisplay()
{
	
	printf("\n\n\n");
	
    int pid = fork();

    if(pid < 0)
    {
        perror("Creation of a new process is unsuccessful!\n");
        exit(1);
    }

    if(pid == 0)
    { 
        execlp("figlet", "figlet", "-c", "-k", "-t","MAZE BANK", NULL);
    }

    wait(NULL);
   


    char flower[8][50] = {	"	                           .-. .-.			",
     						"	                          (   |   )			",
     						"	                        .-.:  |  ;,-.		",
     						"	                       (_ __`.|.'__ _)		",
     						"	                       (    .'|`.    )		",
     						"	                        `-'/  |  \\`-'		",
     						"	                          (   !   )			",
     						"	                           `-' `-'			"
     					};
    
		
	
	printf("\n\n");
	
	for(int i = 0; i < 8; i++)
	{
		printf("%s\n", flower[i]);
	}
	
    sleep(20);

    //system("clear"); //clear the terminal
}







