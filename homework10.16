void StrReplace_Sq2(DSqString &S,char ch){
	int i,j;
	for(i=0;i<S.length;i++){
		if(S.str[i]==ch){
			for(j=i;j<S.length;j++){
				S.str[j]=S.str[++j];
			}
			S.length--;
		}
	}
}
void StrReplace_L2(SLinkString &S,char ch){
	SLinkString p,q;
	int i,j;
	p=S->next;
	while(p){
		if(p->next->str==ch){
			p->next=p->next->next;
			free(p->next);
		}
	}
} 
void StrReplace_Sq(DSqString &S,DSqString &T,int i,int j){
	int x,y=0;
	if(i<0||j<0||j>S.length||i>S.length)return false;
	for(x=i+1;x<j;x++){
		S.str[x]=T.str[y++];
	}
} 
bool Index_Sq(DSqString S,DSqString T){
	int i=0,j=0;
	int count=0;
	while(i<S.length&&j<T.length){
		if(S.str[i]==T.str[j]){
			if(j=T.length-1){
				count++;
			}
			i++;
			j++;
		}else{
			i=i-j+1;
			j=0;
		}
	}
}