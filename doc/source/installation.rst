Installation
============

An installation of g++ and an installation of the curses library is required.
The installation of make is optional, it makes the building easier.

.. code-block::
   
   sudo apt install git g++ make libncurses5-dev libncursesw5-dev

- Download the repository

.. code-block::

   git clone https://guthub.com/Guenther1978/connect_four

   
Instead of cloning the repository with *git clone* it can be downloaded as a zip archive.

- Go inside the *src* folder

.. code-block::

   cd connect_four/src/

   
- Compiling and linking the code

.. code-block::

   make


- Start the game

.. code-block::

   ./connect_four
