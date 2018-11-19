#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  
  printf("initial parent fork\n");
  
  int d = fork();
  int status1;
  int pidone = wait(&status1);
  if (!d){
    printf("first child pid: %d\n", getpid());
    int sleeptime1 = rand()%16 + 5;
    sleep(sleeptime1);
    printf("%d finished sleeping for %d seconds\n", getpid(), sleeptime1);
    
    return sleeptime1;
  }
  printf("waited for %d for %d seconds\n", pidone, WEXITSTATUS(status1));
  
  printf("\nsecond parent fork\n");
  
  int e = fork();
  int status2;
  int pidtwo = wait(&status2);
  if (!e){
    printf("second child pid: %d\n", getpid());
    int sleeptime2 = rand()%16 + 5;
    sleep(sleeptime2);
    printf("%d finished sleeping for %d seconds\n", getpid(), sleeptime2);
    
    return sleeptime2;
  }
  printf("waited for %d for %d seconds\n", pidtwo, WEXITSTATUS(status2));

  return 0;
}
