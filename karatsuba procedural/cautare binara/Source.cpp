#include <iostream>

using namespace std;

int v1[50], n1, v2[50], n2;

void citire()
{
	cout << "numarul de elemente al primului numar: ";
	cin >> n1;
	cout << "cifrele primului numar:\n";
	for (int i = 1; i <= n1; i++)
	{
		cout << "v1[" << i << "] = ";
		cin >> v1[i];
	}
	cout << "numarul de elemente al al doilea numar: ";
	cin >> n2;
	cout << "cifrele celui de al doilea numar:\n";
	for (int i = 1; i <= n2; i++)
	{
		cout << "v2[" << i << "] = ";
		cin >> v2[i];
	}
}
void egalare()
{
	int i;
	if (n1 < n2)
	{
		for (i = n2; n1 >= 1; i--)
			v1[i] = v1[n1--];
		for (int j = 1; j <= i; j++)
			v1[j] = 0;
		n1 = n2;
	}
	else
	{
		for (i = n1; n2 >= 1; i--)
			v2[i] = v2[n2--];
		for (int j = 1; j <= i; j++)
			v2[j] = 0;
		n2 = n1;
	}
	
}
void afisare()
{
	cout << "primul numar este\n";
	for (int i = 1; i <= n1; i++)
		cout << v1[i];
	cout << "\nal doilea numar este\n";
	for (int i = 1; i <= n2; i++)
		cout << v2[i];
}

void suma(int a[], int b[], int *s, int n, int st)
{
	for (int i = 0; i < n; i++)
	{
		s[i + 1] = v1[st + i] + v2[st + i];
	}
}
int kara(int st, int dr)
{
	int val, s1, s2, p1, p2, sp , ps;
	if (dr > st + 1)
	{
		p1 = kara(st, (st + dr) / 2);
		p2 = kara((st + dr) / 2 + 1, dr);
	}
	else
	{
		s1 = v1[st] + v1[st + 1];
		s2 = v2[st] + v2[st + 1];
		p1 = v1[st] * v2[st];
		p2 = v1[st + 1] * v2[st + 1];
		ps = s1 * s2;
		sp = p1 + p2;
		ps -= sp;
	}
}

int main()
{
	citire();
	egalare();
	afisare();
}