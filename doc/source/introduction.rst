Introduction
============

This is the game *connect four*.


Building the executeable
------------------------

An installation of g++ and an installation of the curses library is required.
The installation of make is optional, it makes the building easier.

.. code-block::
   
   sudo apt install g++
   sudo apt install libncurses5-dev libncursesw5-dev
   sudo apt install make

# Download the repository

.. code-blocks::

   git clone https://guthub.com/Guenther1978/connect_four

Instead of using git the repository can be downloaded as a zip archive.

# Go inside the *src* folder

.. code-blocks::

   cd connect_four/src/

# Compiling and linking the code

.. code-blocks::

   make

Rules of the game
-----------------

# Choose if You want to play against the computer or against another
human beeing.
