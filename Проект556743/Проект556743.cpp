#include"Shop.h"
#include<iostream>
using namespace std;
int main() {
    setlocale(0, "");
    Shop myShop;
    int choice;

    do {
        cout << "\n--- Меню магазину верхнього одягу ---\n";
        cout << "1. Додати пальто\n";
        cout << "2. Видалити пальто\n";
        cout << "3. Редагувати розмір пальта\n";
        cout << "4. Пошук пальта за типом\n";
        cout << "5. Сортувати пальта за ціною\n";
        cout << "6. Вивести всі пальта\n";
        cout << "0. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Overcoat o;
            cin >> o;
            myShop.addOvercoat(o);
            cout << "Пальто додано.\n";
            break;
        }
        case 2: {
            int index;
            cout << "Введіть номер елемента для видалення: ";
            cin >> index;
            myShop.removeOvercoat(index - 1);
            break;
        }
        case 3: {
            int index, newSize;
            cout << "Введіть номер елемента для редагування: ";
            cin >> index;
            cout << "Введіть новий розмір: ";
            cin >> newSize;
            myShop.editSize(index - 1, newSize);
            break;
        }
        case 4: {
            string type;
            cout << "Введіть тип для пошуку (чоловічий, жіночий, дитячий): ";
            cin >> type;
            myShop.findByType(type);
            break;
        }
        case 5: {
            myShop.sortByPrice();
            break;
        }
        case 6: {
            myShop.printAll();
            break;
        }
        case 0: {
            cout << "Вихід з програми.\n";
            break;
        }
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}

