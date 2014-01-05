#ifndef _INCLUDE_RAYSTORM_H
#define _INCLUDE_RAYSTORM_H

/*
 * File generated by StormLink from rsi:lib.fd
 * DO NOT EDIT
 * $VER: raystorm.library 2.0 (02-Feb-98)
 */
#ifdef __cplusplus
extern "C" {
#endif
#pragma amicall(RayStormBase, 0x1E, rsiSetCooperateCB())
#pragma amicall(RayStormBase, 0x24, rsiSetCheckCancelCB())
#pragma amicall(RayStormBase, 0x2A, rsiSetLogCB())
#pragma amicall(RayStormBase, 0x30, rsiSetUpdateStatusCB())
#pragma amicall(RayStormBase, 0x36, rsiInit())
#pragma amicall(RayStormBase, 0x3C, rsiExit())
#pragma amicall(RayStormBase, 0x42, rsiCreateContext())
#pragma amicall(RayStormBase, 0x48, rsiFreeContext())
#pragma amicall(RayStormBase, 0x4E, rsiSetUserData())
#pragma amicall(RayStormBase, 0x54, rsiGetUserData())
#pragma amicall(RayStormBase, 0x5A, rsiGetErrorMsg())
#pragma amicall(RayStormBase, 0x60, rsiCleanup())
#pragma amicall(RayStormBase, 0x66, rsiRender())
#pragma amicall(RayStormBase, 0x6C, rsiSetOctreeDepth())
#pragma amicall(RayStormBase, 0x72, rsiSetRenderField())
#pragma amicall(RayStormBase, 0x78, rsiSetAntialias())
#pragma amicall(RayStormBase, 0x7E, rsiSetDistribution())
#pragma amicall(RayStormBase, 0x84, rsiSetRandomJitter())
#pragma amicall(RayStormBase, 0x8A, rsiSetWorld())
#pragma amicall(RayStormBase, 0x90, rsiSetCamera())
#pragma amicall(RayStormBase, 0x96, rsiSetScreen())
#pragma amicall(RayStormBase, 0x9C, rsiSetBrushPath())
#pragma amicall(RayStormBase, 0xA2, rsiSetTexturePath())
#pragma amicall(RayStormBase, 0xA8, rsiSetObjectPath())
#pragma amicall(RayStormBase, 0xAE, rsiSavePicture())
#pragma amicall(RayStormBase, 0xB4, rsiCreatePointLight())
#pragma amicall(RayStormBase, 0xBA, rsiSetPointLight())
#pragma amicall(RayStormBase, 0xC0, rsiCreateSpotLight())
#pragma amicall(RayStormBase, 0xC6, rsiSetSpotLight())
#pragma amicall(RayStormBase, 0xCC, rsiCreateFlare())
#pragma amicall(RayStormBase, 0xD2, rsiSetFlare())
#pragma amicall(RayStormBase, 0xD8, rsiCreateStar())
#pragma amicall(RayStormBase, 0xDE, rsiSetStar())
#pragma amicall(RayStormBase, 0xE4, rsiCreateSphere())
#pragma amicall(RayStormBase, 0xEA, rsiSetSphere())
#pragma amicall(RayStormBase, 0xF0, rsiCreateTriangle())
#pragma amicall(RayStormBase, 0xF6, rsiCreateMesh())
#pragma amicall(RayStormBase, 0xFC, rsiCreatePlane())
#pragma amicall(RayStormBase, 0x102, rsiSetPlane())
#pragma amicall(RayStormBase, 0x108, rsiCreateCSG())
#pragma amicall(RayStormBase, 0x10E, rsiSetCSG())
#pragma amicall(RayStormBase, 0x114, rsiLoadObject())
#pragma amicall(RayStormBase, 0x11A, rsiCreateBox())
#pragma amicall(RayStormBase, 0x120, rsiSetBox())
#pragma amicall(RayStormBase, 0x126, rsiCreateCylinder())
#pragma amicall(RayStormBase, 0x12C, rsiSetCylinder())
#pragma amicall(RayStormBase, 0x132, rsiCreateSOR())
#pragma amicall(RayStormBase, 0x138, rsiSetSOR())
#pragma amicall(RayStormBase, 0x13E, rsiCreateCone())
#pragma amicall(RayStormBase, 0x144, rsiSetCone())
#pragma amicall(RayStormBase, 0x14A, rsiCreateSurface())
#pragma amicall(RayStormBase, 0x150, rsiSetSurface())
#pragma amicall(RayStormBase, 0x156, rsiAddTexture())
#pragma amicall(RayStormBase, 0x15C, rsiSetTexture())
#pragma amicall(RayStormBase, 0x162, rsiAddHyperTexture())
#pragma amicall(RayStormBase, 0x168, rsiSetHyperTexture())
#pragma amicall(RayStormBase, 0x16E, rsiAddBrush())
#pragma amicall(RayStormBase, 0x174, rsiSetBrush())
#pragma amicall(RayStormBase, 0x17A, rsiCreateActor())
#pragma amicall(RayStormBase, 0x180, rsiSetActor())
#pragma amicall(RayStormBase, 0x186, rsiPosition())
#pragma amicall(RayStormBase, 0x18C, rsiAlignment())
#pragma amicall(RayStormBase, 0x192, rsiSize())
#ifdef __cplusplus
};
#endif
#endif
