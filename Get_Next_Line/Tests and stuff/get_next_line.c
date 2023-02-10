/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:44:54 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/03 13:51:20 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*get_next_line(int fd);
char	*readbuf(char *buf, char *terminated_buf, int *i, int fd);
char	*splitbuf(char *buf, int i, char *terminated_buf);
char	*buffer_no_newline(char *buf, char *terminated_buf, int *i, int fd);

char *get_next_line(int fd)
{
	char			*buf;
	char			*terminated_buf;
	static int		i;
	
	i = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	terminated_buf = malloc(BUFFER_SIZE * sizeof(char));
	if (i >= BUFFER_SIZE)
		read(fd, buf, BUFFER_SIZE);
	if (i == 0)
		read(fd, buf, BUFFER_SIZE);
	terminated_buf = readbuf(buf, terminated_buf, &i, fd);
/* 	printf("This is the current butter content: %s\n", buf); */
	return (terminated_buf);
}

char	*readbuf(char *buf, char *terminated_buf, int *i, int fd)
{
	while (buf[*i])
	{
		/* printf("This is buf[%i]: %c\n", i, buf[i]); */
		if (buf[*i] == '\n')
		{
			terminated_buf = malloc(*i + 1 * sizeof(char));
			return (splitbuf(buf, *i, terminated_buf));
		}
		*i = *i + 1;
	}
	terminated_buf = buffer_no_newline(buf, terminated_buf, i, fd);
	return (terminated_buf);
}

char	*splitbuf(char *buf, int i, char *terminated_buf)
{
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

char	*buffer_no_newline(char *buf, char *terminated_buf, int *i, int fd)
{
	int		expanded_i;
	
	expanded_i = 0;
	terminated_buf = malloc((*i * 2) * sizeof(char));
	while (expanded_i <= BUFFER_SIZE)
	{
		terminated_buf[expanded_i] = buf[expanded_i];
		expanded_i++;
	}
	read(fd, buf, BUFFER_SIZE);
	while (expanded_i <= (BUFFER_SIZE * 2))
	{
		terminated_buf[expanded_i] = buf[expanded_i];
		expanded_i++;
	}
	while (buf[*i])
	{
		/* printf("This is buf[%i]: %c\n", i, buf[i]); */
		if (buf[*i] == '\n')
		{
			terminated_buf = malloc(*i + 1 * sizeof(char));
			return (splitbuf(buf, *i, terminated_buf));
		}
		*i = *i + 1;
	}
	buffer_no_newline(buf, terminated_buf, i, fd);
	return (NULL);
}

int	main(void)
{
	int fd;
	char *path;

	path = "/Users/lhop/Desktop/Get_Next_Line/test.txt";
	fd = open(path, O_RDONLY);
	printf("First line: %s", get_next_line(fd));
	printf("Second line: %s", get_next_line(fd));
	printf("Third line: %s", get_next_line(fd));
	printf("Fourth line: %s", get_next_line(fd));
	return (1);
}