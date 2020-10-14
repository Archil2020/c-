#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

template <typename T>

class List{
    private:
        T* arr;
        int count;
        T* store;
    public:
        List(){
            count = 0;
        }
        void add(T element){
            if(count==0){
                count++;
                arr = new T[count];
                arr[count-1] = element;
            }
            else{
                store = new T[count];
                for(int i = 0;i<count;i++){
                    store[i] = arr[i];
                }
                delete [] arr;
                count++;
                arr  = new T[count];
                for(int i = 0;i<count-1;i++){
                    arr[i] = store[i];
                }
                arr[count-1] = element;
                delete [] store;
            }
        }

        void printAll(){
            for(int i = 0;i<count;i++){
                cout<<i<<"----"<<arr[i]<<endl;
            }
        }
        int length(){
            return count;
        }

        T *element(int index){
            return arr;
        }

        ~List(){
            delete [] arr;
        }
};

int main(){
    srand(time(0));
    List<char> l;
    for(int i=0;i<20;i++){
        l.add(char(rand() % 100));
    }

    char* arr = l.element(2);
    cout<<l.element(2)<<endl;

    l.printAll();
    return 0;
}