#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
//mirar los while que hay uno que me mata
char	*get_next_line(int fd)
{
	int		i;
	char	*buff;
	static char	*rest;
	int		finish;
	unsigned int		tambuffer;
	unsigned int 		aux;

	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	finish = 0;
	tambuffer = 0;
	i = 0;
	aux = 0;
	if (rest && ft_strlen(rest))
	{
		buff = ft_strdup(rest);
		printf("rest<%p>", rest);
		free(rest);
	}
	else
	{
		free(rest);
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, buff, BUFFER_SIZE);
	}
	if (ft_strlen(buff) == 0)
		finish = 1;
	while ((check(buff) == 0) && finish == 0)
	{
		tambuffer = reading(fd, &buff, &finish);
		if (tambuffer == aux)
			finish = 1;
		aux = tambuffer;
		i++;
	}
	if (finish == 1 || check(buff) == 0)
	{
		if (ft_strlen(buff))
			return (buff);
		free(buff);
		return (NULL);
	}

	printing(&buff, &rest);
	printf("%p", rest);
	return (buff);
}

int		check(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j++;
		}
		i++;
	}
	return (j);
}

int		reading(int fd, char **buff, int *finish)
{
	char	*aux;
	char	*aux2;

	aux = NULL;
//	write(1,"1",1);
	aux = ft_strdup(*buff);
	free(*buff);
	*buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, *buff, BUFFER_SIZE);
	if (ft_strlen(*buff) == 0)
		(*finish) = 1;
	aux2 = ft_strjoin(aux, *buff);
	free(*buff);
	*buff = ft_strdup(aux2);
	free(aux);
	free(aux2);
	return ((unsigned)ft_strlen(*buff));
}

void	printing(char **buff, char **rest)
{
	int		i;
	char	*tmp;

	i = 0;
	//if (check(*buff) > 0)
	//{
		tmp = ft_strdup(*buff);
		free(*buff);
		//write(1,"A",1);
		while (tmp[i] && tmp[i] != '\n')
		{
			i++;
		}
		//write(1,"C",1);
		if (tmp[i] == '\n')
		{	
			*buff = ft_substr(tmp, 0, i + 1);
//			if (BUFFER_SIZE > 1 && tmp[i + 1] != '\0' )
			if (BUFFER_SIZE > 1)
				*rest = ft_substr(tmp, i + 1, (ft_strlen(tmp) - i + 1));
			free(tmp);
		}
		else
		{
			*buff = ft_strdup(tmp);
			free (tmp);
		}
//	}
}	
