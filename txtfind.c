#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]){
    char c;
    int i=0;
    while((c=getchar())!=EOF && c!='\n' && c!='\r') {
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}


int getWord(char w[]){
    char c;
    int i=0;
    while((c=getchar())!=EOF && c!='\n' && c!='\t' && c!=' ' ) {
        w[i]=c;
        i++;
    }
    w[i]='\0';
    return i;
}

int substring(char *str1,char *str2){
    char *ans;
    ans=strstr(str1,str2);
    if (ans!=(char*)NULL){
        return 1;
    }
    return 0;
}
int similar(char *s,char *t,int n){
    if((strlen(s)- strlen(t))!=n) return 0;

    int i,j,count;
    i=j=count=0;
    for (int k = 0; k < strlen(s); k++) {
        if(*(s+i)==*(t+j)){
            i++;
            j++;
        }
        else {
            i++;
            count++;
            if(count>n) return 0;
        }
    }
    return 1;
}
void print_lines(char *str){
    char line[LINE];
    while (getLine(line))
    {
        if(substring(line,str)==1){
            printf("%s\n",line);
        }
    }
}
void print_similar_words(char *str){
    char word[WORD];
    while(getWord(word))
    {
        if(similar(word,str,1)==1 || similar(word,str,0)==1){
            printf("%s\n",word);
        }
    }

}
int main(){
    char c[WORD];
    char str[WORD];
    getWord(str);
    getWord(c);

    char temp[LINE];
    getLine(temp);

    if(strcmp(c,"a")==0) {
        print_lines(str);
    }
    else if(strcmp(c,"b")==0){
        print_similar_words(str);
    }
}
