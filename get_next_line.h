#include <stdlib.h>
#include <unistd.h>
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*handle(char *buff, char *rest, int i, int j);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		reading(int fd, char **buff, int *finish);
void	printing(char **buff, char **rest);
int		check(char *str);
