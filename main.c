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

//2 . default students :
void Initialize_Default_Students() {
    if (e == 0) {


        students[0].id = 1;
        strcpy(students[0].nom, "Ahmed Idris");
        students[0].generalnote = 15.0;
        strcpy(students[0].departement, "Info");
        Date[0].year = 2000;
        Date[0].month = 5;
        Date[0].day = 15;
        e++;


        students[1].id = 2;
        strcpy(students[1].nom, "Layla Hassan");
        students[1].generalnote = 12.5;
        strcpy(students[1].departement, "Math");
        Date[1].year = 1999;
        Date[1].month = 8;
        Date[1].day = 22;
        e++;


        students[2].id = 3;
        strcpy(students[2].nom, "Omar Farouk");
        students[2].generalnote = 18.0;
        strcpy(students[2].departement, "Pc");
        Date[2].year = 2001;
        Date[2].month = 2;
        Date[2].day = 10;
        e++;


        students[3].id = 4;
        strcpy(students[3].nom, "Fatima Nour");
        students[3].generalnote = 16.0;
        strcpy(students[3].departement, "Pc");
        Date[3].year = 2002;
        Date[3].month = 2;
        Date[3].day = 20;
        e++;

        students[4].id = 5;
        strcpy(students[4].nom, "Youssef Malik");
        students[4].generalnote = 9.5;
        strcpy(students[4].departement, "Math");
        Date[4].year = 2003;
        Date[4].month = 5;
        Date[4].day = 8;
        e++;

        students[5].id = 6;
        strcpy(students[5].nom, "Zineb Ali");
        students[5].generalnote = 18.0;
        strcpy(students[5].departement, "Info");
        Date[5].year = 2004;
        Date[5].month = 8;
        Date[5].day = 27;
        e++;

        students[6].id = 7;
        strcpy(students[6].nom, "Khadija Elfassi");
        students[6].generalnote = 18.0;
        strcpy(students[6].departement, "Pc");
        Date[6].year = 2004;
        Date[6].month = 9;
        Date[6].day = 14;
        e++;

        students[7].id = 8;
        strcpy(students[7].nom, "Mohamed Bensaid");
        students[7].generalnote = 6.0;
        strcpy(students[7].departement, "svt");
        Date[7].year = 2000;
        Date[7].month = 9;
        Date[7].day = 12;
        e++;

        students[9].id = 9;
        strcpy(students[8].nom, "Omar Farouk");
        students[8].generalnote = 18.0;
        strcpy(students[8].departement, "Pc");
        Date[8].year = 2001;
        Date[8].month = 2;
        Date[8].day = 10;
        e++;

    }
}

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
        printf("L'id : %d\n",e+1);
        students[e].id = e+1;
        printf("Le nom et prenom : ");
        scanf(" %[^\n]", students[e].nom);
        printf("Date de naissance : \n");
        do{
            printf("Annee : ");
            scanf("%d", &Date[e].year);
        if(Date[e].year > 2023 || Date[e].year < 1980){
            printf("entrer une date plus de 1980 et moins de 2023 !\n");
        }else{
            printf("la variable annee est ajoutee avec succes! \n");
            break;
        }

        }while(1);
        do{
            printf("Mois  : ");
            scanf("%d", &Date[e].month);
        if(Date[e].month > 12 || Date[e].month < 1){
            printf("entrez une date de mois valide :\n");
        }else{
            printf("la variable mois est ajoutee avec succes ! \n");
            break;
        }
        }while(1);
        do{
            printf("Jour : ");
    scanf("%d", &Date[e].day);

        if (Date[e].day < 1 || Date[e].day > 31) {
            printf("entrer un jour entre 1 et 31.\n");
        } else if (Date[e].month == 2 && Date[e].day > 28) {
            printf("le jour doit être entre 1 et 28 !\n");  // fevrier 28jour
        } else if ((Date[e].month == 4 || Date[e].month == 6 || Date[e].month == 9 || Date[e].month == 11) && Date[e].day > 30) {
            printf("Ce mois a seulement 30 jours !\n"); //les mois de 30 jour
        } else {
            printf("La variable jour est ajoutee avec succes !\n");
        break;
        }


        }while(1);
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
    char search[100];
    int trouve=0;


    printf("ecrire le nom et prenom de l'etudiant que vous souhaitez rechercher : ");
    scanf(" %[^\n]",search);
    for(int i=0 ; i < e ; i++){
    if(strcmp(search,students[i].nom)==0){
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
        printf("aucun eleve avec ce nom !\n");
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
    int i ;
    student_search();
    int set;
    printf("[1] pour modifier le nom et prenom \n");
    printf("[2] pour modifier la date de naissance \n");
    printf("[3] pour modifier la departement \n");
    printf("[4] pour modifier la note generale \n");
    printf("choisir un choix : ");
    scanf("%d",&set);
    switch(set){
case 1 :
    printf("entrer le nouveaux nom et prenom :");
    scanf(" %[^\n]",students[i].nom);
    break;
case 2 :
    printf("entrer le nouveaux date de naissance :\n");
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
    scanf("%f",&students[i].generalnote);
default :
    printf("Choix invalide. Veuillez reessayer.");
    break;

    }

}
//3. Supprimer un eleve
void Suppr_contact() {
    char name[100];
    char confirmation[3];
    int suppr = 0;
    int i;
    int j;
    printf("Tapez le nom et prenom que vous souhaitez supprimer : ");
    scanf(" %[^\n]", name);
    for (i = 0; i < e; i++) {
        if (strcmp(name, students[i].nom) == 0) {
            suppr = 1;
            break;
        }
    }

    if (suppr == 0) {
        printf("Le nom du contact n'a pas ete trouver ! \n");
    } else {
        printf("Etes vous sur de vouloir supprimer l'eleve '%s' ? (oui/non) : ", name);
        scanf("%s", confirmation);

    if (strcmp(confirmation, "oui") == 0) {
            for (j = i; j < e - 1; j++) {
                students[j] = students[j + 1];
                Date[j] = Date[j + 1];
            }
            e--;
            printf("L'eleve a ete supprime ! \n");
        } else {
            printf("Suppression annulee.\n");
        }
    }
    return;
}

int main() {
    int choix;
    do {
         printf("-------------------------------------\n");
        printf("             MAIN MENU               \n");
        printf("-------------------------------------\n");
        printf("     [1] Ajouter un eleve            \n");
        printf("     [2] Afficher tous les eleves    \n");
        printf("     [3] Rechercher un eleve         \n");
        printf("     [4] Modifier un eleve           \n");
        printf("     [5] Supprimer un eleve          \n");
        printf("     [6] Default students            \n");
        printf("     [0] Quitter                     \n");
        printf("-------------------------------------\n");
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
            case 5 :
                Suppr_contact();
                break;
            case 6 :
                Initialize_Default_Students();
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
