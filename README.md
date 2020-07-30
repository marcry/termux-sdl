# termux-sdl

这是一个termux sdl插件，为编译运行SDL2和native app程序！

同时我把ffplay也添加了进来，因此它也可以作为一个本地播放器，ffplay目前实现了进度条，时间的显示，滑动屏幕左边控制亮度，右边控制音量，进度条的实现是通过SDL2_gfx进行绘制的，时间的显示是通过SDL2_ttf来绘制的

ffplay目前存在的bug，当以倍速进行播放时，拖动进度条，时间不准确，视频与音频不同步

###### ffplay播放：
```bash
# example/SDL2/ffplay/ffplay 是一个shell命令，并不是真正的二进制文件
cp example/SDL2/ffplay/ffplay /data/data/com.termux/files/usr/bin

# 播放视频
ffplay -i /sdcard/video/test.mp4

# 播放音乐 1.5倍速
ffplay -af atempo=1.5 -i /sdcard/music/hello.flac

# 2倍速度播放
ffplay -af atempo=2.0 -vf setpts=1/2*PTS -i /sdcard/video/test.mp4

# 任意倍速度播放：atempo=x setpts=1/x*PTS
......

```


### 如何使用：
解压examples/libs.zip文件，复制SDL库文件到/data/data/com.termux/files/usr/lib

解压examples/heades.zip文件，复制SDL头文件到/data/data/com.termux/files/usr/include


```
# 进入examples的示例代码下，执行 make run
# 比如...
cd /sdcard/termux-sdl/examples/SDL2/draw2
make run
```

 **** 

This is a termux sdl plugin for compiling and running SDL2 and native app programs!

 At the same time, I added ffplay, so it can also be used as a local player. ffplay currently implements a progress bar, time display, slide the screen to control the brightness on the left, and the right to control the volume. The progress bar is drawn by SDL2_gfx  , The time display is drawn by SDL2_ttf

 The current bug of ffplay, when playing at playback speed, drag the progress bar, the time is inaccurate, and the video and audio are not synchronized

###### ffplay playing:
```bash
# example/SDL2/ffplay/ffplay is a shell command, not a real binary file
cp example/SDL2/ffplay/ffplay /data/data/com.termux/files/usr/bin

# Play video
ffplay -i /sdcard/video/test.mp4

# play music whit 1.5x speed
ffplay -af atempo=1.5 -i /sdcard/music/hello.flac


# 2x speed playback
ffplay -af atempo=2.0 -vf setpts=1/2*PTS -i /sdcard/video/test.mp4

# play at any speed: atempo=x setpts=1/x*PTS
```



### How to use:
Extract the examples/libs.zip file and copy the SDL library file to /data/data/com.termux/files/usr/lib

Extract the examples/headers.zip file and copy the SDL header file to /data/data/com.termux/files/usr/include


```
# Enter the demo code under examples and execute make run
# for example
cd /sdcard/termux-sdl/examples/SDL2/draw2
make run
```

##### app [download](https://github.com/Lzhiyong/termux-sdl/releases)


 **** 

## Screenshots

<a href="./screenshots/screenshot1.jpg"><img src="./screenshots/screenshot1.jpg" width="30%" /></a>
<a href="./screenshots/screenshot2.jpg"><img src="./screenshots/screenshot2.jpg" width="30%" /></a>
<a href="./screenshots/screenshot3.jpg"><img src="./screenshots/screenshot3.jpg" width="30%" /></a>
<a href="./screenshots/screenshot4.jpg"><img src="./screenshots/screenshot4.jpg" width="30%" /></a>
<a href="./screenshots/screenshot5.jpg"><img src="./screenshots/screenshot5.jpg" width="30%" /></a>
<a href="./screenshots/screenshot6.jpg"><img src="./screenshots/screenshot6.jpg" width="30%" /></a>

 **** 
 
 <a href="./screenshots/screenshot7.jpg"><img src="./screenshots/screenshot7.jpg" width="50%" /></a>
 
## How to use SDL_AndroidLogPrint function

 ```c

#include "SDL2/SDL.h"

// define log tag
#define TAG "HELLO_WORLD" 

#define WIDTH 640;
#define HEIGHT 480;

SDL_Window* window = NULL;
SDL_Renderer* render = NULL;
SDL_Texture* texture = NULL;
 
bool sdl_init()
{
	window = SDL_CreateWindow("SDL Hello World",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
		SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
	    // show error log in java program
		SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat window error");
		return false;
	}
	render = SDL_CreateRenderer(window, -1, 0);
	if (render == NULL)
	{
		SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat render error");
		return false;
	}
	return true;
}
 
bool load_image()
{
	SDL_Surface* surface = NULL;
	hello = SDL_LoadBMP("hello.bmp");
	if (surface == NULL)
	{
		SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "load bmp error");
		return false;
	}
	tex = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	if (texture == NULL)
	{
		SDL_AndroidLogPrint(LOG_ERROR, TAG, "%s\n", "creat surface texture error");
		return false;
	}
	return true;
}
 
bool display_image()
{
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderPresent(render);
	SDL_Delay(3000);
	return true;
}
 
void quit()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_DestroyTexture(texture);
	SDL_Quit();
}
 
int main(int argc, char *args[])
{
    // show log info in java program
    SDL_AndroidLogPrint(LOG_INFO, TAG, "%s\n", "Hello World!");
	
	if (sdl_init())
	{
		if(load_image()) display_image();
		quit();
	}
	return 0;
}
```

