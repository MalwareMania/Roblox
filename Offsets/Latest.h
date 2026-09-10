namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x1CAB4B0);
    inline const uintptr_t ScriptContextResume = REBASE(0x4260F50);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6E26C70);
    inline const uintptr_t GetGlobalState = REBASE(0x41BD590);
    inline const uintptr_t CastArgs = REBASE(0x4124580);
    inline const uintptr_t PushInstance = REBASE(0x41A5F20);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x81570C8); // This could be wrong
        inline const uintptr_t GetIdentityStruct = REBASE(0x4250);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x80BBE20);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0x2B0FAF0);
        inline const uintptr_t GetProperty = REBASE(0x1CE4BE0);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x272A260);
        inline const uintptr_t LuaO_NilObject = REBASE(0x63CDF48);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x63CE8C8);
        inline const uintptr_t LuaD_Throw = REBASE(0x2709720);
        inline const uintptr_t LuaVM_Load = REBASE(0x41B3B50);
    }

    namespace Touch
    {
        inline const uintptr_t FireLeftMouseClick = REBASE(0x3B4D9F0);
        inline const uintptr_t FireRightMouseClick = REBASE(0x3B4DB90);
        inline const uintptr_t FireMouseHoverEnter = REBASE(0x3B4EFE0);
        inline const uintptr_t FireMouseHoverLeave = REBASE(0x3B4F180);
        inline const uintptr_t FireProximityPrompt = REBASE(0x3102650);
        inline const uintptr_t FireTouchInterest = REBASE(0xA6DFA0);
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x4319B60);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8DC2258);
        inline const uintptr_t RealDataModel = 0x1F8;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x5D8;
    }

    namespace TaskScheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x8B5CEE8);
        inline const uintptr_t JobStart = 0xC8;
        inline const uintptr_t JobEnd = 0xD0;
        inline const uintptr_t JobName = 0x18;
        inline const uintptr_t Fps = 0xB0;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x1CE6760);
        inline const uintptr_t Capabilities = 0x30;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0xBB4;
        inline const uintptr_t ScriptContextToResume = 0x9E0;
    }
}
