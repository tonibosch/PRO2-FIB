/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
    return i_maxim(primer_node,N);
}

static T i_maxim(node_arbreNari* n, int N){
    T max = n->info;
    for(int i = 0; i < N; ++i){
        if(n->seg[i] != NULL and max < i_maxim(n->seg[i],N)) max = i_maxim(n->seg[i],N);
    }
    return max;
}