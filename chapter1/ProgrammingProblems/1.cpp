/* 按照行序，搜索n*n矩阵mat来查找等于item的元素 */
bool found = false;

for (int row = 0; row < n; row++)
{
	if (found)
	{
		break;
	}

	for (int col = 0; col < n; col++)
	{
		if (mat[row][col] == item)
		{
			cout << "item found\n";
			break ;
		}
	}
}

if (found)
{
	cout << "item found\n";
}
else 
{
	cout << "item not found\n";
}
