#include<ctype.h>
#include<string.h>
#define size 50
struct stack
{
    char st[size];
    int top;
};
typedef struct stack S;
char in[size],pos[size],pre[size];
void push(S *s,char data)
{
    if(s->top==size-1)
    {
        printf("\nStack Overload");
        return;
    }
    s->top=s->top+1;
    s->st[s->top]=data;
}
char pop(S *s)
{
    if(s->top==-1)
    {
        printf("\n Stack underflow\n");
        return -1;
    }
    return s->st[s->top--];
}
int prec(char ch)
{
    if(ch=='('||ch=='#')
    return 0;
     if(ch=='+'||ch=='-')
    return 1;
     if(ch=='*'||ch=='/')
    return 2;
     if(ch=='^'||ch=='$')
    return 3;
    
}
void infixtopost(S s)
{
   
    int i=0,j=0;
    push(&s,'#');
    for(i=0;in[i]!='\0';i++)
    {
     if(isdigit(in[i]))
   {
     while(isdigit(in[i]))
     {
        pos[j++]=in[i++];
     }
        pos[j++]=' ';
        i--;
    }
    else if(in[i]=='(')
    {
        push(&s,in[i]);
    }
    else if(in[i]==')')
    {
        while(s.st[s.top]!='(')
        {
            pos[j++]=pop(&s);
            pos[j++]=' ';
        }
        pop(&s);
    }
    else
    {
        while(prec(s.st[s.top])>=prec(in[i]))
        {
            pos[j++]=pop(&s);
            pos[j++]=' ';
        }
        push(&s,in[i]);
    }
    }
    while(s.st[s.top]!='#'){
    pos[j++]=pop(&s);
    pos[j++]=' ';
    }pos[j]='\0';
}
int posteval(S s)
{   
  
    int i=0;
    int res;
    char op1,op2,temp[20];
     while (pos[i] != '\0') {
        if (isdigit(pos[i])) {
            int k = 0;
            // Extract the full number
            while (isdigit(pos[i])) {
                temp[k++] = pos[i++];
            }
            temp[k] = '\0';  // Null-terminate the string
                push(&s, atoi(temp)); 
        }
    
        else if(pos[i]!=' ')
        {
            op2=pop(&s);
            op1=pop(&s);
            switch(pos[i])
            {
                case '+' : res=op1+op2;
                            break;
                case '-' : res=op1-op2;break;
                case '*' : res=op1*op2;break;
                case '/' : res=op1/op2;break;
                case '^' : res=1;
                            for(int j=0;j<op2;j++)
                            {
                                res*=op1;
                            }
                           
                            break;
             }
             push(&s,res);
        }
        i++;
    }
    return pop(&s);
}
void reverse(char *str)
{
    int n=strlen(str);
    for(int i=0;i<n/2;i++)
    {
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;

    }
}
void infixtoprefix(S s)
{
  
    int i=0,j=0;
  int n=strlen(in);
    reverse(in);
    for(int i=0;i<n;i++)
    {
        if(in[i]=='(')
        {
            in[i]=')';
        }
        else if(in[i]==')')
        {
            in[i]='(';
        }
    }
    push(&s,'#');
    for(i=0;i<strlen(in);i++)
    {
        if(isalnum(in[i]))
    {
        while(isalnum(in[i]))
    {
        pre[j++]=in[i++];
    }
    
        pre[j++]=' ';
        i--;
    }
    else if(in[i]=='(')
    {
        push(&s,in[i]);
    }
    else if(in[i]==')')
    {
        while(s.st[s.top]!='(')
        {
            pre[j++]=pop(&s);
            pre[j++]=' ';
        }
        pop(&s);
    }
    else
    {
        while(prec(s.st[s.top])>prec(in[i]))
        {
            pre[j++]=pop(&s);
            pre[j++]=' ';
        }
        push(&s,in[i]);
    }
    }
    while(s.st[s.top]!='#'){
    pre[j++]=pop(&s);
    pre[j++]=' ';
    }pre[j]='\0';
}


int preeval(S s)
{   
    
    int i=0;
    int result;
    char op1,op2,temp[20];
  int len=strlen(pre);
  for(int i=len-1;i>=0;i--)
    {   int k=0;
        if(isdigit(pre[i]))
        {
            while(i>=0&&isdigit(pre[i]))
        {
            
          temp[k++]=pre[i--];
        }
        temp[k]='\0';
        reverse(temp);
         push(&s,atoi(temp));
         i++;
        }
        else if(pre[i]!=' ')
        {
            op1=pop(&s);
            op2=pop(&s);
            switch(pre[i])
            {
                case '+' : result=op1+op2;
                            break;
                case '-' : result=op1-op2;break;
                case '*' : result=op1*op2;break;
                case '/' : result=op1/op2;break;
                case '^' : result=1;
                            for(int j=0;j<op2;j++)
                            {
                                result*=op1;
                            }
                            break;
             }
             push(&s,result);
        }
    }
    return pop(&s);
}
int main()
{   
    struct stack s;
    s.top=-1;
    int res;result;
    int choice;
   
    for(;;)
    {
        printf("\n1.Infix to postfix\n2.Evaluation of postfix\n3.Infix to prefix\n4.Evaluation of prefix\n");    
    printf("\n Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\n Enter the infix expression\n");
                scanf("%s",in);
                infixtopost(s);
                printf("\n The postfix expression is %s  ",pos);break;
        case 2:res= posteval(s);
                printf("\n The evaluation of postfix expresiion is %d",res);break;
        case 3:  printf("\n Enter the infix expression\n");
                    scanf("%s",in);
                    infixtoprefix(s);
                reverse(pre);
                 printf("\n The prefix expression is %s  ",pre);break;
        case 4:result= preeval(s);
              printf("\n The evaluation of prefix expresiion is %d",result);break;
        case 5:exit(0);
    }
    }
   
    return 0;
}