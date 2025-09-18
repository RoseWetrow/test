#include <iostream>
using namespace std;

// Класс Double "имитирующий стандартный тип double"
class Double {
private:
    double value; 

public:
    Double(int val): value(val) {}           // инициализация value целым числом

    void setZero() { value = 0.0; }          // метод установки value в 0
    void print() { cout << value << endl; }  // метод вывода значения value

    Double add(Double& other) {              // метод сложения двух объектов
        return Double(value + other.value);
    }
};

void task1() {
    Double d1(3), d2(4);       // инициализация
    Double d3 = d1.add(d2);    // сложение и присвоение результата третьему

    cout << "Результат сложения: ";
    d3.print();
}

// Класс employee для хранения номера сотрудника и его оклада
class Employee {
private:
    int number;     // номер сотрудника
    float salary;   // оклад

public:
    void inData() {         // ввод данных 
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }
 
    void outData() {  // вывод данных
        cout << "Сотрудник №" << number << ", оклад: " << salary << endl;
    }
};

void task2() {
    Employee emp[3];
    for (int i = 0; i < 3; i++) {  // последовательный ввод данных о сотрудниках
        cout << "Сотрудник " << i + 1 << ":" << endl;
        emp[i].inData();
    }

    cout << "\nДанные сотрудников:\n";
    for (int i = 0; i < 3; i++) {  // последовательный вывод данных о сотрудниках
        emp[i].outData();
    }
}

// Класс date
class Date {
private:
    int month, day, year;
    char slash;

public:
    void getDate() {         // ввод даты
        cout << "Введите дату (MM/DD/YY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    void showDate() const {  // вывод даты с сохранением нулей
        cout << (month < 10 ? "0" : "") << month << "/"
             << (day < 10 ? "0" : "") << day << "/"
             << (year < 10 ? "0" : "") << year << endl;
    }
};

void task3() {
    Date date;
    date.getDate();
    cout << "Вы ввели дату: ";
    date.showDate();
}

// Класс time
class Time {
private:
    int hours, minutes, seconds;

public:
    Time(): hours(0), minutes(0), seconds(0) {}                     // инициализация с нулевыми значениями
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {} // инициализация с заданным набором значений

    void showTime() const {             // вывод значений в формате 11:59:59
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    Time add(const Time& t2) const {    // сложение значений двух объектов time (const метод во избежании изменения t1,
        // перевод времени в секунды                                        //  const ссылка во избежании изменения t2)
        int allSec = t2.hours * 3600 + t2.minutes * 60 + t2.seconds + 
        this->hours * 3600 + this->minutes * 60 + this->seconds; 

        // перевод из секунд в часы.минуты.секунды
        int totalHr = allSec / 3600;            // часы
        allSec = allSec -  totalHr * 3600;      // минус часы, остаются минуты + секунды
        int totalMin = allSec / 60;             // минуты
        int totalSec = allSec - totalMin * 60;  // минус минуты, остаются секунды

        return Time(totalHr, totalMin, totalSec);
        
        // int totalHr = t2.hours + this->hours;
        // int totalMin = t2.minutes + this->minutes;
        // int totalSec = t2.seconds + this->seconds;

        // if (totalSec > 59){
        //     totalSec = totalSec - 60;
        //     totalMin += 1;}
        // if (totalMin > 59){
        //     totalMin = totalMin - 60;
        //     totalHr += 1;}
        // if (totalHr > 12) totalHr = 0;
    
        // return Time(totalHr, totalMin, totalSec);
    }
};

void task4() {
    const Time t1(1, 40, 30);
    const Time t2(2, 30, 40);
    Time result;

    result = t1.add(t2);   // Time result = Time(h, m, s)

    cout << "\nСумма времени: ";
    result.showTime();
}


// Расширенный employee с классом Date и перечислением
class ExtendedEmployee {
private:
    Date hireDate;  // экземпляр класса Date - дата приема сотрудника на работу
    enum Etype {laborer, secretary, manager, accountant, executive, researcher};
    Etype position; // хранение должности сотрудника
    int number;     // номер сотрудника
    float salary;   // оклад сотрудника

public:
    void getEmploy() {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад: ";
        cin >> salary;
        hireDate.getDate();

        char ch;
        cout << "Введите первую букву должности (l, s, m, a, e, r): ";
        cin >> ch;
    
        switch (ch) { // определение должности
            case 'l': position = laborer; break;
            case 's': position = secretary; break;
            case 'm': position = manager; break;
            case 'a': position = accountant; break;
            case 'e': position = executive; break;
            case 'r': position = researcher; break;
            default: cout << "Ошибка ввода"; return;
        }
    }

    void putEmploy() const {
        cout << "Сотрудник №" << number << ", оклад: " << salary << ", дата найма: ";
        hireDate.showDate();

        cout << "Должность: ";    // вывод названия должности    
        switch (position) {
            case laborer: cout << "laborer\n"; break;
            case secretary: cout << "secretary\n"; break;
            case manager: cout << "manager\n"; break;
            case accountant: cout << "accountant\n"; break;
            case executive: cout << "executive\n"; break;
            case researcher: cout << "researcher\n"; break;
        }
    }
};

void task5() {
    ExtendedEmployee emps[3];
    for (int i = 0; i < 3; i++) {  // последовательный ввод данных о сотрудниках
        cout << "\nВведите данные для сотрудника " << i + 1 << ":" << endl;
        emps[i].getEmploy();
    }

    cout << "\nДанные о сотрудниках:\n";
    for (int i = 0; i < 3; i++) {  // последовательный вывод данных о сотрудниках
        emps[i].putEmploy();
    }
}

int main() {
    int choice;
    do {
        cout << "\nВыберите задание (1-5, 0 для выхода): ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: cout << "Выход.\n"; break;
            default: cout << "Неверный выбор.\n";
        }
    } while (choice != 0);
    return 0;
}
