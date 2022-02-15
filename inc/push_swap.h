/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:47:32 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 17:19:01 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				i;
	int				s;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int		count_a;
	int		count_b;
	int		tmp_ra;
	int		tmp_rb;
	int		tmp_av;
	int		opt_ra;
	int		opt_rb;
	int		opt_av;
	int		print;
	t_stack	*sa;
	t_stack	*sb;
	t_stack	*sort;
}	t_stacks;

void		ft_error(t_stacks *stacks);
void		ft_free(t_stacks *stacks);
void		ft_only_error(void);
char		**ft_split_nbr(char *s, char c);
void		*ftp_calloc(size_t count, size_t size);
int			ft_atoi(const char *str, t_stacks *stacks);
int			ft_abs(int nb);
int			ft_check_str(char *str);
int			ft_size_stack(t_stack *list);
int			ft_not_dup(t_stack *stack, int value);
t_stack		*ft_to_list(t_stack **stack, int value);
void		ft_add_head(t_stack **stack, t_stack *head);
void		ft_add_back(t_stack **stack, t_stack *new);
t_stack		*ft_find_last_node(t_stack *stack);
t_stack		*ft_new_node(int value);
void		ft_distrib(char *op, int t, t_stacks *stacks);
void		ft_three_sort(t_stacks *stacks);
void		ft_five_sort(t_stacks *stacks);
void		ft_big_sort(t_stacks *stacks);
t_stack		*ft_find_max_sorted(t_stack *stack);
int			ft_swap(t_stack **stack);
int			ft_push(t_stack **from, t_stack **to);
int			ft_rotate(t_stack **stack);
int			ft_rev_rotate(t_stack **stack);
t_stack		*ft_del_head(t_stack **stack);
t_stack		*ft_del_back(t_stack **stack);
void		ft_from_sa_to_sb(t_stacks *stacks);
void		ft_from_sb_to_sa(t_stacks *stacks);
int			ft_find_part(int len, int poz);
void		ft_index(t_stack *stack);
void		ft_min_to_top(t_stacks *stacks);
int			ft_count_steps(int a, int b, int poz_b);
int			ft_def_tmp_rank(t_stacks *stacks, t_stack *tmp_sb);
void		ft_join_sb_to_sa(t_stacks *stacks);
t_stacks	*ft_init_stacks(int argc, char **argv);

#endif
