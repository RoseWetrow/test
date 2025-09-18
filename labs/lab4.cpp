#include <iostream>
using namespace std;

// Функция по переводу времени в секунды
long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}

void task1() {
    int hours, minutes, seconds;
    while (true) {
        cout << "\nВведите часы, минуты и секунды (через пробел): ";
        cin >> hours >> minutes >> seconds;
        if (minutes > 59 || seconds > 59 || hours < 0) {     // проверка на соответствие формату
            cout << "Ошибка в введенном формате времени.\n";
            continue;
        }
        cout << "Общее количество секунд: " << hms_to_secs(hours, minutes, seconds) << endl;
        break;
    }
}

struct time {
    int hours;
    int minutes;
    int seconds;
};

// Функция по переводу времени в скунды
long time_to_secs(struct time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Функция по переводу из секунд в часы.минуты.секунды
struct time secs_to_time(long totalSec) {
    struct time t;
    t.hours = totalSec / 3600;               // часы
    totalSec = totalSec -  t.hours * 3600;  // минус часы, остаются минуты + секунды
    t.minutes = totalSec / 60;               // минуты
    t.seconds = totalSec - t.minutes * 60; // минус минуты, остаются секунды
    return t;
}

// Cложение двух моментов времени
void task2() {
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
    
    // передаем функции структуру из часов минут и секунд для перевода в секунды, получаем long значение
    long totalSum = time_to_secs(t1) + time_to_secs(t2);

    // перевод обратно в часы, минуты и секунды
    sum = secs_to_time(totalSum);

    if (sum.hours > 12) { // если часов больше 12, записываем разницу
        sum.hours -= 12;
    }

    cout << "Сумма времени: " << sum.hours << ":" << sum.minutes << ":" << sum.seconds << endl;
}


// Функция по обмену значениями двух аргументов для структуры time
// чтобы изменения сохранились в вызывающей функции, используем передачу по ссылке.
void swap(int &a, int &b) {
    int temp = a; // используем временную переменную, 
    a = b;        // чтобы корректно присвоить a значение b, b значение a
    b = temp;
}

void task3() {
    int x, y;
    cout << "\nВведите два числа через пробел: ";
    cin >> x >> y;
    cout << "До обмена: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "После обмена: x = " << x << ", y = " << y << endl;
}

// Функция по обмену значениями двух аргументов типа time (структура)
void swap(struct time &t1, struct time &t2) {
    struct time temp = t1;
    t1 = t2;
    t2 = temp;
}

void task4() {
    struct time t1, t2;
    char dot;
    
    cout << "\nВведите первое время (формат часы:минуты:секунды): ";
    cin >> t1.hours >> dot >> t1.minutes >> dot >> t1.seconds;

    cout << "Введите второе время (формат часы:минуты:секунды): ";
    cin >> t2.hours >> dot >> t2.minutes >> dot >> t2.seconds;
    
    cout << "До обмена: первое время " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " второе время "
         << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
    swap(t1, t2);
    cout << "После обмена: первое время " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " второе время "
         << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
}

// Функция по подсчету количества вызовов
// используем статическую переменную для сохранения количества вызывов
void counter() {
    static int count = 0;   
    count++;
    cout << "Функция вызвана " << count << " раз(а)." << endl;
}

void task5() {
    for (int i = 0; i < 10; i++) {
        counter();
    }
}

int main() {
    int choice;
    do {
        cout << "\nВыберите задание (1-5) или 0 для выхода: ";
        cin >> choice;
        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: cout << "Выход...\n"; break;
            default: cout << "Некорректный ввод, попробуйте снова.\n";
        }
    } while (choice != 0);
    return 0;
}