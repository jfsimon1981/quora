#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Debug = 1 pour afficher le detail du calcul
// permet de bien comprendre comment les boucles
// fonctionnent.
// Ensuite Debug = 0 pour afficher le programme normal.

#define DEBUG 0 

void debug3(int i, int j, int k) {
#if DEBUG == 1
	printf("log: %d %% %d = %d\n", i, j, k);
#endif
}


int main(int argc, char *argv[]) {
	int n=0;
	printf("ceci est un generateur de nombres premiers inferieurs ou egaux a N\n\n");
	printf("votre valeur de N svp:\n");
	scanf("%i",&n);
	printf("N = %d\n",n);
	if (n>3) {
		for (int i=3;i<=n;i++) {
			int i_est_premier = 1; // Est presume premier jusqu'a ce que l'on trouve un multiple
			for (int j=2;j<i;j++) { // j Strictement < i
				int r=i%j; // Oui on voit << n'est pas un multiple de >>
				       // Ensuite on doit faire un ET logique pour
				       // s'assurer que nous n'avons trouve aucun
				       // multiple, alors on a bien un nombre premier.
				if (!r) i_est_premier = 0; // Modulo nul => multiple
				debug3(i,j,r); // Pour debuguer on peut afficher les valeurs intermediaires
			}
			if (i_est_premier)
				printf("%d\n",i);
		}
	}
	else printf("\n 3");
	return 0;
}
