#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	a_list
{
	int				numb;
	int				index;
	int 			sorted;
	int 			marker;
	struct a_list	*next;
}				t_A_stack;

int			ft_atoi(char *str);
char		*ft_itoa(int n);
int			ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

#endif
