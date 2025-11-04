#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const string filename = "student.txt";
    // Write initial records (overwrite)
    {
        ofstream ofs(filename);
        ofs << "11,Alice,85\n";
        ofs << "12,Bob,78\n";
    }
    // Read and display
    cout << "Contents after initial write:\n";
    {
        ifstream ifs(filename);
        string line;
        while (getline(ifs, line)) cout << line << '\n';
    }
    // Append a new record
    {
        ofstream ofs(filename, ios::app);
        ofs << "13,Charlie,92\n";
    }
    cout << "\nContents after append:\n";
    {
        ifstream ifs(filename);
        string line;
        while (getline(ifs, line)) cout << line << '\n';
    }
    return 0;
}
