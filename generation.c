#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
int mat[N][N];

void affectation_nb_matrice(int mat[N][N],int ligne) {
	
}

void lecture_fic(char *nom_fic, int niveau) { /* Lecture du fichier contenant les puzzles prédéfinis */
	FILE * fic_gen;
	char cle[4] = "PHVF", carac;
	int i, num_ligne, num_puz, nb_case;
	
	fic_gen = fopen(nom_fic,"r");
	fscanf(fic_gen,"%c %i",&carac,&num_puz);
	
	while(!feof(fic_gen)) {
		if(carac == cle[0] && num_puz == niveau) {
			printf("%c %i\n",carac,num_puz);
			for(i = 1; i <= 2; i++) {
				num_ligne = 0;
				
				while(carac != cle[i]) {
					fscanf(fic_gen,"%c",&carac);
				}
				printf("%c",carac);
				fscanf(fic_gen,"%c",&carac);
				while(carac != cle[i+1]) {
					printf("%c",carac);
					if(carac == ' ' || carac == '\n') {
						fscanf(fic_gen,"%i",&nb_case);
						printf("%i",nb_case);
						printf("%i\n",num_ligne);
						if(carac == '\n') num_ligne++;
					}
					fscanf(fic_gen,"%c",&carac);
				}
				printf("\n\n");
			}
		}
		fscanf(fic_gen,"%c %i",&carac,&num_puz);
	}
	fclose(fic_gen);
	printf("Sortie du fichier\n");
}

int main() {
	char *saisie = "nombres_puzzle.txt";
	
	lecture_fic(saisie,2);
}
