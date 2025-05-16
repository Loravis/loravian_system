# Environment variables
Before building, ensure you create a header file named **env.h** in the same directory containing this README file.

This header file defines all environment variables, in form of string constants. It should have the following format:
```cpp
#ifndef ENVVARS
#include <string>

const std::string BOT_TOKEN = "YOUR_TOKEN_HERE";

#endif
```