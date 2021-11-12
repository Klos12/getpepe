#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
/*int	main(void)
{
	int		fd;
	char	*print;
	
	fd = open("ElQuijote.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));
	print = get_next_line(fd);
	
//	system("leaks a.out");:w
//
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("------------------------------------------------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	close(fd);
}
*/
int				main()
{
	int			fd;
	char		*str;
	int			i;
	i = 0;
	fd = open("41_with_nl", O_RDONLY);
 //	printf("%s",get_next_line(fd));
//	get_next_line(fd);

//	printf("%s", str); 
	while ((str = get_next_line(fd)) && i <9)
	{
		printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
	}
//	printf("%s\n", str);
system("leaks a.out");
	return (0);
}



















