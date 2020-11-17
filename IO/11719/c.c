#include <stdio.h>

int		main(void) {
	char	c;
	while ((c = (char)getchar())!= EOF) {
		putchar(c);
	}
	return (0);
}