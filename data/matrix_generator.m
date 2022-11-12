clear
clc
%24
% Matrix4.txt-->det = -6148
%Matrix3.txt -3.3888e+17
%Matrix2 -> 1.4035e+10
A = [1 0 0 1 1 2 0 0 0 3 3 0 0 1 3 2 4 1 3 1 0 0 3 0 0 2 1 2 3 2 4 3 1 2 0 1 3 3 2 2 4 3 0 0 0 0 1 3 1 1 2 3 2 3 1 2 1 4 3 2 1 3 3 4 4 3 1 0 1 2 3 0 0 0 4 2 2 4 3 4 2 2 3 3 2 1 2 4 1 3 4 1 3 2 4 2 0 2 3 2
1 1 4 1 2 4 2 2 2 1 1 2 0 0 3 3 3 4 4 4 0 2 3 3 4 2 3 0 2 1 2 3 0 3 0 2 2 3 1 3 4 4 3 0 0 1 1 4 1 0 3 0 3 1 3 2 1 1 1 0 3 1 0 4 3 2 4 1 1 2 4 3 1 3 3 0 3 0 1 1 2 1 2 4 2 2 4 3 3 0 0 2 1 3 1 2 4 3 4 3
2 0 0 3 1 2 1 0 0 2 4 0 3 1 4 1 2 1 0 2 4 2 2 1 0 4 2 0 1 3 3 0 1 2 4 4 0 3 1 2 1 1 3 1 3 1 3 4 0 4 2 4 1 1 3 0 1 1 0 0 0 4 4 1 4 3 4 4 1 2 3 2 2 4 3 2 3 1 1 2 3 0 2 0 2 2 4 1 4 2 3 2 1 1 4 3 2 2 2 4
2 0 1 4 1 0 0 4 1 0 0 4 1 2 0 3 1 0 3 1 0 3 1 4 2 4 0 4 2 1 3 1 1 4 1 2 1 0 1 0 4 1 1 2 2 4 3 1 4 4 3 4 3 4 0 0 0 0 1 3 0 2 4 1 1 2 1 2 3 2 2 4 3 0 4 0 4 1 4 0 0 4 1 0 3 2 2 1 1 2 4 3 0 3 4 0 0 1 3 0
1 0 1 1 2 3 1 3 3 2 2 4 4 2 4 2 1 3 3 1 1 2 1 2 4 2 4 3 3 1 2 0 0 2 3 3 1 4 2 1 4 0 4 1 3 4 2 3 2 1 0 3 4 4 1 4 1 0 1 4 4 1 1 3 0 1 1 2 1 0 4 3 1 2 3 0 2 3 4 3 0 4 1 1 1 1 4 0 4 0 3 2 2 4 3 0 4 0 2 3
1 1 1 3 4 0 4 2 2 2 0 2 1 3 1 3 0 4 4 2 2 4 2 0 2 0 4 4 3 0 2 2 2 0 1 2 3 3 0 2 4 4 1 0 4 4 2 4 3 3 4 0 0 1 2 4 2 3 1 2 2 3 2 0 4 0 0 3 4 2 4 4 1 2 1 1 4 0 0 0 3 0 0 4 0 2 4 2 2 3 4 1 0 1 1 2 0 3 2 0
4 1 3 0 4 4 1 3 0 4 3 4 1 3 2 0 1 2 4 0 1 4 0 4 3 0 3 1 1 3 1 3 1 0 4 3 3 1 2 2 3 2 2 1 3 1 4 4 3 2 4 1 4 2 1 2 3 0 3 1 2 2 3 3 0 3 3 3 0 0 0 3 3 4 2 3 1 4 3 1 0 3 4 1 1 3 0 2 4 2 0 0 0 3 4 3 0 2 3 4
2 1 4 2 2 1 1 2 2 4 3 2 2 0 0 3 0 3 4 3 4 4 1 0 2 1 4 2 1 4 1 1 0 0 0 3 2 1 0 4 3 2 0 0 3 4 3 4 4 1 3 2 4 4 4 2 3 0 0 1 4 3 0 2 1 0 4 3 0 4 2 4 0 0 0 4 1 3 0 1 2 0 2 0 4 2 0 0 0 3 3 4 0 4 0 1 4 2 2 2
3 3 4 4 2 1 3 1 0 1 2 1 1 3 1 1 1 1 3 3 1 1 0 3 4 3 4 2 0 2 1 1 2 2 1 0 0 1 1 0 2 3 4 3 1 3 1 0 2 1 4 4 0 0 2 1 3 4 4 1 1 0 2 4 3 3 4 1 3 0 0 1 1 2 3 1 0 3 2 4 2 0 2 0 0 2 2 1 3 1 3 3 1 3 1 3 1 0 3 4
1 3 3 4 3 0 4 0 4 0 4 3 1 1 2 0 1 0 4 4 1 3 1 1 4 3 4 3 2 0 2 3 2 2 1 3 2 4 3 3 2 0 0 4 0 2 4 2 2 3 2 1 4 0 2 3 2 3 4 0 4 0 3 2 2 3 3 0 3 3 2 0 0 2 0 2 4 3 2 3 0 2 1 3 0 4 3 4 4 2 3 3 4 2 1 0 3 3 0 1
4 1 1 1 2 3 2 0 3 4 3 0 3 4 3 3 2 1 0 3 4 2 1 2 0 0 1 2 0 1 3 0 1 0 1 2 4 2 1 4 0 1 1 3 0 2 2 4 3 4 1 0 1 0 1 4 3 4 3 2 4 3 4 1 1 2 2 0 3 4 2 1 0 2 3 0 0 3 0 3 0 2 1 4 3 3 3 1 3 0 0 4 1 3 4 4 2 1 1 2
4 0 1 2 4 2 1 0 3 3 4 4 2 3 1 3 4 0 0 0 1 1 4 1 1 2 3 2 0 3 1 4 4 2 0 2 2 1 1 0 3 4 2 0 4 1 2 4 4 3 4 1 0 1 1 2 4 0 0 4 3 1 3 1 2 0 1 2 3 3 1 3 1 1 2 3 0 4 4 3 3 2 0 4 1 0 1 2 1 1 3 1 3 4 4 4 3 3 4 0
3 4 4 1 2 1 0 4 3 1 3 1 1 3 3 2 4 4 2 2 3 1 0 1 2 1 2 2 1 1 0 0 4 2 1 0 2 0 3 3 0 3 3 2 0 3 1 2 1 4 3 1 1 3 3 3 1 3 4 0 4 3 3 2 2 0 4 3 0 1 2 4 2 2 0 0 4 0 2 3 4 2 4 1 2 2 4 2 4 3 1 0 2 3 4 1 3 0 3 2
2 3 4 2 1 0 2 2 0 3 0 0 3 2 0 4 0 4 2 2 2 0 3 4 4 2 4 0 3 1 4 0 4 0 2 3 3 3 2 0 4 2 4 2 2 0 3 0 0 0 0 3 2 2 0 0 4 0 2 2 3 4 3 1 2 0 0 4 1 1 3 4 1 3 4 2 0 4 4 0 2 2 4 0 0 3 4 1 4 4 0 0 1 1 3 4 2 0 3 2
2 1 3 1 0 0 2 2 0 2 2 4 1 2 3 2 2 1 3 1 4 3 1 1 0 0 1 1 0 3 2 1 2 1 4 3 3 2 4 4 4 0 2 0 0 0 0 0 3 2 4 0 0 2 2 3 0 4 1 1 1 2 0 1 2 1 0 2 0 4 2 4 1 3 3 0 4 2 4 2 2 1 4 1 4 4 4 0 4 3 1 4 4 1 3 0 2 3 4 1
2 2 3 0 0 4 4 3 2 3 1 2 2 1 1 2 2 4 0 3 0 4 3 2 2 4 4 0 2 3 0 4 0 2 2 1 3 1 1 2 2 3 4 0 4 3 4 3 4 3 3 2 0 2 1 0 0 4 4 4 1 0 2 3 0 4 1 3 4 3 1 2 4 0 0 4 2 2 3 0 4 4 0 1 0 1 0 1 4 4 2 4 2 3 2 0 0 4 2 2
2 1 2 2 4 1 3 1 1 0 2 0 1 3 0 3 3 1 4 1 3 1 4 2 0 1 0 3 0 2 0 2 1 4 2 1 3 1 4 3 0 0 1 0 0 1 3 0 4 0 1 2 4 2 3 1 2 1 2 1 4 2 0 1 0 3 1 0 1 1 0 1 3 0 0 2 1 0 1 4 4 3 2 0 3 0 0 1 3 2 1 4 0 4 2 4 0 3 0 1
1 1 0 3 1 1 2 0 4 1 3 0 4 2 1 0 3 1 0 2 4 0 2 2 0 0 3 0 0 0 2 0 4 1 4 2 2 2 4 4 2 4 4 2 0 3 1 2 0 0 1 0 1 3 0 0 0 0 4 2 2 2 2 3 2 3 3 0 0 3 1 2 4 3 1 4 4 3 2 0 3 0 1 2 4 3 1 1 0 3 4 0 1 1 0 3 1 2 0 4
3 1 0 2 4 3 2 2 3 0 2 3 4 3 3 3 4 3 0 1 1 3 2 2 3 1 3 2 1 0 0 2 2 3 2 2 4 2 0 4 0 2 4 0 4 3 0 4 2 2 0 3 1 0 2 1 4 3 1 3 2 1 1 2 4 4 3 4 3 1 1 2 2 0 2 4 0 1 1 0 0 2 0 2 0 4 4 3 0 4 2 4 3 2 0 4 3 3 3 4
4 4 3 2 0 3 1 4 1 3 1 2 2 4 1 3 2 1 3 2 1 2 3 0 0 0 1 4 1 2 4 0 1 2 3 0 0 1 4 4 0 3 4 2 1 0 4 3 3 2 1 0 0 4 1 1 1 0 0 1 0 4 0 1 0 3 3 0 3 2 1 4 4 0 0 2 1 2 2 2 0 4 1 1 0 1 2 4 0 2 2 4 3 4 3 4 1 4 2 2
1 4 4 4 0 4 2 1 2 2 3 4 3 4 4 4 3 4 4 1 1 1 3 2 3 1 3 1 1 1 1 1 3 0 2 1 0 0 4 1 1 2 1 2 0 1 0 0 0 3 3 4 1 0 0 1 1 0 3 3 0 1 4 4 2 0 0 2 2 4 2 4 1 1 0 1 3 1 4 3 3 2 2 4 0 0 3 0 3 0 2 1 4 2 1 3 1 4 3 0
4 3 2 1 0 2 4 2 0 3 2 2 3 3 1 1 0 1 2 3 0 4 0 0 3 1 1 2 0 2 1 4 3 3 2 4 1 2 2 0 3 1 2 3 0 1 3 3 2 2 1 3 0 2 1 2 2 3 2 0 3 4 4 4 3 4 2 3 0 3 4 3 2 2 4 1 4 1 3 3 1 2 2 0 1 0 2 2 1 0 1 2 4 2 4 4 0 1 3 1
0 2 0 4 4 2 2 1 0 4 2 1 4 3 2 4 4 1 2 1 3 3 0 4 2 4 0 2 0 2 4 0 4 2 3 1 1 3 0 2 4 2 3 1 0 1 1 2 2 4 3 3 0 0 1 3 2 1 4 4 4 4 1 3 2 0 2 3 4 2 1 0 4 3 3 2 2 1 0 2 4 0 4 2 2 2 4 4 4 4 3 2 3 2 0 3 4 3 4 2
4 2 3 3 0 2 4 2 2 2 0 0 0 4 0 0 0 3 2 2 0 3 2 3 4 0 4 4 0 1 4 4 2 3 4 0 4 4 1 4 0 3 3 3 4 1 0 3 0 1 4 0 3 2 1 4 3 0 4 0 0 0 0 4 3 1 3 0 3 0 1 3 2 0 4 3 2 4 2 3 3 4 2 2 1 4 0 1 0 3 2 3 1 3 0 1 4 2 1 1
2 2 3 0 0 2 4 3 4 2 4 2 0 4 3 2 3 2 0 2 1 3 1 2 1 1 1 1 0 0 1 4 1 4 1 2 4 1 1 4 3 3 3 3 4 1 4 3 3 0 0 0 3 1 0 4 4 1 4 0 0 2 4 2 4 3 4 0 0 0 3 0 4 3 1 2 0 3 1 0 4 0 3 2 4 3 2 0 4 3 4 4 4 4 4 0 1 4 3 3
3 2 2 2 3 2 3 0 1 2 1 4 0 3 3 0 3 4 2 3 4 4 0 3 4 1 1 1 2 3 0 2 2 2 3 0 4 1 0 1 1 4 2 2 0 3 3 4 1 4 2 2 1 0 0 4 4 4 3 3 2 1 2 2 4 1 3 3 1 2 4 3 0 2 2 2 1 1 0 2 2 0 2 2 4 1 1 4 4 2 3 1 1 0 1 3 4 1 4 1
4 3 4 0 1 4 1 3 3 2 0 2 2 1 2 3 0 4 4 1 1 4 4 4 0 4 0 3 3 4 0 1 3 3 3 0 2 2 3 0 1 0 2 1 1 0 0 3 2 1 4 1 3 2 4 3 1 3 2 4 2 2 2 2 4 0 3 3 1 3 0 1 4 0 4 0 4 1 3 0 3 4 3 3 1 4 1 1 0 3 1 0 1 1 0 0 1 4 0 1
3 2 3 3 0 3 0 0 1 4 2 4 2 4 0 0 3 1 1 1 4 2 1 2 1 2 1 3 0 2 4 1 3 0 2 1 1 1 0 4 1 0 2 1 0 0 4 3 3 4 1 2 0 2 1 1 2 4 4 0 4 4 1 2 4 4 2 1 1 4 0 4 1 4 3 3 3 2 2 2 3 1 1 2 2 4 3 4 0 4 4 1 1 2 4 3 1 3 3 4
4 1 1 1 3 2 1 0 4 3 0 3 1 4 2 1 3 3 1 3 0 3 0 1 3 3 0 3 2 2 3 3 4 0 2 3 1 4 4 2 1 3 3 2 3 0 1 4 3 2 1 4 0 0 0 3 1 3 2 2 2 3 3 3 0 2 0 3 2 2 1 2 4 0 3 4 3 2 0 0 1 0 4 1 2 0 4 4 0 2 0 2 3 0 2 0 4 2 3 4
4 1 2 3 3 1 4 0 2 4 3 2 0 0 4 2 1 3 3 1 4 1 3 3 0 2 0 1 2 4 3 3 4 3 1 0 2 0 4 0 3 2 1 4 3 4 0 3 4 4 1 2 3 0 2 3 4 2 0 0 2 4 4 0 1 2 4 3 2 3 4 2 1 2 2 3 0 3 3 3 0 2 1 4 2 2 1 4 4 2 0 3 2 4 3 4 1 3 2 3
0 4 4 3 3 4 2 1 2 1 4 1 0 4 3 1 0 0 4 4 4 1 2 1 0 4 2 4 0 1 1 3 1 0 1 4 3 0 1 0 4 3 4 0 3 3 3 1 0 1 0 3 3 1 0 3 4 1 0 0 4 1 4 4 3 3 4 1 4 2 0 1 4 1 2 4 4 0 4 1 1 0 2 1 3 0 4 4 2 1 3 4 0 2 1 0 0 2 3 3
3 4 3 3 4 0 1 3 4 3 1 0 1 1 2 3 0 0 4 1 1 1 1 2 2 3 0 0 3 1 1 0 3 1 4 4 3 1 1 2 1 3 0 3 2 4 1 3 2 4 3 2 0 2 4 3 1 3 1 3 2 0 0 2 1 2 0 2 1 4 1 3 4 2 2 0 4 2 3 3 2 0 3 3 0 3 1 4 2 4 2 1 2 2 4 2 2 1 3 3
0 1 1 3 0 3 4 0 1 4 2 4 3 1 0 0 4 2 3 3 0 2 0 2 3 1 4 4 3 4 1 2 3 3 4 2 3 1 0 4 1 4 2 1 0 3 0 0 4 4 4 3 2 4 4 0 0 1 0 0 1 3 0 0 0 3 1 1 3 2 4 2 4 4 1 0 0 1 1 2 4 0 1 2 4 4 0 3 4 2 4 4 1 4 4 1 2 0 0 3
0 4 3 2 2 2 4 2 0 0 1 3 4 4 3 2 2 4 4 4 2 1 3 1 3 4 2 1 0 1 4 3 0 4 4 0 1 1 3 2 1 2 2 1 0 1 3 3 2 0 2 2 3 4 3 4 4 3 2 3 4 2 1 4 0 0 3 3 0 1 4 4 2 0 4 1 3 1 1 0 2 3 0 2 2 1 3 3 4 3 1 2 2 4 2 2 0 1 1 3
0 3 4 4 4 0 3 4 3 0 3 2 0 2 3 4 1 1 1 0 1 1 3 2 1 3 0 1 4 0 2 4 2 0 3 3 3 4 2 0 2 4 2 1 2 0 4 3 2 4 0 2 4 0 2 0 1 3 0 0 3 2 2 4 0 4 0 3 2 0 3 1 0 2 1 2 1 1 0 2 1 4 3 1 2 4 3 1 4 1 1 3 3 1 1 3 1 1 3 0
1 3 3 0 3 3 1 0 4 2 2 0 3 2 2 1 0 1 0 4 2 1 3 2 4 1 2 0 3 4 2 2 0 4 2 0 3 1 2 4 1 0 1 2 3 4 2 0 3 3 0 1 0 3 2 0 4 2 3 2 4 1 0 3 2 2 1 3 3 3 2 1 0 1 1 1 2 1 1 0 1 3 4 4 4 4 3 1 3 1 4 1 4 3 2 3 4 4 3 0
3 0 1 3 2 2 3 4 3 4 4 2 0 3 1 0 2 3 2 1 1 2 4 2 3 2 3 0 0 4 4 0 1 3 2 3 0 4 4 4 1 2 2 3 1 4 2 3 1 2 4 3 0 0 2 3 1 1 0 2 3 0 4 4 3 3 4 0 3 3 2 3 4 2 2 1 4 2 0 1 4 3 3 2 1 4 2 3 0 3 0 2 0 2 1 4 2 0 0 3
0 3 1 4 1 1 4 3 2 2 0 1 4 1 1 4 2 3 4 3 1 0 1 1 3 3 4 2 3 4 3 3 3 0 3 2 0 1 1 4 3 4 1 0 3 2 3 3 0 2 4 1 4 1 1 0 1 3 1 4 3 0 2 4 4 4 3 4 2 0 3 3 0 2 3 0 3 0 0 4 0 3 0 2 1 2 0 3 0 3 4 2 2 1 0 1 1 3 2 3
0 4 4 2 0 4 0 2 0 3 2 1 3 0 1 2 3 1 0 2 0 4 3 1 2 4 4 3 1 0 2 1 2 3 1 0 0 0 2 4 3 2 2 4 1 2 3 2 0 4 1 2 3 4 4 4 1 3 3 0 1 1 2 3 2 0 2 4 2 3 2 1 4 2 3 1 1 2 1 2 2 4 0 1 1 4 4 0 1 2 3 0 2 3 1 2 1 1 4 1
4 0 2 4 0 4 0 3 2 3 2 1 3 3 0 2 3 0 0 1 2 1 3 0 1 2 4 2 3 3 3 0 2 0 2 0 2 4 3 3 2 4 4 2 0 1 1 3 3 3 2 3 4 1 2 2 0 3 3 4 1 0 2 3 2 3 2 1 3 2 4 0 2 4 2 0 3 1 4 2 3 0 4 1 3 1 2 1 0 3 2 4 3 0 0 0 4 1 3 1
3 2 0 0 3 2 3 0 0 4 3 2 0 1 3 4 1 0 3 2 1 3 0 1 0 2 0 4 1 3 4 0 3 3 3 1 1 2 2 1 3 1 0 4 0 3 2 0 3 1 0 3 4 3 2 2 3 1 0 1 2 3 0 0 0 0 0 3 3 4 4 3 3 0 2 1 3 0 0 1 4 2 3 0 0 4 2 0 1 3 2 4 2 2 4 2 4 1 2 2
4 3 2 0 2 3 2 2 0 1 0 4 2 3 1 1 4 3 4 1 1 0 1 4 3 3 1 2 0 4 2 0 0 2 3 1 0 1 3 0 2 0 0 3 0 1 4 3 1 1 0 4 0 2 0 0 0 1 1 1 2 1 1 0 1 4 4 2 3 0 1 2 1 4 2 4 3 0 2 1 4 4 1 0 0 1 1 2 2 2 0 0 2 0 0 2 0 1 0 0
0 2 0 3 3 4 1 2 3 2 1 2 1 2 3 1 3 1 0 3 4 2 2 4 0 0 0 3 0 0 0 3 3 4 2 3 3 3 0 2 2 0 2 4 2 2 3 4 2 4 0 1 2 0 2 2 3 2 0 2 3 4 4 3 0 2 0 4 0 4 3 3 1 4 4 1 2 3 4 2 4 2 0 4 2 4 2 0 1 2 2 1 2 4 0 1 2 2 3 4
4 2 2 4 4 1 2 0 0 0 0 1 1 1 0 3 2 0 2 4 4 2 4 1 3 2 2 3 1 4 0 0 0 1 0 3 4 1 0 3 4 0 2 1 4 1 4 2 0 1 0 4 3 4 0 1 3 0 1 0 4 0 2 1 4 2 0 4 2 4 1 0 0 3 4 0 4 0 3 4 4 4 0 1 4 4 4 3 3 2 0 1 4 2 0 1 2 2 4 4
1 0 4 0 1 3 2 2 2 0 0 2 3 2 4 0 0 1 2 3 0 2 1 3 0 2 1 0 0 0 1 2 2 4 4 1 4 1 1 0 0 2 3 0 4 2 1 2 4 3 1 1 3 1 3 3 4 2 0 0 0 0 4 2 2 2 3 2 4 1 2 4 2 4 4 1 3 1 2 1 4 4 3 1 3 1 0 0 3 3 3 0 0 0 2 0 1 3 1 1
3 2 2 0 4 3 2 2 3 3 3 3 1 0 4 0 3 1 1 4 3 0 1 2 4 0 2 3 3 3 3 1 3 3 2 0 4 0 3 0 1 2 2 3 1 3 3 3 0 3 2 3 2 0 3 0 1 4 4 3 0 0 1 3 2 1 4 3 1 3 2 0 2 1 4 3 3 2 4 4 4 4 0 1 0 1 0 3 0 1 3 0 3 0 2 1 2 4 3 2
3 1 4 4 2 1 2 4 4 1 2 4 1 0 4 0 3 4 2 4 2 4 3 4 3 3 4 4 1 2 1 3 1 2 4 0 4 4 1 2 1 1 4 3 3 4 4 2 0 2 2 4 1 0 3 4 2 3 3 3 4 1 0 0 3 0 3 0 0 0 1 1 3 2 0 3 2 0 2 0 0 0 3 3 4 2 2 3 0 2 4 2 4 3 2 3 1 2 2 2
2 0 4 4 2 1 4 2 0 2 0 3 4 4 1 4 0 2 0 4 2 4 4 2 0 0 4 2 4 2 3 4 3 4 3 0 1 0 3 2 4 1 1 2 3 2 1 2 0 3 2 3 2 3 0 0 3 4 2 4 4 0 1 2 0 2 1 1 3 4 0 3 4 0 1 2 0 0 3 3 2 2 3 2 2 3 2 2 2 2 2 4 3 2 0 3 0 3 4 0
2 0 0 3 2 4 0 4 3 4 2 2 4 4 0 1 2 3 2 3 1 3 4 0 0 2 1 2 2 3 0 4 0 4 2 3 3 0 1 0 2 0 2 3 2 3 4 0 4 0 2 2 0 2 0 0 1 3 2 3 1 3 1 2 4 2 0 1 3 4 0 4 1 0 2 2 3 4 4 0 0 2 4 1 4 2 1 4 3 0 0 2 0 4 4 2 4 3 0 1
0 0 3 1 1 4 4 3 3 3 3 1 4 2 0 3 0 3 1 3 1 3 2 2 0 1 0 1 4 1 3 0 3 1 4 4 2 2 1 3 3 0 4 0 0 1 4 2 1 3 0 1 0 3 4 2 3 1 2 4 0 4 1 3 0 0 2 1 4 1 3 2 1 1 2 0 1 4 3 4 1 4 3 1 2 1 1 0 2 3 2 0 2 2 3 4 0 2 2 2
2 4 0 1 4 4 0 3 4 0 3 1 3 0 1 3 3 4 0 4 2 0 3 2 1 1 2 2 4 3 4 0 4 0 3 0 0 1 3 1 3 4 0 2 3 0 0 1 2 0 2 4 1 0 2 0 4 4 1 0 1 0 0 0 4 0 0 3 2 4 2 2 4 1 1 1 4 0 2 1 2 2 1 4 4 4 4 4 2 4 2 4 0 4 2 2 3 2 3 1
2 2 4 3 1 0 0 1 1 0 0 3 3 0 4 0 3 1 4 1 3 3 3 4 0 1 2 4 3 1 3 0 1 3 2 0 3 2 3 2 1 2 3 4 0 1 4 1 0 4 0 0 0 1 3 4 1 1 3 1 0 4 0 1 4 2 3 2 0 0 2 4 4 2 1 3 4 1 2 3 0 0 4 2 0 0 4 4 1 4 4 1 3 1 0 3 2 3 3 1
4 3 4 2 4 4 1 1 0 2 1 1 0 0 2 4 4 4 2 3 4 0 4 0 2 4 1 0 0 1 3 1 2 0 1 2 1 0 2 4 4 3 2 2 1 3 3 2 0 3 2 0 1 1 4 3 3 2 1 2 1 1 0 0 2 2 0 4 4 1 2 1 1 3 3 2 1 1 0 4 2 0 1 0 2 2 3 0 3 3 4 4 3 3 3 0 0 2 4 2
4 4 0 3 4 4 4 1 3 3 3 3 0 2 3 1 2 0 3 0 1 0 4 2 1 1 0 1 2 1 0 2 1 2 0 0 3 0 2 3 3 0 0 3 0 2 3 1 3 3 0 3 0 0 0 3 1 3 3 4 4 0 2 0 4 4 3 3 4 1 2 4 4 1 0 4 4 0 2 2 1 1 2 3 0 4 2 2 3 4 0 2 4 3 3 3 1 4 4 3
2 2 0 2 4 2 3 2 3 2 1 4 0 3 1 3 4 0 0 4 1 0 3 3 2 0 3 1 4 0 1 2 2 4 1 4 1 4 3 0 1 2 0 4 4 3 3 0 1 1 0 0 1 4 0 2 2 4 1 1 1 1 4 1 1 4 1 0 1 0 0 4 1 1 4 2 0 2 2 4 2 4 1 0 1 4 1 2 4 0 1 0 1 0 2 2 4 0 1 3
1 1 0 2 3 3 2 3 0 4 3 0 2 3 4 0 0 2 4 1 1 1 4 4 0 2 0 4 0 1 0 4 3 1 2 4 3 0 1 3 4 0 4 1 3 3 0 3 1 3 0 3 0 2 3 4 0 0 0 2 2 4 2 4 2 3 0 4 3 4 0 4 2 3 4 3 4 4 4 3 4 2 3 0 4 1 4 2 0 2 2 2 4 4 4 3 3 4 4 4
3 3 1 2 2 4 2 3 1 0 4 2 0 2 1 4 4 1 2 3 3 4 0 0 4 0 3 0 0 1 4 1 4 2 2 4 4 0 1 1 4 1 1 4 3 0 4 0 1 2 1 2 2 1 3 1 1 0 1 3 0 1 1 3 3 3 2 4 1 1 1 1 0 2 2 0 2 2 1 4 2 3 4 0 0 2 0 2 4 2 2 3 3 3 3 0 1 3 3 2
3 2 4 3 1 0 2 4 4 1 4 0 4 0 2 0 3 4 3 3 1 1 1 4 4 4 1 4 1 1 1 4 3 1 1 3 4 2 3 2 4 2 1 0 1 2 4 1 2 0 2 4 1 0 2 3 2 2 4 1 2 3 3 4 2 3 2 4 0 2 3 0 4 1 4 3 0 0 4 1 1 2 4 3 0 3 2 3 2 2 0 3 2 0 3 1 3 2 0 0
4 2 4 2 4 1 3 3 4 1 2 1 4 4 4 4 2 1 1 3 4 2 2 3 0 4 4 0 3 1 1 2 1 4 3 2 4 3 1 1 0 3 4 3 0 3 0 1 4 3 4 4 4 2 1 2 0 3 3 1 4 3 2 3 3 4 4 1 3 1 0 1 3 4 0 1 2 3 3 2 3 3 4 2 3 1 0 4 2 1 1 1 2 1 2 3 2 1 4 0
1 3 1 4 0 2 4 2 3 4 1 4 0 3 1 1 4 4 3 4 2 4 1 0 2 2 3 3 3 3 0 1 4 1 0 3 1 1 1 3 1 0 4 0 2 1 4 2 0 3 2 2 4 4 3 0 1 2 0 4 0 3 1 3 0 0 3 0 1 0 0 2 1 4 1 1 3 4 2 3 3 1 0 0 3 4 4 1 1 1 0 0 1 1 0 4 1 2 3 3
3 1 0 2 0 4 4 3 2 4 3 1 0 0 3 2 3 2 0 0 2 3 2 3 3 2 3 0 0 3 4 4 0 0 2 1 0 2 1 2 1 3 4 1 1 4 2 2 2 2 0 3 0 3 3 0 3 4 3 3 2 0 0 4 4 2 4 1 2 0 1 4 4 4 4 2 0 1 2 4 3 2 2 0 3 2 4 3 0 4 2 0 2 0 1 1 1 3 4 4
1 2 0 2 1 1 1 1 1 1 4 4 3 3 4 1 3 2 2 0 2 2 4 3 1 2 2 3 1 1 4 3 2 2 4 4 1 1 1 3 4 2 2 1 1 3 1 4 0 1 3 1 4 3 1 3 0 2 2 1 4 0 0 1 2 4 3 2 0 1 0 2 2 1 1 3 0 4 1 1 4 4 4 2 2 3 4 4 4 3 0 4 1 2 4 1 2 3 4 4
1 0 2 0 4 0 0 0 0 2 0 0 1 2 1 4 2 3 4 4 2 0 3 1 3 0 2 3 3 0 1 4 2 1 0 2 3 1 4 0 0 3 0 1 2 0 1 4 4 3 3 4 2 3 1 3 0 2 3 3 0 3 1 3 0 4 0 4 0 2 2 4 1 1 0 3 2 2 0 4 1 3 2 1 2 4 3 1 2 0 3 0 4 1 0 4 1 1 0 0
1 3 0 0 0 4 0 1 4 1 0 4 4 4 4 2 1 0 3 4 1 3 3 2 1 1 4 1 3 3 4 3 4 1 0 3 0 2 3 1 0 0 4 1 3 0 3 2 2 3 3 3 1 0 0 1 2 2 3 2 3 0 2 2 3 3 2 1 4 0 2 1 1 3 3 0 1 3 1 4 0 3 0 0 3 0 0 3 1 2 1 1 2 1 4 1 3 3 0 3
3 0 2 1 4 1 3 2 0 3 1 0 1 3 1 3 3 3 2 1 1 0 3 0 1 4 4 3 3 1 3 1 4 3 3 2 3 4 1 1 3 4 4 3 3 3 2 1 3 3 0 0 0 0 1 1 0 1 0 2 2 1 2 1 0 3 1 4 2 4 4 0 3 1 2 0 2 4 4 3 0 4 2 2 0 1 1 4 1 4 0 4 0 4 1 0 3 1 4 4
0 3 1 4 0 3 2 2 4 0 1 4 1 4 3 3 2 4 0 3 2 3 4 0 0 2 1 1 4 3 4 4 0 1 3 1 2 2 0 3 4 1 0 0 0 1 0 4 0 0 4 3 1 1 4 0 1 0 1 3 3 4 2 2 3 3 4 1 0 4 3 1 3 0 3 2 2 4 2 2 0 3 3 3 4 1 1 3 3 3 1 2 3 1 3 4 1 1 3 4
0 2 1 1 1 4 3 4 2 2 2 0 1 2 1 2 2 1 3 0 3 2 3 4 4 0 3 2 1 2 2 3 3 3 1 4 2 0 1 0 4 1 1 4 2 3 1 2 2 4 2 2 3 4 2 2 3 2 4 2 0 2 1 2 0 0 0 3 4 3 1 3 4 3 0 4 4 4 4 0 1 4 0 4 1 4 3 1 2 2 2 0 0 1 1 3 0 0 0 1
1 0 3 0 0 3 2 3 0 4 2 0 3 4 4 4 0 0 1 0 3 3 2 4 4 1 1 2 2 3 3 0 4 2 0 4 1 1 3 0 4 3 2 0 3 4 4 3 1 2 0 3 3 0 1 0 3 3 3 4 2 2 2 2 0 0 2 1 4 1 3 4 0 3 2 3 3 2 2 0 3 0 4 0 4 3 4 4 3 2 2 1 3 2 3 1 1 0 4 2
2 1 3 4 4 0 1 3 2 0 3 3 0 3 1 1 3 3 2 1 1 2 3 0 3 3 2 0 3 0 0 1 2 3 1 1 0 0 0 4 0 1 2 3 3 2 4 2 4 4 0 3 1 2 2 2 4 4 2 2 4 0 0 3 2 0 2 1 1 3 1 2 1 1 2 3 0 3 1 0 1 0 0 4 0 0 0 3 3 0 3 0 0 3 1 0 4 1 3 2
3 4 3 4 4 1 4 4 4 4 2 2 3 4 4 2 0 4 2 2 4 3 0 0 2 2 1 2 3 2 3 3 1 2 2 3 1 1 3 3 2 4 0 1 4 0 3 0 3 1 3 3 3 0 3 3 4 1 0 3 2 4 4 1 3 2 3 3 1 2 0 3 3 4 0 1 3 2 2 4 3 1 2 2 1 0 3 1 0 4 4 2 4 4 3 4 3 0 2 4
2 4 2 1 4 0 3 1 0 2 3 1 0 0 3 0 0 3 3 1 2 3 3 1 4 2 3 4 0 4 4 1 1 2 0 4 2 0 2 4 1 0 3 2 4 2 3 4 4 4 3 3 2 1 2 1 4 0 1 4 3 0 4 1 3 0 1 2 2 3 2 3 3 3 3 0 3 3 2 4 3 3 3 4 0 2 4 0 1 1 4 2 3 0 3 4 3 1 0 0
2 2 4 4 4 2 1 4 1 4 1 3 2 3 3 0 4 4 2 0 2 2 2 4 0 3 3 2 0 3 4 2 0 3 1 3 4 0 1 4 2 4 3 1 1 3 4 0 4 1 0 1 3 2 1 3 0 4 0 3 3 1 2 4 3 4 0 2 4 3 1 1 1 2 0 4 0 2 2 0 0 0 1 2 1 1 4 1 1 1 4 1 4 2 1 1 1 1 2 1
3 0 1 3 4 4 2 1 1 2 2 3 3 3 0 3 3 0 4 0 4 1 2 4 3 0 3 4 2 3 0 2 2 4 1 2 4 4 3 4 3 0 2 1 0 0 3 2 0 4 0 1 4 4 4 0 2 2 2 3 4 3 1 4 4 2 4 0 0 1 4 4 1 2 0 2 2 4 0 4 2 3 3 0 4 2 0 2 4 3 0 4 4 3 4 3 1 0 0 4
1 4 4 3 0 0 4 1 3 1 0 0 2 0 4 3 0 3 1 4 3 2 4 3 2 1 0 3 1 0 3 2 4 3 1 4 2 0 3 3 0 2 3 2 1 1 3 4 4 2 0 1 1 1 0 0 3 0 4 4 2 1 3 3 4 1 2 2 4 3 4 3 0 1 4 1 3 4 0 4 0 3 3 2 1 4 1 3 3 1 4 1 1 0 0 2 4 4 2 0
0 1 2 1 0 0 0 3 1 0 1 1 4 2 1 3 3 4 1 0 1 0 3 1 0 0 4 2 4 0 4 4 4 3 4 0 0 2 0 4 3 3 2 3 0 4 4 0 1 3 3 1 3 2 4 4 3 4 0 4 3 1 2 4 1 1 4 4 3 3 4 4 2 1 0 2 2 1 0 3 1 2 1 2 1 4 4 1 3 3 4 4 4 3 1 1 3 0 3 2
4 3 3 2 1 1 4 0 1 4 2 4 0 2 4 1 4 4 0 3 1 3 3 3 3 2 2 3 1 3 1 4 4 4 4 3 4 3 2 1 0 0 3 0 4 2 3 2 0 0 2 3 2 0 2 3 1 3 2 2 0 4 4 2 2 4 1 3 1 4 3 0 0 1 2 2 3 3 4 3 2 0 1 4 4 1 3 3 0 4 1 3 1 0 2 3 3 2 0 0
0 1 2 1 2 2 3 1 0 1 2 0 1 4 2 1 2 2 4 1 4 4 2 1 3 3 0 0 1 0 4 2 4 1 4 4 0 2 3 3 3 4 4 2 1 3 2 2 4 3 1 2 3 1 0 0 0 0 3 0 2 0 4 0 1 0 4 2 1 0 0 0 3 2 3 0 4 4 1 0 2 3 2 3 4 0 2 2 0 0 3 3 1 3 3 2 2 0 3 0
1 3 1 0 0 3 1 2 3 2 3 2 3 2 1 0 4 0 1 0 2 4 0 2 3 1 0 1 3 0 2 4 0 4 3 2 4 0 1 0 4 0 3 2 2 4 0 1 2 3 4 2 4 3 3 1 0 3 4 0 1 0 2 3 4 4 1 4 2 4 0 4 3 1 0 4 4 2 3 3 3 0 2 1 1 2 0 1 1 0 3 1 0 4 3 0 3 1 4 2
3 4 4 3 3 2 0 0 4 3 2 1 1 2 0 4 1 3 1 0 4 2 3 0 4 2 3 2 2 0 3 3 4 0 1 0 4 4 1 4 0 4 0 0 0 2 4 4 4 1 0 2 1 2 3 1 2 3 0 0 2 0 1 2 3 0 2 3 1 3 4 2 1 2 4 2 3 0 2 3 4 3 3 2 1 1 2 2 4 1 0 4 1 2 0 2 3 1 4 0
2 1 4 1 2 1 1 1 4 4 4 2 2 1 1 4 1 0 2 0 3 4 1 2 2 4 3 0 3 4 4 1 4 4 4 0 4 3 3 3 2 0 0 2 4 1 1 4 1 4 1 1 0 4 4 1 0 2 4 3 4 4 2 4 1 1 1 2 3 1 4 2 3 1 3 3 2 1 0 4 4 2 4 0 4 0 2 2 1 0 1 2 4 3 1 3 3 2 2 0
3 4 3 2 2 0 3 4 0 3 2 2 4 2 1 3 2 4 2 0 3 2 3 3 4 3 0 0 0 1 4 3 1 4 1 0 1 1 1 1 1 0 3 1 3 2 0 4 0 2 4 0 3 4 3 0 2 0 3 1 4 2 2 2 3 0 4 3 0 0 0 4 2 2 4 4 3 2 2 2 3 1 4 0 0 3 2 1 0 0 3 1 4 3 3 3 4 1 1 0
1 0 0 3 3 3 2 0 2 3 2 3 2 2 1 3 3 2 4 1 2 4 0 3 0 1 1 2 4 2 1 1 0 3 3 3 1 2 1 2 2 4 4 3 4 2 4 1 1 3 0 4 1 0 4 2 2 4 2 3 0 2 2 2 4 1 0 1 4 2 2 2 3 4 4 4 3 2 2 4 3 0 2 0 3 4 0 2 4 0 2 3 4 4 4 1 2 2 3 0
1 4 0 1 3 4 1 4 4 1 0 2 0 4 0 4 2 1 0 1 1 4 1 3 1 0 0 3 4 0 1 1 1 4 1 4 2 4 3 1 3 2 0 4 1 3 4 1 2 2 0 4 4 1 1 1 0 3 3 0 3 1 1 0 1 1 2 4 2 1 3 3 3 1 2 1 1 2 3 3 0 0 2 4 0 3 1 1 0 0 1 2 0 1 0 1 3 3 0 3
2 0 4 1 1 1 0 0 3 2 4 3 1 3 1 4 1 3 2 4 2 2 1 1 3 0 1 1 0 3 4 2 3 1 3 0 3 1 1 0 4 0 2 0 2 3 0 0 4 0 1 3 4 0 3 3 0 2 4 2 2 2 4 1 0 4 1 4 0 4 2 3 2 1 4 3 0 4 1 2 3 2 1 1 2 3 3 1 3 0 4 3 1 4 3 4 3 3 0 2
4 3 0 1 3 0 2 1 2 0 1 2 0 3 2 0 1 2 0 3 1 1 4 4 3 3 4 2 4 1 2 3 3 0 2 3 0 0 3 3 1 3 0 1 2 1 2 3 0 3 2 1 4 0 4 0 3 1 1 0 0 1 4 4 2 0 0 3 1 3 4 4 3 3 2 2 4 3 0 2 3 4 1 2 0 1 1 1 4 4 0 4 3 2 4 3 1 4 4 1
3 3 1 3 4 2 0 2 2 0 2 4 3 3 2 0 3 4 2 2 0 2 0 3 1 4 4 0 3 3 4 1 3 3 2 4 1 3 2 4 4 2 4 3 0 2 2 4 3 1 3 2 2 1 4 2 3 2 4 1 3 1 4 0 4 0 1 4 3 0 0 3 3 0 0 4 1 2 3 1 3 0 4 1 2 3 4 4 0 2 3 1 3 4 1 0 2 4 2 2
4 3 0 1 4 4 4 4 2 3 2 2 0 3 2 0 2 3 0 1 0 1 2 3 3 2 2 1 2 3 1 2 0 3 3 3 2 1 2 3 0 3 1 3 2 1 0 3 2 4 4 0 1 1 0 3 2 2 2 3 1 4 0 3 2 3 0 1 0 1 0 0 3 1 4 4 0 3 2 4 3 4 0 4 2 0 2 2 0 3 2 2 4 1 2 1 3 4 1 1
4 0 3 3 0 2 2 3 1 2 4 0 3 4 3 0 4 1 2 2 0 0 1 4 1 0 1 1 0 1 4 2 2 2 4 2 1 3 4 1 3 2 4 4 0 1 4 2 0 0 4 4 4 1 4 1 1 0 4 4 0 2 0 1 3 0 3 0 3 2 3 2 3 0 3 2 4 0 0 2 4 0 1 1 4 4 1 2 0 0 4 3 0 3 1 0 2 3 1 0
4 1 3 0 1 3 4 1 1 1 1 4 4 2 0 4 4 1 4 3 4 3 2 1 2 1 1 2 0 0 3 1 3 1 4 3 2 4 1 1 0 4 1 1 0 1 4 4 4 3 0 3 1 4 4 4 4 1 2 3 2 2 2 0 3 1 3 0 2 4 0 4 1 1 1 1 1 1 1 0 1 4 1 0 0 1 0 0 0 1 0 0 4 3 1 3 1 0 0 2
4 1 2 4 3 2 0 1 0 0 2 3 3 1 3 3 1 3 0 1 1 1 0 2 3 3 4 1 2 4 0 3 2 0 2 1 0 2 2 0 0 4 0 3 1 2 0 4 1 1 3 0 2 3 4 4 0 3 2 3 4 4 1 2 3 1 0 3 3 3 3 3 3 2 1 1 3 1 4 1 2 4 4 4 4 1 0 0 1 3 0 4 0 2 2 0 1 3 0 2
0 0 0 1 3 0 4 2 0 3 4 0 3 4 4 0 4 1 3 4 0 1 1 2 2 1 1 2 3 3 4 1 4 1 0 4 2 0 2 0 4 4 0 2 2 0 4 4 4 4 0 2 4 3 0 4 4 3 0 2 1 4 1 0 1 3 2 2 3 2 3 4 2 2 4 3 2 3 1 0 2 0 3 2 1 0 4 3 1 1 0 4 2 4 2 0 2 0 3 1
2 2 2 0 1 0 1 1 4 2 2 2 2 2 3 4 4 3 4 0 0 0 2 0 4 0 2 2 2 2 1 1 1 3 3 1 1 2 2 2 4 4 0 3 0 4 2 1 4 2 1 3 4 3 1 2 3 1 0 2 4 0 4 0 0 4 1 3 4 1 1 3 1 3 3 4 1 2 1 3 1 0 0 3 3 2 2 0 2 1 2 1 3 1 2 2 1 1 3 4
4 3 4 3 4 2 3 1 1 3 1 0 1 4 4 0 0 4 0 1 1 2 3 2 0 4 4 0 0 1 1 4 2 3 1 3 4 4 3 2 3 4 4 0 3 0 2 1 2 1 4 1 3 2 3 2 0 4 2 0 1 1 3 3 3 3 3 2 2 3 1 0 2 2 1 1 1 0 2 1 3 0 4 1 4 4 4 4 1 4 1 0 4 4 2 3 4 2 0 3
1 3 1 0 1 2 4 3 4 3 0 1 4 3 2 1 3 3 4 2 3 1 2 4 3 1 3 1 0 1 3 1 4 1 0 0 2 1 0 0 1 3 1 0 1 2 1 0 3 0 2 2 1 3 4 4 4 0 2 2 3 1 4 3 2 1 0 3 4 1 2 1 0 0 3 4 2 3 4 2 2 3 1 0 3 1 2 1 1 3 1 3 1 0 2 3 2 0 3 0
4 2 3 3 3 2 2 4 2 3 0 2 1 1 3 1 2 1 1 0 0 4 3 4 0 0 1 4 2 1 2 0 0 4 3 0 4 2 4 2 2 2 2 2 4 4 3 4 4 1 1 2 3 1 4 0 0 1 1 3 2 4 2 2 3 2 4 3 4 3 0 3 4 2 4 2 1 2 0 1 4 0 3 1 2 0 3 4 0 4 1 0 2 0 0 0 1 1 0 4
1 3 3 3 1 4 1 0 2 1 3 1 3 3 1 0 4 4 0 4 4 1 1 0 4 2 3 0 3 0 1 2 2 0 1 4 3 3 2 1 3 4 2 1 1 1 4 0 0 4 4 2 2 1 2 1 2 2 3 3 0 1 3 2 1 0 1 1 3 3 1 4 0 3 0 3 1 0 2 3 2 1 3 3 1 4 0 2 4 4 2 4 1 3 3 2 4 0 4 4
1 2 2 0 0 1 2 1 0 1 4 2 2 0 3 4 0 3 1 3 0 2 4 1 3 4 3 3 3 3 4 4 3 0 4 4 3 0 2 3 1 1 0 2 3 3 2 1 3 0 2 1 0 2 0 0 1 0 1 4 1 1 0 1 3 2 2 2 4 0 4 0 1 1 1 2 2 2 3 2 2 3 3 0 4 3 0 1 2 4 1 1 0 4 2 3 3 0 0 0
3 3 2 2 2 0 2 0 4 0 3 3 0 0 0 0 3 1 4 1 2 2 4 4 2 0 2 0 2 4 0 4 0 2 3 0 1 4 1 1 2 1 0 1 1 0 4 1 4 1 0 4 1 1 2 2 2 0 4 0 1 0 2 3 2 0 3 3 2 2 3 0 4 0 0 2 1 3 3 1 3 4 3 4 2 1 2 0 3 1 3 2 0 4 1 4 0 0 0 0
0 4 0 2 4 3 1 2 2 1 4 4 2 3 0 3 3 3 1 3 3 2 2 2 0 1 2 0 3 0 3 0 1 0 3 1 0 2 0 1 0 2 0 2 4 3 2 2 4 1 1 4 4 3 2 0 0 3 4 3 1 4 4 1 3 0 0 0 4 2 1 2 2 2 1 4 2 3 4 3 1 0 3 1 4 0 2 1 1 0 3 0 4 0 4 4 2 1 0 4
2 1 0 1 1 3 2 4 0 3 2 0 4 3 1 0 3 3 1 3 4 4 1 1 2 4 4 0 1 2 2 4 4 3 2 4 4 1 1 4 2 0 2 4 1 0 4 2 4 4 1 3 3 2 1 0 0 1 4 4 1 2 3 2 3 3 4 0 0 3 0 3 4 0 0 1 3 3 4 0 1 3 1 1 1 1 0 4 1 1 0 2 2 4 2 0 0 3 3 4];
hadamard = size(A,1)^(size(A,1)/2)*5^size(A,1)
determinante = det(A)
if(rank(A)<size(A,1))
    disp('Matrix is singular')
else 
    disp('Matrix is regular')
end

dlmwrite('matrix1.txt',A,'\t');