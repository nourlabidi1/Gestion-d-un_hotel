#ifndef MES_H_INCLUDED
#define MES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;


struct offre
{
     float  reduc ;
     DATE  datei;//  cette offre valable  de la datei a la datef
     DATE datef;
};
typedef struct offre OFFRE;


struct extra
{
  float pdp;//prix demi pension
  float pcp;
  float pics;
  float psuite;
};
typedef struct  extra EXTRA;

struct  caracteristique
{
  int nbpisc; // piscine eli lbara
  int nbpiscc; // piscine couvertes
  char vuesurm; // 'v' si vuesurmer et 'f' sinon
  char suite ; // 'v' si il ya des suites
  float prixlpd; //lit et petit dej ( akaal hajaa)
  EXTRA ext;

};
typedef struct caracteristique CARACTERISTIQUE; // nkhammou nahiwha :p

struct hotel
{
 char nomh[50];
 char adresseh[50];
 char ad_emailh[50];
 char faciliteh;
  int  nboffreh;
 OFFRE * offreh; // tableau dynamique des offres existants , ken el tableau feragh yany famesh offre
  CARACTERISTIQUE carac;

};
typedef struct hotel HOTEL;

struct reservation
{
  char nom_hotel[50]; //CODE
  DATE  date_in; //date initiale
  DATE date_fin;
  int nbjours;
  float  facture;
  char demipen; // demi pension , si oui 'v'
  char pencomp;// pension complete
  char aics;//all in clusive
  char suite;
};
typedef struct reservation RESERVATION;
struct client
{
int  CIN;
char nom [50];
char prenom[50];
int numtell;
char ad_email[50];
int  nbreservation;
RESERVATION reser[200];

};
typedef struct client CLIENT;
//---------------------------------------
int saisie();
void remplir_reservation(RESERVATION* , int );
RESERVATION saisie_reservation();
void ajouter_client(CLIENT*,int);
void afficher_tab_reservation(RESERVATION* , int );
 void afficher_reservation(RESERVATION );
 void afficher_client(CLIENT*,int )  ;
OFFRE *allocation_offreh(int );
HOTEL saisie_hotel();
void ajouter_hotel(HOTEL *);
void afficher_hotel(HOTEL*,int);
void  afficher(HOTEL );
void client_annee(CLIENT*, int);
void hotel_annee( HOTEL*,int );


#endif // MES_H_INCLUDED

