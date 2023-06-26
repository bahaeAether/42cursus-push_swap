/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:39:31 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:48:31 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				place;
	struct s_list	*next;
}				t_list;

ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	count_strs(char const *str, char sep);
size_t	len_str(char const *str, char sep);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
t_list	*elem_index(t_list **stack, int index);
int		ft_putnbr(long n);
int		ft_strcmp(char *s1, char *s2);
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rr(t_list **stack_a, t_list **stack_b);
int		rb(t_list **stack_b);
int		rra(t_list **stack_a);
int		rrr(t_list **stack_a, t_list **stack_b);
int		rrb(t_list **stack_b);
int		ft_limit(long n, int sign);
int		ft_lstsize(t_list *head);
int		ft_atoi(const char *str);
int		*parse_args(t_list **stack_a, int ac, char **av);
int		ft_abs(int n);
int		*list_to_tab(t_list *stack, int size);
int		**best_move(t_list **stack_a, t_list **stack_b);
int		**moves_optimizer(int *moves, int size_a, int size_b);
int		*moves_to_place(int i, int j, int size_a, int size_b);
int		min_tab(int *tab, int size);
int		max_tab(int *tab, int size);
int		max_tab_index(int *tab, int size);
int		min_tab_index(int *tab, int size);
int		ft_isbigger(int a, int b);
int		*sequence_tab(int *tab, int ac);
int		sequence_head(int *tab, int ac);
int		sequence_length(int *tab, int ac, int index);
int		**ft_malloc_tab(int n, int m);
int		ft_str_is_numeric(char *str);
int		lst_min_position(t_list *stack);
int		is_sorted(int *tab, int size);
void	ft_clone(int **clone, int **tab);
void	ft_place(t_list **stack_a, t_list **stack_b);
void	ft_error(void);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	init_stack(t_list **stack_a, int *array, int size);
void	sort_list(t_list **stack_a);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_lstclear(t_list **lst);
void	execute_move(int move, t_list **stack_a, t_list **stack_b);
void	ft_update(int **optimized, int **best, int *min);
void	ft_free_int(int **tab, int n);
void	optimiser1(int **optimized, int *moves);
void	optimiser2(int **optimized, int *moves);
void	optimiser3(int **optimized, int *moves, int size_a, int size_b);
void	optimiser4(int **optimized, int *moves, int size_a, int size_b);
void	optimiser5(int **optimized, int *moves, int size_b);
void	optimiser6(int **optimized, int *moves, int size_a);
void	optimiser7(int **optimized);
void	place_helper(t_list **stack_b, int **tab, int i, int size_a);
void	filter_a(t_list **stack_a, t_list **stack_b, int n);
void	ft_error_malloc(void);
void	ft_error_stack(void);
void	ft_free_split(char **split, char *str, int ac);
void	parse_int(int *tab, int ac, char **av);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*joined_args(int ac, char **av);
char	**ft_split(char const *s, char c);
char	**ft_free(char **str, size_t n);

#endif
