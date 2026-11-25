#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Specialnist { KOMP_NAUKY, INFORMATYKA, MAT_EKONOMIKA, FIZ_INFORMATYKA, TRUD_NAVCHANNIA };

struct Student
{
	string prizv;
	unsigned kurs;
	Specialnist spec;
	int fizyka;
	int matematyka;
	int informatyka;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double SerednijBal(Student s);
void PrintSerednijBal(Student* s, const int N);
double ProcentFizyka4abo5(Student* s, const int N);

int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	do {
		cout << "Введіть кількість студентів N: "; cin >> N;
	} while (N <= 0);

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);
	PrintSerednijBal(s, N);

	double proc = ProcentFizyka4abo5(s, N);
	cout << "Процент студентів, які отримали з фізики оцінки \"5\" або \"4\":" << endl;
	cout << fixed << setprecision(2) << proc << "%" << endl;

	delete[] s;
	return 0;
}

void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, s[i].prizv);
		cout << " курс: "; cin >> s[i].kurs;
		cout << " спеціальність (0 - Комп'ютерні науки, 1 - Інформатика," << endl
			<< "                2 - Математика та економіка, 3 - Фізика та інформатика," << endl
			<< "                4 - Трудове навчання): ";
		cin >> spec;
		s[i].spec = (Specialnist)spec;
		cout << " оцінка з фізики : "; cin >> s[i].fizyka;
		cout << " оцінка з математики : "; cin >> s[i].matematyka;
		cout << " оцінка з інформатики : "; cin >> s[i].informatyka;
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка",
						 "Фізика та інформатика", "Трудове навчання" };

	cout << string(94, '=') << endl;
	cout << "| " << setw(3) << right << "№"
		<< " | " << setw(13) << left << "Прізвище"
		<< " | " << setw(4) << right << "Курс"
		<< " | " << setw(24) << left << "Спеціальність"
		<< " | " << setw(6) << right << "Фізика"
		<< " | " << setw(10) << right << "Математика"
		<< " | " << setw(12) << right << "Інформатика"
		<< " |" << endl;
	cout << string(94, '-') << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1
			<< " | " << setw(13) << left << s[i].prizv
			<< " | " << setw(4) << right << s[i].kurs
			<< " | " << setw(24) << left << specStr[s[i].spec]
			<< " | " << setw(6) << right << s[i].fizyka
			<< " | " << setw(10) << right << s[i].matematyka
			<< " | " << setw(12) << right << s[i].informatyka
			<< " |" << endl;
	}
	cout << string(94, '=') << endl;
	cout << endl;
}

double SerednijBal(Student s)
{ // повертає середній бал студента
	return (s.fizyka + s.matematyka + s.informatyka) / 3.0;
}

void PrintSerednijBal(Student* s, const int N)
{
	cout << "Прізвище та середній бал кожного студента:" << endl;
	for (int i = 0; i < N; i++)
		cout << setw(3) << right << i + 1 << " "
		<< setw(13) << left << s[i].prizv
		<< " " << fixed << setprecision(2) << SerednijBal(s[i]) << endl;
	cout << endl;
}

double ProcentFizyka4abo5(Student* s, const int N)
{ // повертає процент студентів з оцінкою 5 або 4 з фізики
	int k = 0;
	for (int i = 0; i < N; i++)
		if (s[i].fizyka == 5 || s[i].fizyka == 4)
			k++;
	return 100.0 * k / N;
}