class Overcoat {
private:
    string name;
    string type; // чоловічий, жіночий, дитячий
    int size;
    double price;

public:
    // Конструктор за замовчуванням
    Overcoat() : name(""), type(""), size(0), price(0.0) {}

    // Конструктор із параметрами
    Overcoat(string n, string t, int s, double p) : name(n), type(t), size(s), price(p) {}

    // Гетери
    string getName() const { return name; }
    string getType() const { return type; }
    int getSize() const { return size; }
    double getPrice() const { return price; }

    // Сетери
    void setName(string n) { name = n; }
    void setType(string t) { type = t; }
    void setSize(int s) { size = s; }
    void setPrice(double p) { price = p; }

    // Оператори порівняння
    bool operator==(const Overcoat& other) const { return type == other.type; }
    bool operator!=(const Overcoat& other) const { return !(*this == other); }
    bool operator>(const Overcoat& other) const { return price > other.price; }
    bool operator>=(const Overcoat& other) const { return price >= other.price; }
    bool operator<(const Overcoat& other) const { return price < other.price; }
    bool operator<=(const Overcoat& other) const { return price <= other.price; }

    // Операція + для збільшення розміру на 2
    Overcoat operator+(int increment) const {
        Overcoat temp = *this; // Копіюємо поточний об'єкт
        temp.size += increment; // Додаємо 2 до розміру
        return temp; // Повертаємо новий об'єкт
    }

    // Префіксний інкремент
    Overcoat& operator++() {
        ++size;
        return *this;
    }

    // Постфіксний інкремент
    Overcoat operator++(int) {
        Overcoat temp = *this;
        ++(*this);
        return temp;
    }

    // Префіксний декремент
    Overcoat& operator--() {
        --size;
        return *this;
    }

    // Постфіксний декремент
    Overcoat operator--(int) {
        Overcoat temp = *this;
        --(*this);
        return temp;
    }

    // Перевантаження оператора введення
    friend istream& operator>>(istream& in, Overcoat& o) {
        cout << "Введіть найменування: ";
        in >> o.name;
        cout << "Введіть тип (чоловічий, жіночий, дитячий): ";
        in >> o.type;
        cout << "Введіть розмір: ";
        in >> o.size;
        cout << "Введіть ціну: ";
        in >> o.price;
        return in;
    }

    // Перевантаження оператора виведення
    friend ostream& operator<<(ostream& out, const Overcoat& o) {
        out << "Найменування: " << o.name << "\nТип: " << o.type
            << "\nРозмір: " << o.size << "\nЦіна: " << o.price << "\n";
        return out;
    }
};
