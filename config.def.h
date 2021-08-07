/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "alacritty"
#define TERMCLASS "Alacritty"

/* appearance */
static const unsigned int borderpx      = 1;        /* border pixel of windows */
static const unsigned int snap          = 32;       /* snap pixel */
static const unsigned int gappih        = 23;       /* horiz inner gap between windows */
static const unsigned int gappiv        = 23;       /* vert inner gap between windows */
static const unsigned int gappoh        = 23;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov        = 23;       /* vert outer gap between windows and screen edge */
static       int smartgaps              = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating        = 0;        /* 1 means swallow floating windows by default */
static const int showbar                = 1;        /* 0 means no bar */
static const int topbar                 = 1;        /* 0 means bottom bar */
static const char *fonts[]              = { "Iosevka Extended:size=11", "FuraCode Nerd Font:size=11" };
static const char *brupcmd[]            = { "brightnessctl", "set", "10%+", NULL };
static const char *brdowncmd[]          = { "brightnessctl", "set", "10%-", NULL };
static const char *upvol[]              = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",     NULL };
static const char *downvol[]            = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",     NULL };
static const char *mutevol[]            = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle",  NULL };
static const char *upvol[]              = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",     NULL };
static const char *downvol[]            = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",     NULL };
static const char *mutevol[]            = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle",  NULL };
static const char col_gray1[]           = "#05060b";
static const char col_gray2[]           = "#D8DEE9";
static const char col_gray3[]           = "#bbbbbb";
static const char col_gray4[]           = "#eeeeee";
static const char col_cyan[]            = "#66cccc";
static const unsigned int baralpha     = 0xd0;
static const unsigned int borderalpha  = OPAQUE;
static const char *colors[][3]          = {
 	/*               fg         bg         border   */
 	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
 	[SchemeSel]  = { col_cyan, col_gray1,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
  [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",          NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Alacritty",     NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,            NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "./patches/vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "alacritty", NULL };
static const char *webcmd[]  = { "brave", NULL };

#include <X11/XF86keysym.h>
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          SHCMD("dmenu_run -c -l 10 -g 3") },
	{ MODKEY,			                  XK_p,      spawn,		       SHCMD("feh --bg-fill --randomize ~/pics/wallpaper/* &") },
	{ MODKEY,			                  XK_r,      spawn,		       SHCMD(TERMINAL " -e ranger") },
	{ MODKEY,			                  XK_m,      spawn,		       SHCMD(TERMINAL " -e neomutt") },
	{ MODKEY,			                  XK_y,      spawn,		       SHCMD("flameshot gui -p ~/pics/screenshots") },
	{ MODKEY|ShiftMask,			        XK_y,      spawn,		       SHCMD("flameshot full -p ~/pics/screenshots") },
	{ MODKEY|ShiftMask,			        XK_v,      spawn,		       SHCMD("mpv /dev/video0") },
	{ MODKEY,			                  XK_w,      spawn,		       {.v = webcmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|Mod4Mask,              XK_x,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_z,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_g,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_g,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, //tile
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} }, //monocle
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[11]} }, //centeredmaster
	{ MODKEY|ShiftMask,             XK_c,      setlayout,      {.v = &layouts[12]} }, //centeredfloatingmaster
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,		        XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ 0,                            XK_F11,    spawn,          {.v = downvol } },
	{ 0,                            XK_F9,     spawn,          {.v = mutevol } },
	{ 0,                            XK_F12,    spawn,          {.v = upvol   } },
  { 0,                            XF86XK_MonBrightnessUp,   spawn, {.v = brupcmd}},
  { 0,                            XF86XK_MonBrightnessDown, spawn, {.v = brdowncmd}},
	{ 0,                            XF86XK_AudioLowerVolume,  spawn, {.v = downvol } },
	{ 0,                            XF86XK_AudioMute,         spawn, {.v = mutevol } },
	{ 0,                            XF86XK_AudioRaiseVolume,  spawn, {.v = upvol   } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

