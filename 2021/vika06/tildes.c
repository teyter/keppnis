#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000001
int p[MAXN]; // = [-1, -1, ..., -1]

int find(int x)
{
	return p[x] < 0 ? x : (p[x] = find(p[x]));
}
void join(int x, int y)
{
	int rx = find(x), ry = find(y);
	if (rx == ry) return;
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
	else p[rx] += p[ry], p[ry] = rx;
}

int main()
{
	for (int i = 0; i < MAXN; i++) 
    {
        p[i] = -1;
    }

    int N, Q;
    scanf("%d %d\n", &N, &Q);
    char op;
    int left;
    int right;
    for (int i = 0; i < Q; i++)
    {
        scanf("%c",&op);
        if (op == 's')
        {
            scanf("%d\n",&left);
            printf("%d\n",abs(p[find(left)]));
        }
        else if (op == 't')
        {
            scanf("%d %d\n",&left,&right);
            join(left,right);
        }
    }
}
