#ifndef _ANSI_COLORS_H_

//
// ------- Color ANSI codes ---------
//
#define ANSI_NOCOLOR "\033[0m"
// Foreground normal intesity
#define ANSI_BLACK "\033[0;30m"
#define ANSI_RED  "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_GOLD  "\033[0;33m"
#define ANSI_BLUE "\033[0;34m"
#define ANSI_MAGENTA "\033[0;35m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_WHITE  "\033[0;37m"
// Foreground high intensity
#define ANSI_BRBLACK "\033[0;90m"
#define ANSI_BRRED  "\033[0;91m"
#define ANSI_BRGREEN "\033[0;92m"
#define ANSI_BRGOLD  "\033[0;93m"
#define ANSI_BRBLUE "\033[0;94m"
#define ANSI_BRMAGENTA "\033[0;95m"
#define ANSI_BRCYAN "\033[0;96m"
#define ANSI_BRWHITE  "\033[0;97m"
// Foreground RGB
#define ANSI_RGB "\033[38;2;%u;%u;%um"
// Foregroun CUSTOM
#define ANSI_SUN "\033[38;2;255;255;0m"
// Background
#define ANSI_BLACK_BG "\033[0;40m"
#define ANSI_BLUE_BG "\033[0;44m"
#define ANSI_GREEN_BG "\033[0;42m"
#define ANSI_CYAN_BG "\033[0;46m"
#define ANSI_RED_BG  "\033[0;41m"
#define ANSI_GOLD_BG  "\033[0;43m"
#define ANSI_GRAY_BG  "\033[0;47m"
#define ANSI_RGB_BG "\033[48;2;%u;%u;%um"

#endif // _ANSI_COLORS_H_
