/*
���������ѣ����������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ���
ƽ��ʱ�临�Ӷȣ�O(n*log2n)
���ʱ�临�Ӷȣ�O(n*log2n)
�ռ临�Ӷȣ� O(1)
���ݶ����ȶ��ԣ����ȶ�
*/
#include <iostream>
#include <algorithm>

void max_heapify(int arr[], int start, int end)
{
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)	//���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])//�ȱȽ������ӽڵ�Ĵ�С��ѡ������
		{
			son++;
		}
		if (arr[dad] > arr[son])//������ڵ�����ӽڵ���������ϣ�ֱ����������
		{
			return;
		}
		else//���򽻻����������ټ����ӽڵ������ıȽ�
		{
			swap(arr[dad], arr(son));
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len)
{
	//��ʼ����i�����һ�����ڵ㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		max_heapify(arr, i, len - 1);
	}
	//�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ������յ�����Ԫ��֮ǰ��Ԫ�أ���ֱ���������
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}


