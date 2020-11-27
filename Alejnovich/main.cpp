

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