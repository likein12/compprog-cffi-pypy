typedef struct {
    int length;
    int depth;
    int n;
    int64_t* q;
} PriorityQueue;

PriorityQueue *PriorityQueueInit(int _length){
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    int length = 1;
    int depth = 1;
    while (length<_length){
        length *= 2;
        depth += 1;
    }
    (*pq).length = length;
    (*pq).depth = depth;
    (*pq).n = 0;
    (*pq).q = (int64_t*)malloc(length*sizeof(int64_t));
    return pq;
}

int pq_get_size(PriorityQueue *pq){
    return pq->n;
}

int64_t pq_pop(PriorityQueue *pq){
    int64_t* q = pq->q;
    int res = q[0];
    q[0] = q[pq->n-1]; 
    (pq->n)--;
    int n = pq->n;
    int now = 0;
    int64_t tmp;
    int ch;
    while (2*now+1<=n-1){
        if (2*now+2<=n-1) {
            if (q[2*now+1]<q[2*now+2]) ch = 2*now+1;
            else ch = 2*now+2;
        } else {
            ch = 2*now+1;
        }
        if (q[now] > q[ch]) {
            tmp = q[now];
            q[now] = q[ch];
            q[ch] = tmp;
            now = ch;
        } else {
            break;
        }             
    }        
    return res;
}

int64_t pq_top(PriorityQueue *pq){
    return pq->q[0];
}

void pq_push(PriorityQueue *pq, int64_t x){
    int64_t* q = pq->q;
    (pq->n)++;
    int now = pq->n-1;
    q[now] = x;
    int64_t tmp;
    int par;
    while (now>0) {
        par = (now-1)/2;
        if (q[par] > q[now]) {
            tmp = q[now];
            q[now] = q[par];
            q[par] = tmp;
            now = par;
        } else {
            break;
        }       
    }
}