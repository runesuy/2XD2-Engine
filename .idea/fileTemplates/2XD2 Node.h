#if !defined(${NAME}_H)
#define ${NAME}_H

#include "e2XD/framework/nodes/Node.h"

class ${NAME} : public Node {
public:
    ${NAME}();
    virtual ~${NAME}() = default;

    void onCreate() override;
    
    void onUpdate() override;
};

#endif // ${NAME}_H