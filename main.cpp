#include <stdio.h>
#include "heap.h"

int main()
{
	int A[]={6,2,3,5,4};
	int B[]={423,243,4231,75,332,797,423};

	heap<int> h0;
	heap<int> h(A,A+5);

	int i;
	for (i=0;i<5;++i)
	{
		printf("pop : %d\t",h.pop());
		printf("size:%d\n",h.size());
	}

	for (i=0;i<5;++i)
	{
		h.push(i);
		printf("top is %d\t",h.top());
		printf("size:%d\n",h.size());
	}

	for (i=0;i<5;++i)
	{
		printf("pop %d\n",h.pop());
	}

	h0.assign(B,B+5);
	for (i=0;i<5;++i)
	{
		printf("pop %d\n",h0.pop());
	}
	system("pause");
	return 0;
}