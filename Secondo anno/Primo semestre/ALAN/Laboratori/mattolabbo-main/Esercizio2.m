A = [
   0 1 1 1 1 1 1 0 0 0 0;
   1 0 0 0 0 0 0 0 0 0 0;
   1 0 0 0 0 0 0 0 0 1 0;
   1 0 0 0 1 0 0 0 0 1 0;
   1 0 0 1 0 1 0 1 0 0 0;
   1 0 0 0 1 0 0 1 0 0 0;
   1 0 0 0 0 0 0 0 0 0 0;
   0 0 0 0 1 1 0 0 1 0 0;
   0 0 0 0 0 0 0 1 0 0 0;
   0 0 1 1 0 0 0 0 0 0 1;
   0 0 0 0 0 0 0 0 0 1 0;
];

D = diag(sum(A, 1));

G = A * D^-1;

[V, w] = eig(G);

V
w;
W = sum(w, 2) % per trasformare la visualizzazione da matrice diagonale a vettore %

