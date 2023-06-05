ABin removeMenor (ABin *a){
    ABin res = *a;
    if (*a!=NULL){
        if ((*a)->esq == NULL){
            res = *a;
            *a = (*a)->dir;
        }
        else res = removeMaior(&((*a)->esq));
    }
    return res;
}

void removeRaiz (ABin *a){
    ABin menor = removeMenor (&((*a)->dir));
    ABin aux_e = (*a)->esq;
    ABin aux_dir = (*a)->dir;
    free(*a);
    if (menor == NULL) *a = aux_e;
    else{
        *a = menor;
        (*a)->esq = aux_e;
        (*a)->dir = aux_dir;
    }
}





ABin removeMenor (ABin *a){
    if (*a == NULL) return NULL;
    if ((*a)->esq == NULL){
        ABin resultado = *a;
        *a = (*a)->dir;
        return resultado;
    }
    else{
        return removeMenor(&((*a)->esq));
    }
}