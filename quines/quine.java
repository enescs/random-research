public class quine{
public static void main(String[] args){
String quine="System.out.println(\"public class quine{\\npublic static void main(String[] args){\\nString quine=\\\"\"+helper(quine)+\"\\\";\\n\"+quine+\"\\n}\\npublic static String helper(String a){\\nfor(int i =0;i<a.length();i++){\\nif(a.charAt(i)=='\\\"'||(a.charAt(i)=='\\\\\\\\')){\\na=a.substring(0, i)+\\\"\\\\\\\\\\\"+a.substring(i);\\ni++;\\n}\\n}\\nreturn a;\\n}\\n}\");";
System.out.println("public class quine{\npublic static void main(String[] args){\nString quine=\""+helper(quine)+"\";\n"+quine+"\n}\npublic static String helper(String a){\nfor(int i =0;i<a.length();i++){\nif(a.charAt(i)=='\"'||(a.charAt(i)=='\\\\')){\na=a.substring(0, i)+\"\\\\\"+a.substring(i);\ni++;\n}\n}\nreturn a;\n}\n}");
}
public static String helper(String a){
for(int i =0;i<a.length();i++){
if(a.charAt(i)=='"'||(a.charAt(i)=='\\')){
a=a.substring(0, i)+"\\"+a.substring(i);
i++;
}
}
return a;
}
}