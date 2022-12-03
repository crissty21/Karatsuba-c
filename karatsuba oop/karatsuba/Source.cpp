#include <iostream>

using namespace std;

class numar
{
public:
	int cifre[50] = { 0 };//cifrele numarului
	int n; //numarul de cifre
	numar operator+(numar); //adunarea a doua numere
	numar operator-(numar); //scaderea a doua numere
	void egalare(numar&); //determina care dintre doua numere este mai mare, si apeleaza functia adauga zerouri prin functia adaugare_zero
	void citire(); //citirea unui numar
	void afisare(); //afisarea unui numar
	void adaugare_zero(int); //adauga un numar de zero-uri in stanga numarului
	numar portiune(int,int); //returneaza un o portiune dintr-un numar
	void sterge_zero(); //sterge zero-uri din stanga numarului
	void z(int); //adauga zerouri in drepta 
};


numar numar::operator+(numar second)
{
	numar rez;
	int tine_minte = 0;
	egalare(second);
	for (int i = n; i >= 1; i--)
	{
		rez.cifre[i] = cifre[i] + second.cifre[i] + tine_minte;
		if (rez.cifre[i] > 9)
		{
			tine_minte = 1;
			rez.cifre[i] -= 10;
		}
		else tine_minte = 0;
	}
	rez.n = n;
	if (tine_minte > 0)
	{
		rez.adaugare_zero(1);
		rez.cifre[1] = tine_minte;
		//rez.n++;
	}
	return rez;
}

numar numar::operator-(numar second)
{
	numar rez;
	egalare(second);
	int tine_minte = 0;
	for (int i = n; i >= 1; i--)
	{
		rez.cifre[i] = cifre[i] - second.cifre[i] - tine_minte;
		if (rez.cifre[i] < 0)
		{
			tine_minte = 1;
			rez.cifre[i] += 10;
		}
		else tine_minte = 0;
	}
	rez.n = n;
	rez.sterge_zero();
	return rez;
}
void numar::citire()
{
	cout << "numarul de cifre este:  ";
	cin >> n;
	cout << "cifrele sunt:\n";
	for (int i = 1; i <= n; i++)
		cin >> cifre[i];
}

void numar::afisare()
{
	cout << "numarul este: ";
	for (int i = 1; i <= n; i++)
		cout << cifre[i];
}

void numar::adaugare_zero(int x)
{
	int n1 = n + x, i;
	for (i = n1; n > 0; i--)
		cifre[i] = cifre[n--];
	for (; i >= 1; i--)
		cifre[i] = 0;
	n = n1;
}

void numar::egalare(numar& second)
{
	if (n > second.n)
		second.adaugare_zero(n - second.n);
	else if (second.n > n) adaugare_zero(second.n - n);
}

numar numar::portiune(int st, int dr)
{
	numar rezultat;
	rezultat.n = dr - st+1;
	for (int i = 1; i <= rezultat.n; i++)
		rezultat.cifre[i] = cifre[st++];
	return rezultat;
}

void numar::sterge_zero()
{
	int x = 1;
	while (cifre[x] == 0)x++;
	x--;
	for (int i = 1; i <= n; i++)
		cifre[i] = cifre[i + x];
	n -=x;
}

void numar::z(int pow)
{
	n += pow;
}
/// ////

//FUNCTIA PROBLEMEI
numar kata(numar first, numar second)
{
	numar unu, doi, trei;
	numar a, b, c, d;
	numar rez;
	first.egalare(second); //egalam lungimea numerelor, adaugand zero-uri in stanga
	int n = first.n;
	if (n >= 2) //daca avem mai mult de o cifra, continuam
	{
		//impartim numerele in 2 jumatati
		int mij = n / 2;
		a = first.portiune(1, mij);
		b = first.portiune(mij + 1, first.n);
		a.egalare(b);
		c = second.portiune(1, mij);
		d = second.portiune(mij + 1, second.n);
		c.egalare(d);

		unu = kata(a,c);
		doi = kata(b,d);
		trei = kata((a + b), (c + d));
		trei = (trei - doi) - unu;
		unu.z(a.n * 2);
		trei.z(b.n);
		rez = (unu + doi) + trei;
	}
	else
	{
		//daca numerele noastre au o singura cifra, facem inmultirea clasica
		rez.cifre[1] = (first.cifre[1] * second.cifre[1]) / 10;
		rez.cifre[2] = (first.cifre[1] * second.cifre[1]) % 10;
		rez.n = 2;
		rez.sterge_zero();
	}
	return rez;
}


int main()
{
	numar first, second, third, rez;
	first.citire();
	second.citire();
	rez = kata(first, second);
	rez.afisare();
}