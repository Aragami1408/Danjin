#pragma once

#include <Danjin/common.h>

namespace Danjin {
class DANJIN_API Application {
public:
    Application();
    virtual ~Application();

    void run();
};

// TODO(higanbana): To be defined in CLIENT
Application *createApplication();
}
