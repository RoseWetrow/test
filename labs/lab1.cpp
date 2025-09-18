#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

// Вывод стихотворения
void task1() {
    printf("О сколько нам открытий чудных\nГотовят просвещенья дух\nИ опыт, сын ошибок трудных,\nИ гений, парадоксов друг.\n");
    cout << "\n(А.С. Пушкин)" << endl;
}

// Перевод Цельсия в Фаренгейт
void task2() {
    double celsius;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> celsius;
    double fahrenheit = (celsius * 9/5) + 32;
    cout << "Температура в градусах Фаренгейта: " << fahrenheit << endl;
}

// Сложение дробей
void task3() {
    int a, b, c, d;
    char dummychar ;
    cout << "Введите первую дробь (в формате a / b): ";
    cin >> a >> dummychar >> b;
    cout << "Введите вторую дробь (в формате c / d): ";
    cin >> c >> dummychar >> d;
    int chis = a * d + b * c;
    int znam = b * d;
    cout << "Сумма равна: " << chis << "/" << znam << endl;
}

// Конвертация старого денежного формата в новый
// Если в новой системе 1 фунт = 100 пенс, а в старой = 240 пенс (20*12), значит инфляция в 2.4 раза. 
void task4() {
    int pounds, shillings, pence;
    cout << "Введите количество фунтов: ";
    cin >> pounds;
    cout << "Введите количество шиллингов: ";
    cin >> shillings;
    cout << "Введите количество пенсов: ";
    cin >> pence;
    double decimalPounds = ((pounds * 240 + shillings * 12 + pence) / 2.4) / 100;  // переводим старую валюту в пенсы, 
    cout << "Десятичных фунтов: £" << decimalPounds << endl;                       // затем переводим в новые пенсы (путем деления на 2.4), затем переводим в новые фунты
}

// Конвертация десятичных фунтов в старый формат 
void task5() {
    double decimalPounds;
    cout << "Введите число десятичных фунтов: ";
    cin >> decimalPounds;

    int pounds = static_cast<int>(decimalPounds);     // отбрасывание дробной части (остаются фунты) 
    double modern_shillings_pence = (decimalPounds - pounds) * 100;  // выделение дробной части (остаются новые шиллинги и пенсы)
    double inOldPence = modern_shillings_pence * 2.4;        // новые шиллинги и пенсы в старых пенсах (в 2.4 раза инфляция) 
    double old_shillings_pence = inOldPence / 12;            // получение из старых пенсов старого формата шиллинги.пенсы
    int old_shillings = static_cast<int>(old_shillings_pence);       // отбрасывание дробной части (остаются старые шиллинги)
    double old_pences = (old_shillings_pence - old_shillings) * 10; // из старого формата шиллинги.пенсы убираем шиллинги - остаются старые пенсы

    cout << "Эквивалентная сумма в старой форме записи: £" << pounds << "." << old_shillings << "." << old_pences << endl;
}

int main() {
    int choice;
    cout << "Выберите задание (1-5): ";
    cin >> choice;
    switch(choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        default: cout << "Некорректный выбор" << endl;
    }
    return 0;
}