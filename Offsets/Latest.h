namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x1C68FE0);
    inline const uintptr_t ScriptContextResume = REBASE(0x40CBD40);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6D45820);
    inline const uintptr_t GetGlobalState = REBASE(0x402B3C0);
    inline const uintptr_t CastArgs = REBASE(0x3F93510);
    inline const uintptr_t PushInstance = REBASE(0x4013BA0);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x8051178);
        inline const uintptr_t GetIdentityStruct = REBASE(0x4170);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x7FAF260);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0x2AADA50);
        inline const uintptr_t GetProperty = REBASE(0x1CA2B00);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x26BDA30);
        inline const uintptr_t LuaO_NilObject = REBASE(0x62F7418);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x62F6EC8);
        inline const uintptr_t LuaD_Throw = REBASE(0x26ADAD0);
        inline const uintptr_t LuaVM_Load = REBASE(0x4021B10);
    }

    namespace Touch
    {
        inline const uintptr_t FireLeftMouseClick = REBASE(0x3AC4300);
        inline const uintptr_t FireRightMouseClick = REBASE(0x3AC44A0);
        inline const uintptr_t FireMouseHoverEnter = REBASE(0x3AC58F0);
        inline const uintptr_t FireMouseHoverLeave = REBASE(0x3AC5A90);
        inline const uintptr_t FireProximityPrompt = REBASE(0x309BD00);
        inline const uintptr_t FireTouchInterest = REBASE(0xA566E0));
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x4186980);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8CA9CC8);
        inline const uintptr_t RealDataModel = 0x1F8;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x5D0;
    }

    namespace TaskScheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x8A44D68);
        inline const uintptr_t JobStart = 0xC8;
        inline const uintptr_t JobEnd = 0xD0;
        inline const uintptr_t JobName = 0x18;
        inline const uintptr_t JobTypeName = 0x108;
        inline const uintptr_t Fps = 0xB0;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x1CA46D0);
        inline const uintptr_t Capabilities = 0x28;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0xA00;
        inline const uintptr_t ResumeFacet = 0x8E0;
    }
}
