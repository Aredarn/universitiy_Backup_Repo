#include <stdio.h>
#include <stdlib.h>

#define URES '-'

/*
 * Otodolo
 * Pálya szélessége és magassága?
 * Pálya létrehozása - 2D tömb (karakter)
 * ...
 * ...
 * Játék megvalósítása
Pálya:

	ABCDEF
   ########
 1 #      #
 2 #   O  #
 3 #  X X #
 4 #  OX  #
 5 #      #
 6 #      #
   ########
*/

typedef struct _palya
{
	unsigned sorok, oszlopok;
	char **tartalom;
} Palya;

//void palyaKirajzol(Palya p)
//{
//	unsigned s, o;
//	printf("    ");
//	for (o=0; o<p.oszlopok; o++)
//		printf("%c", 'A'+o);
//	printf(" \n");
//	printf("   ");
//	for (o=0; o<p.oszlopok+2; o++)
//		printf("#");
//	printf("\n");
//	for (s=0; s<p.sorok; s++)
//	{
//		printf("%2u #", s+1);
//		for (o=0; o<p.oszlopok; o++)
//			printf("%c", p.tartalom[s][o]);
//		printf("#\n");
//	}
//	printf("   ");
//	for (o=0; o<p.oszlopok+2; o++)
//		printf("#");
//	printf("\n");
//}

void palyaKirajzol(Palya p)
{
	unsigned s, o;
	printf("     ");
	for (o=0; o<p.oszlopok; o++)
		printf("%c ", 'A'+o);
	printf("\n");
	printf("   ");
	for (o=0; o<p.oszlopok*2+3; o++)
		printf("#");
	printf("\n");
	for (s=0; s<p.sorok; s++)
	{
		printf("%2u # ", s+1);
		for (o=0; o<p.oszlopok; o++)
			printf("%c ", p.tartalom[s][o]);
		printf("#\n");
	}
	printf("   ");
	for (o=0; o<p.oszlopok*2+3; o++)
		printf("#");
	printf("\n");
}

//int nyertE(Palya p, unsigned sor, unsigned oszlop)
//{
//	int s, o;
//	char aktualis=p.tartalom[sor][oszlop];
//	s=sor;
//	o=oszlop;
//	unsigned mennyi=0;
//	while (o<(int)p.oszlopok && p.tartalom[s][o]==aktualis)
//	{
//		o++;
//		mennyi++;
//	}
//	o=oszlop;
//	o--;
//	while (o>=0 && p.tartalom[s][o]==aktualis)
//	{
//		o--;
//		mennyi++;
//	}
//	if (mennyi>=5) return 1;

//	// ...stb ugyanezt másolva, átírva
//	return 0;
//}

int helyesAzIndex(int s, int o, Palya p)
{
	if (s>=0 && s<p.sorok && o>=0 && o<=p.oszlopok) return 1;
	else return 0;
}

int nyertE(Palya p, unsigned sor, unsigned oszlop)
{
	int irany[4][2]={{0,1},{1,1},{1,0},{1,-1}};
	int s, o;
	char aktualis=p.tartalom[sor][oszlop];
	int i;
	for (i=0; i<4; i++)
	{
		s=sor;
		o=oszlop;
		unsigned mennyi=0;
		while (helyesAzIndex(s, o, p) && p.tartalom[s][o]==aktualis)
		{
			s+=irany[i][0];
			o+=irany[i][1];
			mennyi++;
		}
		s=sor;
		o=oszlop;
		s-=irany[i][0];
		o-=irany[i][1];
		while (helyesAzIndex(s, o, p) && p.tartalom[s][o]==aktualis)
		{
			s-=irany[i][0];
			o-=irany[i][1];
			mennyi++;
		}
		if (mennyi>=5) return 1;
	}
	return 0;
}

int main()
{
	// BEKERES
	Palya jatekter;
	printf("Kerem a palya szelesseget: ");
	scanf("%u", &jatekter.oszlopok);
	printf("Kerem a palya magassagat: ");
	scanf("%u", &jatekter.sorok);
	unsigned int o, s;
	jatekter.tartalom=(char**)malloc(sizeof(char*)*jatekter.sorok);
	for (s=0; s<jatekter.sorok; s++)
	{
		jatekter.tartalom[s]=(char*)malloc(sizeof(char)*jatekter.oszlopok);
		for (o=0; o<jatekter.oszlopok; o++)
			jatekter.tartalom[s][o]=URES;
	}

	// teszt
//	jatekter.tartalom[1][3]='X';
//	jatekter.tartalom[1][5]='X';
//	jatekter.tartalom[2][3]='X';
//	jatekter.tartalom[1][2]='O';
//	jatekter.tartalom[4][2]='O';
//	jatekter.tartalom[4][4]='O';
//	palyaKirajzol(jatekter);

	// Játék menete:
	// Felváltva raknak
	//   Megadja a koordinátát (pl. B7)
	//   Csak üres mezõre rakhat
	//   Nem rakhat ki a pályáról
	//   Nyert-e

	// MEGJELENITES
	palyaKirajzol(jatekter);

	// JATEK
	char aktualis='O';
	int vege=0;
	while (vege==0)
	{
		// POZICIO BEKERES
		char pozicio[4];
		int megfelelo=1;
		unsigned sor;
		unsigned oszlop;
		do
		{
			printf("%c jatekos - Kerem a koordinatat (pl. B7 vagy F15): ", aktualis);
			scanf("%s", pozicio);
			oszlop=pozicio[0]-'A';
			if (pozicio[2]=='\0')
			{
				sor = pozicio[1]-'1';
			}
			else
			{
				sor = (pozicio[1]-'0')*10 + pozicio[2]-'0' - 1;
			}
			megfelelo=1;
			if (!(sor<jatekter.sorok && oszlop<jatekter.oszlopok))
			{
				printf("A pozicio nincs a palyan belul!\n");
				megfelelo=0;
			}
			else if (jatekter.tartalom[sor][oszlop]!=URES)
			{
				printf("Itt mar van valami!\n");
				megfelelo=0;
			}
		} while (megfelelo==0);

		// KITOLTES
		jatekter.tartalom[sor][oszlop]=aktualis;

		// MEGJELENITES
		palyaKirajzol(jatekter);

		// NYERT-E A JATEKOS EZZEL A LEPESSEL?
		if (nyertE(jatekter, sor, oszlop)==1)
		{
			vege=1;
			printf("A \'%c\' jatekos nyert!\n", aktualis);
		}

		// JATEKOSVALTAS
		if (aktualis=='O') aktualis='X';
		else aktualis='O';
	}


	// FELSZABADITAS
	for (s=0; s<jatekter.sorok; s++)
		free(jatekter.tartalom[s]);
	free(jatekter.tartalom);

	return 0;
}
