#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    vector<int> A, B;
    setlocale(LC_ALL, "Russian");
    int razA, razB;
    int choice = 0, temp = 0;
    cout << "������� , ���� ������ ������ ��������� ����������, ��� 2, ���� ������ ������ ��������� ����������" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "������� ����������� ��������� A" << endl; // 4.1.2.1
            cin >> razA;
            cout << "������� ����������� ��������� B" << endl; // 4.1.2.2
            cin >> razB;
            A = vector<int>(razA); // 4.1.2.3
            B = vector<int>(razB); // 4.1.2.4
            for (int i = 0; i < razA; i++) {// 4.1.2.5
                cin >> A[i];
            }
            for (int j = 0; j < razB; ++j) {//4.1.2.6
                cin >> B[j];
            }
        }
        case 2: {
            int k, d, h, s = 1;
            cin >> k;
            cin >> d;
            cin >> h;
            A = vector<int>(h - d + 1);
            razA = h - d + 1;
            vector<int> coefA = vector<int>(k);
            vector<int> powA = vector<int>(k);

            int j = 1;
            int res = 0;
            for (; d < h;) {
                for (; j <=
                       coefA.size();) { //!!! размер веткора или k использовать для показателя размера множества коэфф
                    res = res + (coefA[j - 1] * pow(d, powA[j - 1]));
                    j = j + 1;
                }
                A[d] = res;
                d = d + s;
            }

            cin >> k;
            cin >> d;
            cin >> h;
            B = vector<int>(h - d + 1);
            razB = h - d + 1;
            vector<int> coefB = vector<int>(k);
            vector<int> powB = vector<int>(k);

            j = 1;
            res = 0;
            for (; d < h;) {
                for (; j <=
                       coefB.size();) { //!!! размер веткора или k использовать для показателя размера множества коэфф
                    res = res + (coefB[j - 1] * pow(d, powB[j - 1]));
                    j = j + 1;
                }
                B[d] = res;
                d = d + s;
            }
        }
    }
    switch (choice) {
        case 1: {
            vector<int> C = vector<int>(razA);
            for (int i = 0; i < razA; ++i) {
                C[i] = A[i];
            }
            int razC = razA;
            int i = 1;
            number4_3_4:
            int j = 1;
            for (; i <= razB;) {
                if (C[j - 1] == B[i - 1]) {
                    i = i + 1;
                    if (i <= razB) goto number4_3_4;
                } else {
                    j = j + 1;
                    if (j <= razA) {

                    } else {
                        razC = razC + 1;
                        C.push_back(B[i]);
                        i = i + 1;
                        goto number4_3_4;
                    }
                }
            }
            cout << "{ ";
            for (int k = 0; k < razC; ++k) {
                cout << C[k] << " ";
            }
            cout << "}";
        }
        case 2: {
            vector<int> C = vector<int>(0);
            int razC = 0;
            int i = 1;
            number4_4_3:
            int j = 1;
            for (; i <= razB; ++i) {
                if (B[i] == A[j - 1]) {
                    razC = razC + 1;
                    C.push_back(A[i - 1]);
                    i = i + 1;
                    goto number4_4_3;
                } else {
                    if (j < razA) {
                        j = j + 1;
                    } else {
                        goto number4_4_3;
                    }
                }
            }
            cout << "{ ";
            for (int k = 0; k < razC; ++k) {
                cout << C[k] << " ";
            }
            cout << "}";
        }
        case 3: {
            vector<int> C = vector<int>(0);
            int razC = 0;
            int i = 1;
            number4_5_3:
            int j = 1;
            for (; i <= razA;) {
                if (A[i - 1] != B[j - 1]) {
                    if (j != razB) {
                        razC = razC + 1;
                        C.push_back(A[i - 1]);
                        i = i + 1;
                        goto number4_5_3;
                    } else {
                        j = j + 1;
                    }
                } else {
                    i = i + 1;
                    goto number4_5_3;
                }
            }
            cout << "{ ";
            for (int k = 0; k < razC; ++k) {
                cout << C[k] << " ";
            }
            cout << "}";
        }
        case 4: {
            int razU;
            cin >> razU;
            vector<int> U = vector<int>(razU);
            vector<int> C = vector<int>(0);
            int razC = 0;
            int i = 1;
            number4_6_6:
            int j = 1;
            for (; i <= razU;) {
                if (U[i - 1] != A[j - 1]) {
                    if (j != razA) {
                        razC = razC + 1;
                        C.push_back(U[i - 1]);
                        i = i + 1;
                        goto number4_6_6;
                    } else {
                        j = j + 1;
                    }
                } else {
                    i = i + 1;
                    goto number4_6_6;
                }
            }
            cout << "{ ";
            for (int k = 0; k < razC; ++k) {
                cout << C[k] << " ";
            }
            cout << "}";
        }
        case 5: {
            vector<int> C = vector<int>(0);
            int razC = 0;
            int j = 1;
            number4_7_3:
            int i = 1;
            for (; j <= razA;) {
                if (A[j - 1] != B[i - 1]) {
                    j = j + 1;
                    B.erase(B.begin() + i - 1);
                    razB = razB - 1;
                    goto number4_7_3;
                } else {
                    if (i == razB) {
                        razC = razC + 1;
                        C.push_back(A[j - 1]);
                        j = j + 1;
                        goto number4_7_3;
                    } else {
                        i = i + 1;
                        goto number4_7_3;
                    }
                }
            }
            razC = razC + razB;
            j = 1;
            for (; j <= razB;) {
                C.push_back(B[j - 1]);
                j = j + 1;
            }
            cout << "{ ";
            for (int k = 0; k < razC; ++k) {
                cout << C[k] << " ";
            }
            cout << "}";
        }
        case 6: {
            vector<vector<int>> C = vector<vector<int>>(razB * razB);
            int razC = razA * razB;
            vector<int> T = vector<int>(2);
            number4_8_3:
            int i = 1;
            int j = 1;
            int k = 1;
            for (; i < razA;) {
                if (j <= razB){
                    T[0] = A[i-1];
                    T[1] = B[j-1];
                    C[k] = T;
                    k = k +1;
                    j = j +1;
                }
                else {
                    i = i +1;
                    goto number4_8_3;
                }
            }
            cout << "{ ";
            for (int l = 0; l < razC; ++l) {
                cout << "< ";
                for (int i = 0; i < 2; ++i) {
                    cout << C[l][i] << " ";
                }
                cout << "> ";
            }
            cout << "}";

        }
    }
    cout
            << "�������� ��������: 1-�����������, 2-�����������, 3-��������, 4-����������, 5-�������. ��������, 6-��������� ��������."
            << endl;
    cin >> choice; //����� ��������
    vector<int> c;
}

