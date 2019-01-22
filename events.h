typedef struct date {
	int day ;
	char month[10] ;
	int year ;
} date ;

typedef struct event {
	char description[128] ;
	date date_of_event ;
} event ;

void create_event(int , event[]);
void display_event(int , event[]);
int compar_event(event , event);
void swap_event(event* , event*);
void basic_sort(event[] , int);
void selection_sort(event[] , int);
void bubble_sort(event[] , int);
void insertion_sort(event[],int);
void set_compteur( long long int);
long long int get_compteur();
int clock2();