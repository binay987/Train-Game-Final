#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include<windows.h>

int x = GetSystemMetrics(SM_CXSCREEN);
int y = GetSystemMetrics(SM_CYSCREEN);

const float aspect_ratio = float(y)/float(x);

const int video_width = int(float(x)*60/100);
const int video_height = int(float(video_width)*aspect_ratio + 100);

const int font_size = 50;
int train_speed = 200;

#endif