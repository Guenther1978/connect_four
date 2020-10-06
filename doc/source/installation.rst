Installation of the game
========================

- Intallation of required software and libraries

  - g++: The source code is written in C++, so this compiler is used instead of gcc.

  - curses: This library is used for the graphics.

  - make: Optional, it makes the building process easier.

  - git: Optional, can be used for downloading the whole repository.
    
.. code-block::
   
   sudo apt install git g++ make libncurses5-dev libncursesw5-dev

- Download the repository

.. code-block::

   git clone https://github.com/Guenther1978/connect_four

   
Instead of cloning this repository with *git clone* it can be downloaded as a zip archive.

- Go inside the src folder

.. code-block::

   cd connect_four/src/

   
- Compiling and linking the code

.. code-block::

   make


- Start the game

.. code-block::

   ./connect_four
