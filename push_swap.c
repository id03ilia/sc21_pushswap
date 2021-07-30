#include "push_swap.h"

void	check_str_eof(char *str)
{
	if (str[0] == '\0')
		error(-1);
}

int	main(int argc, char **argv)
{
	t_A_stack	*a;
	t_A_stack	*b;
	t_A_stack	*t;
	t_A_stack	*t2;
	int			i;

	a = create_steakA(argc, argv);
	dublikat(&a);
	index_mas_A(&a);
	t = razmtka1(&a);
	t2 = razmtka2_indx(&a);
	if (argc - 1 > 5)
		i = vibor_razmtki100(&a, t, t2);
	else
		i = vibor_razmtki5(&a, t, t2);
	if (i == 2)
		t = t2;
	mark_and_BtoA(&a, &b, checkAandPB(&a, &b, t, i));
	st_A_rovno(&a);
	ft_lstclear(&a);
	return (0);
}
