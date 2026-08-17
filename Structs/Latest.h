// Probably Proto is the most notable struct here, many changes
// Credits to my partner, not confirmed by me atm

#define CommonHeader \ uint8_t tt; // 0x0
\ uint8_t memcat; // 0x01 
\ uint8_t marked; // 0x02

struct TString
{
    CommonHeader; // 0x0
    uint8_t pad3; // 0x03
    int atom; // 0x04
    TString* next; // 0x08
    TSTRING_HASH_ENC<uint32_t> hash; // 0x10
    uint32_t len; // 0x14
    char data[1]; // 0x18
};

struct Udata
{
    CommonHeader; // 0x0
    uint8_t tag; // 0x03
    int32_t len; // 0x04
    UDATA_META_ENC<LuaTable*> metatable; // 0x08
    char data[1]; // 0x10
};

struct CallInfo
{
    StkId base; // 0x00
    StkId func; // 0x08
    Proto* p; // 0x10
    StkId top;  // 0x18

    union
    {
        int errfunc; // 0x20
        const Instruction* savedpc; // 0x20
    };

    int nresults; // 0x28
    unsigned int flags; // 0x2C
} CallInfo;

struct stringtable
{
    struct TString** hash; // 0x0
    uint32_t nuse; // 0x8
    int size; // 0xC
};

struct lua_Debug
{
    void* userdata; // 0x0
    uint8_t nupvals; // 0x8
    uint8_t nparams; // 0x9
    uint8_t isvararg; // 0xA
    uint8_t pad01; // 0xB
    int linedefined; // 0xC
    int currentline; // 0x10
    uint32_t pad04; // 0x14
    const char* source; // 0x18
    const char* what; // 0x20
    const char* short_src; // 0x28
    const char* name; // 0x30
    char ssbuf[LUA_IDSIZE]; // 0x38
};

struct lua_Callbacks
{
    void* userdata; // 0x0
    void (*onallocate)(lua_State* L, size_t osize, size_t nsize); // 0x8
    void (*panic)(lua_State* L, int errcode); // 0x10
    void (*interrupt)(lua_State* L, int gc); // 0x18
    void (*debugstep)(lua_State* L, lua_Debug* ar); // 0x20
    void (*debugprotectederror)(lua_State* L); // 0x28
    void (*userthread)(lua_State* LP, lua_State* L); // 0x30
    void (*debugbreak)(lua_State* L, lua_Debug* ar); // 0x38
    int16_t (*useratom)(lua_State* L, const char* s, size_t l); // 0x40
    void (*debuginterrupt)(lua_State* L, lua_Debug* ar); // 0x48
};

struct Shared
{
    int ThreadCount; // 0x0
    uint32_t pad04; // 0x4
    void* ScriptVMState; // 0x8
    void* ScriptContext; // 0x10
    char Threads[0x18]; // 0x18
};

struct RbxExtraSpace
{
    char Hook[0x18]; // 0x0
    std::shared_ptr<Shared> Shared; // 0x18
    RbxExtraSpace* FlyWeightNode; // 0x28
    void* Continuations; // 0x30
    uint64_t Capabilities; // 0x38
    uint32_t Identity; // 0x40
    uint32_t pad04; // 0x44
    uint64_t pad08; // 0x48
    uint64_t pad08_1; // 0x50
    std::weak_ptr<uintptr_t> Source; // 0x58
    std::shared_ptr<uintptr_t> Random_Refcounted_Object; // 0x68
    uint64_t pad08_2; // 0x78
    uint64_t pad08_3; // 0x80
    std::weak_ptr<uintptr_t> Actor; // 0x88
};

struct Closure
{
    CommonHeader; // 0x00
    uint8_t preload; // 0x03
    uint8_t stacksize; // 0x04
    uint8_t nupvalues; // 0x05
    uint8_t isC; // 0x06
    uint8_t pad7;// 0x07
    GCObject* gclist; // 0x08
    LuaTable* env;    // 0x10

    union
    {
        struct
        {
            lua_CFunction f; // 0x18
            TString* debugname; // 0x20
            CLOSURE_DEBUGNAME_ENC<const char*> debugname_DEPRECATED; // 0x28
            CLOSURE_CONT_ENC<lua_Continuation> cont; // 0x30
            TValue upvals[1]; // 0x38
        } c;

        struct
        {
            Proto* p; // 0x18
            TValue uprefs[1]; // 0x20
        } l;
    };
};

struct Proto
{
    CommonHeader; // 0x00
    uint8_t maxstacksize; // 0x03
    uint8_t numparams; // 0x04
    uint8_t is_vararg; // 0x05
    uint8_t flags; // 0x06
    uint8_t nups; // 0x07

    PROTO_USERDATA_ENC<void*> userdata; // 0x08
    PROTO_ABSLINEINFO_ENC<int*> abslineinfo; // 0x10
    PROTO_DEBUGNAME_ENC<TString*> debugname; // 0x18
    Proto** p; // 0x20
    PROTO_TYPEINFO_ENC<uint8_t*> typeinfo; // 0x28
    PROTO_LINEINFO_ENC<uint8_t*> lineinfo; // 0x30
    PROTO_DEBUGINSN_ENC<uint8_t*> debuginsn; // 0x38
    GCObject* gclist; // 0x40
    PROTO_LOCVARS_ENC<LocVar*> locvars; // 0x48
    void* execdata; // 0x50
    uintptr_t exectarget; // 0x58
    PROTO_SOURCE_ENC<TString*> source; // 0x60
    PROTO_UPVALUES_ENC<TString**> upvalues; // 0x68
    TValue* k; // 0x70
    Instruction* code;  // 0x78
    const Instruction* codeentry; // 0x80

    int sizecode;// 0x88
    int sizetypeinfo; // 0x8C
    int sizelineinfo; // 0x90
    int sizelocvars; // 0x94
    int linedefined; // 0x98
    int bytecodeid; // 0x9C
    int sizeupvalues; // 0xA0
    int linegaplog2; // 0xA4
    int sizep; // 0xA8
    int sizek; // 0xAC

    FeedbackVectorSlot* feedbackvec; // 0xB0
    uint32_t feedbackvecsize; // 0xB8
    uint32_t funid; // 0xBC
    Proto* optimized; // 0xC0
    Proto* deoptimized; // 0xC8
    uint64_t cost; // 0xD0
};

struct lua_State
{
    CommonHeader; // 0x0
    uint8_t status; // 0x03
    uint8_t activememcat; // 0x04
    bool singlestep; // 0x05
    bool isactive; // 0x06
    uint8_t pad07; // 0x07

    StkId top; // 0x08
    StkId stack_last; // 0x10
    CallInfo* ci; // 0x18
    global_State* global; // 0x20
    StkId base; // 0x28
    StkId stack; // 0x30
    TString* namecall; // 0x38
    GCObject* gclist; // 0x40
    UpVal* openupval; // 0x48
    LuaTable* gt; // 0x50
    RbxExtraSpace* userdata; // 0x58
    CallInfo* end_ci; // 0x60
    CallInfo* base_ci; // 0x68

    unsigned short nCcalls; // 0x70
    unsigned short baseCcalls; // 0x72
    int cachedslot; // 0x74

    LSTATE_STACKSIZE_ENC<int> stacksize; // 0x78
    int size_ci; // 0x7C
};


struct global_State
{
    stringtable strt; // 0x0
    GCObject* gray; // 0x10
    GCObject* grayagain; // 0x18
    GCObject* weak; // 0x20
    lua_Alloc frealloc; // 0x28
    void* ud; // 0x30
    int gcstepsize; // 0x38
    int gcstepmul; // 0x3C
    int gcgoal; // 0x40
    uint32_t pad04; // 0x44
    size_t GCthreshold; // 0x48
    size_t totalbytes; // 0x50
    uint8_t currentwhite; // 0x58
    uint8_t gcstate; // 0x59
    uint16_t pad06_0; // 0x5A
    uint16_t pad06_1; // 0x5C
    uint16_t pad06_2; // 0x5E
    lua_Page* freepages[LUA_SIZECLASSES]; // 0x60
    lua_State* mainthread; // 0x1A0
    lua_Page* sweepgcopage; // 0x1A8
    lua_Page* freegcopages[LUA_SIZECLASSES]; // 0x1B0
    lua_Page* allgcopages; // 0x2F0
    lua_Page* allpages; // 0x2F8
    UpVal uvhead; // 0x300
    LuaTable* mt[LUA_T_COUNT]; // 0x328
    TString* tmname[TM_N]; // 0x398
    TString* ttname[LUA_T_COUNT]; // 0x440
    TValue pseudotemp; // 0x4B0
    TValue registry; // 0x4C0
    registryfree_t registryfree; // 0x4D0
    uint32_t pad04_1; // 0x4D4
    struct lua_jmpbuf* errorjmp; // 0x4D8
    lua_Callbacks cb; // 0x4E0
    uint64_t rngstate; // 0x530
    uint64_t ptrenckey[4]; // 0x538
    lua_ExecutionCallbacks ecb; // 0x558
    alignas(16) uint8_t ecbdata[LUA_EXECUTION_CALLBACK_STORAGE]; // 0x5A0
    lua_UdataDirectAccessData udatadirect[UTAG_INTERNAL_LIMIT]; // 0x7A0
    size_t memcatbytes[LUA_MEMORY_CATEGORIES]; // 0x2C30
    void (*udatagc[LUA_UTAG_LIMIT])(lua_State*, void*); // 0x3430
    void (*udatamark[LUA_UTAG_LIMIT])(lua_State*, void*); // 0x3830
    LuaTable* udatamt[LUA_UTAG_LIMIT]; // 0x3C30
    TValue weakregistry; // 0x4030
    int weakregistryfree; // 0x4040
    uint32_t pad04_2; // 0x4044
    lua_EmbedderGc embeddergc; // 0x4048
    TString* lightuserdataname[LUA_LUTAG_LIMIT]; // 0x4050
    LuaTable* udatadirectfields[UTAG_INTERNAL_LIMIT]; // 0x4450
    GCStats gcstats; // 0x4850
    uint32_t lastprotoid; // 0x4918
    uint32_t pad04_3; // 0x491C
#ifdef LUAI_GCMETRICS
    GCMetrics gcmetrics;
#endif
};
