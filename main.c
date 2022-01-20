
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mesfich.h"

#include<string.h>


int main()
{
     char r='o';
 HOTEL * tab;
 int h,c;
 HOTEL l;

 long rep;
 char e[9];

int choix;
CLIENT* t;
CLIENT clt;
 system("color 9");
//+++++++++++++++++++++++++++++++++++++++++++++++++++
 printf(" /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$         \n");
    printf("| $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/     \n");
    printf("| $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$               \n");
    printf("| $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$             \n");
    printf("| $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/             \n");
    printf("| $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$               \n");
    printf("| $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$      \n ");
    printf("|__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/        \n");
    printf("\n");
      printf("\n"); printf("\n"); printf("\n"); printf("\n");printf("saisir le mot de passe svp ");
      do
     {scanf("%s",&e);
     if (!(strcasecmp(e,"SONIE"))==0)
     {system("color 4");
    printf ("\n mot de passe incorrecte ,veuillez svp retapez le mdp");}}
    while (!(strcasecmp(e,"SONIE"))==0);

if ((strcasecmp(e,"SONIE"))==0)
{system("color 2");
    for(int i=0;i<20;i++)

{
printf("\n\n\n");

         printf("     BIENVENUE CHEZ SONIE VOYAGE \n \n  Reservez maintenant votre hotel en temps reel\n ");
      printf("\n  * * * * * * *   MENU  * * * * * * * * * * \n");
        printf("  *                                       * \n");
        printf("  *      1-ajouter des client             *\n" );
        printf("  *      2- afficher les client           *\n");
        printf("  *      3-ajouter des hotel              *\n");
        printf("  *      4-afficher les hotels            *\n");
        printf("  *      5- le client de l'annee          *\n");
        printf("  *      6- l'hotel de l'annee            *\n");
        printf("  *      7- quitter                       *\n ");
        printf(" *                                       * \n");
        printf("  * * * * * * * * * * * * * * * * * * * * *\n");
        printf("nos contacts \n Adresse:infoe12122@gmail.com \n rue des Entrepreneurs , 3eme etage ,Charguia II - 2035 TUNIS CARTHAGE \n Tel:+(216) 759 952 235 ");
         do
            {
              printf("\n\n >>>> Veuillez choisir une des options donnees \n");
              scanf("%d",&choix);
             }
         while ((choix<1) || (choix>7));

         switch (choix)
         {
             case 1: {printf("\n donner le nombre de client \n");
                     scanf("%d",&c);
                     t=(CLIENT*)malloc(c*sizeof(CLIENT));
                     if (t==NULL) exit (-1);
                     ajouter_client(t, c);

                     };
             break;
               case 2:afficher_client(t,c);
             break;
             case 3:{h=saisie();for (int i=0;i<h;i++)
                                 {
                                     tab=(HOTEL*)malloc(h*sizeof(HOTEL));
                                     if (!tab) exit(-8);
                                      ajouter_hotel(&l);
                                      *(tab+i)=l;
                                      printf("------------------------- \n");

                                      }
                    };
             break;
             case 4:afficher_hotel(tab,h);
             break;
             case 5:client_annee(t,c);
             break;

             case 6:hotel_annee(tab,h);
             break;


         }
if (choix==7)   break;}


printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
printf("\n>>>>Revenez quand vous voudrez, vous etes le bienvenue chez nous.\n");

printf(" \n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

return 0;
}

