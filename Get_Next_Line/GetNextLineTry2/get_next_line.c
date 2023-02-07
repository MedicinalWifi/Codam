/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:15:00 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/07 15:21:00 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd);
char *assemble_return(int fd, char *static_buf, char *buf, char *nextline);
char *write_next_line(char *nextline, char *buf, char *static_buf, int i);
char *write_static_buf(char *buf, char *static_buf, int i);

char *get_next_line(int fd)
{
	static char		*static_buf;
	char			*buf;
	static char		*nextline;

	static_buf = NULL;
	nextline = NULL;
	buf = NULL;
	if (fd == 0 || BUFFER_SIZE < 0)//these are my checks to see if the read/write is even possible with current fd and bufsize.
		return (NULL);
	if (buf == NULL)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));//I malloc BUFFER_SIZE plus space for null terminator, because there will never be more space needed than that.
		if (!buf)
			return (NULL);
		buf[BUFFER_SIZE + 1] = '\0';	
	}
	if (nextline == NULL)
	{
		nextline = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (nextline == NULL)
			return(NULL);
		nextline[BUFFER_SIZE + 1] = '\0';
	}
	if (static_buf == NULL)
		read(fd, buf, BUFFER_SIZE);
		
	nextline = assemble_return(fd, static_buf, buf, nextline);
	
	return (nextline);
}

char *assemble_return(int fd, char *static_buf, char *buf, char *nextline)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			nextline = write_next_line(nextline, buf, static_buf, i);
			if (buf[i + 1])
				static_buf = write_static_buf(buf, static_buf, i);
			else
			{
				free(static_buf);
				static_buf = NULL;
			}
			return (nextline);
		}
		i++;
	}
	free(nextline);
	nextline = NULL;
	nextline = malloc((BUFFER_SIZE * 2) * sizeof(char));
	if (!nextline)
		return (NULL);
	i = 0;
	static_buf = write_static_buf(buf, static_buf, i);
	read(fd, buf, BUFFER_SIZE);
	nextline = assemble_return(fd, static_buf, buf, nextline);
	return(NULL);
}

char *write_next_line(char *nextline, char *buf, char *static_buf, int i)
{
	int	i2;

	i2 = 0;
	if (static_buf != NULL)
	{
		while (static_buf[i2])
		{
			nextline[i2] = static_buf[i2];
			i2++;
		}
		while (buf[i])
		{
			nextline[i2] = buf[i];
			i++;
			i2++;
		}
	}
	else while (i >= 0)
	{
		nextline[i] = buf[i];
		i--;
	}
	return (nextline);
}

char *write_static_buf(char *buf, char *static_buf, int i)
{
	int	i2;
	int i3;
	int i4;
	
	i2 = 0;
	i3 = i;
	i4 = 0;
	while (buf[i3])
	{
		i4++;
		i3++;
	}
	static_buf = malloc(i4 + 1 * sizeof(char));
	if (!static_buf)
		return (NULL);
	static_buf[i4 + 1] = '\0';
	while (i2 <= i3)
	{
		static_buf[i2] = buf[i];
		i++;
		i2++;
	}
	return (static_buf);
}

int	main(void)
{
	int fd;
	char *path;

	path = "/Users/lhop/Desktop/Get_Next_Line/test.txt";
	fd = open(path, O_RDONLY);
	printf("|| END OF OPERATION 1 ||\n|| First line: %s || \n\n", get_next_line(fd));
	printf("|| END OF OPERATION 2 ||\n|| Second line: %s || \n\n", get_next_line(fd));
	printf("|| END OF OPERATION 3 ||\n|| Third line: %s || \n\n", get_next_line(fd));
	printf("|| END OF OPERATION 4 ||\n|| Fourth line: %s || \n\n", get_next_line(fd));
	return (1);
}