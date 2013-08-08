## Change whatever can be changed with sexkbmap cos xmodmap is a buggy beast!
## Look in /usr/X11R6/share/X11/xkb/rules/base.lst for more kbdhax

setxkbmap gb -option 'caps:swapescape,lv3:ralt_alt'

## Create a right alt key from whatever there be there!
## Check xmodmap -pke for all available. Can pipe to .xmodmaprc

if [ $(hostname) = "puffy.bsd.cs" ] || [ $(hostname) = "fugu.swn.hse" ]; then
	xmodmap -e "keysym Menu = Control_R"
elif [ $(hostname) = "paddy.bsd.cs" ] || [ $(hostname) = "crispian.swn.hse" ]; then
	xmodmap -e "keysym Print = Super_R"
        # Change ThinkPad nipple settings - xinput list-prop /dev/wsmouse for more
        xinput set-prop /dev/wsmouse "WS Pointer Wheel Emulation Button" 3
        xinput set-prop /dev/wsmouse "WS Pointer Wheel Emulation" 1
        # Turn touchPad off if your feeling particulary hardcore!
        # synclient TouchpadOff=1
fi


## Set kbd rate, screentime out and background
xset r rate 345 53 s 80 dpms 100 111 120
#feh --bg-fill /home/toby/img/wallpapers/bsd/think-securely-black.png

## Start apps and wm of choice

eval "$(gpg-agent --daemon)"
#xclock -geometry 50x50-1+1 &
#xconsole -iconic &
xterm -maximize -e tmux attach &
/usr/X11R6/bin/cwm
#/home/toby/cfg/x11/ttwm/ttwm
#fvwm || xterm
