//#include <iostream>
//#include <cstdlib>
//#include <math.h>
//#include <stdlib.h>
//#include <iomanip>
//#include <string>
//using namespace std;
//class Vokzal
//{
//    int length;//колво перронов
//    string peronu;// название перрона
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
//    string on_dest;//пункт отправки
//    string destination; //пункт назначение 
//    int departure;// выезд , отправка 
//    int time;//время , прибытия
//    int vagon;//колво вагонов 
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
//    string tip;//тип вагона 
//    int mest;//колво мест 
//    int new_mest;//колво свободных мест
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
//    char name[20];//имя пассажира
//    char family[20]; //фамилия пассажира
//    char gender[20];//пол
//    int age;//возраст
//    int pasport;//номер паспорта 
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
//        cout << "Введите пункт отбытия: ";
//        cin.get();
//        cin >> on_dest;
//        cout << "Введите пункт назначения: ";
//        cin.get();
//        cin >> destination;
//
//        cout << "Введите время отбытия: ";
//        while (!(cin >> departure) || departure < 1 || departure>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите время отбытия : ";
//        }
//
//        cout << "Введите время прибытия: ";
//        while (!(cin >> time) || time < 1 || time>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите время в пути: ";
//        }
//        cout << "Введите количество вагонов: ";
//        while (!(cin >> vagon) || vagon < 1 || vagon>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите количество вагонов: ";
//        }
//
//    }
//}
//void Train::show_Train()const
//{
//
//    {
//        cout << "Пункт отбытия: " << on_dest << endl;
//        cout << "Пункт назначения:  " << destination << endl;
//        cout << "Время отбытия:  " << departure << endl;
//        cout << "Время прибытия:  " << time << endl;
//        cout << "Количество вагонов:  " << vagon << endl;
//
//    }
//}
//
//void Vokzal::set(Vokzal v[])
//{
//    cout << "Введите количество перронов:" << endl;
//    cin >> length;
//    for (int i = 0; i < length; i++)
//    {
//        cout << "Введите название перрона : " << endl;
//        cin >> v[i].peronu;
//    }
//}
//void Vokzal::show(Vokzal v[])
//{
//    for (int i = 0; i < length; i++)
//    {
//        cout << i + 1 << ":\n";
//        cout << "Название перрона: " << v[i].peronu << endl;
//    }
//}
//void Vagon::set_Vagon()
//{
//    cout << "тип вагона :" << endl;
//    cin >> tip;
//    cout << "количество мест :" << endl;
//    cin >> mest;
//    cout << "количество свободных мест :" << endl;
//    cin >> new_mest;
//
//
//}
//void Vagon::show_Vagon()const
//{
//    cout << "Тип вагона : " << tip << endl;
//    cout << "Количество мест : " << mest << endl;
//    cout << "Количество свободных мест: " << new_mest << endl;
//
//}
//void Vagon::buy_Vagon()
//{
//    int n;
//    int ticket;
//    cout << "Введите кол-во покупаемых билетов" << endl;
//    cin >> ticket;
//    for (int i = 0; i < ticket; i++)
//    {
//        n = new_mest - ticket;
//    }
//    cout << "Колво оставшихся свободных мест" << n << endl;
//}
//
//void Person::set_Person()
//{
//    cout << "введите имя пассажира: " << endl;
//    cin >> name;
//    cout << "введите фамилию пассажира: " << endl;
//    cin >> family;
//    cout << "введите пол пассажира: " << endl;
//    cin >> gender;
//    cout << "введите возраст пассажира: " << endl;
//    cin >> age;
//    cout << "введите номер паспорта: " << endl;
//    cin >> pasport;
//
//}
//
//void Person::show_Person()const
//{
//    cout << "Имя:  " << name << endl;
//    cout << "Фамилия:  " << family << endl;
//    cout << "Пол:  " << gender << endl;
//    cout << "Возраст:  " << age << endl;
//    cout << "Номер паспорта:  " << pasport << endl;
//}
//
//int main() {
//    system("chcp 1251");
//
//    Person A;
//    cout << "Введите информацию о пассажире: " << endl;
//    cout << endl;
//    A.set_Person();
//    cout << "Информация о пассажире: " << endl;
//    cout << endl;
//    A.show_Person();
//    cout << endl;
//    Vagon B;
//    cout << "Введите информацию о вагоне: " << endl;
//    cout << endl;
//    B.set_Vagon();
//    cout << "Информация о вагоне: " << endl;
//    cout << endl;
//    B.show_Vagon();
//    cout << endl;
//    B.buy_Vagon();
//    cout << endl;
//    Train C;
//    cout << "Заполните список сведениями о поезде:" << endl;
//    C.set2();
//    C.show_Train();
//    cout << endl;
//    cin.get();
//    Vokzal D;
//    cout << "Заполните данные о перронах:" << endl;
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

//        cout << "Пункт отбытия: " << on_dest << endl;
//        cout << "Пункт назначения:  " << destination << endl;
//        cout << "Время отбытия:  " << departure << endl;
//        cout << "Время прибытия:  " << time << endl;
//        cout << "Количество вагонов:  " << vagon << endl;

//    {
//        cout << "Введите пункт отбытия: ";
//        cin.get();
//        cin >> on_dest;
//        cout << "Введите пункт назначения: ";
//        cin.get();
//        cin >> destination;
//
//        cout << "Введите время отбытия: ";
//        while (!(cin >> departure) || departure < 1 || departure>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите время отбытия : ";
//        }
//
//        cout << "Введите время прибытия: ";
//        while (!(cin >> time) || time < 1 || time>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите время в пути: ";
//        }
//        cout << "Введите количество вагонов: ";
//        while (!(cin >> vagon) || vagon < 1 || vagon>10000)
//        {
//            cout << "Error\n\n";
//            cout << "Введите количество вагонов: ";
//        }
//
//    }

//    string on_dest;//пункт отправки
//    string destination; //пункт назначение 
//    int departure;// выезд , отправка 
//    int time;//время , прибытия
//    int vagon;//колво вагонов 

class Ticket {
private:
        string on_dest;     //пункт отправки
        string destination; //пункт назначение

        int time;      //время отбытия
        string date;        //дата
        int price;       //цена

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

string Ticket::get_direction() //получение пути поезда
{ 
    string direction;
    direction.append(this->on_dest);
    direction.append(" - ");
    direction.append(this->destination);
    direction.push_back('\0');
    return direction; 
}

string Ticket::get_date() //получение даты
{
    return this->date;
}
int Ticket::get_price() //получеие цены
{
    return this->price;
}

int Ticket::get_time()  //получение времени отправки поезда
{
    return this->time;
}

void Ticket::set_date(string date) // получение даты рейса
{ 
    this->date = date; 
}

void Ticket::set_price(int price) // получение цены рейса
{ 
    this->price = price; 
}

void Ticket::set_direction(string on_dest, string destination) //сохранение пути рейса
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

void show_all_tickets(const vector<Ticket>& tckts) {//вывод всех билетов
    for (auto i : tckts) { cout << i; }
}

void buy_ticket(const Ticket& tckt, vector<Ticket>& tckts) { // покупка билета
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