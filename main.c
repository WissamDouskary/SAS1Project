#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEVE 100
#define MAX 100

typedef struct {
    int id;
    char nom[MAX];
    float generalnote;
    char departement[MAX];
} student;

typedef struct {
    int year;
    int month;
    int day;
} dero;

int e = 0;
student students[MAX_ELEVE];
dero Date[MAX];

// 1. Ajoute un eleve :
void Ajouter_eleve() {
    int many;
    printf("Tapez le nombre d'eleves que vous souhaitez ajouter : ");
    scanf("%d", &many);
    if (many + e >= MAX_ELEVE) {
        printf("La liste d'eleves est pleine !\n");
        return;
    }
    for (int i = 0; i < many; i++) {
        printf("L'id : %d\n",i+1);
        students[i].id=i+1;
        printf("Le nom et prenom : ");
        scanf(" %[^\n]", students[e].nom);
        printf("Date de naissance : \n");
        printf("Annee : ");
        scanf("%d", &Date[e].year);
        printf("Mois  : ");
        scanf("%d", &Date[e].month);
        printf("Jour  : ");
        scanf("%d", &Date[e].day);
        printf("Departement : ");
        scanf("%s", students[e].departement);
        printf("Note generale : ");
        scanf("%f", &students[e].generalnote);
        e++;
    }
}

// 2. Afficher les details :
void Affich_Tout() {
    if (e <= 0) {
        printf("Aucun eleve disponible.\n");
    } else {
        printf("Les details des eleves sont :\n");
        for (int i = 0; i < e; i++) {
            printf("=====================================\n");
            printf("id                              : %d\n",students[i].id);
            printf("Nom et prenom de l'eleve %d     : %s\n", i + 1, students[i].nom);
            printf("Date de naissance de l'eleve %d : %d/%d/%d\n", i + 1, Date[i].year, Date[i].month, Date[i].day);
            printf("Departement de l'eleve %d       : %s\n", i + 1, students[i].departement);
            printf("Note generale de l'eleve %d     : %.2f\n", i + 1, students[i].generalnote);
            printf("=====================================\n");
        }
    }
}

//3 .Modifier les information d'un eleve :
void id_search(){
    int o;
    int trouve=0;


    printf("tapez l'id de l'etudiant que vous souhaitez rechercher : ");
    scanf("%d",&o);
    for(int i=0 ; i < e ; i++){
    if(o==students[i].id){
        printf("id                : %d \n",students[i].id);
        printf("le nom et prenom  : %s \n",students[i].nom);
        printf("date de naissance : %d/%d/%d \n",Date[i].year,Date[i].month, Date[i].day);
        printf("departement       : %s \n",students[i].departement);
        printf("note generale     : %.2f \n",students[i].generalnote);
     trouve = 1;
     break;
    }


    }
    if(trouve==0){
        printf("aucun eleve avec ce id !\n");
    }
}
void name_search(){
    char o;
    int trouve=0;


    printf("ecrire le nom et prenom de l'etudiant que vous souhaitez rechercher : ");
    scanf(" %[^\n]",o);
    for(int i=0 ; i < e ; i++){
    if(strcmp(o,students[i].nom)==0){
        printf("id                : %d \n",students[i].id);
        printf("le nom et prenom  : %s \n",students[i].nom);
        printf("date de naissance : %d/%d/%d \n",Date[i].year,Date[i].month, Date[i].day);
        printf("departement       : %s \n",students[i].departement);
        printf("note generale     : %.2f \n",students[i].generalnote);
     trouve = 1;
     break;
    }


    }
    if(trouve==0){
        printf("aucun eleve avec ce id !\n");
    }


}
void student_search(){
    int mod;
    printf("[1] rechercher avec id.\n");
    printf("[2] rechercher avec nom.\n");
    printf("choisir un choix : ");
    scanf("%d",&mod);
    switch(mod){
case 1 :
    id_search();
    break;
case 2 :
    name_search();
    break;
    }
}
void modify_student(){
    student_search();
    int set;
    printf("[1] pour modifier le nom et prenom \n");
    printf("[2] pour modifier la date de naissance \n");
    printf("[3] pour modifier la departement \n");
    printf("[4] pour modifier la note generale \n");
    printf("choisir un choix : ");
    scanf("%d",&set);
    for(int i = 0 ; i< e ; i++){
    switch(set){
case 1 :
    printf("entrer le nouveaux nom et prenom :");
    scanf(" %[^\n]",students[i].nom);
    break;
case 2 :
    printf("entrer le nouveaux date de naissance :");
    printf("Annee : ");
    scanf("%d",&Date[i].year);
    printf("Mois  : ");
    scanf("%d",&Date[i].month);
    printf("Jour  : ");
    scanf("%d",&Date[i].day);
    break;
case 3 :
    printf("entrer le nouveaux departement :");
    scanf("%s",students[i].departement);
    break;
case 4 :
    printf("entrer le nouveaux note generale :");
    scanf("%f",students[i].generalnote);
default :
    printf("Choix invalide. Veuillez reessayer.");
    break;

    }
    }
}

int main() {
    int choix;
    do {
        printf("-------------------------------------\n");
        printf("             MAIN MENU           \n");
        printf("\n----------------------------------- \n");
        printf("\n     [1] ajouter un eleve        \n");
        printf("     [2] afficher tout les eleves\n");
        printf("     [3] rechercher un eleve         \n");
        printf("     [3] modifier un eleve           \n");
        printf("\n------------------------------------\n");
        printf("\nentre un choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                Ajouter_eleve();
                break;
            case 2:
                Affich_Tout();
                break;
            case 3 :
                student_search();
                break;
            case 4 :
                modify_student();
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
