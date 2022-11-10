#!/bin/bash

gcc -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 basic-tutorial-1.c -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -o basic-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`

