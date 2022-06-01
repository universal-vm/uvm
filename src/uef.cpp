#include "./uef.h"

bool check_uef(char *CONTENTS)
{
    if(CONTENTS[0] == 'U' && CONTENTS[1] == 'E' && CONTENTS[2] == 'F' && CONTENTS[3] == 0xFF)
    {
        return true;
    }
    else
    {
        return false;
    }
}