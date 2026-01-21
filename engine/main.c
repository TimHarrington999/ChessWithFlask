// Timothy's Custom Chess Engine
// 
// This engine uses UCI (Universal Chess Interface) to communicate with the front-end.
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 1024

bool running = true;

void handle_uci()
{
  printf("id name TimothyChessEngine\n");
  printf("id author TimothyHarrington\n");
  printf("uciok\n");
  fflush(stdout);
}

void handle_isready()
{
  printf("readyok\n");
  fflush(stdout);
}

void handle_position()
{
  // TODO
  
}

void handle_go()
{
  // TODO
  printf("bestmove b8c6\n");
  fflush(stdout);
}

void handle_quit()
{
  running = false;
}

int main()
{

  char line[MAX_LINE];

  while (running && fgets(line, sizeof(line), stdin))
  {
    // remove the newline from the request
    line[strcspn(line, "\n")] = 0;
    

    // route the incoming request from the front-end to the proper place
    if (strcmp(line, "uci") == 0)
    {
      handle_uci();
    }
    else if (strcmp(line, "isready") == 0)
    {
      handle_isready();
    }
    else if (strncmp(line, "position", 8) == 0)
    {
      handle_position();
    }
    else if (strncmp(line, "go", 2) == 0)
    {
      handle_go();
    }
    else if (strcmp(line, "quit") == 0)
    {
      handle_quit();
    }
  }

  return 0;
}
