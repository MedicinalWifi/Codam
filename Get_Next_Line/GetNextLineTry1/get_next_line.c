/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:44:54 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/09 13:08:40 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char 	*get_next_line(int fd);
char	*readbuf(int fd, char *buf, char *buf_remainder, char *terminated_buf, int *i);
char	*splitbuf(char *buf, int i, char *terminated_buf);
char	*buffer_no_newline(int fd, char *buf, char *terminated_buf, int *i);
char	*splitbuf2(char *buf, int i, int i2, char *terminated_buf);
char	*readbuf2(int fd, char *buf, char *buf_remainder, char *terminated_buf);

char *get_next_line(int fd)
{
	char			*buf;
	static char		*buf_remainder;
	char			*terminated_buf;
	static int		i;
	
	i = 0 + i;
	if (buf_remainder == NULL)
	{
		buf_remainder = malloc(BUFFER_SIZE + 1 * sizeof(char));
		buf_remainder[BUFFER_SIZE + 1] = '\0';
	}
	buf = malloc(BUFFER_SIZE * sizeof(char));
	terminated_buf = malloc(BUFFER_SIZE * sizeof(char));
/* 	printf("buf_remainder in first function after malloc: %s\n", buf_remainder); */
	printf("Value of static int i in first function: %i\n", i);
	if (i >= 1 && i < BUFFER_SIZE)
	{
		printf("Program went into terminated-buf-based function\n");
		buf = buf_remainder;
		terminated_buf = readbuf2(fd, buf, buf_remainder, terminated_buf);
	}
	else
	{
		printf("Program went into read-to-buf-based function\n");
		read(fd, buf, BUFFER_SIZE);
		terminated_buf = readbuf(fd, buf, buf_remainder, terminated_buf, &i);
	}
/* 	printf("This is the current butter content: %s\n", buf); */
	return (terminated_buf);
}

char	*readbuf(int fd, char *buf, char *buf_remainder, char *terminated_buf, int *i)
{
	int i2;
	int	i_c;

	i2 = 0;
	i_c = 0;
/* 	printf("the contents of buf: %s\n", buf); */
	while (buf[*i])
	{
		/* printf("value of buf[*i]: '%c'\n", buf[*i]); */
		/* printf("This is buf[%i]: %c\n", i, buf[i]); */
		if (buf[*i] == '\n')
		{
			i_c = *i;
			terminated_buf = malloc(BUFFER_SIZE * sizeof(char));
			terminated_buf = splitbuf(buf, *i, terminated_buf);
			printf("terminated_buf: '%s'", terminated_buf);
			while (i_c <= BUFFER_SIZE)
			{
/* 				printf("Current value of 'i_c' %i\n", i_c);
				printf("writing '%c' into '%c'\n", buf[i_c], buf_remainder[i2]); */
				buf_remainder[i2] = buf[i_c];
				i_c++;
				i2++;
			}
/* 			printf("buf_remainder: %s\n", buf_remainder); */
			return (terminated_buf);
		}
		*i = *i + 1;
	}
	if (fd != 0)
		return(terminated_buf);
	if (i_c == 0)
		terminated_buf = buffer_no_newline(fd, buf, terminated_buf, i);
	return (terminated_buf);
}

char	*readbuf2(int fd, char *buf, char *buf_remainder, char *terminated_buf)
{
	int i2;
	int	i_c;
	int i_3;

	i2 = 0;
	i_c = 0;
	i_3 = 1;
/* 	printf("the contents of buf: %s\n", buf); */
	while (buf[i_3])
	{
		/* printf("value of buf[*i]: '%c'\n", buf[*i]); */
		/* printf("This is buf[%i]: %c\n", i, buf[i]); */
		if (buf[i_3] == '\n')
		{
			printf("The value of i3 is: %i\n", i_3);
			i_c = i_3;
			terminated_buf = malloc(BUFFER_SIZE * sizeof(char));
			terminated_buf = splitbuf(buf, i_3, terminated_buf);
			printf("terminated_buf: '%s'", terminated_buf);
			while (i_c <= BUFFER_SIZE)
			{
/* 				printf("Current value of 'i_c' %i\n", i_c);
				printf("writing '%c' into '%c'\n", buf[i_c], buf_remainder[i2]); */
				buf_remainder[i2] = buf[i_c];
				i_c++;
				i2++;
			}
/* 			printf("buf_remainder: '%s'\n", buf_remainder); */
			return (terminated_buf);
		}
		i_3++;
	}
	if (fd != 0)
		return(terminated_buf);
	if (i_c == 0)
		terminated_buf = buffer_no_newline(fd, buf, terminated_buf, &i_3);
	return (terminated_buf);
}

char	*splitbuf(char *buf, int i, char *terminated_buf)
{
	int original_i;

	original_i = i;
	terminated_buf[i + 1] = '\0';
	while (i >= 0)
	{
/* 		printf("this is the letter currently being placed: %c\n", buf[i]); */
		terminated_buf[i] = buf[i];
		i--;
	}
/* 	printf("Here is a line split:%s||", terminated_buf); */
	free(buf);
	return (terminated_buf);
}

char	*buffer_no_newline(int fd, char *buf, char *terminated_buf, int *i)
{
	int i2;

	i2 = 0;
	terminated_buf = malloc(BUFFER_SIZE * 2 * sizeof(char));
	terminated_buf = splitbuf(buf, *i, terminated_buf);
	read(fd, buf, BUFFER_SIZE);
	while (buf[i2])
	{
		/* printf("This is buf[%i]: %c\n", i, buf[i]); */
		if (buf[i2] == '\n')
		{
			return (splitbuf2(buf, *i, i2, terminated_buf));
		}
		i2++;
	}
/* 	terminated_buf = buffer_no_newline(buf, terminated_buf, i); */
	return (terminated_buf);
}

char	*splitbuf2(char *buf, int i, int i2, char *terminated_buf)
{
	terminated_buf[i + 1] = '\0';
	while (i >= 0)
	{
/* 		printf("this is the letter currently being placed: %c\n", buf[i]); */
		terminated_buf[i + i2] = buf[i2];
		i2--;
	}
/* 	printf("Here is a line split:%s||", terminated_buf); */
	free(buf);
	return (terminated_buf);
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