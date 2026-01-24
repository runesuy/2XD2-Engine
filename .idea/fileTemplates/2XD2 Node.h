#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}

#[[#include]]# <2XD2/framework/nodes/Node.h>

class ${NAME} : public e2XD::framework::Node {
public:
    ${NAME}();
    ~${NAME}() override = default;

    void onCreate() override;
    
    void onUpdate() override;
};

#[[#endif]]# //${INCLUDE_GUARD}