/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/* Gruvbox color palette */
#define BG          "#282828" /* Background */
#define FG          "#ebdbb2" /* Foreground */
#define BLACK       "#3c3836" /* Black */
#define RED         "#cc241d" /* Red */
#define GREEN       "#98971a" /* Green */
#define YELLOW      "#d79921" /* Yellow */
#define BLUE        "#458588" /* Blue */
#define MAGENTA     "#b16286" /* Magenta */
#define CYAN        "#689d6a" /* Cyan */
#define WHITE       "#a89984" /* White */
#define ORANGE      "#d65d0e" /* Orange */

static const struct arg args[] = {
    /* function format          argument */
    
    /* CPU with blue background - compact style */
    { cpu_perc, "^b"BLUE"^^c"BG"^ CPU ^c"FG"^%2s%% ^d^", NULL },
    
    /* RAM with yellow background */
    { ram_perc, "^b"YELLOW"^^c"BG"^ RAM ^c"FG"^%2s%% ^d^", NULL },
    
    /* WiFi with magenta background */
    { wifi_perc, "^b"MAGENTA"^^c"BG"^ SLR ^c"FG"^%2s%% ^d^", "wlan0" },
    
    /* Disk/Battery green section */
    { disk_free, "^b"GREEN"^^c"BG"^ D ^c"FG"^%s ^d^", "/" },
    
    /* Date with orange background */
    { datetime, "^b"ORANGE"^^c"BG"^ %s ^d^", "%a %d %b" },
    
    /* Time with orange background */
    { datetime, "^b"ORANGE"^^c"BG"^ %s ^d^", "%H:%M" },
    
    /* Add empty space for system tray padding */
    { run_command, "^f0^^c"BG"^ %s", "echo '     '" },
};
