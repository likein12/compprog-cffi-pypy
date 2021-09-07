// AVL tree

typedef struct {
    cs_data_t_TAG key;
    cs_node_TAG* left;
    cs_node_TAG* right;
    int rank;
    int size;
} cs_node_TAG;

cs_node_TAG* new_cs_node_TAG(cs_data_t_TAG key){
    cs_node_TAG* nd = (cs_node_TAG*)malloc(sizeof(cs_node_TAG));
    nd->key = key;
    nd->left = NULL;
    nd->right = NULL;
    nd->rank = 0;
    nd->size = 1;
    return nd;
}

typedef struct {
    cs_node_TAG* root;
    int size;
} coset_TAG;

coset_TAG* coset_init_TAG(){
    coset_TAG* cs = (coset_TAG*)malloc(sizeof(coset_TAG));
    cs->root = NULL;
    cs->size = 0;
}

int cs_get_size_TAG(coset_TAG* cs){
    return cs->size;
}

cs_node_TAG* _cs_max_TAG(cs_node_TAG* nd){
    if (nd->right==NULL) return nd;
    return _cs_max_TAG(nd->right);
}

cs_node_TAG* cs_max_TAG(coset_TAG* cs){
    if (cs->root==NULL) return NULL;
    return _cs_max_TAG(cs->root);
}

cs_node_TAG* _cs_min_TAG(cs_node_TAG* nd){
    if (nd->left==NULL) return nd;
    return _cs_min_TAG(nd->left);
}

cs_node_TAG* cs_min_TAG(coset_TAG* cs){
    if (cs->root==NULL) return NULL;
    return _cs_min_TAG(cs->root);
}

cs_node_TAG* _cs_lower_bound_TAG(cs_node_TAG* nd, cs_data_t_TAG k){
	if(nd==NULL) return NULL;
	if(nd->key < k) return _cs_lower_bound_TAG(nd->right, k);
	return _cs_lower_bound_TAG(nd->left, k)?:nd;
}

cs_node_TAG* cs_lower_bound_TAG(coset_TAG* cs, cs_data_t_TAG k){
    return _cs_lower_bound_TAG(cs->root, k);
}

cs_node_TAG* _cs_upper_bound_TAG(cs_node_TAG* nd, cs_data_t_TAG k){
	if(nd==NULL) return NULL;
	if(nd->key <= k) return _cs_upper_bound_TAG(nd->right, k);
	return _cs_upper_bound_TAG(nd->left, k)?:nd;
}

cs_node_TAG* cs_upper_bound_TAG(coset_TAG* cs, cs_data_t_TAG k){
    return _cs_upper_bound_TAG(cs->root, k);
}

cs_node_TAG* _cs_find_TAG(cs_node_TAG* nd, cs_data_t_TAG k){
    if(nd==NULL) return NULL;
    if(nd->key==k) return nd;
    if(nd->key<k) return _cs_find_TAG(nd->right, cs_data_t_TAG k);
    if(nd->key>k) return _cs_find_TAG(nd->left, cs_data_t_TAG k);
}

cs_node_TAG* cs_find_TAG(coset_TAG* cs, cs_data_t_TAG k){
    return _cs_find_TAG(cs->root, k);
}

//勉強中
cs_node_TAG* _cs_insert_TAG(cs_node_TAG* nd, cs_data_t_TAG k){
    if(nd==NULL) return new_cs_node_TAG(k);
    if(nd->key<k) nd->right = insert(nd->right, k);
    else nd->left = insert(nd->left, k);
}

void cs_insert_TAG(coset_TAG* cs, cs_data_t_TAG k){
    cs->root = _cs_insert_TAG(cs->root, k);
}

//勉強中
cs_node_TAG* _cs_remove_TAG(cs_node_TAG* nd, cs_data_t_TAG k){
    if(nd==NULL) return new_cs_node_TAG(k);
    if(nd->key<k) nd->right = insert(nd->right, k);
    else nd->left = insert(nd->left, k);
}

void cs_remove_TAG(coset_TAG* cs, cs_data_t_TAG k){
    
}