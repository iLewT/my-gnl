#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
void	ft_memmove(void *dest, void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_search(char **line, char *buf);
char	*ft_check(char *rm, char **line);
int		ft_connect(char **line, char *buf);
size_t	ft_strlen(char *s);

#endif