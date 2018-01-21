/* 在搜索列表查找指定的元素
 * 前置条件：列表长度为11
 * 后置条件：找到返回1，否则返回0*/

int search(int list[], int length, int item)
{
	int result = 0;
	for (int i = 0; i < lenght; i ++)
	{
		if (list[i] == item)
		{
			result = 1;
			break;
		}
	}

	return result;
}
