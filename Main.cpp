//Shady Salaheldin
#include <cstdlib>
#include <iostream>
#include "LargeInteger.cpp"
#include <string>

using namespace std;

void test();

int main()
{
    test();

    system("PAUSE");
    return 0;
}

void test() {
    string Ainit, Binit, Cinit, Dinit, AXinit, AZinit;
    LongInteger A, B, C, D, AX, AZ, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, AA, AB, AC, AD, AE, AF, AG, AH, E1, E2, E3, E4, E5, E6, E7, E8;

    Ainit = "2222";
    Binit = "50174";//"99999999";
    Cinit = "246813575732";
    Dinit = "110004";//"180270361023456789";
    AXinit = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";
    AZinit = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";


    A.INITIALIZE(Ainit);
    B.INITIALIZE(Binit);
    C.INITIALIZE(Cinit);
    D.INITIALIZE(Dinit);
    AX.INITIALIZE(AXinit);
    AZ.INITIALIZE(AZinit);

    /*cout<< "A = ";A.PRINT();cout<<endl;
    cout<< "B = ";B.PRINT();cout<<endl;
    cout<< "C = ";C.PRINT();cout<<endl;
    cout<< "D = ";D.PRINT();cout<<endl;
    cout<< "AX = ";AX.PRINT();cout<<endl;
    cout<< "AZ = ";AZ.PRINT();cout<<endl;


    int count;
    count = A.GETDIGITCOUNT();
    cout<< "# of digits in A = "<< count<<endl;
    count = B.GETDIGITCOUNT();
    cout<< "# of digits in B = "<< count<<endl;
    count = C.GETDIGITCOUNT();
    cout<< "# of digits in C = "<< count<<endl;
    count = D.GETDIGITCOUNT();
    cout<< "# of digits in D = "<< count<<endl;
    count = AX.GETDIGITCOUNT();
    cout<< "# of digits in AX = "<< count<<endl;
    count = AZ.GETDIGITCOUNT();
    cout<< "# of digits in AZ = "<< count<<endl;*/





    cout << "A > B : ";
    if (A.GREATERTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A > C : ";
    if (A.GREATERTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A > D : ";
    if (A.GREATERTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A > AX : ";
    if (A.GREATERTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A > AZ : ";
    if (A.GREATERTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "A < B : ";
    if (A.LESSTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A < C : ";
    if (A.LESSTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A < D : ";
    if (A.LESSTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A < AX : ";
    if (A.LESSTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A < AZ : ";
    if (A.LESSTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "A = B : ";
    if (A.EQUALTO(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A = C : ";
    if (A.EQUALTO(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A = D : ";
    if (A.EQUALTO(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A = AX : ";
    if (A.EQUALTO(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A = AZ : ";
    if (A.EQUALTO(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;



    cout << "B > A : ";
    if (B.GREATERTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B > C : ";
    if (B.GREATERTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B > D : ";
    if (B.GREATERTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B > AX : ";
    if (B.GREATERTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B > AZ : ";
    if (B.GREATERTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "B < A : ";
    if (B.LESSTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B < C : ";
    if (B.LESSTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B < D : ";
    if (B.LESSTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B < AX : ";
    if (B.LESSTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "A < AZ : ";
    if (A.LESSTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "B = A : ";
    if (B.EQUALTO(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B = C : ";
    if (B.EQUALTO(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B = D : ";
    if (B.EQUALTO(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B = AX : ";
    if (B.EQUALTO(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "B = AZ : ";
    if (B.EQUALTO(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;




    cout << "C > A : ";
    if (C.GREATERTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C > B : ";
    if (C.GREATERTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C > D : ";
    if (C.GREATERTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C > AX : ";
    if (C.GREATERTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C > AZ : ";
    if (C.GREATERTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "C < A : ";
    if (C.LESSTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C < B : ";
    if (C.LESSTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C < D : ";
    if (C.LESSTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C < AX : ";
    if (C.LESSTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C < AZ : ";
    if (C.LESSTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "C = A : ";
    if (C.EQUALTO(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C = B : ";
    if (C.EQUALTO(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C = D : ";
    if (C.EQUALTO(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C = AX : ";
    if (C.EQUALTO(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "C = AZ : ";
    if (C.EQUALTO(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;



    cout << "D > A : ";
    if (D.GREATERTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D > B : ";
    if (D.GREATERTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D > C : ";
    if (D.GREATERTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D > AX : ";
    if (D.GREATERTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D > AZ : ";
    if (D.GREATERTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "D < A : ";
    if (D.LESSTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D < B : ";
    if (D.LESSTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D < C : ";
    if (D.LESSTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D < AX : ";
    if (D.LESSTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D < AZ : ";
    if (D.LESSTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "D = A : ";
    if (D.EQUALTO(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D = B : ";
    if (D.EQUALTO(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D = C : ";
    if (D.EQUALTO(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D = AX : ";
    if (D.EQUALTO(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "D = AZ : ";
    if (D.EQUALTO(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;




    cout << "AX > A : ";
    if (AX.GREATERTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX > B : ";
    if (AX.GREATERTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX > C : ";
    if (AX.GREATERTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX > D : ";
    if (AX.GREATERTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX > AZ : ";
    if (AX.GREATERTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "AX < A : ";
    if (AX.LESSTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX < B : ";
    if (AX.LESSTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX < C : ";
    if (AX.LESSTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX < D : ";
    if (AX.LESSTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX < AZ : ";
    if (AX.LESSTHAN(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "AX = A : ";
    if (AX.EQUALTO(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX = B : ";
    if (AX.EQUALTO(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX = C : ";
    if (AX.EQUALTO(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX = D : ";
    if (AX.EQUALTO(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AX = AZ : ";
    if (AX.EQUALTO(AZ))
        cout << "True" << endl;
    else
        cout << "False" << endl;




    cout << "AZ > A : ";
    if (AZ.GREATERTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ > B : ";
    if (AZ.GREATERTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ > C : ";
    if (AZ.GREATERTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ > D : ";
    if (AZ.GREATERTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ > AX : ";
    if (AZ.GREATERTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "AZ < A : ";
    if (AZ.LESSTHAN(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ < B : ";
    if (AZ.LESSTHAN(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ < C : ";
    if (AZ.LESSTHAN(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ < D : ";
    if (AZ.LESSTHAN(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ < AX : ";
    if (AZ.LESSTHAN(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    cout << "AZ = A : ";
    if (AZ.EQUALTO(A))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ = B : ";
    if (AZ.EQUALTO(B))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ = C : ";
    if (AZ.EQUALTO(C))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ = D : ";
    if (AZ.EQUALTO(D))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "AZ = AX : ";
    if (AZ.EQUALTO(AX))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int XX = 99999999;
    int ofB = OVER_FLOW(XX);
    cout << "Over flow B = " << ofB << endl;

    E = A.ADD(D);
    cout << "E = A + D = "; E.PRINT(); cout << endl;
    F = B.ADD(C);
    cout << "F = B + C = "; F.PRINT(); cout << endl;
    G = C.ADD(D);
    cout << "G = C + D = "; G.PRINT(); cout << endl;
    H = E.ADD(E);
    cout << "H = E + E = "; H.PRINT(); cout << endl;
    I = A.ADD(E);
    cout << "I = A + E = "; I.PRINT(); cout << endl;
    J = B.ADD(G);
    cout << "J = B + G = "; J.PRINT(); cout << endl;


    K = A.SUBTRACT(D);
    cout << "K = A - D = "; K.PRINT(); cout << endl;
    L = C.SUBTRACT(D);
    cout << "L = C - D = "; L.PRINT(); cout << endl;
    M = D.SUBTRACT(C);
    cout << "M = D - C = "; M.PRINT(); cout << endl;
    N = H.SUBTRACT(H);
    cout << "N = H - H = "; N.PRINT(); cout << endl;
    O = L.SUBTRACT(K);
    cout << "O = L - K = "; O.PRINT(); cout << endl;
    P = J.SUBTRACT(M);
    cout << "P = J - M = "; P.PRINT(); cout << endl;



    Q = A.MULTIPLY(D);
    cout << "Q = A * D = "; Q.PRINT(); cout << endl;
    R = B.MULTIPLY(C);
    cout << "R = B * C = "; R.PRINT(); cout << endl;
    S = D.MULTIPLY(D);
    cout << "S = D * D = "; S.PRINT(); cout << endl;
    T = K.MULTIPLY(E);
    cout << "T = K * E = "; T.PRINT(); cout << endl;
    U = F.MULTIPLY(L);
    cout << "U = F * L = "; U.PRINT(); cout << endl;
    V = I.MULTIPLY(J);
    cout << "V = I * J = "; V.PRINT(); cout << endl;


    W = D.POWER(2);
    cout << "W = D ^ 2 = "; W.PRINT(); cout << endl;
    X = A.POWER(5);
    cout << "X = A ^ 5 = "; X.PRINT(); cout << endl;
    Y = B.POWER(10);
    cout << "Y = B ^ 10 = "; Y.PRINT(); cout << endl;
    Z = W.POWER(4);
    cout << "Z = W ^ 4 = "; Z.PRINT(); cout << endl;
    AA = E.POWER(2);
    cout << "AA = E ^ 2 = "; AA.PRINT(); cout << endl;
    AB = K.POWER(2);
    cout << "AB = K ^ 2 = "; AB.PRINT(); cout << endl;



    AC = D.DIVIDE(B);
    cout << "AC = D / B = "; AC.PRINT(); cout << endl;
    AD = D.DIVIDE(A);
    cout << "AD = D / A = "; AD.PRINT(); cout << endl;
    AE = Q.DIVIDE(D);
    cout << "AE = Q / D = "; AE.PRINT(); cout << endl;
    AF = T.DIVIDE(K);
    cout << "AF = T / K = "; AF.PRINT(); cout << endl;
    AG = H.DIVIDE(E);
    cout << "AG = H / E = "; AG.PRINT(); cout << endl;
    AH = U.DIVIDE(U);
    cout << "AH = U / U = "; AH.PRINT(); cout << endl;





    E1 = AX.MULTIPLY(AZ);
    cout << "E1 = AX * AZ = "; E1.PRINT(); cout << endl;
    E2 = AX.MULTIPLY(AX);
    cout << "E2 = AX * AX = "; E2.PRINT(); cout << endl;
    E3 = AZ.MULTIPLY(AZ);
    cout << "E3 = AZ * AZ = "; E3.PRINT(); cout << endl;
    E4 = E2.MULTIPLY(E3);
    cout << "E4 = E2 * E3 = "; E4.PRINT(); cout << endl;
    E5 = AX.POWER(10);
    cout << "E5 = AX ^ 10 = "; E5.PRINT(); cout << endl;
    E6 = AZ.POWER(14);
    cout << "E6 = AZ ^ 14 = "; E6.PRINT(); cout << endl;
    E7 = E2.POWER(4);
    cout << "E7 = E2 ^ 4 = "; E7.PRINT(); cout << endl;
    E8 = E3.POWER(7);
    cout << "E8 = E3 ^ 7 = "; E8.PRINT(); cout << endl;


}
