static int max(const int a, const int b){return a>b?a:b;}
typedef struct set_node{
	int key;
	int rank;
	int size;
	struct set_node *left, *right;
} set_node;
int get_rank(set_node *x){return x == NULL ? -1 : (*x).rank;}
int get_size(set_node *x){return x == NULL ?  0 : (*x).size;}
static void update(set_node *x){
	if(x == NULL)return;
	(*x).rank = max(get_rank((*x).left),get_rank((*x).right)) + 1;
	(*x).size = get_size((*x).left) + get_size((*x).right) + 1;
}
static set_node* new_node(int k){
	set_node* res = (set_node*)malloc(sizeof(set_node));
	(*res).key = k;
	(*res).left = NULL;
	(*res).right = NULL;
	(*res).rank = 0;
	(*res).size = 1;
	return res;
}
static set_node* left_rotate(set_node* x){
	if(x == NULL) return NULL;
	set_node *y = (*x).right;
	if(y == NULL) return x;
	(*x).right = (*y).left;
	(*y).left = x;
	update(x);
	update(y);
	return y;
}
static set_node* right_rotate(set_node *y){
	if(y == NULL) return NULL;
	set_node *x = (*y).left;
	if(x == NULL) return y;
	(*y).left = (*x).right;
	(*x).right = y;
	update(y);
	update(x);
	return x;
}
static set_node* fixup(set_node *x){
	if(x == NULL) return NULL;
	update(x);
	int l = get_rank((*x).left), r = get_rank((*x).right);
	if(abs(l - r) <= 1) return x;
	if(l - r == 2){
		if(get_rank((*(*x).left).left) < get_rank((*(*x).left).right)){
			(*x).left = left_rotate((*x).left);
		}
		return right_rotate(x);
	}
	if(l - r == -2){
		if(get_rank((*(*x).right).left) > get_rank((*(*x).right).right)){
			(*x).right = right_rotate((*x).right);
		}
		return left_rotate(x);
	}
	return NULL;
}
set_node* insert(set_node *x, int t){
	if(x == NULL){
		return new_node(t);
	}
	if(t < (*x).key){
		(*x).left = insert((*x).left, t);
	}else{
		(*x).right = insert((*x).right, t);
	}
	return fixup(x);
}

set_node*lt(set_node*x,int k){
	if(x==NULL)return NULL;
	if((*x).key>=k)return lt((*x).left,k);
	return lt((*x).right,k)?:x;
}
set_node*gt(set_node*x,int k){
	if(x==NULL)return NULL;
	if((*x).key<=k)return gt((*x).right,k);
	return gt((*x).left,k)?:x;
}

set_node*SetInit(){
    set_node *s;
    return s;
}