#ifndef GENERATE_CPP_H
#define GENERATE_JAVA_H

#include "aidl_language.h"

#include <string>

int generate_cpp(const std::string& filename, const std::string& originalSrc,
                document_item_type* iface);

#endif // GENERATE_CPP_H

