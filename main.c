/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:48:15 by smtetwa           #+#    #+#             */
/*   Updated: 2018/09/29 10:30:15 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		copy_envv(int ac, char **av, char **envv)
{
	int i;

	(void)ac;
	(void)av;
	g_envv = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1));
	i = 0;
	while (envv[i])
	{
		if (!(g_envv[i] = ft_strdup(envv[i])))
		{
			ft_free_array(g_envv);
			write(1, "\n", 1);
			exit(0);
		}
		i++;
	}
	g_envv[i] = NULL;
}

static int		exec_builtins(char **args)
{
	if (!args || args[0] == NULL)
		return (1);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (ft_unsetenv(args + 1));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args + 1));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args + 1));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (ft_setenv(args + 1));
	else if (ft_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	else
		return (exec_bin(args));
}

static void		sh_loop(void)
{
	char	*cmd_line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr("\033[31m$>\033[0m ");
		get_next_line(0, &cmd_line);
		args = ft_split(cmd_line);
		free(cmd_line);
		status = exec_builtins(args);
		ft_free_array(args);
	}
}

int				main(int ac, char **av, char **envp)
{
	copy_envv(ac, av, envp);
	sh_loop();
	ft_free_array(g_envv);
	return (1);
}
