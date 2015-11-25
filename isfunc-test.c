
#include <stdio.h>

#include "isfunc.h"

#define GROUPING  4

const char text[] = "This is a string!";

char charstring[100];
char *chardump ( void *p, size_t len ) {
  int i = 0, c;
  while ( i < len ) {
    c = *((char *)p + i);
    charstring[i++] = ( c < 0x20 || c > 126 ) ?
      '.' : c;
  }
  charstring[i] = '\0';
  return charstring;
}


char hexstring[100];
char *hexdump ( void *ptr, size_t len ) {
  int i = 0, c, g;
  char *sp = hexstring;
  unsigned char *p = ptr;
  while ( i < len ) {
    g = GROUPING;
    while ( i < len && g-- ) {
      c = *(p + i++);
      sprintf(sp, "%02x", c);
      sp += 2;
    }
    *sp++ = ' ';
  }
  *sp = '\0';
  return hexstring;
}

int main ( int argc, char *argv[] ) {
  void *funp = (void *)main;
  void *texp = (void *)text;
  size_t funl = sizeof( main )
      , texl  = sizeof( text )
      , count = funl > texl ? funl : texl;
  ISFUNC_BOOL isfunc_func, isfunc_text;
  
  errno = 0;
  if ( (isfunc_func = isfunc( funp ))
      && ! errno
      && ! (isfunc_text = isfunc( texp ))
      && ! errno ) {
    printf( "main[%14p]: %s%s (%2lu) - %s\n", funp, hexdump( funp, count ), chardump( funp, count ), funl, isfunc_func ? "isfunc" : "! isfunc" );
    printf( "text[%14p]: %s%s (%2lu) - %s\n", texp, hexdump( texp, count ), chardump( texp, count ), texl, isfunc_text ? "isfunc" : "! isfunc" );
  }
  
  printf( "isfunc is %sworking\n"
      , ( ! errno && isfunc_func && ! isfunc_text )
      ? "" : "NOT " );
  
  return 0;
}

