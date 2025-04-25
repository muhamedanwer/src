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
    
    /* CPU with blue color and icon */
    { cpu_perc, "^c"BLUE"^ 󰻠 CPU %2s%% ^c"FG"^│ ", NULL },
    
    /* RAM with yellow color and icon */
    { ram_perc, "^c"YELLOW"^ 󰍛 RAM %2s%% ^c"FG"^│ ", NULL },
    
    /* WiFi with magenta color and icon */
    { wifi_perc, "^c"MAGENTA"^ 󰖩 WiFi %2s%% ^c"FG"^│ ", "wlan0" },
    
    /* Disk with green color and icon */
    { disk_free, "^c"GREEN"^ 󰋊 %s ^c"FG"^│ ", "/" },
    
    /* Date with orange color and icon */
    { datetime, "^c"ORANGE"^ 󰃭 %s ^c"FG"^│ ", "%a %d %b" },
    
    /* Time with cyan color and icon */
    { datetime, "^c"CYAN"^ 󱑆 %s ^c"FG"^", "%H:%M" },
    
    /* Add empty space for system tray padding */
    { run_command, " %s", "echo '     '" },
};
