//#include <iostream>
//#include <cstdlib>
//#include <math.h>
//#include <stdlib.h>
//#include <iomanip>
//#include <string>
//using namespace std;
//class Vokzal
//{
//    int length;//����� ��������
//    string peronu;// �������� �������
//
//public:
//    Vokzal(string p, int pe) :peronu(p) {}
//    Vokzal() {}
//    void set(Vokzal v[]);
//    void show(Vokzal v[]);
//
//};
//class Train
//{
//
//    string on_dest;//����� ��������
//    string destination; //����� ���������� 
//    int departure;// ����� , �������� 
//    int time;//����� , ��������
//    int vagon;//����� ������� 
//
//
//
//public:
//
//    Train(string on, string de, int d, int t, int v) : on_dest(on), destination(de), departure(d), time(t), vagon(v) {}
//    Train() {}
//    void set2();
//    void show_Train()const;
//
//
//};
//
//
//class Vagon
//{
//
//    string tip;//��� ������ 
//    int mest;//����� ���� 
//    int new_mest;//����� ��������� ����
//public:
//    Vagon(int v, string t, int m, int nm) :tip(t), mest(m), new_mest(nm) {}
//    Vagon() {}
//    void set_Vagon();
//    void show_Vagon()const;
//    void buy_Vagon();
//
//};
//class Person
//{
//
//    char name[20];//��� ���������
//    char family[20]; //������� ���������
//    char gender[20];//���
//    int age;//�������
//    int pasport;//����� �������� 
//public:
//    void set_Person();
//    void show_Person()const;
//
//};
//
//
//void Train::set2()
//{
//
//
//    {
//        cout << "������� ����� �������: ";
//        cin.get();
//        cin >> on_dest;
//        cout << "������� ����� ����������: ";
//        cin.get();
//        cin >> destination;
//
//        cout << "������� ����� �������: ";
//        while (!(cin >> departure) || departure < 1 || departure>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ����� ������� : ";
//        }
//
//        cout << "������� ����� ��������: ";
//        while (!(cin >> time) || time < 1 || time>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ����� � ����: ";
//        }
//        cout << "������� ���������� �������: ";
//        while (!(cin >> vagon) || vagon < 1 || vagon>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ���������� �������: ";
//        }
//
//    }
//}
//void Train::show_Train()const
//{
//
//    {
//        cout << "����� �������: " << on_dest << endl;
//        cout << "����� ����������:  " << destination << endl;
//        cout << "����� �������:  " << departure << endl;
//        cout << "����� ��������:  " << time << endl;
//        cout << "���������� �������:  " << vagon << endl;
//
//    }
//}
//
//void Vokzal::set(Vokzal v[])
//{
//    cout << "������� ���������� ��������:" << endl;
//    cin >> length;
//    for (int i = 0; i < length; i++)
//    {
//        cout << "������� �������� ������� : " << endl;
//        cin >> v[i].peronu;
//    }
//}
//void Vokzal::show(Vokzal v[])
//{
//    for (int i = 0; i < length; i++)
//    {
//        cout << i + 1 << ":\n";
//        cout << "�������� �������: " << v[i].peronu << endl;
//    }
//}
//void Vagon::set_Vagon()
//{
//    cout << "��� ������ :" << endl;
//    cin >> tip;
//    cout << "���������� ���� :" << endl;
//    cin >> mest;
//    cout << "���������� ��������� ���� :" << endl;
//    cin >> new_mest;
//
//
//}
//void Vagon::show_Vagon()const
//{
//    cout << "��� ������ : " << tip << endl;
//    cout << "���������� ���� : " << mest << endl;
//    cout << "���������� ��������� ����: " << new_mest << endl;
//
//}
//void Vagon::buy_Vagon()
//{
//    int n;
//    int ticket;
//    cout << "������� ���-�� ���������� �������" << endl;
//    cin >> ticket;
//    for (int i = 0; i < ticket; i++)
//    {
//        n = new_mest - ticket;
//    }
//    cout << "����� ���������� ��������� ����" << n << endl;
//}
//
//void Person::set_Person()
//{
//    cout << "������� ��� ���������: " << endl;
//    cin >> name;
//    cout << "������� ������� ���������: " << endl;
//    cin >> family;
//    cout << "������� ��� ���������: " << endl;
//    cin >> gender;
//    cout << "������� ������� ���������: " << endl;
//    cin >> age;
//    cout << "������� ����� ��������: " << endl;
//    cin >> pasport;
//
//}
//
//void Person::show_Person()const
//{
//    cout << "���:  " << name << endl;
//    cout << "�������:  " << family << endl;
//    cout << "���:  " << gender << endl;
//    cout << "�������:  " << age << endl;
//    cout << "����� ��������:  " << pasport << endl;
//}
//
//int main() {
//    system("chcp 1251");
//
//    Person A;
//    cout << "������� ���������� � ���������: " << endl;
//    cout << endl;
//    A.set_Person();
//    cout << "���������� � ���������: " << endl;
//    cout << endl;
//    A.show_Person();
//    cout << endl;
//    Vagon B;
//    cout << "������� ���������� � ������: " << endl;
//    cout << endl;
//    B.set_Vagon();
//    cout << "���������� � ������: " << endl;
//    cout << endl;
//    B.show_Vagon();
//    cout << endl;
//    B.buy_Vagon();
//    cout << endl;
//    Train C;
//    cout << "��������� ������ ���������� � ������:" << endl;
//    C.set2();
//    C.show_Train();
//    cout << endl;
//    cin.get();
//    Vokzal D;
//    cout << "��������� ������ � ��������:" << endl;
//    Vokzal* v = new Vokzal;
//    D.set(v);
//    cout << endl;
//    D.show(v);
//    cin.get();
//    return 0;
//}



#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//        cout << "����� �������: " << on_dest << endl;
//        cout << "����� ����������:  " << destination << endl;
//        cout << "����� �������:  " << departure << endl;
//        cout << "����� ��������:  " << time << endl;
//        cout << "���������� �������:  " << vagon << endl;

//    {
//        cout << "������� ����� �������: ";
//        cin.get();
//        cin >> on_dest;
//        cout << "������� ����� ����������: ";
//        cin.get();
//        cin >> destination;
//
//        cout << "������� ����� �������: ";
//        while (!(cin >> departure) || departure < 1 || departure>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ����� ������� : ";
//        }
//
//        cout << "������� ����� ��������: ";
//        while (!(cin >> time) || time < 1 || time>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ����� � ����: ";
//        }
//        cout << "������� ���������� �������: ";
//        while (!(cin >> vagon) || vagon < 1 || vagon>10000)
//        {
//            cout << "Error\n\n";
//            cout << "������� ���������� �������: ";
//        }
//
//    }

//    string on_dest;//����� ��������
//    string destination; //����� ���������� 
//    int departure;// ����� , �������� 
//    int time;//����� , ��������
//    int vagon;//����� ������� 

class Ticket {
private:
        string on_dest;     //����� ��������
        string destination; //����� ����������

        int time;      //����� �������
        string date;        //����
        int price;       //����

public:
    string get_direction();//+
    int get_time();//+
    string get_date();//+
    int get_price();//+

    void set_direction(string on_dest, string destination);//+
    void set_date(string date);//+
    void set_price(int price);//+

    friend bool operator < (const Ticket& tckt1, const Ticket& tckt2);//+
    friend ostream& operator << (ostream& out, const Ticket& tckt);//+
    friend bool operator == (const Ticket& tckt1, const Ticket& tckt2);//+
};

string Ticket::get_direction() //��������� ���� ������
{ 
    string direction;
    direction.append(this->on_dest);
    direction.append(" - ");
    direction.append(this->destination);
    direction.push_back('\0');
    return direction; 
}

string Ticket::get_date() //��������� ����
{
    return this->date;
}
int Ticket::get_price() //�������� ����
{
    return this->price;
}

int Ticket::get_time()  //��������� ������� �������� ������
{
    return this->time;
}

void Ticket::set_date(string date) // ��������� ���� �����
{ 
    this->date = date; 
}

void Ticket::set_price(int price) // ��������� ���� �����
{ 
    this->price = price; 
}

void Ticket::set_direction(string on_dest, string destination) //���������� ���� �����
{
    this->on_dest = on_dest;
    this->destination = destination;
}

ostream& operator << (ostream& out, const Ticket& tckt) {
    out << tckt.date << endl
        << tckt.on_dest << " - "
        << tckt.destination << endl
        << tckt.time << endl
        << tckt.price << endl
        << endl;
    return out;
}

void show_all_tickets(const vector<Ticket>& tckts) {//����� ���� �������
    for (auto i : tckts) { cout << i; }
}

void buy_ticket(const Ticket& tckt, vector<Ticket>& tckts) { // ������� ������
    tckts.erase(remove_if(tckts.begin(), tckts.end(),[tckt](auto& element) {return element == tckt; }), tckts.end());
}
bool operator < (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.price < tckt2.price; }
bool operator == (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.time == tckt2.time && tckt1.destination == tckt2.destination && tckt1.on_dest == tckt2.on_dest && tckt1.date == tckt2.date && tckt1.price == tckt2.price; }





int main() {
    std::vector<Ticket> tickets(5);
    tickets[0].set_direction("Canada","USA");
    tickets[0].set_date("10.09.2020");
    tickets[0].set_price(235);

    tickets[1].set_direction("USA","England");
    tickets[1].set_date("13.09.2020");
    tickets[1].set_price(140);

    tickets[2].set_direction("England", "Canada");
    tickets[2].set_date("16.09.2020");
    tickets[2].set_price(120);

    tickets[3].set_direction("Italy", "Canada");
    tickets[3].set_date("20.09.2020");
    tickets[3].set_price(98);

    tickets[4].set_direction("New Zeland", "USA");
    tickets[4].set_date("25.09.2020");
    tickets[4].set_price(480);
    show_all_tickets(tickets);
    cout << "===================================================" << endl; 
    buy_ticket(tickets[0], tickets);
    sort(tickets.begin(), tickets.end());
  
    show_all_tickets(tickets);
}