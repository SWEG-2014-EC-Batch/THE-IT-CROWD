//Question a) finding a string's length
int stringLength(char str[]){
   int lengthCounter=0,itretionCounter=0;
   while(1==1) {
    if(str[itretionCounter]!='\0'){
        lengthCounter++;
        itretionCounter++;
    }
    else{
        return lengthCounter;
        break;
    }
   }
}

//Question b) reversing the a string
void reverseString(char str[]){
    int length=stringLength(str);
    char reversingStr[length];
    for (int i=0;i<length; i++){
        reversingStr[i]=str[length-1-i];
    }
    for (int i=0;i<length;i++){
        str[i]=reversingStr[i];
    }
}

//Comparing if 2 strings is are the same(returning 1 if so) or not(returning 0 in that case)
int compareString(char str1[], char str2[]){
    int checker;
    if(stringLength(str1)==stringLength(str2)){
            for (int i=0; i<stringLength(str1); i++){
                if(str1[i]==str2[i]){
                    checker=1;
                }
                else{
                    checker=0;
                }
            }
    }
    else{
        checker=0;
    }
    return checker;
}

//Question c)Comparing if the first string length is greater than second string
int compareStrLength(char str1[], char str2[]){
    if(stringLength(str1)==stringLength(str2)){
        return 0;
    }
    else if(stringLength(str1)>stringLength(str2)){
        return 1;
    }
    else{
        return -1;
    }
}

//Question d)Comparing changing all string elements to uppercase
void makeUpper(char str[]){
    int length = stringLength(str);
    for(int i=0;i<length;i++){
        if((int)str[i]<=123&&(int)str[i]>=97&&str[i]!=' '&&str[i]!='!'&&str[i]!='.'&&str[i]!=','){
            str[i]=(char)((int)str[i]-32);
        }
    }
}

//Question d)Comparing changing all string elements to uppercase
void makeSmall(char str[]){
    int length = stringLength(str);
    for(int i=0;i<length;i++){
        if((int)str[i]<=91&&(int)str[i]>=26&&str[i]!=' '&&str[i]!='!'&&str[i]!='.'&&str[i]!=','){
            str[i]=(char)((int)str[i]+32);
        }
    }
}


