//
//  GameData.h
//  English
//
//  Created by wangjiashuai on 22/10/13.
//
//

#ifndef English_GameData_h
#define English_GameData_h
#include "cocos-ext.h"
USING_NS_CC_EXT;

class GameData {
public:
    static GameData *Shared();
    GameData();
    
    cs::CSJsonDictionary*       getEnglishData();
    int                         getEnlishKeyIndex(const char *pKey);
    int                         getEnlishCount();
    const char*                 getEnglishKeyName(int index);
    const char*                 getEnglishKeyData(int index);
    
private:
    cs::CSJsonDictionary*   m_pEnglishData;
};

#endif
