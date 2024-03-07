// What
#include "DebugVars.h"

DebugVars::DebugVars()
{

}

DebugVars& DebugVars::getInstance()
{
    static DebugVars instance;
    return instance;
}

void DebugVars::SetInflate()
{
    mInflate = !mInflate;
}

void DebugVars::SetRandomGrapple()
{
    mRandomGrapple = !mRandomGrapple;
}

bool DebugVars::GetInflate() const
{
    return mInflate;
}

bool DebugVars::GetRandomGrapple() const
{
    return mRandomGrapple;
}
