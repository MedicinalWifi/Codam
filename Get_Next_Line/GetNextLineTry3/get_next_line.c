/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 15:42:06 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/10 18:28:24 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#include "get_next_line.h"

char *get_next_line(int fd);
char *assemble_return(char *nextline, int fd, char **static_buf, char *buf);
char *write_next_line(char *nextline, char *buf, char **static_buf, int i);
char *write_static_buf(char *buf, char *static_buf, int i);

char *get_next_line(int fd)
{
	static char		*static_buf;
	char			*buf;
	char			*nextline;
	int 			i;
	
	/* printf("Static buf at start contains: %s\n", static_buf); */
	i = 0;
	if (!static_buf)
		static_buf = NULL;
	nextline = ft_calloc(BUFFER_SIZE, sizeof(char));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE + 1] = '\0';
	if (static_buf != NULL)
		i = ft_strlen(static_buf);
	if (i > 0)
	{
		buf = static_buf;
		nextline = assemble_return(nextline, fd, &static_buf, buf);
		return (nextline);
	}
	else
	{
		read(fd, buf, BUFFER_SIZE);
		nextline = assemble_return(nextline, fd, &static_buf, buf);
	/* 	printf("Static buf after whole function contains: %s\n", static_buf); */
		return(nextline);
	}
	return (NULL);
}

char *assemble_return(char *nextline, int fd, char **static_buf, char *buf)
{
	int	i;

	i = 0;
	printf("buf contains: %s\n", buf);
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			nextline = write_next_line(nextline, buf, static_buf, i);
			if (i < BUFFER_SIZE)
			{
				*static_buf = write_static_buf(buf, *static_buf, i);
				printf("Static buf after write_static_buf contains: %s\n", *static_buf);
			}
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
	nextline = malloc((BUFFER_SIZE * 2) * sizeof(char));
	if (!nextline)
		return (NULL);
	i = 0;
	*static_buf = write_static_buf(buf, *static_buf, i);
	read(fd, buf, BUFFER_SIZE);
	nextline = assemble_return(nextline, fd, static_buf, buf);
	return(NULL);
}

char *write_next_line(char *nextline, char *buf, char **static_buf, int i)
{
	int	i2;

	i2 = 0;
	if (ft_strlen(*static_buf) > 0)
	{
		while (static_buf[i2])
		{
			if (*(char *)(static_buf + i2) == '\n')
				return(nextline);
			nextline[i2] = *static_buf[i2];
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
	int i2;

	i2 = 0;
	i++;
	if (static_buf != NULL)
		free(static_buf);
	static_buf = ft_calloc(((BUFFER_SIZE - i) + 1), sizeof(char));
	while (i <= BUFFER_SIZE)
	{
		static_buf[i2] = buf[i];
		i2++;
		i++;
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