////////////////////////////////////////////////////////////////////////////////
///
///  MILLENIUM-STUDIO
///  Copyright 2015 Millenium-studio SARL
///  All Rights Reserved.
///
////////////////////////////////////////////////////////////////////////////////

# include "blackrock_foundry.hpp"

DoorData const g_DoorData[] =
{
    { eFoundryGameObjects::GruulSpikeDoor,              eFoundryDatas::DataGruul,               DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::BKFoundrySpikeTrapGate,      eFoundryDatas::DataOregorger,           DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::FurnacePortcullis,           eFoundryDatas::DataOregorger,           DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::BlastFurnaceEncounterDoor,   eFoundryDatas::DataBlastFurnace,        DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::HansgarAndFranzokEntrance,   eFoundryDatas::DataHansgarAndFranzok,   DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::HansgarAndFranzokExit,       eFoundryDatas::DataHansgarAndFranzok,   DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::FirewallDoor,                eFoundryDatas::DataFlamebenderKagraz,   DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::BurningFrontDoor,            eFoundryDatas::DataFlamebenderKagraz,   DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::KromogsDoorSouth,            eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::KromogsDoorEast,             eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::BlackForgePortcullis,        eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::BlackForgeGate,              eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::TheBeastGate,                eFoundryDatas::DataBeastlordDarmac,     DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE },
    { eFoundryGameObjects::TerminusDoor,                eFoundryDatas::DataBeastlordDarmac,     DoorType::DOOR_TYPE_PASSAGE,    BoundaryType::BOUNDARY_NONE },
    { 0,                                                0,                                      DoorType::DOOR_TYPE_ROOM,       BoundaryType::BOUNDARY_NONE } ///< End
};

class instance_blackrock_foundry : public InstanceMapScript
{
    public:
        instance_blackrock_foundry() : InstanceMapScript("instance_blackrock_foundry", 1205) { }

        struct instance_blackrock_foundryMapScript : public InstanceScript
        {
            instance_blackrock_foundryMapScript(Map* p_Map) : InstanceScript(p_Map)
            {
                m_Initialized               = false;

                m_DungeonID                 = 0;

                m_SlagworksEntrance         = 0;
                m_GruulGuid                 = 0;
                m_PristineTrueIronOres      = 0;

                m_OregorgerGuid             = 0;
                m_VolatileOreGuid           = 0;
                m_VolatileOreGrinded        = false;

                m_HeartOfTheMountain        = 0;
                m_ForemanFeldspar           = 0;
                m_CosmeticBlackhand         = 0;
                m_FurnaceGate               = 0;
                m_PrimalElementalistTime    = 0;
                m_YaWeveGotTimeAchiev       = false;

                m_BlackForgeEntrance        = 0;

                m_HansgarGuid               = 0;
                m_FranzokGuid               = 0;
                m_StampStampRevolution      = true;

                m_IronTaskmasterAggro       = false;
                m_SteelHasBeenBrought       = true;
                m_FlamebenderKagrazGuid     = 0;
                m_AknorSteelbringerGuid     = 0;
                m_LavaStalkerGuid           = 0;
                m_MoltenTorrentStalkerGuid  = 0;

                m_WouldYouGiveMeAHand       = false;
                m_GraspingEarthHandsTime    = 0;
                m_KromogGuid                = 0;

                m_IronAssemblyEntrance      = 0;
                m_DarmacBeastMountedFirst   = 0;
                m_BeastlordDarmacGuid       = 0;
                m_CruelfangGuid             = 0;
                m_DreadwingGuid             = 0;
                m_IroncrusherGuid           = 0;
                m_ThunderlordPackPens       = 0;
                m_BeastsEnclosureDoor       = 0;

                m_SpikeGateGuid             = 0;
                m_CrucibleEntrance          = 0;
            }

            bool m_Initialized;

            uint32 m_DungeonID;

            /// Slagworks
            uint64 m_SlagworksEntrance;
            uint64 m_GruulGuid;
            uint8 m_PristineTrueIronOres;

            uint64 m_OregorgerGuid;
            uint64 m_VolatileOreGuid;
            bool m_VolatileOreGrinded;

            /// Blast Furnace
            uint64 m_HeartOfTheMountain;
            uint64 m_ForemanFeldspar;
            uint64 m_CosmeticBlackhand;
            uint64 m_FurnaceGate;
            uint32 m_PrimalElementalistTime;
            bool m_YaWeveGotTimeAchiev;

            /// The Black Forge
            uint64 m_BlackForgeEntrance;
            /// Slagmill Press
            uint64 m_HansgarGuid;
            uint64 m_FranzokGuid;
            bool m_StampStampRevolution;

            /// Burning Front
            bool m_IronTaskmasterAggro;
            bool m_SteelHasBeenBrought;
            uint64 m_FlamebenderKagrazGuid;
            uint64 m_AknorSteelbringerGuid;
            uint64 m_LavaStalkerGuid;
            uint64 m_MoltenTorrentStalkerGuid;

            /// The Great Anvil
            bool m_WouldYouGiveMeAHand;
            uint32 m_GraspingEarthHandsTime;
            uint64 m_KromogGuid;

            /// Iron Assembly
            uint64 m_IronAssemblyEntrance;
            /// The Breaking Grounds
            uint32 m_DarmacBeastMountedFirst;
            uint64 m_BeastlordDarmacGuid;
            uint64 m_CruelfangGuid;
            uint64 m_DreadwingGuid;
            uint64 m_IroncrusherGuid;
            uint64 m_ThunderlordPackPens;
            uint64 m_BeastsEnclosureDoor;

            /// Blackhand's Crucible
            uint64 m_SpikeGateGuid;
            uint64 m_CrucibleEntrance;

            void Initialize() override
            {
                SetBossNumber(eFoundryDatas::MaxBossData);

                LoadDoorData(g_DoorData);

                instance->SetObjectVisibility(300.0f);
            }

            void OnCreatureCreate(Creature* p_Creature) override
            {
                switch (p_Creature->GetEntry())
                {
                    case eFoundryCreatures::BossGruul:
                        m_GruulGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossOregorger:
                        m_OregorgerGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::HeartOfTheMountain:
                        m_HeartOfTheMountain = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::ForemanFeldspar:
                        m_ForemanFeldspar = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BlackhandCosmetic:
                        m_CosmeticBlackhand = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossHansgar:
                        m_HansgarGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossFranzok:
                        m_FranzokGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossFlamebenderKagraz:
                        m_FlamebenderKagrazGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::AknorSteelbringer:
                        m_AknorSteelbringerGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::LavaStalker:
                        m_LavaStalkerGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::MoltenTorrentStalker:
                        m_MoltenTorrentStalkerGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossKromog:
                        m_KromogGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossBeastlordDarmac:
                        m_BeastlordDarmacGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossCruelfang:
                        m_CruelfangGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossDreadwing:
                        m_DreadwingGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::BossIroncrusher:
                        m_IroncrusherGuid = p_Creature->GetGUID();
                        break;
                    case eFoundryCreatures::ThunderlordPackPens:
                        m_ThunderlordPackPens = p_Creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* p_GameObject) override
            {
                switch (p_GameObject->GetEntry())
                {
                    case eFoundryGameObjects::GruulSpikeDoor:
                    case eFoundryGameObjects::BKFoundrySpikeTrapGate:
                    case eFoundryGameObjects::FurnacePortcullis:
                    case eFoundryGameObjects::BlastFurnaceEncounterDoor:
                    case eFoundryGameObjects::HansgarAndFranzokEntrance:
                    case eFoundryGameObjects::HansgarAndFranzokExit:
                    case eFoundryGameObjects::FirewallDoor:
                    case eFoundryGameObjects::BurningFrontDoor:
                    case eFoundryGameObjects::KromogsDoorSouth:
                    case eFoundryGameObjects::KromogsDoorEast:
                    case eFoundryGameObjects::BlackForgePortcullis:
                    case eFoundryGameObjects::BlackForgeGate:
                    case eFoundryGameObjects::TheBeastGate:
                    case eFoundryGameObjects::TerminusDoor:
                        AddDoor(p_GameObject, true);
                        break;
                    case eFoundryGameObjects::VolatileBlackrockOre:
                        m_VolatileOreGuid = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::CrucibleLeft:
                    case eFoundryGameObjects::CrucibleRight:
                        p_GameObject->SetAIAnimKitId(eFoundryVisuals::CrucibleVisuals);
                        break;
                    case eFoundryGameObjects::FurnaceGate:
                        m_FurnaceGate = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::ConveyorBelt001:
                    case eFoundryGameObjects::ConveyorBelt002:
                    case eFoundryGameObjects::ConveyorBelt003:
                    case eFoundryGameObjects::ConveyorBelt004:
                    case eFoundryGameObjects::ConveyorBelt005:
                        p_GameObject->SetAIAnimKitId(eFoundryVisuals::ConveyorsStop);
                        break;
                    case eFoundryGameObjects::ConveyorBelt006:
                    case eFoundryGameObjects::ConveyorBelt008:
                    case eFoundryGameObjects::ConveyorBelt010:
                        p_GameObject->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStart2, true);
                        break;
                    case eFoundryGameObjects::ConveyorBelt007:
                    case eFoundryGameObjects::ConveyorBelt009:
                        p_GameObject->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStart3, true);
                        break;
                    case eFoundryGameObjects::SlagworksDoor:
                        m_SlagworksEntrance = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::BlackForgeEntrance:
                        m_BlackForgeEntrance = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::IronAssembleyGate:
                        m_IronAssemblyEntrance = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::SpikeGate:
                        m_SpikeGateGuid = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::CrucibleDoor:
                        m_CrucibleEntrance = p_GameObject->GetGUID();
                        break;
                    case eFoundryGameObjects::BeastsEnclosureDoor:
                        m_BeastsEnclosureDoor = p_GameObject->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* p_GameObject) override
            {
                switch (p_GameObject->GetEntry())
                {
                    case eFoundryGameObjects::GruulSpikeDoor:
                    case eFoundryGameObjects::BKFoundrySpikeTrapGate:
                    case eFoundryGameObjects::FurnacePortcullis:
                    case eFoundryGameObjects::BlastFurnaceEncounterDoor:
                    case eFoundryGameObjects::HansgarAndFranzokEntrance:
                    case eFoundryGameObjects::HansgarAndFranzokExit:
                    case eFoundryGameObjects::FirewallDoor:
                    case eFoundryGameObjects::BurningFrontDoor:
                    case eFoundryGameObjects::KromogsDoorSouth:
                    case eFoundryGameObjects::KromogsDoorEast:
                    case eFoundryGameObjects::BlackForgePortcullis:
                    case eFoundryGameObjects::BlackForgeGate:
                    case eFoundryGameObjects::TheBeastGate:
                    case eFoundryGameObjects::TerminusDoor:
                        AddDoor(p_GameObject, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 p_BossID, EncounterState p_State) override
            {
                uint32 l_OldState = GetBossState(p_BossID);

                if (!InstanceScript::SetBossState(p_BossID, p_State))
                    return false;

                /// Don't handle the next in case of loading
                if (l_OldState != EncounterState::IN_PROGRESS)
                    return true;

                switch (p_BossID)
                {
                    case eFoundryDatas::DataGruul:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_PristineTrueIronOres >= eFoundryDatas::MaxPristineTrueIronOres && !instance->IsLFR())
                                    DoCompleteAchievement(eFoundryAchievements::TheIronPrince);

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_PristineTrueIronOres = 0;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataOregorger:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_VolatileOreGrinded && !instance->IsLFR())
                                    DoCompleteAchievement(eFoundryAchievements::HeShootsHeOres);

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_VolatileOreGrinded = false;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataBlastFurnace:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_YaWeveGotTimeAchiev && !instance->IsLFR())
                                    DoCompleteAchievement(eFoundryAchievements::YaWeveGotTime);

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_PrimalElementalistTime = 0;
                                m_YaWeveGotTimeAchiev = false;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataHansgarAndFranzok:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_StampStampRevolution && !instance->IsLFR())
                                    DoCompleteAchievement(eFoundryAchievements::StampStampRevolution);

                                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                                {
                                    if (Creature* l_Hansgar = instance->GetCreature(m_HansgarGuid))
                                    {
                                        if (l_Hansgar->IsAIEnabled)
                                            l_Hansgar->AI()->Talk(8);   ///< Death
                                    }
                                });

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_StampStampRevolution = true;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataFlamebenderKagraz:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_SteelHasBeenBrought && !instance->IsLFR())
                                {
                                    DoCompleteAchievement(eFoundryAchievements::TheSteelHasBeenBrought);
                                    DoCastSpellOnPlayers(eFoundrySpells::FollowerAknorSteelbringer);
                                }

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_SteelHasBeenBrought = true;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataKromog:
                    {
                        switch (p_State)
                        {
                            case EncounterState::DONE:
                            {
                                if (m_WouldYouGiveMeAHand && !instance->IsLFR())
                                {
                                    if (Creature* l_Kromog = instance->GetCreature(m_KromogGuid))
                                    {
                                        if (!sObjectMgr->IsDisabledEncounter(GetEncounterIDForBoss(l_Kromog)))
                                            DoCompleteAchievement(eFoundryAchievements::WouldYouGiveMeAHand);
                                    }
                                }

                                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                                {
                                    if (Creature* l_Blackhand = instance->GetCreature(m_CosmeticBlackhand))
                                    {
                                        if (l_Blackhand->IsAIEnabled)
                                            l_Blackhand->AI()->Talk(12, 0, TextRange::TEXT_RANGE_MAP);   ///< KromogKilled
                                    }
                                });

                                break;
                            }
                            case EncounterState::NOT_STARTED:
                            {
                                m_WouldYouGiveMeAHand = false;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    case eFoundryDatas::DataBeastlordDarmac:
                    {
                        switch (p_State)
                        {
                            case EncounterState::FAIL:
                            {
                                m_DarmacBeastMountedFirst = 0;
                                break;
                            }
                            default:
                                break;
                        }

                        break;
                    }
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 p_Type, uint32 p_Data) override
            {
                switch (p_Type)
                {
                    case eFoundryDatas::PristineTrueIronOres:
                    {
                        if (instance->IsLFR())
                            break;

                        ++m_PristineTrueIronOres;
                        break;
                    }
                    case eFoundryDatas::VolatileOreGrinded:
                    {
                        if (instance->IsLFR())
                            break;

                        m_VolatileOreGrinded = p_Data != 0;
                        break;
                    }
                    case eFoundryDatas::PrimalElementalistTime:
                    {
                        if (instance->IsLFR())
                            break;

                        if (!m_PrimalElementalistTime)
                            m_PrimalElementalistTime = p_Data;
                        else
                        {
                            /// Defeating all four Primal Elementalists within 10 seconds of each other
                            if (p_Data > (m_PrimalElementalistTime + 10))
                                m_YaWeveGotTimeAchiev = false;
                            else
                                m_YaWeveGotTimeAchiev = true;
                        }

                        break;
                    }
                    case eFoundryDatas::PlayerStamped:
                    {
                        if (instance->IsLFR())
                            break;

                        m_StampStampRevolution = false;
                        break;
                    }
                    case eFoundryDatas::IronTaskmasterAggro:
                    {
                        m_IronTaskmasterAggro = true;
                        break;
                    }
                    case eFoundryDatas::AknorDied:
                    {
                        if (instance->IsLFR())
                            break;

                        m_SteelHasBeenBrought = false;
                        break;
                    }
                    case eFoundryDatas::GraspingEarthTime:
                    {
                        if (instance->IsLFR())
                            break;

                        if (!m_GraspingEarthHandsTime)
                            m_GraspingEarthHandsTime = p_Data;
                        else
                        {
                            /// Defeat 10 Grasping Earth hands within 5 seconds and then defeat Kromog in Blackrock Foundry on Normal difficulty or higher.
                            if (p_Data > (m_GraspingEarthHandsTime + 5))
                                m_WouldYouGiveMeAHand = false;
                            else
                                m_WouldYouGiveMeAHand = true;
                        }

                        break;
                    }
                    case eFoundryDatas::DarmacBeastMountedFirst:
                    {
                        if (instance->IsLFR())
                            break;

                        m_DarmacBeastMountedFirst = p_Data;
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 p_ID) override
            {
                switch (p_ID)
                {
                    case eFoundryDatas::IronTaskmasterAggro:
                        return (uint32)m_IronTaskmasterAggro;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 p_Type) override
            {
                switch (p_Type)
                {
                    case eFoundryCreatures::BossGruul:
                        return m_GruulGuid;
                    case eFoundryCreatures::BossOregorger:
                        return m_OregorgerGuid;
                    case eFoundryCreatures::HeartOfTheMountain:
                        return m_HeartOfTheMountain;
                    case eFoundryCreatures::ForemanFeldspar:
                        return m_ForemanFeldspar;
                    case eFoundryCreatures::BlackhandCosmetic:
                        return m_CosmeticBlackhand;
                    case eFoundryGameObjects::VolatileBlackrockOre:
                        return m_VolatileOreGuid;
                    case eFoundryGameObjects::FurnaceGate:
                        return m_FurnaceGate;
                    case eFoundryCreatures::BossHansgar:
                        return m_HansgarGuid;
                    case eFoundryCreatures::BossFranzok:
                        return m_FranzokGuid;
                    case eFoundryCreatures::BossFlamebenderKagraz:
                        return m_FlamebenderKagrazGuid;
                    case eFoundryCreatures::AknorSteelbringer:
                        return m_AknorSteelbringerGuid;
                    case eFoundryCreatures::LavaStalker:
                        return m_LavaStalkerGuid;
                    case eFoundryCreatures::MoltenTorrentStalker:
                        return m_MoltenTorrentStalkerGuid;
                    case eFoundryCreatures::BossKromog:
                        return m_KromogGuid;
                    case eFoundryCreatures::BossBeastlordDarmac:
                        return m_BeastlordDarmacGuid;
                    case eFoundryCreatures::BossCruelfang:
                        return m_CruelfangGuid;
                    case eFoundryCreatures::BossDreadwing:
                        return m_DreadwingGuid;
                    case eFoundryCreatures::BossIroncrusher:
                        return m_IroncrusherGuid;
                    case eFoundryCreatures::ThunderlordPackPens:
                        return m_ThunderlordPackPens;
                    case eFoundryGameObjects::BeastsEnclosureDoor:
                        return m_BeastsEnclosureDoor;
                    default:
                        break;
                }

                return 0;
            }

            bool CheckAchievementCriteriaMeet(uint32 p_CriteriaID, Player const* p_Source, Unit const* p_Target, uint64 p_MiscValue1) override
            {
                bool l_DifficultyOK = !instance->IsLFR();

                switch (p_CriteriaID)
                {
                    case eFoundryCriterias::DreadwingMountedFirst:
                        return l_DifficultyOK + (m_DarmacBeastMountedFirst == eFoundryDatas::DataDreadwingFirst);
                    case eFoundryCriterias::IroncrusherMountedFirst:
                        return l_DifficultyOK + (m_DarmacBeastMountedFirst == eFoundryDatas::DataIronCrusherFirst);
                    case eFoundryCriterias::CruelfangMountedFirst:
                        return l_DifficultyOK + (m_DarmacBeastMountedFirst == eFoundryDatas::DataCruelfangFirst);
                    default:
                        break;
                }

                return false;
            }

            bool CheckRequiredBosses(uint32 p_BossID, Player const* p_Player = nullptr) const override
            {
                if (!InstanceScript::CheckRequiredBosses(p_BossID, p_Player))
                    return false;

                switch (p_BossID)
                {
                    case eFoundryDatas::DataBlastFurnace:
                    {
                        /// Oregroger and Gruul must be defeated to starts Blast Furnace encounter
                        if (GetBossState(eFoundryDatas::DataOregorger) != EncounterState::DONE ||
                            GetBossState(eFoundryDatas::DataGruul) != EncounterState::DONE)
                            return false;

                        return true;
                    }
                    default:
                        break;
                }

                return true;
            }

            void OnPlayerEnter(Player* p_Player) override
            {
                InstanceScript::OnPlayerEnter(p_Player);

                /// Disable non available bosses for LFR
                if (!m_Initialized)
                {
                    m_Initialized = true;

                    m_DungeonID = p_Player->GetGroup() ? sLFGMgr->GetDungeon(p_Player->GetGroup()->GetGUID()) : 0;

                    if (!instance->IsLFR())
                        m_DungeonID = 0;

                    std::vector<uint64> m_DisabledGoBs;

                    switch (m_DungeonID)
                    {
                        case eFoundryDungeons::Slagworks:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eFoundryDatas::DataHansgarAndFranzok);
                            l_DisabledMask |= (1 << eFoundryDatas::DataFlamebenderKagraz);
                            l_DisabledMask |= (1 << eFoundryDatas::DataKromog);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBeastlordDarmac);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOperatorThogar);
                            l_DisabledMask |= (1 << eFoundryDatas::DataIronMaidens);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlackhand);

                            SetDisabledBosses(l_DisabledMask);

                            m_DisabledGoBs.push_back(m_BlackForgeEntrance);
                            m_DisabledGoBs.push_back(m_IronAssemblyEntrance);
                            m_DisabledGoBs.push_back(m_SpikeGateGuid);
                            m_DisabledGoBs.push_back(m_CrucibleEntrance);
                            break;
                        }
                        case eFoundryDungeons::BlackForge:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eFoundryDatas::DataGruul);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOregorger);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlastFurnace);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBeastlordDarmac);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOperatorThogar);
                            l_DisabledMask |= (1 << eFoundryDatas::DataIronMaidens);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlackhand);

                            SetDisabledBosses(l_DisabledMask);

                            m_DisabledGoBs.push_back(m_SlagworksEntrance);
                            m_DisabledGoBs.push_back(m_IronAssemblyEntrance);
                            m_DisabledGoBs.push_back(m_SpikeGateGuid);
                            m_DisabledGoBs.push_back(m_CrucibleEntrance);
                            break;
                        }
                        case eFoundryDungeons::IronAssembly:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eFoundryDatas::DataGruul);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOregorger);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlastFurnace);
                            l_DisabledMask |= (1 << eFoundryDatas::DataHansgarAndFranzok);
                            l_DisabledMask |= (1 << eFoundryDatas::DataFlamebenderKagraz);
                            l_DisabledMask |= (1 << eFoundryDatas::DataKromog);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlackhand);

                            SetDisabledBosses(l_DisabledMask);

                            m_DisabledGoBs.push_back(m_SlagworksEntrance);
                            m_DisabledGoBs.push_back(m_BlackForgeEntrance);
                            m_DisabledGoBs.push_back(m_SpikeGateGuid);
                            m_DisabledGoBs.push_back(m_CrucibleEntrance);
                            break;
                        }
                        case eFoundryDungeons::BlackhandsCrucible:
                        {
                            uint32 l_DisabledMask = 0;

                            l_DisabledMask |= (1 << eFoundryDatas::DataGruul);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOregorger);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBlastFurnace);
                            l_DisabledMask |= (1 << eFoundryDatas::DataHansgarAndFranzok);
                            l_DisabledMask |= (1 << eFoundryDatas::DataFlamebenderKagraz);
                            l_DisabledMask |= (1 << eFoundryDatas::DataKromog);
                            l_DisabledMask |= (1 << eFoundryDatas::DataBeastlordDarmac);
                            l_DisabledMask |= (1 << eFoundryDatas::DataOperatorThogar);
                            l_DisabledMask |= (1 << eFoundryDatas::DataIronMaidens);

                            SetDisabledBosses(l_DisabledMask);

                            m_DisabledGoBs.push_back(m_SlagworksEntrance);
                            m_DisabledGoBs.push_back(m_BlackForgeEntrance);
                            m_DisabledGoBs.push_back(m_IronAssemblyEntrance);
                            break;
                        }
                        default:
                            break;
                    }

                    for (uint64 l_Guid : m_DisabledGoBs)
                    {
                        if (GameObject* l_Door = sObjectAccessor->FindGameObject(l_Guid))
                            l_Door->SetGoState(GOState::GO_STATE_READY);
                    }
                }
            }

            void OnPlayerExit(Player* p_Player) override
            {
                InstanceScript::OnPlayerExit(p_Player);
            }

            void SendUpdateWorldState(uint32 p_Field, uint32 p_Value)
            {
                Map::PlayerList const& l_Players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator l_Iter = l_Players.begin(); l_Iter != l_Players.end(); ++l_Iter)
                {
                    if (Player* l_Player = l_Iter->getSource())
                        l_Player->SendUpdateWorldState(p_Field, p_Value);
                }
            }

            void PlaySceneForPlayers(Position const p_Pos, uint32 p_ScenePackageID)
            {
                Map::PlayerList const& l_Players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator l_Iter = l_Players.begin(); l_Iter != l_Players.end(); ++l_Iter)
                {
                    if (Player* l_Player = l_Iter->getSource())
                        l_Player->PlayStandaloneScene(p_ScenePackageID, 16, p_Pos);
                }
            }

            bool IsPlayerImmuneToFallDamage(Player* p_Player) const override
            {
                float l_X = p_Player->m_positionX;
                float l_Y = p_Player->m_positionY;
                float l_Z = p_Player->m_positionZ;

                /// Elevator for Hans'gar & Franzok is a safe zone for falling damages
                if (l_X >= 239.5f && l_X <= 267.0f && l_Y >= 3487.01f && l_Y <= 3512.08f && l_Z >= 140.281f)
                    return true;

                return false;
            }

            void Update(uint32 p_Diff) override
            {
                UpdateOperations(p_Diff);
                UpdateCombatResurrection(p_Diff);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* p_Map) const override
        {
            return new instance_blackrock_foundryMapScript(p_Map);
        }
};

void AddSC_instance_blackrock_foundry()
{
    new instance_blackrock_foundry();
}
