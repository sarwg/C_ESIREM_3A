#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "events.h"
#include <time.h>

int main(){

    long long int i ;
    // création des tableaux qui contiendrons le nombre d'iterations

    long long int nb_iteration_10E_1F[4];
    long long int nb_iteration_10E_10F[4];
    //int nb_iteration_10E_100F[4];
    //int nb_iteration_10E_1000F[4];

    long long int nb_iteration_100E_1F[4];
    long long int nb_iteration_100E_10F[4];
    //int nb_iteration_100E_100F[4];
    //int nb_iteration_100E_1000F[4];

    long long int nb_iteration_1000E_1F[4];
    long long int nb_iteration_1000E_10F[4];
    //int nb_iteration_1000E_100F[4];
    //int nb_iteration_1000E_1000F[4];

    // on met les valeurs des tableaux a 0
    for(i = 0 ; i < 4 ; i++){
        nb_iteration_10E_1F[i] = 0 ;
        nb_iteration_10E_10F[i] = 0 ;
        nb_iteration_100E_1F[i] = 0 ;
        nb_iteration_100E_10F[i] = 0 ;
        nb_iteration_1000E_1F[i] = 0 ;
        nb_iteration_1000E_10F[i] = 0 ;
    }

    // 1 fois
    // calule du nb d'itération pour tout les trie avec un tableau de taille 10
    int fois = 1;
    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 10;
        // création du tableau d'évenement
        event events[TAILLE];
        // initialisation du tableau
        create_event(TAILLE ,events);
        // on met le compteur d'itération à 0
        set_compteur(0);
        // on tri avec le basic sort
        basic_sort(events, TAILLE);
        // on stock le nb d'itération dans le tableau
        nb_iteration_10E_1F[0] = get_compteur();
        // puis on recréé un tableaux d'evenements non tri
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        nb_iteration_10E_1F[1] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        nb_iteration_10E_1F[2] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        nb_iteration_10E_1F[3] = get_compteur();
    }
    // on refait la même chose avec un tableau de taille 100
    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 100;
        event events[TAILLE];
        create_event(TAILLE ,events);
        set_compteur(0);
        basic_sort(events, TAILLE);
        nb_iteration_100E_1F[0] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        nb_iteration_100E_1F[1] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        nb_iteration_100E_1F[2] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        nb_iteration_100E_1F[3] = get_compteur();
    }
    // Puis avec un tableau de taille 1000
    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 1000;
        event events[TAILLE];
        create_event(TAILLE ,events);
        set_compteur(0);
        basic_sort(events, TAILLE);
        nb_iteration_1000E_1F[0] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        nb_iteration_1000E_1F[1] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        nb_iteration_1000E_1F[2] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        nb_iteration_1000E_1F[3] = get_compteur();
    }

    // 10 fois
    // Pour le prochain for nous allons faire tourner les algos plusieurs fois et
    fois = 10;
    long long int basic[fois];
    long long int selection[fois];
    long long int bubble[fois];
    long long int insertion[fois];

    for(i = 0 ; i < fois ; i++){
        basic[i] = 0 ;
        selection[i] = 0 ;
        bubble[i] = 0 ;
        insertion[i] = 0 ;
    }

    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 10;
        event events[TAILLE];
        create_event(TAILLE ,events);
        set_compteur(0);
        basic_sort(events, TAILLE);
        basic[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        selection[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        bubble[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        insertion[i] = get_compteur();
        if( i == (fois-1)){
            int h ;
            long long int tab[4];
            for( h = 0 ; h < 4 ; h++){
                tab[h] = 0 ;
            }
            for(h = 0 ; h < fois ; h++){
                tab[0] = tab[0] + basic[h];
                tab[1] = tab[1] + selection[h];
                tab[2] = tab[2] + bubble[h];
                tab[3] = tab[3] + insertion[h];
            }
            nb_iteration_10E_10F[0] = tab[0]/fois;
            nb_iteration_10E_10F[1] = tab[1]/fois;
            nb_iteration_10E_10F[2] = tab[2]/fois;
            nb_iteration_10E_10F[3] = tab[3]/fois;
        }
    }

    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 100;
        event events[TAILLE];
        create_event(TAILLE ,events);
        set_compteur(0);
        basic_sort(events, TAILLE);
        basic[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        selection[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        bubble[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        insertion[i] = get_compteur();
        if( i == (fois-1)){
            int h ;
            long long int tab[4];
            for( h = 0 ; h < 4 ; h++){
                tab[h] = 0 ;
            }
            for(h = 0 ; h < fois ; h++){
                tab[0] = tab[0] + basic[h];
                tab[1] = tab[1] + selection[h];
                tab[2] = tab[2] + bubble[h];
                tab[3] = tab[3] + insertion[h];
            }
            nb_iteration_100E_10F[0] = (tab[0]/fois);
            nb_iteration_100E_10F[1] = (tab[1]/fois);
            nb_iteration_100E_10F[2] = (tab[2]/fois);
            nb_iteration_100E_10F[3] = (tab[3]/fois);
        }
    }

    for(i = 0 ; i < fois ; i++ ){
        int TAILLE = 1000;
        event events[TAILLE];
        create_event(TAILLE ,events);
        set_compteur(0);
        basic_sort(events, TAILLE);
        basic[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        selection_sort(events,TAILLE);
        selection[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        bubble_sort(events , TAILLE);
        bubble[i] = get_compteur();
        create_event(TAILLE ,events);
        set_compteur(0);
        insertion_sort(events, TAILLE);
        insertion[i] = get_compteur();
        if( i == (fois-1)){
            int h ;
            long long int tab[4];
            for( h = 0 ; h < 4 ; h++){
                tab[h] = 0 ;
            }
            for(h = 0 ; h < fois ; h++){
                tab[0] = tab[0] + basic[h];
                tab[1] = tab[1] + selection[h];
                tab[2] = tab[2] + bubble[h];
                tab[3] = tab[3] + insertion[h];
            }
            nb_iteration_1000E_10F[0] = (tab[0]/fois);
            nb_iteration_1000E_10F[1] = (tab[1]/fois);
            nb_iteration_1000E_10F[2] = (tab[2]/fois);
            nb_iteration_1000E_10F[3] = (tab[3]/fois);
        }
    }

    FILE* fichier = NULL;
    fichier = fopen("data.html","w");

    if (fichier != NULL)
    {
        fprintf(fichier, "%s\n","<!DOCTYPE html><html><head><title>Stats</title></head><body>");
        fprintf(fichier, "%s \n", "<table><tr><td>algo</td><td>itérations 10 éléments 1 fois</td><td>itérations 100 éléments 1 fois</td> <td>itérations 1000 éléments 1 fois</td></tr>");
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>basic_sort</td><td>",nb_iteration_10E_1F[0],"</td><td>",nb_iteration_100E_1F[0],"</td><td>",nb_iteration_1000E_1F[0],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>selection_sort</td><td>",nb_iteration_10E_1F[1],"</td><td>",nb_iteration_100E_1F[1],"</td><td>",nb_iteration_1000E_1F[1],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>bubble_sort</td><td>",nb_iteration_10E_1F[2],"</td><td>",nb_iteration_100E_1F[2],"</td><td>",nb_iteration_1000E_1F[2],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>insertion_sort</td><td>",nb_iteration_10E_1F[3],"</td><td>",nb_iteration_100E_1F[3],"</td><td>",nb_iteration_1000E_1F[3],"</td></tr>" );
        // fprintf(fichier, "%s \n","<tr><td></td><td>",,"</td><td>",,"</td><td>","</td></tr>" );
        fprintf(fichier, "%s \n", "<table><tr><td>algo</td><td>itérations 10 éléments 10 fois</td><td>itérations 100 éléments 10 fois</td> <td>itérations 1000 éléments 10 fois</td></tr>");
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>basic_sort</td><td>",nb_iteration_10E_10F[0],"</td><td>",nb_iteration_100E_10F[0],"</td><td>",nb_iteration_1000E_10F[0],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>selection_sort</td><td>",nb_iteration_10E_10F[1],"</td><td>",nb_iteration_100E_10F[1],"</td><td>",nb_iteration_1000E_10F[1],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>bubble_sort</td><td>",nb_iteration_10E_10F[2],"</td><td>",nb_iteration_100E_10F[2],"</td><td>",nb_iteration_1000E_10F[2],"</td></tr>" );
        fprintf(fichier, "%s %lld %s %lld %s %lld %s \n","<tr><td>insertion_sort</td><td>",nb_iteration_10E_10F[3],"</td><td>",nb_iteration_100E_10F[3],"</td><td>",nb_iteration_1000E_10F[3],"</td></tr>" );
        fprintf(fichier, "%s\n", "</table>" );
        fprintf(fichier, "%s\n","</body></html>" );
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
    fclose(fichier);
    return 0;
}