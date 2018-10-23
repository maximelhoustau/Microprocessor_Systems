#!/bin/sh
stty -F /dev/cu.usbmodem1421 38400 raw -echo -echoe -echok -crtscts clocal
