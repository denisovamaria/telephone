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
    long long int **keybord = new long long int *[n];
    for (int i = 0; i < n; ++i) {
        keybord[i] = new long long int[m];
    }
    keybord[0][0] = freq[0];
    for (int i = 1; i < m; i++) {
        keybord[0][i] = book[0][i];
    }
    for (int i = 1; i < n; i++) {
        keybord[i][i] = keybord[i - 1][i - 1] + freq[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            unsigned long long int sum = keybord[0][m - 1];
            keybord[i][j] = sum;
            for (int s = i - 1; s < m - 1; s++) {
                sum = keybord[i - 1][s] + book[s + 1][j];
                if (sum < keybord[i][j])
                    keybord[i][j] = sum;
            }
        }
    }
    out << keybord[n - 1][m - 1];
    return 0;
}
