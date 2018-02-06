#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lecture_fic(char *nom_fic, int niveau) { /* Lecture du fichier contenant les puzzles prédéfinis */
	FILE * fic_gen;
	char cle[4] = "PHV-", puzzle, coord;
	int i, num_puz, nb_case;
	
	fic_gen = fopen(nom_fic,"r");
	fscanf(fic_gen,"%c %i",&puzzle,&num_puz);
	
	while(!feof(fic_gen)) {
		if(puzzle == cle[0] && num_puz == niveau) {
			fscanf(fic_gen,"%c",&coord);
			if(coord == cle[1]) {
				while(coord != cle[2]) {
					fscanf(fic_gen,"%i",&nb_case);
					/* conditions d'insertion */
					fscanf(fic_gen,"%c",&coord);
				}
			}
			if(coord == cle[2]) {
				while(coord != cle[3]) {
					fscanf(fic_gen,"%i",&nb_case);
					/* conditions d'insertion */
					fscanf(fic_gen,"%c",&coord);
				}
			}
		}
		fscanf(fic_gen,"%c %i",&puzzle,&num_puz);
	}
	fclose(fic_gen);
	printf("Sortie du fichier\n");
}

int main() {
	char *saisie = "nombres_puzzle.txt";
	
	lecture_fic(saisie,2);
}
