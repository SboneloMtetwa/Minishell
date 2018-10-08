/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 11:37:42 by smtetwa           #+#    #+#             */
/*   Updated: 2018/09/11 14:18:21 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./libft/libft.h"

char **g_envv;

int		exec_bin(char **args);
void	print_env(void);
int		envv_len(char **envv);
int		ft_echo(char **args);
int		ft_unsetenv(char **args);
int		ft_setenv(char **args);
char	*locate_env(char *var);
int		ft_position(char *var);
int		ft_cd(char **args);
void	set_env(char *name, char *value);

#endif
