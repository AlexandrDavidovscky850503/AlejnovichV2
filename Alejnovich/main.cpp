#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <string>
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
        int places = -1;
 
public:

    void set_direction(string on_dest, string destination) //���������� ���� �����
    {
        this->on_dest = on_dest;
        this->destination = destination;
    }
    void set_destination(string destination) { this->destination = destination; }
    void set_price(double price){ this->price = price;}
    void set_date(string date) { this->date = date; }
    void set_time(string time) { this->time = time; }
    void set_start(string start) { this->on_dest = start; }
    void set_places(int number) { this->places = number; }

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
    int get_places() { return places; }

    bool byTicket() {
        places--;
        if (places <= 0)return false;
        else return true;
    }

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
        << "�-�� ��������� ����: " << tckt.places << endl
        << endl;
    return out;
}
bool operator < (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.price < tckt2.price; }
bool operator == (const Ticket& tckt1, const Ticket& tckt2) { return tckt1.time == tckt2.time && tckt1.destination == tckt2.destination 
&& tckt1.on_dest == tckt2.on_dest && tckt1.date == tckt2.date && tckt1.price == tckt2.price && tckt1.places == tckt2.places; }

class DataBase {
    string fileName;
    vector<Ticket> currentTickets;
    vector<Ticket> tempTickets;

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
            for (int i = 0; i < 6; i++) {
                string s;
                fout >> s;
                if (fout.eof())break;
                switch (i) {
                    case 0: temp.set_start(addSpaises(s)); break;
                    case 1: temp.set_destination(addSpaises(s)); break;
                    case 2: temp.set_time(s); break;
                    case 3: temp.set_date(s); break;
                    case 4: temp.set_price(stod(s)); break;
                    case 5: temp.set_places(stoi(s)); break;
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
            fin << to_string(i.get_places()) << ' ';
            fin << '\n';
        }
        fin.close();
    }

    void show_all_tickets() {
        for (auto i : currentTickets) { cout << i; }
    }

    // ����������
    void dateSort() {
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
    void placesSort() {
        int size = currentTickets.size();
        bool done;
        for (int i = 1; i < size; i++) {
            done = true;
            for (int j = 0; j < size - i; j++) {
                if (currentTickets.at(j).get_places() > currentTickets.at(j + 1).get_places()) {
                    Ticket temp = currentTickets.at(j);
                    currentTickets.at(j) = currentTickets.at(j + 1);
                    currentTickets.at(j + 1) = temp;
                    done = false;
                }
            }
            if (done)return;
        }
    }

    // ��������� ������ ������� � ���������� ����������
    vector<int> sameDate(string data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_date() == data)answer.push_back(i);
        }
        return answer;
    }
    vector<int> sameTime(string data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_time() == data)answer.push_back(i);
        }
        return answer;
    }
    vector<int> samePlaces(int data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_places() == data)answer.push_back(i);
        }
        return answer;
    }
    vector<int> sameDestination(string data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_destination() == data)answer.push_back(i);
        }
        return answer;
    }
    vector<int> samePrice(double data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_price() == data)answer.push_back(i);
        }
        return answer;
    }
    vector<int> sameStart(string data) {
        vector<int> answer;
        for (int i = 0; i < currentTickets.size(); i++) {
            if (currentTickets.at(i).get_start() == data)answer.push_back(i);
        }
        return answer;
    }

    void createNewTicket() {
        clone();
        Ticket temp;

        while (1) {
            string s;
            cout << "������� ����� �����������" << endl;
            cin >> s;
            if (s.empty()) cout << "����� ������ ��� ������" << endl;
            else {
                temp.set_start(s);
                break;
            }
        }
        
        while (1) {
            string s;
            cout << "������� ����� ��������" << endl;
            cin >> s;
            if (s.empty()) cout << "����� ������ ��� ������" << endl;
            else {
                temp.set_destination(s);
                break;
            }
        }

        while (1) {
            string s;
            cout << "������� ����� ������� � ������� ��.��.��" << endl;
            cin >> s;
            if (s.size() != 8)cout << "������������ ������ �����" << endl;
            else {
                temp.set_time(s);
                break;
            }
            
        }
        while (1) {
            string s;
            cout << "������� ���� �����������  � ������� ��.��.����" << endl;
            cin >> s;
            if (s.size() != 10)cout << "������������ ������ �����" << endl;
            else {
                temp.set_date(s);
                break;
            }

        }
        while (1) {
            string s;
            cout << "������� ���� �������" << endl;
            cin >> s;
            bool ok=true;
            for (int i = 0; i < s.size(); i++) {
                if ((s.at(i) < '0' || s.at(i) > '9') && s.at(i) != '.') {
                    ok = false;
                    break;
                }
            }
            if (!ok) { cout << "������������ ������ �����" << endl;  ok = true; }
            else {
                temp.set_price(stod(s));
                break;
            }

        }
        while (1) {
            string s;
            cout << "������� �-�� ��������� ����" << endl;
            cin >> s;
            bool ok = true;
            for (int i = 0; i < s.size(); i++) {
                if ((s.at(i) < '0' || s.at(i) > '9')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) { cout << "������������ ������ �����" << endl;  ok = true; }
            else {
                temp.set_places(stoi(s));
                break;
            }
        }
        add_Ticket(temp);
    }

    void changeTicket(int ticketNumber) {
        clone();
        char number = '0';
        while (1) {
            cout << "�������� ���� ��� ���������:" << endl;
            cout << "1) ����� �����������" << endl;
            cout << "2) ����� ��������" << endl;
            cout << "3) ����� �������" << endl;
            cout << "4) ���� �������" << endl;
            cout << "5) ���� �������" << endl;
            cout << "6) �-�� �������� ����" << endl;

            cin >> number;
            if (number < '1' || number>'6')cout << "������������ ������ �����" << endl;
            else break;
        }

        switch (number)
        {
        case '1':
            while (1) {
                string s;
                cout << "������� ����� �����������" << endl;
                cin >> s;
                if (s.empty()) cout << "����� ������ ��� ������" << endl;
                else {
                    currentTickets.at(ticketNumber).set_start(s);
                    break;
                }
            }
            break;
        case '2':
            while (1) {
                string s;
                cout << "������� ����� ��������" << endl;
                cin >> s;
                if (s.empty()) cout << "����� ������ ��� ������" << endl;
                else {
                    currentTickets.at(ticketNumber).set_destination(s);
                    break;
                }
            }
            break;
        case '3':
            while (1) {
                string s;
                cout << "������� ����� ������� � ������� ��.��.��" << endl;
                cin >> s;
                if (s.size() != 8)cout << "������������ ������ �����" << endl;
                else {
                    currentTickets.at(ticketNumber).set_time(s);
                    break;
                }

            }
            break;
        case '4':
            while (1) {
                string s;
                cout << "������� ���� �����������  � ������� ��.��.����" << endl;
                cin >> s;
                if (s.size() != 10)cout << "������������ ������ �����" << endl;
                else {
                    currentTickets.at(ticketNumber).set_date(s);
                    break;
                }

            }
            break;
        case '5':
            while (1) {
                string s;
                cout << "������� ���� �������" << endl;
                cin >> s;
                bool ok = true;
                for (int i = 0; i < s.size(); i++) {
                    if ((s.at(i) < '0' || s.at(i) > '9') && s.at(i) != '.') {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { cout << "������������ ������ �����" << endl;  ok = true; }
                else {
                    currentTickets.at(ticketNumber).set_price(stod(s));
                    break;
                }

            }
            break;
        case '6':
            while (1) {
                string s;
                cout << "������� �-�� ��������� ����" << endl;
                cin >> s;
                bool ok = true;
                for (int i = 0; i < s.size(); i++) {
                    if ((s.at(i) < '0' || s.at(i) > '9')) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) { cout << "������������ ������ �����" << endl;  ok = true; }
                else {
                    currentTickets.at(ticketNumber).set_places(stoi(s));
                    break;
                }
            }
            break;
        default: break;
        }
    }

    void byTicket(int number) {
        clone();
        if (!currentTickets.at(number).byTicket()) delete_Ticket(currentTickets.at(number));
    }

    //��� ������ ���������� ��������
    void deny() {currentTickets = tempTickets;}
    void clone() {tempTickets = currentTickets;}
};




int main() {
    setlocale(LC_ALL, "rus");
    DataBase f("DataBase.txt");
   // f.createNew();
    vector<Ticket> tickets(5);
    tickets[0].set_direction("Canada","USA");
    tickets[0].set_date("16.09.2020");
    tickets[0].set_time("00.02.10");
    tickets[0].set_price(235.2);
    tickets[0].set_places(21);

    tickets[1].set_direction("USA","England");
    tickets[1].set_date("13.09.2020");
    tickets[1].set_time("10.22.10");
    tickets[1].set_price(140);
    tickets[1].set_places(1);

    tickets[2].set_direction("England", "Canada");
    tickets[2].set_date("16.09.2020");
    tickets[2].set_time("01.00.40");
    tickets[2].set_price(120);
    tickets[2].set_places(3);

    tickets[3].set_direction("Italy", "Canada");
    tickets[3].set_date("20.09.2020");
    tickets[3].set_time("23.02.10");
    tickets[3].set_price(98);
    tickets[3].set_places(41);

    tickets[4].set_direction("New Zeland", "USA");
    tickets[4].set_date("25.09.2020");
    tickets[4].set_time("04.04.04");
    tickets[4].set_price(480);
    tickets[4].set_places(4);

    f.setTickets(tickets);
   // f.loadToFile();
    //f.getFromFile();
    cout << "===================================================\n";
    f.show_all_tickets();
    f.byTicket(1);
    cout << "===================================================\n";
    f.show_all_tickets();
    cout << "===================================================\n";
    f.deny();
    f.show_all_tickets();
    return 0;
}