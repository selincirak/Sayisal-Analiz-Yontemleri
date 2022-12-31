#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


double poly(int a[20], double x, int n);
double turev(int a[100], double x, int n);
int fac(int n);

int main()
{
  int a[20], b[100], i, r, p, f, n, it, s, secim, secim2, row = 0, col = 0, j, k, N, secim3, nn, secim5, parca, bitis = 1, degersayi, derece = 0;
  double x, eps, maxIt, start, end, mid, c, d, e, x0, x1, xn, turevN, hturev, hvalue, z, h, h1, value, yeni, eski, x3, x4, sonuc2, deger3, deger4, deger1, sum3, M[50][50], C[25][25], sonuc3, h2, sonuc4;
  double fark, y, v, xx = 1, deger, ilk = 0, aranandeger, degerler[20][21], sabit, sonuc5, ara, sonuc6, S[20], result;
  while (bitis == 1)
  {

    printf("1. Bisection yontemi\n2. Regula-Falsi yontemi\n3. Newton-Rapshon yontemi\n4. NxN lik bir matrisin tersi\n5. Gauss Eleminasyon\n6. Sayisal Turev \n7. Simpson yontemi\n8. Trapez yontemi\n9. Gregory newton Enterpolasyonu\n seciminiz: ");
    scanf("%d", &secim);
    system("cls");
    switch (secim)
    {
    case 1: // BISECTION
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      printf("%d", a[0]);

      do
      {
        printf("\nstarting point: ");
        scanf("%lf", &start);
        printf("\nending point: ");
        scanf("%lf", &end);
        printf("\nepsilon: ");
        scanf("%lf", &eps);
        printf("\nmax iteration: ");
        scanf("%lf", &maxIt);
        it = 0;
        // printf("%f", (start+end)/pow(2, it));
        if (poly(a, start, n) * poly(a, end, n) > 0)
          printf("baska baslangic degerleri giriniz.");
      } while (poly(a, start, n) * poly(a, end, n) > 0);
      printf("\ndurma kosulu secin, f(x)<=eps (1) veya |start-end|/2^n<eps (2): ");
      scanf("%d", &secim2);
      if (secim2 == 2)
      {
        do
        {

          printf("\nstart: %lf", start);
          printf("\nend: %lf", end);
          mid = (start + end) / 2.0;
          printf("\nmid: %lf", mid);
          c = poly(a, start, n); // c= start�n polinom de�eri
          printf("\nfstart: %lf", c);
          d = poly(a, end, n);
          printf("\nfend: %lf", d); // d= endin polinom de�eri
          e = poly(a, mid, n);
          printf("\nfmid: %lf", e); // e= midin polinom de�eri
          it++;
          printf("\niterasyon: %d", it);
          printf("\nepsilon: %lf", eps);
          printf("\n");
          if (d * e < 0)
          {
            start = mid;
          }
          else
          {
            end = mid;
          }
        } while (fabs(start - end) / pow(2, it) > eps && it < maxIt);
      }
      else if (secim2 == 1)
      {
        do
        {

          printf("\nstart: %lf", start);
          printf("\nend: %lf", end);
          mid = (start + end) / 2.0;
          printf("\nmid: %lf", mid);
          c = poly(a, start, n); // c= start�n polinom de�eri
          printf("\nfstart: %lf", c);
          d = poly(a, end, n);
          printf("\nfend: %lf", d); // d= endin polinom de�eri
          e = poly(a, mid, n);
          printf("\nfmid: %lf", e); // e= midin polinom de�eri
          it++;
          printf("\niterasyon: %d", it);
          printf("\nepsilon: %lf", eps);
          printf("\n");
          if (d * e < 0)
          {
            start = mid;
          }
          else
          {
            end = mid;
          }
        } while (fabs(e) > eps && it < maxIt);
      }
      printf("\nResult: %lf", mid);
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");
      break;
    case 2: // REGULA FALS�
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      printf("%d", a[0]);
      do
      {
        printf("\nstarting point: ");
        scanf("%lf", &start);
        printf("\nending point: ");
        scanf("%lf", &end);
        printf("\nepsilon: ");
        scanf("%lf", &eps);
        printf("\nmax iteration: ");
        scanf("%lf", &maxIt);
        it = 0;
        // printf("%f", (start+end)/pow(2, it));
        if (poly(a, start, n) * poly(a, end, n) > 0)
          printf("baska baslangic degerleri giriniz.");
      } while (poly(a, start, n) * poly(a, end, n) > 0);
      printf("\ndurma kosulu secin, f(x)<=eps (1) veya |start-end|/2^n<eps (2): ");
      scanf("%d", &secim2);
      if (secim2 == 2)
      {

        do
        {
          printf("\nstart: %lf", start);
          printf("\nend: %lf", end);
          c = poly(a, start, n); // c= start�n polinom de�eri
          printf("\nfstart: %lf", c);
          d = poly(a, end, n);
          printf("\nfend: %lf", d); // d= endin polinom de�eri
          x0 = (start * d - end * c) / (d - c);
          printf("\npoint: %lf", x0);
          e = poly(a, x0, n);
          printf("\nfx0: %lf", e); // e= x0�n polinom de�eri
          it++;
          printf("\niterasyon: %d", it);
          printf("\nepsilon: %lf", eps);
          printf("\n");
          if (d * e < 0)
          {
            start = x0;
          }
          else
          {
            end = x0;
          }
        } while (fabs(start - end) / pow(2, it) > eps && it < maxIt);
      }
      else if (secim2 == 1)
      {
        do
        {
          printf("\nstart: %lf", start);
          printf("\nend: %lf", end);
          c = poly(a, start, n); // c= start�n polinom de�eri
          printf("\nfstart: %lf", c);
          d = poly(a, end, n);
          printf("\nfend: %lf", d); // d= endin polinom de�eri
          x0 = (start * d - end * c) / (d - c);
          printf("\npoint: %lf", x0);
          e = poly(a, x0, n);
          printf("\nfx0: %lf", e); // e= x0�n polinom de�eri
          it++;
          printf("\niterasyon: %d", it);
          printf("\nepsilon: %lf", eps);
          printf("\n");
          if (d * e < 0)
          {
            start = x0;
          }
          else
          {
            end = x0;
          }
        } while (fabs(e) > eps && it < maxIt);
      }
      printf("\nResult: %lf", x0);
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");
      break;
    case 3: // NEWTON
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      do
      {
        printf("\nstarting value: ");
        scanf("%lf", &value);
        printf("\nbaslama aralik noktasi: ");
        scanf("%lf", &start);
        printf("\nbitis aralik noktas�: ");
        scanf("%lf", &end);
        printf("\nepsilon: ");
        scanf("%lf", &eps);
        printf("\nmax iteration: ");
        scanf("%lf", &maxIt);
        it = 0;
        if (poly(a, start, n) * poly(a, end, n) > 0)
        {
          printf("baska baslangic degerleri giriniz.");
        }
      } while (poly(a, start, n) * poly(a, end, n) > 0);
      printf("\n");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      printf("%d", a[0]);

      printf("\nstart: %lf\n", start);
      printf("end: %lf\n", end);
      printf("epsilon: %lf\n", eps);
      do
      {
        it++;
        printf("\nxn: %lf\n", value);
        hvalue = poly(a, value, n);
        hturev = turev(a, value, n);
        eski = value; // korumak i�in
        yeni = value - (double)(hvalue / hturev);
        printf("fxn: %lf\n", hvalue);
        printf("f'xn: %lf\n", hturev);
        printf("xyeni: %lf", yeni);
        printf("\niterasyon: %d", it);
        printf("\n");
        value = yeni;

      } while (fabs(yeni - eski) > eps && it < maxIt);

      printf("\nResult: %lf", value);
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");
      break;

    case 4: // MATR�S TERS�

      printf("Lutfen kare matris boyutunu (NxN) Giriniz: ");
      scanf("%d", &N);
      printf("\nSayilari giriniz\n");
      for (i = 0; i < N; i++)
      {
        for (j = 0; j < N; j++)
        {
          printf("%d. Satir, %d. Sutun: ", i, j);
          scanf("%lf", &M[i][j]);
        }
      }
      printf("\n");
      printf("ilk hali:\n");
      for (i = 0; i < N; i++)
      { // ilk matrisi yazd�rma
        for (j = 0; j < N; j++)
        {
          printf("[%lf]", M[i][j]);
        }
        printf("\n");
      }

      for (i = 0; i < N; i++)
      { // birim matris olu�turma
        for (j = 0; j < N; j++)
        {
          if (i == j)
            C[i][j] = 1;
          else
            C[i][j] = 0;
        }
      }

      for (i = 0; i < N; i++)
      {
        ilk = M[i][i];
        for (j = 0; j < N; j++)
        {
          M[i][j] = M[i][j] / ilk; // k��egen terimlerini 1 yapmaya �al���yorum
          C[i][j] = C[i][j] / ilk; // birim matrise ayn�lar�n� yapaca��m
        }
        for (p = 0; p < N; p++)
        { // p de�i�keni sat�r de�erini tutmas� i�in, i�erideki d�ng�de ilk ikinci sat�rdan, onun ilk teriminin ilk sat�rla ��kar�las�yla olu�acak
          if (p != i)
          { // p 1 ile ba�larsa iki ve ��� halledip daha sonradan i artaca�� i�in �ste d�necek ve o s�rada �st ��gen hale gelmi� matrisi birim yapacak. p ile i e�it olursa k��egen de�erleriyle i�lem yapm�� oluruz ama ama� onlar� s�f�r yapmak de�il.
            //**p'yi direkt 1 ile ba�latmay� d���nd�m ilk ba�ta. ama bu sefer 0 de�erine hi� gitmedi�i i�in �st ��gene benzer matris halinde kald�. o y�zden s�f�ra geri d�nd�m.
            sabit = M[p][i]; // ilk matrisi d�ng�de de�i�tirece�im i�in	s�f�r yapmak istedi�im terimleri bir de�ere atamak gerekiyor
            for (r = 0; r < N; r++)
            {                                        // r ise s�tunlar aras� gezecek, s�ra s�ra terimlerle �arp�p ��kartma yapmak gerekiyor
              M[p][r] = M[p][r] - (sabit * M[i][r]); // buras�n� slayttaki y�ntem ile yapt�m, s�ras�yla alttaki sat�rlar�, onun ilk terimi ve en �st sat�r�n �arp�m�n� ��kartarak yani ilk terimleri s�f�rlamak <-- (bu en sol taraf i�in)
              C[p][r] = C[p][r] - (sabit * C[i][r]); // [i] olmas�n�n sebebi i'nin p'nin bulundu�u de�erleri s�f�rlayacak 1 de�erine sahip olmas� yani direkt o sat�rda kalarak s�tunlar� gezebiliyoruz. p olmamal� ��nk� ��kartaca��m�z ve s�f�r yapaca��m�z sat�r de�eri p'de.
            }
          }
        }
      }
      printf("\n");
      printf("son hali:\n");
      for (i = 0; i < N; i++)
      {
        for (j = 0; j < N; j++)
        {
          printf("[%lf]", C[i][j]);
        }
        printf("\n");
      }

      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");

      break;
    case 5: // EL�M�NASYON
      printf("\nbilinmeyen sayisi: ");
      scanf("%d", &N);
      printf("\nmatris sayilarini giriniz\n");
      for (i = 0; i < N; i++)
      {
        for (j = 0; j < N; j++)
        {
          printf("%d. Satir, %d. Sutun: ", i, j);
          scanf("%lf", &M[i][j]);
        }
      }
      printf("\n");
      for (i = 0; i < N; i++)
      {
        for (j = 0; j < N; j++)
        {
          printf("[%lf]", M[i][j]);
        }
        printf("\n");
      }
      printf("\nsonuclari giriniz:\n");
      for (i = 0; i < N; i++)
      {
        printf("\n%d. Satir: ", i);
        scanf("%lf", &C[i][0]);
      }
      for (i = 0; i < N; i++)
      {
        printf("[%lf]", C[i][0]);
        printf("\n");
      }
      for (i = 0; i < N; i++)
      {
        ilk = M[i][i];
        C[i][0] = C[i][0] / ilk; // matrisin tersinden fark� s�tun gezmeye gerek olmamas�

        for (j = 0; j < N; j++)
        {
          M[i][j] = M[i][j] / ilk; // k��egen terimlerini 1 yapmaya �al���yorum
        }
        for (p = 0; p < N; p++)
        { // p de�i�keni sat�r de�erini tutmas� i�in, i�erideki d�ng�de ilk ikinci sat�rdan, onun ilk teriminin ilk sat�rla ��kar�lmas�yla olu�acak
          if (p != i && p > i)
          { // ikinci e�itli�i yazma sebebim, �st ��gen olurken sabit de�i�keninde s�f�rlamak istedi�im de�erlerin hepsinde p, i'den b�y�kt�.

            sabit = M[p][i]; // ilk matrisi d�ng�de de�i�tirece�im i�in	s�f�r yapmak istedi�im terimleri bir de�ere atamak gerekiyor
            for (r = 0; r < N; r++)
            {                                        // r ise s�tunlar aras� gezecek, s�ra s�ra terimlerle �arp�p ��kartma yapmak gerekiyor
              M[p][r] = M[p][r] - (sabit * M[i][r]); // buras�n� slayttaki y�ntem ile yapt�m, s�ras�yla alttaki sat�rlar�, onun ilk terimi ve en �st sat�r�n �arp�m�n� ��kartarak yani sol ba�taki (k��egene kadar olan) terimleri s�f�rlamak
            }
            C[p][0] = C[p][0] - (sabit * C[i][0]); // [i] olmas�n�n sebebi i'nin p'nin bulundu�u de�erleri s�f�rlayacak 1 de�erine sahip olmas� yani direkt o sat�rda kalarak s�tunlar� gezebiliyoruz. p olmamal� ��nk� ��kartaca��m�z ve s�f�r yapaca��m�z sat�r de�eri p'de.
          }
        }
      }
      printf("\n");
      for (i = 0; i < N; i++)
      {
        result = 0;
        for (j = 0; j < i; j++)
        {
          result = result + M[N - i - 1][N - j - 1] * S[j];
        }
        S[i] = C[N - i - 1][0] - result;
      }
      printf("\nust ucgen hali: \n\n");
      for (i = 0; i < N; i++)
      {
        for (j = 0; j < N; j++)
        {
          printf("[%lf]", M[i][j]);
        }
        printf("\n");
      }
      for (i = N - 1; i >= 0; i--)
      {

        printf("\n%d. degisken=[%lf]\n", N - i, S[i]);
      }
      printf("\n");

      printf("\n");

      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      break;
    case 6:
      // SAYISAL TUREV
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      printf("%d", a[0]);

      printf("\ncozum yontemi seciniz: geri fark (1), ileri fark(2), merkezi fark(3)\n ");
      scanf("%d", &secim3);
      printf("x degeri giriniz: ");
      scanf("%lf", &x);
      printf("h degeri giriniz: ");
      scanf("%lf", &h);

      if (secim3 == 1)
      {
        printf("(f(x)-f(x-h))/h\n");
        printf("x: %lf \n", x);
        printf("h: %lf\n", h);
        x3 = poly(a, x, n);
        x4 = poly(a, x - h, n);
        sonuc2 = (x3 - x4) / h;
        printf("sonuc= %lf", sonuc2);
      }
      else if (secim3 == 2)
      {
        printf("(f(x+h)-f(x))/h\n");
        printf("x: %lf \n", x);
        printf("h: %lf\n", h);
        x3 = poly(a, x, n);
        x4 = poly(a, x + h, n);
        sonuc2 = (x4 - x3) / h;
        printf("sonuc= %lf", sonuc2);
      }
      else if (secim3 == 3)
      {
        printf("(f(x+h)-f(x))/h\n");
        printf("x: %lf \n", x);
        printf("h: %lf\n", h);
        x3 = poly(a, x - h, n);
        x4 = poly(a, x + h, n);
        sonuc2 = (x4 - x3) / (2 * h);
        printf("sonuc= %lf", sonuc2);
      }
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");
      break;
    case 7:
      // SIMPSON
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      sonuc3 = 0;
      printf("%d", a[0]);
      printf("\nyontem seciniz: 1/3 (1) veya 3/8 (2) ");
      scanf("%d", &secim5);
      printf("\nstarting point: ");
      scanf("%lf", &start);
      printf("\nending point: ");
      scanf("%lf", &end);
      printf("\nparca sayisi: ");
      scanf("%d", &parca);
      if (secim5 == 1)
      {
        h = (end - start) / parca;
        for (i = 0; i < parca; i++)
        {

          sonuc2 = poly(a, start + (h * i), n);
          sonuc4 = poly(a, start + (h * (i + 1)), n);
          ara = (start + (h * i) + start + (h * (i + 1))) / 2;
          sonuc5 = poly(a, ara, n);
          sonuc3 += h * (sonuc4 + (sonuc5 * 4) + sonuc2) / 6;
        }
      }
      if (secim5 == 2)
      {
        h = (end - start) / parca;
        for (i = 0; i < parca; i++)
        {
          sonuc2 = poly(a, start + (h * i), n);
          sonuc4 = poly(a, start + (h * (i + 1)), n);
          x1 = (start + (h * (i + 1)) - (start + (h * i))) / 3;
          x3 = start + (h * i) + x1;
          x4 = x1 + x3;
          sonuc5 = poly(a, x3, n);
          sonuc6 = poly(a, x4, n);
          sonuc3 += h * (sonuc4 + (3 * sonuc5) + (3 * sonuc6) + sonuc2) / 8;
        }
      }
      printf("sonuc= %lf", sonuc3);
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");
      break;
    case 8:
      // TRAPEZ
      printf("polinomun derecesini giriniz: ");
      scanf("%d", &n);
      for (i = 0; i <= n; i++)
      {
        printf(" x^%d 'in bas katsayisini giriniz ", i);
        scanf("%d", &a[i]);
      }
      system("cls");
      for (i = n; i > 0; i--)
      {
        printf("%dx^%d + ", a[i], i);
      }
      printf("%d", a[0]);

      sonuc3 = 0;
      printf("\nstarting point: ");
      scanf("%lf", &start);
      printf("\nending point: ");
      scanf("%lf", &end);
      printf("\nkac parcaya ayirmak istediginizi yaziniz: ");
      scanf("%d", &parca);

      h = (end - start) / parca;
      for (i = 0; i < parca; i++)
      {

        sonuc4 = poly(a, start + (h * i), n);
        sonuc2 = poly(a, start + (h * (i + 1)), n);
        sonuc3 += h * (sonuc4 + sonuc2) / 2;
      }
      printf("sonuc= %lf", sonuc3);

      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");

      break;
    case 9:
      deger = 0;
      printf("\ngirilecek deger sayisi: ");
      scanf("%d", &degersayi);
      printf("\n degerleri giriniz: \n");
      for (i = 0; i < degersayi; i++)
      {
        printf("x%d= ", i);
        scanf("%lf", &degerler[i][0]);
        printf("y%d= ", i);
        scanf("%lf", &degerler[i][1]);
      }
      for (j = 2; j <= degersayi; j++)
        for (i = 0; i < degersayi - 1; i++)
          degerler[i][j] = degerler[i + 1][j - 1] - degerler[i][j - 1]; // yeni s�tun olu�mas� ve delta de�erlerinin saklanmas�

      printf("goruntusu aranacak deger: ");
      scanf("%lf", &aranandeger);
      h = degerler[1][0] - degerler[0][0];    // h bulunmas� ikinci de�er-ilk de�er
      v = (aranandeger - degerler[0][0]) / h; // x-x0/h k�sm�
      y = degerler[0][1];                     // fo de�eri
      for (i = 1; i < degersayi; i++)
      {
        xx = xx * (v - (i - 1));
        y = y + (degerler[0][i + 1] * xx) / fac(i); // delta de�erleri ile �arp�m� ve fakt�riyele b�l�m�
      }
      printf("\nx=%lf noktasindaki deger %lfdir\n", aranandeger, y);
      printf("\ndevam etmek icin 1'e cikmak icin 0'a basiniz.\n");
      scanf("%d", &bitis);
      system("cls");

      break;
    default:
      printf("1-9 arasi degerler girmelisiniz.\n");
      break;
    }
  }
  return 0;
}
double poly(int a[], double x, int n)
{
  double sum = a[0];
  int i;
  for (i = 1; i <= n; i++)
  {

    sum = sum + a[i] * pow(x, i);
  }

  return sum;
}
double turev(int a[], double x, int n)
{
  double sum2;
  int i;
  int b[100];
  for (i = 0; i <= n; i++)
  {
    b[i] = a[i];
  }
  b[0] = b[1];
  sum2 = b[0];
  for (i = 2; i <= n; i++)
  {
    b[i - 1] = i * b[i];
    sum2 = sum2 + b[i - 1] * pow(x, i - 1);
  }
  return sum2;
}
int fac(int n)
{
  int i, f = 1;
  for (i = 1; i <= n; i++)
    f = f * i;
  return f;
}
