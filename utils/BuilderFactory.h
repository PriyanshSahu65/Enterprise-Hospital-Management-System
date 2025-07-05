#ifndef BUILDERFACTORY_H
#define BUILDERFACTORY_H
#include <string>
#include "Builder.h"

class BuilderFactory {
public:
    static Builder* createBuilder(const std::string& type);
};

#endif // BUILDERFACTORY_H
