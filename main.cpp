#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in >> n;
    int m;
    in >> m;
    int *freq = new int[m];
    for (int i = 0; i < m; i++) {
        in >> freq[i];
    }
    int ans = 0;
    if (n > m) {
        for(int i = 0; i < m; i ++){
            ans = ans + freq[i];
        }
        out << ans;
        return 0;
    }
    long long int **book = new long long int *[m];
    for (int i = 0; i < m; i++) {
        book[i] = new long long int[m];
    }
    for (int i = 0; i < m; i++) {
        book[i][i] = freq[i];
    }
    for (int i = 0; i < m; i++) {
        int f = 2;
        for (int j = i + 1; j < m; j++) {
            book[i][j] = book[i][j - 1] + f * freq[j];
            f++;
        }
    }

}
