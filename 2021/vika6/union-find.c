#include <stdio.h>

#define MAXN 1000000
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
    char op[Q];
    int a[Q];
    int b[Q];
    for (int i = 0; i < Q; i++)
    {
        scanf("%c %d %d\n", &op[i], &a[i], &b[i]);
    }
    for (int i = 0; i < Q; i++)
    {
        char ops = op[i];
        int aa = a[i];
        int bb = b[i];
        if (ops == '?')
        {
            if (find(aa) == find(bb))
                printf("yes\n");
            else
                printf("no\n");
        }
        if (ops == '=')
        {
            join(aa,bb);
        }
    }
}
