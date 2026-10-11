extern int g(int);
extern int tbl[];
int f(int a, int b, int *p) {
    int i, s = 0;
    for (i = 0; i < a; i++) { s += g(p[i] + b); tbl[i] = s; }
    return s * b;
}
