/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:00:49 by smtetwa           #+#    #+#             */
/*   Updated: 2018/09/12 14:58:12 by smtetwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		execute(char *path, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
		ft_putendl("\033[31mfork failed\033[0m");
	wait(&pid);
	return (1);
}

static void		print_error(char *str)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(str);
}

static int		exec_path_bin(char **args, char **paths)
{
	int			i;
	struct stat	fstat;
	char		*tmp;
	char		*tmp1;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		tmp1 = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (lstat(tmp1, &fstat) != -1)
		{
			if (fstat.st_mode & S_IXUSR)
			{
				execute(tmp1, args);
				free(tmp1);
				return (1);
			}
		}
		free(tmp1);
	}
	return (0);
}

int				exec_bin(char **args)
{
	int			t;
	struct stat	fstat;
	char		**paths;

	t = 0;
	if (lstat(args[0], &fstat) != -1)
	{
		if (fstat.st_mode & S_IXUSR)
		{
			execute(args[0], args);
			return (1);
		}
	}
	paths = ft_strsplit(locate_env("PATH"), ':');
	if (!paths || paths[0] == NULL)
		print_error(args[0]);
	else
	{
		t = exec_path_bin(args, paths);
		if (t == 0)
			print_error(args[0]);
	}
	ft_free_array(paths);
	return (1);
}
