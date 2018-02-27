// Adem TURKOGLU
// 1306150102
// Date 16.12.2016
// Development Environment : Visual Studio2015

#include<stdio.h>
#include<string.h>

int main()
{
	int encokadet = 0;
	int asc[127] = { 0 };
	int bosluklar[200] = { 0 };
	char dizi[200];
	int i,bsluk,noktalama,chsayi;
	bsluk = 0;
	noktalama = 0;
    int kyt=0;
	int gecici = 0;
	printf("Cumlenizi giriniz.\n");
	gets(dizi);
	for (i = strlen(dizi) - 1;i >= 0;i--){printf("%c", dizi[i]);}  /*Tersini yaz�yor.*/
	printf("\n");
	for (int x = 0;x <= strlen(dizi);x++)   //Kelimelerin ayr� ayr� tersini al�yor.
	{ 
		if (dizi[x] == ' '|| dizi[x] == '\0')
		{
              for (int y = x-1;y >= kyt;y--)
				  printf("%c", dizi[y]);
			kyt = x;
			printf(" ");
		}
	}
	for(i=0;i<200;i++) {   /*Kelime say�s� ve noktalama i�areti sayisi*/
		if (dizi[i] == ' ') bsluk++;
		switch (dizi[i])
		{
		case '.': noktalama++; break;
		case ':': noktalama++; break;
		case ',': noktalama++; break;
		case ';':noktalama++; break;
		case '?': noktalama++; break;
		case '!': noktalama++; break;
		case '`':noktalama++; break;
		}
	 }
	chsayi = strlen(dizi); /*kakrakter say�s�.*/
	printf("\nCharacter:%d\tWords:%d\tSpecialchars:%d\n", chsayi, bsluk+1, noktalama);// 
	for (i = 0;i < strlen(dizi); i++)  //hangi karakterden ka� tane oldu�unu g�steren k�s�m
		asc[dizi[i]]++;
	for (char x = 0; x < 127; x++)      //karakterlerin ascii tablosundaki kar��l�klar�n� kullanarak ka� tane kullan�ld�klar�n� asc dizisine att�m
	{                                       //sadece ingilizce karakterler
		if (asc[x] != 0 && x != ' ')
		{
			printf("%c:", x);    
			printf("%d  ", asc[x]);
		}
		if (asc[x] > encokadet) encokadet = asc[x]; //en �ok kullan�lan karakterin say�s�n� tutuyorum
	}
	printf("\n");
	 while (encokadet > 0) //en �ok adetten ba�layarak o adetteki karakterleri yazd�r�yorum.
	 {
		for (char j = 0; j < 127; j++)
		{
			if (encokadet == asc[j])
			{
				printf("%c", j);  
				gecici = 1;
			}
		}
			if (gecici == 1)
			{
				printf(" ");
				gecici = 0;
			}
		encokadet--;   //burda eksilterek en �ok adetin bir k�����n� kotrol ediyorum.
	} 
	 printf("\n");
  bsluk = 1;
	 for (i = 0;i <= strlen( dizi );i++)// c�mledeki kelimeleri karakter say�s�na g�re s�ralay�p bas�yor.
	 {
		 if (dizi[i] == ' ')
		 {
			 bosluklar[bsluk] = i;
			 ++bsluk;
		 }
		 if (i == strlen(dizi))
			 bosluklar[bsluk] = i + 1;
	 }
	 for (i = strlen(dizi);i >=0;i--)
	 {
		 for (int j = 0;j <= bsluk+1;++j)
		 {
			 if ((bosluklar[j + 1] - 1) - (bosluklar[j]+1) == i)
			 {
				 for (int c = bosluklar[j];c < bosluklar[j+ 1];c++)
					 printf("%c", dizi[c]);
				 printf(" ");
			 }
		 }
	 }
getchar();

return 0;

}
