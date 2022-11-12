% clear all;
close all;
clc;
A = load('matrix4.txt')
tol = 1e-12;

%Testcase 1
% A = rand(3);
[L,R] = myLu(A);

err = max(abs(L*R-A));

if (err < tol)
    fprintf('Testcase 1: Passed\n');
else
    fprintf(2, 'Testcase 1: Failed\n');
end    
determinant = det(R)*det(L)
