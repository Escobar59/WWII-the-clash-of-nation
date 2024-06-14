// include permet d'ouvrir des bibliothèques dans notre code //
// include can open libraries in our code //
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Cette fonction permet de pouvoir ouvrir le fichier texte ainsi que de pouvoir le lire et le fermer//
//This function can make open a text, can read the text and to close this// 

//Si jamais le fichier ne s'ouvre pas, un message d'erreur s'affiche//
//If the text don't open, a error text arrived//
void afficherHistoire(int choix, char *fichier_texte) { 
    char filename[20];
    sprintf(filename, fichier_texte, choix);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}


// Procedure qui permet d'afficher si on veut choisir 1 ou 2 //
// Procedure that allows displaying whether one wants to choose 1 or 2 //
void choix_fct()
{
    int choix,langue;

    if (langue == 1)
    {
        printf("Choose 1 or 2 (the other choices will be 2 by defeats) : "); 
    }
    else
    {
        printf("Choisissez 1 ou 2 (Les autres choix seront 2 par défaults) : ");
    }
    
    
}

//This function for the choice of language //
//Cette fonction est pour choisir la langue //
int choix_langue()
{
    int langue;
    printf("In what language do you want play ? \n");
    printf(" \n 1. EN \n 2. FR \n 1 or 2 : ");
    scanf("%d", &langue);
    return langue;
}

int show_map (char *nom, int langue)
{
    int choix;
    char chaineFusionnee[100];
    if(langue == 1)
    {
        strcpy(chaineFusionnee, nom);
        strcat(chaineFusionnee,"_gb.txt");
        afficherHistoire(1, chaineFusionnee);
    }
    else
    {
        strcpy(chaineFusionnee, nom);
        strcat(chaineFusionnee,"_fr.txt");
        afficherHistoire(1, chaineFusionnee);
    }
}

//fonction de choix //
//fuction of choice //

// Cette fonction peut ouvrir les fichiers textes et demande le choix de l'utilisateur, comme 1 ou 2 et il l'enregistre dans une variable "choix" //
//this function can open the text and ask the choice of user, like 1 or 2 and put the answer in the variable "choix" //

//Cette fonction permet d'ouvrir le fichier texte dans la langue que l'utilisateur a choisit//
//This function can open a text in the language of user choice //
int choix_fr(char *nom,int langue)
{
    int choix;
    char chaineFusionnee[100];

    if(langue == 1)
    {
        strcpy(chaineFusionnee, nom);
        strcat(chaineFusionnee,"_gb.txt");
       
    }
    else
    {
        strcpy(chaineFusionnee,nom);
        strcat(chaineFusionnee,"_fr.txt");

    }

    afficherHistoire(1,chaineFusionnee);
    choix_fct();
    scanf("%d", &choix);
    return choix;
}

/*This function can open a text of you choice but where the end you are dead so, printf to exit the game (name is the name of the player) */
/*Cette fonction peut ouvrir un fichier texte de votre choix mais à la fin un message de mort arrive pour que vous quittez */
int mort(char *nom,int langue)
{
    int choix;
    char chaineFusionnee[100];
    const char* str1 = "_gb.txt";
    const char* str2 = "_fr.txt";

    if (langue == 1)
    {
        strcpy(chaineFusionnee,nom);
        strcat(chaineFusionnee,str1);
        afficherHistoire(1, chaineFusionnee);
        printf("\n You Are DEAD ... \n");
        printf("\n press any touch of keyboard to exit  : ");
        scanf("%d", &choix);
        return choix;
    }
    else
    {
        strcpy(chaineFusionnee,nom);
        strcat(chaineFusionnee,str2);
        afficherHistoire(1, chaineFusionnee);
        printf("\n Vous êtes MORT ... \n");
        printf("\n Appuyer sur n'importe quelles toûches de votre clavier  : ");
        scanf("%d", &choix);
        return choix;
    }


}



int main()
{
    int choix, langue;
    afficherHistoire(1, "wwII.txt");
    printf("Word War II : The Clash Of Nations !\n");
    langue = choix_langue();
    printf("%d",langue);
    show_map("map_france", langue);
    if(langue == 1)
    {
        printf("\n Progression in history : \n");
        afficherHistoire(1, "0.txt");
    }
    else
    {
        printf("\n Progression dans l'histoire : \n");
        afficherHistoire(1, "0.txt");
    }
    choix_fr("accueil_france", langue);
        if (choix==1)
        {
            choix_fr("france_1", langue);
            if (choix == 1)
            {
                mort("france_11_121", langue);
            }
            else
            {
                choix_fr("france_12", langue);
                if (choix == 1)
                {
                    mort("france_11_121", langue);
                }
                else 
                {
                    mort("france_122", langue);
                }

            }  
        } 
        else
        {
            choix_fr("france_2", langue);
            if(choix == 1)
            {
               choix_fr("france_21", langue);
                if (choix == 1)
                {
                    mort("france_211_221", langue);
                }
                else
                {
                    choix_fr("france_212_222", langue);
                    choix = 1;
                    if(choix == 1) /*USAAAAAAAAAAAAAAAAAA*/
                    {
                        show_map("map_pearl_habor", langue);
                        afficherHistoire (25, "25.txt");
                        choix_fr("accueil_usa", langue);  
                        if(choix ==1)
                        {
                            choix_fr("usa_1", langue);
                            if(choix == 1)
                            {
                                choix_fr("usa_11", langue);
                                if (choix == 1)
                                {
                                    choix_fr("usa_111", langue);
                                    choix = 1;
                                    if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    {   
                                        show_map("map_stalingrad", langue);
                                        afficherHistoire(50, "50.txt");
                                        choix_fr("accueil_urss", langue);
                                        if (choix == 1)
                                        {
                                            choix_fr("urss_1", langue);
                                            if (choix == 1)
                                            {
                                                mort("urss_11", langue);
                                            }
                                            else
                                            {
                                                choix_fr("urss_12", langue);
                                            if(choix == 1)
                                                {
                                                    mort("urss_121", langue);
                                                }
                                                else
                                                {
                                                    choix_fr("urss_122", langue);
                                                    if (choix == 1)
                                                    {
                                                        mort("urss_1221", langue);
                                                        
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_1222", langue);
                                                        choix = 1;
                                                        if (choix == 1)//ALL
                                                        {
                                                            show_map("map_camp", langue);
                                                            afficherHistoire(75, "75.txt");
                                                            choix_fr("accueil_all", langue);
                                                            if (choix == 1)
                                                            {
                                                                choix_fr("all_1", langue);
                                                                if (choix == 1)
                                                                {
                                                                    mort("all_11", langue);
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_1", langue);
                                                                    }
                                                                } 
                                                            }
                                                            else
                                                            {
                                                                choix_fr("all_2_12", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_121_21", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_122_22_211_1211", langue);
                                                                        afficherHistoire (1, "100.txt");   
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_122_22_211_1211", langue);
                                                                        afficherHistoire (1, "100.txt");
                                                                    }
                                                                    
                                                                }
                                                                
                                                            }
                                                        }
                                                    }
                                                    
                                                }
                                            }
                                        }
                                        else
                                        {
                                            mort("urss_2", langue);
                                        }
                                    }
                                }
                                else
                                {
                                    choix_fr("usa_122", langue);
                                    if(choix == 1)
                                    {
                                        choix_fr("usa_1121", langue);
                                        choix = 1;
                                        if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                        {
                                            show_map("map_stalingrad", langue);
                                            afficherHistoire (50, "50.txt");
                                            choix_fr("accueil_urss", langue);
                                            if (choix == 1)
                                            {
                                                choix_fr("urss_1", langue);
                                                if (choix == 1)
                                                {
                                                    mort("urss_11", langue);
                                                    
                                                }
                                                else
                                                {
                                                    choix_fr("urss_12", langue);
                                                    if(choix == 1)
                                                    {
                                                        mort("urss_121", langue);
                                                        
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_122", langue);
                                                        if (choix == 1)
                                                        {
                                                            mort("urss_1221", langue);
                                                            
                                                        }
                                                        else
                                                        {
                                                            choix_fr("urss_1222", langue);
                                                            choix = 1;
                                                            if (choix == 1)//ALL
                                                            {
                                                                show_map("map_camp", langue);
                                                                afficherHistoire (1, "75.txt");
                                                                choix_fr("accueil_all", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_1", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_11", langue);
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_2_12", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_121_21", langue);
                                                                            if (choix == 1)
                                                                            {
                                                                                choix_fr("all_122_22_211_1211", langue);
                                                                                afficherHistoire (1, "100.txt");
                                                                            }
                                                                            
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                    } 
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_2_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);   
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    
                                                                }
                                                            }
                                                        }
                                                        
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                mort("urss_2", langue);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        choix_fr("usa_1122", langue);
                                        choix = 1;
                                        if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                        {
                                            show_map("map_stalingrad", langue);
                                            afficherHistoire (1, "50.txt");
                                            choix_fr("accueil_urss", langue);
                                            if (choix == 1)
                                            {
                                                choix_fr("urss_1", langue);
                                                if (choix == 1)
                                                {
                                                    mort("urss_11", langue);
                                                }
                                                else
                                                {
                                                    choix_fr("urss_12", langue);
                                                    if(choix == 1)
                                                    {
                                                        mort("urss_121", langue);
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_122", langue);
                                                        if (choix == 1)
                                                        {
                                                            mort("urss_1221", langue);
                                                        }
                                                        else
                                                        {
                                                            choix_fr("urss_1222", langue);
                                                            choix = 1;
                                                            if (choix == 1)//ALL
                                                            {
                                                                show_map("map_camp", langue);
                                                                afficherHistoire (1, "75.txt");
                                                                choix_fr("accueil_all", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_1", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_11", langue);
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_2_12", langue);
                                                                        if (choix== 1)
                                                                        {
                                                                            choix_fr("all_121_21", langue);
                                                                            if (choix == 1)
                                                                            {
                                                                                choix_fr("all_122_22_211_1211", langue);
                                                                                afficherHistoire (1, "100.txt");
                                                                            }
                                                                            
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                    } 
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_2_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);  
                                                                            afficherHistoire (1, "100.txt"); 
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    
                                                                }
                                                            }
                                                        }
                                                        
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                mort("urss_2", langue);
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                mort("usa_12", langue);  
                            }
                        }
                        else 
                        {
                            mort("usa_2", langue);      
                        }
                    }
                }
            }
            else
            {
                choix_fr("france_22", langue);
                if (choix == 1)
                {
                    mort("france_211_221", langue);
                }
                else
                {
                    choix_fr("france_212_222", langue);
                    choix = 1;
                    if(choix == 1) /*USAAAAAAAAAAAAAAAAAA*/
                    {
                        show_map("map_pearl_habor", langue);
                        afficherHistoire (25, "25.txt");
                        choix_fr("accueil_usa", langue);  
                        if(choix ==1)
                        {
                            choix_fr("usa_1", langue);
                            if(choix == 1)
                            {
                                choix_fr("usa_11", langue);
                                if(choix == 1)
                                {
                                    choix_fr("usa_111", langue);
                                    choix = 1;
                                    if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    {
                                        show_map("map_stalingrad", langue);
                                        afficherHistoire (50, "50.txt");
                                        choix_fr("accueil_urss", langue);
                                        if (choix == 1)
                                        {
                                            choix_fr("urss_1", langue);
                                            if (choix == 1)
                                            {
                                                mort("urss_11", langue);
                                            }
                                            else
                                            {
                                                choix_fr("urss_12", langue);
                                                if(choix == 1)
                                                {
                                                    mort("urss_121", langue);
                                                }
                                                else
                                                {
                                                    choix_fr("urss_122", langue);
                                                    if (choix == 1)
                                                    {
                                                        mort("urss_1221", langue);
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_1222", langue);
                                                        choix = 1;
                                                        if (choix == 1)//ALL
                                                        {
                                                            show_map("map_camp", langue);
                                                            afficherHistoire (1, "75.txt");
                                                            choix_fr("accueil_all", langue);
                                                            if (choix == 1)
                                                            {
                                                                choix_fr("all_1", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_11", langue);
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_2_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_122_22_211_1211", langue);
                                                                        afficherHistoire (1, "100.txt");
                                                                    }
                                                                } 
                                                            }
                                                            else
                                                            {
                                                                choix_fr("all_2_12", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_121_21", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_122_22_211_1211", langue);
                                                                        afficherHistoire (1, "100.txt");   
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_122_22_211_1211", langue);
                                                                        afficherHistoire (1, "100.txt");
                                                                    }
                                                                    
                                                                }
                                                                
                                                            }
                                                        }
                                                    }
                                                    
                                                }
                                            }
                                        }
                                        else
                                        {
                                            mort("urss_2", langue);
                                        }
                                    }
                                }
                                else
                                {
                                    choix_fr("usa_112", langue);
                                    if(choix == 1)
                                    {
                                        choix_fr("usa_1121", langue);
                                        choix = 1;
                                        if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                        {
                                            show_map("map_stalingrad", langue);
                                            afficherHistoire (50, "50.txt");
                                            choix_fr("accueil_urss", langue);
                                            if (choix == 1)
                                            {
                                                choix_fr("urss_1", langue);
                                                if (choix == 1)
                                                {
                                                    mort("urss_11", langue);
                                                }
                                                else
                                                {
                                                    choix_fr("urss_12", langue);
                                                    if(choix == 1)
                                                    {
                                                        mort("urss_121", langue);
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_122", langue);
                                                        if (choix == 1)
                                                        {
                                                            mort("urss_1221", langue);
                                                        }
                                                        else
                                                        {
                                                            choix_fr("urss_1222", langue);
                                                            choix = 1;
                                                            if (choix == 1)//ALL
                                                            {
                                                                show_map("map_camp", langue);
                                                                afficherHistoire (75, "75.txt");
                                                                choix_fr("accueil_all", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_1", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_11", langue);
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_2_12", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_121_21", langue);
                                                                            if (choix == 1)
                                                                            {
                                                                                choix_fr("all_122_22_211_1211", langue);
                                                                                afficherHistoire (1, "100.txt");
                                                                            }
                                                                            
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                    } 
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_2_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);  
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    
                                                                }
                                                            }
                                                        }
                                                        
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                mort("urss_2", langue);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        choix_fr("usa_1122", langue);
                                        choix = 1;
                                        if (choix == 1) //URSSSSSSSSSSSSSSSSSSSSSSSSSS
                                        {
                                            show_map("map_stalingrad", langue);
                                            afficherHistoire (1, "50.txt");
                                            choix_fr("accueil_urss", langue);
                                            if (choix == 1)
                                            {
                                                choix_fr("urss_1", langue);
                                                if (choix == 1)
                                                {
                                                    mort("urss_11", langue);
                                                }
                                                else
                                                {
                                                    choix_fr("urss_12", langue);
                                                    if(choix == 1)
                                                    {
                                                        mort("urss_121", langue);
                                                    }
                                                    else
                                                    {
                                                        choix_fr("urss_122", langue);
                                                        if (choix == 1)
                                                        {
                                                            mort("urss_1221", langue);
                                                        }
                                                        else
                                                        {
                                                            choix_fr("urss_1222", langue);
                                                            choix = 1;
                                                            if (choix == 1)//ALL
                                                            {
                                                                show_map("map_camp", langue);
                                                                afficherHistoire (1, "75.txt");
                                                                choix_fr("accueil_all", langue);
                                                                if (choix == 1)
                                                                {
                                                                    choix_fr("all_1", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_11", langue);
                                                                    }
                                                                    else
                                                                    {
                                                                        choix_fr("all_2_12", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_121_21", langue);
                                                                            if (choix == 1)
                                                                            {
                                                                                choix_fr("all_122_22_211_1211", langue);
                                                                                afficherHistoire (1, "100.txt");
                                                                            }
                                                                            
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                    } 
                                                                }
                                                                else
                                                                {
                                                                    choix_fr("all_2_12", langue);
                                                                    if (choix == 1)
                                                                    {
                                                                        choix_fr("all_121_21", langue);
                                                                        if (choix == 1)
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);  
                                                                            afficherHistoire (1, "100.txt"); 
                                                                        }
                                                                        else
                                                                        {
                                                                            choix_fr("all_122_22_211_1211", langue);
                                                                            afficherHistoire (1, "100.txt");
                                                                        }
                                                                        
                                                                    }
                                                                    
                                                                }
                                                            }
                                                        }
                                                        
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                mort("urss_2", langue);
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                mort("usa_12", langue);  
                            }
                        }
                        else 
                        {
                            mort("usa_2", langue);     
                        }
                    }                     
                }
            }
        }        
}
