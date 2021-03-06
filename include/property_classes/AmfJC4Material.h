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
