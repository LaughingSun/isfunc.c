
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

#ifdef bool
#define ISFUNC_BOOL  bool
#define ISFUNC_TRUE  (true)
#define ISFUNC_FALSE (false)
#else
#define ISFUNC_BOOL  int
#define ISFUNC_TRUE  (1)
#define ISFUNC_FALSE (0)
#endif

extern ISFUNC_BOOL isfunc ( void *p );

