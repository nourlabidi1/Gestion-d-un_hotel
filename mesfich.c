#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mesfich.h"
int saisie()
{int h;
    printf("donner le nombre d'hotels");
 scanf("%d",&h);
 return h;
}

// ******************************************************************************

void afficher_tab_reservation(RESERVATION* tab, int n)
 {
     int i;
     for(i=0;i<n;i++)
        afficher_reservation(*(tab+i));
 }
// ******************************************************************************
void afficher_reservation(RESERVATION res)
 {
     printf("le nom du client est %s \n",res.nom_hotel);
      printf("la date initiale %d%d%d\n",res.date_in.jour,res.date_in.mois,res.date_in.annee);
    printf("la date finale %d%d%d\n",res.date_fin.jour,res.date_fin.mois,res.date_fin.annee);
    printf("le nombre de jours %d\n",res.nbjours);
      if((res.demipen)=='v')
        printf("\n le client a choisi demipen \n");
        if((res.pencomp)=='v')
        printf("\n le client a choisi pencom \n");
        if((res.aics)=='v')
        printf("\n le client a choisi aics \n");
      if((res.suite)=='v')
        printf("\n le client a choisi suite \n");
        printf("\n votre facture est :%f ",res.facture);
 }


//***********************************************************

void remplir_reservation(RESERVATION* tab, int n)
 {
     int i;
     for(i=0;i<n;i++)
        *(tab+i)=saisie_reservation();
 }


 //***********************************************************
 RESERVATION saisie_reservation()
 { CLIENT clt;
     RESERVATION res;
     float fac;

    printf("\n donner le nom d'hotel svp \n");
     scanf("%s",&res.nom_hotel);
     printf("\n donner la date d'arrivee \n") ;
     scanf("%d%d%d",&res.date_in.jour,&res.date_in.mois,&res.date_in.annee);
     printf("\n donner la date de depart \n") ;
     scanf("%d%d%d",&res.date_fin.jour,&res.date_fin.mois,&res.date_fin.annee);
    printf("\n donner le nombre de jours  svp \n");
     scanf("%d",&res.nbjours);
         while(1)
     {
         printf("\n retourne v si le client a choisi demi pension sinon retourner f \n");
         scanf("%s",&res.demipen);
         if((res.demipen==('v'))||(res.demipen==('f'))) break;
         }

     while(1)
     {
         printf("\n retourne v si le client a choisi pension complete sinon retourner f \n");
         scanf("%s",&res.pencomp);
         if((res.pencomp==('v'))||(res.pencomp==('f'))) break;
     }
     while(1)
     {
         printf("\n retourne v si le client a choisi all in sinon retourner f \n");
         scanf("%s",&res.aics);
         if((res.aics==('v'))||(res.aics==('f')) )break;
     }



     while(1)
     {
         printf("\n retourne v si le client a choisi une suite  sinon retourner f \n");
         scanf("%s",&res.suite);
         if((res.suite==('v'))||(res.suite==('f'))) break;
         }
  printf("\n donner la facture ")  ;
  scanf("%f",&res.facture);


     return res;
 }

//***********************************************************
void ajouter_client(CLIENT *t,int c)
{
    CLIENT clt;
    int CIN,x,i=0,y,j=0;



 for (i=0;i<c;i++)
 {
      printf("\n donner le CIN du client svp \n");
    scanf("%d",&CIN);

        clt.CIN=CIN;
        printf("\n donner le nom du client sans espace svp \n" );
        scanf("%s",&clt.nom);
        printf("\n donner le prenom du client sans espace svp \n" );
        scanf("%s",&clt.prenom);
        printf("\n donner le mum tell du client svp \n");
        scanf("%d",&clt.numtell);
        printf("\n donner l'adresse mail du client sans espace svp \n" );
        scanf("%s",&clt.ad_email);
        printf("\n donner le nbr de reservation \n" );
        scanf("%d",&clt.nbreservation);
        remplir_reservation(clt.reser,clt.nbreservation);

    *(t+i)=clt;
 }

}
//***********************************************************
  void afficher_client(CLIENT*t,int n)
  {
      for (int i=0;i<n;i++)
      {
          printf("\n le client numero %d",i+1);
           printf("\n le cin est %d",((t+i)->CIN));
   printf("\n le nom est %s",((t+i)->nom));
   printf("\n le prenom %s",((t+i)->prenom));
   printf("\n le numero du tele %d",((t+i)->numtell));
   printf("\n ladresse mail est %s",(t+i)->ad_email);
   printf("\n le nbre de reservation est %d",((t+i)->nbreservation));
   afficher_tab_reservation((t+i)->reser,((t+i)->nbreservation)) ;
      }


  }




//********************************************************
OFFRE * allocation_offreh(int n )
{OFFRE * o;
   o=(OFFRE*)malloc(n*sizeof(OFFRE));
 if (o==NULL) exit (-1);
 return o;
}

// ******************************************************************************
HOTEL saisie_hotel( )
{ HOTEL h;

printf("donner le nom de l'hotel\n");
scanf("%s",h.nomh);
printf("donner l'adresse email de l'hotel \n");
scanf("%s",h.ad_emailh);
printf("donner l'adresse de l'hotel\n");
scanf("%s",h.adresseh);
do
{printf("si il a des facilitees taper v sinon f  ");
scanf("%c",&h.faciliteh);
}
while ((h.faciliteh!='v')&&(h.faciliteh!='f'));
printf("donner le nombre des offres de votre hotel\n ");
 scanf("%d",&h.nboffreh);
 if ((h.nboffreh)!=0)
 {h.offreh=allocation_offreh(h.nboffreh);
 for (int i=0;i<h.nboffreh;i++)
{  printf("donner la somme de la reduction\n");
scanf("%f",&(((h.offreh)+i)->reduc) );

printf("donner la date initiale de l'offre\n");
scanf("%d%d%d",&((((h.offreh)+i)->datei).jour),&((((h.offreh)+i)->datei).mois),&((((h.offreh)+i)->datei).annee)) ;

   printf("donner la date finale de l'offre\n");
scanf("%d%d%d",&((((h.offreh)+i)->datef).jour),&((((h.offreh)+i)->datef).mois),&((((h.offreh)+i)->datef).annee)) ;
}
}
printf("donner le nombre des piscines non couvertes\n");
scanf("%d",&(h.carac.nbpisc));
printf("donner le nombre des piscines  couvertes\n");
scanf("%d",&(h.carac.nbpiscc));
do {
printf("si lhotel a une vue sur mer donner v sinon f\n");
scanf("%c",&h.carac.vuesurm);
}
while (((h.carac.vuesurm)!='v') && ((h.carac.vuesurm)!='f'));
do
{
printf("si lhotel a au moins une suite donner v sinon f\n");
scanf("%c",&h.carac.suite);
}
while (((h.carac.suite)!='v')&&((h.carac.suite)!='f'));
printf("donner le prix de l'offre lit et petit dej\n");
scanf("%f",&h.carac.prixlpd);

printf("donner le prix de demi pension\n ");
scanf("%f",&h.carac.ext.pdp);
printf("donner le prix de  pension complete\n ");
scanf("%f",&h.carac.ext.pcp);
printf("donner le prix de all inclusive\n");
scanf("%f",&h.carac.ext.pics);
printf("donner le prix d'une suite\n");
scanf("%f",&h.carac.ext.psuite);

 return h;
}
// ******************************************************************************
void ajouter_hotel(HOTEL *h)
{

  *h=saisie_hotel();



}
// ******************************************************************************
  void  afficher(HOTEL h)
    {
printf("le nom de l'hotel :%s",h.nomh);
printf("\nl'adresse email de l'hotel :%s",h.ad_emailh);
printf("\n l'adresse de l'hotel:%s",h.adresseh);
if ((h.faciliteh)=='v')
printf("\n l'hotel a des facilitees ");
else
  printf(" \nl'hotel n'a pas des facilitees ");
printf("\nle nombre des offres de l' hotel est %d",h.nboffreh);
 if ((h.nboffreh)!=0)
{printf("\nles offres de l'hotel sont :");
 for (int i=0;i<h.nboffreh;i++)
  { printf("-----------------");
    printf("\nla somme de la reduction : %f",((h.offreh)+i)->reduc);
    printf("\nla date initiale de l'offre est : %d%d%d",(((h.offreh)+i)->datei).jour,(((h.offreh)+i)->datei).mois,(((h.offreh)+i)->datei).annee) ;
    printf("\nla date finale de l'offre est :%d%d%d",(((h.offreh)+i)->datef).jour,(((h.offreh)+i)->datef).mois,(((h.offreh)+i)->datef).annee) ;
    printf("-----------------");
  }
}
printf("\nle nombre des piscines non couvertes est: %d",h.carac.nbpisc);
printf("\nle nombre des piscines  couvertes est :%d",h.carac.nbpiscc);
if ((h.carac.vuesurm)=='v')
printf("\nhotel a une vue sur mer ");
else
printf("\nl'hotel n'a pas une vue sur mer ");

if ((h.carac.suite)=='v')
printf("\nl'hotel a des suites ");
else
printf("\nl'hotel n'a pas des suites ");

printf(" \nle prix de l'offre lit et petit dejeuner est :%f",h.carac.prixlpd);
printf("\n le prix de demi pension est:%f",h.carac.ext.pdp);
printf("\nle prix de  pension complete est: %f",h.carac.ext.pcp);
printf(" \nle prix de all inclusive est:%f",h.carac.ext.pics);
printf(" \nle prix de  suite est:%f",h.carac.ext.psuite);
}

// ******************************************************************************
   void afficher_hotel( HOTEL* tab , int f)
   { for (int i=0;i<f;i++)
      { printf("l'hotel num %d \n", i+1);
           afficher(*(tab+i));
      }
    }

// ******************************************************************************

void client_annee(CLIENT*tab1,int nb)
{ int i,j,indicemax ;
  float sommemax ,s1 ;

        indicemax=0;
        sommemax=0;
      for(i=0;i<nb;i++)
      {
       s1=0;
       for(j=0;j<(tab1+i)->nbreservation;j++)
       { s1= s1+(tab1+i)->reser[j].facture;
       if (s1> sommemax)
       { indicemax=i;
         sommemax=s1;
       }
       }}
       printf("le meilleur client est de \n : " );
       printf(" CIN %d \n",(tab1+indicemax)->CIN);
       printf(" nom %s \n",(tab1+indicemax)->nom);
       printf(" prenom %s \n",(tab1+indicemax)->prenom);
       printf(" numero tel %d \n",(tab1+indicemax)->numtell);
       printf(" nb reservations %d \n",(tab1+indicemax)->nbreservation);
       printf("sa facture totale %f \n", sommemax);



}

//******************************************************************
void hotel_annee(HOTEL*tab,int h)
 {int i,indicemax,maxnboffreh ;
     maxnboffreh=tab->nboffreh;
     indicemax=0;
     for (i=0;i<h;i++)
     if(((tab+i)->nboffreh)> maxnboffreh)
          {maxnboffreh=(tab+i)->nboffreh;
          indicemax=i;}
 printf("le meilleur hotel dont : \n ");
 printf("le nom %s \n",(tab+indicemax)->nomh);
 printf("adresse %s \n",(tab+indicemax)->adresseh);
 printf("adremail %s \n",(tab+indicemax)->ad_emailh);
 printf(" nombre des offres %d \n",(tab+indicemax)->nboffreh);
 }

