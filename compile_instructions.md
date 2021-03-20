First you will need to reset the keyboard with ```Fn+Esc``` then do

```
make kbdfans/kbd75/rev1:eb:dfu
```
## Docker Build

Build the firmware with the docker container

```
docker run --rm -it --privileged -v /dev:/dev \
	-w /qmk_firmware \
	-v "`pwd`":/qmk_firmware \
	qmkfm/base_container \
	make kbdfans/kbd75/rev1:eb
```

then use qmk toolbox to load the new firmware to the keyboard. Use this local
file `/Volumes/Data/Projects/qmk_firmware/.build/kbdfans_kbd75_rev1_eb.hex`.
