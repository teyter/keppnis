#include <stdio.h>
#include <stdlib.h>
int count(int *bits, int N, int l, int r) {
	//printf("Right:%d:%d, Left:%d:%d, Right-Left:%d\n", r, bits[r], l, bits[l], bits[r]-bits[l]);
	for (int i = 0; i < N; i++) {
		//printf("%d",bits[i]);
	}
	//printf("\n");

	if (l > 1) {
		return bits[r]-bits[l-1];
	}
	return bits[r];
}

void teitur(int *bits, int c, int N) {
	int teitur;
	// hvort a ad increment eda decrement
	if (bits[c] != bits[c-1]) {
		teitur = -1;
	} else {
		teitur = 1;
	}

	//printf("Flip %d to %d by %d\n",c,N,teitur);
	//print_bits(bits,N);
	for (int i = c; i < N; i++) {
		bits[i] += teitur;		
	}
	//print_bits(bits,N);

}

void print_bits(int *bits, int N) {
	for (int i = 0; i < N; i++) {
		printf("%d", bits[i]);
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%d", i);
	}
	printf("\n");
	printf("=============\n");
}
int main()
{
	int N, K;
	scanf("%d %d\n", &N, &K);
	int bits[N+1];
	char f[K];
	int c[K], d[K];

	// input
	for (int i = 0; i < K; i++) {
		scanf("%c %d %d\n", &f[i], &c[i], &d[i]);
	}

	// nullstilla
	for (int i = 0; i <= N; i++) {
		bits[i] = 0;
	}

	// keyrslan 
	for (int i = 0; i < K; i++) {
		// flip
		if (f[i] == 'F') {
			teitur(bits, c[i], N+1);
		} 
		
		// telja fra l til r
		else if (f[i] == 'C') {
			//printf("From %d to %d\n", c[i], d[i]);
			//printf("Return~~%d\n",count(bits, N, c[i], d[i]));
			printf("%d\n",count(bits, N+1, c[i], d[i]));
			//print_bits(bits,N);
		}
	}
	return 0;
}
