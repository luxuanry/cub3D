#include "../../includes/cub3d.h"

static int	check_first_last_row(char *row)
{
	int	x;
	int	row_len;

	x = 0;
	row_len = ft_strlen(row);
	while (x < row_len)
	{
		if (row[x] == '0')
			return (0);
		x++;
	}
	return (1);
}

static int	check_row_edges(char *row)
{
	int	x;
	int	row_len;

	row_len = ft_strlen(row);
	x = 0;
	while (x < row_len && row[x] == ' ')
		x++;
	if (x < row_len && row[x] != '1')
		return (0);
	x = row_len - 1;
	while (x >= 0 && row[x] == ' ')
		x--;
	if (x >= 0 && row[x] != '1')
		return (0);
	return (1);
}

int	check_border_walls(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		if (y == 0 || y == data->map.height - 1)
		{
			if (!check_first_last_row(data->map.grid[y]))
				return (0);
		}
		else
		{
			if (!check_row_edges(data->map.grid[y]))
				return (0);
		}
		y++;
	}
	return (1);
}

static int	check_adjacent_vertical(t_data *data, int x, int y)
{
	int	up_len;
	int	down_len;

	if (y > 0)
	{
		up_len = ft_strlen(data->map.grid[y - 1]);
		if (x < up_len && data->map.grid[y - 1][x] == '0')
			return (0);
	}
	if (y < data->map.height - 1)
	{
		down_len = ft_strlen(data->map.grid[y + 1]);
		if (x < down_len && data->map.grid[y + 1][x] == '0')
			return (0);
	}
	return (1);
}

int	check_spaces_validity(t_data *data)
{
	int	x;
	int	y;
	int	row_len;

	y = 0;
	while (y < data->map.height)
	{
		row_len = ft_strlen(data->map.grid[y]);
		x = 0;
		while (x < row_len)
		{
			if (data->map.grid[y][x] == ' ')
			{
				if (!check_adjacent_vertical(data, x, y))
					return (0);
				if (!check_adjacent_horizontal(data->map.grid[y], x, row_len))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
