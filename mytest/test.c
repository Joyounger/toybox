#include <stdio.h>
#include "toys.h"


struct toy_list toy_list[] = {
#include "generated/newtoys.h"
};


// global context for this command.
struct toy_context toys;


// Like exec() but runs an internal toybox command instead of another file.
// Only returns if it can't run command internally, otherwise exit() when done.
void toy_exec(char *argv[])
{
  struct toy_list *which;

  // Return if we can't find it (which includes no multiplexer case),
  if (!(which = toy_find(*argv))) return;


}


// Multiplexer command, first argument is command to run, rest are args to that.
// If first argument starts with - output list of command install paths.
void toybox_main(void)
{
  static char *toy_paths[]={"usr/","bin/","sbin/",0};
  int i, len = 0;

  // fast path: try to exec immediately.
  // (Leave toys.which null to disable suid return logic.)
  printf("toys.argv[1]--%s\n", toys.argv[1]);
  printf("*(toys.argv+1)--%s\n", *(toys.argv+1));
  
  //if (toys.argv[1]) toy_exec(toys.argv+1);


}

int main(int argc, char* argv[])
{
    printf("*argv--%s\n", *argv);
    if (!*argv) return 127;    

    toys.argv = argv-1;
    
    toybox_main();
    

    printf("haha\n");
    return 0;
}


/*
kolya@asus ~/test/toybox $ ./test 
*argv--./test
toys.argv[1]--./test
*(toys.argv+1)--./test
haha
kolya@asus ~/test/toybox $ ./ls -a
*argv--./ls
toys.argv[1]--./ls
*(toys.argv+1)--./ls
haha
*/

