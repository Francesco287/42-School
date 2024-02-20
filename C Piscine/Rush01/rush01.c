#include <unistd.h>
#define SIDE 4

void update_control_array(int ca[SIDE][SIDE], int pos[SIDE][SIDE])
{
	int max[SIDE] = {0, 3, 3, 0};
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			if (ca[i][j] != max[pos[i][j]])
			{
				ca[i][j]++;
				return;
			}
			else
				ca[i][j] = 0;
		}
	}
}

int check_matrix(int matrix[SIDE][SIDE])
{
	for (int i = 0; i < SIDE; i++)
	{
		int found[SIDE] = {0};
		for (int j = 0; j < SIDE; j++)
		{
			if (matrix[i][j] != 0)
			{
				if (found[matrix[i][j] - 1])
					return 1;
				else
					found[matrix[i][j] - 1] = 1;
			}
		}
	}
	for (int i = 0; i < SIDE; i++)
	{
		int found[SIDE] = {0};
		for (int j = 0; j < SIDE; j++)
		{
			if (matrix[j][i] != 0)
			{
				if (found[matrix[j][i] - 1])
					return 1;
				else
					found[matrix[j][i] - 1] = 1;
			}
		}
	}
	return 0;
}

void complete_matrix(int matrix[SIDE][SIDE])
{
	int to_change[SIDE][SIDE] = {0};
	for (int i = 0; i < SIDE; i++)
		for (int j = 0; j < SIDE; j++)
			if (matrix[i][j] == 0)
			{
				to_change[i][j] = 1;
				matrix[i][j] = 1;
			}
	while (check_matrix(matrix))
	{
		for (int i = 0; i < SIDE; i++)
			for (int j = 0; j < SIDE; j++)
			{
				if (to_change[i][j])
				{
					if (matrix[i][j] < 4)
					{
						matrix[i][j]++;
						i = SIDE;
						break;
					}
					else
						matrix[i][j] = 1;
				}
			}
	}
}

void	write_matrix(int pos[4][4])
{
	int numbers[SIDE][SIDE][SIDE] = {{{4, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
	                    			{{0, 4, 0, 0}, {3, 0, 4, 0}, {2, 1, 4, 3}, {3, 0, 0, 4}},
	                    			{{0, 3, 4, 0}, {1, 2, 4, 3}, {0, 3, 0, 4}, {2, 1, 3, 4}},
	                    			{{1, 2, 3, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
	int control_array[SIDE][SIDE] = {0};

    int i, j;
	int control = 1;
	while (control)
	{
		int matrix[SIDE][SIDE] = {0};
		control = 0;
		for (int k = 0; k < SIDE; k++)
		{
		    i = 0;
			while (i >= 0 && i < SIDE)
			{
		        if (k == 0 || k == 2)
		            j = 0;
		        else
		            j = SIDE - 1;
		        int y = 0;
			    while (j >= 0 && j < SIDE)
			    {
					if (numbers[pos[k][i]][control_array[k][i]][y] != 0)
					{
						if ((k == 0 || k == 1) && (matrix[j][i] == 0 || matrix[j][i] == numbers[pos[k][i]][control_array[k][i]][y]))
							matrix[j][i] = numbers[pos[k][i]][control_array[k][i]][y];
						else if (k == 0 || k == 1)
						{
							update_control_array(control_array, pos);
							control = 1;
							break;
						}
						if ((k == 2 || k == 3) && (matrix[i][j] == 0 || matrix[i][j] == numbers[pos[k][i]][control_array[k][i]][y]))
							matrix[i][j] = numbers[pos[k][i]][control_array[k][i]][y];
						else if (k == 2 || k == 3)
						{
							update_control_array(control_array, pos);
							control = 1;
							break;
						}
					}
			        if (k == 0 || k == 2)
		                j++;
		            else
		                j--;
		            y++;
			    }
				if (control)
					break;
			    i++;
			}
			if (control)
				break;
		}
		if (check_matrix(matrix) && !control)
		{
			update_control_array(control_array, pos);
			control = 1;
		}
		if (!control)
		{
			complete_matrix(matrix);
			for (int i = 0; i < SIDE; i++)
			{
				for (int j = 0; j < SIDE; j++)
				{
					char c = matrix[i][j] + '0';
					write(1, &c, 1);
					write(1, " ", 1);
				}
				write(1, "\n", 1);
			}
		}
	}
}

int main(int n, char **arg)
{
    char *p = arg[1];
	int pos[SIDE][SIDE];
	for (int i = 0; i < SIDE; i++)
		for (int j = 0; j < SIDE; j++)
			pos[i][j] = p[2 * (SIDE * i + j)] - '0' - 1;
	write_matrix(pos);
	return 0;
}