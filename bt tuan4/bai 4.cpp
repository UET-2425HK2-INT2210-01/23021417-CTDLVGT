#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct SinhVien {
    int ID;
    string ten;
    string lop;
};

class QuanLySinhVien {
private:
    vector<SinhVien> danhSach;

public:
    void insert(int ID, string ten, string lop) {
        for (auto &sv : danhSach) {
            if (sv.ID == ID) {
                sv.ten = ten;
                sv.lop = lop;
                return;
            }
        }
        danhSach.push_back({ID, ten, lop});
    }

    void deleteSV(int ID) {
        for (size_t i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].ID == ID) {
                danhSach.erase(danhSach.begin() + i);
                return;
            }
        }
    }

    string infor(int ID) {
        for (const auto &sv : danhSach) {
            if (sv.ID == ID) {
                return sv.ten + "," + sv.lop;
            }
        }
        return "NA,NA";
    }
};

int main() {
    QuanLySinhVien qlsv;
    string command;

    while (getline(cin, command)) {
        if (command == "Exit") break;

        if (command.find("Insert") == 0) {
            int ID;
            string ten, lop;
            command = command.substr(7, command.size() - 8); // Loại bỏ "Insert(" và ")"
            stringstream ss(command);
            getline(ss, command, ',');
            ID = stoi(command);
            getline(ss, ten, ',');
            getline(ss, lop, ',');
            qlsv.insert(ID, ten, lop);
        }
        else if (command.find("Delete") == 0) {
            int ID;
            sscanf(command.c_str(), "Delete(%d)", &ID);
            qlsv.deleteSV(ID);
        }
        else if (command.find("Infor") == 0) {
            int ID;
            sscanf(command.c_str(), "Infor(%d)", &ID);
            cout << qlsv.infor(ID) << endl;
        }
    }

    return 0;
}
