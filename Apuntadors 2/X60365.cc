/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
   if(primer_node == NULL) return false;
   return i_bucar(primer_node, x);
}

static bool i_bucar(node_arbreGen* n, const T& x){
    if(n->info == x) return true;

    int mida_fills = (n->seg).size();
    bool trobat = false;
    for(int i = 0; i < mida_fills and not trobat; ++i){
        trobat = i_bucar(n->seg[i], x);
    }
    return trobat;
}