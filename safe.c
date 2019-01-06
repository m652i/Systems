#include 	"safeBustersHeaders.h"

int		pgrmruns = 1;
int		safeopened = 0;
int		firstnum;
int		secondnum;
int		thirdnum;
pid_t		crackingThief; //gotta set it up here

void		 SIG_QUIT_HANDLER	(int signum)
{
  pgrmruns = 0; //stops program
}




int		computeResponse		(int* countPtr) //FREE CODE YAAY
{
  int	toReturn;

  sleep(1);
  (*countPtr)--;

  if  (*countPtr == 0)
  {
    printf("Safe \"Click!\"\n");
    toReturn	= SIG_RIGHT_DIGIT;
  }
  else
  {
    printf("Safe \"Clic...NOT!\"\n"); //nah
    toReturn	= SIG_WRONG_DIGIT;
  }

  return(toReturn);
}



void 		SIG_TRY_NEXT_DIGIT_HANDLER	(int signum, siginfo_t* siginfoPtr, void* data)
{
  crackingThief = (*siginfoPtr).si_pid; //made it local in here mistake.

  int address = 0;
  if (firstnum > 0)
  {
    address = computeResponse(&firstnum);
  } 
  else if (secondnum > 0)
  {
    address = computeResponse(&secondnum);
  }
  else if (thirdnum > 0)
  { 
    address = computeResponse(&thirdnum);
    if (address == SIG_RIGHT_DIGIT)
    {
      safeopened = 1;
    }
  }
  kill(crackingThief, address);
}

int		main 		()
{
  srand(getpid()); //init random gen
  
  struct sigaction a;
  memset(&a, '\0', sizeof(a));    //simple hand
  a.sa_handler = SIG_QUIT_HANDLER;  //sends sig to func and change to 0 to stop
  sigaction(SIG_QUIT, &a, NULL);  //recieves sigquit from lookout

  a.sa_flags = SA_SIGINFO;          //install sigtrynextdigit advanced hand
  a.sa_sigaction = SIG_TRY_NEXT_DIGIT_HANDLER;
  sigaction(SIG_TRY_NEXT_DIGIT, &a, NULL);

  firstnum = (rand() % 16) + 1;    //randommmmmmmmmmmmmm
  secondnum = (rand() % 16) + 1;   //the bigger the better
  thirdnum = (rand() % 16) + 1;    //that's what she said
  printf("Don't tell these bad boys, my digits are %d-%d-%d \n", firstnum, secondnum, thirdnum);
  if (firstnum+secondnum+thirdnum > 24)
  {
    printf("They ain't opening this! \n");
  }
  else
  {
    printf("I have a bad feeling about this one...\n");
  }
  while (pgrmruns) //while pgrmruns = 1 stays running
  {
    sleep(1);      //make sure they only get 24 tries
  }

  if(safeopened)
  {
    printf("I don't usually open up this easily... \n");
  }
  else
  {
    printf("Well, too bad, lemme give you one last chance. \n");
  }

return(EXIT_SUCCESS);
}
