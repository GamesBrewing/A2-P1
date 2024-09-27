#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Starting shield power level
int shield_power = 50;  

int main() {
    
    pid_t pid;

    pid = fork();

    //printf("Millennium Falcon: Initial shield power level: %d%%\n\n", shield_power);

    // Create 4 child processes - 4 different characters adjusting shield power

            // Luke increases the shield power by 25
            // Han increases the shield power by 20
            // Chewbacca increases the shield power by 30
            // Leia increases the shield power by 15
    if (pid < 0) {    // Check if process creation failed
        printf("Fork failed.\n");
        return 1;
    } else if (pid == 0) { //child process
       int n = 1;
       printf("Millennium Falcon: Initial shield power level: %d%%\n\n", shield_power);
       while (n<=4)
        {
        switch(n)
        {
            case 1:
            printf ("Luke: Adjusting shields...\n");
            shield_power = 75;
            printf ("Shield power level now at %d%%\n", shield_power);
            break;
            case 2:
             printf ("Han: Adjusting shields...\n");
            shield_power = 70;
            printf ("Shield power level now at %d%%\n", shield_power);
            break;
            default:
            break;
        }       

        n +=1;
        }
        } else if (pid>0){
        // Parent process
        printf("\nFinal shield power level on the Millennium Falcon: %d%%\n", shield_power);
        printf("\nMay the forks be with you!\n");

        // Wait for child
        wait(NULL);  
    }
    


       

    // Make parent process wait for all child processes to complete
    

    // Parent process reports final state
    //printf("\nFinal shield power level on the Millennium Falcon: %d%%\n", shield_power);
    //printf("\nMay the forks be with you!\n");
    return 0;
}
