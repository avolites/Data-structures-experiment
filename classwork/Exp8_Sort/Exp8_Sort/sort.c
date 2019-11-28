#include "sort.h"

void StrInsertion(SqList *L)
{
	for (uint32_t i = 2; i <= L->length; ++i)
	{
		if (LT(L->elem[i].key, L->elem[i - 1].key))
		{
			L->elem[0] = L->elem[i];
			L->elem[i] = L->elem[i - 1];
			int32_t j;
			for (j = i - 2; LT(L->elem[0].key, L->elem[j].key); --j)
				L->elem[j + 1] = L->elem[j];
			L->elem[j + 1] = L->elem[0];
		}
	}
}

void BinInsertion(SqList *L)
{
	for (uint32_t i = 2; i <= L->length; ++i)
	{
		L->elem[0] = L->elem[i];
		uint32_t low = 1;
		uint32_t high = i - 1;
		while (low <= high)
		{
			uint32_t m = (low + high) / 2;
			if (LT(L->elem[0].key, L->elem[m].key))
				high = m - 1;
			else
				low = m + 1;
		}
		for (uint32_t j = i - 1; j >= high + 1; --j)
			L->elem[j + 1] = L->elem[j];
		L->elem[high + 1] = L->elem[0];
	}
}

void ShellSort(SqList * L, uint32_t dlta[], uint32_t t)
{
	for (uint32_t i = 0; i < t; ++i)
		ShellInsert(L, dlta[i]);
}

static void ShellInsert(SqList * L, uint32_t dk)
{
	//operation: one round of Shell' sort
	for (uint32_t i = dk + 1; i <= L->length; ++i)
	{
		if (LT(L->elem[i].key, L->elem[i - dk].key))
		{
			L->elem[0] = L->elem[i];
			int32_t j;
			for (j = i - dk; j > 0 && LT(L->elem[0].key, L->elem[j].key); j -= dk)
				L->elem[j + dk] = L->elem[j];
			L->elem[j + dk] = L->elem[0];
		}
	}
}

void Quick(SqList *L, uint32_t low, uint32_t high)
{
	if (low < high)
	{
		uint32_t pivokeyloc;
		pivokeyloc = Partition(L, low, high);
		Quick(L, low, pivokeyloc - 1);
		Quick(L, pivokeyloc + 1, high);
	}
}

static uint32_t Partition(SqList * L, uint32_t low, uint32_t high)
{
	L->elem[0] = L->elem[low];
	KeyType pivokey = L->elem[low].key;
	while (low < high)
	{
		while (low < high && L->elem[high].key >= pivokey)
			--high;
		L->elem[low] = L->elem[high];
		while (low < high && L->elem[low].key <= pivokey)
			++low;
		L->elem[high] = L->elem[low];
	}
	L->elem[low] = L->elem[0];
	return low;
}

void MergeSort(SqList *L)
{
	MSort(L->elem, L->elem, 1, L->length);
}

void Merge(Record SR[], Record TR[], uint32_t i, uint32_t m, uint32_t n)
{
	//operation: sort every two adjacent elements in an "array"
	uint32_t j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
		if (LQ(SR[i].key, SR[j].key))
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	if (i <= m)
		for (uint32_t temp = 0; temp <= m - i; ++temp)
			TR[k + temp] = SR[i + temp];
	if (j <= n)
		for (uint32_t temp = 0; temp <= n - j; ++temp)
			TR[k + temp] = SR[j + temp];
}

void MSort(Record SR[], Record TR[], uint32_t s, uint32_t t)
{
	if (s == t)
		TR[s] = SR[s];
	else
	{
		uint32_t m = (s + t) / 2;
		Record TR2[2000];
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR, s, m, t);
	}
}
