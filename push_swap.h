#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
//# include <fcntl.h>
//# include <sys/types.h>
//# include <sys/stat.h>

typedef struct s_list
{
	int				numb;
	int				index;
	int				razmtk;
	int				razmtk2;
	int				marker;
	int				marker2;
	struct s_list	*nexta;
	struct s_list	*nextb;
}				t_A_stack;

long int	ft_atoi(char *str);
int			ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_lstadd_back(t_A_stack **lst, t_A_stack *new);
void		ft_lstadd_backB(t_A_stack **lst, t_A_stack *new);
int			ft_lstsize(t_A_stack **a);
int			ft_lstsizeB(t_A_stack **lst);
char		**ft_split(char const *s, char c, int *strok);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isdigit(int c);
char		**ft_cpy_mall_free(char **res, int r );
t_A_stack	*ft_lstnew(int content);
void		error(int i);
void		ft_lstclear(t_A_stack **lst);
void		sa(t_A_stack **a);
void		sb(t_A_stack **b);
void		ss(t_A_stack **a, t_A_stack **b);
void		pb(t_A_stack **a, t_A_stack **b);
void		pa(t_A_stack **a, t_A_stack **b);
void		rra(t_A_stack **a, int y);
void		rrb(t_A_stack **b, int y);
void		rrr(t_A_stack **a, t_A_stack **b);
void		ra(t_A_stack **a, int i);
void		rb(t_A_stack **b, int i);
void		rr(t_A_stack **a, t_A_stack **b);
void		index_mas_A(t_A_stack **a);
t_A_stack	*razmtka1(t_A_stack **a);
void		raztka1_sa(t_A_stack **a, t_A_stack *t_mark);
t_A_stack	*razmtka2_indx(t_A_stack **a);
void		razmtka2_sa(t_A_stack **a, t_A_stack *t_mark);
int			vibor_razmtki5(t_A_stack **a, t_A_stack *t, t_A_stack *t2);
int			vibor_razmtki100(t_A_stack **a, t_A_stack *t, t_A_stack *t2);
int			proverka_sa(t_A_stack **a, t_A_stack *t, int i);
int			proverka_a_fls(t_A_stack **a);
int			check_a_false(t_A_stack **a, int i);
void		st_B_markirovka(t_A_stack **a, t_A_stack **b, int s, int s_b);
t_A_stack	*st_B_min_mark(t_A_stack **b);
void		mark_and_BtoA(t_A_stack **a, t_A_stack **b, int s);
void		st_A_rovno(t_A_stack **a);
int			checkAandPB(t_A_stack **a, t_A_stack **b, t_A_stack *t, int i);
void		mall_free(char **res, int r);
void		free_and_error(t_A_stack **a);
void		free_mall_and_error(t_A_stack **a, char **mas_numb, int r);
t_A_stack	*create_steakA(int argc, char **argv);
void		dublikat(t_A_stack **a);
void		check_str_eof(char *str);

#endif
