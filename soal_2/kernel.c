int cursor = 0;
char color = 0x07;
int isRadiant = 0;
char radiantColor = 0x09;

void putInMemory(int segment, int address, char character);
int getChar();

void printChar(char c) {
    char print_col = color;
    int rem;
    
    /* Logika Radiant*/
    if (isRadiant && c != ' ' && c != '\n' && c != '\r' && c != '\b') {
        print_col = radiantColor;
        radiantColor++;
        if (radiantColor > 0x0F) radiantColor = 0x09;
    }

    if (c == '\n' || c == '\r') {
        /* Menghitung modulo 160 tanpa % */
        rem = cursor;
        while (rem >= 160) { rem -= 160; }
        cursor += (160 - rem);
    } else if (c == '\b') {
        if (cursor >= 2) {
            cursor -= 2;
            putInMemory(0xB800, cursor, ' ');
            putInMemory(0xB800, cursor + 1, 0x07);
        }
    } else {
        putInMemory(0xB800, cursor, c);
        putInMemory(0xB800, cursor + 1, print_col);
        cursor += 2;
    }
    
    if (cursor >= 4000) { cursor = 0; }
}

void printString(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        printChar(str[i]);
        i++;
    }
}

void newline() {
    printChar('\n');
}

void clearScreen() {
    int i;
    for (i = 0; i < 4000; i += 2) {
        putInMemory(0xB800, i, ' ');
        putInMemory(0xB800, i + 1, 0x07);
    }
    cursor = 0;
}

void readString(char* buf) {
    int i = 0;
    char c;
    while(1) {
        c = getChar();
        if (c == '\r' || c == '\n') { 
            buf[i] = '\0'; 
            break; 
        }
        else if (c == '\b') { 
            if (i > 0) { 
                i--; 
                printChar('\b'); 
            } 
        }
        else { 
            buf[i] = c; 
            i++; 
            printChar(c); 
        }
    }
}

int strcmp(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return 1;
        i++;
    }
    return (s1[i] == s2[i]) ? 0 : 1;
}

int startsWith(char* str, char* prefix) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (str[i] != prefix[i]) return 0;
        i++;
    }
    return 1;
}

int atoi(char* str) {
    int res = 0, i = 0, sign = 1;
    if (str[i] == '-') { 
        sign = -1; 
        i++; 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * sign;
}

void intToString(int n, char* str) {
    int j, temp_idx = 0;
    char temp[16];
    int is_neg = 0;
    int quotient, remainder;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    if (n < 0) {
        is_neg = 1;
        n = -n;
    }
    
    while (n > 0) {
        quotient = 0;
        remainder = n;
       
        while (remainder >= 10) {
            remainder -= 10;
            quotient++;
        }
        temp[temp_idx] = remainder + '0';
        temp_idx++;
        n = quotient;
    }

    if (is_neg) {
        temp[temp_idx] = '-';
        temp_idx++;
    }

    for (j = 0; j < temp_idx; j++) {
        str[j] = temp[temp_idx - 1 - j];
    }
    str[temp_idx] = '\0';
}

int factorial(int n) {
    int res = 1, i;
    if (n < 0) return 0; 
    for (i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

void printTriangle(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            printChar('*');
        }
        newline();
    }
}

void main() {
    char cmd[64];

    clearScreen();

    printString("Welcome to Assistant's Last Gift");
    newline();
    printString("type 'help'");
    newline();
    newline();

    while (1) {
        printString("> ");
        readString(cmd);
        newline();

        /* command */
        if (strcmp(cmd, "check") == 0) {
            printString("ok");
        
        } else if (strcmp(cmd, "clear") == 0) {
            clearScreen();
            continue;
            
        } else if (strcmp(cmd, "about") == 0) {
            printString("Final Challenge OS Project 2026");
            
        } else if (startsWith(cmd, "add ")) {
            int i = 4, a, b;
            char resStr[16];
            a = atoi(cmd + i);
            if (cmd[i] == '-') i++;
            while (cmd[i] >= '0' && cmd[i] <= '9') i++;
            while (cmd[i] == ' ') i++;
            b = atoi(cmd + i);
            intToString(a + b, resStr);
            printString(resStr);
            
        } else if (startsWith(cmd, "sub ")) {
            int i = 4, a, b;
            char resStr[16];
            a = atoi(cmd + i);
            if (cmd[i] == '-') i++;
            while (cmd[i] >= '0' && cmd[i] <= '9') i++;
            while (cmd[i] == ' ') i++;
            b = atoi(cmd + i);
            intToString(a - b, resStr);
            printString(resStr);
            
        } else if (startsWith(cmd, "fac ")) {
            int n = atoi(cmd + 4);
            char resStr[16];
            
            if (n < 0 || n > 7) {
                printString("know your limit little bro.");
            } else {
                intToString(factorial(n), resStr);
                printString(resStr);
            }
            
        } else if (startsWith(cmd, "triangle ")) {
            int n = atoi(cmd + 9);
            printTriangle(n);
            continue; 
            
        } else if (startsWith(cmd, "season ")) {
            char* name = cmd + 7;
            if (strcmp(name, "winter") == 0) {
                color = 0x0F; isRadiant = 0;
            } else if (strcmp(name, "spring") == 0) {
                color = 0x0A; isRadiant = 0;
            } else if (strcmp(name, "summer") == 0) {
                color = 0x0E; isRadiant = 0;
            } else if (strcmp(name, "fall") == 0) {
                color = 0x06; isRadiant = 0;
            } else if (strcmp(name, "radiant") == 0) {
                isRadiant = 1;
            } else {
                printString("unknown season");
                newline();
                continue;
            }
            printString("Season changed!");
            
        } else if (strcmp(cmd, "help") == 0) {
            printString("check add sub fac season triangle clear about");
            
        } else if (strcmp(cmd, "") != 0) {
            printString("Command not found");
        }

        newline();
    }
}
