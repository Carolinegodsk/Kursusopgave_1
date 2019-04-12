//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define NMAX 100

void Programintroduktion();
double f(double t);

// Del A:
void IntroA();
void IntroA1();
void IndtastDataA1(double &a, double &b, int &n);
double Simpson(double a, double b, int n);

void IntroA2();
void IndtastDataA2(double &x, int &n);
double Fix_by_Simpson(double x, int n);

void IntroA3();
void IndtastDataA3(double &x);
double Fix_by_Taylor(double x);

// Del B:
void IntroB();
void IntroB1();
void IndtastDataB1(double &xmin, double &xmax, int &N);
void Fix_Table(double xmin, double xmax, int N);

void IntroB2();
void IndtastDataB2(double &a, double &b);
void Test_Simpson(double a, double b);

int main() {
	char svar, del, svarA, svarB;
	int n, valgA, valgB, N;
	double a, b, x, xmin, xmax;
	do {
		Programintroduktion();
		do {
			cout << "\nVil du køre program A eller B? Tast her: " << endl;
			cin >> del;
		}
		while(del != 'A' && del != 'a' && del != 'B' && del != 'b');
		if (del=='A' or del=='a'){
			do {
				IntroA();
				do {
					cout << "Indtast 1, 2 eller 3:" << endl;
					cin >> valgA;
				}
				while (valgA != 1 && valgA != 2 && valgA != 3);
				switch (valgA){
					case 1:
						IntroA1();
						IndtastDataA1(a,b,n);
						cout << "Integralet ved Simpson = " << Simpson(a,b,n) << endl;
						break;
					case 2:
						IntroA2();
						IndtastDataA2(x,n);
						cout << "Normalfordeling ved Simpson = " << Fix_by_Simpson(x,n) << endl;
						break;
					case 3:
						IntroA3();
						IndtastDataA3(x);
						cout << "Normalfordeling ved Taylor = " << Fix_by_Taylor(x) << endl;
						break;
					}
				cout << "\nVil du køre del A igen? Skriv J for ja, N for nej: ";
				cin >> svarA;
				}
			while (svarA=='J' or svarA=='j');
		}
		else if (del=='B' or del=='b'){
			do {
				IntroB();
				do {
					cout << "Indtast 1 eller 2:" << endl;
					cin >> valgB;
				}
				while (valgB != 1 && valgB != 2);
				switch (valgB){
					case 1:
						IntroB1();
						IndtastDataB1(xmin,xmax,N);
						Fix_Table(xmin,xmax,N);
						break;
					case 2:
						IntroB2();
						IndtastDataB2(a,b);
						Test_Simpson(a,b);
						break;
					}
				cout << "\nVil du køre del B igen? Skriv J for ja, N for nej: ";
				cin >> svarB;
			}
			while (svarB=='J' or svarB=='j');
		}
		else {
			cout << "Indtast venligst A eller B: " << endl;
		}
		cout << "\nVil du køre hele programmet igen? Skriv J for ja, N for nej: ";
		cin >> svar;
	}
	while (svar=='J' or svar=='j');
	return 0;
}


void Programintroduktion(){
	cout << "Dette program beskæftiger sig med numerisk integration af den Gaussiske tæthedsfunktion, og udregner tilnærmelsesvis";
	cout << "\nværdien af det bestemte integrale af f(t)=(1/√2π)*e^((-1/2)t^2) vha. Simpsons metode og Taylorpolynomier.";
	cout << "\n\nProgrammet er delt op i to dele: ";
	cout << "\n\nA)   Beregning af tilnærmede funktionsværdier af det bestemte integrale vha. Simpson, Φ(x) by Simpson, Φ(x) by Taylor";
	cout << "\n\nB)   Beregning og udskrivning af tabel over tilnærmede værdier af det bestemte integrale vha. Taylor, Φ(x) by Simpson, Φ(x) by Taylor" << endl;
}

double f(double t){
	double f;
	f = (1/sqrt(2*acos(-1)))*exp(-0.5*t*t);
	return f;
}

// Del A:

void IntroA(){
	cout << "\nDel A af programmet beregner hhv. tilnærmede værdier af det bestemte integrale vha. Simpsons regel, Φ(x) vha. Simpsons regel, Φ(x) vha. Taylorpolynomier";
	cout << "\n\nVælg næste skridt: ";
	cout << "\n1)   Integration ved Simpson, tast 1";
	cout << "\n2)   Φ(x) vha. Simpson, tast 2";
	cout << "\n3)   Φ(x) vha. Taylor, tast 3" << endl;
}

void IntroA1(){
	cout << "\nDette program approksimerer numerisk det bestemte integrale for normalfordelingsfunktionen i et givet areal [a,b] og n delintervaller vha. Simpsons regel:" << endl;
}

void IndtastDataA1(double &a, double &b, int &n){
	cout << "\nIndtast ønsket interval [a,b], samt antal delintervaller, n: " << endl;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "n = "; cin >> n;
}

double Simpson(double a, double b, int n){
	double I, h, sum1, sum2, sum4;
	h = (b-a)/n;
	sum1 = f(a)+f(b);
	sum2 = 0;
	for(int i=1; i<n; i++) {
		sum2 += f(a+i*h);
	}
	sum4 = 0;
	for(int i=1; i<=n; i++) {
			sum4 += f(a-h/2+i*h);
		}
	I = (h/6)*(sum1+2*sum2+4*sum4);
	return I;
}

void IntroA2(){
	cout << "\nDette program approksimerer Φ(x) for normalfordelingsfunktionen omkring et givent x!=0 vha. Simpsons regel:" << endl;
}

void IndtastDataA2(double &x, int &n){
	cout << "\nIndtast ønsket x, samt antal delintervaller, n: " << endl;
	cout << "x = "; cin >> x;
	cout << "n = "; cin >> n;
}

double Fix_by_Simpson(double x, int n){
	double Fix, I, h, sum1, sum2, sum4;
	h = x/n;
	sum1 = f(0)+f(x);
	sum2 = 0;
	for(int i=1; i<n; i++) {
		sum2 += f(i*h);
	}
	sum4 = 0;
	for(int i=1; i<=n; i++) {
		sum4 += f((-h)/2+i*h);
		}
	I = h/6*(sum1+2*sum2+4*sum4);
	Fix = 0.5+I;
	return Fix;
}

void IntroA3(){
	cout << "\nDette program approksimerer Φ(x) for normalfordelingsfunktionen omkring et givent x!=0 vha. et Taylor-polynomium:" << endl;
}

void IndtastDataA3(double &x){
	cout << "\nIndtast ønsket x-værdi: " << endl;
	cout << "x = "; cin >> x;
}

double Fix_by_Taylor(double x){
	double fx, term, sum, Fix;
	int k;
	k=0; term=x; sum=x;
	do{
		k=k+1;
		fx=sum;
		term=term*(-0.5)*x*x/k*(2*k-1)/(2*k+1);
		sum+=term;
	}
	while(fx!=sum);
	Fix=0.5+1/sqrt(2*acos(-1))*sum;
	return Fix;
}

// Del B:

void IntroB(){
	cout << "\nDel B af programmet udskriver en tabel over tilnærmede værdier af Φ(x) vha. hhv. Simpsons regel og Taylorpolynomier";
	cout << "\n\nVælg næste skridt: ";
	cout << "\n1)   Tabel med x, Φ(x) ved Simpsons regel og Φ(x) ved et Taylor-polynomium, tast 1";
	cout << "\n2)   Tabel med n og numerisk integration ved Simpsons regel, tast 2" << endl;
}

void IntroB1(){
	cout << "\nDette program udskriver en tabel med x, Φ(x) ved Simpsons regel og Φ(x) ved et Taylorpolynomium" << endl;
}

void IndtastDataB1(double &xmin, double &xmax, int &N){
	cout << "\nIndtast ønsket interval og antal elementer, der skal udskrives, N: " << endl;
	cout << "xmin = "; cin >> xmin;
	cout << "xmax = "; cin >> xmax;
	cout << "N = "; cin >> N;
}

void Fix_Table(double xmin, double xmax, int N){
	double x, dx, fix_Simpson, fix_Taylor;
	int n, k;
	char svar;
	do {
		cout << "Indtast antal delintervaller, n: "; cin >> n;
		dx = (xmax-xmin)/(N-1);
		x = xmin;
		fix_Simpson = 0.5+Simpson(0,x,n);
		fix_Taylor = Fix_by_Taylor(x);
		cout << endl << setw(10) << "x" << "  |  " << setw(20) << "Φ(x) ved Simpson" << "   |  " << setw(20) << "Φ(x) ved Taylor" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << setw(10) << x << "  |  " << setw(20) << setprecision(14) << fix_Simpson << "  |  " << setw(20) << setprecision(14) << fix_Taylor << endl;
		for(k=1; k<N; k++){
			fix_Simpson += Simpson(x,x+dx,n);
			x += dx;
			fix_Taylor = Fix_by_Taylor(x);
			cout << setw(10) << x << "  |  " << setw(20) << setprecision(14) << fix_Simpson << "  |  " << setw(20) << setprecision(14) << fix_Taylor << endl;
		}
		cout << "\nVil du køre programmet igen med et nyt n? Skriv J for ja, N for nej: ";
		cin >> svar;
	}
	while (svar == 'J' or svar == 'j');
}

void IntroB2(){
	cout << "\nDette program udskriver en tabel med brugervalgte n-værdier og numerisk integration vha. Simpsons regel" << endl;
}

void IndtastDataB2(double &a, double &b){
	cout << "\nIndtast nedre grænse, a = "; cin >> a;
	cout << "Indtast øvre grænse, b = "; cin >> b;
}

void Test_Simpson(double a, double b){
	int n=0, nTabel[NMAX];
	double In, InTabel[NMAX];
	char svar;
	cout << "Indtast nu værdier af n løbende:" << endl;
	do {
		cout << "Indtast værdi n = "; cin >> nTabel[n];
		In = Simpson (a,b,nTabel[n]);
		InTabel[n] = In;
		n++;
		cout << "Ønsker du at indtaste en værdi mere? j/n: ";
		cin >> svar;
	}
	while (svar == 'j');
	cout << endl << setw(10) << "n" << "  |  " << setw(20) << "I(n)" << endl;
	cout <<"------------------------------------"<<endl;
	for(int i=0; i<n; i++){
		cout << setw(10) << nTabel[i] << "  |  " << setw(20) << setprecision(14) << InTabel[i] << endl;
	}
}

