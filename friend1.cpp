#include <iostream>
using namespace std;
class matrix{
    int arr [2][2];
    public:
    matrix(int a , int b, int c, int d){
        this->arr[0][0]=a;
        this->arr[0][1]=b;
        this->arr[1][0]=c;
        this->arr[1][1]=d;

    }
    friend vector product (matrix * m, vector *v);
    
};
class vector {
    int arr1[2];
    public:
      vector (int a, int b){
        this->arr1[0]=a;
        this->arr1[1]=b;

      }
      void show-data(void){
        cout<<" a and b are :"<<arr1[0]<<"and"<<arr1[1]<<endl;

        
      }
      friend vector product (matrix* m, vector*v);
};
vector product (matrix* m, vector*v){
    vector t(0,0);
    t.arr1[0]=m->arr[0][1]*vv->arr1[0][1]*v->arr1[1];
    t.arr1[1]=m->arr[1][0]*vv->arr1[1][1]*v->arr1[1];
    return t;
}
int main (){
    matrix m1(1,2,3,4);
    vector v1(1,2)v4(0,0);
    v4 = product(&m1, &v1);
    v4.show_data();
    return 0;
}