ptr pare(ptr T,int x,ptr root){
  if(!T) return T;
  if(T->key[0] == x && T==root) return NULL;
  int i = 0;
  for(i;i<T->cnt;i++){
    if(x == T->ptr[i]->key[0]) return T;
    if(x<T->key[i]) break;
  }
  return pare(T->ptr[i],x,root);
}
