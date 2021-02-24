#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <sys/times.h>  // for tms struct
#include <sys/types.h>  // for time type, etc.
#include <math.h>       // for sqrt()
#include <unistd.h>     // for sysconf()

//Calculate factorial recursively
double rfact(double number);

//Call factorial a lot
void child1 (double num);



int main()
{
  //User input
  int N;

  //Check for non number input

  //Prompt user for number, get number
  printf("Please enter a number: ");
  scanf("%d", &N);

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

  //Greeting with process id	
  printf("Hello, from Child1! My PID is: %d\n", getpid());

  int i = 0;

  //Call factorial calculation 4 million times.
  while (i < 4000000)
  {
    rfact(num);
    i++;
    
  }

  //Get current runtime in user mode
  

  //Goodbye with time and process id	
  printf("Goodbye, from Child1. That took <<RUNTIME>> seconds. My PID is: %d\n", getpid());

}
