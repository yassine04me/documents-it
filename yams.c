#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NB_TOURS 13

// Noms des categories pour l'affichage
const char* categories[NB_TOURS] = {
    "As", "Deux", "Trois", "Quatre", "Cinq", "Six",
    "Brelan", "Carre", "Full", "Petite Suite", 
    "Grande Suite", "YAMS", "Chance"
};

// Tableau de score du joueur (-1 signifie case vide)
int grille[NB_TOURS];

// Fonction pour initialiser la grille
void initialiser_grille() {
    for (int i = 0; i < NB_TOURS; i++) {
        grille[i] = -1;
    }
}

// Fonction pour afficher la grille de score
void afficher_grille() {
    printf("\n--- VOTRE GRILLE DE SCORE ---\n");
    for (int i = 0; i < NB_TOURS; i++) {
        printf("%2d. %-15s : ", i + 1, categories[i]);
        if (grille[i] == -1) {
            printf("[ Vide ]\n");
        } else {
            printf("%d points\n", grille[i]);
        }
    }
    printf("-----------------------------\n");
}

// Fonction pour lancer ou relancer les des
void lancer_des(int des[], bool garder[]) {
    for (int i = 0; i < 5; i++) {
        if (!garder[i]) {
            des[i] = (rand() % 6) + 1; // Nombre entre 1 et 6
        }
    }
}

// Nouvelle fonction pour afficher les des de facon graphique (ASCII Art)
void afficher_des(int des[]) {
    printf("\nVos des :\n");
    
    // 1. Bordure superieure
    for (int i = 0; i < 5; i++) printf(" -------  ");
    printf("\n");

    // 2. Ligne du haut des points
    for (int i = 0; i < 5; i++) {
        if (des[i] == 1) printf("|       | ");
        else if (des[i] == 2 || des[i] == 3) printf("| o     | ");
        else printf("| o   o | ");
    }
    printf("\n");

    // 3. Ligne du milieu des points
    for (int i = 0; i < 5; i++) {
        if (des[i] == 1 || des[i] == 3 || des[i] == 5) printf("|   o   | ");
        else if (des[i] == 6) printf("| o   o | ");
        else printf("|       | ");
    }
    printf("\n");

    // 4. Ligne du bas des points
    for (int i = 0; i < 5; i++) {
        if (des[i] == 1) printf("|       | ");
        else if (des[i] == 2 || des[i] == 3) printf("|     o | ");
        else printf("| o   o | ");
    }
    printf("\n");

    // 5. Bordure inferieure et numero du de en dessous
    for (int i = 0; i < 5; i++) printf(" -------  ");
    printf("\n");
    for (int i = 0; i < 5; i++) printf("   De %d   ", i + 1);
    printf("\n\n");
}

// Fonction principale pour calculer les points d'une combinaison
int calculer_points(int des[], int choix) {
    int compte[7] = {0}; // Compte l'occurrence de chaque face (index 1 a 6)
    int somme_totale = 0;

    for (int i = 0; i < 5; i++) {
        compte[des[i]]++;
        somme_totale += des[i];
    }

    // Index 0 a 5 correspondent aux nombres de 1 a 6
    if (choix >= 0 && choix <= 5) {
        return compte[choix + 1] * (choix + 1);
    }

    switch (choix) {
        case 6: // Brelan (au moins 3 des identiques)
            for (int i = 1; i <= 6; i++) if (compte[i] >= 3) return somme_totale;
            return 0;

        case 7: // Carre (au moins 4 des identiques)
            for (int i = 1; i <= 6; i++) if (compte[i] >= 4) return somme_totale;
            return 0;

        case 8: // Full (3 identiques + 2 identiques)
            {
                bool a_trois = false, a_deux = false;
                for (int i = 1; i <= 6; i++) {
                    if (compte[i] == 3) a_trois = true;
                    if (compte[i] == 2) a_deux = true;
                }
                if (a_trois && a_deux) return 25;
                // Cas special : un Yams (5) peut compter comme un Full
                for (int i = 1; i <= 6; i++) if (compte[i] == 5) return 25;
                return 0;
            }

        case 9: // Petite Suite (4 des qui se suivent)
            if ((compte[1] && compte[2] && compte[3] && compte[4]) ||
                (compte[2] && compte[3] && compte[4] && compte[5]) ||
                (compte[3] && compte[4] && compte[5] && compte[6])) {
                return 30;
            }
            return 0;

        case 10: // Grande Suite (5 des qui se suivent)
            if ((compte[1] && compte[2] && compte[3] && compte[4] && compte[5]) ||
                (compte[2] && compte[3] && compte[4] && compte[5] && compte[6])) {
                return 40;
            }
            return 0;

        case 11: // YAMS (5 des identiques)
            for (int i = 1; i <= 6; i++) if (compte[i] == 5) return 50;
            return 0;

        case 12: // Chance
            return somme_totale;

        default:
            return 0;
    }
}

int main() {
    srand(time(NULL)); // Initialisation de l'aleatoire
    initialiser_grille();
    
    int des[5];
    bool garder[5] = {false};
    int total_points = 0;

    printf("=== BIENVENUE DANS LE JEU DE YAMS EN C ===\n");

    for (int tour = 0; tour < NB_TOURS; tour++) {
        printf("\n*** TOUR %d / %d ***\n", tour + 1, NB_TOURS);
        
        // Reinitialiser les des gardes au debut du tour
        for(int i=0; i<5; i++) garder[i] = false;

        // Les 3 lancers
        for (int lancer = 1; lancer <= 3; lancer++) {
            printf("\n-- Lancer %d --\n", lancer);
            lancer_des(des, garder);
            afficher_des(des);

            if (lancer < 3) {
                int choix;
                printf("Voulez-vous relancer certains des ? (1 = Oui, 0 = Non, garder tout) : ");
                scanf("%d", &choix);
                
                if (choix == 0) break; // Le joueur s'arrete avant le 3eme lancer

                printf("Entrez 1 pour GARDER le de, 0 pour le RELANCER :\n");
                for (int i = 0; i < 5; i++) {
                    printf("Garder le De %d (valeur %d) ? (1=Oui / 0=Non) : ", i + 1, des[i]);
                    int g;
                    scanf("%d", &g);
                    garder[i] = (g == 1) ? true : false;
                }
            }
        }

        // Enregistrement du score
        afficher_grille();
        int choix_categorie;
        
        while (1) {
            printf("\nChoisissez une categorie vide (1 a 13) pour inscrire votre score : ");
            scanf("%d", &choix_categorie);
            choix_categorie--; // Ajustement pour l'index du tableau (0 a 12)

            if (choix_categorie >= 0 && choix_categorie < NB_TOURS && grille[choix_categorie] == -1) {
                int points = calculer_points(des, choix_categorie);
                grille[choix_categorie] = points;
                printf("=> Vous avez marque %d points dans la categorie %s !\n", points, categories[choix_categorie]);
                break;
            } else {
                printf("Erreur : categorie invalide ou deja remplie. Reessayez.\n");
            }
        }
    }

    // Calcul du score final
    int somme_haut = 0, somme_bas = 0;
    for (int i = 0; i < 6; i++) somme_haut += grille[i];
    for (int i = 6; i < 13; i++) somme_bas += grille[i];

    int bonus = (somme_haut >= 63) ? 35 : 0;
    total_points = somme_haut + bonus + somme_bas;

    printf("\n=== FIN DE LA PARTIE ===\n");
    afficher_grille();
    printf("Total partie superieure : %d\n", somme_haut);
    if (bonus > 0) printf("BONUS OBTENU ! (+35 points)\n");
    printf("Total partie inferieure : %d\n", somme_bas);
    printf("-----------------------------\n");
    printf("SCORE FINAL : %d points\n", total_points);

    return 0;
}
