                                                        /*IL ROBOT */
/*Il progetto ha la finalità di creare un algoritmo in linguaggio C che simuli il movimento di un robot,il quale sceglie la direzione da seguire
in base a determinati criteri,all'interno di una stanza le cui pareti cambiano posizione da test a test in modo randomico,fino al momento in cui il
robot arriverà all'uscita della stessa stanza. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creazione_stanza(char a[][100],int n,int m);
void stampa_stanza(char a[][100],int n,int m);
void spost_robot(char a[][100],int n,int m);
int dist_up(char a[][100],int n,int m,int i,int j);
int dist_down(char a[][100],int n,int m,int i,int j);
int dist_right(char a[][100],int n,int m,int i,int j);
int dist_right(char a[][100],int n,int m,int i,int j);
int dist_left(char a[][100],int n,int m,int i,int j);

/*Il main principale si occupa di richiamare le varie funzioni utilizzate per simulare i movimenti del robot all'interno della stanza e
di spiegare i simboli che useremo per rappresentare le pareti della stanza il robot e gli spazzi in cui esso si muoverà.*/
int main()
{
    /*Come struttura per rappresentare la stanza viene utilizzata una matrice di caratteri la quale però viene resa
    dinamica tramite gli input e size della matrice n ed m, rispettivamente lunghezza e profondità della stanza i quali
    vengono assegnati da tastiera. Le pareti così come il robot si muoveranno in base a tali dimensioni,per ragioni di
    spazio come test viene usata una matrice 10x10.Le funzioni che andremo a richiamre nel main sono creazione_stanza e
    spost_robot che andremo a spiegare nello specifico più avanti.*/
    system("color 02");
    char stanza[100][100];
    int n,m,hu;
    do{
        printf("\n\t\t\t\t*IL ROBOT*");
        printf("\n\t-Benvenuto nel sistema di simulazione del robot");
        printf("\n\t-Digitare le dimensioni della stanza per iniziare la simulazione");
        printf("\n\t-Lunghezza stanza:");
        scanf("%d",&n);
        printf("\t-Profondita' stanza:");
        scanf("%d",&m);
        printf("\t-Legenda simboli\n\n\t-P=parete\n\n\t-' '=casella di movimento\n\n\t-R=robot\n\n\t-S=posizione precedente del robot");
        printf("\n\n\t-Mappa stanza\n");
        creazione_stanza(&stanza[0][0],n,m);
        spost_robot(&stanza[0][0],n,m);
        printf("\n");
        printf("\n\tVuoi simulare di nuovo? (0 == No || 1 == Si)\n\tScegli: ");
        scanf("%d",&hu);
        system("cls");
    }while( hu==1);
    system("cls");
    system("pause");
    return 0;
}


/*La funzione creazione_stanza si occupa della creazione delle pareti esterne,nonchè contorno della stanza, ed interne generate le quali vengono
generate randomicamente. Entrambe si addatterano al size della matrice la quale è resa appunto dinamica,i parametri i quali vengono passati a tale
funzione sono la matrice di char, cioè la stanza, e n ed m cioè il size di tale matrice, entrambi dichiarati nel main.*/
void creazione_stanza(char a[][100],int n,int m)
{
/*Come prima cosa andremo a definire i contorni della stanza tramite dei cicli for che inseriranno le pareti simboleggiate da delle P con l'ausilio
delle variabili i e j*/

    int i,j,k,h,parete;

/*Tramite questo ciclo for viene creata la prima parete,quella di sinistra, tenendo fisso l'indice di colonna a 0 e variando l'indice di riga fino
 ad n-1*/
    for(i=0;i<n;i++){
        a[i][0]='P';

    }
/*Per creare la parete di destra viene utilizzato lo stesso procedimento per la parete precedente solo che stavolta l'indice di colonna viene tenuto
fisso ad m-1 cioè l'indice estremo di destra*/
    for(i=0;i<n;i++){
        a[i][m-1]='P';
        }

/*La parete di sopra viene creata tenendo fisso a 0 stavolta l'indice di riga e facendo variare l'indice di colonna j da un valore da 0 fino ad m-1*/
    for(j=0;j<m;j++){
        a[0][j]='P';
        }
/*Lo stesso procedimento viene applicato alla parete di sotto solo che l'indice di riga viene tenuto fisso ad n-1*/
    for(j=0;j<m;j++){
        a[n-1][j]='P';
        }

/*Una volta creato il contorno della stanza viene riempito il suo interno con le caselle di movimento del robot rappresentate da ' ', la struttura
utilizzata è un doppio for i cui estremi sono 1 fino ad n-2 per la riga ed 1 fino ad m-2 per la colonna in modo da non andare ad intaccare le pareti
di contorno precedentemente create,la stanza viene riempita facendo variare stavolta entrambi gli indici i e j nei limiti sopra citati*/
    for(i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            a[i][j]=' ';
        }
    }

/*Le pareti interne richiedono la proprietà di essere generate in modo randomico per cui utilizzeremo le funzioni rand() che genera numeri pseudo
casuali e la funzione srand(time(NULL)) la quale fa in modo di cambiare il seed da cui generare i numeri casuali in base all'orario segnato dal sistema
in questo modo si evita di avere una generazione uquale nei vari casi in cui utilizzeremo la funzione rand(),la peculiarità è che le pareti riescono
ad adattarsi alla grandezza della stanza. Per gestire ciò viene utilizzato un ciclo while dove le pareti raggiungono una lunghezza casuale data dalla
generazione di parete, nel caso in cui la lunghezza della parete potrebbe risultare inutilizzabile viene assegnata una lunghezza pari a 3 in modo da
non creare problemi.Le pareti possono essere solo verticali o orizzontali, la prima viene resa muovendo rispettivamente l'indice i e j.Infine viene
creata un uscita la quale anch'essa si adatta alle dimensioni della stanza lavorando su parametri n ed m messi da tastiera.*/

/*Prima parete interna verticale*/
    srand(time(NULL));
    k=0;
    parete=1+rand()%(n-4);
    if(parete<0){
        parete=3;
    }
    i=1+rand()%(n-2);
    j=1+rand()%(m-2);
    while(k!=parete){
        a[i][j]='P';
        i++;
        k++;
    }

    /*Prima parete intera orizzontale */
    k=0;
    parete=1+rand()%(m-4);
    if(parete<0){
        parete=3;
    }
    i=1+rand()%(n-2);
    j=1+rand()%(m-2);
    while(k!=parete){
        a[i][j]='P';
        j++;
        k++;
    }

    /*Seconda parete interna verticale*/
    k=0;
    parete=1+rand()%(n-4);
    if(parete<0){
        parete=3;
    }
    i=1+rand()%(n-2);
    j=1+rand()%(m-2);
    while(k!=parete){
        a[i][j]='P';
        i++;
        k++;
    }

    /*Seconda parete interna orizzontale*/
    k=0;
    parete=1+rand()%(m-4);
    if(parete<0){
        parete=3;
    }
    i=1+rand()%(n-2);
    j=1+rand()%(m-2);
    while(k!=parete){
        a[i][j]='P';
        j++;
        k++;
    }

    /*Uscita*/
    a[n-5][0]=' ';
    a[n-4][0]=' ';
}

/*La void stampa stanza è la funzione che ci permetterà di stampare la stanza una volta creata ,richiamandola nel main e successivamente richiamndola
nella funzione che si occupa del movimento del robot ci permette di visualizzare i vari spostamenti del robot. La stampa a video della stanza viene
resa tramite un doppio ciclo for annidato il quale muovendosi sugl'indici i e j stampa la matrice con i valori assegnatigli precedentemente in ogni
posizione.*/
void stampa_stanza(char a[][100],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++){
        printf("\n\t");
        for(j=0;j<m;j++){
            printf("%c ",a[i][j]);
        }
    }
}

/*La function spost_robot si occupa di piazzare il robot in modo casuale nela stanza e di farlo muovere.*/
void  spost_robot(char a[][100],int n,int m)
{
    int i,j,h,p,up,down,right,left,s,e,x,y;
/*Il robot viene piazzato nella stanza utilizzando la funzione rand() su i e j e assegnando all'elemento a[i][j] una R che simboleggia robot, il robot
non viene mai assegnato in una delle pareti esterne della stanza dato che al rand() di i e j viene sommato uno e l'intervallo in cui possono rientare i
e j sono rispettivamente fino ad n-2 ed m-2.*/
    srand(time(NULL));
    i=1+rand()%(n-2);
    j=1+rand()%(m-2);
    a[i][j]='R';
    stampa_stanza(&a[0][0],n,m);
    printf("\n\n\t-Itinerario robot\n");

/*Lo spostamento del robot viene gestito all'interno di un ciclo while dal quale si esce una volta che il robot raggiunge le cordinate i=n-4 j=0 o
i=m-4 j=0 le quali sono entrambe coordinate dell'uscita della stanza.All'interno del while viene assegnato ap tramite generazione casuale un numero tra
0 e 99,se il numero e <30 allora il robot si muoverà seguendo il 30% di probabilità,altrimenti scegliera di muoversi nel restante 70%.Se p è minore di
30 allora si entrera nel ciclo if il quale fa si che il robot si muova casualmente in una delle quattro direzioni possibili, la scelta della posizione
è data dal valore assegnato randomicamente ad h in un intervallo che va da 0 a 3 dove 0=sopra,1=sotto,2=right,3=left.Sebbene il robot scelga uno dei
tre movimenti possibili il movimento avviene solo nel caso in cui il robot quando deciderà di muoversi in una direzione non troverà un muro segnalato
da una P o una S che corrisponde alla direzione opposta scelta nello step precednte, entrambe sono gestite giocando sugli indice i e j della matrice
presi ogni volta che il robot efftua un movimento,viene controllato cosa c'è davanti al robot in quella direzione sommando ad uno la i della posizione
del robot in quel momento se questo deve muoversi verso l'alto,sottrarre uno se deve muoversi in basso,sommare uno a j se deve andare a destra,
sottrarre uno se il robot deve muoversi a sinistra, nel caso in cui questo controllo rinvenga una S o una P viene ripetuta l'operazione di random
finchè il robot non sceglierà un movimento possibile.Nel 70% dei casi il robot entrerà nell'else e ripeterà lo stesso procedimento appena illustrato
solo che non sceglierà più randomicamnete la sua direzione, ma sceglierà quella che dista di più da una parete.*/
    while((i!=n-4 || i!=n-5) && j!=0){
        p=rand()%100;
        if(p<30){
            h=rand()%4;
            /*Sopra*/
            if(h==0){
                if(a[i-1][j]!='P'&& a[i-1][j]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    i=i-1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            /*Sotto*/
            if(h==1){
               if(a[i+1][j]!='P'&& a[i+1][j]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    i=i+1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            /*Destra*/
            if(h==2){
                if(a[i][j+1]!='P'&& a[i][j+1]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    j=j+1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            /*Sinistra */
            if(h==3){
                if(a[i][j-1]!='P'&& a[i][j-1]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    j=j-1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
        }
/*All'interno dell'else comè già detto nel commento sopra viene scelta la distanza massima da un muro rispetto alla posizione del robot in quel momento
ciò avviene assegnando ad s cioè la distanza massima iniaziale, tra le varie distanze calcolate tramite delle funzioni,quella alla sinistra del robot.
Questa viene poi confronatata con le altre tramite degli if e scelta quella maggiore la quale farà si che il robot entrerà nel succesivo if corrispondente
e si muova seguendo le regole sopra citate. Nel caso due o più distanze siano uguali il robot sceglie casualmente una delle due tramite un rand
gestito dalla variabile e.*/
        else{
                up=dist_up(&a[0][0],n,m,i,j)-1;
                down=dist_down(&a[0][0],n,m,i,j)-1;
                right=dist_right(&a[0][0],n,m,i,j)-1;
                left=dist_left(&a[0][0],n,m,i,j)-1;

            s=left;
            if(s==right){
                e=rand()%2;
                if(e==0){
                    s=right;
                }
            }
            if(s<right){
                s=right;
            }
            if(s==down){
                e=rand()%2;
                if(e==0){
                    s=down;
                }
            }
            if(s<down){
                s=down;
            }
            if(s==up){
                e=rand()%2;
                if(e==0){
                    s=up;
                }
            }
            if(s<up){
                s=up;
            }
            if(s==up){
                 if(a[i-1][j]!='P'&& a[i-1][j]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    i=i-1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            if(s==down){
                if(a[i+1][j]!='P'&& a[i+1][j]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    i=i+1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            if(s==right){
                if(a[i][j+1]!='P'&& a[i][j+1]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    j=j+1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
            if(s==left){
                 if(a[i][j-1]!='P'&& a[i][j-1]!='S'){
                    a[x][y]=' ';
                    a[i][j]='S';
                    x=i;
                    y=j;
                    j=j-1;
                    a[i][j]='R';
                    stampa_stanza(&a[0][0],n,m);
                    printf("\n");
                }
            }
        }
    }
}
/*Infine vi sono una serie di funzioni dist le quali calcolano la distanza da un muro a partire dalle coordinate i e j del robot passate alle varie
funzioni e che restituiscono le varie distanze*/

/*Distanza sopra*/
int dist_up(char a[][100],int n,int m,int i,int j)
{
    int u=0;
    while(a[i][j]!='P'){
        i=i-1;
        u++;
    }
    return u;
}

/*Distanza sotto*/
int dist_down(char a[][100],int n,int m,int i,int j)
{
    int d=0;
     while(a[i][j]!='P'){
        i=i+1;
        d++;
    }
    return d;
}

/*Distanza destra*/
int dist_right(char a[][100],int n,int m,int i,int j)
{
     int r=0;
     while(a[i][j]!='P'){
        j=j+1;
        r++;
    }
    return r;
}

/*Distanza sinistra*/
int dist_left(char a[][100],int n,int m,int i,int j)
{
     int l=0;
     while(a[i][j]!='P'){
        j=j-1;
        l++;
    }
    return l;
}

