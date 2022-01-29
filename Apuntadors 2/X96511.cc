/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
    int apar = 0;
    if(primer_node == NULL) return apar;
    else return i_freq(primer_node, x, apar);
}

static int i_freq(node_arbreGen* n, const T& x, int& apar) {
    if(n->info == x) ++apar;

    int mida_fills = n->seg.size();
    for(int i = 0; i < mida_fills; ++i){
        if(n->seg.size() != 0) i_freq(n->seg[i],x,apar);
    }
    return apar;
}