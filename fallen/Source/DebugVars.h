#pragma once
//#include <string>
class DebugVars
{
public:
    static DebugVars& getInstance();
    DebugVars(const DebugVars&) = delete;
    void operator=(const DebugVars&) = delete;
    
    void SetInflate();
    void SetRandomGrapple();

    bool GetInflate() const;
    bool GetRandomGrapple() const;

private:
    bool mInflate = false;
    bool mRandomGrapple = false;

    DebugVars();
};

