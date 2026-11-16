#include  <string_view>
 namespace Color{
    constexpr std::string_view BLACK      = "\033[30m";
    constexpr std::string_view RED        = "\033[31m";
    constexpr std::string_view GREEN      = "\033[32m";
    constexpr std::string_view YELLOW     = "\033[33m";
    constexpr std::string_view BLUE       = "\033[34m";
    constexpr std::string_view MAGENTA    = "\033[35m";
    constexpr std::string_view CYAN       = "\033[36m";
    constexpr std::string_view WHITE      = "\033[37m";
    constexpr std::string_view RESET      = "\033[0m"; 

inline std::string_view toOneColorName(std::string_view colorName){
std::string lowerColor="";

for (int i=0 ;colorName[i]!='\0';i++){
   char c=colorName[i];
    if(c>='A' && c<='Z'){
        c+=32;
    }
            lowerColor+=c;

}

    if(lowerColor=="black") return BLACK;
    if(lowerColor=="red") return RED;
    if(lowerColor=="green") return GREEN;
    if(lowerColor=="yellow") return YELLOW;
    if(lowerColor=="blue") return BLUE;
    if(lowerColor=="magenta") return MAGENTA;
    if(lowerColor=="cyan") return CYAN;
    if(lowerColor=="white") return WHITE;
   return "";
}
    
    
 }