#ifndef WORDLENGTH_H
#define WORDLENGTH_H




int string_length(char word1[]){
    int letter_count =0;
    for (int i=0; word1[i] != '\0'; i++) {
        letter_count++;
    }
    return letter_count;
}

void vowel_consonant(char word[], int &vow_count, int &cons_count) {
    vow_count =0, cons_count =0;
    for(int i=0; i<string_length(word); i++) {
        char ltr= word[i];
        if(ltr == 'a'||ltr == 'e'||ltr=='i'||ltr=='o'||ltr=='u'||ltr == 'A'||ltr == 'E'||ltr=='I'||ltr=='O'||ltr=='U') {
            vow_count++;
        } else {
            cons_count++;
        }
    }
}

void string_reverse(char word[]) {
    for (int i=0; i<string_length(word)/2; i++) {
        char temp;
        temp = word[i];
        word[i] = word[string_length(word) - i - 1];
        word[string_length(word) - i - 1] = temp;
    }
}

int string_compare(char string1[], char string2[]) {
    int com_val;
    if (string_length(string1) == string_length(string2)) {
        for (int i=0; i<string_length(string1); i++) {
            if (string1[i]==string2[i]) {
                com_val = 0;
            } 
        }
    } else if (string_length(string1) >string_length(string2)) {
            com_val = 1;
    } else {
        com_val = -1;
    }
        return com_val;
}

void to_upper(char word[]) {
    for (int i=0; i< string_length(word); i++) {
        if (word[i]>=97 && word[i]<=122) {
            word[i] -=32; 
        } 
    }
}

void to_lower(char word[]) {
    for (int i =0; i< string_length(word); i++) {
        if(word[i]>=65 && word[i]<=90) {
            word[i] +=32;
        }
    }
}

#endif
