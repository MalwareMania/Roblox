namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x1C68F60);
    inline const uintptr_t ScriptContextResume = REBASE(0x40CA400);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6CEFD50);
    inline const uintptr_t GetGlobalState = REBASE(0x402A8B0);
    inline const uintptr_t CastArgs = REBASE(0x3F93C30);
    inline const uintptr_t PushInstance = REBASE(0x4012EF0);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x7FE8828);
        inline const uintptr_t GetIdentityStruct = REBASE(0x4170);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x7F47B30);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0x2ACD990);
        inline const uintptr_t GetProperty = REBASE(0x1C1D720);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x26A96D0);
        inline const uintptr_t LuaO_NilObject = REBASE(0x629DEC8);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x629A948);
        inline const uintptr_t LuaD_Throw = REBASE(0x2699F70);
        inline const uintptr_t LuaVM_Load = REBASE(0x4020EB0);
    }

    namespace Touch
    {
        inline const uintptr_t FireLeftMouseClick = REBASE(0x3AD5890);
        inline const uintptr_t FireRightMouseClick = REBASE(0x3AD5A30);
        inline const uintptr_t FireMouseHoverEnter = REBASE(0x3AD6E80);
        inline const uintptr_t FireMouseHoverLeave = REBASE(0x3AD7020);
        inline const uintptr_t FireProximityPrompt = REBASE(0x30C3170);
        inline const uintptr_t FireTouchInterest = REBASE(0xA4E640);
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x4183400);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8C426F8);
        inline const uintptr_t RealDataModel = 0x1D8;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x5C0;
    }

    namespace TaskScheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x89DD108);
        inline const uintptr_t JobStart = 0xC8;
        inline const uintptr_t JobEnd = 0xD0;
        inline const uintptr_t JobName = 0x18;
        inline const uintptr_t Fps = 0xB0;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x1C1F930);
        inline const uintptr_t Capabilities = 0x28;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0x9A0;
        inline const uintptr_t ScriptContextToResume = 0x7E0;
    }
}
