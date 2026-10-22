/**
 * @file assets.c
 * @author Gavin O.
 * @brief Output for all the frequently used assets
 * @version 0.1
 * @date 2026-10-08
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "RPG_Assets.h"
#include <stdio.h>

// Function for when each enemy dies
int death(int type) {
    // If Mad Bunny
    if (type == 1) {
        assets(0);
        printf("Mad Bunny died\n");
        printf("=============\n");
    }
    // If Mad Bunny
    else if (type == 2) {
        assets(5);
        printf("Fire Wolf died\n");
        printf("=============\n");
    }
}

// Function for the image assets
int assets(int grab) {

    // Asset storage
    switch (grab) {
        // Bunny series
        // Mad Bunny (Dead)
        case 0:
            printf(" o( xwx)\n");
            printf("   \\/\\/\n");
            break;
        // Mad Bunny (Normal)
        case 1:
            printf("   /\\/\\\n");
            printf("  (owo )o\n");
            printf("=============\n");
            break;
        // Mad Bunny (Enraged)
        case 2:
            printf("   /\\ v /\\\n");
            printf("  (  owo  )o\n");
            printf("=============\n");
            break;
        // Flame Wolf (On Fire)
        case 3:
            printf("  ___/\\_____***    *\n");
            printf(" / /o      ***+*  *#*\n");
            printf(" \\/\\        *+*+* *+#*\n");
            printf("/\\/        **++#+**+#*\n");
            printf("\\___   _____*+##*+#*\n");
            printf("    | | | | |**###+*\n");
            printf("    <_| <_| <_**+**\n");
            break;
        // Flame Wolf (Normal)
        case 4:
            printf("  ___/\\_______     * \n");
            printf(" / /o         \\__*\\+\\*\n");
            printf(" \\/\\             \\/ /\n");
            printf("/\\/                /\n");
            printf("\\___   _____   ____|\n");
            printf("    | | | | | | | |\n");
            printf("    <_| <_| <_| <_|\n");
            break;
        case 5:
            printf("  ___/\\_______       \n");
            printf(" /  x         \\__ \\#\\\n");
            printf(" \\/\\             \\/ /\n");
            printf("/\\/                /\n");
            printf("\\___   _____   ____|\n");
            printf("    | | | | | | | |\n");
            printf("    <_| <_| <_| <_|\n");
            break;
        case 6:
            printf(" _____\n");
            printf("( o o )\n");
            printf(" -----\n");
            break;
        case 7:
            printf(" _____\n");
            printf("( o o )_____\n");
            printf(" -----( o o ) \n");
            printf("       -----\n");
            break;
        case 8:
            printf("       _____\n");
            printf(" _____(o o  )\n");
            printf("( o o )_____\n");
            printf(" -----( o o ) \n");
            printf("       -----\n");
            break;
    }

    return 0;
}
