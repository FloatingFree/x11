/* copyright J.McClure 2012-2013, see alopex.c or COPYING for details */

static const char font[] =
	"-misc-*-*";
static const char *tile_modes[] =
	{"monocle", "rstack", "bstack", NULL};
static const Tagcon tagcons[] = {
	/* pre		icon		post */
	{ NULL,		20,			"one"},
	{ NULL,		21,			"two" },
	{ NULL,		22,			"three" },
};
static const char	alopex_cursor		= XC_left_ptr;
static const int	borderwidth			= 0;
static const int	tilegap				= 0;
static const int	tagspace			= 0;
static const int	max_status_line		= 256;
static const int	win_min				= 20;
static const Bool	focusfollowmouse	= False;
static Bool			showbar				= True;
static Bool			topbar				= True;
static int			tilebias			= 0;
static const int	attachmode			= 0;
static int			stackcount			= 2;

#define CMD(app)	app "&"
//#define WALLPAPER		"feh --bg-scale ~/images/bg.jpg"
#define KEY1 Mod4Mask
#define KEY2 Mod1Mask
#define KEY3 ControlMask
#define KEY4 ShiftMask
#define TagKey(KEY,TAG) \
	{ KEY2,				KEY,		tag,	"s " TAG }, \
	{ KEY1|KEY2,		KEY,		tag,	"t " TAG }, \
	{ KEY1|KEY3,		KEY,		tag,	"m " TAG }, \
	{ KEY1|KEY4,		KEY,		tag,	"a " TAG },

static Key keys[] = {
	/* modifier			key			function	argument */
	/* launchers + misc: */
	{ KEY1,				XK_r,		spawn,		CMD("dmenu_run -fn \"-misc-*-*\" -nb \"#101010\" -nf \"#484862\" -sb \"#080808\" -sf \"#FFDD0E\"")	},
	{ KEY2,				XK_F2,		spawn,		CMD("dmenu_run -fn \"-misc-*-*\" -nb \"#101010\" -nf \"#484862\" -sb \"#080808\" -sf \"#FFDD0E\"")	},
	{ KEY1,				XK_t,	    spawn,		CMD("urxvt -e tmux attach")	},
	{ KEY1,				XK_w,		spawn,		CMD("firefox")	},
	{ KEY2,				XK_F1,  	windowlist,	"interrobang alopex"},
	{ KEY2,				XK_F4,		killclient,	NULL			},
	{ KEY2,				XK_F10,		fullscreen,	NULL			},
	/* tiling:
		tile modes, increase/decrease master region size,
		increment or decrement (+/-) the number of stack clients,
		select for all or one ("ttwm tiling") stack clients */
	{ KEY2,				XK_space,	tile,		"cycle"			},
	{ KEY2,				XK_l,		tile_conf,	"increase"		},
	{ KEY2,				XK_h,		tile_conf,	"decrease"		},
    { KEY2,				XK_equal,	tile_conf,	"+"				},
    { KEY2,				XK_minus,  	tile_conf,	"-"				},
	{ KEY1,				XK_comma, 	tile_conf,	"all"			},
	{ KEY1,				XK_period, 	tile_conf,	"one"			},
	/* tagging:
		flip between alternate views, set tags */
	{ KEY1,				XK_Tab,		tag,		"flip"			},
		TagKey(			XK_1,					"1"		)
		TagKey(			XK_2,					"2"		)
		TagKey(			XK_3,					"3"		)
	/* window focus/movement:
		f=focus previous, next, or alternate  window in tag(s)
		s=swap window with previous, next, or alternate  window
		capital "Next" or "Prev" include floating windows
		+/- adjust a windows monitor number */
	{ KEY2,				XK_j,		window,		"f prev"		},
	{ KEY2,				XK_k,		window,		"f next"		},
	{ KEY1,	        	XK_j,		window,		"s prev"		},
	{ KEY1,     		XK_k,		window,		"s next"		},
	{ KEY2,				XK_Tab,		window,		"f alt"			},
	{ KEY2|KEY4,		XK_Tab,		window,		"s alt"			},
	{ KEY1,     		XK_equal,	window,		"+"				},
	{ KEY1,	        	XK_minus,	window,		"-"				},
};

static Button buttons[] = {
	/* modifier			button		function 	arg */
	{ KEY2,				1,			mouse,		"move"		},
	{ KEY2,				2,			toggle,		"floating"	},
	{ KEY2,				3,			mouse,		"resize"	},
	{ KEY2,				4,			window,		"s prev"	},
	{ KEY2,				5,			window,		"s next"	},
	{ KEY2,				6,			window,		"f prev"	},
	{ KEY2,				7,			window,		"f next"	},
};

static Rule rules[] = {
	/* name				class		tags		flags */
	/* tags/flags=0 means no change to default */
	{ NULL,				"float",	0,			FLAG_FLOATING },
	{ "float",			NULL,		0,			FLAG_FLOATING },
};

// vim: ts=4
