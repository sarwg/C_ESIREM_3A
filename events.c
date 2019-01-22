#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "events.h"
#include <time.h>

#include <stdlib.h>

#include <stdio.h>

#define TAILLE 10
char months[12][10] = {"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
long long int compteur ;
void create_event(int n ,event event[])
{
	int i ;
	for(i = 0 ; i < n ; i++){
		struct date date_random	;
		int k = rand()%12+1;
		int k1 = k+1;
		sprintf(date_random.month , months[k] ) ; 
		int y = (rand()%2018)+1;
		date_random.year = y ;
		int d = (rand()%31)+1;
		date_random.day = d ;
		sprintf(event[i].description ,"Event-%d-%d-%d", date_random.year , k1 , date_random.day);
		event[i].date_of_event = date_random ;
	}
}
void display_event(int n , event event[])
{
	int i ;
	for(i = 0 ; i < n ; i++)
	{
		printf("%s\n", event[i].description);
	}
}
int compar_event(event e1 , event e2)
{
	if(e1.date_of_event.year < e2.date_of_event.year)
	{
		return -1 ;
	}
	if(e1.date_of_event.year > e2.date_of_event.year)
	{
		return 1 ;
	}
	if(e1.date_of_event.year == e2.date_of_event.year)
	{
		int i ;
		int month1 = 0 ;
		int month2 = 0 ;
		for(i = 0 ; i < 12 ; i ++)
		{
			if(e1.date_of_event.month == months[i])
			{
				month1 = i;
			}
		}
		for(i = 0 ; i < 12 ; i ++)
		{
			if(e2.date_of_event.month == months[i])
			{
				month2 = i;
			}
		}
		if(month1 < month2)
		{
			return -1 ;
		}
		if(month1 > month2)
		{
			return 1 ;
		}
		if(month1 == month2)
		{
			if(e1.date_of_event.day < e2.date_of_event.day)
			{
				return -1 ;
			}
			if(e1.date_of_event.day > e2.date_of_event.day)
			{
				return 1 ;
			}
			if(e1.date_of_event.day == e2.date_of_event.day)
			{
				return 0 ;
			}
		}
	}
	return 0;
}
void swap_event(event *events1 , event *events2 )
{
	compteur ++;
	event tmp;
	tmp = *events1;
	*events1 = *events2;
	*events2 = tmp ;
}
void basic_sort(event events[] , int taille)
{
	int j ;
	int i = 0;
	for (j = 0; j < taille; j++)
	{
		for(i=j+1; i < taille; i++)
		{
			if(compar_event(events[j],events[i]) > 0)
			{
				swap_event(&events[j],&events[i]);
			}
		}
				
	}

}
void selection_sort(event events[] , int taille){
	int i;
	int j;
	int it = TAILLE-1 ;
	int jt = TAILLE ;
	for (i=0; i < it ; i++)
	{
		for (j=i+1; j < jt; j++)
		{
			if(compar_event(events[i],events[j]) > 0)
			{
				swap_event(&events[i],&events[j]);
			}
		}
	}
}
void bubble_sort(event events[] , int taille){
  	int taille2 = taille-1 ;
  	int i,j;
  	for ( i=0 ; i < taille2 ; i++ ) {
    	for ( j=0 ; j < taille2 ; j++ ) {
      		if ((compar_event(events[j],events[j+1]))>0){
				swap_event(&events[j],&events[j+1]);
     	 	}
    	}
  	}
}
void insertion_sort(event events[] , int taille){
	int i ;
	int j ;
	for ( i = 1 ; i < taille ; i ++){
		for ( j = 0 ; j < i ; j ++){
			if ((compar_event(events[j],events[i]))>0){
				swap_event(&events[j],&events[i]);
     	 	}
		}
	}
}
void set_compteur(long long int i){
	compteur = i ;
}
long long int get_compteur(){
	return compteur ;
}
int clock2(){
	return clock();
}
/*int clock2(int i,event events[], int taille){
	int start;
	int end;
	int tps;
	switch (i){
 
	case 1: 
			start = clock();
			basic_sort(events,taille);
			end = clock();
			tps = (end-start);
			break;
	case 2: 
			start = clock();
			selection_sort(events,taille);
			end = clock();
			tps = (end-start);
			break;
 	case 3: 
			start = clock();
			bubble_sort(events,taille);
			end = clock();
			tps = (end-start);
			break;
	case 4: 
			start = clock();
			insertion_sort(events,taille);
			end = clock();
			tps = (end-start);
			break;
	default:
		tps=0;
		break;
	}
	return tps;
}*/