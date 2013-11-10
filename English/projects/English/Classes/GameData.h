//
//  GameData.h
//  English
//
//  Created by wang jia shuai on 13-10-20.
//
//

#ifndef __English__GameData__
#define __English__GameData__
#include "cocos-ext.h"
USING_NS_CC_EXT;

class GameData {
public:
    
    static  GameData *Shared();
    GameData();
    
    cs::CSJsonDictionary*   getEnglishData();
    int         getEnlishKeyIndex(const char *pKey);
    int         getEnlishCount();
    const   char*   getEnglishKeyName(int index);
    const   char*   getEnglishKeyData(const char *pKey);
private:
    cs::CSJsonDictionary* m_pEnglishData;
};

#endif /* defined(__English__GameData__) */
