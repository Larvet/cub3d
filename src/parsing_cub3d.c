#include "cub3d.h"

char	**read_file(char *filename)
{
	t_str	*strlist;
	t_str	*tmp;
	char	**tab;
	char	*line;
	int		fd;

	strlist = NULL;
	tab = NULL;
	fd = open(filename);
	if (fd != -1)
	{
		line = get_next_line(fd);
		while (line)
		{
			tmp = t_str_new(line);
			if (tmp)
				t_str_addback(&strlist, tmp);
			else
				// error handling
			// don't free here (destructor)
			line = get_next_line(fd);
		}
		tab = strlist_to_tab(strlist);
		if (!tab)
			// error handling
	}
	else
		// error handling
	return (tab);
}