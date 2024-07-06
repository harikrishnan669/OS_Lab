#!/bin/bash

echo "a) Operating System Information:"
echo "   - OS and Version:"
lsb_release -a
echo "   - Kernel Version:"
uname -r

echo "b) Available Shells:"
cat /etc/shells

echo "c) CPU Information:"
echo "   - Processor Type:"
cat /proc/cpuinfo | grep "model name" | uniq
echo "   - CPU Speed:"
cat /proc/cpuinfo | grep "cpu MHz" | uniq

echo "d) Memory Information:"
free -m

echo "e) Hard Disk Information:"
echo "   - Size of Hard Disk:"
df -h | grep -E "^/dev/sd|^/dev/nv|^/dev/hd"
echo "   - Cache Memory:"
sudo hdparm -I /dev/sda | grep -iE "buffer size|cache size"
echo "   - Model:"
sudo hdparm -I /dev/sda | grep -iE "model"

echo "f) File System (Mounted):"
df -Th
