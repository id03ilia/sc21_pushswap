#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ');
}

static int	digit(char *str)
{
	int	i;
	int	di;

	i = 0;
	di = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) > 0)
	{
		i++;
		di++;
	}
	if (!str[i] && di)
		di = 1;
	else
		di = 0;
	return (di);
}

static void	parser_str(t_A_stack **a, char *str)
{
	char		**mas_numb;
	int			i;
	int			strok;
	long int	d;
	t_A_stack	*tempa;

	mas_numb = ft_split(str, ' ', &strok);
	if (!mas_numb)
		error(-1);
	i = 0;
	while (mas_numb[i])
	{
		if (digit(mas_numb[i]) == 0)
			free_mall_and_error(a, mas_numb, strok);
		d = ft_atoi(mas_numb[i]);
		if ((d > 2147483647) || (d < -2147483648))
			free_mall_and_error(a, mas_numb, strok);
		tempa = ft_lstnew((int)d);
		if (tempa == NULL)
			free_mall_and_error(a, mas_numb, strok);
		ft_lstadd_back(a, tempa);
		i++;
	}
	mall_free(mas_numb, i);
}

static void	parser_int(t_A_stack **a, int argc, char **argv)
{
	int			i;
	t_A_stack	*tempa;
	long int	d;

	i = 1;
	while (i < argc)
	{
		if (digit(argv[i]) == 0)
			free_and_error(a);
		d = ft_atoi(argv[i]);
		if ((d > 2147483647) || (d < -2147483648))
			free_and_error(a);
		tempa = ft_lstnew((int)d);
		if (tempa == NULL)
			free_and_error(a);
		ft_lstadd_back(a, tempa);
		i++;
	}
}

t_A_stack	*create_steakA(int argc, char **argv)
{
	t_A_stack	*a;

	if (argc == 1)
		exit (1);
	if (argc == 2 && !digit(argv[1]))
		parser_str(&a, argv[1]);
	else
		parser_int(&a, argc, argv);
	return (a);
}
