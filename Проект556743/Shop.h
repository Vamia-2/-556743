#pragma once
#include "Overcoat.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Shop {
private:
    vector<Overcoat> shop;

public:
    // Додавання елементу
    void addOvercoat(const Overcoat& o) {
        shop.push_back(o);
    }

    // Видалення елементу за індексом
    void removeOvercoat(int index) {
        if (index >= 0 && index < shop.size()) {
            shop.erase(shop.begin() + index);
            cout << "Елемент успішно видалено.\n";
        }
        else {
            cout << "Неправильний індекс.\n";
        }
    }

    // Редагування розміру елементу за індексом
    void editSize(int index, int newSize) {
        if (index >= 0 && index < shop.size()) {
            shop[index].setSize(newSize);
            cout << "Розмір успішно оновлено.\n";
        }
        else {
            cout << "Неправильний індекс.\n";
        }
    }

    // Пошук за типом
    void findByType(const string& type) const {
        bool found = false;
        for (const auto& overcoat : shop) {
            if (overcoat.getType() == type) {
                cout << overcoat << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Нічого не знайдено для типу: " << type << "\n";
        }
    }

    // Сортування за ціною
    void sortByPrice() {
        sort(shop.begin(), shop.end(), [](const Overcoat& a, const Overcoat& b) {
            return a.getPrice() < b.getPrice();
            });
        cout << "Сортування за ціною завершено.\n";
    }

    // Виведення всіх товарів
    void printAll() const {
        if (shop.empty()) {
            cout << "Магазин порожній.\n";
            return;
        }
        for (size_t i = 0; i < shop.size(); ++i) {
            cout << "Елемент " << i + 1 << ":\n" << shop[i] << endl;
        }
    }
};
