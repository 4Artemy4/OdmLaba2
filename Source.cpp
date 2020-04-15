#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    vector<int> A, B;
    setlocale(LC_ALL, "Russian");
    int razA, razB;
    int choice = 0, temp = 0;
    cout << "Введите 1, если хотите задать множество поэлеметно, или 2, если хотите задать множество выражением" << endl; 
    cin >> choice; // 4.1.1

    switch (choice) {
    case 1: { // 4.1.2
        cout << "введите размерность множества A" << endl; 
        cin >> razA; // 4.1.2.1
        cout << "введите размерность множества B" << endl;
        cin >> razB; // 4.1.2.2
        A = vector<int>(razA); // 4.1.2.3
        B = vector<int>(razB); // 4.1.2.4
        for (int i = 0; i < razA; i++) {// 4.1.2.5
            cin >> A[i];
        }
        for (int j = 0; j < razB; ++j) {//4.1.2.6
            cin >> B[j];
        }
    } break;
    case 2: { // 4.1.3
        int k, d, h = 1;
        cin >> k; // 4.1.3.1
        cin >> d; // 4.1.3.2
        cin >> h; // 4.1.3.3
        int s = 1; // 4.1.3.4
        A = vector<int>(h - d + 1); // 4.1.3.5
        razA = h - d + 1; // 4.1.3.6
        vector<int> coefA = vector<int>(k); // 4.1.3.7
        vector<int> powA = vector<int>(k); // 4.1.3.9

        int j = 1; // 4.1.3.11
        int res = 0; // 4.1.3.12
        for (; d <= h;) { // 4.1.3.13
            for (; j <= 
                coefA.size();) { // !!! размер вектора или k использовать для показателя размера множества коэфф 4.1.3.13.1
                res = res + (coefA[j - 1] * pow(d, powA[j - 1]));
                j = j + 1;
            }
            A[d] = res; // 4.1.3.13.2.1
            d = d + s; // 4.1.3.13.2.2
        }

        cin >> k; // 4.1.3.15
        cin >> d; // 4.1.3.16
        cin >> h; // 4.1.3.17
        s = 1; // 4.1.3.18
        B = vector<int>(h - d + 1); // 4.1.3.19
        razB = h - d + 1; // 4.1.3.20
        vector<int> coefB = vector<int>(k); // 4.1.3.21
        vector<int> powB = vector<int>(k); // 4.1.3.23

        j = 1; // 4.1.3.25
        res = 0; // 4.1.3.26
        for (; d <= h;) { 
            for (; j <=
                coefB.size();) { //!!! размер вектора или k использовать для показателя размера множества коэфф 4.1.3.27.1
                res = res + (coefB[j - 1] * pow(d, powB[j - 1]));
                j = j + 1;
            }
            B[d] = res; // 4.1.3.27.2.1
            d = d + s; // 4.1.3.27.2.2
        }
    }
    }
    cout << "Выберите операцию: 1-объединение, 2-пересечение, 3-разность, 4-дополнение, 5-симметр. разность, 6-декартово произвед." << endl;
    cin >> choice; // 4.2.1
    switch (choice) {
    case 1: { // 4.3
        vector<int> C = vector<int>(razA); // 4.3.1
        for (int i = 0; i < razA; ++i) { // 4.3.2
            C[i] = A[i]; 
        }
        int razC = razA;
        int i = 1; // 4.3.3
    number4_3_4:
        int j = 1; // 4.3.4
        for (; i <= razB;) { // 4.3.5
            if (C[j - 1] == B[i - 1]) { // 4.3.5.1
                i = i + 1; // 4.3.5.1.1
                if (i <= razB) // 4.3.5.1.2 
                    goto number4_3_4; // 4.3.5.1.2.1
            }
            else { // 4.3.5.2
                j = j + 1; // 4.3.5.2.1
                if (j <= razA) { // 4.3.5.2.2
                    goto number4_3_4; // 4.3.5.1.2.1
                }
                else { // 4.3.5.2.3
                    razC = razC + 1; // 4.3.5.2.3.1 
                    C.push_back(B[i]); // 4.3.5.2.3.2
                    i = i + 1; // 4.3.5.2.3.3
                    goto number4_3_4; // 4.3.5.2.3.4
                }
            }
        }
        cout << "{ ";
        for (int k = 0; k < razC; ++k) { // 4.3.6.1
            cout << C[k] << " ";
        }
        cout << "}";
    } break;
    case 2: { // 4.4
        vector<int> C = vector<int>(0); // 4.4.1
        int razC = 0; 
        int i = 1; // 4.4.2
    number4_4_3:
        int j = 1; // 4.4.3
        for (; i <= razB; ++i) { // 4.4.4
            if (B[i] == A[j - 1]) {
                razC = razC + 1; // 4.4.4.1.1
                C.push_back(A[i - 1]); // 4.4.4.1.2
                i = i + 1; // 4.4.4.1.3
                goto number4_4_3; // 4.4.4.1.4
            }
            else {
                if (j < razA) { // 4.4.4.2.1
                    j = j + 1; // 4.4.4.2.1.1
                }
                else {
                    goto number4_4_3;
                }
            }
        }
        cout << "{ ";
        for (int k = 0; k < razC; ++k) { // 4.4.5.1
            cout << C[k] << " ";
        }
        cout << "}";
    } break;
    case 3: { // 4.5
        vector<int> C = vector<int>(0); // 4.5.1
        int razC = 0;
        int i = 1; // 4.5.2
    number4_5_3:
        int j = 1; // 4.5.3
        for (; i <= razA;) { // 4.5.4
            if (A[i - 1] != B[j - 1]) { // 4.5.4.1
                if (j != razB) { // 4.5.4.1.1
                    razC = razC + 1; // 4.5.4.1.1.1
                    C.push_back(A[i - 1]); // 4.5.4.1.1.2
                    i = i + 1; // 4.5.4.1.1.3
                    goto number4_5_3; // 4.5.4.1.1.4
                }
                else {
                    j = j + 1; // 4.5.4.1.2.1
                }
            }
            else {
                i = i + 1; // 4.5.4.2.1
                goto number4_5_3; // 4.5.4.2.2
            }
        }
        cout << "{ ";
        for (int k = 0; k < razC; ++k) { // 4.5.5.1
            cout << C[k] << " ";
        }
        cout << "}";
    } break;
    case 4: { // 4.6
        int razU;
        cin >> razU; // 4.6.1
        vector<int> U = vector<int>(razU); // 4.6.2
        vector<int> C = vector<int>(0); // 4.6.4
        int razC = 0;
        int i = 1; // 4.6.5
    number4_6_6:
        int j = 1; // 4.6.6
        for (; i <= razU;) { // 4.6.7
            if (U[i - 1] != A[j - 1]) { // 4.6.7.1
                if (j != razA) { // 4.6.7.1.1
                    razC = razC + 1; // 4.6.7.1.1.1
                    C.push_back(U[i - 1]); // 4.6.7.1.1.2
                    i = i + 1; // 4.6.7.1.1.3
                    goto number4_6_6; // 4.6.7.1.14
                }
                else {
                    j = j + 1; // 4.6.7.1.2.1
                }
            }
            else {
                i = i + 1; // 4.6.7.2.1
                goto number4_6_6; // 4.6.7.2.2
            }
        }
        cout << "{ ";
        for (int k = 0; k < razC; ++k) { // 4.6.8.1
            cout << C[k] << " ";
        }
        cout << "}";
    } break;
    case 5: { // 4.7
        vector<int> C = vector<int>(0); // 4.7.1
        int razC = 0;
        int j = 1; // 4.7.2
    number4_7_3:
        int i = 1; // 4.7.3
        for (; j <= razA;) { // 4.7.4
            if (A[j - 1] != B[i - 1]) { // 4.7.4.1
                j = j + 1; // 4.7.4.1.1
                B.erase(B.begin() + i - 1); // 4.7.4.1.2
                razB = razB - 1; // 4.7.4.1.3
                goto number4_7_3; // 4.7.4.1.4
            }
            else {
                if (i == razB) { // 4.7.4.2.1
                    razC = razC + 1; // 4.7.4.2.1.1
                    C.push_back(A[j - 1]); // 4.7.4.2.1.2
                    j = j + 1; // 4.7.4.2.1.3
                    goto number4_7_3; // 4.7.4.2.1.4
                }
                else {
                    i = i + 1; // 4.7.4.2.2.1
                    goto number4_7_3; // 4.7.4.2.2.2
                }
            }
        }
        razC = razC + razB; // 4.7.5.1
        j = 1; // 4.7.5.2
        for (; j <= razB;) { // 4.7.5.3
            C.push_back(B[j - 1]); // 4.7.5.3.1
            j = j + 1; // 4.7.5.3.2
        }
        cout << "{ ";
        for (int k = 0; k < razC; ++k) { // 4.7.5.4.1
            cout << C[k] << " ";
        }
        cout << "}";
    } break;
    case 6: { // 4.8
        vector<vector<int>> C = vector<vector<int>>(razB * razB); // 4.8.1
        int razC = razA * razB;
        vector<int> T = vector<int>(2); // 4.8.2
    number4_8_3:
        int i = 1; // 4.8.3
        int j = 1; // 4.8.4
        int k = 1; // 4.8.5
        for (; i < razA;) { // 4.8.6
            if (j <= razB) { // 4.8.6.1
                T[0] = A[i - 1]; // 4.8.6.1.1
                T[1] = B[j - 1]; // 4.8.6.1.2
                C[k] = T; // 4.8.6.1.3
                k = k + 1; // 4.8.6.1.4
                j = j + 1; // 4.8.6.1.5
            }
            else {
                i = i + 1; // 4.8.6.2.1
                goto number4_8_3; // 4.8.6.2.2
            }
        }
        cout << "{ ";
        for (int l = 0; l < razC; ++l) { // 4.8.7.1
            cout << "< ";
            for (int i = 0; i < 2; ++i) {
                cout << C[l][i] << " ";
            }
            cout << "> ";
        }
        cout << "}";

    } break;
    }
}

