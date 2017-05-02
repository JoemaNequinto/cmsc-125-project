#!/bin/bash
cd contrib/8puzzle &&
sudo make &&
sudo make install &&

cd ../.. &&
sudo make clean &&
sudo make &&
sudo make install &&

qemu-system-x86_64 -fda ics-os-floppy.img