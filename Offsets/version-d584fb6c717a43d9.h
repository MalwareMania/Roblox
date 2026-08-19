namespace Offsets
{
    inline const uintptr_t Print = REBASE(0x91F9A0);
    inline const uintptr_t ScriptContextResume = REBASE(0x22FA7B0);
    inline const uintptr_t OpcodeLookupTable = REBASE(0x6B5F680);
    inline const uintptr_t GetGlobalState = REBASE(0x2259730);
    inline const uintptr_t CastArgs = REBASE(0x2234DD0);
    inline const uintptr_t PushInstance = REBASE(0x226A200);

    namespace Identity
    {
        inline const uintptr_t Identity = REBASE(0x7ED2808);
        inline const uintptr_t GetIdentityStruct = REBASE(0x40E0);
    }

    namespace Atom
    {
        inline const uintptr_t KTable = REBASE(0x7E73AE0);
    }

    namespace Properties
    {
        inline const uintptr_t GetPropertyData = REBASE(0xD70670);
        inline const uintptr_t GetProperty = REBASE(0x8E90A0);
    }

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x95E8C0);
        inline const uintptr_t LuaO_NilObject = REBASE(0x610B898);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x610B760);
        inline const uintptr_t LuaD_Throw = REBASE(0x945D80);
    }

    namespace Touch
    {
        const uintptr_t FireLeftMouseClick = REBASE(0x4F70EF0);
        const uintptr_t FireRightMouseClick = REBASE(0x4F71090);
        const uintptr_t FireMouseHoverEnter = REBASE(0x4F724E0);
        const uintptr_t FireMouseHoverLeave = REBASE(0x4F72680);
        const uintptr_t FireProximityPrompt = REBASE(0x4D92DA0);
    }

    namespace Task
    {
        inline const uintptr_t Defer = REBASE(0x23F68E0);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModel = REBASE(0x8A5D748);
        inline const uintptr_t RealDataModel = 0x1D0;

        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x578;
    }

    namespace Capabilities
    {
        inline const uintptr_t GetCapabilities = REBASE(0x8EB520);
        inline const uintptr_t Capabilities = 0x28;
    }
    
    namespace Extra
    {
        inline const uintptr_t RequireBypass = 0x840;
        inline const uintptr_t ScriptContextToResume = 0x7D0;
    }
}
