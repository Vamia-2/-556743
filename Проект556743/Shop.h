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
    // ��������� ��������
    void addOvercoat(const Overcoat& o) {
        shop.push_back(o);
    }

    // ��������� �������� �� ��������
    void removeOvercoat(int index) {
        if (index >= 0 && index < shop.size()) {
            shop.erase(shop.begin() + index);
            cout << "������� ������ ��������.\n";
        }
        else {
            cout << "������������ ������.\n";
        }
    }

    // ����������� ������ �������� �� ��������
    void editSize(int index, int newSize) {
        if (index >= 0 && index < shop.size()) {
            shop[index].setSize(newSize);
            cout << "����� ������ ��������.\n";
        }
        else {
            cout << "������������ ������.\n";
        }
    }

    // ����� �� �����
    void findByType(const string& type) const {
        bool found = false;
        for (const auto& overcoat : shop) {
            if (overcoat.getType() == type) {
                cout << overcoat << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "ͳ���� �� �������� ��� ����: " << type << "\n";
        }
    }

    // ���������� �� �����
    void sortByPrice() {
        sort(shop.begin(), shop.end(), [](const Overcoat& a, const Overcoat& b) {
            return a.getPrice() < b.getPrice();
            });
        cout << "���������� �� ����� ���������.\n";
    }

    // ��������� ��� ������
    void printAll() const {
        if (shop.empty()) {
            cout << "������� �������.\n";
            return;
        }
        for (size_t i = 0; i < shop.size(); ++i) {
            cout << "������� " << i + 1 << ":\n" << shop[i] << endl;
        }
    }
};
