n = 12;
A = diag(ones(1, n-1), 1) + eye(n);
E = zeros(n);
E(n, 1) = 2^-n;
B = A + E;

VA = eig(A);
VB = eig(B);

norm(B - A) / norm(A)
norm(VB - VA) / norm(VA)

AA = transpose(A) * A;
BB = transpose(B) * B;
VAA = eig(AA)
VBB = eig(BB)

norm(BB - AA) / norm(AA)
norm(VBB - VAA) / norm(VAA)
