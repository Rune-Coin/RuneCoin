runecoin
=====================

Copyright (c) 2017 runecoin Developers


Running
---------------------
The following are some helpful notes on how to run runecoin on your native platform.

### Unix

You need the Qt4 run-time libraries to run runecoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/runecoin-qt (GUI, 32-bit) or bin/32/runecoind (headless, 32-bit)
- bin/64/runecoin-qt (GUI, 64-bit) or bin/64/runecoind (headless, 64-bit)

### Windows

Unpack the files into a directory, and then run runecoin-qt.exe.

### OSX

Drag runecoin-Qt to your applications folder, and then run runecoin-Qt.

Building
---------------------
The following are developer notes on how to build runecoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------

- [Coding Guidelines](coding.md)

### Miscellaneous
- [Files](files.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
