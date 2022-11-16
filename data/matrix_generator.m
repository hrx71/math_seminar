clear
clc
%24
%matrix5 -->  -5.1014e+216
% Matrix4.txt-->1.1647e+152
%Matrix3.txt -5.7417e+93 ~25
%Matrix2 -> -9.1672e+40  ~10 primes
%Matrix1 -->-5.5855e+04 ~2 primes
A = [92    99     1     8    15    67    74    51    58    40
    98    80     7    14    16    73    55    57    64    41
     4    81    88    20    22    54    56    63    70    47
    85    87    19    21     3    60    62    69    71    28
    86    93    25     2     9    61    68    75    52    34
    17    24    76    83    90    42    49    26    33    65
    23     5    82    89    91    48    30    32    39    66
    79     6    13    95    97    29    31    38    45    72
    10    12    94    96    78    35    37    44    46    53
    11    18   100    77    84    36    43    50    27    59];

% hadamard = size(A,1)^(size(A,1)/2)*5^size(A,1)
% determinante = det(A)
if(rank(A)<size(A,1))
    disp('Matrix is singular')
else 
    disp('Matrix is regular')
end

dlmwrite('matrix6.txt',A,'\t');