#include <stdio.h>
#include <stdlib.h>

int function(char *buf, int i)
{
	if (i <= 3)
	{
		buf[i] = '1';
	}
	i++;
	return(1);
}

int main(void)
{
	static char *buf;
	static char i;

	i = 0;

	buf = malloc(3 * sizeof(char));
	buf[0] = '\0';
	printf("Contents of buf[0]: %c", buf[0]);
	function(buf, i);
	printf("Contents of buf[0]: %c", buf[0]);
	return(1);
}