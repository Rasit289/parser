#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Raþit Karabýyýk
//02200201078
//2.sýnýf örgün öðretim

bool karakter(char kar)
{
	if (kar == ' ' || kar == '+' || kar == '-' || kar == '*' ||
		kar == '/' || kar == ';' || kar == '>' || kar == ';' ||	//karakter ve operatör alýmý
		kar == '<' || kar == '=' || kar == '(' || kar == ')' ||
		kar == '[' || kar == ']' || kar == '{' || kar == '}' ||
		kar == '#' || kar == ',' || kar == '%' || kar == '.')
		return (true);
	return (false);
}

bool harf(char kar)
{
	if (kar == 'a' || kar == 'b' || kar == 'c' || kar == 'd' ||
		kar == 'e' || kar == 'f'
)
		return (true);
	return (false);
}

bool rakamlar(char rakam)
{
	if (rakam == '0' || rakam == '1' || rakam == '2' ||
		rakam == '3' || rakam == '4' || rakam == '5' ||	//rakam ve sayý operatör alýmý
		rakam == '6' || rakam == '7' || rakam == '8' ||
		rakam == '9')
		return (true);
	return (false);
}

int id(int ilk, int son, char *dizi)
{
	int k = 0;
	int sayac3 = 0;
	int sayac4 = 0;
	int m = 0;
	int gecici = 0;

	for(k=ilk;k<son;k++)
	{
		if(harf(dizi[k])==true)
		{
			if(dizi[k+1] == '<'|| dizi[k + 1] =='>'|| dizi[k+1] == '='|| dizi[k + 1] == '*'|| dizi[k + 1] == '+'|| dizi[k + 1] == '-'|| dizi[k + 1] == '/' || dizi[k + 1] == '}' || dizi[k + 1] == ')') {}
			else
			{
				return 1;
			}

			if (rakamlar(dizi[k+1]) == true)						//bu kýsýmda gramerimizin <id> kýsmýný kontrol ediyoruz
			{
				return 1;
			}
		}
		else if (rakamlar(dizi[k]) == true)
		{
			if (harf(dizi[k+1]) == true)
			{
				return 1;
			}
		}
		else
		{
			m = 1;
		}
	}

	return m;

}

int main()
{
	char metin[10000];
	char dizi[10000];
	int a;
	int i = 0;
	int j = 0;
	FILE * fp;

	printf(" Lutfen dosya yolu giriniz  ");
	scanf("%s", &metin);	//dosya yolu alýnýyor.

	if ((fp = fopen(metin, "r")) == NULL)
	{
		printf("Dosya acma hatasi!");	//dosya yolu okunuyor.

		exit(1);

	}

	do {
		a = fgetc(fp);
		if ((int) a !=10 && (int) a!= 32 && (int) a!= 9)
		{
			dizi[i] = a;	//metinden veri alýnýyor eðerki boþluk yoksa diziye atýlýyor.
			i++;

		}

		printf("%c", a);	//metin dosyasý yazdýrýlýyor

	}

	while (a != EOF);
	{
		if ((int) a !=10 &&(int) a!= 32&&(int) a!= 9)
		{
			dizi[i]= a;
			i++;
			//döngü ile metinden tekrar veri alýnýyor eðerki boþluk yoksa diziye atýlýyor.
		}
	}

	for (i=0; i<100;i++)
	{
		printf("%c", dizi[i]);
	}
	//if(a<b)
	i = 0;
	j = 0;
	int ara_op = 0;
	int sayac1 = 0;
	a = 0;
	int sayac2 = 0;
	int sayac3 = 0;
	int sayac4 = 0;
	int sayac5 = 0;
	int sayac6 = 0;
	int k = 0;
	int m = 0;// hata degiskeni
	int s = 0;
	int esit2 = 0;
	int esitmi = 0;
	int ikiop = 0;
	int kontrol = 0;
	
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("   ************************     \n");
	printf("  TOKENIZER ISLEMI    \n");
	printf(" \n");
	printf(" \n");

	while (dizi[i] != EOF)
	{
		//dizi içindeki text dosyasýnýn karakterlerini konrtol eder. 			              
		//Eðerki rakamsa,operatör yada karakterse fonksiyona gönderip hangisi olduðunu bulmaya çalýþýr.
		//Deðilse harfleri kontrol ederek tek tek yan yana yazdýrýr.
		//yazdýrýken, kullanarak tokenizer iþemini uygular.

		if (dizi[i] == '&' && dizi[i + 1] == '&' || dizi[i] == '|' && dizi[i + 1] == '|' || dizi[i] == '<' && dizi[i + 1] == '=' || dizi[i] == '>' && dizi[i + 1] == '=' ||
			dizi[i] == '+' && dizi[i + 1] == '=' || dizi[i] == '!' && dizi[i + 1] == '=' || dizi[i] == '-' && dizi[i + 1] == '=' || dizi[i] == '=' && dizi[i + 1] == '=' ||
			dizi[i] == '*' && dizi[i + 1] == '=' || dizi[i] == '/' && dizi[i + 1] == '=')
		{
			//==,&& gibi iki operatör yana yana olduðu durumlarýn bir kýsmýný  kontrol ediyor
			printf(",%c", dizi[i]);
			printf("%c,", dizi[i + 1]);
			i++;
		}
		else if (karakter(dizi[i]) == true)
		{
			//dizinin[i] ninci elemanýný kontrol ediyor eðerki karakter yada operator ise döngüye giriyor

			if (karakter(dizi[i + 1]) == true)
			{
				//++,-- gibi iki operatör yana yana olduðu durumlarýn diðer kýsmýný kontrol ediyor kontrol ediyor
				if (dizi[i] == '+' && dizi[i + 1] == '+' || dizi[i] == '-' && dizi[i + 1] == '-' || dizi[i] == '=' && dizi[i + 1] == '=' ||
					dizi[i] == '+' && dizi[i + 1] == '=' || dizi[i] == '!' && dizi[i + 1] == '=' || dizi[i] == '-' && dizi[i + 1] == '=' ||
					dizi[i] == '&' && dizi[i + 1] == '&' || dizi[i] == '|' && dizi[i + 1] == '|' || dizi[i] == '<' && dizi[i + 1] == '=' ||
					dizi[i] == '>' && dizi[i + 1] == '=' || dizi[i] == '*' && dizi[i + 1] == '=' || dizi[i] == '/' && dizi[i + 1] == '=')
				//++,-- gibi iki operatör yana yana olduðu durumlarýn diðer kýsmýný kontrol ediyor kontrol ediyor
				{
					printf(",%c", dizi[i]);
					printf("%c", dizi[i + 1]);
					i++;
				}
				else if (dizi[i] == '}')
				{
					printf("%c", dizi[i]);
					i++;
				}
				else
				{
					// eðerki iki karakter yan yana deðilse o karakteri  yazýyor.
					//iki karakter yan yana gediðinde hata verebiliyor o yüzden- 
					// 120 ve 148. satýrlar arasýnda opratör ve karakter arasýndaki virgül atamalarýný kontrol ediyor   
					if (i == 0)
					{
						printf("%c", dizi[i]);
					}
					else if (dizi[i] == '(' && dizi[i+1] == ')')
					{
						printf(",%c", dizi[i]);
					}
					else if (dizi[i] == '/' && dizi[i+1] == '/')
					{
						printf(",%c", dizi[i]);
					}
					else if (dizi[i] == ')')
					{
						printf(",%c", dizi[i]);

					}
					else if (dizi[i] == ';' && dizi[i+1] == '}')
					{
						printf("%c", dizi[i]);

					}
					else if (dizi[i] == ';' && dizi[i+1] == '/')
					{
						printf("%c", dizi[i]);

					}
					else
					{
						printf(",%c,", dizi[i]);
					}
				}
			}
			else
			{
				if (dizi[i + 1] == ',')
				{
					printf("%c,", dizi[i]);
				}	//tek opratörü yazdýrýr ve 
				//fazladan virgül varsa onlarý diziden atar.
				else
				{
					printf(",%c,", dizi[i]);
				}
			}
		}
		else if (rakamlar(dizi[j]) == true)
		{
			//dizi[i] ninci elemaný rakam mý diye kontrol ediyor

			do {
				printf(",%c", dizi[j]);	// eðerki rakamsa sadece buraya giriyor
			}

			while (rakamlar(dizi[j] + 1) == true);
			{
				// eðer sayýysa tek tek rakamlarý burada kontrol ediyor

				printf("%c,", dizi[j+1]);
				j++;
			}
		}
		else
		{
			//deðiþkenleri yada for while  gibi komutlarý  yazdýrýyor

			printf("%c", dizi[i]);

		}

		i++;
	}
	
	//if(a<b){a=a+b} seklindeki bir ifadede < operatoru SAYAC1 , ) operatoru SAYAC2 , }operatoru SAYAC3 
	// = operatoru SAYAC4 , +operatoru SAYAC5 i gosterir
	//diziden alýnan text in uc sýnýrlarý belirlenip uc sýnýrlar arasýnda grammer hatasý var mý diye kontrol edilir.
	//dosya hatalarý analiz ettikten sonra dosya doðruysa dosya doðrudur deðilsedosya hatalýdýr der  hatalý kýsmýn aralýðýný belirtrtir.
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("   ************************     \n");
	printf("  PARSER ISLEMI    \n");
	printf(" \n");
	printf(" \n");
	i=0;

	if (dizi[i] == 'i' && dizi[i+1] == 'f')  
	{
		if (dizi[i+2] == '(')
		{
			a = dizi[i];

			while (dizi[i] != ')' || sayac2 == 18)
			{
				sayac2++;
				i++;

				if (sayac2 == 17)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");										
					printf(" \n");
					printf("   ************************     \n");
					printf("if kismindaki) kapali parantez yok yok");
					return (0);
				}
			}

			for (j=3; j <sayac2;j++)
			{
				if (dizi[j]== '=')
				{
					esitmi = esitmi + 1;
				}

				if (dizi[j] == '<')					// if kisminin sart kismindaki operarorun esittir olup olmadýðý kontrol edilir
													//esittir ise hata verir.
				{
					esitmi--;

				}

				if (dizi[j] == '>')
				{
					esitmi--;
				}
			}

			if (esitmi == 1)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if icinde esittir olmaz");
				return (0);
			}
			
			for (j = 3; j < sayac2; j++)
			{
				if (dizi[j] == '<' || dizi[j] == '=' || dizi[j] == '>' || dizi[j] == '=' && dizi[j + 1] == '=' || dizi[j] == '<' || dizi[j + 1] == '=' || dizi[j] == '>' && dizi[j + 1] == '=')
				{
					sayac1 = j;				
					m = 1;					//bu kisimda if kisminin sart kismindaki operator bulunur.
					esit2 = 0;

				}
			}

			for (j = 3; j < sayac2; j++)
			{
				if (dizi[j] == '=' && dizi[j + 1] == '=')
				{
					printf(" \n");
					ikiop = 1;
				}												//<= ,== >= operatorlerinin gelmesi durumunda uc sinirlar guncellenir

				if (dizi[j] == '<' && dizi[j + 1] == '=')
				{
					ikiop = 1;
				}

				if (dizi[j] == '>' && dizi[j + 1] == '=')
				{
					ikiop = 1;
				}
			}

			if (m == 0)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if icindeki operator yok");
				return (0);

			}

			m = 0;
			if (sayac1 - 2 == 1)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if icindeki operatorun onu bos");
				return (0);
			}
			else
			{
				m = id(3, sayac1 - ikiop, dizi); // if kisminin sart kismindaki operatorun onunu kontrol ediyor

				if (m == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("if kisminin sart kismindaki operatorun onu hatali");
					return (0);

				}
			}

			if (sayac2 - sayac1 == 1)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if icindeki sartli ifadedeki operatorun  arkasi bos");
				return (0);
			}
			else
			{
				m = 0;
				m = id(sayac1 + 1 + s, sayac2, dizi); //if kismindaki sartli ifadedeki operatorun arkasýný kontrol ediyor

				if (m == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("if kismindaki sartli ifadedeki operatorun arkasi hatali");
					return (0);

				}
			}
		}
		else
		{
			printf(" \n");
			printf("DOSYA HATALIDIR");
			printf(" \n");
			printf("   ************************     \n");
			printf(" if kismindaki (acik parantez konulmamis");
			return (0);

		}

		if (dizi[sayac2 + 1] == '{')
		{
			m = 0;
			for (k = sayac2+4; k<20;k++)			//süslü parantez bulunuyor
			{
				if (dizi[k] != '}') {}
				else
				{
					sayac3 = k;
					m = 1;
				}
			}

			if (m == 0)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if kisminin cumle kisminda } konulmamis");
				return (0);
			}

			m = 0;
			for (j = sayac2+2; j <sayac3; j++)
			{
				if (dizi[j] == '=')
				{								//<id> = <id>+<id> kismindaki = operatorunu konrol eder
					sayac4 =j;
					m =1;

				}
			}

			if (m == 0)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("suslu parantez icindeki esittir yok");
				return (0);
			}

			if (sayac4 - sayac2 + 2 == 1)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("esittirin onu bos");
			}

			int hata = 1;;

			//	//<id> = <id>+<id> kismindaki = onundeki id i kontol eder
			for (k = sayac2 +2; k <sayac4;k++)
			{
			

				if (harf(dizi[k]) == true)
				{
					hata = -5;
					if (harf(dizi[k + 1]) == true)
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf(" if kisminin cumle kismindaki esittirin  onundeki id hatali");	
						return (0);
						printf("DOSYA HATALIDIR");
						hata = 1;
					}
				}
				else if (rakamlar(dizi[k]) == true)
				{
					if (harf(dizi[k + 1]) == true)
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf(" if kisminin cumle kismindaki esittirin  onundeki id hatali");
						return (0);
						hata = 1;
					}

					hata = -5;

				}
				else
				{
				
				}
			}

			if (hata == 1)
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf(" if kisminin cumle kismindaki esittirin  onu hatali");
				return (0);

			}

			m = 0;
				//	//<id> = <id>+<id> kismindaki + operatoru kontol eder
			for (j = sayac4; j < sayac3; j++)
			{
				if (dizi[j] =='+'|| dizi[j] =='-'|| dizi[j] =='*'|| dizi[j] =='/')
				{
					sayac5 = j;
					m = 1;

				}
			}
		
			if (m == 0)
			{
				if (sayac1 - 2 == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("operanýn onu bos");
				}
				else
				{
					//cumle kisminda <id>=<id> kismini kontol eder
					m = 0;
				
					for (k = sayac4+1; k <sayac3; k++)
					{
						if (harf(dizi[k]) == true) {
							if (harf(dizi[k+1]) == true) {
									printf(" \n");
									printf("DOSYA HATALIDIR");
									printf(" \n");
									printf("   ************************     \n");
									printf("if kisminin cumle kismindaki esittirin arkasindaki id hatali");
									return(0);
							}
						}
						else if (rakamlar(dizi[k]) == true) {
							if (harf(dizi[k+1]) == true) {
									printf(" \n");
									printf("DOSYA HATALIDIR");
									printf(" \n");
									printf("   ************************     \n");
									printf("if kisminin cumle kismindaki esittirin arkasindaki id hatali");
									return(0);
							}
						}
						else
						{
							m = 1;
						}
					}
				}

				if (m == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("if kisminin cumle kismindaki esittirin arkasindaki id hatali");
					return(0);
				}
			}

			if (m == 1)
			{
				if (sayac1 - 2 == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("operanýn onu bos");
				}
				else
				{
					m = 0;
					//cumle kisminda <id>=<id>+<id> kisminda + nin onundeki id i kontrol eder
					m = id(sayac4+1, sayac5,dizi);

				}

				if (m == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("if kisminin cumle kismindaki = ile + arasi hatali");
					return (0);
				}
				else
				{
					m = 0;
					//cumle kisminda <id>=<id>+<id> kisminda + nin arkasindaki id i kontrol eder
					m = id(sayac5+1, sayac3, dizi);

				}

				if (m == 1)
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf("if kisminin cumle kismindaki + ile } arasi hatali");
					return (0);
				}
			}
		}
		else
		{
			printf(" \n");
			printf("DOSYA HATALIDIR");
			printf(" \n");
			printf("   ************************     \n");
			printf("if kisminin cumle kismindaki { 	ac suslu parantez yok");
			return (0);

		}

		int temp = sayac3 + 1;
		//kaldigimi zon kisim yani son } paranetezin yerini temp e atiyoruz

		int a = 0;
		int b = 0;
		int sinir = 0;

		if (dizi[temp] =='e')
		{
			if (dizi[temp]=='e'&& dizi[temp + 1]=='l' && dizi[temp + 2]=='s'&& dizi[temp+3] =='e'&& dizi[temp+ 4] =='i' && dizi[temp+5] == 'f')
			{
				while (dizi[temp]=='e'&& dizi[temp+1]== 'l'&& dizi[temp+ 2] == 's' && dizi[temp+3]== 'e' && dizi[temp+4] == 'i' && dizi[temp+5] == 'f')
				{
					i = temp;
					kontrol++;

					if (dizi[i + 6] == '(')
					{
						m = 0;
						for (i = temp; i < temp + 16; i++)
						{
							if (dizi[i] == ')')
							{
								sayac2 = i;
								m = 1;

							}
						}

						if (m == 0)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki sart kismindaki) kapali parantez  yok", kontrol);
							return (0);
						}

						m = 0;

						esitmi = 0;
						for (j = temp; j < sayac2; j++)
						{
							if (dizi[j] == '=')
							{
								esitmi = esitmi + 1;
							}

							if (dizi[j] == '<')
							{
								esitmi--;

							}

							if (dizi[j] == '>')			//else if kisminin sart kismindaki operator esittirmi diye kontorl ediyor
							{
								esitmi--;
							}
						}

						if (esitmi == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki sart kisminda icinde esittir olamaz", kontrol);
							return (0);
						}
						
						//else if kisminin sart kismindaki operatorý kontorl ediyor
						for (j = temp; j < sayac2; j++)
						{
							if (dizi[j] == '<' || dizi[j] == '=' || dizi[j] == '>' || dizi[j] == '=' && dizi[j + 1] == '=' || dizi[j] == '<' || dizi[j + 1] == '=' || dizi[j] == '>' && dizi[j + 1] == '=')
							{
								sayac1 = j + 1;
								m = 1;
								esit2 = 0;

							}
						}

						ikiop = 0;
						for (j = temp; j < sayac2; j++)
						{
							if (dizi[j] == '=' && dizi[j + 1] == '=')
							{
								ikiop = 1;
							}

							if (dizi[j] == '<' && dizi[j + 1] == '=')
							{
								ikiop = 1;
							}

							if (dizi[j] == '>' && dizi[j + 1] == '=')
							{
								ikiop = 1;
							}
						}

						if (m == 0)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki sart kisminda operator yok", kontrol);
							return (0);
						}

						m = 0;

						if (sayac1 - temp == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki sart kisminda operatorun onu bos", kontrol);
							return (0);
						}

						
						else
						{
							//else if kisminin sart kismindaki operatorun onundeki id i kontrol ediyor ediyor
							m = id(temp + 7, sayac1 - ikiop, dizi);

							if (m == 1) {}
						}

						

						if (sayac2 - sayac1 + 1 == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki sart kisminda operatorun arkasi bos", kontrol);
							return (0);
						}
						else
						{
							int hata = 1;

							m = 0;
							for (k = sayac1; k < sayac2; k++)
							{
					

								if (harf(dizi[k]) == true)
								{
									hata = -5;
									if (harf(dizi[k + 1]) == true)
									{
										printf(" \n");
										printf("DOSYA HATALIDIR");
										printf(" \n");
										printf("   ************************     \n");
										printf(" %d .else if kisminin cumle kismindaki esittirin  onu hatali", kontrol);
										return (0);
										printf("DOSYA HATALIDIR");
										hata = 1;
									}
								}
								else if (rakamlar(dizi[k]) == true)
								{
									if (harf(dizi[k + 1]) == true)
									{
										printf(" \n");
										printf("DOSYA HATALIDIR");
										printf(" \n");
										printf("   ************************     \n");
										printf(" %d .else if kisminin cumle kismindaki esittirin  onu hatali", kontrol);

										return (0);
										hata = 1;
									}

									hata = -5;

								}
								else {}
							}
						}
					}
					else
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");

						printf(" %d .else if teki sart kismindaki (ac parantez  yok", kontrol);
						return (0);
					}

					if (dizi[sayac2 + 1] == '{')
					{
						m = 0;
						for (k = sayac2 + 4; k < temp + 24; k++)
						{
							if (dizi[k] != '}') {}
							else
							{
								sayac3 = k;
								m = 1;
							}
						}

						if (m == 0)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki cumle kismindaki } konulmamis", kontrol);

							return (0);
						}

						m = 0;

						for (j = sayac2 + 2; j < sayac3; j++)
						{
							if (dizi[j] == '=')
							{
								sayac4 = j;
								m = 1;

							}
						}

						if (m == 0)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf(" %d .else if teki cumle kismindaki esittir yazilmamis", kontrol);
							return (0);
						}
						
							if(dizi[sayac2+2]=='='){
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf("else if kisminin cumle kismindaki esittirin onu bos olamaz");
						return (0);
					}


						m = id(sayac2 + 2 + s, sayac4, dizi);

						if (m == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("  %d .else if teki cumle kismindaki operatorun onu hatali", kontrol);
							return (0);

						}

						m = 0;
						for (j = sayac4; j < sayac3; j++)
						{
							if (dizi[j] == '+' || dizi[j] == '-' || dizi[j] == '*' || dizi[j] == '/')
							{
								sayac5 = j;
								m = 1;

							}
						}

						if (m == 0)
						{
							if (sayac1 - temp == 1)
							{
								printf(" \n");
								printf("DOSYA HATALIDIR");
								printf(" \n");
								printf("   ************************     \n");
								printf("operanýn onu bos");
							}
							else
							{
								m = 0;

								for (k = sayac4 + 1; k < sayac3; k++)
								{
									if (harf(dizi[k]) == true) {
											if (harf(dizi[k+1]) == true) {
											printf(" \n");
											printf("DOSYA HATALIDIR");
											printf(" \n");
											printf("   ************************     \n");
											printf("  %d .else if teki cumle kismindaki esittirin arkasindaki id hatali", kontrol);
											
											return(0);
											}
									}
									else if (rakamlar(dizi[k]) == true) {
										
											if (harf(dizi[k+1]) == true) {
											printf(" \n");
											printf("DOSYA HATALIDIR");
											printf(" \n");
											printf("   ************************     \n");
											printf("  %d .else if teki cumle kismindaki esittirin arkasindaki id hatali", kontrol);
											return(0);
											}
										
									}
									else
									{
										m = 1;
									}
								}
							}

							if (m == 1)
							{
								printf(" \n");
								printf("DOSYA HATALIDIR");
								printf(" \n");
								printf("   ************************     \n");
								printf("esittirin arkasi hatali");
								return (0);
							}
						}

						if (m == 1)
						{
							if (sayac5 - sayac4 == 1)
							{
								printf(" \n");
								printf("DOSYA HATALIDIR");
								printf(" \n");
								printf("   ************************     \n");
								printf(" %d .esittirin arkasi bos", kontrol);
								return (0);
								

							}

							else
							{
								m = 0;
								m = id(sayac4 + 1, sayac5, dizi);

							}

							if (m == 1)
							{
								printf(" \n");
								printf("DOSYA HATALIDIR");
								printf(" \n");
								printf("   ************************     \n");
								printf(" %d .else if teki cumle  kismindaki = ile + arasi hatali", kontrol);
								return (0);
							}
							else
							{
								m = 0;
								// cumle kismindaki id nin esittir ile opetator arasýný kontrol eder
								m = id(sayac5 + 1, sayac3, dizi);

							}

							if (m == 1)
							{
								printf(" \n");
								printf("DOSYA HATALIDIR");
								printf(" \n");
								printf("   ************************     \n");
								printf(" %d .else if teki cumle  kismindaki + ile } arasi hatali", kontrol);
								return (0);

							}
						}
					}
					else
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf(" %d .else if teki cumle  ac { 	konulmamis", kontrol);
						return (0);

					}

					//temp her seferinde else if in bir sonraki baslayacaðý yeri gosterir
					temp = sayac3 + 1;

				}
			}
			else
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("if' ten sonra else if yada else gelmeli yada hicbirsey gelmemeli");
				return (0);
			}
		}
		else
		{
			printf(" \n");
			printf("   ************************     \n");
			printf("DOSYA DOGRUDUR");
			printf(" \n");
			printf(" \n");
			return (0);
		}

		if (dizi[temp] == 'e' && dizi[temp + 1] == 'l' && dizi[temp + 2] == 's' && dizi[temp + 3] == 'e')
		{
			if (dizi[temp + 4] == '(')
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");

				printf("else de (olmaz");
				return (0);

			}
			else
			{
				if (dizi[temp + 4] == '{')
				{
					sayac2 = temp + 4;

					m = 0;
					for (k = sayac2 + 4; k < temp + 20; k++)
					{
						if (dizi[k] != '}') {}
						else
						{
							sayac3 = k;
							m = 1;
						}
					}

					if (m == 0)
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf("else kismindaki cumle kisminda kapa } konulmamis");
						return (0);
					}

					m = 0;

					for (j = sayac2 + 1; j < sayac3; j++)
					{
						if (dizi[j] == '=')
						{
							sayac4 = j;
							m = 1;

						}
					}

					if (m == 0)
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf("else kisminin cumle kismindaki suslu parantez icindeki esittir yok");
						return (0);
					}
					
					
					
					if(dizi[sayac2+1]=='='){
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf("else kisminin cumle kismindaki esittirin onu bos olamaz");
						return (0);
					}
					


					m = id(sayac2 + 1, sayac4, dizi);

					if (m == 1)
					{
						printf(" \n");
						printf("DOSYA HATALIDIR");
						printf(" \n");
						printf("   ************************     \n");
						printf(" else kisminin cumle kismindaki   operatorun onu hatali");
						return (0);
					}

					m = 0;
					for (j = sayac4; j < sayac3; j++)
					{
						if (dizi[j] == '+' || dizi[j] == '-' || dizi[j] == '*' || dizi[j] == '/')
						{
							sayac5 = j;
							m = 1;

						}
					}

					if (m == 0)
					{
						if (sayac1 - 2 == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("operanýn onu bos");
						}
						else
						{
							m = 0;

							for (k = sayac4 + 1; k < sayac3; k++)
							{
								if (harf(dizi[k]) == true) {
									
										if (harf(dizi[k+1]) == true) {
												printf(" \n");
												printf("DOSYA HATALIDIR");
												printf(" \n");
												printf("   ************************     \n");
												printf("else  kisminin cumle kismindaki esittirin arkasindaki id hatali");
												return(0);
										}
									
									
								
								
								}
								else if (rakamlar(dizi[k]) == true) {
									
										if (harf(dizi[k+1]) == true) {
												printf(" \n");
												printf("DOSYA HATALIDIR");
												printf(" \n");
												printf("   ************************     \n");
												printf("else  kisminin cumle kismindaki esittirin arkasindaki id hatali");
												return(0);
										}
								
								
								}
								else
								{
									m = 1;
								}
							}
						}

						if (m == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("esittirin arkasi hatali");
						}
					}

					if (m == 1)
					{
						if (sayac1 - 2 == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("operanýn onu bos");
						}
						else
						{
							m = 0;
							m = id(sayac4 + 1, sayac5, dizi);

						}

						if (m == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("else kisminin cumle kismindaki = ile + arasi hatali");
							return (0);
						}
						else
						{
							m = 0;
							m = id(sayac5 + 1, sayac3, dizi);

						}

						if (m == 1)
						{
							printf(" \n");
							printf("DOSYA HATALIDIR");
							printf(" \n");
							printf("   ************************     \n");
							printf("else kisminin cumle kismindaki + ile } arasi hatali");
							return (0);

						}
					}
				}
				else
				{
					printf(" \n");
					printf("DOSYA HATALIDIR");
					printf(" \n");
					printf("   ************************     \n");
					printf(" else kisminin cumle kisminda ac { 	konulmamis");
					return (0);

				}
			}

			temp = sayac3 + 1;

			if (dizi[temp] == 'e' && dizi[temp + 1] == 'l' && dizi[temp + 2] == 's' && dizi[temp + 3] == 'e')
			{
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("else den sonra tekrar else yazilamaz");
				return (0);
			}
			else if(dizi[temp] != EOF){
				printf(" \n");
				printf("DOSYA HATALIDIR");
				printf(" \n");
				printf("   ************************     \n");
				printf("else den sonra herhangi birsey yazilamaz");
				return (0);
			}
			
		}
		else
		{
			printf(" \n");
			printf("DOSYA HATALIDIR");
			printf(" \n");
			printf("   ************************     \n");
			printf("else yanlis yazilmis yada yazilmamis");
			return (0);

		}

		printf(" \n");
		printf("   ************************     \n");
		printf(" \n");
		printf("DOSYA DOGRUDUR");
		printf(" \n");
		printf("   ************************     \n");
		printf(" \n");
	}
	else
	{
		printf(" \n");
		printf("DOSYA HATALIDIR");
		printf(" \n");
		printf("   ************************     \n");
		printf("if yanlis yazilmis");
		return (0);
	}

	printf("\n");

	i = 0;
	i++;

	fclose(fp);
	return (0);
}
