/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
//17. �绰�������ĸ���

//ʹ��malloc��������ռ䣬returnSize���ڷ����ַ������С��
//Ӧ�����������������߽��ˣ������ڴ����������
 
//δͨ�� 

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char Char(char ch,int it)
{
    switch (ch)
    {
        case '2':
        {
            switch (it)
            {
                case 0: return 'a';
                case 1: return 'b';
                case 2: return 'c';
            }
        }
        case '3':
        {    
            switch (it)
            {
                case 0: return 'd';
                case 1: return 'e';
                case 2: return 'f';
            }
        }
        case '4':
        {
            switch (it)
            {
                case 0: return 'g';
                case 1: return 'h';
                case 2: return 'i';
            }
        }
        case '5':
        {    
            switch (it)
            {
                case 0: return 'j';
                case 1: return 'k';
                case 2: return 'l';
            }
        }
        case '6':
        {
            switch (it)
            {
                case 0: return 'm';
                case 1: return 'n';
                case 2: return 'o';
            }
        }
        case '7':
        {    
            switch (it)
            {
                case 0: return 'p';
                case 1: return 'q';
                case 2: return 'r';
                case 3: return 's';
            }
        }
        case '8':
        {
            switch (it)
            {
                case 0: return 't';
                case 1: return 'u';
                case 2: return 'v';
            }
        }
        case '9':
        {    
            switch (it)
            {
                case 0: return 'w';
                case 1: return 'x';
                case 2: return 'y';
                case 3: return 'z';
            }
        }
    }
    return '1';
} 

char** letterCombinations(char* digits, int* returnSize) {
	int j,z;
    int i,num=1,numr=1,numt;
    
    char **at=(char**)malloc(sizeof(char*)*1000);
    for(i=0;i<1000;i++)
    {
        at[i]=(char*)malloc(sizeof(char)*20);
        memset(at[i],0,sizeof(char)*20);  //��ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ.
    }
    
    for(i=0;digits[i]!='\0';i++)
    {
        if(digits[i]=='9'||digits[i]=='7')
            numr*=4;
        else
            numr*=3;
    }
    numt=i;
    *returnSize=numr;
    
    for(i=0;digits[i]!='\0';i++)
    {
        
        if(digits[i]!='9'&&digits[i-1]!='7')
            numr/=3;//��ѭ��
        else
            numr/=4;
        if(digits[i]=='9'||digits[i]=='7')
            num*=4;//��ѭ��
        else
            num*=3;
        for(j=0;j<num;j++)
        {
            for(z=j*numr;z<(j+1)*numr;z++)
            {
                if(digits[i]!='7'&&digits[i]!='9')
                	at[z][i]=Char(digits[i],j%3);
                else
                	at[z][i]=Char(digits[i],j%4);
            }
        }
        
    }
    
    for(i=0;i<numr;i++)
    {
        at[i][numt]='\0';
    }
    
    return at;
}


int main()
{
	char **p;
	char digits[10]="72356";
	int returnSize; 
	int i;
	p=letterCombinations(digits, &returnSize);
	
	for(i=0;i<returnSize;i++)
		printf("%s:",p[i]);
	
	return 0;
}




