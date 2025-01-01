#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <vector>
#include <string>

#include <chrono>
#include <thread>
#include <cstdlib>
#include "oops.h"
#include "logger.h"
#include "function.h"
#include "Environment.h"
#include "WebHelper.h"
#include "const.h"
#include "oppsFileInclude/objectOrientedProgram.h"
#ifdef _WIN32
#include <windows.h>  // For Sleep on Windows
#else
#include <unistd.h>  // For sleep on non-Windows platforms (e.g., Linux, macOS)
#endif
#include "MainApp.h"

// Add other commonly used headers here

#endif // PCH_H
