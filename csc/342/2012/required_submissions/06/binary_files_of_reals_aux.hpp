//binary_file_of_reals_aux.hpp

void DisplayProgramInfo()
{
    cout << "This program allows the user to perform some activities "
        "with a binary file of\nreals. The program can only work with "
        "one file at a time. When the program\nstarts, it may be used to "
        "create such a file at that time, or the user may opt\nto open a "
        "pre-existing file. During any given run, the current file may be "
        "\nclosed and another opened or created."

        "\n\nThe program currently does no error checking, so if the user "
        "attempts something\nthat doesn't \"make sense\" for the current "
        "file or for the current position in\nthe file, the outcome may "
        "be unpredictable."

        "\n\n- Option 1 is the usual Quit option."
        "\n\n- Option 2 displays the information you are now reading."
        "\n\n- Option 3 creates a new empty binary file of reals with "
        "a user-chosen name."
        "\n\n- Option 4 opens an already existing binary file of reals."
        "\n\n- Option 5 displays the current values of the following "
        "stream functions:"
        "\n  is_open()\n  good(), bad(), fail(), eof()\n  tellg(), "
        "tellp(), gcount()\n\n";
    Pause();
    cout << "- Option 6 allows the user to move to a specific position "
        "in the file to\n  perform a subsequent action (reading or "
        "writing a value, for example).\n  That position may be the "
        "beginning or end of the file, a particular numbered\n  position "
        "in the file, or a new position relative to the current position."
        "\n\n- Option 7 writes reals entered by the user to the file, "
        "starting at\n  the current location."
        "\n\n- Option 8 displays a user-chosen number of reals, one per "
        "line, starting\n  at the beginning of the file."
        "\n\n- Option 9 displays all real values stored in the file, "
        "one per line."
        "\n\n- Option 10 displays real values from the file, "
        "one per line, starting from\n  the current location."
        "\n\n- Option 11 closes the current file (after which a new one "
        "may be opened,\n  or created, during the same run)."
        "\n\n\n\n\n\n";
}


void AddOptionsToMenu
(
    Menu& m //inout
)
{
    m.addOption("Quit");
    m.addOption("Get information");
    m.addOption("Create an empty binary file of reals and "
        "leave it open");
    m.addOption("Open an already existing binary file of reals");
    m.addOption("Display current status of the binary file");
    m.addOption("Move to an absolute or relative position in the "
        "binary file");
    m.addOption("Copy one or more reals from the keyboard to the "
        "binary file");
    m.addOption("Copy one or more reals from start of binary file "
        "to the screen");
    m.addOption("Copy all reals from the binary file to the "
        "screen");
    m.addOption("Copy reals from file to screen, starting from the "
        "current location");
    m.addOption("Close the binary file");
}
