

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
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
        string on_dest="Nan";     //����� ��������
        string destination = "Nan"; //����� ����������

        string time = "Nan";      //����� �������
        string date = "Nan";        //����
        double price=-1;       //����

public:

    void set_direction(string on_dest, string destination) //���������� ���� �����
    {
        this->on_dest = on_dest;
        this->destination = destination;
    }
    void set_price(int price){ this->price = price;}
    void set_date(string date) { this->date = date; }
    void set_duration(string time) { this->time = time; }

    double get_price() { return this->price;}
    string get_date() { return this->date;}
    string get_time() { return this->time;}
    string get_direction() //��������� ���� ������
    {
        string direction;
        direction.append(this->on_dest);
        direction.append(" - ");
        direction.append(this->destination);
        direction.push_back('\0');
        return direction;
    }
    string get_destination() { return destination; }
    string get_start() { return on_dest; }

    friend bool operator < (const Ticket& tckt1, const Ticket& tckt2);//+
    friend ostream& operator << (ostream& out, const Ticket& tckt);//+
    friend bool operator == (const Ticket& tckt1, const Ticket& tckt2);//+
};


ostream& operator << (ostream& out, const Ticket& tckt) {
    out << "���� �����������(����.�����.���): "<< tckt.date << endl
        << "����� �������(���.����.������): " << tckt.time << endl
        << "������� �����������: " << tckt.on_dest << endl
        << "������� ��������: " << tckt.destination << endl
        << "��������� �������: " << tckt.price << endl
        << endl;
    return out;
}
bool operator < (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.price < tckt2.price; }
bool operator == (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.time == tckt2.time && tckt1.destination == tckt2.destination && tckt1.on_dest == tckt2.on_dest && tckt1.date == tckt2.date && tckt1.price == tckt2.price; }

class DataBase {
    string fileName;
    vector<Ticket> currentTickets;

public:

    DataBase(string fileName) {
        this->fileName = fileName;
    }

    void setTickets(vector<Ticket> Tickets) {this->currentTickets = Tickets; }
    vector<Ticket> getTickets() { return currentTickets; }

    void createNew() {ofstream oFile(fileName);}

    bool add_Ticket(Ticket ticket) {
        for (auto i : currentTickets) { if (i == ticket) return false; }
        currentTickets.push_back(ticket);
        return true;
    }

    bool delete_Ticket(Ticket ticket) {
        bool deleted = false;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i) == ticket) {
                deleted = true;
            }
            if (deleted == true) {
                if (i == currentTickets.size() - 1)break;
                Ticket temp = currentTickets.at(i + 1);
                currentTickets.at(i + 1) = currentTickets.at(i);
                currentTickets.at(i) = temp;
            }
        }
        if (deleted) {
            currentTickets.resize(currentTickets.size() - 1);
            return true;
        }
        return false;
    }

    void getFromFile() {}

    void setToFile() {}

    void show_all_tickets() {
        for (auto i : currentTickets) { cout << i; }
    }

    void dataSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_date() > currentTickets.at(j + 1).get_date()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }
    void timeSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_time() > currentTickets.at(j + 1).get_time()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }
    void priceSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_price() > currentTickets.at(j + 1).get_price()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }
    void destinationSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_destination() > currentTickets.at(j + 1).get_destination()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }
    void startSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_start() > currentTickets.at(j + 1).get_start()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }

};




int main() {
    setlocale(LC_ALL, "rus");
    DataBase f("1");
    vector<Ticket> tickets(5);
    tickets[0].set_direction("Canada","USA");
    tickets[0].set_date("16.09.2020");
    tickets[0].set_duration("00.02.10");
    tickets[0].set_price(235);

    tickets[1].set_direction("USA","England");
    tickets[1].set_date("13.09.2020");
    tickets[1].set_duration("10.22.10");
    tickets[1].set_price(140);

    tickets[2].set_direction("England", "Canada");
    tickets[2].set_date("16.09.2020");
    tickets[2].set_duration("01.00.40");
    tickets[2].set_price(120);

    tickets[3].set_direction("Italy", "Canada");
    tickets[3].set_date("20.09.2020");
    tickets[0].set_duration("23.02.10");
    tickets[3].set_price(98);

    tickets[4].set_direction("New Zeland", "USA");
    tickets[4].set_date("25.09.2020");
    tickets[4].set_duration("04.04.04");
    tickets[4].set_price(480);
    //show_all_tickets(tickets);
    //cout << "===================================================" << endl; 
    //buy_ticket(tickets[0], tickets);
    //sort(tickets.begin(), tickets.end());

    f.setTickets(tickets);
    //f.delete_Ticket(tickets[4]);
    f.show_all_tickets();
    f.dataSort();
    cout << "===================================================" << endl;
    f.show_all_tickets();
    return 0;
}