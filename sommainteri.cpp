#include <iostream>
#include <fstream>

using namespace std;

int main () {

fstream ingresso, uscita;
int N, M;

ingresso.open("input.txt", ios::in);
uscita.open("output.txt", ios::out);

ingresso >> N >> M;
uscita << N+M << "\n";

ingresso.close();
uscita.close();
return 0;

}