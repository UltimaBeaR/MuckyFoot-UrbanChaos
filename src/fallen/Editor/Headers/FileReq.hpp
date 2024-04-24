// TexTab.hpp
// Guy Simmons, 20th February 1997

#pragma once

#include "ModeTab.hpp"

class FileRequester : public EdRect {
private:
    CBYTE* WildCard;
    CBYTE* Title;
    EdRect OK;
    EdRect Cancel;
    EdRect TextEdit;
    EdRect TextList[30];

public:
    FileRequester(CBYTE* Path, CBYTE* Extension, CBYTE* Title, CBYTE* FileName);
    CBYTE* Path;
    CBYTE FileName[200];
    SLONG Draw();
    ControlSet Controls;
};

