#ifndef ZYCHEATS_SGUYS_FUNCTIONS_H
#define ZYCHEATS_SGUYS_FUNCTIONS_H

// here you can define variables for the patches
bool Speed, GetUnlockedSkins;

monoString *CreateIl2cppString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString*(*)(void*, const char*)) (g_il2cppBaseMap.startAddress + string2Offset(OBFUSCATE("0x2596B20")));
    return String_CreateString(NULL, str);
}



void Pointers() {

}

void Patches() {

}

// declare your hooks here
bool (*old_GetUnlockedSkins)(void *instance);
bool GetUnlockedSkins(void *instance) {
    if (instance != NULL) {
        if (isAmmoandFirerate) {
            return true;
        }
    }
    return old_GetUnlockedSkins(instance);
}


//the void *instance is a self-created variable.





void Hooks() {
    HOOK("0x16A5CD8", GetUnlockedSkins, old_GetUnlockedSkins);
    

}

#endif //ZYCHEATS_SGUYS_FUNCTIONS_H
