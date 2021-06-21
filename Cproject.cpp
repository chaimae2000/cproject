#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Ajout();
void Suppression();
int Recherche();
void Modification();
void Affichage();
void Remplissage();
void Triparmoy();
void Triparordrealph();
struct Date{
		int J,M,A;
	};
struct Etudiant
{
	int mat;
	char NP[50];
    struct Date DN;
	float Moy;	
};
struct Etudiant Etud;
main()
{
	int choix;
	char rep;
		system("cls");
		printf("\t Menu\n");
		printf("1-Remplissage \n");
		printf("2-Affichage\n");
		printf("3-Tri par ordre alphabetique \n");
		printf("4-Tri par ordre de mérite\n");
		printf("5-Ajout\n");
		printf("6-Modification\n");
		printf("7-Suppression\n");
		printf("8-Recherche\n");
		printf("9-Quitter\n");
	do{
		printf("\n Entrez Votre Choix:");
		scanf("%d",&choix);
	}while(choix<1||choix>9);
	switch(choix)
	{
		
		case 1:Remplissage();
		break;
		case 2:Affichage();
		break;
		case 4:Triparmoy();
		break;
		case 5:Ajout();
		break;
		case 6:Modification();
		break;
		case 7:Suppression();
		break;
		case 8:Recherche();
		break;
		case 9:break;
	}
}
void Remplissage()
 {
 	int r;
 	FILE *f;
 	f=fopen("Etudiant.txt","a");
 	printf("voulez-vous entrez les informations d'un etudiant(0/1)");
 	scanf("%d",&r);
 	while(r==1)
 	{
 	printf(" Entrer le numero du matricule ");
	scanf("%d",&Etud.mat);
	fflush(stdin);
	printf("\n Entrer le nom et le prenom");
	gets(Etud.NP);
	fflush(stdin);
	printf("\n entrez la date de naissance ");
	printf("\n jj=");
	scanf("%d",&Etud.DN.J);
	fflush(stdin);
	printf("\n mm=");
	scanf("%d",&Etud.DN.M);
	fflush(stdin);
	printf("\n aaaa=");
	scanf("%d",&Etud.DN.A);
	fflush(stdin);
	printf("\n entrez la moyenne");
	scanf("%f",&Etud.Moy);
	fflush(stdin);
	fprintf(f,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,Etud.Moy);	
	printf("voulez-vous entrez les informations d'un autre etudiant(0/1)");
 	scanf("%d",&r);
	 }
	 fclose(f);
 }
int Ajout()
{
	FILE *f;
	f=fopen("Etudiant.txt","a");
	printf("\n Entrer le numero du matricule ");
	scanf("%d",&Etud.mat);
	fflush(stdin);
	printf("\n Entrer le nom et le prenom");
	gets(Etud.NP);
	fflush(stdin);
	printf("\n entrez la date de naissance ");
	printf("\n jj=");
	scanf("%d",&Etud.DN.J);
	fflush(stdin);
	printf("\n mm=");
	scanf("%d",&Etud.DN.M);
	fflush(stdin);
	printf("\n aaaa=");
	scanf("%d",&Etud.DN.A);
	fflush(stdin);
	printf("\n entrez la moyenne\n");
	scanf("%f",&Etud.Moy);
	fflush(stdin);
	fprintf(f,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,Etud.Moy);
	fclose(f);	
}
void Suppression()
{
	int Nmat; 
	FILE *f,*f1;
	f=fopen("Etudiant.txt","r");
	f1=fopen("SupEtudiant.txt","w");
	printf("entrez le Numero du matricule d'étudiant a supprimer");
	scanf("%d",&Nmat);
	do{
		fscanf(f,"%d %s %d-%d-%d %f\n",&Etud.mat,&Etud.NP,&Etud.DN.J,&Etud.DN.M,&Etud.DN.A,&Etud.Moy);
	if(Nmat != Etud.mat)
	{
		fprintf(f1,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,Etud.Moy);
	}
	}
	while(!feof(f));
	fclose(f);
	fclose(f1);
	remove("Etudiant.txt");
	rename("SupEtudiant.txt","Etudiant.txt");
}
int Recherche()
{
	int Nmat;
	FILE *f;
	f=fopen("Etudiant.txt","r");
	printf("entrez le numero du matricule");
	scanf("%d",&Nmat);
	do{
		fscanf(f,"%d %s %d-%d-%d %f\n",&Etud.mat,&Etud.NP,&Etud.DN.J,&Etud.DN.M,&Etud.DN.A,&Etud.Moy);
	fflush(stdin);
	if(Etud.mat == Nmat)
	{
		fclose(f);
		printf("l'Etudiant existe");
		return 1;
	}
	}while(!feof(f));
	fclose(f);
	printf("l Etudiant est introuvable");
	return 0;
}
void Modification()
{
	FILE *f,*f1;
	int Nmat;
	float My;
	f=fopen("Etudiant.txt","r");
	printf("entrez le numero du matricule");
	scanf("%d",&Nmat);
	fflush(stdin);
	f=fopen("Etudiant.txt","r");
	f1=fopen("ModEtudiant.txt","w");
	printf("\n Entrez la nouvelle moyenne :");
	scanf("%f",&My);
	fflush(stdin);
	while(NULL!=feof(f))
	{
		fscanf(f,"%d %s %d-%d-%d %f\n",&Etud.mat,&Etud.NP,&Etud.DN.J,&Etud.DN.M,&Etud.DN.A,&Etud.Moy);
		fflush(stdin);
		if(Nmat==Etud.mat)
		{
			fprintf(f1,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,My);
		}
		if(Nmat!=Etud.mat){
			fprintf(f1,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,Etud.Moy);
		}
	}
	fclose(f);
	fclose(f1);
	remove("Etudiant.txt");
	rename("ModEtudiant.txt","Etudiant.txt");
}
void Affichage()
{
	FILE *f;
	char buffer[100];
	f=fopen("Etudiant.txt","r");
	printf("La liste des etudiants est :\n \n");
	while(fgets(buffer,100,f)!=NULL){
		printf("%s\n",buffer);
	}
	fclose(f);
}
void Triparmoy()
{
	FILE *f;
	FILE *f1;
	int i=0,min,j;
	int k;
	float c;
	float T[50];
	f=fopen("Etudiant.txt","r");
	f1=fopen("EtudiantTri.txt","w");
	do{
		fscanf(f,"%d %s %d-%d-%d %f\n",&Etud.mat,&Etud.NP,&Etud.DN.J,&Etud.DN.M,&Etud.DN.A,&Etud.Moy);
		fflush(stdin);
		T[i]=Etud.Moy;
		i=i+1;
	}while(feof(f)!=NULL);
	for(j=1;j<i;j++)
	{
		
		for(k=j+1;k<i+1;k++)
		{
			if(T[k]>T[j]){
				c=T[j];
				T[j]=T[k];
				T[k]=c;
			}	
		}	
	}
	for(j=0;j<i+1;j++)
	{
		do{
			fscanf(f,"%d %s %d-%d-%d %f\n",&Etud.mat,&Etud.NP,&Etud.DN.J,&Etud.DN.M,&Etud.DN.A,&Etud.Moy);
			fflush(stdin);
			if(T[j]==Etud.Moy)
			{
				fprintf(f1,"%d %s %d-%d-%d %f\n",Etud.mat,Etud.NP,Etud.DN.J,Etud.DN.M,Etud.DN.A,Etud.Moy);
			}
		}while(NULL!=feof);
	}
	printf("le tri est terminer ");
	fclose(f);
	fclose(f1);
	remove("Etudiant.txt");
	rename("EtudiantTri.txt","Etudiant.txt");
}


