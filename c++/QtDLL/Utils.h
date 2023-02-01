#ifndef UTILS_H
#define UTILS_H

#include <functional>

class Utils
{
public:
    Utils();
    template<class RESULT, class CONSTRUCTOR>
    inline static auto makeCallback(){
        return [](){
            return (RESULT*) new CONSTRUCTOR;
        };
    }
};

#endif // UTILS_H
