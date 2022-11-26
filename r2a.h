#ifndef R2A_H
#define R2A_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG_OUTPUT
//#define CBCurses_Disable
#include "cbcurses.h"
//#define LINEMAX 4096
#define LINEMAX 1024
//#define TOKENMAX 256
#define TOKENMAX 128

char newline[LINEMAX];

struct token {
    int replaced;
    int found;
    char old[TOKENMAX];
    char rep[TOKENMAX];
};
struct token *tokens=NULL;
int tokenscount=0;

struct kill {
    int found;
    int functionkilled;
    char target[TOKENMAX];
};
struct kill *kills=NULL;
int killscount=0;

enum inform_tags {
    INF_DEBUG,
    INF_INFO,
    INF_WARNING,
    INF_FATAL,
    INF_CODE
};
int ischarvalid(char a);
int inittokens();
int initkills();
int inittweaks();
int showtokensstats();
int showkillsstats();
int inform(int lvl, const char *format, ...);
int fileexists(const char *path);
int renamefile(const char *oldname,const char *newname);
int trydelete(const char *path);
int updatefile(const char *path);
int processline(const char *line);
int replacetokens();
int processfile(const char *path);

int ischarvalid(char a){
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')){
        return 1;
    }else return 0;
}
int inittokens(){
    if(!fileexists("r2a_tokens.c"))return 0;
    FILE *fp=fopen("r2a_tokens.c","r");{
        char tok[TOKENMAX];
        while(!feof(fp)){
            memset(tok,0,TOKENMAX);
            fscanf(fp,"%s",tok);
            memset(tok,0,TOKENMAX);
            fscanf(fp,"%s",tok);
            if(strlen(tok))tokenscount++;
            else break;
        }
        inform(INF_INFO,"%d tokens found.",tokenscount);
    }
    if(tokenscount==0){
        inform(INF_WARNING,"No tokens found.");
        return 0;
    }
    tokens=malloc(tokenscount*sizeof(struct token));
    if(tokens==NULL){
        inform(INF_FATAL,"Fatal error: Cannot allocate memory.");
        fclose(fp);
        getch();
        exit(-1);
        return -1;
    }
    rewind(fp);
    for(int i=0;i<tokenscount;i++){
        char tok[TOKENMAX];
        memset(tok,0,TOKENMAX);
        fscanf(fp,"%s",tok);
        strcpy(tokens[i].old,tok);
        memset(tok,0,TOKENMAX);
        fscanf(fp,"%s",tok);
        strcpy(tokens[i].rep,tok);
        tokens[i].replaced=0;
        tokens[i].found=0;
        inform(INF_DEBUG,"%s -> %s",tokens[i].old,tokens[i].rep);
    }
    fclose(fp);
    return 1;
}
int initkills(){
    if(!fileexists("r2a_kills.c"))return 0;
    FILE *fp=fopen("r2a_kills.c","r");{
        char tok[TOKENMAX];
        while(!feof(fp)){
            memset(tok,0,TOKENMAX);
//            fscanf(fp,"%s",tok);
            fgets(tok,TOKENMAX,fp);
            size_t len=strlen(tok);
            while(len){
                if(tok[len-1]=='\n'||tok[len-1]=='\r')tok[len-1]=0;
                else break;
            }
            if(strlen(tok))killscount++;
            else break;
        }
        inform(INF_INFO,"%d kill targets found.",killscount);
    }
    if(killscount==0){
        inform(INF_WARNING,"No kill targets found.");
        return 0;
    }
    kills=malloc(killscount*sizeof(struct kill));
    if(kills==NULL){
        inform(INF_FATAL,"Fatal error: Cannot allocate memory.");
        fclose(fp);
        getch();
        exit(-1);
        return -1;
    }
    rewind(fp);
    for(int i=0;i<killscount;i++){
        char tok[TOKENMAX];
        memset(tok,0,TOKENMAX);
        fscanf(fp,"%s",tok);
        strcpy(kills[i].target,tok);
        kills[i].found=0;
        kills[i].functionkilled=0;
        inform(INF_DEBUG,"Kill %s()",kills[i].target);
    }
    fclose(fp);
    return 1;

}
int inittweaks(){
    if(!fileexists("r2a_tweaks.c"))return 0;

}
int showtokensstats(){
    if(!tokenscount){
        inform(INF_FATAL,"Illegal request.");
        return 0;
    }
    if(tokens==NULL){
        inform(INF_FATAL,"Illegal request.");
        return 0;
    }
    for(int i=0;i<tokenscount;i++){
        if(tokens[i].replaced){
            inform(INF_DEBUG,"Token \"%s\": %d replaced.",tokens[i].old,tokens[i].replaced);
        }else{
            if(!tokens[i].found)inform(INF_WARNING,"Token \"%s\" not found.",tokens[i].old);
        }
    }
    return 1;
}
int showkillsstats(){
    if(!killscount){
        inform(INF_FATAL,"Illegal request.");
        return 0;
    }
    if(kills==NULL){
        inform(INF_FATAL,"Illegal request.");
        return 0;
    }
    for(int i=0;i<killscount;i++){
        if(kills[i].found){
            inform(INF_DEBUG,"Kill target \"%s\": %d (%d) killed.",kills[i].target,kills[i].found,kills[i].functionkilled);
        }
    }
    return 1;
}
int inform(int lvl, const char *format, ...){
    switch(lvl){
    case INF_DEBUG:
#ifndef DEBUG_OUTPUT
        return 1;
#endif
        cbc_setcolor(Cyan|Bright);
        printf("[DEBUG] ");
        break;
    case INF_FATAL:
        cbc_setcolor(Red|Bright);
        printf("#FATAL# ");
        break;
    case INF_INFO:
        cbc_setcolor(Default);
//        cbc_setcolor(Green|Bright);
        break;
    case INF_WARNING:
        cbc_setcolor(Yellow|Bright);
        printf("<ERROR> ");
        break;
    case INF_CODE:
        cbc_setcolor(Green);
    default:
        break;
    }
    va_list args;
    va_start(args,format);
    vprintf(format,args);
    va_end(args);
    if(lvl!=INF_CODE)fputc('\n',stdout);
    return 1;
}
int fileexists(const char *path){
    FILE *filetocheck=fopen(path,"r");
    if(!filetocheck){
        inform(INF_WARNING,"File \"%s\" not found.",path);
        return 0;
    }
    else{
        fclose(filetocheck);
        inform(INF_INFO,"File \"%s\" found.",path);
        return 1;
    }
}
int renamefile(const char *oldname,const char *newname){
    FILE *filetocheck=fopen(oldname,"r");
    if(!filetocheck){
        inform(INF_WARNING,"Rename failed: File \"%s\" doesn't exist.",oldname);
        return 0;
    }
    fclose(filetocheck);
    int ret=rename(oldname,newname);
    if(ret==0){
        inform(INF_INFO,"File \"%s\" renamed into \"%s\".",oldname,newname);
        return 1;
    }else{
        inform(INF_WARNING,"Failed to rename file \"%s\" into \"%s\".",oldname,newname);
        return 0;
    }
}

int trydelete(const char *path){
    FILE *filetocheck=fopen(path,"r");
    if(filetocheck){
        fclose(filetocheck);
        inform(INF_INFO,"Deleting file \"%s\"...",path);
        if(remove(path)==0)inform(INF_INFO,"\"%s\" deleted.",path);
        else inform(INF_WARNING,"Cannot delete file \"%s\".",path);
        return 1;
    }
    return 0;
}
int updatefile(const char *path){
    FILE *filetocheck=fopen(path,"r");
    if(!filetocheck){
        inform(INF_WARNING,"File \"%s\" not found.",path);
        return 0;
    }
    fclose(filetocheck);
    filetocheck=fopen("r2a_temp_c","r");
    if(!filetocheck){
        inform(INF_WARNING,"Cannot update file.",path);
        return 0;
    }
    fclose(filetocheck);
    if(remove(path)!=0){
        inform(INF_WARNING,"Cannot delete file \"%s\".",path);
        return 0;
    }
    if(rename("r2a_temp_c",path)!=0){
        inform(INF_WARNING,"Cannot delete file \"%s\".",path);
        return 0;
    }
    inform(INF_INFO,"File \"%s\" updated.",path);
    return 1;
}
int processline(const char *line){
    if(strlen(line)==0)return 0;
    static int cplusplus=0,functiondeclaration=0,deletable=0,deleteflag=0;
    if(deletable==2){
        deletable=0;
        deleteflag=0;
    }
    int kill=0;
    if(!functiondeclaration){
        if((ischarvalid(line[0])&&strncmp(line,"typedef",7)&&strncmp(line,"extern \"",8)&&strncmp(line,"FILE *funopen",13)&&strchr(line,';')==NULL&&strchr(line,'[')==NULL)
           ||strncmp(line,"{\n",2)==0||strncmp(line,"}\n",2)==0){
            static int LINESTATUS=3;
            if(line[0]=='{'){
                if(LINESTATUS==1);
                else inform(INF_WARNING,line);
                LINESTATUS=2;
            }
            else if(line[0]=='}'){
                if(LINESTATUS==2);
                else inform(INF_WARNING,line);
                LINESTATUS=3;
                if(deletable)deletable=2;
            }else{
                if(LINESTATUS==3);
                else inform(INF_WARNING,line);
                if(strchr(line,'{'))LINESTATUS=2;
                else LINESTATUS=1;
                {
                    deletable=1; // the whole function should be removed?
                    for(int i=0;i<killscount;i++){
                        char *temp=strstr(line,kills[i].target);
                        if(temp){
                            if(temp>line){
                                temp--;
                                if(ischarvalid(temp[0]))continue;
                                temp++;
                            }
                            temp+=strlen(kills[i].target);
                            if(temp<line+LINEMAX){
                                if(ischarvalid(temp[0]))continue;
                            }
                            temp-=strlen(kills[i].target);
                        }else continue;
                        kills[i].functionkilled++;
                        deleteflag=1;
                        inform(INF_DEBUG,"%s found.",kills[i].target);
                    }
                }
            }
        }
    }
    if(strstr(line,"__cplusplus")){
        cplusplus=1;
    }else if(cplusplus){
        if(strstr(line,"extern \"C\"")){
            inform(INF_INFO,"Inside function declaration zone...");
            functiondeclaration=1;
            // is: function declaration in headers
        }else if(line[0]=='}'){
            inform(INF_INFO,"Out of function declaration zone...");
            functiondeclaration=0;
        }
        cplusplus=0;
    }
    if(functiondeclaration){
        for(int i=0;i<killscount;i++){
            char *temp=strstr(line,kills[i].target);
            if(temp){
                if(temp>line){
                    temp--;
                    if(ischarvalid(temp[0]))continue;
                    temp++;
                }
                temp+=strlen(kills[i].target);
                if(temp<line+LINEMAX){
                    if(ischarvalid(temp[0]))continue;
                }
                temp-=strlen(kills[i].target);
            }else continue;
            kill=1;
            inform(INF_DEBUG,"%s found.",kills[i].target);
        }
    }
    if(kill)return 0;
    if(deletable){
        if(deleteflag)return 0;
    }
    memset(newline,0,LINEMAX);
    strcpy(newline,line);
    if(strlen(line)>3)replacetokens(newline);
    return 1;
}
int replacetokens(){
    char result[LINEMAX];
    if(result==NULL){
        inform(INF_FATAL,"Fatal error: Cannot allocate memory.");
        getch();
        exit(-1);
        return -1;
    }
    for(int i=0;i<tokenscount;i++){
        if(strstr(newline,tokens[i].rep)){
            tokens[i].found=1;
            continue;
        }
        if(strstr(newline,tokens[i].old)==NULL){
            continue;
        }
        memset(result,0,LINEMAX);
        char *temp;
        char *linepointer=newline;
        int offset=0;
        while(1){
            temp=strstr(linepointer+offset,tokens[i].old);
            if(temp==NULL)break;
            if(temp>newline){
                char *ttemp=temp-1;
                if(ttemp[0]!=' '&&ttemp[0]!='*'){
                    offset=temp-linepointer+1;
                    continue;
                }
                if(newline+strlen(newline)>temp+strlen(tokens[i].old)){
                    ttemp=temp+strlen(tokens[i].old);
                    if(ischarvalid(ttemp[0])){
                        offset=temp-linepointer+1;
                        continue;
                    }
                }
            }
            offset=0;
            int length=temp-linepointer;
            temp+=strlen(tokens[i].old);
            strncat(result,linepointer,length);
            strcat(result,tokens[i].rep);
            linepointer+=length+strlen(tokens[i].old);
            tokens[i].replaced++;
        }
        if(temp==NULL){
            strcat(result,linepointer);
        }
        memset(newline,0,LINEMAX);
        strcpy(newline,result);
    }
    return 1;
}
int processfile(const char *path){
    FILE *fp=fopen(path,"r");
    if(!fp){
        inform(INF_WARNING,"File \"%s\" does not exist.",path);
    }
    FILE *fnew=fopen("r2a_temp_c","w");
    char line[LINEMAX];
    memset(line,0,LINEMAX);
    memset(newline,0,LINEMAX);
    while(fgets(line,LINEMAX,fp)){
        processline(line);
//    printf("<");
        fputs(newline,fnew);
//    printf(">");
        memset(line,0,LINEMAX);
        memset(newline,0,LINEMAX);
    }
    fclose(fp);
    fclose(fnew);
    updatefile(path);
    return 0;
}
#endif // R2A_H
