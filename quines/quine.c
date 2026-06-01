#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* helper(char* quine) {
int length=(int)strlen(quine)*2;
char* s=(char*)malloc(length);
strcpy(s,quine);
for (int i =0; i < strlen(s); i++) {
if (*(s+i)=='\"') {
for (int j=(int)strlen(s); j>i; j--) {
*(s+j)=*(s+j-1);
}
*(s+i)='\\';
i+=1;
}
if (*(s+i)=='\n'){
for (int j=(int)strlen(s); j>i; j--) {
*(s+j)=*(s+j-1);
}
*(s+i)='\\';
*(s+i+1)='n';
i+=1;
}
if (*(s+i)=='\\') {
for (int j=(int)strlen(s); j>i; j--) {
*(s+j)=*(s+j-1);
}
*(s+i)='\\';
i+=1;
}
}
return s;
}
int main(){
char quine[1000]="printf(\"#include <stdio.h>\\n#include <stdlib.h>\\n#include <string.h>\\nchar* helper(char* quine) {\\nint length=(int)strlen(quine)*2;\\nchar* s=(char*)malloc(length);\\nstrcpy(s,quine);\\nfor (int i =0; i < strlen(s); i++) {\\nif (*(s+i)=='\\\\\\\"') {\\nfor (int j=(int)strlen(s); j>i; j--) {\\n*(s+j)=*(s+j-1);\\n}\\n*(s+i)='\\\\\\\\';\\ni+=1;\\n}\\nif (*(s+i)=='\\\\n'){\\nfor (int j=(int)strlen(s); j>i; j--) {\\n*(s+j)=*(s+j-1);\\n}\\n*(s+i)='\\\\\\\\';\\n*(s+i+1)='n';\\ni+=1;\\n}\\nif (*(s+i)=='\\\\\\\\') {\\nfor (int j=(int)strlen(s); j>i; j--) {\\n*(s+j)=*(s+j-1);\\n}\\n*(s+i)='\\\\\\\\';\\ni+=1;\\n}\\n}\\nreturn s;\\n}\\nint main(){\\nchar quine[1000]=\\\"%s\\\";\\n%s\\n}\",helper(quine),quine);";
printf("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nchar* helper(char* quine) {\nint length=(int)strlen(quine)*2;\nchar* s=(char*)malloc(length);\nstrcpy(s,quine);\nfor (int i =0; i < strlen(s); i++) {\nif (*(s+i)=='\\\"') {\nfor (int j=(int)strlen(s); j>i; j--) {\n*(s+j)=*(s+j-1);\n}\n*(s+i)='\\\\';\ni+=1;\n}\nif (*(s+i)=='\\n'){\nfor (int j=(int)strlen(s); j>i; j--) {\n*(s+j)=*(s+j-1);\n}\n*(s+i)='\\\\';\n*(s+i+1)='n';\ni+=1;\n}\nif (*(s+i)=='\\\\') {\nfor (int j=(int)strlen(s); j>i; j--) {\n*(s+j)=*(s+j-1);\n}\n*(s+i)='\\\\';\ni+=1;\n}\n}\nreturn s;\n}\nint main(){\nchar quine[1000]=\"%s\";\n%s\n}",helper(quine),quine);
}