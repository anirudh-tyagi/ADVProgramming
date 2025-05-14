#include <iostream>
using namespace std;
class Distance_fi{
    private:
    int feet; 
    int inch;
    public:
    static int count;
    void set_value( int feet, int inch){
        this -> feet=feet;
        this -> inch=inch;
        count++;

    }
    void get_values(void){
        cout << "feet -> " << feet << ", inch -> " << inch << ", count -> " << count << endl;

            }
            static void count_access (void){
                cout<<"the value of count is"<< count<<endl;
            }
};
            int Distance_fi :: count=0;
            int main(){
                Distance_fi d1,d2,sum;
                d1.set_value(4,5);
                d1.get_values();
                d2.set_value(5,5);
                d2.get_values();
                sum.set_value
                Distance_fi :: count_access();
                return 0;
            }