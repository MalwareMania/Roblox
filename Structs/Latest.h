// Probably Proto is the most notable struct here, many changes

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
    ExtraSpace* userdata; // 0x58
    CallInfo* end_ci; // 0x60
    CallInfo* base_ci; // 0x68

    unsigned short nCcalls; // 0x70
    unsigned short baseCcalls; // 0x72
    int cachedslot; // 0x74

    LSTATE_STACKSIZE_ENC<int> stacksize; // 0x78
    int size_ci; // 0x7C
};
