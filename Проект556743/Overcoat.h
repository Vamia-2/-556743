class Overcoat {
private:
    string name;
    string type; // ��������, ������, �������
    int size;
    double price;

public:
    // ����������� �� �������������
    Overcoat() : name(""), type(""), size(0), price(0.0) {}

    // ����������� �� �����������
    Overcoat(string n, string t, int s, double p) : name(n), type(t), size(s), price(p) {}

    // ������
    string getName() const { return name; }
    string getType() const { return type; }
    int getSize() const { return size; }
    double getPrice() const { return price; }

    // ������
    void setName(string n) { name = n; }
    void setType(string t) { type = t; }
    void setSize(int s) { size = s; }
    void setPrice(double p) { price = p; }

    // ��������� ���������
    bool operator==(const Overcoat& other) const { return type == other.type; }
    bool operator!=(const Overcoat& other) const { return !(*this == other); }
    bool operator>(const Overcoat& other) const { return price > other.price; }
    bool operator>=(const Overcoat& other) const { return price >= other.price; }
    bool operator<(const Overcoat& other) const { return price < other.price; }
    bool operator<=(const Overcoat& other) const { return price <= other.price; }

    // �������� + ��� ��������� ������ �� 2
    Overcoat operator+(int increment) const {
        Overcoat temp = *this; // ������� �������� ��'���
        temp.size += increment; // ������ 2 �� ������
        return temp; // ��������� ����� ��'���
    }

    // ���������� ���������
    Overcoat& operator++() {
        ++size;
        return *this;
    }

    // ����������� ���������
    Overcoat operator++(int) {
        Overcoat temp = *this;
        ++(*this);
        return temp;
    }

    // ���������� ���������
    Overcoat& operator--() {
        --size;
        return *this;
    }

    // ����������� ���������
    Overcoat operator--(int) {
        Overcoat temp = *this;
        --(*this);
        return temp;
    }

    // �������������� ��������� ��������
    friend istream& operator>>(istream& in, Overcoat& o) {
        cout << "������ ������������: ";
        in >> o.name;
        cout << "������ ��� (��������, ������, �������): ";
        in >> o.type;
        cout << "������ �����: ";
        in >> o.size;
        cout << "������ ����: ";
        in >> o.price;
        return in;
    }

    // �������������� ��������� ���������
    friend ostream& operator<<(ostream& out, const Overcoat& o) {
        out << "������������: " << o.name << "\n���: " << o.type
            << "\n�����: " << o.size << "\nֳ��: " << o.price << "\n";
        return out;
    }
};
