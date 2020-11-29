

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <string>
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
        string on_dest="Nan";     //пункт отправки
        string destination = "Nan"; //пункт назначение

        string time = "Nan";      //время отбытия
        string date = "Nan";        //дата
        double price=-1;       //цена

public:

    void set_direction(string on_dest, string destination) //сохранение пути рейса
    {
        this->on_dest = on_dest;
        this->destination = destination;
    }
    void set_destination(string destination) { this->destination = destination; }
    void set_price(int price){ this->price = price;}
    void set_date(string date) { this->date = date; }
    void set_time(string time) { this->time = time; }
    void set_start(string start) { this->on_dest = start; }

    double get_price() { return this->price;}
    string get_date() { return this->date;}
    string get_time() { return this->time;}
    string get_direction() //получение пути поезда
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
    out << "Дата отправления(день.месяц.год): "<< tckt.date << endl
        << "Время поездки(дни.часы.минуты): " << tckt.time << endl
        << "Станция отправления: " << tckt.on_dest << endl
        << "Станция прибытия: " << tckt.destination << endl
        << "Стоимость поездки: " << tckt.price << endl
        << endl;
    return out;
}
bool operator < (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.price < tckt2.price; }
bool operator == (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.time == tckt2.time && tckt1.destination == tckt2.destination && tckt1.on_dest == tckt2.on_dest && tckt1.date == tckt2.date && tckt1.price == tckt2.price; }

class DataBase {
    string fileName;
    vector<Ticket> currentTickets;

    string deleteSpaises(string msg) {
        for (int i = 0; i < msg.size(); i++) 
            if (msg.at(i) == ' ')msg.at(i) = '~';
        return msg;
    }
    string addSpaises(string msg) {
        for (int i = 0; i < msg.size(); i++)
            if (msg.at(i) == '~')msg.at(i) = ' ';
        return msg;
    }

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

    void getFromFile() {
        ifstream fout(fileName);
        while (1) {
            Ticket temp;
            for (int i = 0; i < 5; i++) {
                string s;
                fout >> s;
                if (fout.eof())break;
                switch (i) {
                    case 0: temp.set_start(addSpaises(s)); break;
                    case 1: temp.set_destination(addSpaises(s)); break;
                    case 2: temp.set_time(s); break;
                    case 3: temp.set_date(s); break;
                    case 4: temp.set_price(stod(s)); break;
                    default:break;
                }
            }
            if (fout.eof())break;
            add_Ticket(temp);
        }
        fout.close();
    }

    void loadToFile() {
        ofstream fin(fileName);
        for (auto i : currentTickets) {
            fin << deleteSpaises(i.get_start()) << ' ';
            fin << deleteSpaises(i.get_destination()) << ' ';
            fin << i.get_time() << ' ';
            fin << i.get_date() << ' ';
            fin << to_string(i.get_price()) << ' ';
            fin << '\n';
        }
        fin.close();
    }

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
    DataBase f("DataBase.txt");
    f.createNew();
    vector<Ticket> tickets(5);
    tickets[0].set_direction("Canada","USA");
    tickets[0].set_date("16.09.2020");
    tickets[0].set_time("00.02.10");
    tickets[0].set_price(235);

    tickets[1].set_direction("USA","England");
    tickets[1].set_date("13.09.2020");
    tickets[1].set_time("10.22.10");
    tickets[1].set_price(140);

    tickets[2].set_direction("England", "Canada");
    tickets[2].set_date("16.09.2020");
    tickets[2].set_time("01.00.40");
    tickets[2].set_price(120);

    tickets[3].set_direction("Italy", "Canada");
    tickets[3].set_date("20.09.2020");
    tickets[0].set_time("23.02.10");
    tickets[3].set_price(98);

    tickets[4].set_direction("New Zeland", "USA");
    tickets[4].set_date("25.09.2020");
    tickets[4].set_time("04.04.04");
    tickets[4].set_price(480);

    f.setTickets(tickets);
    f.loadToFile();
    f.getFromFile();
    cout << "===================================================\n";
    f.show_all_tickets();
    return 0;
}