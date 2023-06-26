/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:51:31 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:46:03 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strnjoin(char *s1, char *s2, int n);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_read(char *buffer, int fd);
char	*ft_get_line(char *buffer);
char	*ft_update(char *buffer);
char	*get_next_line(int fd);
t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *head);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstclear(t_list **lst);
int		swap(t_list **stack);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
void	ft_error(void);
int		ft_limit(long n, int sign);
void	init_stack(t_list **stack_a, int *array, int size);
int		ft_str_is_numeric(char *str);
int		ft_strcmp(char *s1, char *s2);
int		*parse_args(t_list **stack_a, int ac, char **av);
char	*joined_args(int ac, char **av);
void	parse_int(int *tab, int ac, char **av);
void	ft_free_split(char **split, char *str, int ac);
void	ft_checker(t_list **stack_a, t_list **stack_b);
int		*list_to_tab(t_list *stack, int size);
void	execute_moves(t_list **stack_a, t_list **stack_b, char *line);
char	**ft_split(char const *s, char c);
char	**ft_free(char **str, size_t n);
size_t	len_str(char const *str, char sep);
size_t	count_strs(char const *str, char sep);
int		is_sorted(int *tab, int size);
size_t	ft_strlen(const char *s);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);

#endif
