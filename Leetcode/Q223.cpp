//�̶���һ�������ڶ������ĸ���λ�ڵ�һ������
//   AD --- CD     EH --- GH
//   |       |     |       |
//   AB --- CB     EF --- GF
// �����ص�������������

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    //R1 H(A,C),V(B,D)
    //R2 H(E,G),V(F,H)

    int X,Y;
    //����x�ص�����
    if(C<=E || G<=A) X = 0;
    else if(A>=E && C<=G) X = abs(C-A);
    else if(A<E && C>G) X = abs(G-E);
    else X = abs(C-A)+abs(G-E)-max(abs(G-A),abs(C-E));

    //����y�ص�����
    if(H<=B || D<=F) Y = 0;
    else if(B>=F&&D<=H) Y = abs(D-B);
    else if(B<F&&D>H) Y = abs(H-F);
    else Y = abs(D-B)+abs(H-F)-max(abs(H-B),abs(F-D));

    int X1 = abs(C-A);
    int Y1 = abs(D-B);
    int X2 = abs(G-E);
    int Y2 = abs(H-F);
    cout << X1*Y1 << endl << X2*Y2 << endl << X*Y <<endl;

    return X1*Y1+X2*Y2-X*Y;  
}

-2
-1
2
2
-2
-2
2
0