#include <iostream>
using namespace std;
int main ()
{
  int N(100);
  while (N != 0){
    //cin >> N;
    if (N != 0){
      double a=1, b=1, c=1, max=370;
      bool solved = false; 
      while (a + b + c + b < 4000){
        double acubed = (a*a*a);
        double bcubed = (b*b*b);
        double ccubed = (c*c*c);
        double result = (acubed+ccubed)/bcubed;
        if (result == N){
          solved = true;
          break;
        }   
        else{
          ++a;
          if (a > max){
            ++c;
            a = c;
            if (c > max){
              ++b;
              a = b;
              c = b;
              if (b > max){
                max += 500;
              }
            }
          }
        }
      }
      if (solved){
        cout << "(" << a << "/" << b << ")^3 + "
             << "(" << c << "/" << b << ")^3 = " << N << endl;
      }
      else{
        cout << "No value." << endl;
      }
    }
    N--;
  }
  return 0;
}
