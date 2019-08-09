#include <iostream>
#include <stdio.h>
#define ll long long
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

const int MAXN = 1e5 + 10;
ll sum[MAXN << 2];
ll add[MAXN << 2];

void push_up(int rt){//���ϸ���
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int rt, int m){
    if(add[rt]){//���б��,�򽫱�������ƶ�һ��
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += (m - (m >> 1)) * add[rt];
        sum[rt << 1 | 1] += (m >> 1) * add[rt];
        add[rt] = 0;//ȡ��������
    }
}

void build(int l, int r, int rt){//����
    add[rt] = 0;
    if(l == r){
        scanf("%lld", &sum[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);//���ϸ���
}

void update(int L, int R, ll key, int l, int r, int rt){//�������
    if(L <= l && R >= r){
        sum[rt] += (r - l + 1) * key;
        add[rt] += key;
        return;
    }
    push_down(rt, r - l + 1);//���¸���
    int mid = (l + r) >> 1;
    if(L <= mid) update(L, R, key, lson);
    if(R > mid) update(L, R, key, rson);
    push_up(rt);//���ϸ���
}

ll query(int L, int R, int l, int r, int rt){//�������
    if(L <= l && R >= r) return sum[rt];
    push_down(rt, r - l + 1);//���¸���
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(L <= mid) ans += query(L, R, lson);
    if(R > mid) ans += query(L, R, rson);
    return ans;
}

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while(m--){
        char str[3];
        int x, y;
        ll z;
        scanf("%s", str);
        if(str[0] == 'C'){
            scanf("%d%d%lld", &x, &y, &z);
            update(x, y, z, 1, n, 1);
        }else{
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
}
