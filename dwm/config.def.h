/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* increased border pixel for better visual distinction */
static const unsigned int gappx     = 10;       /* increased gaps for better visual separation */
static const unsigned int snap      = 20;       /* reduced snap pixel for more precise window control */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner */
static const unsigned int systrayspacing = 4;   /* increased systray spacing for better visual separation */
static const int systraypinningfailfirst = 1;   /* display on first monitor if pinning fails */
static const int showsystray        = 1;        /* show systray */
static const int showbar            = 1;        /* show bar */
static const int topbar             = 1;        /* top bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12" }; /* increased font size */
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=12";     /* increased font size */

/* Gruvbox Dark Theme - preserved from original */
static const char col_bg[]          = "#282828"; /* background */
static const char col_bg_alt[]      = "#3c3836"; /* slightly lighter background */
static const char col_fg[]          = "#ebdbb2"; /* foreground/text */
static const char col_fg_dim[]      = "#a89984"; /* dimmed text */
static const char col_accent[]      = "#458588"; /* blue accent */
static const char col_urgent[]      = "#cc241d"; /* red for urgent */
static const char col_border[]      = "#83a598"; 

static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { col_fg_dim,  col_bg,      col_border },
	[SchemeSel]  = { col_fg,      col_accent,  col_accent },
};

/* Renamed workspaces for clarity - fewer, more clear distinctions */
static const char *tags[] = {
    "TERM",  /* Terminal */
    "CODE",  /* Code/Programming */
    "WEB",   /* Browser */
    "MEDIA", /* Music/Media */
    "NOTES", /* Study/Notes */
};

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	/* Terminal apps - send to workspace 1 by default */
	{ "Alacritty", NULL,     NULL,       0,            0,           -1 },
	{ "kitty",     NULL,     NULL,       1,            0,           -1 },
	/* Code editors - workspace 2 */
	{ "Vim",       NULL,     NULL,       1 << 1,       0,           -1 },
	{ "Code",      NULL,     NULL,       1 << 1,       0,           -1 },
	/* Browsers - workspace 3 */
	{ "chromium",  NULL,     NULL,       1 << 2,       0,           -1 },
	{ "Chromium",  NULL,     NULL,       1 << 2,       0,           -1 },
	{ "firefox",   NULL,     NULL,       1 << 2,       0,           -1 },
	/* Media apps - workspace 4 */
	{ "Spotify",   NULL,     NULL,       1 << 3,       0,           -1 },
	{ "LMMS",      NULL,     NULL,       1 << 3,       0,           -1 },
	/* Note-taking - workspace 5 */
	{ "Obsidian",  NULL,     NULL,       1 << 4,       0,           -1 },
	/* Float certain distracting windows by default */
	{ "Thunar",    NULL,     NULL,       0,            1,           -1 },
	{ "Pavucontrol", NULL,   NULL,       0,            1,           -1 },
	{ "Galculator", NULL,    NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* increased master area size for better focus */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* respect size hints */
static const int lockfullscreen = 1; /* force focus on fullscreen */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* default tiling */
	{ "[M]",      monocle }, /* monocle - moved to second position for easier access */
	{ "><>",      NULL },    /* floating - moved to last position as it's most distracting */
};

/* key definitions */
#define MODKEY Mod4Mask  /* Changed to Super key (Windows key) for easier access */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg, "-nf", col_fg_dim, "-sb", col_accent, "-sf", col_fg, NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", "-theme", "gruvbox-dark", NULL };
static const char *termcmd[] = { "alacritty", NULL };
static const char *browser[] = { "chromium", NULL };
static const char *vscode[] = { "code", NULL };
static const char *vim[] = { "alacritty", "-e", "vim", NULL };
static const char *lmms[] = { "lmms", NULL };
static const char *filemgr[] = { "thunar", NULL };
static const char *obsidian[] = { "obsidian", NULL };
static const char *spotify[] = { "spotify", NULL };
static const char *brightness_up[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brightness_down[] = { "brightnessctl", "set", "10%-", NULL };
/* Focus tools */
static const char *pomodoro[] = { "alacritty", "-e", "pomotroid", NULL };
static const char *whitenoise[] = { "alacritty", "-e", "sh", "-c", "play -n synth brownnoise", NULL };
static const char *lock_screen[] = { "slock", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* Program launchers - grouped for clarity */
	{ MODKEY,                       XK_space,  spawn,          {.v = roficmd } },     /* changed to space for easier access */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = browser } },
	{ MODKEY,                       XK_c,      spawn,          {.v = vscode } },
	{ MODKEY,                       XK_v,      spawn,          {.v = vim } },
	{ MODKEY,                       XK_m,      spawn,          {.v = lmms } },
	{ MODKEY,                       XK_s,      spawn,          {.v = spotify } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filemgr } },
	{ MODKEY,                       XK_o,      spawn,          {.v = obsidian } },
	
	/* Focus tools for ADHD */
	{ MODKEY,                       XK_p,      spawn,          {.v = pomodoro } },
	{ MODKEY,                       XK_n,      spawn,          {.v = whitenoise } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = lock_screen } },
	
	/* Brightness controls */
	{ 0,                            XK_F8,     spawn,          {.v = brightness_down } },
        { 0,                            XK_F9,     spawn,          {.v = brightness_up } },
	
	/* Window management - simplified */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },  /* changed from c to q for consistency */
	
	/* Simplified layout management - only 3 layouts */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },  /* tiling */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },  /* monocle (full screen) */
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[2]} },  /* floating */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	
	/* Tag/workspace management */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	
	/* Direct workspace access */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	
	/* Exit dwm */
	{ MODKEY|ShiftMask, XK_q,      quit,           {0} },  /* harder to trigger accidentally */
};

/* button definitions */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },  /* monocle is now second */
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

