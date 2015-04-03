#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <setjmp.h>

char *ch, *p;
jmp_buf environment;

double eval()
{
  double x1;  char *c1, *c2;
  if (isspace(*--p))
  {
    while (p>ch && isspace(*p))  --p;
    if (p>ch)  switch (*p)
    {
        case '+': return eval()+eval();
        case '*': return eval()*eval();
        case '-': return x1 = eval(),eval()-x1;
        case '/': return x1 = eval(),eval()/x1;
	default:  c1 = p + 1;
                  while (!isspace(*--p))  ;
		  if (x1 = strtod(++p, &c2),c2 == c1)  return x1;
    }
  }
  longjmp(environment,0);
}

int main()
{
  int size,c,n;
  double x1;
  ch = (char*)malloc(size=4);
  *ch = ' ';
  p = ch+1;
  while ((c=getchar())!=EOF)
    if (c!='\n')
    {
      n = p-ch;
      if (n+2==size)  ch = (char*)realloc(ch,size*=2);
      p = ch+n;
      *p++ = c;
    }
    else
    {
      while (--p>ch && isspace(*p))  ;
      if (p++>ch)
      {
        *p++ = ' ';
        if (!setjmp(environment))
        {
          x1 = eval();
          while (--p>ch && isspace(*p))  ;
          if (p>ch)  longjmp(environment,0);
          printf("%f\n",x1);
        }
        else  printf("error\n");
        p = ch+1;
      }
    }
  return 0;
}
