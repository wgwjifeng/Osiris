#pragma once

enum class ClientFrameStage {
    FRAME_UNDEFINED = -1,
    FRAME_START,
    FRAME_NET_UPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_END,
    FRAME_NET_UPDATE_END,
    FRAME_RENDER_START,
    FRAME_RENDER_END
};

enum class ClassId {
    AI_BaseNPC = 0,
    AK47,
    BaseAnimating,
    BaseAnimatingOverlay,
    BaseAttributableItem,
    BaseButton,
    BaseCombatCharacter,
    BaseCombatWeapon,
    BaseCSGrenade,
    BaseCSGrenadeProjectile,
    BaseDoor,
    BaseEntity,
    BaseFlex,
    BaseGrenade,
    BaseParticleEntity,
    BasePlayer,
    BasePropDoor,
    BaseTeamObjectiveResource,
    BaseTempEntity,
    BaseToggle,
    BaseTrigger,
    BaseViewModel,
    BaseVPhysicsTrigger,
    BaseWeaponWorldModel,
    Beam,
    BeamSpotlight,
    BoneFollower,
    BreakableProp,
    BreakableSurface,
    C4,
    CascadeLight,
    Chicken,
    ColorCorrection,
    ColorCorrectionVolume,
    CSGameRulesProxy,
    CSPlayer,
    CSPlayerResource,
    CSRagdoll,
    CSTeam,
    DEagle,
    DecoyGrenade,
    DecoyProjectile,
    DynamicLight,
    DynamicProp,
    EconEntity,
    EconWearable,
    Embers,
    EntityDissolve,
    EntityFlame,
    EntityFreezing,
    EntityParticleTrail,
    EnvAmbientLight,
    EnvDetailController,
    EnvDOFController,
    EnvParticleScript,
    EnvProjectedTexture,
    EnvQuadraticBeam,
    EnvScreenEffect,
    EnvScreenOverlay,
    EnvTonemapController,
    EnvWind,
    FEPlayerDecal,
    FireCrackerBlast,
    FireSmoke,
    FireTrail,
    Fish,
    Flashbang,
    FogController,
    FootstepControl,
    Func_Dust,
    Func_LOD,
    FuncAreaPortalWindow,
    FuncBrush,
    FuncConveyor,
    FuncLadder,
    FuncMonitor,
    FuncMoveLinear,
    FuncOccluder,
    FuncReflectiveGlass,
    FuncRotating,
    FuncSmokeVolume,
    FuncTrackTrain,
    GameRulesProxy,
    HandleTest,
    HEGrenade,
    Hostage,
    HostageCarriableProp,
    IncendiaryGrenade,
    Inferno,
    InfoLadderDismount,
    InfoOverlayAccessor,
    Item_Healthshot,
    ItemDogTags,
    Knife,
    KnifeGG,
    LightGlow,
    MaterialModifyControl,
    MolotovGrenade,
    MolotovProjectile,
    MovieDisplay,
    ParticleFire,
    ParticlePerformanceMonitor,
    ParticleSystem,
    PhysBox,
    PhysBoxMultiplayer,
    PhysicsProp,
    PhysicsPropMultiplayer,
    PhysMagnet,
    PlantedC4,
    Plasma,
    PlayerResource,
    PointCamera,
    PointCommentaryNode,
    PointWorldText,
    PoseController,
    PostProcessController,
    Precipitation,
    PrecipitationBlocker,
    PredictedViewModel,
    Prop_Hallucination,
    PropDoorRotating,
    PropJeep,
    PropVehicleDriveable,
    RagdollManager,
    RagdollProp,
    RagdollPropAttached,
    RopeKeyframe,
    SCAR17,
    SceneEntity,
    SensorGrenade,
    SensorGrenadeProjectile,
    ShadowControl,
    SlideshowDisplay,
    SmokeGrenade,
    SmokeGrenadeProjectile,
    SmokeStack,
    SpatialEntity,
    SpotlightEnd,
    Sprite,
    SpriteOriented,
    SpriteTrail,
    StatueProp,
    SteamJet,
    Sun,
    SunlightShadowControl,
    Team,
    TeamplayRoundBasedRulesProxy,
    TEArmorRicochet,
    TEBaseBeam,
    TEBeamEntPoint,
    TEBeamEnts,
    TEBeamFollow,
    TEBeamLaser,
    TEBeamPoints,
    TEBeamRing,
    TEBeamRingPoint,
    TEBeamSpline,
    TEBloodSprite,
    TEBloodStream,
    TEBreakModel,
    TEBSPDecal,
    TEBubbles,
    TEBubbleTrail,
    TEClientProjectile,
    TEDecal,
    TEDust,
    TEDynamicLight,
    TEEffectDispatch,
    TEEnergySplash,
    TEExplosion,
    TEFireBullets,
    TEFizz,
    TEFootprintDecal,
    TEFoundryHelpers,
    TEGaussExplosion,
    TEGlowSprite,
    TEImpact,
    TEKillPlayerAttachments,
    TELargeFunnel,
    TEMetalSparks,
    TEMuzzleFlash,
    TEParticleSystem,
    TEPhysicsProp,
    TEPlantBomb,
    TEPlayerAnimEvent,
    TEPlayerDecal,
    TEProjectedDecal,
    TERadioIcon,
    TEShatterSurface,
    TEShowLine,
    Tesla,
    TESmoke,
    TESparks,
    TESprite,
    TESpriteSpray,
    Test_ProxyToggle_Networkable,
    TestTraceline,
    TEWorldDecal,
    TriggerPlayerMovement,
    TriggerSoundOperator,
    VGuiScreen,
    VoteController,
    WaterBullet,
    WaterLODControl,
    WeaponAug,
    WeaponAWP,
    WeaponBaseItem,
    WeaponBizon,
    WeaponCSBase,
    WeaponCSBaseGun,
    WeaponCycler,
    WeaponElite,
    WeaponFamas,
    WeaponFiveSeven,
    WeaponG3SG1,
    WeaponGalil,
    WeaponGalilAR,
    WeaponGlock,
    WeaponHKP2000,
    WeaponM249,
    WeaponM3,
    WeaponM4A1,
    WeaponMAC10,
    WeaponMag7,
    WeaponMP5Navy,
    WeaponMP7,
    WeaponMP9,
    WeaponNegev,
    WeaponNOVA,
    WeaponP228,
    WeaponP250,
    WeaponP90,
    WeaponSawedoff,
    WeaponSCAR20,
    WeaponScout,
    WeaponSG550,
    WeaponSG552,
    WeaponSG556,
    WeaponSSG08,
    WeaponTaser,
    WeaponTec9,
    WeaponTMP,
    WeaponUMP45,
    WeaponUSP,
    WeaponXM1014,
    World,
    DustTrail,
    MovieExplosion,
    ParticleSmokeGrenade,
    RocketTrail,
    SmokeTrail,
    SporeExplosion,
    SporeTrail,
    MAX_CLASSID
};
