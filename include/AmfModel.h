/*  Apex Engine Format Library
	Copyright(C) 2014-2019 Lukas Cone

	This program is free software : you can redistribute it and / or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include "AmfEnums.h"
#include "AdfBaseObject.h"
#include "ApexApi.h"
#include "datas/flags.hpp"
#include <vector>

struct GeneralConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x1B12D103;
	Vector overlayColor;
	float roughnessModulator,
		metallicModulator,
		dielectricReflectance,
		emissiveIntensity,
		emissiveScale,
		emissiveExposureAdapt,
		layeredHeightOffset,
		layeredContrast,
		layeredOpacity,
		layeredBottomHeightInfluence,
		layeredTopHeightInfluence,
		layeredMaskInfluence,
		overlayHeightOffset,
		overlayContrast,
		overlayOpacity,
		overlayBottomHeightInfluence,
		overlayTopHeightInfluence,
		overlayMaskInfluence,
		diffuseRoughness,
		specularAniso,
		transmission,
		clearCoat,
		detailNormalModulator,
		detailNormalTileU,
		detailNormalTileV,
		depthBias,
		hardwareDepthBias,
		hardwareSlopeBias,
		minTimeOfDayEmissive,
		startFadeOutDistanceEmissiveSq,
		gIEmissionModulator,
		HDRReferenceMultiplier,
		rippleAngle,
		rippleSpeed,
		rippleMagnitude;
	esFlags<int, GeneralConstantsFlags> flags;
};

struct CarLightConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x948AE239;
	Vector4 diffuseModulator;
	Vector2 detailTiling;
	float roughnessModulator,
		dielectricReflectance,
		emissiveHead,
		emissiveBlinker,
		emissiveBrake,
		emissiveReverse;
	bool doubleSided;
};

struct WindowConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x58D9967A;
	float roughnessModulator,
		dielectricReflectance,
		tintPower,
		minAlpha,
		UVScale;
	esFlags<char, WindowConstantsFlags> flags;
};

struct CarPaintStaticConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xE513D12B;
	Vector4 dirtParams,
		dirtBlend,
		dirtColor,
		decalCount,
		decalWidth,
		decal1Color,
		decal2Color,
		decal3Color,
		decal4Color,
		decalBlend,
		damage,
		damageBlend,
		damageColor;
	float roughnessModulator,
		metallicModulator,
		dielectricReflectance,
		emissiveIntensity,
		diffuseRoughness,
		specularAniso,
		transmission,
		supportDecals,
		supportDmgBlend,
		supportRotating,
		supportScrolling,
		supportDirt,
		supportSoftTint,
		useLayeredBaseColor;
};

struct CarPaintDynamicConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xCD2C3428;
	Vector4 tintColorR,
		tintColorG,
		tintColorB,
		tecalIndex;
};

struct CarPaintConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x73375A05;
	CarPaintStaticConstants staticAttributes;
	CarPaintDynamicConstants dynamicAttributes;
	float gIEmissionModulator;
	esFlags<short, CarPaintConstantsFlags0> flags0;
	esFlags<int, CarPaintConstantsFlags1> flags1;
	esFlags<short, CarPaintConstantsFlags2> flags2;
};

struct CharacterSkinConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xD8749464;
	Vector2 detailTilingFactorUV;
	float roughnessModulator,
		transmissionModulator,
		diffuseRoughness,
		transmission,
		dirtFactor,
		furLength,
		furThickness,
		furRoughness,
		furGravity,
		furSize;
	esFlags<short, CharacterSkinConstantsFlags> flags;
};

struct CharacterConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x25970695;
	Vector2 detailTilingFactorUV,
		decalBlendFactors;
	float roughnessModulator,
		metallicModulator,
		dielectricReflectance,
		diffuseRoughness,
		specularAniso,
		transmission,
		emissiveIntensity,
		dirtFactor;
	esFlags<int, CharacterConstantsFlags> flags;
};

struct EyeGlossConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x1BAC0639;
	float eyeGlossiness,
		eyeSpecularIntensity,
		eyeReflectIntensity,
		eyeReflectThreshold,
		eyeGlossShadowIntensity;
	esFlags<short, EyeGlossConstantsFlags> flags;
};

struct HairConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x342303CE;
	float roughnessModulator,
		specularMultiplier,
		scatteringMultiplier,
		shiftFactor,
		dielectricReflectance;
	esFlags<short, HairConstantsFlags> flags;
};

struct BarkConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x60A5C450;
	float roughnessModulator,
		dielectricReflectance,
		diffuseRoughness,
		normalStrength,
		detailNormalModulator,
		detailNormalTileU,
		detailNormalTileV,
		isGrass,
		maxWindRotation,
		distanceAtRotationStart,
		distanceAtMaxRotation,
		windSpeedForMaxRotation,
		leafStiffness,
		windProperty7,
		windProperty8;
	esFlags<int, BarkConstantsFlags> flags;
};

struct FoliageConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xA37CA160;
	Vector4 diffuseModulator;
	float roughnessModulator,
		transmissionModulator,
		dielectricReflectance,
		sphereNormalStrength,
		transmission,
		oneOverSubpixelDetailFadeRange,
		ssGrass,
		maxWindRotation,
		distanceAtRotationStart,
		distanceAtMaxRotation,
		windSpeedForMaxRotation,
		leafStiffness,
		windProperty7,
		windProperty8;
	esFlags<char, FoliageConstantsFlags> flags;
};

struct HologramConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x75AF78A;
	Vector emissiveColor;
	float emissiveIntensity,
		blinkIntensity;
	Vector scanlineColor;
	float cloudIntensity,
		cloudTiling,
		cloudSpeedX,
		cloudSpeedY,
		scanline01Tiling,
		scanline01Speed,
		scanline01Thickness,
		scanline01Intensity,
		scanline01DetailTiling,
		scanline01DetailIntensity,
		scanline02Tiling,
		scanline02Speed,
		scanline02Thickness,
		scanline02Intensity,
		meshlineTiling,
		meshlineSpeed,
		meshlineIntensity;
};

struct LandmarkConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xE73F3C81;
	float specularGloss,
		reflectivity,
		emissive,
		specularFresnel;
	Vector diffuseModulator;
	float diffuseWrap,
		backLight,
		minTimeOfDayEmissive,
		startFadeOutDistanceEmissive,
		depthBias;
};

struct EmissiveUIConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x669097B7;
	Vector primaryColor,
		secondaryColor;
	float bias,
		power,
		intensity,
		opacity,
		usePanning,
		panningSpeed,
		panningScale;
};

struct GeneralR2Constants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x8BB29AA0;
	float depthBias,
		detailRepeatU,
		detailRepeatV,
		terrainColorFactor,
		terrainTopProjection,
		blendMaskContrast1,
		blendMaskContrast2;
	esFlags<uint, GeneralR2ConstantsFlags> flags;
};

static_assert(sizeof(GeneralR2Constants) == 32, "Check assumptions");

struct GeneralMkIIIConstants
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xD01A8371;
	float normalStrength,
		reflectivity_1,
		roughness_1,
		diffuseWrap_1,
		emissive_1,
		transmission_1,
		clearCoat_1,
		roughness_2,
		diffuseWrap_2,
		emissive_2,
		transmission_2,
		reflectivity_2,
		clearCoat_2,
		roughness_3,
		diffuseWrap_3,
		emissive_3,
		transmission_3,
		reflectivity_3,
		clearCoat_3,
		roughness_4,
		diffuseWrap_4,
		emissive_4,
		transmission_4,
		reflectivity_4,
		clearCoat_4,
		layeredHeightMapUVScale,
		layeredUVScale,
		layeredHeight1Influence,
		layeredHeight2Influence,
		layeredHeightMapInfluence,
		layeredMaskInfluence,
		layeredShift,
		layeredRoughness,
		layeredDiffuseWrap,
		layeredEmissive,
		layeredTransmission,
		layeredReflectivity,
		layeredClearCoat,
		decalBlend,
		decalBlendNormal,
		decalReflectivity,
		decalRoughness,
		decalDiffuseWrap,
		decalEmissive,
		decalTransmission,
		decalClearCoat,
		overlayHeightInfluence,
		overlayHeightMapInfluence,
		overlayMaskInfluence,
		overlayShift,
		overlayColorR,
		overlayColorG,
		overlayColorB,
		overlayBrightness,
		overlayGloss,
		overlayMetallic,
		overlayReflectivity,
		overlayRoughness,
		overlayDiffuseWrap,
		overlayEmissive,
		overlayTransmission,
		overlayClearCoat,
		damageReflectivity,
		damageRoughness,
		damageDiffuseWrap,
		damageEmissive,
		damageTransmission,
		damageHeightInfluence,
		damageMaskInfluence,
		damageClearCoat,
		depthBias,
		hardwareDepthBias,
		hardwareSlopeBias,
		minTimeOfDayEmissive,
		startFadeOutDistanceEmissiveSq,
		gIEmissionModulator,
		rippleAngle,
		rippleSpeed,
		rippleMagnitude;
	esFlags<uint, GeneralMkIIIConstantsFlags> flags;
};

static_assert(sizeof(GeneralMkIIIConstants) == 320, "Check assumptions");

struct CharacterConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xCE6A3748;
	Vector2 detailTilingFactorUV;
	float specularGloss,
		transmissionIntensity,
		diffuseRoughness,
		emissiveIntensity,
		nightVisibility,
		rimFrontStrength,
		cameraStrength,
		cameraSpecular,
		rimStrength,
		dirtFactor;		
	esFlags<int, CharacterConstantsFlags_GZ> flags;
};

static_assert(sizeof(CharacterConstants_GZ) == 52, "Check assumptions");

struct HairConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x55204F03;
	float specularGloss,
		transmissionIntensity,
		specularFresnel,
		diffuseWrap,
		diffuseRoughness,
		anisotropicStrength,
		anisotropicX,
		anisotropicY,
		rimStrength,
		ringStrength,
		ringAngle,
		ringOffset;
	esFlags<short, HairConstantsFlags_GZ> flags;
};

static_assert(sizeof(HairConstants_GZ) == 52, "Check assumptions");

struct CharacterSkinConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xA5A7B4D5;
	Vector2 detailTilingFactorUV;
	float diffuseRoughness,
		transmissionModulator,
		cameraStrength,
		cameraSpecular,
		dirtFactor,
		furLength,
		furThickness,
		furRoughness,
		furGravity,
		furSize;
	esFlags<short, CharacterSkinConstantsFlags_GZ> flags;
};

static_assert(sizeof(CharacterSkinConstants_GZ) == 52, "Check assumptions");

struct WindowConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0x943EA98D;
	float specGloss,
		specFresnel,
		diffuseRoughness,
		tintPower,
		tintMultiplier,
		minAlpha,
		UVScale,
		chromaticAberration,
		refractionStrength;
	esFlags<short, WindowConstantsFlags_GZ> flags;
};

static_assert(sizeof(WindowConstants_GZ) == 40, "Check assumptions");

struct BarkConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xF5BBB286;
	float glossiness,
		normalStrength,
		diffuseWrap,
		fresnel;
	Vector4 diffuseModulator;
	float layeredHeightMapUVScale,
		layeredUVScale,
		layeredHeight1Influence,
		layeredHeight2Influence,
		layeredHeightMapInfluence,
		layeredMaskInfluence,
		layeredShift,
		layeredRoughness,
		layeredDiffuseWrap,
		layeredEmissive,
		layeredTransmission,
		layeredReflectivity,
		layeredClearCoat,
		layeredUpInfluence,
		overlayHeightInfluence,
		overlayHeightMapInfluence,
		overlayMaskInfluence,
		overlayShift;
	Vector overlayColor;
	float overlayBrightness,
		overlayGloss,
		overlayMetallic,
		overlayReflectivity,
		overlayRoughness,
		overlayDiffuseWrap,
		overlayEmissive,
		overlayTransmission,
		overlayClearCoat,
		overlayUpInfluence;
	esFlags<short, BarkConstantsFlags_GZ> flags;
};

static_assert(sizeof(BarkConstants_GZ) == 160, "Check assumptions");

struct FoliageConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xD32674C9;
	Vector4 diffuseModulator;
	float specularGloss,
		emissionIntensity,
		transmissionIntensity,
		diffuseWrap,
		reflectivity,
		specularFresnel,
		sphereNormalStrength,
		oneOverSubpixelDetailFadeRange;
	esFlags<short, FoliageConstantsFlags> flags;
};

static_assert(sizeof(FoliageConstants_GZ) == 52, "Check assumptions");

struct CarLightConstants_GZ
{
	DECLARE_REFLECTOR;
	static const ApexHash HASH = 0xFB2F8330;
	Vector4 diffuseModulator;
	Vector2 detailTiling;
	float specularGloss,
		reflectivity,
		emissiveHead,
		emissiveBlinker,
		emissiveBrake,
		emissiveReverse,
		specularFresnel;
	bool doubleSided;
};

static_assert(sizeof(CarLightConstants_GZ) == 56, "Check assumptions");

struct GeneralR2Constants_HU
{
	static const ApexHash HASH = 0xB3C503A8;
};

struct CharacterConstants_HU
{
	static const ApexHash HASH = 0xD5C4F848;
};

struct GeneralConstants_HU
{
	static const ApexHash HASH = 0xA59F1968;
};

struct PropConstants_HU
{
	static const ApexHash HASH = 0xCAF76915;
};

struct CarPaintMMConstants_HU
{
	static const ApexHash HASH = 0x99A777D9;
};

struct GeneralJC3Constants_HU
{
	static const ApexHash HASH = 0xD6ACDCC3;
};

struct AmfMaterial
{
	enum MaterialType
	{
		MaterialType_Traditional,
		MaterialType_PBR
	};
	struct
	{
		ApexHash name;
		ApexHash renderBlockID;
		AdfDeferred attributes;
		AdfArray textures;
	}Header;

	StringHash *name;
	StringHash *renderBlockID;
	AdfProperties *attributes;
	std::vector<StringHash *> textures;
	MaterialType materialType;

	int Load(BinReader *rd, ADF *linker);
	AmfMaterial() : materialType(MaterialType_PBR), attributes(nullptr), Header{ 0 } {};
	~AmfMaterial();
};

struct AmfModel : ADFInstance
{
	struct
	{
		ApexHash meshPath;
		AdfArray lodSlots;
		unsigned int memoryTag;
		float lodFactor;
		AdfArray materials;
	}Header;

	StringHash *meshPath;
	std::vector<AmfMaterial*> materials;
	std::vector<unsigned char> lodSlots;

	AmfMaterial *FindMaterial(StringHash *str);
	int Load(BinReader *rd, ADF *linker);
	void Link(ADF *linker);
	ES_INLINE std::string *RequestsFile() { return &meshPath->string; }
	void Merge(ADFInstance*) {}
	static const ApexHash HASH = 0xF7C20A69;
	~AmfModel();
};