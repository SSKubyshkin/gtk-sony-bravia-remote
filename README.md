# GTK+ Sony BRAVIA Remote

A simple GTK+ application to control Sony BRAVIA Smart TV. I'm developing this app for my dad who's having constant issues with his existing software remote.

This is also my very first GTK+/C project!

## Features

The current version provides you with basic features such as:
* Volume control;
* TV channel switching;
* Up, down, right, left arrows;
* "HOME", "RETURN", "OK" buttons;
* Num keys (0-9).

## Usage

### Clone the repository:

`git clone https://github.com/SSKubyshkin/gtk-sony-bravia-remote.git`

or simply download the code in a zip archive.

### CD into the folder

`cd gtk-sony-bravia-remote`

### Compile the binary:

`` gcc -o bravia-remote bravia-remote.c `pkg-config --cflags --libs gtk4` ``

### Launch the application:

`./bravia-remote`
