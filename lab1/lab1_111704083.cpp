#include<iostream>

using namespace std;
class FUNC{
   public:
       int v11,v12,v13,v21,v22,v23;
       void input_p(){
            cin >> v11 >> v12 >> v13;
       }
       void input_other(){
            cin >> v11 >> v12 >> v13 >> v21 >> v22 >> v23;
       }
       void print(){
            cout << "[" << v11 << ","<< v12 <<","<< v13 << "]" << endl;
       }
       void add_vector(){
            cout << "[" << v11 + v21 <<","<< v12 + v22 << ","<< v13 + v23 << "]" << endl;
       }
       void dot_product(){
            cout << v11 * v21 + v12 * v22 + v13 * v23 << endl;
       }
       void cross_product(){
         cout << "[" << v12 * v23 - v13 * v22 << "," << v13 * v21 - v11 * v23 << "," << v11 * v22 - v12 * v21 << "]"<< endl;
       }
};

int main(){
   char a;
   int n,i = 0;
   cin >> n;
   while(i < n){
     cin >> a;
     FUNC func;
     switch(a){
         case 'p':
             func.input_p();
             func.print();
             break;
         case '+':
            func.input_other();
            func.add_vector();
            break;
         case '*':
             func.input_other();
             func.dot_product();
             break;
         case 'x':
            func.input_other();
            func.cross_product();
            break;
     }
     i++;
   }
   return 0;
}
