
#include "isfunc.h"

void func ( ) { }

size_t determine_func_common_length ( ) {
  char *funcp = (char *)func
      , *p = (char *)determine_func_common_length;
  size_t c = 0;
  while ( *funcp == *p++ && ++c < 8 ) funcp++;
  if ( c > 0 && c < 8 ) return c;
  return 0;
}

size_t func_common_length = 0;

ISFUNC_BOOL isfunc ( void *p ) {
  char *funcp = (char *)func;
  size_t c = func_common_length ? func_common_length
      : (func_common_length = determine_func_common_length());
  
  if ( ! c ) {
    errno = ENOTSUP;
    perror("isfunc is not available for this system configuraion");
    return ISFUNC_FALSE;
  }
  while ( c-- ) if ( *((char *)p++) != *funcp++ ) return ISFUNC_FALSE;
  
  return ISFUNC_TRUE;
}


