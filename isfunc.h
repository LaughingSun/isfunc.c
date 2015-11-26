
#ifndef ISFUNC_H
#define ISFUNC_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

#ifndef ISFUNC_EXPECTED_COMMON_SIZE
// TODO: this actually would vary depending on the target hardware (and OS?):
//       so it would be best to detect that using the predefined macros.
#define ISFUNC_EXPECTED_COMMON_SIZE 4

#endif

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

#endif

