concordance.txt
========================================
ProgramDescription
A concordance is a certain kind of list of the all words in a file. We will
display a concordance in the style shown below, which we shall refer to as
"movie credit" format, and in which each word appears right-justified within
a fieldwidth of 15 spaces.

      firstword 6 15 23
     secondword 2 7 8 10 11 14 15 16 19 20 21 33 45 129 147
                222 298 301
      thirdword 13 27
    ... and so on ...

All words are converted to lower case, and they appear in alphabetical order,
one per line. Each word is followed by the line numbers of all lines on which
that word occurs in the file, with a maximum of 15 such numbers per line.

In this context a "word" consists of any contiguous sequence of alphabetic
characters (no digits and no punctuation characters permitted). Also, the line
numbers on which any word appears are listed in increasing numerical order.

This program may take zero to three command-line parameters, and thus may be
used in any one of the following four ways:

                                                                  Screen 1 of 2
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
prompt> find_concordance.exe
This first way just displays the ID screen and this information. None of the
other options causes the ID screen and this information to be displayed.

In the next three usage examples, all command-line parameters are interpreted
as names of textfiles.

prompt> find_concordance.exe any_in.txt
In this case, any_in.txt is any input file of text. The program produces the
concordance for this file and displays it on the standard output.

prompt> find_concordance.exe any_in.txt cc_out.txt
In this case, the concordance for any_in.txt is sent to the output file
cc_out.txt instead of to the standard output.

prompt> find_concordance.exe any_in.txt cc_out.txt cc_other.txt
Finally, if the the third parameter (cc_other.txt) appears, the concordance for
any_in.txt is sent to cc_out.txt, as before, and then a list of the differences
between cc_out.txt and cc_other.txt is written to a file named differences.txt.

If any of the required files does not exist, the program simply terminates,
with an appropriate message.
                                                                  Screen 2 of 2
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
----------------------------------------
========================================
