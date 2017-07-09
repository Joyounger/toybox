#include <setjmp.h>

// Array of available commands
extern struct toy_list {
  char *name;
  void (*toy_main)(void);
  char *options;
  int flags;
} toy_list[];



// Global context shared by all commands.
extern struct toy_context {
  struct toy_list *which;  // Which entry in toy_list is this one?
  char **argv;             // Original command line arguments
  char **optargs;          // Arguments left over from get_optflags()
  unsigned long long optflags; // Command line option flags from get_optflags()
  int exitval;             // Value error_exit feeds to exit()
  int optc;                // Count of optargs
  int old_umask;           // Old umask preserved by TOYFLAG_UMASK
  short toycount;          // Total number of commands in this build
  short signal;            // generic_signal() records what signal it saw here
  int signalfd;            // and writes signal to this fd, if set
  int wasroot;             // dropped setuid

  // This is at the end so toy_init() doesn't zero it.
  jmp_buf *rebound;        // longjmp here instead of exit when do_rebound set
  struct arg_list *xexit;  // atexit() functions for xexit(), set by sigatexit()
  void *stacktop;          // nested toy_exec() call count, or 0 if vforked
} toys;