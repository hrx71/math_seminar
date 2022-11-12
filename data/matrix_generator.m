clear
clc
%24
%matrix5 -->  -5.1014e+216
% Matrix4.txt-->1.1647e+152
%Matrix3.txt -5.7417e+93 ~25
%Matrix2 -> -9.1672e+40  ~10 primes
%Matrix1 -->-5.5855e+04 ~2 primes
A = [0 4 2 4 2 0 3 4 3 2
3 3 0 3 3 2 4 4 0 0
0 3 1 2 1 3 2 3 1 2
0 2 4 2 0 3 0 2 4 0
3 3 3 0 0 0 0 2 4 3
3 3 0 3 4 4 3 2 1 3
3 0 4 1 1 1 2 0 0 1
2 4 1 0 0 3 0 2 0 1
1 1 3 0 4 1 1 4 3 0
0 3 1 3 0 1 1 2 4 3];

hadamard = size(A,1)^(size(A,1)/2)*5^size(A,1)
determinante = det(A)
if(rank(A)<size(A,1))
    disp('Matrix is singular')
else 
    disp('Matrix is regular')
end

dlmwrite('matrix1.txt',A,'\t');