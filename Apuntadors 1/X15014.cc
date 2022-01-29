/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const{
    i_arb_sumes(primer_node, asum.primer_node);
}

static int i_arb_sumes(node_arbre* n, node_arbre* &asum){
    int s;
    if(n == NULL) {                                         //Cas base: Si l'arbre és nul
        asum = NULL;
        s = 0;
    }
    else {                                                  //Cas base: Si l'arbre és nul 
        asum = new node_arbre;                              //Cream un node

        int se = i_arb_sumes(n->segE,asum->segE);           //Cream els fills del node esquerra i retornem el valor de la seva suma.
        int sd = i_arb_sumes(n->segD,asum->segD);           //Cream els fills del node dret i retornem el valor de la seva suma.
        asum->info = se + sd + n->info;                     //El node de l'arbre creat té la suma del seus fills més el node en la mateixa posició que està en el p.i.
        s = asum->info;
    }
    return s;
}