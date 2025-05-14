#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void logAttendance(int userId) {
    ofstream file("attendance.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    file << "User " << userId << " marked present at " << dt;
    file.close();
}
