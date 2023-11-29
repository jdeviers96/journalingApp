# journalApp:
A simple journaling app for logging timecoded actions throughout the day.

  * Daily logs are grouped into logfiles abiding by the following naming format: dd-mm-yyyy_logfile.dat. 
  * Logfiles are stored into the LGF_PATH directory, which defaults to /home/${USER}/.local/logs. A different path can be specified to CMake with the option -DLGF_PATH=<...>

## Usage:
To add a new log, simply run journalApp "<Your message here...>". 

  * journalApp must be in your path; by default, it is installed in /usr/bin. If the executable is not in your path, then providing the full to it still allows to execute it correctly, although doing it this way is annoying.
  * The log message must consist of a single-line string, enclosed in double quotes. Alphanumeric characters are allowed; I haven't checked yet if weird input breaks it.

## Further developments:

  * Check if weird input (special characters, single quotes, Unicode, escapes, ...) breaks behaviour.
  * Check whether inner, escaped double quotes in the input are allowed and correctly interpreted.
  * Add padding to the date and time format.
  * Allow to provide an installation path for the executable as well, and maybe the possibility to export its path.
  * Environment variables are expanded in the entries; e.g writing $PATH expands it. Escaping the dollar sign works but it's still unwanted behaviour.

