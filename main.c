/*
  California University of Pennsylvania
  CSC 400 Operating Systems
  Spring 2021  
  Kiana Savage, Jeremy Mwangelwa
  sav1976@calu.edu mwa2711@calu.edu
  
*/

#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <time.h>
#include <sys/times.h>  // for tms struct
#include <sys/types.h>  // for time type, etc.
#include <unistd.h>     // for sysconf()

//Calculate factorial recursively
double rfact(double number);

//Call factorial a lot
void child1 (double num);



int main()
{
  //User input
  int N;

		
  
  //Prompt user for number, get number
  printf("Please enter a number: ");
  scanf("%d", &N);  
  
  //!!Needs to error-check for characters and negative numbers!!

  //Pass number to child
  child1(N);

	return 0;
}

//Calculate factorial recursively
double rfact(double number)
{  
  //Factorial of 1 or less is 1
  if (number <= 1)
  {    
    return 1;
  }
  
  //Calculate factorial
  return number * rfact(number - 1);
}


//Calls factorial a lot
void child1 (double num)
{
  //Store process times
  struct tms mytimes; 

  //time(&t1);

  //CPU clock ticks
  int clock_ticks;
  clock_ticks = sysconf(_SC_CLK_TCK);  

  //Greeting with process id	
  printf("Hello, from Child1! My PID is: %d\n", getpid());

  int i = 0;

  //Call factorial calculation 4 million times.
  while (i < 4000000)
  {
    rfact(num);
    i++;
    
  }

  // go get process times, with error-checking
    if (times(&mytimes) == -1) {
        perror("error calling times()");
        exit(-1);
    }

  
  //Goodbye with time and process id	
  printf("Goodbye, from Child1.My PID is: %d\n", getpid());
  printf("I used %.2f seconds of user time.\n", (float)mytimes.tms_utime / clock_ticks);

}
