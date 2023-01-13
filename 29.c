#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct process{
	int m_i;
	int h;
}process_t;
typedef struct worklist{
	int pron;
	int preh;
	int index;
	process_t *process;
}worklist_t;
int max(int a,int b){return (a>b)?a:b;}
void initwl(worklist_t **k,int M){
	*k=(worklist_t*)malloc(sizeof(worklist_t)*M);
	int i;
	for(i=0;i<M;i++){
		(*k)[i].pron=0;
		(*k)[i].preh=0;
		(*k)[i].index=i;
	}
}
void dewl(worklist_t *a,int M){
	int i,j;
	for(i=0;i<M;i++){
		printf("index:%d preh:%d process n:%d ",a[i].index,a[i].preh,a[i].pron);
		for(j=0;j<a[i].pron;j++){
			printf("(%d,%d)",a[i].process[j].m_i,a[i].process[j].h);
		}
		puts("");
	}
}
void initarr(int **arr,int n){
	*arr=malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)(*arr)[i]=0;	
}
void printarr(int *tl,int N){
	int i;for(i=0;i<N;i++)printf("%d ",tl[i]);
	puts("");
}
void inputwl(worklist_t *wl,int M){
	int i,j;
	for(i=0;i<M;i++){
		scanf("%d",&wl[i].pron);
		wl[i].process=(process_t*)malloc(sizeof(process_t)*wl[i].pron);
		for(j=0;j<wl[i].pron;j++){
			scanf("%d%d",&wl[i].process[j].m_i,&wl[i].process[j].h);
		}
	}
}
void f(worklist_t *wl,int *tl,int N,int M,int *pindex){
	int i;
	int t1,t2,tmax;
	int h,tt=0;
	for(h=0;h<M;h++)tt+=wl[h].pron;
	for(h=0;h<tt;h++){
		process_t *nextps;nextps=NULL;
		int preh=0;
		int tindex=0;
		for(i=0;i<M;i++){
			if(pindex[i] < wl[i].pron){
				t1=tl[wl[i].process[pindex[i]].m_i];
				t2=wl[i].preh;
				tmax=max(t1,t2)+wl[i].process[pindex[i]].h;
			}
			else continue;
			if(!nextps||(max(tl[nextps->m_i],preh)+(nextps->h))>tmax){
				nextps=&wl[i].process[pindex[i]];
				preh=wl[i].preh;
				tindex=wl[i].index;
			}
		}
		pindex[tindex]+=1;
		int finmax = max(tl[nextps->m_i],preh)+(nextps->h);
		wl[tindex].preh = finmax;
		tl[nextps->m_i] = finmax;
	}
}
int main(){
	int N,M;
	int i;
	int ans=0;
	scanf("%d%d",&N,&M);
	worklist_t *wl;
	int *tl;
	int *pindex;
	initwl(&wl,M);
	initarr(&tl,N);
	initarr(&pindex,M);
	inputwl(wl,M);
	f(wl,tl,N,M,pindex);
	for(i=0;i<M;i++)ans+=wl[i].preh;
	printf("%d",ans);
	for(i=0;i<M;i++)free(wl[i].process);
	free(wl);
	free(tl);
	return 0;
}