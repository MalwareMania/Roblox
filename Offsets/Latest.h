namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x1CFA0D0);
    inline const uintptr_t ScriptContextResume = REBASE(0x429B530);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6F1BF50);
    inline const uintptr_t GetGlobalState = REBASE(0x41F2300);
    inline const uintptr_t CastArgs = REBASE(0x414ECD0);
    inline const uintptr_t PushInstance = REBASE(0x41D9F50);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x828CA38);
        inline const uintptr_t GetIdentityStruct = REBASE(0x7240);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x81E9120);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0x1D32FF0);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x269E520);
        inline const uintptr_t LuaO_NilObject = REBASE(0x64BA248);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x64B68D8);
        inline const uintptr_t LuaD_Throw = REBASE(0x266EA40);
        inline const uintptr_t LuaVM_Load = REBASE(0x41E8BD0);
    }

    namespace Touch
    {
        inline const uintptr_t FireLeftMouseClick = REBASE(0x3C3EDC0);
        inline const uintptr_t FireRightMouseClick = REBASE(0x3C3EF60);
        inline const uintptr_t FireMouseHoverEnter = REBASE(0x3C403B0);
        inline const uintptr_t FireMouseHoverLeave = REBASE(0x3C40550);
        inline const uintptr_t FireProximityPrompt = REBASE(0x31BD800);
        inline const uintptr_t FireTouchInterest = REBASE(0x1584BC0);
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x435A060);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8EE1728);
        inline const uintptr_t RealDataModel = 0x1F8;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x5D0;
    }

    namespace TaskScheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x8C8D108);
        inline const uintptr_t JobStart = 0xC8;
        inline const uintptr_t JobEnd = 0xD0;
        inline const uintptr_t JobName = 0x18;
        inline const uintptr_t Fps = 0xB0;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x1D34B70);
        inline const uintptr_t Capabilities = 0x30;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0xAAE;
        inline const uintptr_t ResumeFacet = 0xA38;
    }
}
