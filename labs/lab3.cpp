#include <iostream>
using namespace std;

// структура для хранения информации о сотруднике
struct employee {
    int number;     // номер сотрудника
    float salary;   // зарплата
};

// Информация о сотрудниках
void task1() {
    employee emp1, emp2, emp3;
    char zap;
    
    // ввод данных о сотрудниках
    cout << "\nВведите номер сотрудника и его зарплату в формате номер, зарплата: ";
    cin >> emp1.number >> zap >> emp1.salary;
    cout << "Введите номер сотрудника и его зарплату: ";
    cin >> emp2.number >> zap >> emp2.salary;
    cout << "Введите номер сотрудника и его зарплату: ";
    cin >> emp3.number >> zap >> emp3.salary;
    
    // вывод информации
    cout << "\nСотрудник 1: № " << emp1.number << ", зарплата " << emp1.salary << " руб.\n";
    cout << "Сотрудник 2: № " << emp2.number << ", зарплата " << emp2.salary << " руб.\n";
    cout << "Сотрудник 3: № " << emp3.number << ", зарплата " << emp3.salary << " руб.\n";
}

// перечисление для должностей
enum etype { laborer, secretary, manager, accountant, executive, researcher };

// Обработка должностей сотрудников
void task2() {
    char ch;
    cout << "\nВведите первую букву должности (l, s, m, a, e, r): ";
    cin >> ch;
    etype position;

    switch (ch) {                             // определение должности
        case 'l': position = laborer; break;
        case 's': position = secretary; break;
        case 'm': position = manager; break;
        case 'a': position = accountant; break;
        case 'e': position = executive; break;
        case 'r': position = researcher; break;
        default: cout << "Ошибка ввода"; return;
    }
    
    cout << "Полное название должности: ";    // вывод названия должности    
    switch (position) {
        case laborer: cout << "laborer\n"; break;
        case secretary: cout << "secretary\n"; break;
        case manager: cout << "manager\n"; break;
        case accountant: cout << "accountant\n"; break;
        case executive: cout << "executive\n"; break;
        case researcher: cout << "researcher\n"; break;
    }
}

// структура для хранения дробей
struct fraction {
    int chis;
    int znam;
};

// Сложение дробей с использованием структуры
void task3() {
    fraction frac1, frac2, result;
    char dummychar;
    
    cout << "\nВведите первую дробь (в формате a / b): ";
    cin >> frac1.chis >> dummychar >> frac1.znam;
    cout << "Введите вторую дробь (в формате c / d): ";
    cin >> frac2.chis >> dummychar >> frac2.znam;
    
    result.chis = frac1.chis * frac2.znam + frac1.znam * frac2.chis;
    result.znam = frac1.znam * frac2.znam;
    
    cout << "Сумма равна: " << result.chis << "/" << result.znam << endl;
}

// структура для хранения времени
struct time {
    int hours;
    int minutes;
    int seconds;
};

// Расчет общего количества секунд во времени
void task4() {
    char dot;
    struct time t;    // явно указываем, что time - структура, 
                      // так как "time" зарезервировано под метод
    cout << "\nВведите время в формате часы:минуты:секунды - ";
    cin >> t.hours >> dot >> t.minutes >> dot >> t.seconds;
    
    int totalSeconds = t.hours * 3600 + t.minutes * 60 + t.seconds;
    cout << "Количество секунд в введенном времени: " << totalSeconds << endl;
}

// Cложение двух моментов времени
void task5() {
    struct time t1, t2, sum;
    char dot;

    do {
        cout << "\nВведите первое время (формат 12:59:59): ";
        cin >> t1.hours >> dot >> t1.minutes >> dot >> t1.seconds;
    
        cout << "Введите второе время (формат 12:59:59): ";
        cin >> t2.hours >> dot >> t2.minutes >> dot >> t2.seconds;
    
        if (t1.minutes > 59 || t2.minutes > 59 || t1.seconds > 59 || t2.seconds > 59 || t1.hours > 12 || t2.hours > 12) {
            cout << "Ошибка в введенном формате времени.\n";
        }
    } while (t1.minutes > 59 || t2.minutes > 59 || t1.seconds > 59 || t2.seconds > 59 || t1.hours > 12 || t2.hours > 12);
    
    // перевод времени в секунды
    int totalSec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int totalSum = totalSec1 + totalSec2;

    // перевод обратно в часы, минуты и секунды
    sum.hours = totalSum / 3600;             // часы
    totalSum = totalSum - sum.hours * 3600;  // минус часы, остаются минуты + секунды
    sum.minutes = totalSum / 60;             // минуты
    sum.seconds = totalSum - sum.minutes * 60;  // минус минуты, остаются секунды

    if (sum.hours >= 12) { // если часов больше 12, записываем разницу
        sum.hours -= 12;
    }

    cout << "Сумма времени: " << sum.hours << ":" << sum.minutes << ":" << sum.seconds << endl;
}


int main() {
    int choice;
    do {
        cout << "Выберите задание (1-5) или 0 для выхода: ";
        cin >> choice;
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
        }
    } while (choice != 0);
    return 0;
}