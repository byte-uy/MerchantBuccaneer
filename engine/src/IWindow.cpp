#include "IWindow.h"

#include <cassert>

int MBEngine::IWindow::getWidth() const 
{
    return width_; 
}

int MBEngine::IWindow::getHeight() const 
{ 
    return height_; 
}
