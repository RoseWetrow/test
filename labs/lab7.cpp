#include <iostream>
#include <cstring>
using namespace std;



// Функция, складывающая элементы двух массивов (a, b) и сохраняющая в третий (result)
void addarrays(float* a, float* b, float* result, int size) {
    // цикл по всем элементам массивов
    for (int i = 0; i < size; i++) {
        *(result + i) = *(a + i) + *(b + i); // последовательное сложение и сохранение
    }                                        // ~ записать в result[i] сумму a[i] и b[i]
}

// Сумма элементов массивов через указатели
void task1() {
    const int size = 5;
    float a[size] = {1.1, 2.2, 3.3, 4.4, 5.5}; // инициализация массива 1
    float b[size] = {5.5, 6.6, 7.7, 8.8, 9.9}; // инициализация массива 2
    float result[size];                        // массив для суммы

    addarrays(a, b, result, size);

    cout << "\nРезультирующий массив: ";
    // последовательный вывод элементов массива result
    for (int i = 0; i < size; i++) cout << result[i] << " "; 
    cout << endl;
}



// Функция, сравнивающая две строки по числовому значению из таблицы ASCII
// и возвращающая в соответсвии -1/0/1
int compstr(char* s1, char* s2) { 
    // посимвольное сравнение строк, пока они обе не закончились
    while (*s1 != '\0' && *s2 != '\0') {  
        if (*s1 < *s2) return -1;     // первая строка меньше второй (-1)
        else if (*s1 > *s2) return 1; // первая строка длиннее второй (1)
        s1++; // переход к следующим символам
        s2++;
    }
    // обе строки закончились одновременно = они одинаковы (0)
    if (*s1 == '\0' && *s2 == '\0') return 0;
    // одна строка закончилась раньше другой (-1 если первая, 1 если вторая)
    return (*s1 == '\0') ? -1 : 1;
}

// Сравнение строк через указатели
void task2() {
    char str1[100], str2[100];
    cout << "\nВведите первую строку: ";
    cin >> str1;
    cout << "Введите вторую строку: ";
    cin >> str2;

    int result = compstr(str1, str2);
    cout << "Результат сравнения: " << result << endl;
}



// Массив указателей на 10 массивов из 10 элементов в каждом
void task3() {
    const int NUMARRAYS = 10, MAXSIZE = 10;
    // 10 массивов размера 10 элементов
    int a0[MAXSIZE], a1[MAXSIZE], a2[MAXSIZE], a3[MAXSIZE], a4[MAXSIZE];
    int a5[MAXSIZE], a6[MAXSIZE], a7[MAXSIZE], a8[MAXSIZE], a9[MAXSIZE];
    // массив из указателей на массивы
    int* ap[NUMARRAYS] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

    // последовательное заполнение каждого массива 10 элементами
    for (int j = 0; j < NUMARRAYS; j++) {   // перебор массивов a0, a1...
        for (int k = 0; k < MAXSIZE; k++) { // перебор всех значений массива
            ap[j][k] = j + k;               // заполнение тестовыми данными
        }
    }
    // последовательный вывод по тому же принципу
    for (int j = 0; j < NUMARRAYS; j++) {   
        for (int k = 0; k < MAXSIZE; k++) {
            cout << ap[j][k] << " ";
        }
        cout << endl;
    }
}



// Динамическое создание массива указателей на 10 массивов из 10 элементов в кадом
void task4() {
    const int NUMARRAYS = 10, MAXSIZE = 10;
    int* ap[NUMARRAYS]; // массив из указателей на массивы 

    // последовательное создание новых массивов с динамическим выделением памяти
    // и заполнение элементов массива тестовыми данными
    for (int j = 0; j < NUMARRAYS; j++) { 
        *(ap + j) = new int[MAXSIZE];  // динамическое выделение памяти под массив
        for (int k = 0; k < MAXSIZE; k++) {
            *(*(ap + j) + k) = j + k;  // разыменование указателя на k элемент j массива ap
        }   // ap[j][k]                       
    }
    
    for (int j = 0; j < NUMARRAYS; j++) {
        for (int k = 0; k < MAXSIZE; k++) {
            cout << *(*(ap + j) + k) << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < NUMARRAYS; j++) delete[] ap[j]; // освобождение памяти
}

// Аналогично
// // Динамическое создание массива указателей на 10 массивов из 10 элементов в кадом
// void task4() {
//     const int NUMARRAYS = 10, MAXSIZE = 10;
//     int* ap[NUMARRAYS]; // массив из указателей на массивы 

//     // последовательное создание новых массивов с динамическим выделением памяти
//     for (int j = 0; j < NUMARRAYS; j++) { 
//         ap[j] = new int[MAXSIZE];  // динамическое выделение памяти под массив
//         for (int k = 0; k < MAXSIZE; k++) {
//             ap[j][k] = j + k;      // заполнение элементов массива тестовыми данными
//         }                          // [0][0] [0][1] [0][2]...[1][0] [1][1] [1][2]... 
//     }

//     for (int j = 0; j < NUMARRAYS; j++) {
//         for (int k = 0; k < MAXSIZE; k++) {
//             cout << ap[j][k] << " "; // доступ через указатели
//         }
//         cout << endl;
//     }

//     for (int j = 0; j < NUMARRAYS; j++) delete[] ap[j]; // освобождение памяти
// }


// Структура для сотрудников
struct Person {
    char* name;     // имя
    float salary;   // зарплата
};

// Функция ввода информации о сотрудниках
void input_persons(Person* persons, int count) {
    cout << "\nВведите информацию о " << count << " сотрудниках." << endl;
    for (int i = 0; i < count; i++) {
        char buffer[100]; // временный буфер для введенного имени
        cout << "Введите имя " << i + 1 << " сотрудника: ";
        cin >> buffer;
        // динамически выделяем место в куче для i сотрудника (учитывая \0 для строки)
        persons[i].name = new char[strlen(buffer) + 1]; 
        strcpy(persons[i].name, buffer); // копирование строки из стека в кучу

        cout << "Введите зарплату: ";
        cin >> persons[i].salary;
    }
}

// Функция вывода информации о сотрудниках
void print_persons(Person* persons, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Имя: " << persons[i].name << ", зарплата: " << persons[i].salary << endl;
    }
}

// Фунцкия сортировки сотрудников по величине зарплаты
void sort_persons(Person* persons, int count) {
    for (int i = 0; i < count-1; i++){    // 4 раза сраниваем элементы (оцениваем по последнему)
        for (int j = 0; j < count-1; j++) {
            // если зп j сотрудника больше следующего - меняем местами зп и имя
            if(persons[j].salary > persons[j+1].salary){ 
                // меняем местами зп
                float temp_el_salary = persons[j].salary;// создание временного элемента
                persons[j].salary = persons[j+1].salary;
                persons[j+1].salary = temp_el_salary;
                // меняем местами имена
                char* temp_el_name = persons[j].name;    // создание временного элемента
                persons[j].name = persons[j+1].name;
                persons[j+1].name = temp_el_name;
            }
        }
    }
}

void task5() {
    const int count = 5;
    // создаем указатель на данные типа Person и 
    // выделяем память для хранения информации о 5 сотрудниках
    Person* persons = new Person[count]; 

    input_persons(persons, count); // ввод 
    cout << "\nДо сортировки:\n";
    print_persons(persons, count); // вывод

    sort_persons(persons, count); // сортировка

    cout << "\nПосле сортировки:\n";
    print_persons(persons, count); // вывод

    for (int i = 0; i < count; i++) delete[] persons[i].name; // освобождение строк
    delete[] persons; // освобождение массива структур
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