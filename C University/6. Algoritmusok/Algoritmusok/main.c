#include <stdio.h>

#define MAXELLENSEG 10

/*
6
zombi 120 15 4
csontvaz 80 10 2
bandita 160 12 7
sarkany 1200 30 14
vampir 240 17 1
pok 30 5 1

10
zombi 120 15 4
csontvaz 80 10 2
bandita 160 12 7
csontvaz 90 11 3
sarkany 1200 30 14
vampir 240 17 1
bandita 200 13 7
pok 30 5 1
bandita 120 8 7
vampir 290 19 3

*/

typedef struct ellenseg
{
	char tipus[20];
	int elet;
	int sebzes;
	int pancel;
} Ellenseg;

typedef struct ellensegtar
{
	Ellenseg tomb[MAXELLENSEG];
	unsigned darab;
} EllensegTar;

EllensegTar ellensegekBeolvas()
{
	EllensegTar tarolo;
	printf("Mennyi ellenseg van? (0-20) ");
	scanf("%u", &tarolo.darab);
	unsigned i;
	for (i=0; i<tarolo.darab; i++)
	{
		printf("Kerem a(z) %d. ellenseg adatait:\n", i+1);
		printf("  Tipus? ");
		scanf("%s", tarolo.tomb[i].tipus);
		printf("  Elet? ");
		scanf("%d", &tarolo.tomb[i].elet);
		printf("  Sebzes? ");
		scanf("%d", &tarolo.tomb[i].sebzes);
		printf("  Pancel? ");
		scanf("%d", &tarolo.tomb[i].pancel);
	}

	return tarolo;
}

void ellensegekKiir(EllensegTar tarolo)
{


unsigned i=0;
	for (i=0; i<tarolo.darab; i++)
	{
		printf("%d. ellenseg:\n", i+1);
		printf("  Tipus: %s\n", tarolo.tomb[i].tipus);
		printf("  Elet: %d\n", tarolo.tomb[i].elet);
		printf("  Sebzes: %d\n", tarolo.tomb[i].sebzes);
		printf("  Pancel: %d\n", tarolo.tomb[i].pancel);
	}
}

Ellenseg ellensegBeolvas(){

}


// Feladatok (mindegyiknek egy függvény):
//   Mennyi az ellenségek összes élete?
//   Mennyi az adott típusú ellenségek összes élete?
//   Mennyi van egy adott típúsú ellenségbõl?
//   Mennyi olyan van, akinek legfeljebb x élete van?
//   Van-e közte olyan, akinek legalább x a pajzsa?
//   Válogassuk ki az összeset egy adott típusból!

int szovegUgyanaz(char *szoveg1, char *szoveg2)
{
	// v1
//	unsigned i=0;
//	while (szoveg1[i]!='\0' && szoveg2[i]!='\0')
//	{
//		if (szoveg1[i]!=szoveg2[i]) return 0;
//		i++;
//	}
//	if (szoveg1[i]=='\0' && szoveg2[i]=='\0') return 1;
//	else return 0;

	// v2
	unsigned i=0;
	while (szoveg1[i]!='\0' && szoveg1[i]==szoveg2[i]) i++;
	if (szoveg1[i]==szoveg2[i]) return 1;
	else return 0;
}

int main()
{
    int i;
	EllensegTar tarolo;

	printf("\n\nBEKERES\n\n");
	tarolo=ellensegekBeolvas();

	printf("\n\nKIIRAS\n\n");
	ellensegekKiir(tarolo);


    //Összes karakter élete:
	int osszelet;

	for(i=0;i<tarolo.darab;i++)
    {
        osszelet+=tarolo.tomb[i].elet;
    }

    printf("\nOsszelet: %d", osszelet);



    //MEgadott életnél kisebbek:
    int darab, elet;

    printf("\nAdj meg egy kivant eletet:");
    scanf("%d", &elet );

    for(i=0;i<tarolo.darab;i++){
        if(tarolo.tomb[i].elet<elet)
            darab++;
    }

    printf("\n%d darab van ami %d nel kisebb eletu", darab,elet);





	printf("\n\nVEGE\n\n");
	return 0;
}
