#ifndef OBJECTORIENTEDPROGRAM_H
#define OBJECTORIENTEDPROGRAM_H
#include <iostream>

class OOPS{
    private :
        int userValue;
    public:
        OOPS(){}
        OOPS(int userValue):userValue{userValue} {}
        friend void openUserNeededStudyMaterial(OOPS &);
};

void openUserNeededStudyMaterial(OOPS &);

#endif // OBJECTORIENTEDPROGRAM_H
