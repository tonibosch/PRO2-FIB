/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    i_arbsuma(primer_node,N,asum.primer_node);
}

static int i_arbsuma(node_arbreNari* n, int N, node_arbreNari* & m) {
    if( n == NULL) {
        m = NULL;
        return 0;
    }
    else {
        int suma = n->info;
        m = new node_arbreNari;
        m->seg = vector<node_arbreNari*>(N,NULL);
        for (int i = 0; i < N; ++i){
            int suma_fill = i_arbsuma(n->seg[i],N,m->seg[i]);
            suma += suma_fill;
        }
        m->info = suma;
        return suma;
    }
}