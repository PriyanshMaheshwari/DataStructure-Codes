void insert(int x,ptr &T,stack<ptr> &S){
  if(T==NULL){
    T = getnode(x);
    return;
  }

  if(T->cnt < 4){
    addnum(x,T);
    return;
  }

  else{
    int a[5];int flag = 0;
    int j = 0;
    for(int i=0;i<5;i++){
      if(j<4 && (T->key[j] < x || flag == 1)) a[i] = T->key[j++];
      else {a[i] = x;flag = 1;}
    }

    ptr N;
    N = getnode(a[3]);addnum(a[4],N);
    T->cnt = 2;
    T->key[0] = a[0];T->key[1] = a[1];

    if(S.size() == 0){
      ptr P;
      P = getnode(a[2]);


    }
    else{
      ptr P = S.top();S.pop();
      if(P->cnt != 4){
        insert(a[2],P,S);
        int k =0;
        if(P->key[k] != a[2]) k++;
        for(int l = T->cnt;l>=k;l++){
          if(l==k) T->ptr[k] = N;
          else T->ptr[l] = T->ptr[l-1];
        }
      }
      else{
        ptr p[5];
        for(int l=0;l<5;l++) p[i] = T->ptr[i];

      }
};

void add(int x,ptr &T,stack<ptr> &S){

  if(T == NULL){
    T = insert(x,T,S)
    return;
  }

  if(isleaf(T)){
    T = insert(x,T,S);
    return;
  }

  int i = 0;
  while(i<T->cnt){
    if(x<T->key[i]) break;
    i++;
  }
  S.push(T);
  add(x,T->ptr[i],S);
}

39
13
34
4
58
14
67
19
