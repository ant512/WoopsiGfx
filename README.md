WoopsiGfx
=========

WoopsiGfx is a C++ 2D graphics library for the Nintendo DS, derived from the
Woopsi GUI framework.  It allows the developer to create and manipulate bitmaps
using a comprehensive set of drawing tools.  It includes an extensible font
system for drawing text to bitmaps, and features support for packed monochrome
and 16-bit fonts out of the box.

WoopsiGfx can also be used to draw directly to the DS' VRAM.  This is useful
when the DS is in MODE_FB0 or MODE_5_2D.


Features
--------

  - Extensible font system that supports compressed proportional and fixed-width
    fonts (monochrome and 16-bit);
  - Animation class with support for variable framerates and standard/pingpong
    looping;
  - Bitmap class for 16-bit bitmap image manipulation;
  - BufferedBitmap class that can restore itself to a previous state, undoing
    drawing operations;
  - Graphics class providing clipped, DMA-accelerated drawing functions:
    - Pixels;
    - Lines;
    - Filled and unfilled rectangles;
    - Filled and unfilled ellipses;
    - XOR horizontal/vertical lines, pixels, rectangles and filled rectangles;
    - Bitmap blitting;
    - Bitmap blitting with transparent colour key;
    - Bitmap blitting in greyscale;
    - Flood fill;
    - Region scrolling;
    - Region copying;
    - Region dimming;
    - Region conversion to greyscale;
    - Text rendering.
  - Dynamic array container and iterator classes.
  - Object-orientated design for easy integration into other C++ software;
  - Simple API;
  - Unicode strings encoded with UTF-8;
  - Compatible with Woopsi font tools.


Requirements
------------

To compile the project you need devKitARM.


Installation
------------

Create a new directory called "libwoopsigfx" in your devkitPro directory.  In
Windows, for example, this would typically be "C:\devkitPro".  Copy the "icon",
"lib" and "include" directories from this archive into the new directory.  In
Windows, you will end up with the following directory structure:

    C:\devkitPro\libwoopsigfx\icon
    C:\devkitPro\libwoopsigfx\include
    C:\devkitPro\libwoopsigfx\lib

Once you've done installed WoopsiGfx, you can test the installation by trying to
compile the "simplepicture" example project in the "tests" folder of this
archive.  Open a shell, navigate to its directory, and type "make".  If this
successfully produces a ROM file then the installation worked.


Credits and Acknowledgements
---------------------------

  - Coding and design                                - Antony Dzeryn
  - Packed font classes                              - Jeff Laing
  - PALib independence                               - Steven Harrison
  - Unicode work                                     - Olivier Binda
  - Simian Zombie logo                               - John Clay


Links
-----

  - http://simianzombie.com                          - Development blog


Email
-----

Contact me at <ant@woopsi.org>.