#define CommonHeader \ uint8_t tt; // 0x0
\ uint8_t memcat; // 0x01 
\ uint8_t marked; // 0x02

struct TString
{
    CommonHeader; // 0x0
    uint16_t atomflag; // 0x04
    int16_t atom; // 0x06
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
    StkId base; // 0x0
    StkId func; // 0x08
    Proto* p; // 0x10
    StkId top; // 0x18

    union
    {
        const Instruction* savedpc;
        int errfunc;
    }; 

    int nresults;
    uint32_t flags;
};

struct Closure
{
    CommonHeader; // 0x0

    uint8_t isC; // 0x03
    uint8_t nupvalues; // 0x04
    uint8_t preload; // 0x05
    uint8_t stacksize; // 0x06
    uint8_t pad07; // 0x07

    GCObject* gclist; // 0x08
    LuaTable* env; // 0x10

    union
    {
        struct
        {
            TString* debugname; // 0x18
            CLOSURE_DEBUGNAME_ENC<const char*> debugname_DEPRECATED; // 0x20
            CLOSURE_CONT_ENC<lua_Continuation> cont; // 0x28
            lua_CFunction f; // 0x30
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
    CommonHeader; // 0x0

    uint8_t is_vararg; // 0x03
    uint8_t numparams; // 0x04
    uint8_t nups; // 0x05
    uint8_t flags; // 0x06
    uint8_t maxstacksize; // 0x07

    PROTO_TYPEINFO_ENC<uint8_t*> typeinfo; // 0x08
    Proto** p; // 0x10
    PROTO_DEBUGNAME_ENC<TString*> debugname; // 0x18
    PROTO_SOURCE_ENC<TString*> source; // 0x20
    PROTO_LOCVARS_ENC<LocVar*> locvars; // 0x28
    void* execdata; // 0x30
    uintptr_t exectarget; // 0x38
    PROTO_UPVALUES_ENC<TString**> upvalues; // 0x40
    PROTO_USERDATA_ENC<void*> userdata; // 0x48
    PROTO_LINEINFO_ENC<uint8_t*> lineinfo; // 0x50
    GCObject* gclist; // 0x58
    PROTO_DEBUGINSN_ENC<uint8_t*> debuginsn; // 0x60
    const Instruction* codeentry; // 0x68
    PROTO_ABSLINEINFO_ENC<int*> abslineinfo; // 0x70
    TValue* k; // 0x78
    Instruction* code; // 0x80

    int sizelocvars; // 0x88
    int sizep; // 0x8C
    int bytecodeid; // 0x90
    int sizeupvalues; // 0x94
    int sizek; // 0x98
    int sizecode; // 0x9C
    int sizetypeinfo; // 0xA0
    int sizelineinfo; // 0xA4
    int linegaplog2; // 0xA8
    int linedefined; // 0xAC

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

    unsigned short nCcalls; // 0x08
    unsigned short baseCcalls; // 0x0A
    int cachedslot; // 0x0C

    LSTATE_STACKSIZE_ENC<int> stacksize; // 0x10
    int size_ci; // 0x14

    GCObject* gclist; // 0x18
    UpVal* openupval; // 0x20
    RbxExtraSpace* userdata; // 0x28
    global_State* global; // 0x30
    StkId base; // 0x38
    StkId stack; // 0x40
    StkId stack_last; // 0x48
    CallInfo* ci; // 0x50
    StkId top; // 0x58
    CallInfo* end_ci; // 0x60
    CallInfo* base_ci; // 0x68

    LuaTable* gt; // 0x70
    TString* namecall; // 0x78
};
