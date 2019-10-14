#include <stdio.h>
#include <stdlib.h>
#define size 10
char infix[size],postfix[size],stack[size];
int is_operator(char c){
        if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-'){
                return 1;
        }
        return 0;
}
int precedence(char t,int k){
	if(k!=-1){
		while(stack[k]!=')'){
			if(t==stack[k]){
				return 0;
			}
			if(t=='^'){
				return 1;
			}
			if((t=='/')||(t=='*')){
				if((stack[k]=='+')||(stack[k]=='-')){
					return 1;
				}
				return 0;
			}
			if((t=='+')||(t=='-')){
				if((stack[k]=='/')||(stack[k]=='*')){
					return 0;
				}
				return 1;
			}
			k--;
		}
	}
}
void inf_pos(char infix[]){
	int i=0,j=0,k=-1;
	while(infix[i]!=EOF){
		char term=infix[i];
		if(is_operator(term)){
			if(precedence(term,k)==1){
				stack[++k]=term;
			}
			else{
				while(stack[k]!='('){
					postfix[i++]=stack[k--];
				}
			}
		}
		else if( term=='(' || term==')' ){
			if(term=='('){
				stack[k++]=term;
			}
			else{
				while(stack[k]!='('){
                                        postfix[i++]=stack[k--];
                                }

			}
		}
		else{
			postfix[j++]=term;
		}
		i++;
	}
	postfix[j]=EOF;
	printf("\n<<<<<<POSTFIX EXPRESSION>>>>>\n");
	for(i=0;postfix[i]!=EOF;i++){
		printf("%c",postfix[i]);
	}
	printf("\n");
}
void main(){
        int c;
        printf("Press 1.Infix to Postfix Conversion 2.Evaluation of Expression:\n");
        scanf("%d",&c);
        if(c==1){
                char ch;
                int i=0;
		infix[i++]='(';
                printf("Enter the Infix expression:(!!press ctrl+d to stop!!)\n");
                while((ch=(getchar()))!=EOF){
                        infix[i++]=ch;
                }
                infix[i++]=')';
		infix[i]=EOF;
                for(i=0;infix[i]!=EOF;i++){
                        printf("%c",infix[i]);
                }
		inf_pos(infix);
        }
        /*else if(c==2){
        }*/
        else{
                exit(0);
        }
}
