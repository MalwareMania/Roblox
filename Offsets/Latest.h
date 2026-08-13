namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x92C340);
    inline const uintptr_t ScriptContextResume = REBASE(0x22BBA10);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6B83740);
    inline const uintptr_t GetGlobalState = REBASE(0x22D7910);
    inline const uintptr_t CastArgs = REBASE(0x21F5070);
    inline const uintptr_t PushInstance = REBASE(0x222A6B0);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x7EEB448);
        inline const uintptr_t GetIdentityStruct = REBASE(0x4170);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x7E8C7A0);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0xD70670);
        inline const uintptr_t GetProperty = REBASE(0x8F5B50);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0xB59570);
        inline const uintptr_t LuaO_NilObject = REBASE(0x610EFF8);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x610EEB8);
        inline const uintptr_t LuaD_Throw = REBASE(0xB40C30);
        inline const uintptr_t LuaVM_Load = REBASE(0x223D370);
    }

    namespace Touch
    {
        // Could be wrong
        const uintptr_t FireLeftMouseClick = REBASE(0x4F11E30);
        const uintptr_t FireRightMouseClick = REBASE(0x4F124B0);
        const uintptr_t FireMouseHoverEnter = REBASE(0x4EC9630);
        const uintptr_t FireMouseHoverLeave = REBASE(0x4EF8EA0);
        const uintptr_t FireProximityPrompt = REBASE(0x4F12630);
        const uintptr_t FireTouchInterest = REBASE(0x1E46C30);
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x23B5980);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8B79B58);
        inline const uintptr_t RealDataModel = 0x1D0;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x570;
    }

    namespace TaskScheduler
    {
        inline const uintptr_t TaskScheduler = REBASE(0x88B64C8);
        inline const uintptr_t JobStart = 0xC8;
        inline const uintptr_t JobEnd = 0xD0;
        inline const uintptr_t JobName = 0x18;
        inline const uintptr_t Fps = 0xB0;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x8F7FD0);
        inline const uintptr_t Capabilities = 0x28;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0x810;
        inline const uintptr_t ScriptContextToResume = 0x7E0;
    }
}
