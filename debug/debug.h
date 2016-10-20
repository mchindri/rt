#ifndef DEBUG_H
# define DEBUG_H


#include "libft.h"
#include <stdio.h>

#define OK ft_putstr("OK");
#define NB(x) {ft_putstr(#x);ft_putstr("= ");ft_putnbr(x); ft_putendl("");}
#define NBF(x) {ft_putstr(#x);dprintf(2,"= %lf\n", x);}
#define VECT(x) {ft_putstr(#x);dprintf(2,": a=%lf, b=%lf, g=%lf\n",x.a, x.b, x.g);}
#define POINT(a) {ft_putstr(#a);dprintf(2,": x=%lf, y=%lf, z=%lf\n",a.x, a.y, a.z);}
#define STOP {char c;scanf("%c", &c);}
#define EXIT {exit(0);}
#define STR(x) {ft_putstr(x);}

#endif

